#include "Vtop.h"
#include "verilated.h"
#include "Vtop___024root.h"

#include "comparable_runtime_statuses.hpp"
// #include <nvboard.h>

#include <climits>
#include <cstdint>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>

#include <iostream>
#include <format>
#include <unistd.h>

#define IFU_STATUS_IDLE 0
#define IFU_STATUS_WAIT 1
#define IFU_STATUS_WAIT_LOAD 2

void nvboard_bind_all_pins(Vtop *);

bool comparable_runtime_statuses_equal(ComparableRuntimeStatuses &l, ComparableRuntimeStatuses &r) {
	if (l.pc != r.pc) {
		return false;
	}
	for (auto i = 0; i < 32; i += 1) {
		if (l.regfile[i] != r.regfile[i]) {
			return false;
		}
	}
	return true;
}

std::string dump_comparable_runtime_statuses(ComparableRuntimeStatuses &to_dump) {
	auto pc_dump = std::format("pc: [{}]", to_dump.pc);
	auto regfile_1_8_dump = std::format("reg1: [{}], reg2: [{}], reg3: [{}], reg4: [{}], reg5: [{}], reg6: [{}], reg7: [{}], reg8: [{}]",
		to_dump.regfile[0], to_dump.regfile[1], to_dump.regfile[2], to_dump.regfile[3],
		to_dump.regfile[4], to_dump.regfile[5], to_dump.regfile[6], to_dump.regfile[7]
	);
	auto regfile_9_16_dump = std::format("reg9: [{}], reg10: [{}], reg11: [{}], reg12: [{}], reg13: [{}], reg14: [{}], reg15: [{}], reg16: [{}]",
		to_dump.regfile[8], to_dump.regfile[9], to_dump.regfile[10], to_dump.regfile[11],
		to_dump.regfile[12], to_dump.regfile[13], to_dump.regfile[14], to_dump.regfile[15]
	);
	auto regfile_17_24_dump = std::format("reg17: [{}], reg18: [{}], reg19: [{}], reg20: [{}], reg21: [{}], reg22: [{}], reg23: [{}], reg24: [{}]",
		to_dump.regfile[16], to_dump.regfile[17], to_dump.regfile[18], to_dump.regfile[19],
		to_dump.regfile[20], to_dump.regfile[21], to_dump.regfile[22], to_dump.regfile[23]
	);
	auto regfile_25_32_dump = std::format("reg25: [{}], reg26: [{}], reg27: [{}], reg28: [{}], reg29: [{}], reg30: [{}], reg31: [{}], reg32: [{}]",
		to_dump.regfile[24], to_dump.regfile[25], to_dump.regfile[26], to_dump.regfile[27],
		to_dump.regfile[28], to_dump.regfile[29], to_dump.regfile[30], to_dump.regfile[31]
	);
	auto dump = std::format("{}\n{}\n{}\n{}\n{}", pc_dump, regfile_1_8_dump, regfile_9_16_dump, regfile_17_24_dump, regfile_25_32_dump);
	return dump;
}

// 把emu需要暴露的字段 exter 出来
extern uint32_t emu_pc;
extern uint32_t emu_regfile[32];
extern bool emu_meet_ebreak;
extern void single_cycle();

ComparableRuntimeStatuses emu_comparable_runtime_statuses;
ComparableRuntimeStatuses rtl_comparable_runtime_statuses;

void gather_emu_comparable_runtime_statuses() {
	emu_comparable_runtime_statuses.pc = emu_pc;
	for (auto i = 0; i < 32; i += 1) {
		emu_comparable_runtime_statuses.regfile[i] = emu_regfile[i];
	}
}

void gather_rtl_comparable_runtime_statuses(Vtop *to_gather) {
	rtl_comparable_runtime_statuses.pc = to_gather->rootp->top__DOT__npc__DOT__pc;
	for (auto i = 0; i < 32; i += 1) {
		rtl_comparable_runtime_statuses.regfile[i] = to_gather->rootp->top__DOT__npc__DOT__regfile__DOT__storage[i];
	}
}

extern void emu_init_storage(const char *path);
extern void pmem_load_insts(const char *path);

// 要装入 NPC 存储器的程序镜像, 由命令行参数 --image <path> 指定.
// 定义在这里, 让 pmem.cpp / emu.cpp 用 extern 引用同一个路径,
// 这样切换程序不用重新编译仿真环境.
const char *image_path = nullptr;

