// 寄存器和内存的数据定义

#include <cstdint>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <iostream>

#include "read_file.hpp"

#define OPCODE_LOAD 0b0000011
#define OPCODE_OP_IMM 0b0010011
#define OPCODE_STORE 0b0100011
#define OPCODE_OP 0b0110011
#define OPCODE_LUI 0b0110111
#define OPCODE_JALR 0b1100111

#define OPCODE_LOAD_FUNCT3_LBU 0b100
#define OPCODE_LOAD_FUNCT3_LW 0b010

#define DRAM_READ_LBU 0
#define DRAM_READ_LW 1

#define OPCODE_STORE_FUNCT3_SB 0b000
#define OPCODE_STORE_FUNCT3_SW 0b010

#define DRAM_WRITE_SB 0
#define DRAM_WRITE_SW 1

#define IMM_EXT_TYPE_I 0
#define IMM_EXT_TYPE_S 1
#define IMM_EXT_TYPE_B 2
#define IMM_EXT_TYPE_U 3
#define IMM_EXT_TYPE_J 4

#define STORAGE_SIZE (0x08000000)

// PC寄存器
uint32_t emu_pc = 0x80000000;
uint32_t emu_regfile[32] = {0};
bool emu_meet_ebreak = false;
// 目前运行的程序是 1+2+...+10的程序
// 字节序是有问题的 不能这么干
uint8_t emu_dram[STORAGE_SIZE] = {0};

void emu_init_storage(const char *path) {
    std::cout << "start emu init" << std::endl;
    auto file_content = read_file(path);
    if (file_content.file_length > STORAGE_SIZE) {
        throw std::runtime_error("out of storage size");
    }
    // 把file_content挪进去
    for (size_t i = 0; i < file_content.file_length; i += 1) {
        if (i < file_content.file_length) {
            emu_dram[i] = file_content.file_content[i];
            continue;
        }
        emu_dram[i] = 0;
    }
    std::cout << "finish emu init" << std::endl;
}

uint32_t select_bit(uint32_t inst, uint32_t i) {
    return (inst >> i) & 1 ? 1 : 0;
}

// 选定inst[l:r]并放在最低位
// 嗯这个是不对的
uint32_t select_bits(uint32_t inst, uint32_t l, uint32_t r) {
    return (inst << (31 - l)) >> (31 - l + r);
}

uint32_t register_read(uint32_t no) {
    return no ? emu_regfile[no] : 0;
}

void register_write(uint32_t no, uint32_t data) {
    if (no) emu_regfile[no] = data;
}

extern bool uart_ready;
extern unsigned long long get_time_buffer;
extern uint64_t get_time();

uint32_t dram_read(uint32_t addr, int mode) {
    if (addr == 0x10000004) {  // 读出UART状态
        return  uart_ready; // 就绪概率为12.5%
    }
    // 读出时钟的低32位
    else if (addr == 0x20000000) { 
        return get_time() & 0xffffffff; 
    }
    // 读出时钟的高32位
    else if (addr == 0x20000004) { 
        return get_time() >> 32; 
    }
    // 修正偏移
    addr -= 0x80000000;

    if (addr > STORAGE_SIZE) {
        throw std::runtime_error("pmem storage too small");
    }
    // 正式读内存
    if (mode == DRAM_READ_LBU) {
        return (uint32_t)emu_dram[addr];
    }
    if (mode == DRAM_READ_LW) {
        auto data_3 = ((uint32_t)emu_dram[addr+3]) << 24;
        auto data_2 = ((uint32_t)emu_dram[addr+2]) << 16;
        auto data_1 = ((uint32_t)emu_dram[addr+1]) << 8;
        auto data_0 = (uint32_t)emu_dram[addr];
        return data_3 | data_2 | data_1 | data_0;
    }
    throw std::runtime_error("shouldn't run");
}

