// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN-SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(meet_ebreak,0,0);
    VL_OUT8(is_load_export,0,0);
    VL_IN8(__pinNumber5,0,0);
    CData/*0:0*/ top__DOT__lsu_reqValid;
    CData/*1:0*/ top__DOT__npc__DOT__ifu_status;
    CData/*0:0*/ top__DOT__npc__DOT__meet_ebreak_r;
    CData/*2:0*/ top__DOT__npc__DOT__control__DOT__imm_ext_type;
    CData/*0:0*/ top__DOT__npc__DOT__control__DOT__mem_wen;
    CData/*2:0*/ top__DOT__npc__DOT__control__DOT__memr_mask;
    CData/*1:0*/ top__DOT__npc__DOT__control__DOT__wb_type;
    CData/*0:0*/ top__DOT__simple_bus__DOT__ifu_respValid;
    CData/*0:0*/ top__DOT__simple_bus__DOT__lsu_respValid;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP____pinNumber5__0;
    CData/*0:0*/ __VicoDidInit;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    IData/*31:0*/ top__DOT__npc__DOT__pc;
    IData/*31:0*/ top__DOT__npc__DOT__next_pc;
    IData/*31:0*/ top__DOT__npc__DOT__alu__DOT__alu_out;
    IData/*31:0*/ top__DOT__npc__DOT__immgen__DOT__imm;
    IData/*31:0*/ top__DOT__npc__DOT__regfile__DOT__rdata_rs2;
    IData/*31:0*/ top__DOT__npc__DOT__regfile__DOT__i;
    IData/*31:0*/ top__DOT__simple_bus__DOT____VlemCond_1;
    IData/*31:0*/ top__DOT__simple_bus__DOT____VlemCall_0__pmem_read;
    IData/*31:0*/ top__DOT__simple_bus__DOT__ifu_rdata;
    IData/*31:0*/ top__DOT__simple_bus__DOT__lsu_rdata;
    IData/*31:0*/ top__DOT__simple_bus__DOT__tmp;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__npc__DOT__regfile__DOT__storage;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __VtraceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
};


#endif  // guard
