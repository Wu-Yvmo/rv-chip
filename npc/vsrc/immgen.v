`include "defines.v"

module immgen(
    input [31:0] instruction,
    input [2:0] imm_ext_type,
    output reg [31:0] imm
);
    always @(*) begin
        case (imm_ext_type)
        `IMM_EXT_TYPE_I: imm = {{20{instruction[31]}}, instruction[31:20]};
        `IMM_EXT_TYPE_S: imm = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
        `IMM_EXT_TYPE_B: imm = {{19{instruction[31]}}, instruction[31], instruction[7], instruction[30:25], instruction[11:8], 1'b0};
        `IMM_EXT_TYPE_U: imm = {instruction[31:12], 12'b0};
        `IMM_EXT_TYPE_J: imm = {{11{instruction[31]}}, instruction[31], instruction[19:12], instruction[20], instruction[30:21], 1'b0};
        default: imm = 32'b0;
        endcase
    end
endmodule