void dram_write(uint32_t addr, int mode, uint32_t data) {
    if (addr == 0x10000000) {  // 写入UART
        // fputc(data & 0xff, stderr);   // 在stdio.h中定义
        return;
    }

    // 修正偏移
    addr -= 0x80000000;

    if (addr > STORAGE_SIZE) {
        throw std::runtime_error("pmem storage too small");
    }
    // 正式写内存
    auto data_3 = (uint8_t)(data >> 24);
    auto data_2 = (uint8_t)(data >> 16);
    auto data_1 = (uint8_t)(data >> 8);
    auto data_0 = (uint8_t)data;
    emu_dram[addr] = data_0;
    if (mode == DRAM_WRITE_SB) {
        return;
    }
    emu_dram[addr+1] = data_1;
    emu_dram[addr+2] = data_2;
    emu_dram[addr+3] = data_3;
    return;
}

uint32_t fetch_instruction() {
    auto inst = dram_read(emu_pc, DRAM_READ_LW);

    return inst;
}

int fetch_imm_ext_type(uint32_t inst) {
    auto opcode = select_bits(inst, 6, 0);
    switch (opcode) {
        case OPCODE_LOAD: return IMM_EXT_TYPE_I;
        case OPCODE_OP_IMM: return IMM_EXT_TYPE_I;
        case OPCODE_STORE: return IMM_EXT_TYPE_S;
        case OPCODE_OP: return 0;
        case OPCODE_LUI: return IMM_EXT_TYPE_U;
        case OPCODE_JALR: return IMM_EXT_TYPE_I;
        default: throw std::runtime_error("shouldn't run");
    }
}

uint32_t imm_gen(uint32_t inst, int imm_ext_type) {
    switch (imm_ext_type) {
        case IMM_EXT_TYPE_I: return (int32_t)inst >> 20;
        case IMM_EXT_TYPE_S: {
            auto imm_31_25 = inst >> 25;
            auto imm_11_7 = inst >> 7 & 0b11111;
            auto imm = imm_31_25 << 5 | imm_11_7;
            return (int32_t)(imm << 20) >> 20;
        }
        case IMM_EXT_TYPE_B: throw std::runtime_error("shouldn't run"); // 暂时不支持
        case IMM_EXT_TYPE_U: return inst >> 12 << 12;
        case IMM_EXT_TYPE_J: throw std::runtime_error("shouldn't run"); // 我们暂时没有这个类型
        default: throw std::runtime_error("shouldn't run");
    }
}

uint32_t fetch_rd_no(uint32_t inst) {
    return inst >> 7 & 0b11111;
}

uint32_t fetch_rs1_no(uint32_t inst) {
    return inst >> 15 & 0b11111;
}

uint32_t fetch_rs2_no(uint32_t inst) {
    return inst >> 20 & 0b11111;
}

uint32_t fetch_funct3(uint32_t inst) {
    return inst >> 12 & 0b111;
}

// 在load下有 lbu lw
void exec_opcode_load(uint32_t inst) {
    auto imm_type = fetch_imm_ext_type(inst);
    auto imm = (int32_t)imm_gen(inst, imm_type);
    auto funct3 = fetch_funct3(inst);
    auto rd_no = fetch_rd_no(inst);
    auto rs1_no = fetch_rs1_no(inst);
    auto rs1_data = register_read(rs1_no);
    auto memr_addr = rs1_data + imm;
    // 生成读内存的mode
    int read_mode;
    if (funct3 == OPCODE_LOAD_FUNCT3_LBU) {
        read_mode = DRAM_READ_LBU;
    }
    if (funct3 == OPCODE_LOAD_FUNCT3_LW) {
        read_mode = DRAM_READ_LW;
    }
    auto memr_data = dram_read(memr_addr, read_mode);
    register_write(rd_no, memr_data);
    // 增加pc
    emu_pc += 4;
}

