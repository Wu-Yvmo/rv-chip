`include "defines.v"

// 这是不是意味着我们得单独抽象出来一个取指令的逻辑?
// 需要有状态机
// 名为IFU的模块

module npc(
    input clk,
    input rst,
    output meet_ebreak,
    output reg is_load_export,
    // 下面信号为simple bus相关
    // ifu相关信号
    output ifu_reqValid,
    output [31:0] ifu_raddr,
    input [31:0] ifu_rdata,
    input ifu_respValid,
    // lsu相关信号
    output lsu_reqValid,
    output [31:0] lsu_raddr,
    output [2:0] lsu_rmask,
    input [31:0] lsu_rdata,
    output lsu_wen,
    output [31:0] lsu_waddr,
    output [3:0] lsu_wmask,
    output [31:0] lsu_wdata,
    input lsu_respValid
);
    // 目前要处理的就是读内存的问题
    // 对
    // 不能有读使能
    // 处理ifu相关连线
    assign ifu_reqValid = ifu_status == `IFU_STATUS_IDLE;
    assign ifu_raddr = pc;
    // 处理lsu相关连线
    assign lsu_reqValid = (ifu_status == `IFU_STATUS_WAIT) && (is_load | is_store);
    assign lsu_raddr = alu_out;
    assign lsu_rmask = memr_mask;
    // lsu_rdata送回那个啥地方做写回处理
    assign lsu_wen = mem_wen;
    assign lsu_waddr = alu_out;
    assign lsu_wmask = memw_mask;
    assign lsu_wdata = rs2_data;
    
    // C++提供的内存访问接口
    // import "DPI-C" function int pmem_read(input int raddr); // 内存读逻辑
    // import "DPI-C" function void pmem_write(
    //     input int waddr, 
    //     input int wdata, 
    //     input byte wmask
    // ); // 内存写逻辑
    // 将pmen中的ifu_status设置为idle
    import "DPI-C" function void ifu_status_at_idle();
    // 将pmen中的ifu_status设置为wait
    import "DPI-C" function void ifu_status_at_wait();
    // 将pmem中的ifu_status设置为wait load
    import "DPI-C" function void ifu_status_at_wait_load();

    // ifu状态机变量
    reg [1:0] ifu_status;
    // ifu状态转移逻辑
    always @(posedge clk) begin
        if (rst) begin 
            ifu_status <= `IFU_STATUS_IDLE;
            ifu_status_at_idle();
        end
        else begin
            // 需要找个办法把任务完成这件事给转发出去
            if (ifu_status == `IFU_STATUS_IDLE && ifu_respValid) begin
                ifu_status <= `IFU_STATUS_WAIT;
                ifu_status_at_wait();
            end
            // 我们要尝试重新写一下跳转的逻辑
            else if (ifu_status == `IFU_STATUS_WAIT) begin
                // is_load需要从control出来
                if (is_load) begin
                    ifu_status <= `IFU_STATUS_WAIT_LOAD;
                    ifu_status_at_wait_load();
                end
                // 这里如果后面write也有延迟 就需要引入处理手段
                else begin 
                    ifu_status <= `IFU_STATUS_IDLE;
                    ifu_status_at_idle();
                end
            end
            // 当前状态为wait-load
            else begin
                if (lsu_respValid) begin
                    ifu_status <= `IFU_STATUS_IDLE;
                    ifu_status_at_idle();
                end
            end
        end
    end

    // IF阶段 取指令
    reg [31:0] pc = 32'h80000000;
    reg [31:0] next_pc;
    wire inner_meet_ebreak;
    always @(posedge clk) begin // pc的更新
        if (rst) pc <= 32'h80000000; // 目前的复位值修改为0x80000000
        // pc只在
        // 1.没遇到ebreak
        // 2.ifu是wait且不是控制语句
        // 3.ifu是wait_load
        // 条件2和条件3是或的关系
        // 才更新
        else if (~inner_meet_ebreak & ((ifu_status == `IFU_STATUS_WAIT && ~is_load) | (ifu_status == `IFU_STATUS_WAIT_LOAD))) pc <= next_pc;
        else pc <= pc;
    end

    wire [31:0] instruction;
    assign instruction = ifu_rdata;
    
    // reg meet_ebreak_r = instruction == 32'h00100073;
    assign inner_meet_ebreak = instruction == 32'h00100073;
    
    reg meet_ebreak_r;
    always @(posedge clk) begin
        meet_ebreak_r <= inner_meet_ebreak;
    end
    assign meet_ebreak = meet_ebreak_r;

    // deepseek给的建议是把ebreak打一拍再输出
    // assign meet_ebreak = meet_ebreak_r;

    // ID阶段 生成控制信号 读寄存器
    wire reg_wen;
    wire [4:0] reg_waddr = instruction[11:7];
    reg [31:0] reg_wdata;
    wire [4:0] rs1_addr = instruction[19:15];
    wire [31:0] rs1_data;
    wire[4:0] rs2_addr = instruction[24:20];
    wire [31:0] rs2_data;
    regfile regfile(
        .clk (clk),
        .rst (rst),
        // 寄存器堆只有在两个条件同时满足时才可以写：
        // 没遇到ebreak
        // 为wait且不是load 或 为wait load
        // 才允许写
        .wen (reg_wen & ~meet_ebreak & ((ifu_status == `IFU_STATUS_WAIT && ~is_load) | (ifu_status == `IFU_STATUS_WAIT_LOAD))),
        .waddr (reg_waddr),
        .wdata (reg_wdata),
        .raddr_rs1 (rs1_addr),
        .rdata_rs1 (rs1_data),
        .raddr_rs2 (rs2_addr),
        .rdata_rs2 (rs2_data)
    ); // 寄存器实例化 同时完成连线

    wire [2:0] imm_ext_type;
    wire [3:0] alu_op;
    wire alu_l_sel;
    wire alu_r_sel;
    wire jalr;
    wire mem_wen;
    wire [3:0] memw_mask;
    wire mem_ren;
    wire [2:0] memr_mask;
    wire [1:0] wb_type;
    reg is_load;
    reg is_store;
    assign is_load_export = is_load;
    control control(
        .instruction (instruction),
        .imm_ext_type (imm_ext_type),
        .alu_op (alu_op),
        .alu_l_sel (alu_l_sel),
        .alu_r_sel (alu_r_sel),
        .jalr (jalr),
        .mem_wen (mem_wen),
        .memw_mask (memw_mask),
        .mem_ren (mem_ren),
        .memr_mask (memr_mask),
        .reg_wen (reg_wen),
        .wb_type (wb_type),
        .is_load (is_load),
        .is_store (is_store)
    ); // 控制器实例化 同时完成连线

    wire [31:0] imm;
    immgen immgen(
        .instruction (instruction),
        .imm_ext_type (imm_ext_type),
        .imm (imm)
    ); // 立即数生成器实例化 同时完成连线

    // EX阶段 实例化ALU 生成next_pc
    wire [31:0] alu_l = (alu_l_sel == `ALU_L_SEL_RS1) ? rs1_data : pc;
    wire [31:0] alu_r = (alu_r_sel == `ALU_R_SEL_RS2) ? rs2_data : imm;
    wire [31:0] alu_out;
    alu alu(
        .alu_l (alu_l),
        .alu_r (alu_r),
        .alu_op (alu_op),
        .alu_out (alu_out)
    ); // 实例化 alu

    // 这一步是尝试修改ebreak的行为了
    assign next_pc = jalr ? {alu_out[31:1], 1'b0} : pc + 4; // 生成next_pc
    
    // MEM阶段 完成内存的读写
    // 读写内存的数据都可能怎么流转：
    // 读写使用的地址都来自alu
    // 关于读内存：
    //     应该是读出来后被写入寄存器 写入rd
    //     但这个阶段暂时不处理哪里的数据写入寄存器文件
    // 关于写内存：
    //     写的数据应该来自寄存器的rs2数据
    // 读内存可以安全的放在组合逻辑中 其实也不是特别正确 但单周期就是这样了
    // reg [31:0] mem_rdata = 0;
    // lsu lsu(
    //     .clk (clk),
    //     .ren (mem_ren & ~meet_ebreak & (ifu_status == `IFU_STATUS_WAIT)), // ren 需要根据状态具体设计
    //     .raddr (alu_out),
    //     .rmask (memr_mask),
    //     .rdata (mem_rdata),
    //     .wen (mem_wen & ~meet_ebreak & (ifu_status == `IFU_STATUS_WAIT)), // wen 需要根据具体状态来设计
    //     .waddr (alu_out),
    //     .wmask (memw_mask),
    //     .wdata (rs2_data)
    // );

    // 实例化simple bus模块
    //

    // WB阶段
    // 写回的数据有4个来源：
    // imm pcp4
    // alu
    // mem
    always @(*) begin
        case (wb_type)
        `WB_TYPE_IMM: reg_wdata = imm;
        `WB_TYPE_PCP4: reg_wdata = pc + 4;
        `WB_TYPE_ALU: reg_wdata = alu_out;
        `WB_TYPE_MEM: reg_wdata = lsu_rdata;
        default: reg_wdata = 0;
        endcase
    end
endmodule

// 感觉已经可以尝试抽象出simple_bus的逻辑了
// 不过还是先去散步吧

// 还有一个小问题 那就是我们以前的设置为指令完成状态的机制就不行了
// 判断依据需要变成：
// 非load指令 需要按照wait状态判断
// load指令 需要按照load wait状态判断

// 关于NPC的状态，我目前有这样一种设计
// 常规指令执行2个周期 
//     ifu_idle给地址 
//     ifu_wait拿到指令 执行
// 而设计load store的指令有3个部分
//     1. ifu_idle给地址
//     2.ifu_wait 拿到指令 lsu部分给地址
//     3.如果是load指令就完成读 寄存器写回 如果是store指令完成内存写
// 从状态机来看
// deepseek的说法是需要有一个commit的信号表示指令完成
// commit有效时 ifu-status从wait转为idle
// 否则从wait继续转wait
// commit实际上控制的是写的逻辑 写包括mem写和reg写
// 一个想法是让ifu-status来控制commit字段 和is-load字段联合
// 访存中的写 直接就立刻写好了
// 但是读不一样 读数据延迟一个周期

// 可以设置CPU的状态为： IFing IFed Loaded
// if 表示发起了取指令 没有合法指令
// ifed 表示执行指令 同时如果遇到load可发动读内存
// loaded 表示加载到位了，可以写回

// 设置一个特殊字段 instruction_is_load
// 这样CPU的状态转移就不同了
// CPU永远从IFed转移到Loaded
// 当instruction_is_load为false时 转移到IFing
// 否则 转移为Loaded
// Loaded永远下一周期转移到IFing
// 不我觉得还是靠ifu-status比较合理
// 给ifu-status三个状态
// idle 
// wait
// load

// 接下来整理一下状态转移的逻辑
// idle 到wait是无条件的
// wait到idle需要满足 不是load
// wait 到load 需要满足是load
// load到idle无条件转移

// 要实现的指令一共：
// addi I型
// jalr I型
// add R型
// lui U型
// lw I型
// lbu I型
// sw S型
// sb S型

// addi（I 型）
// +---------------------+--------+-----+-------+--------+
// | imm[11:0]           | rs1    | 000 | rd    | 0010011|
// | 31:20               | 19:15  |14:12| 11:7  | 6:0    |
// +---------------------+--------+-----+-------+--------+
// 行为：
//     x[rd] = x[rs1] + sext(imm[11:0])
//     PC = PC + 4
// 说明：
//     imm 是 12 位有符号立即数。

// jalr（I 型）
// +---------------------+--------+-----+-------+--------+
// | imm[11:0]           | rs1    | 000 | rd    | 1100111|
// | 31:20               | 19:15  |14:12| 11:7  | 6:0    |
// +---------------------+--------+-----+-------+--------+
// 行为：
//     t = PC + 4
//     target = (x[rs1] + sext(imm[11:0])) & 0xFFFFFFFE
//     x[rd] = t
//     PC = target
// 说明：
//     目标地址最低位清零。
//     若 rd = rs1，计算 target 时使用旧的 x[rs1]。
//     若 rd = x0，不保存返回地址。

// add（R 型）
// +---------+--------+--------+-----+-------+--------+
// | 0000000 | rs2    | rs1    | 000 | rd    | 0110011|
// | 31:25   | 24:20  | 19:15  |14:12| 11:7  | 6:0    |
// +---------+--------+--------+-----+-------+--------+
// 行为：
//     x[rd] = x[rs1] + x[rs2]
//     PC = PC + 4

// lui（U 型）
// +-----------------------------------+-------+--------+
// | imm[31:12]                        | rd    | 0110111|
// | 31:12                             | 11:7  | 6:0    |
// +-----------------------------------+-------+--------+
// 行为：
//     x[rd] = {imm[31:12], 12'b0}
//     即 x[rd] = imm[31:12] << 12
//     PC = PC + 4
// 说明：
//     U 型立即数直接放到结果高 20 位，低 12 位清零。

// lw（I 型，LOAD）
// +---------------------+--------+-----+-------+--------+
// | imm[11:0]           | rs1    | 010 | rd    | 0000011|
// | 31:20               | 19:15  |14:12| 11:7  | 6:0    |
// +---------------------+--------+-----+-------+--------+
// 行为：
//     addr = x[rs1] + sext(imm[11:0])
//     x[rd] = M[addr]
//           | (M[addr+1] << 8)
//           | (M[addr+2] << 16)
//           | (M[addr+3] << 24)
//     PC = PC + 4
// 说明：
//     从内存读取 32 位，小端，写入 rd

// lbu（I 型，LOAD）
// +---------------------+--------+-----+-------+--------+
// | imm[11:0]           | rs1    | 100 | rd    | 0000011|
// | 31:20               | 19:15  |14:12| 11:7  | 6:0    |
// +---------------------+--------+-----+-------+--------+
// 行为：
//     addr = x[rs1] + sext(imm[11:0])
//     x[rd] = zero_extend(M[addr], 32)
//     PC = PC + 4
// 说明：
//     从内存读取 1 字节，零扩展到 32 位，写入 rd。

// sw（S 型，STORE）
// +----------+--------+--------+-----+---------+--------+
// | imm[11:5]| rs2    | rs1    | 010 | imm[4:0]| 0100011|
// | 31:25    | 24:20  | 19:15  |14:12| 11:7    | 6:0    |
// +----------+--------+--------+-----+---------+--------+
// 行为：
//     addr = x[rs1] + sext(imm[11:0])
//     M[addr]   = x[rs2][7:0]
//     M[addr+1] = x[rs2][15:8]
//     M[addr+2] = x[rs2][23:16]
//     M[addr+3] = x[rs2][31:24]
//     PC = PC + 4
// 说明：
//     把 rs2 的 32 位值按小端写入内存。

// sb（S 型，STORE）
// +----------+--------+--------+-----+---------+--------+
// | imm[11:5]| rs2    | rs1    | 000 | imm[4:0]| 0100011|
// | 31:25    | 24:20  | 19:15  |14:12| 11:7    | 6:0    |
// +----------+--------+--------+-----+---------+--------+
// 行为：
//     addr = x[rs1] + sext(imm[11:0])
//     M[addr] = x[rs2][7:0]
//     PC = PC + 4
// 说明：
//     只把 rs2 的最低 8 位写入内存。

// 下一步干：
// 把模拟器写起来 然后进行对比判断设计有没有问题
