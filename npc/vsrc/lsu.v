`include "defines.v"

module lsu(
    input clk,
    // 读部分
    input ren,
    input [31:0] raddr,
    input [2:0] rmask,
    output reg [31:0] rdata,
    // 写部分
    input wen,
    input [31:0] waddr,
    input [3:0] wmask,
    input [31:0] wdata
);
    // C++提供的内存访问接口
    import "DPI-C" function int pmem_read(input int raddr); // 内存读逻辑
    import "DPI-C" function void pmem_write(
        input int waddr, 
        input int wdata, 
        input byte wmask
    ); // 内存写逻辑

    reg [31:0] tmp;
    always @(posedge clk) begin
        if (ren) begin
            tmp = pmem_read(raddr); // 那外设的访问呢?
            case (rmask)
            `MEMR_MASK_LBU: begin
                tmp = pmem_read(raddr);
                rdata <= {{24{1'b0}}, tmp[7:0]};
            end
            `MEMR_MASK_LW: rdata <= pmem_read(raddr);
            default:;
            endcase
            // 这里要把写的逻辑复制过来 暂时先不做了
            // 先把模块调用方式研究明白再调用
        end
        if (wen) begin
            pmem_write(waddr, wdata, {{4{1'b0}}, wmask});
        end
    end
endmodule