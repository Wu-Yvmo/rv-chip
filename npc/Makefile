all build sim:

verilator:
	verilator --cc --exe -Wall --trace -CFLAGS "-std=c++20" vsrc/top.v csrc/main.cpp

build: verilator
	make -C obj_dir -f Vtop.mk Vtop.out

sim: build
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	./obj_dir/Vtop.out

gen-lint:
	bear -- make build

clean:
	rm -rf obj_dir 

NEMU_HOME := /home/wuyvmo/ysyx-workbench/npc

include ../Makefile

# 下面是我们的参考
# all: run

# # 步骤 1：Verilog -> C++ 模型，并生成链接用的 Vtop.mk
# verilate:
# 	verilator --cc --exe -Wall --trace top.v main.cpp

# # 步骤 2：编译并链接 main.cpp 和 Verilator 生成的 C++ 模型
# compile: verilate
# 	$(MAKE) -C obj_dir -f Vtop.mk Vtop

# # 步骤 3：运行测试
# run: compile
# 	./obj_dir/Vtop

# clean:
# 	rm -rf obj_dir wave.vcd