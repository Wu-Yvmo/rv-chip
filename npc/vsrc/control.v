`include "defines.v"

// alu 的rs1端口可能接收来自：pc 和 rs1
// alu的rs2端口可能接收来自：imm 和rs2
module control(
    input [31:0] instruction,
    // 输出信号
    // imm的扩展方式
    output reg [2:0] imm_ext_type,
    // alu执行的运算
    output reg [3:0] alu_op,
    // alu两边的数据选择
    output reg alu_l_sel, // 0 rs1 1 pc
    output reg alu_r_sel, // 0 imm 1 rs2
    // pc增加方式：
    // 无条件跳转jalr
    output reg jalr,
    // 访存方式
    // 写使能 写地址由alu生成
    output reg mem_wen,
    output reg [3:0] memw_mask,
    // 读使能
    output reg mem_ren, // 读地址由alu生成
    // 思考一下 读掩码是干啥的? 数据加载到寄存器时
    // C++永远返回的是4字节 那这说明我们需要这个mem_rmask来后处理
    // 现在又哪些读指令：lw和lbu
    // 但是总共是5种
    output reg [2:0] memr_mask, // 读内存的掩码
    output wire reg_wen, // 寄存器写使能
    output wire [1:0] wb_type // 写回寄存器堆的数据来源
);
    // 正文
    always @(*) begin
        imm_ext_type = 0;
        alu_op = 0;
        alu_l_sel = 0;
        alu_r_sel = 0;
        jalr = 0;
        mem_wen = 0;
        memw_mask = 0;
        mem_ren = 0;
        reg_wen = 0;
        wb_type = 0;
        // 对imm_ext_type的译码
        case (instruction[6:0])
        `OPCODE_LOAD: imm_ext_type = `IMM_EXT_TYPE_I;
        `OPCODE_OP_IMM: imm_ext_type = `IMM_EXT_TYPE_I;
        `OPCODE_STORE: imm_ext_type = `IMM_EXT_TYPE_S;
        `OPCODE_OP: imm_ext_type = 0;
        `OPCODE_LUI: imm_ext_type = `IMM_EXT_TYPE_U;
        `OPCODE_JALR: imm_ext_type = `IMM_EXT_TYPE_I;
        default: imm_ext_type = 0;
        endcase
        // 对alu_op的译码
        case (instruction[6:0])
        `OPCODE_LOAD: alu_op = `ALU_OP_ADD;
        `OPCODE_OP_IMM: alu_op = `ALU_OP_ADD;
        `OPCODE_STORE: alu_op = `ALU_OP_ADD;
        `OPCODE_OP: alu_op = `ALU_OP_ADD;
        `OPCODE_LUI: alu_op = 0;
        `OPCODE_JALR: alu_op = `ALU_OP_ADD;
        default: alu_op = 0;
        endcase
        // 对alu_l_sel的译码
        case (instruction[6:0])
        `OPCODE_LOAD: alu_l_sel = `ALU_L_SEL_RS1; // alu l 输入 rs1
        `OPCODE_OP_IMM: alu_l_sel = `ALU_L_SEL_RS1;
        `OPCODE_STORE: alu_l_sel = `ALU_L_SEL_RS1;
        `OPCODE_OP: alu_l_sel = `ALU_L_SEL_RS1;
        `OPCODE_LUI: alu_l_sel = 0; // 直通不需要alu
        `OPCODE_JALR: alu_l_sel = `ALU_L_SEL_RS1;
        default: alu_l_sel = 0; // 默认为0
        endcase
        // 对alu_r_sel的译码
        case (instruction[6:0])
        `OPCODE_LOAD: alu_r_sel = `ALU_R_SEL_IMM;
        `OPCODE_OP_IMM: alu_r_sel = `ALU_R_SEL_IMM;
        `OPCODE_STORE: alu_r_sel = `ALU_R_SEL_IMM;
        `OPCODE_OP: alu_r_sel = `ALU_R_SEL_RS2;
        `OPCODE_LUI: alu_r_sel = 0; // 直通不需要alu
        `OPCODE_JALR: alu_r_sel = `ALU_R_SEL_IMM;
        default: alu_r_sel = 0;
        endcase
        // 对jalr的译码
        case (instruction[6:0])
        `OPCODE_LOAD: jalr = 0;
        `OPCODE_OP_IMM: jalr = 0;
        `OPCODE_STORE: jalr = 0;
        `OPCODE_OP: jalr = 0;
        `OPCODE_LUI: jalr = 0;
        `OPCODE_JALR: jalr = 1;
        default: jalr = 0;
        endcase
        // 对mem_wen的译码
        case(instruction[6:0])
        `OPCODE_LOAD: mem_wen = 0;
        `OPCODE_OP_IMM: mem_wen = 0;
        `OPCODE_STORE: mem_wen = 1;
        `OPCODE_OP: mem_wen = 0;
        `OPCODE_LUI: mem_wen = 0;
        `OPCODE_JALR: mem_wen = 0;
        default: mem_wen = 0;
        endcase
        // 对memw_mask的译码
        case (instruction[6:0])
        `OPCODE_LOAD: memw_mask = 0;
        `OPCODE_OP_IMM: memw_mask = 0;
        `OPCODE_STORE: begin
            case (instruction[14:12])
            `OPCODE_STORE_FUNCT3_SB: memw_mask = `MEMW_MASK_SB;
            `OPCODE_STORE_FUNCT3_SW: memw_mask = `MEMW_MASK_SW;
            default: memw_mask = 0;
            endcase
        end
        `OPCODE_OP: memw_mask = 0;
        `OPCODE_LUI: memw_mask = 0;
        `OPCODE_JALR: memw_mask = 0;
        default: memw_mask = 0;
        endcase
        // 对mem_ren的译码
        case (instruction[6:0])
        `OPCODE_LOAD: mem_ren = 1;
        `OPCODE_OP_IMM: mem_ren = 0;
        `OPCODE_STORE: mem_ren = 0;
        `OPCODE_OP: mem_ren = 0;
        `OPCODE_LUI: mem_ren = 0;
        `OPCODE_JALR: mem_ren = 0;
        default: mem_ren = 0;
        endcase
        // 对mem_rmask的译码
        case (instruction[6:0])
        `OPCODE_LOAD: begin
            case (instruction[14:12])
            `OPCODE_LOAD_FUNCT3_LBU: memr_mask = `MEMR_MASK_LBU;
            `OPCODE_LOAD_FUNCT3_LW: memr_mask = `MEMR_MASK_LW;
            default: memr_mask = 0;
            endcase
        end
        `OPCODE_OP_IMM: memr_mask = 0;
        `OPCODE_STORE: memr_mask = 0;
        `OPCODE_OP: memr_mask = 0;
        `OPCODE_LUI: memr_mask = 0;
        `OPCODE_JALR: memr_mask = 0;
        default: memr_mask = 0;
        endcase
        // 对reg_wen的译码
        case (instruction[6:0])
        `OPCODE_LOAD: reg_wen = 1;
        `OPCODE_OP_IMM: reg_wen = 1;
        `OPCODE_STORE: reg_wen = 0;
        `OPCODE_OP: reg_wen = 1;
        `OPCODE_LUI: reg_wen = 1;
        `OPCODE_JALR: reg_wen = 1;
        default: reg_wen = 0;
        endcase
        // 对wb_type的译码
        case (instruction[6:0])
        `OPCODE_LOAD: wb_type = `WB_TYPE_MEM;
        `OPCODE_OP_IMM: wb_type = `WB_TYPE_ALU;
        `OPCODE_STORE: wb_type = 0;
        `OPCODE_OP: wb_type = `WB_TYPE_ALU;
        `OPCODE_LUI: wb_type = `WB_TYPE_IMM;
        `OPCODE_JALR: wb_type = `WB_TYPE_PCP4;
        default: wb_type = 0;
        endcase
    end
endmodule

