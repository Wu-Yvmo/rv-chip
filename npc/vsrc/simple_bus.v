// output        lsu_reqValid,
// output [31:0] lsu_addr,
// output        lsu_wen,
// output [31:0] lsu_wdata,
// output [ 3:0] lsu_wmask,
// input         lsu_respValid,
// input  [31:0] lsu_rdata,

// 我想实现的是
// 在cpu内部实例化simple bus后
// 在取指令阶段和访存阶段就都靠simple bus来进行访存抽象了
// 目前先做接口的设计
// 然后再看别的内容

// simple bus和 if lsu的关系是什么?
// output [31:0] ifu_raddr,
// input  [31:0] ifu_rdata,
`include "defines.v"

module simple_bus(
    input clk,
    // if模块的信号
    input ifu_reqValid,
    input [31:0] ifu_raddr,
    output reg [31:0] ifu_rdata,
    output reg ifu_respValid,
    // lsu模块的信号
    input lsu_reqValid,
    input [31:0] lsu_raddr,
    input [2:0] lsu_rmask,
    output [31:0] lsu_rdata,
    input lsu_wen,
    input [31:0] lsu_waddr,
    input [31:0] lsu_wdata,
    input [3:0] lsu_wmask,
    output reg lsu_respValid
);
    // C++提供的内存访问接口
    import "DPI-C" function int pmem_read(input int raddr); // 内存读逻辑
    import "DPI-C" function void pmem_write(
        input int waddr, 
        input int wdata, 
        input byte wmask
    ); // 内存写逻辑
    localparam TIME_ELAPSE = 5;
    integer ifu_time_elapse_ctr = TIME_ELAPSE;
    integer lsu_time_elapse_ctr = TIME_ELAPSE;
    reg ifu_started = 0;
    reg lsu_started = 0;

    // 处理if
    // 思考一下怎么实现延时
    // 首先需要让reqvalid只在idle周期有效
    // 怀疑已经陷入死循环了 尝试诊断一下哪里的问题
    // idle跳转到wait的条件就是ifu回复 reqvalid 所以这里应该不行?
    // 问题就在这里出现
    always @(posedge clk) begin
        if (ifu_reqValid && ~ifu_started) begin
            ifu_time_elapse_ctr <= TIME_ELAPSE;
            ifu_started <= 1;
        end
        else if (ifu_time_elapse_ctr == 0) begin
            ifu_rdata <= pmem_read(ifu_raddr);
            ifu_respValid <= 1;
            ifu_started <= 0;
        end
        else if (ifu_started) 
            ifu_time_elapse_ctr <= ifu_time_elapse_ctr - 1;
    end

    // 只让ifu_respValid持续1周期
    // 没什么用
    always @(posedge clk) begin
        if (ifu_respValid) ifu_respValid <= 0;
    end

    // 处理lsu
    reg [31:0] tmp;
    always @(posedge clk) begin
        // 读直达
        tmp = (lsu_reqValid && ~lsu_wen) ? pmem_read(lsu_raddr) : 0;
        case (lsu_rmask)
        `MEMR_MASK_LBU: begin
            lsu_rdata <= {{24{1'b0}}, tmp[7:0]};
        end
        `MEMR_MASK_LW: lsu_rdata <= tmp;
        default:;
        // 写相关
        endcase
        if (lsu_reqValid) begin
            if (lsu_wen) begin
                pmem_write(lsu_waddr, lsu_wdata, {{4{1'b0}}, lsu_wmask});
            end
        end
        lsu_respValid <= 1;
    end
endmodule

// ifu 和 lsu 与 simple bus的关系是什么？
// 我的预期是，这俩应当靠simple bus来取数据 这样就可以比较合理的接入soc
// 拿ifu举个例子
// npc应当有状态
// npc接收一个if_finish信号

// 必须要搞清楚的点是 写simple bus就是为了后面接入soc
// 我们不妨暂时认定simple bus已经到位 思考一下其他代码怎么跟着动作