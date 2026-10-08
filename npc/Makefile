include $(NVBOARD_HOME)/scripts/nvboard.mk

VSRC = ./vsrc/defines.v ./vsrc/alu.v ./vsrc/control.v \
	./vsrc/immgen.v ./vsrc/regfile.v ./vsrc/top.v

CPPSRC = ./csrc/emu.cpp ./csrc/pmem.cpp ./csrc/main.cpp
CPPSRC_NVBOARD = build/auto_bind.cpp ./csrc/emu.cpp ./csrc/main.cpp

all build sim:

verilator:
	verilator --cc --exe -Wall -Wno-fatal --trace --top-module top \
		-I./vsrc \
		-CFLAGS "-std=c++20" \
		$(VSRC) $(CPPSRC)

# 带nvboard
verilator-nvboard:
	verilator --cc --exe -Wall -Wno-fatal --trace \
		-CFLAGS "-std=c++20 -I$(NVBOARD_USR_INC) $(shell sdl2-config --cflags)" \
 		-LDFLAGS "$(NVBOARD_ARCHIVE) -lSDL2 -lSDL2_image -lSDL2_ttf" \
		-I./vsrc \
		$(VSRC) $(CPPSRC)

build: verilator
	make -C obj_dir -f Vtop.mk Vtop.out

sim: build
	./obj_dir/Vtop.out

clean:
	rm -rf obj_dir

gen-lint:
	bear -- make build

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