`include "defines.v"

module top(
    input clk,
    input rst,
    output meet_ebreak
);
    // C++提供的内存访问接口
    import "DPI-C" function int pmem_read(input int raddr); // 内存读逻辑
    import "DPI-C" function void pmem_write(
        input int waddr, 
        input int wdata, 
        input byte wmask
    ); // 内存写逻辑

    // IF阶段 取指令
    reg [31:0] pc = 0, next_pc = 0;
    wire inner_meet_ebreak;
    always @(posedge clk) begin // pc的更新
        if (rst) pc <= 0;
        // pc只在没遇到ebreak时才更新
        else if (~inner_meet_ebreak) pc <= next_pc;
        else pc <= pc;
    end

    wire [31:0] instruction;
    assign instruction = pmem_read(pc);
    // reg meet_ebreak_r = instruction == 32'h00100073;
    assign inner_meet_ebreak = instruction == 32'h00100073;
    
    reg meet_ebreak_r;
    always @(posedge clk) begin
        meet_ebreak_r <= inner_meet_ebreak;
    end
    assign meet_ebreak = meet_ebreak_r;

    // deepseek给的建议是把ebreak打一拍再输出
    // assign meet_ebreak = meet_ebreak_r;

    // ID阶段 生成控制信号 读寄存器
    wire reg_wen;
    wire [4:0] reg_waddr = instruction[11:7];
    reg [31:0] reg_wdata;
    wire [4:0] rs1_addr = instruction[19:15];
    wire [31:0] rs1_data;
    wire[4:0] rs2_addr = instruction[24:20];
    wire [31:0] rs2_data;
    regfile regfile(
        .clk (clk),
        .rst (rst),
        // 寄存器堆只有没遇到ebreak才允许写
        .wen (reg_wen & ~meet_ebreak),
        .waddr (reg_waddr),
        .wdata (reg_wdata),
        .raddr_rs1 (rs1_addr),
        .rdata_rs1 (rs1_data),
        .raddr_rs2 (rs2_addr),
        .rdata_rs2 (rs2_data)
    ); // 寄存器实例化 同时完成连线

    wire [2:0] imm_ext_type;
    wire [3:0] alu_op;
    wire alu_l_sel;
    wire alu_r_sel;
    wire jalr;
    wire mem_wen;
    wire [3:0] memw_mask;
    wire mem_ren;
    wire [2:0] memr_mask;
    wire [1:0] wb_type;
    control control(
        .instruction (instruction),
        .imm_ext_type (imm_ext_type),
        .alu_op (alu_op),
        .alu_l_sel (alu_l_sel),
        .alu_r_sel (alu_r_sel),
        .jalr (jalr),
        .mem_wen (mem_wen),
        .memw_mask (memw_mask),
        .mem_ren (mem_ren),
        .memr_mask (memr_mask),
        .reg_wen (reg_wen),
        .wb_type (wb_type)
    ); // 控制器实例化 同时完成连线

    wire [31:0] imm;
    immgen immgen(
        .instruction (instruction),
        .imm_ext_type (imm_ext_type),
        .imm (imm)
    ); // 立即数生成器实例化 同时完成连线

    // EX阶段 实例化ALU 生成next_pc
    wire [31:0] alu_l = (alu_l_sel == `ALU_L_SEL_RS1) ? rs1_data : pc;
    wire [31:0] alu_r = (alu_r_sel == `ALU_R_SEL_RS2) ? rs2_data : imm;
    wire [31:0] alu_out;
    alu alu(
        .alu_l (alu_l),
        .alu_r (alu_r),
        .alu_op (alu_op),
        .alu_out (alu_out)
    ); // 实例化 alu

    // 这一步是尝试修改ebreak的行为了
    assign next_pc = jalr ? {alu_out[31:1], 1'b0} : pc + 4; // 生成next_pc
    
    // MEM阶段 完成内存的读写
    // 读写内存的数据都可能怎么流转：
    // 读写使用的地址都来自alu
    // 关于读内存：
    //     应该是读出来后被写入寄存器 写入rd
    //     但这个阶段暂时不处理哪里的数据写入寄存器文件
    // 关于写内存：
    //     写的数据应该来自寄存器的rs2数据
    // 读内存可以安全的放在组合逻辑中 其实也不是特别正确 但单周期就是这样了
    reg [31:0] mem_rdata = 0;
    reg [31:0] tmp;
    always @(*) begin
        // 处理读
        // 只有在读使能且没遇到ebreak的情况下才读
        if (mem_ren & ~meet_ebreak) begin
            case (memr_mask)
            `MEMR_MASK_LBU: begin
                tmp = pmem_read(alu_out);
                mem_rdata = {{24{1'b0}}, tmp[7:0]};
            end
            `MEMR_MASK_LW: mem_rdata = pmem_read(alu_out);
            default: mem_rdata = 0;
            endcase
        end
        else begin
            mem_rdata = 0;
        end
    end
    // 处理写 现在把写放时钟边沿触发
    always @(posedge clk) begin
        // 只有在没遇到ebreak且且写使能的情况下才写
        if (mem_wen & ~meet_ebreak) begin
            pmem_write(alu_out, rs2_data, {{4{1'b0}}, memw_mask});
        end
    end

    // WB阶段
    // 写回的数据有4个来源：
    // imm pcp4
    // alu
    // mem
    always @(*) begin
        case (wb_type)
        `WB_TYPE_IMM: reg_wdata = imm;
        `WB_TYPE_PCP4: reg_wdata = pc + 4;
        `WB_TYPE_ALU: reg_wdata = alu_out;
        `WB_TYPE_MEM: reg_wdata = mem_rdata;
        default: reg_wdata = 0;
        endcase
    end
endmodule

// 要实现的指令一共：
// addi I型
// jalr I型
// add R型
// lui U型
// lw I型
// lbu I型
// sw S型
// sb S型

// addi（I 型）
// +---------------------+--------+-----+-------+--------+
// | imm[11:0]           | rs1    | 000 | rd    | 0010011|
// | 31:20               | 19:15  |14:12| 11:7  | 6:0    |
// +---------------------+--------+-----+-------+--------+
// 行为：
//     x[rd] = x[rs1] + sext(imm[11:0])
//     PC = PC + 4
// 说明：
//     imm 是 12 位有符号立即数。

// jalr（I 型）
// +---------------------+--------+-----+-------+--------+
// | imm[11:0]           | rs1    | 000 | rd    | 1100111|
// | 31:20               | 19:15  |14:12| 11:7  | 6:0    |
// +---------------------+--------+-----+-------+--------+
// 行为：
//     t = PC + 4
//     target = (x[rs1] + sext(imm[11:0])) & 0xFFFFFFFE
//     x[rd] = t
//     PC = target
// 说明：
//     目标地址最低位清零。
//     若 rd = rs1，计算 target 时使用旧的 x[rs1]。
//     若 rd = x0，不保存返回地址。

// add（R 型）
// +---------+--------+--------+-----+-------+--------+
// | 0000000 | rs2    | rs1    | 000 | rd    | 0110011|
// | 31:25   | 24:20  | 19:15  |14:12| 11:7  | 6:0    |
// +---------+--------+--------+-----+-------+--------+
// 行为：
//     x[rd] = x[rs1] + x[rs2]
//     PC = PC + 4

// lui（U 型）
// +-----------------------------------+-------+--------+
// | imm[31:12]                        | rd    | 0110111|
// | 31:12                             | 11:7  | 6:0    |
// +-----------------------------------+-------+--------+
// 行为：
//     x[rd] = {imm[31:12], 12'b0}
//     即 x[rd] = imm[31:12] << 12
//     PC = PC + 4
// 说明：
//     U 型立即数直接放到结果高 20 位，低 12 位清零。

// lw（I 型，LOAD）
// +---------------------+--------+-----+-------+--------+
// | imm[11:0]           | rs1    | 010 | rd    | 0000011|
// | 31:20               | 19:15  |14:12| 11:7  | 6:0    |
// +---------------------+--------+-----+-------+--------+
// 行为：
//     addr = x[rs1] + sext(imm[11:0])
//     x[rd] = M[addr]
//           | (M[addr+1] << 8)
//           | (M[addr+2] << 16)
//           | (M[addr+3] << 24)
//     PC = PC + 4
// 说明：
//     从内存读取 32 位，小端，写入 rd

// lbu（I 型，LOAD）
// +---------------------+--------+-----+-------+--------+
// | imm[11:0]           | rs1    | 100 | rd    | 0000011|
// | 31:20               | 19:15  |14:12| 11:7  | 6:0    |
// +---------------------+--------+-----+-------+--------+
// 行为：
//     addr = x[rs1] + sext(imm[11:0])
//     x[rd] = zero_extend(M[addr], 32)
//     PC = PC + 4
// 说明：
//     从内存读取 1 字节，零扩展到 32 位，写入 rd。

// sw（S 型，STORE）
// +----------+--------+--------+-----+---------+--------+
// | imm[11:5]| rs2    | rs1    | 010 | imm[4:0]| 0100011|
// | 31:25    | 24:20  | 19:15  |14:12| 11:7    | 6:0    |
// +----------+--------+--------+-----+---------+--------+
// 行为：
//     addr = x[rs1] + sext(imm[11:0])
//     M[addr]   = x[rs2][7:0]
//     M[addr+1] = x[rs2][15:8]
//     M[addr+2] = x[rs2][23:16]
//     M[addr+3] = x[rs2][31:24]
//     PC = PC + 4
// 说明：
//     把 rs2 的 32 位值按小端写入内存。

// sb（S 型，STORE）
// +----------+--------+--------+-----+---------+--------+
// | imm[11:5]| rs2    | rs1    | 000 | imm[4:0]| 0100011|
// | 31:25    | 24:20  | 19:15  |14:12| 11:7    | 6:0    |
// +----------+--------+--------+-----+---------+--------+
// 行为：
//     addr = x[rs1] + sext(imm[11:0])
//     M[addr] = x[rs2][7:0]
//     PC = PC + 4
// 说明：
//     只把 rs2 的最低 8 位写入内存。

// 下一步干：
// 把模拟器写起来 然后进行对比判断设计有没有问题
