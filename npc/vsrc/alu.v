`include "defines.v"

module alu(
    input [31:0] alu_l,
    input [31:0] alu_r,
    input [3:0] alu_op,
    output reg [31:0] alu_out
);
    always @(*) begin
        case (alu_op)
        `ALU_OP_ADD: alu_out = $signed(alu_l) + $signed(alu_r);
        default: alu_out = 0;
        endcase
    end
endmodule
