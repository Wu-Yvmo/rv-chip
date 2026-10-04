#include "Vtop.h"
#include "verilated.h"

#include <cstdlib>
#include <stdio.h>

#include <iostream>
#include <format>

int main(int argc, char **argv) {
	std::cout << "start simulation." << std::endl;
	Verilated::commandArgs(argc, argv);
	Vtop *vtop = new Vtop;
	for (int i = 0; i < 100; i += 1) {
		vtop->a = rand() % 2;
		vtop->b = rand() % 2;
		vtop->eval();
		auto a = vtop->a;
		auto b = vtop->b;
		auto f = vtop->f;
		std::cout << std::format("a: {}, b: {}, f: {}, result: {}", a, b, f, a ^ b == f ? "SUCCESS" : "FAIL") << std::endl;
	}
	return 0;
}
