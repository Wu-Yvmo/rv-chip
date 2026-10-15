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
module simple_bus(
    input clk,
    // if模块的信号
    input if_reqValid,
    input [31:0] if_addr,
    output [31:0] if_data,
    output reg if_respValid,
    // lsu模块的信号
    input lsu_reqValid,
    input [31:0] lsu_addr,
    input lsu_wen,
    input [31:0] lsu_wdata,
    input [3:0] lsu_wmask,
    output reg lsu_respValid,
    output [31:0] lsu_rdata
);
    // 处理if
    always @(posedge clk) begin
        if (if_reqValid) begin
            // TODO: 完成访存
            if_respValid <= 1;
        end
    end
    // 处理lsu
    always @(posedge clk) begin
        // TODO: 在这里无脑完成读取逻辑
        if (lsu_reqValid) begin
            if (lsu_wen) begin
                // TODO: 在这里完成写入
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