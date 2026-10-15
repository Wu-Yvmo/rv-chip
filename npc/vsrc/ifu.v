module ifu(
    input clk,
    input rst,
    input ren,
    input [31:0] addr,
    output reg [31:0] instruction
);
    // C++提供的内存访问接口
    import "DPI-C" function int pmem_read(input int raddr); // 内存读逻辑
    import "DPI-C" function void pmem_write(
        input int waddr, 
        input int wdata, 
        input byte wmask
    ); // 内存写逻辑
    // 要不要把ifu_addr放进这个模块里面?
    always @(posedge clk) begin
        if (rst) instruction <= 0;
        else if (ren) instruction <= pmem_read(addr);
        else instruction <= instruction;
    end
endmodule