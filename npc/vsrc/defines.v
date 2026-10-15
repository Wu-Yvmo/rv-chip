`define IMM_EXT_TYPE_I 3'b000
`define IMM_EXT_TYPE_S 3'b001
`define IMM_EXT_TYPE_B 3'b010
`define IMM_EXT_TYPE_U 3'b011
`define IMM_EXT_TYPE_J 3'b100

`define OPCODE_R 7'b0110011  // R-type: OP，如 add
`define OPCODE_I 7'b0010011  // I-type: OP-IMM，如 addi
`define OPCODE_S 7'b0100011  // S-type: STORE，如 sw/sb
`define OPCODE_B 7'b1100011  // B-type: BRANCH
`define OPCODE_U 7'b0110111  // U-type: LUI
`define OPCODE_J 7'b1101111  // J-type: JAL

// 几种opcode
// opcode（二进制）	十六进制	对应指令
// 0000011	0x03	lw、lbu
// 0010011	0x13	addi
// 0100011	0x23	sw、sb
// 0110011	0x33	add
// 0110111	0x37	lui
// 1100111	0x67	jalr
`define OPCODE_LOAD 7'b0000011
`define OPCODE_OP_IMM 7'b0010011
`define OPCODE_STORE 7'b0100011
`define OPCODE_OP 7'b0110011
`define OPCODE_LUI 7'b0110111
`define OPCODE_JALR 7'b1100111

`define OPCODE_STORE_FUNCT3_SB 3'b000
`define OPCODE_STORE_FUNCT3_SW 3'b010

// 写内存时用到的模式码
`define MEMW_MASK_SB 4'b0001
`define MEMW_MASK_SW 4'b1111

// Load类型下靠funct3区分几个load指令
`define OPCODE_LOAD_FUNCT3_LBU 3'b100
`define OPCODE_LOAD_FUNCT3_LW 3'b010

// 读内存时用到的模式码
`define MEMR_MASK_LBU 3'b000
`define MEMR_MASK_LW 3'b001

`define ALU_OP_ADD 4'b0000

`define ALU_L_SEL_RS1 1'b0
`define ALU_L_SEL_PC 1'b1

`define ALU_R_SEL_IMM 1'b0
`define ALU_R_SEL_RS2 1'b1

`define WB_TYPE_IMM 2'b00
`define WB_TYPE_PCP4 2'b01
`define WB_TYPE_ALU 2'b10
`define WB_TYPE_MEM 2'b11

`define IFU_STATUS_IDLE 2'b00
`define IFU_STATUS_WAIT 2'b01
`define IFU_STATUS_WAIT_LOAD 2'b10