// 在op-imm下有addi
void exec_opcode_op_imm(uint32_t inst) {
    // 获取立即数
    auto imm_type = fetch_imm_ext_type(inst);
    auto imm = (int32_t)imm_gen(inst, imm_type);
    // 开始计算
    auto rs1_no = fetch_rs1_no(inst);
    auto rs1_data = register_read(rs1_no);
    auto rd_no = fetch_rd_no(inst);
    auto rd_data = rs1_data + imm;
    register_write(rd_no, rd_data);
    // 增加pc
    emu_pc += 4;
}

// 在store下有sw sb
void exec_opcode_store(uint32_t inst) {
    //
    auto imm_type = fetch_imm_ext_type(inst);
    auto imm = (int32_t)imm_gen(inst, imm_type);
    // 
    auto rs1_no = fetch_rs1_no(inst);
    auto rs2_no = fetch_rs2_no(inst);
    auto rs1_data = register_read(rs1_no);
    auto rs2_data = register_read(rs2_no);
    // 写内存
    auto memw_addr = rs1_data + (int32_t)imm;
    int memw_mode;
    // 根据funct3设置写模式
    auto funct3 = fetch_funct3(inst);
    if (funct3 == OPCODE_STORE_FUNCT3_SB) {
        memw_mode = DRAM_WRITE_SB;
    }
    if (funct3 == OPCODE_STORE_FUNCT3_SW) {
        memw_mode = DRAM_WRITE_SW;
    }
    dram_write(memw_addr, memw_mode, rs2_data);
    // 增加pc
    emu_pc += 4;
}

// 在op下有add
void exec_opcode_op(uint32_t inst) {
    //
    auto rs1_no = fetch_rs1_no(inst);
    auto rs2_no = fetch_rs2_no(inst);
    auto rd_no = fetch_rd_no(inst);
    auto rs1_data = register_read(rs1_no);
    auto rs2_data = register_read(rs2_no);
    // 应当用无符号加法
    auto rd_data = rs1_data + rs2_data;
    register_write(rd_no, rd_data);
    // 自增pc
    emu_pc += 4;
}

// 在lui下有lui
void exec_opcode_lui(uint32_t inst) {
    // 生成立即数
    auto imm_type = fetch_imm_ext_type(inst);
    auto imm = imm_gen(inst, imm_type);
    // 
    auto rd_no = fetch_rd_no(inst);
    register_write(rd_no, imm);
    // 自增pc
    emu_pc += 4;
}

// 在jalr下有jalr
void exec_opcode_jalr(uint32_t inst) {
    // 生成立即数
    auto imm_type = fetch_imm_ext_type(inst);
    auto imm = imm_gen(inst, imm_type);
    //
    auto t = emu_pc + 4;
    auto rs1_no = fetch_rs1_no(inst);
    auto rd_no = fetch_rd_no(inst);
    auto rs1_data = register_read(rs1_no);
    auto target = (rs1_data + (int32_t)imm) >> 1 << 1;
    register_write(rd_no, t);
    emu_pc = target;
}

size_t emu_instruction_executed = 0;
// 执行一条指令
void single_cycle() {
    emu_instruction_executed += 1;
    // 取指令
    auto inst = fetch_instruction();
    if (inst == 0x00100073) {
        emu_meet_ebreak = true;
        return;
    }
    if (emu_meet_ebreak) {
        return;
    }
    // 按照opcode进行指令分发
    switch (select_bits(inst, 6, 0)) {
        case OPCODE_LOAD: return exec_opcode_load(inst);
        case OPCODE_OP_IMM: return exec_opcode_op_imm(inst);
        case OPCODE_STORE: return exec_opcode_store(inst);
        case OPCODE_OP: return exec_opcode_op(inst);
        case OPCODE_LUI: return exec_opcode_lui(inst);
        case OPCODE_JALR: return exec_opcode_jalr(inst);
        default: throw std::runtime_error("shouldn't run");
    }
}

// 这个地方的访存什么的我真得好好研究一下
// 