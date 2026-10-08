// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);
void Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__top__DOT__pc;
    __Vdly__top__DOT__pc = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__regfile__DOT__storage__v0;
    __Vdlyvset__top__DOT__regfile__DOT__storage__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__regfile__DOT__storage__v32;
    __Vdlyvdim0__top__DOT__regfile__DOT__storage__v32 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__regfile__DOT__storage__v32;
    __Vdlyvval__top__DOT__regfile__DOT__storage__v32 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__regfile__DOT__storage__v32;
    __Vdlyvset__top__DOT__regfile__DOT__storage__v32 = 0;
    // Body
    if ((((1U & (~ (vlSelf->top__DOT__instruction >> 6U))) 
          && ((1U & (vlSelf->top__DOT__instruction 
                     >> 5U)) && ((1U & (~ (vlSelf->top__DOT__instruction 
                                           >> 4U))) 
                                 && ((1U & (~ (vlSelf->top__DOT__instruction 
                                               >> 3U))) 
                                     && ((1U & (~ (vlSelf->top__DOT__instruction 
                                                   >> 2U))) 
                                         && ((1U & 
                                              (vlSelf->top__DOT__instruction 
                                               >> 1U)) 
                                             && (1U 
                                                 & vlSelf->top__DOT__instruction))))))) 
         & (~ (IData)(vlSelf->meet_ebreak)))) {
        Vtop___024root____Vdpiimwrap_top__DOT__pmem_write_TOP(vlSelf->top__DOT__alu_out, 
                                                              ((0U 
                                                                == 
                                                                (0x1fU 
                                                                 & (vlSelf->top__DOT__instruction 
                                                                    >> 0x14U)))
                                                                ? 0U
                                                                : 
                                                               vlSelf->top__DOT__regfile__DOT__storage
                                                               [
                                                               (0x1fU 
                                                                & (vlSelf->top__DOT__instruction 
                                                                   >> 0x14U))]), 
                                                              ((0x40U 
                                                                & vlSelf->top__DOT__instruction)
                                                                ? 0U
                                                                : 
                                                               ((0x20U 
                                                                 & vlSelf->top__DOT__instruction)
                                                                 ? 
                                                                ((0x10U 
                                                                  & vlSelf->top__DOT__instruction)
                                                                  ? 0U
                                                                  : 
                                                                 ((8U 
                                                                   & vlSelf->top__DOT__instruction)
                                                                   ? 0U
                                                                   : 
                                                                  ((4U 
                                                                    & vlSelf->top__DOT__instruction)
                                                                    ? 0U
                                                                    : 
                                                                   ((2U 
                                                                     & vlSelf->top__DOT__instruction)
                                                                     ? 
                                                                    ((1U 
                                                                      & vlSelf->top__DOT__instruction)
                                                                      ? 
                                                                     ((0U 
                                                                       == 
                                                                       (7U 
                                                                        & (vlSelf->top__DOT__instruction 
                                                                           >> 0xcU)))
                                                                       ? 1U
                                                                       : 
                                                                      ((2U 
                                                                        == 
                                                                        (7U 
                                                                         & (vlSelf->top__DOT__instruction 
                                                                            >> 0xcU)))
                                                                        ? 0xfU
                                                                        : 0U))
                                                                      : 0U)
                                                                     : 0U))))
                                                                 : 0U)));
    }
    __Vdly__top__DOT__pc = vlSelf->top__DOT__pc;
    __Vdlyvset__top__DOT__regfile__DOT__storage__v0 = 0U;
    __Vdlyvset__top__DOT__regfile__DOT__storage__v32 = 0U;
    if (vlSelf->rst) {
        vlSelf->top__DOT__regfile__DOT__i = 0x20U;
        __Vdly__top__DOT__pc = 0U;
        __Vdlyvset__top__DOT__regfile__DOT__storage__v0 = 1U;
    } else {
        __Vdly__top__DOT__pc = ((0x100073U == vlSelf->top__DOT__instruction)
                                 ? vlSelf->top__DOT__pc
                                 : vlSelf->top__DOT__next_pc);
        if ((((~ (IData)(vlSelf->top__DOT__meet_ebreak_r)) 
              & (IData)(vlSelf->top__DOT__reg_wen)) 
             & (0U != (0x1fU & (vlSelf->top__DOT__instruction 
                                >> 7U))))) {
            __Vdlyvval__top__DOT__regfile__DOT__storage__v32 
                = ((2U & (IData)(vlSelf->top__DOT__wb_type))
                    ? ((1U & (IData)(vlSelf->top__DOT__wb_type))
                        ? vlSelf->top__DOT__mem_rdata
                        : vlSelf->top__DOT__alu_out)
                    : ((1U & (IData)(vlSelf->top__DOT__wb_type))
                        ? ((IData)(4U) + vlSelf->top__DOT__pc)
                        : vlSelf->top__DOT__imm));
            __Vdlyvset__top__DOT__regfile__DOT__storage__v32 = 1U;
            __Vdlyvdim0__top__DOT__regfile__DOT__storage__v32 
                = (0x1fU & (vlSelf->top__DOT__instruction 
                            >> 7U));
        }
    }
    if (__Vdlyvset__top__DOT__regfile__DOT__storage__v0) {
        vlSelf->top__DOT__regfile__DOT__storage[0U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[1U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[2U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[3U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[4U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[5U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[6U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[7U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[8U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[9U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0xaU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0xbU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0xcU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0xdU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0xeU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0xfU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x10U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x11U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x12U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x13U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x14U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x15U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x16U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x17U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x18U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x19U] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x1aU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x1bU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x1cU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x1dU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x1eU] = 0U;
        vlSelf->top__DOT__regfile__DOT__storage[0x1fU] = 0U;
    }
    if (__Vdlyvset__top__DOT__regfile__DOT__storage__v32) {
        vlSelf->top__DOT__regfile__DOT__storage[__Vdlyvdim0__top__DOT__regfile__DOT__storage__v32] 
            = __Vdlyvval__top__DOT__regfile__DOT__storage__v32;
    }
    vlSelf->top__DOT__pc = __Vdly__top__DOT__pc;
    vlSelf->top__DOT__meet_ebreak_r = (0x100073U == vlSelf->top__DOT__instruction);
    Vtop___024root____Vdpiimwrap_top__DOT__pmem_read_TOP(vlSelf->top__DOT__pc, vlSelf->__Vfunc_top__DOT__pmem_read__0__Vfuncout);
    vlSelf->top__DOT__instruction = vlSelf->__Vfunc_top__DOT__pmem_read__0__Vfuncout;
    vlSelf->meet_ebreak = vlSelf->top__DOT__meet_ebreak_r;
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/top.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
