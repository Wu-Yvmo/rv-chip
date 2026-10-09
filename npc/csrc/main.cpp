#include "Vtop.h"
#include "verilated.h"
#include "Vtop___024root.h"

#include "comparable_runtime_statuses.hpp"
// #include <nvboard.h>

#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>

#include <iostream>
#include <format>
#include <unistd.h>

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

ComparableRuntimeStatuses gather_emu_comparable_runtime_statuses() {
	ComparableRuntimeStatuses comparable_runtime_statuses;
	comparable_runtime_statuses.pc = emu_pc;
	for (auto i = 0; i < 32; i += 1) {
		comparable_runtime_statuses.regfile[i] = emu_regfile[i];
	}
	return comparable_runtime_statuses;
}

ComparableRuntimeStatuses gather_rtl_comparable_runtime_statuses(Vtop *to_gather) {
	ComparableRuntimeStatuses comparable_runtime_statuses;
	comparable_runtime_statuses.pc = to_gather->rootp->top__DOT__pc;
	for (auto i = 0; i < 32; i += 1) {
		comparable_runtime_statuses.regfile[i] = to_gather->rootp->top__DOT__regfile__DOT__storage[i];
	}
	return comparable_runtime_statuses;
}

extern void emu_init_storage();
extern void pmem_load_insts();

int main(int argc, char **argv) {
	std::cout << "start simulation." << std::endl;
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
	
	// 正式指令执行部分
	// 执行测试直到两边都遇到ebreak
	// 只有一边时需要报错
	std::cout << "emu init storage start" << std::endl;
	emu_init_storage();
	pmem_load_insts();
	std::cout << "start verilator" << std::endl;
	for (int i = 0; i < INT_MAX; i += 1) {
		// 1. emu执行一条指令后收集状态
		single_cycle();
		auto emu_comparable_runtime_statuses = gather_emu_comparable_runtime_statuses();
		// 2. rtl执行一条指令后收集状态
		vtop->clk = 1;
		vtop->eval();
		vtop->clk = 0;
		vtop->eval();
		auto rtl_comparable_runtime_statuses = gather_rtl_comparable_runtime_statuses(vtop);
		// 3.打印emu和rtl的寄存器状态
		std::cout << std::endl;
		std::cout << dump_comparable_runtime_statuses(emu_comparable_runtime_statuses) << std::endl;
		std::cout << dump_comparable_runtime_statuses(rtl_comparable_runtime_statuses) << std::endl;
		// 比较emu和rtl的运行状态
		if (!comparable_runtime_statuses_equal(emu_comparable_runtime_statuses, rtl_comparable_runtime_statuses)) {
			// 打印两个comparable_statuses
			throw std::runtime_error("fatal error, difftest not pass");
		}
		printf("finished round: %d, emu_meet_ebreak: %d\n", i, emu_meet_ebreak);
		if (!emu_meet_ebreak && vtop->meet_ebreak) {
			throw std::runtime_error("vtop meet ebreak too early");
		}
		if (emu_meet_ebreak && !vtop->meet_ebreak) {
			throw std::runtime_error("emu meet ebreak too early");
		}
		if (emu_meet_ebreak && vtop->meet_ebreak) {
			break;
		}
	}
	std::cout << "test pass!" << std::endl;
	// nvboard_quit();
	return 0;
}

// 整理一下都需要改写哪些地方
// 先统一一下测试用例的内存大小
// 暂时给定位256吧