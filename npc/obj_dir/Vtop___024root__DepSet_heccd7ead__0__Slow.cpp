// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->top__DOT__pc = 0U;
    vlSelf->top__DOT__next_pc = 0U;
    vlSelf->top__DOT__mem_rdata = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/top.v", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(vlSelf->top__DOT__pc, vlSelf->__Vfunc_top__DOT__pmem_read__0__Vfuncout);
    vlSelf->top__DOT__instruction = vlSelf->__Vfunc_top__DOT__pmem_read__0__Vfuncout;
    if ((0x40U & vlSelf->top__DOT__instruction)) {
        vlSelf->top__DOT__reg_wen = ((1U & (vlSelf->top__DOT__instruction 
                                            >> 5U)) 
                                     && ((1U & (~ (vlSelf->top__DOT__instruction 
                                                   >> 4U))) 
                                         && ((1U & 
                                              (~ (vlSelf->top__DOT__instruction 
                                                  >> 3U))) 
                                             && ((1U 
                                                  & (vlSelf->top__DOT__instruction 
                                                     >> 2U)) 
                                                 && ((1U 
                                                      & (vlSelf->top__DOT__instruction 
                                                         >> 1U)) 
                                                     && (1U 
                                                         & vlSelf->top__DOT__instruction))))));
        vlSelf->top__DOT__wb_type = ((0x20U & vlSelf->top__DOT__instruction)
                                      ? ((0x10U & vlSelf->top__DOT__instruction)
                                          ? 0U : ((8U 
                                                   & vlSelf->top__DOT__instruction)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->top__DOT__instruction)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->top__DOT__instruction)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->top__DOT__instruction)
                                                      ? 1U
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)))
                                      : 0U);
        vlSelf->top__DOT__memr_mask = 0U;
        vlSelf->top__DOT__imm_ext_type = 0U;
    } else if ((0x20U & vlSelf->top__DOT__instruction)) {
        vlSelf->top__DOT__reg_wen = ((1U & (vlSelf->top__DOT__instruction 
                                            >> 4U)) 
                                     && ((1U & (~ (vlSelf->top__DOT__instruction 
                                                   >> 3U))) 
                                         && ((4U & vlSelf->top__DOT__instruction)
                                              ? ((1U 
                                                  & (vlSelf->top__DOT__instruction 
                                                     >> 1U)) 
                                                 && (1U 
                                                     & vlSelf->top__DOT__instruction))
                                              : ((1U 
                                                  & (vlSelf->top__DOT__instruction 
                                                     >> 1U)) 
                                                 && (1U 
                                                     & vlSelf->top__DOT__instruction)))));
        if ((0x10U & vlSelf->top__DOT__instruction)) {
            if ((8U & vlSelf->top__DOT__instruction)) {
                vlSelf->top__DOT__wb_type = 0U;
                vlSelf->top__DOT__imm_ext_type = 0U;
            } else if ((4U & vlSelf->top__DOT__instruction)) {
                vlSelf->top__DOT__wb_type = 0U;
                vlSelf->top__DOT__imm_ext_type = ((2U 
                                                   & vlSelf->top__DOT__instruction)
                                                   ? 
                                                  ((1U 
                                                    & vlSelf->top__DOT__instruction)
                                                    ? 3U
                                                    : 0U)
                                                   : 0U);
            } else {
                vlSelf->top__DOT__wb_type = ((2U & vlSelf->top__DOT__instruction)
                                              ? ((1U 
                                                  & vlSelf->top__DOT__instruction)
                                                  ? 2U
                                                  : 0U)
                                              : 0U);
                vlSelf->top__DOT__imm_ext_type = 0U;
            }
        } else {
            vlSelf->top__DOT__wb_type = 0U;
            vlSelf->top__DOT__imm_ext_type = ((8U & vlSelf->top__DOT__instruction)
                                               ? 0U
                                               : ((4U 
                                                   & vlSelf->top__DOT__instruction)
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & vlSelf->top__DOT__instruction)
                                                    ? 
                                                   ((1U 
                                                     & vlSelf->top__DOT__instruction)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)));
        }
        vlSelf->top__DOT__memr_mask = 0U;
    } else {
        if ((0x10U & vlSelf->top__DOT__instruction)) {
            vlSelf->top__DOT__reg_wen = ((1U & (~ (vlSelf->top__DOT__instruction 
                                                   >> 3U))) 
                                         && ((1U & 
                                              (~ (vlSelf->top__DOT__instruction 
                                                  >> 2U))) 
                                             && ((1U 
                                                  & (vlSelf->top__DOT__instruction 
                                                     >> 1U)) 
                                                 && (1U 
                                                     & vlSelf->top__DOT__instruction))));
            vlSelf->top__DOT__wb_type = ((8U & vlSelf->top__DOT__instruction)
                                          ? 0U : ((4U 
                                                   & vlSelf->top__DOT__instruction)
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & vlSelf->top__DOT__instruction)
                                                    ? 
                                                   ((1U 
                                                     & vlSelf->top__DOT__instruction)
                                                     ? 2U
                                                     : 0U)
                                                    : 0U)));
            vlSelf->top__DOT__memr_mask = 0U;
        } else {
            vlSelf->top__DOT__reg_wen = ((1U & (~ (vlSelf->top__DOT__instruction 
                                                   >> 3U))) 
                                         && ((1U & 
                                              (~ (vlSelf->top__DOT__instruction 
                                                  >> 2U))) 
                                             && ((1U 
                                                  & (vlSelf->top__DOT__instruction 
                                                     >> 1U)) 
                                                 && (1U 
                                                     & vlSelf->top__DOT__instruction))));
            if ((8U & vlSelf->top__DOT__instruction)) {
                vlSelf->top__DOT__wb_type = 0U;
                vlSelf->top__DOT__memr_mask = 0U;
            } else if ((4U & vlSelf->top__DOT__instruction)) {
                vlSelf->top__DOT__wb_type = 0U;
                vlSelf->top__DOT__memr_mask = 0U;
            } else if ((2U & vlSelf->top__DOT__instruction)) {
                if ((1U & vlSelf->top__DOT__instruction)) {
                    vlSelf->top__DOT__wb_type = 3U;
                    vlSelf->top__DOT__memr_mask = (
                                                   (4U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->top__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->top__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 1U
                                                     : 0U));
                } else {
                    vlSelf->top__DOT__wb_type = 0U;
                    vlSelf->top__DOT__memr_mask = 0U;
                }
            } else {
                vlSelf->top__DOT__wb_type = 0U;
                vlSelf->top__DOT__memr_mask = 0U;
            }
        }
        vlSelf->top__DOT__imm_ext_type = 0U;
    }
    vlSelf->meet_ebreak = (0x100073U == vlSelf->top__DOT__instruction);
    vlSelf->top__DOT__imm = ((4U & (IData)(vlSelf->top__DOT__imm_ext_type))
                              ? ((2U & (IData)(vlSelf->top__DOT__imm_ext_type))
                                  ? 0U : ((1U & (IData)(vlSelf->top__DOT__imm_ext_type))
                                           ? 0U : (
                                                   ((- (IData)(
                                                               (vlSelf->top__DOT__instruction 
                                                                >> 0x1fU))) 
                                                    << 0x15U) 
                                                   | ((0x100000U 
                                                       & (vlSelf->top__DOT__instruction 
                                                          >> 0xbU)) 
                                                      | ((0xff000U 
                                                          & vlSelf->top__DOT__instruction) 
                                                         | ((0x800U 
                                                             & (vlSelf->top__DOT__instruction 
                                                                >> 9U)) 
                                                            | (0x7feU 
                                                               & (vlSelf->top__DOT__instruction 
                                                                  >> 0x14U))))))))
                              : ((2U & (IData)(vlSelf->top__DOT__imm_ext_type))
                                  ? ((1U & (IData)(vlSelf->top__DOT__imm_ext_type))
                                      ? (0xfffff000U 
                                         & vlSelf->top__DOT__instruction)
                                      : (((- (IData)(
                                                     (vlSelf->top__DOT__instruction 
                                                      >> 0x1fU))) 
                                          << 0xdU) 
                                         | ((0x1000U 
                                             & (vlSelf->top__DOT__instruction 
                                                >> 0x13U)) 
                                            | ((0x800U 
                                                & (vlSelf->top__DOT__instruction 
                                                   << 4U)) 
                                               | ((0x7e0U 
                                                   & (vlSelf->top__DOT__instruction 
                                                      >> 0x14U)) 
                                                  | (0x1eU 
                                                     & (vlSelf->top__DOT__instruction 
                                                        >> 7U)))))))
                                  : ((1U & (IData)(vlSelf->top__DOT__imm_ext_type))
                                      ? (((- (IData)(
                                                     (vlSelf->top__DOT__instruction 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | ((0xfe0U 
                                             & (vlSelf->top__DOT__instruction 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->top__DOT__instruction 
                                                  >> 7U))))
                                      : (((- (IData)(
                                                     (vlSelf->top__DOT__instruction 
                                                      >> 0x1fU))) 
                                          << 0xcU) 
                                         | (vlSelf->top__DOT__instruction 
                                            >> 0x14U)))));
    vlSelf->top__DOT__alu_out = (((0U == (0x1fU & (vlSelf->top__DOT__instruction 
                                                   >> 0xfU)))
                                   ? 0U : vlSelf->top__DOT__regfile__DOT__storage
                                  [(0x1fU & (vlSelf->top__DOT__instruction 
                                             >> 0xfU))]) 
                                 + (((1U & (~ (vlSelf->top__DOT__instruction 
                                               >> 6U))) 
                                     && ((1U & (vlSelf->top__DOT__instruction 
                                                >> 5U)) 
                                         && ((1U & 
                                              (vlSelf->top__DOT__instruction 
                                               >> 4U)) 
                                             && ((1U 
                                                  & (~ 
                                                     (vlSelf->top__DOT__instruction 
                                                      >> 3U))) 
                                                 && ((1U 
                                                      & (~ 
                                                         (vlSelf->top__DOT__instruction 
                                                          >> 2U))) 
                                                     && ((1U 
                                                          & (vlSelf->top__DOT__instruction 
                                                             >> 1U)) 
                                                         && (1U 
                                                             & vlSelf->top__DOT__instruction)))))))
                                     ? ((0U == (0x1fU 
                                                & (vlSelf->top__DOT__instruction 
                                                   >> 0x14U)))
                                         ? 0U : vlSelf->top__DOT__regfile__DOT__storage
                                        [(0x1fU & (vlSelf->top__DOT__instruction 
                                                   >> 0x14U))])
                                     : vlSelf->top__DOT__imm));
    vlSelf->top__DOT__next_pc = (((1U & (vlSelf->top__DOT__instruction 
                                         >> 6U)) && 
                                  ((1U & (vlSelf->top__DOT__instruction 
                                          >> 5U)) && 
                                   ((1U & (~ (vlSelf->top__DOT__instruction 
                                              >> 4U))) 
                                    && ((1U & (~ (vlSelf->top__DOT__instruction 
                                                  >> 3U))) 
                                        && ((1U & (vlSelf->top__DOT__instruction 
                                                   >> 2U)) 
                                            && ((1U 
                                                 & (vlSelf->top__DOT__instruction 
                                                    >> 1U)) 
                                                && (1U 
                                                    & vlSelf->top__DOT__instruction)))))))
                                  ? (0xfffffffeU & vlSelf->top__DOT__alu_out)
                                  : ((IData)(4U) + vlSelf->top__DOT__pc));
    if ((((1U & (~ (vlSelf->top__DOT__instruction >> 6U))) 
          && ((1U & (~ (vlSelf->top__DOT__instruction 
                        >> 5U))) && ((1U & (~ (vlSelf->top__DOT__instruction 
                                               >> 4U))) 
                                     && ((1U & (~ (vlSelf->top__DOT__instruction 
                                                   >> 3U))) 
                                         && ((1U & 
                                              (~ (vlSelf->top__DOT__instruction 
                                                  >> 2U))) 
                                             && ((1U 
                                                  & (vlSelf->top__DOT__instruction 
                                                     >> 1U)) 
                                                 && (1U 
                                                     & vlSelf->top__DOT__instruction))))))) 
         & (~ (IData)(vlSelf->meet_ebreak)))) {
        if ((0U == (IData)(vlSelf->top__DOT__memr_mask))) {
            Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(vlSelf->top__DOT__alu_out, vlSelf->__Vfunc_top__DOT__pmem_read__1__Vfuncout);
            vlSelf->top__DOT__tmp = vlSelf->__Vfunc_top__DOT__pmem_read__1__Vfuncout;
            vlSelf->top__DOT__mem_rdata = (0xffU & vlSelf->top__DOT__tmp);
        } else if ((1U == (IData)(vlSelf->top__DOT__memr_mask))) {
            Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(vlSelf->top__DOT__alu_out, vlSelf->__Vfunc_top__DOT__pmem_read__2__Vfuncout);
            vlSelf->top__DOT__mem_rdata = vlSelf->__Vfunc_top__DOT__pmem_read__2__Vfuncout;
        } else {
            vlSelf->top__DOT__mem_rdata = 0U;
        }
    } else {
        vlSelf->top__DOT__mem_rdata = 0U;
    }
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->meet_ebreak = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__instruction = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__reg_wen = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__imm_ext_type = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__memr_mask = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__wb_type = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__alu_out = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__mem_rdata = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__tmp = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__storage[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__regfile__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_top__DOT__pmem_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__pmem_read__1__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__pmem_read__2__Vfuncout = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
