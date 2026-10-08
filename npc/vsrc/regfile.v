module regfile(
    input clk,
    input rst,
    input wen,
    input [4:0] waddr,
    input [31:0] wdata,
    input [4:0] raddr_rs1,
    output [31:0] rdata_rs1,
    input [4:0] raddr_rs2,
    output [31:0] rdata_rs2
);
    // 寄存器文件
    reg [31:0] storage [0:31];

    // 写逻辑
    integer i;
    always @(posedge clk) begin
        if (rst) begin
            for (i = 0; i < 32; i = i + 1)
                storage[i] <= 0;
        end
        else if (wen && waddr != 5'd0) 
            storage[waddr] <= wdata;
    end

    // 读逻辑
    assign rdata_rs1 = raddr_rs1 == 0 ? 0 : storage[raddr_rs1];
    assign rdata_rs2 = raddr_rs2 == 0 ? 0 : storage[raddr_rs2];
endmodule