// 解析仿真环境自己的命令行参数
static void parse_args(int argc, char **argv) {
	for (int i = 1; i < argc; i += 1) {
		if (std::string(argv[i]) != "--image") {
			continue;
		}
		if (i + 1 >= argc) {
			throw std::runtime_error("--image 后面需要给出程序镜像的路径");
		}
		image_path = argv[i + 1];
		// 把这两个参数从 argv 里摘掉, 免得 Verilator 因为不认识而报错
		for (int j = i; j + 2 < argc; j += 1) {
			argv[j] = argv[j + 2];
		}
		argc -= 2;
		i -= 1;
	}
}

extern uint64_t cycle_count;
extern int ifu_status;
extern size_t emu_instruction_executed;

uint32_t last_rtl_pc;

int main(int argc, char **argv) {
	parse_args(argc, argv);
	if (image_path) {
		emu_init_storage(image_path);
		pmem_load_insts(image_path);
	} else {
		throw std::runtime_error("no valid image");
	}
	Verilated::commandArgs(argc, argv);
	Vtop *vtop = new Vtop;
	// nvboard_bind_all_pins(vtop);
	// nvboard_init();
	
	// 先把rtl的状态都清零
	vtop->clk = 0;
	vtop->rst = 1;
	vtop->eval();

	vtop->clk = 1;
	vtop->eval();
	
	vtop->clk = 0;
	vtop->rst = 0;
	vtop->eval();
	
	last_rtl_pc = vtop->rootp->top__DOT__npc__DOT__pc;
	// 正式指令执行部分
	// 执行测试直到两边都遇到ebreak
	// 只有一边时需要报错
	std::cout << "emu init storage start" << std::endl;
	std::cout << "start verilator" << std::endl;
	for (size_t i = 0; i < SIZE_MAX; i += 1) {
		cycle_count = i;
		// 1. emu执行一条指令后收集状态
		// 尝试换一个逻辑
		// 2. rtl执行一条指令后收集状态
		vtop->clk = 1;
		vtop->eval();
		vtop->clk = 0;
		vtop->eval();
		// 每次都应该在指令完成提交时执行
		if ((ifu_status == IFU_STATUS_WAIT && !vtop->is_load_store_export) || (ifu_status == IFU_STATUS_WAIT_LOAD && vtop->is_load_store_export)) {
			single_cycle(); // 这么看来的话确实是领先一条指令了
		}
		gather_emu_comparable_runtime_statuses();
		gather_rtl_comparable_runtime_statuses(vtop);
		// 打印两个
		// 比较emu和rtl的运行状态
		// 只在idle状态下检查
		if (ifu_status == IFU_STATUS_IDLE) {
			if (!comparable_runtime_statuses_equal(emu_comparable_runtime_statuses, rtl_comparable_runtime_statuses)) {
				// 打印两个comparable_statuses
				auto emu_dump = dump_comparable_runtime_statuses(emu_comparable_runtime_statuses);
				auto rtl_dump = dump_comparable_runtime_statuses(rtl_comparable_runtime_statuses);
				std::cout << "emu:" << std::endl;
				std::cout << emu_dump << std::endl;
				std::cout << "rtl:" << std::endl;
				std::cout << rtl_dump << std::endl;
				throw std::runtime_error("fatal error, difftest not pass");
			}
			if (!emu_meet_ebreak && vtop->meet_ebreak) {
				throw std::runtime_error("vtop meet ebreak too early");
			}
			if (emu_meet_ebreak && !vtop->meet_ebreak) {
				throw std::runtime_error("emu meet ebreak too early");
			}
			if (emu_meet_ebreak && vtop->meet_ebreak) {
				std::cout << std::format("IPC is: {}", (double)emu_instruction_executed / i) << std::endl;
				break;
			}
		}
		// if (i % 1000000 == 0) {
		// 	printf("inst executed: %d\n", i % 1000000 == 0);
		// }
		// if (vtop->meet_ebreak) {
		// 	break;
		// }
	}
	// 检查a0寄存器
	auto a0 = vtop->rootp->top__DOT__npc__DOT__regfile__DOT__storage[10];
	auto test_status = a0 == 0 ? "PASS" : "FAIL";
	std::cout << test_status << std::endl;
	if (a0) {
		return 1; // 让make能拿到失败
	}
	// nvboard_quit();
	return 0;
}

// 整理一下都需要改写哪些地方
// 先统一一下测试用例的内存大小
// 暂时给定位256吧