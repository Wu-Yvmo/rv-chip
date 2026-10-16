module top(
    input clk,
    input rst,
    output meet_ebreak,
    output is_load_export,
);
    // 实例化npc
    // wire meet_ebreak;
    // wire is_load_export;
    //     ifu相关信号
    wire ifu_reqValid;
    wire [31:0] ifu_raddr;
    wire [31:0] ifu_rdata;
    wire ifu_respValid;
    //     lsu相关信号
    wire lsu_reqValid;
    wire [31:0] lsu_raddr;
    wire [2:0] lsu_rmask;
    wire lsu_wen;
    wire [31:0] lsu_waddr;
    wire [31:0] lsu_wdata;
    wire [3:0] lsu_wmask;
    wire lsu_respValid;
    wire [31:0] lsu_rdata;
    //     正式实例化
    npc npc(
        .clk (clk),
        .rst (rst),
        .meet_ebreak (meet_ebreak),
        .is_load_export (is_load_export),
        // ifu相关信号
        .ifu_reqValid (ifu_reqValid),
        .ifu_raddr (ifu_raddr),
        .ifu_rdata (ifu_rdata),
        .ifu_respValid (ifu_respValid),
        // lsu相关信号
        .lsu_reqValid (lsu_reqValid),
        .lsu_raddr (lsu_raddr),
        .lsu_rmask (lsu_rmask),
        .lsu_wen (lsu_wen),
        .lsu_waddr (lsu_waddr),
        .lsu_wmask (lsu_wmask),
        .lsu_wdata (lsu_wdata),
        .lsu_respValid (lsu_respValid),
        .lsu_rdata (lsu_rdata)
    );
    // 实例化simple bus
    simple_bus simple_bus(
        .clk (clk),
        .ifu_reqValid (ifu_reqValid),
        .ifu_raddr (ifu_raddr),
        .ifu_rdata (ifu_rdata),
        .ifu_respValid (ifu_respValid),
        // lsu相关信号
        .lsu_reqValid (lsu_reqValid),
        .lsu_raddr (lsu_raddr),
        .lsu_rmask (lsu_rmask),
        .lsu_wen (lsu_wen),
        .lsu_waddr (lsu_waddr),
        .lsu_wmask (lsu_wmask),
        .lsu_wdata (lsu_wdata),
        .lsu_respValid (lsu_respValid),
        .lsu_rdata (lsu_rdata)
    );
endmodule