// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(meet_ebreak,0,0);
    CData/*0:0*/ top__DOT__reg_wen;
    CData/*2:0*/ top__DOT__imm_ext_type;
    CData/*2:0*/ top__DOT__memr_mask;
    CData/*1:0*/ top__DOT__wb_type;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top__DOT__pc;
    IData/*31:0*/ top__DOT__next_pc;
    IData/*31:0*/ top__DOT__instruction;
    IData/*31:0*/ top__DOT__imm;
    IData/*31:0*/ top__DOT__alu_out;
    IData/*31:0*/ top__DOT__mem_rdata;
    IData/*31:0*/ top__DOT__tmp;
    IData/*31:0*/ top__DOT__regfile__DOT__i;
    IData/*31:0*/ __Vfunc_top__DOT__pmem_read__0__Vfuncout;
    IData/*31:0*/ __Vfunc_top__DOT__pmem_read__1__Vfuncout;
    IData/*31:0*/ __Vfunc_top__DOT__pmem_read__2__Vfuncout;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__storage;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
