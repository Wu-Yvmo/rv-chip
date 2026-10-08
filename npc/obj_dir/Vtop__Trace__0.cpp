// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__pc),32);
        bufp->chgIData(oldp+1,(vlSelf->top__DOT__next_pc),32);
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__instruction),32);
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__reg_wen));
        bufp->chgCData(oldp+4,((0x1fU & (vlSelf->top__DOT__instruction 
                                         >> 7U))),5);
        bufp->chgIData(oldp+5,(((2U & (IData)(vlSelf->top__DOT__wb_type))
                                 ? ((1U & (IData)(vlSelf->top__DOT__wb_type))
                                     ? vlSelf->top__DOT__mem_rdata
                                     : vlSelf->top__DOT__alu_out)
                                 : ((1U & (IData)(vlSelf->top__DOT__wb_type))
                                     ? ((IData)(4U) 
                                        + vlSelf->top__DOT__pc)
                                     : vlSelf->top__DOT__imm))),32);
        bufp->chgCData(oldp+6,((0x1fU & (vlSelf->top__DOT__instruction 
                                         >> 0xfU))),5);
        bufp->chgIData(oldp+7,(((0U == (0x1fU & (vlSelf->top__DOT__instruction 
                                                 >> 0xfU)))
                                 ? 0U : vlSelf->top__DOT__regfile__DOT__storage
                                [(0x1fU & (vlSelf->top__DOT__instruction 
                                           >> 0xfU))])),32);
        bufp->chgCData(oldp+8,((0x1fU & (vlSelf->top__DOT__instruction 
                                         >> 0x14U))),5);
        bufp->chgIData(oldp+9,(((0U == (0x1fU & (vlSelf->top__DOT__instruction 
                                                 >> 0x14U)))
                                 ? 0U : vlSelf->top__DOT__regfile__DOT__storage
                                [(0x1fU & (vlSelf->top__DOT__instruction 
                                           >> 0x14U))])),32);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__imm_ext_type),3);
        bufp->chgBit(oldp+11,(((1U & (~ (vlSelf->top__DOT__instruction 
                                         >> 6U))) && 
                               ((1U & (vlSelf->top__DOT__instruction 
                                       >> 5U)) && (
                                                   (1U 
                                                    & (vlSelf->top__DOT__instruction 
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
                                                                   & vlSelf->top__DOT__instruction)))))))));
        bufp->chgBit(oldp+12,(((1U & (vlSelf->top__DOT__instruction 
                                      >> 6U)) && ((1U 
                                                   & (vlSelf->top__DOT__instruction 
                                                      >> 5U)) 
                                                  && ((1U 
                                                       & (~ 
                                                          (vlSelf->top__DOT__instruction 
                                                           >> 4U))) 
                                                      && ((1U 
                                                           & (~ 
                                                              (vlSelf->top__DOT__instruction 
                                                               >> 3U))) 
                                                          && ((1U 
                                                               & (vlSelf->top__DOT__instruction 
                                                                  >> 2U)) 
                                                              && ((1U 
                                                                   & (vlSelf->top__DOT__instruction 
                                                                      >> 1U)) 
                                                                  && (1U 
                                                                      & vlSelf->top__DOT__instruction)))))))));
        bufp->chgBit(oldp+13,(((1U & (~ (vlSelf->top__DOT__instruction 
                                         >> 6U))) && 
                               ((1U & (vlSelf->top__DOT__instruction 
                                       >> 5U)) && (
                                                   (1U 
                                                    & (~ 
                                                       (vlSelf->top__DOT__instruction 
                                                        >> 4U))) 
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
                                                                   & vlSelf->top__DOT__instruction)))))))));
        bufp->chgCData(oldp+14,(((0x40U & vlSelf->top__DOT__instruction)
                                  ? 0U : ((0x20U & vlSelf->top__DOT__instruction)
                                           ? ((0x10U 
                                               & vlSelf->top__DOT__instruction)
                                               ? 0U
                                               : ((8U 
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
                                           : 0U))),4);
        bufp->chgBit(oldp+15,(((1U & (~ (vlSelf->top__DOT__instruction 
                                         >> 6U))) && 
                               ((1U & (~ (vlSelf->top__DOT__instruction 
                                          >> 5U))) 
                                && ((1U & (~ (vlSelf->top__DOT__instruction 
                                              >> 4U))) 
                                    && ((1U & (~ (vlSelf->top__DOT__instruction 
                                                  >> 3U))) 
                                        && ((1U & (~ 
                                                   (vlSelf->top__DOT__instruction 
                                                    >> 2U))) 
                                            && ((1U 
                                                 & (vlSelf->top__DOT__instruction 
                                                    >> 1U)) 
                                                && (1U 
                                                    & vlSelf->top__DOT__instruction)))))))));
        bufp->chgCData(oldp+16,(vlSelf->top__DOT__memr_mask),3);
        bufp->chgCData(oldp+17,(vlSelf->top__DOT__wb_type),2);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__imm),32);
        bufp->chgIData(oldp+19,((((1U & (~ (vlSelf->top__DOT__instruction 
                                            >> 6U))) 
                                  && ((1U & (vlSelf->top__DOT__instruction 
                                             >> 5U)) 
                                      && ((1U & (vlSelf->top__DOT__instruction 
                                                 >> 4U)) 
                                          && ((1U & 
                                               (~ (vlSelf->top__DOT__instruction 
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
                                  : vlSelf->top__DOT__imm)),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__alu_out),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__mem_rdata),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__tmp),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__regfile__DOT__storage[0]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__regfile__DOT__storage[1]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__regfile__DOT__storage[2]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__regfile__DOT__storage[3]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__regfile__DOT__storage[4]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__regfile__DOT__storage[5]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__regfile__DOT__storage[6]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__regfile__DOT__storage[7]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__regfile__DOT__storage[8]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__regfile__DOT__storage[9]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__regfile__DOT__storage[10]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__regfile__DOT__storage[11]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__regfile__DOT__storage[12]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__regfile__DOT__storage[13]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__regfile__DOT__storage[14]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__regfile__DOT__storage[15]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__regfile__DOT__storage[16]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__regfile__DOT__storage[17]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__regfile__DOT__storage[18]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__regfile__DOT__storage[19]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__regfile__DOT__storage[20]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__regfile__DOT__storage[21]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__regfile__DOT__storage[22]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__regfile__DOT__storage[23]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__regfile__DOT__storage[24]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__regfile__DOT__storage[25]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__regfile__DOT__storage[26]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__regfile__DOT__storage[27]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__regfile__DOT__storage[28]),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__regfile__DOT__storage[29]),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__regfile__DOT__storage[30]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__regfile__DOT__storage[31]),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__regfile__DOT__i),32);
    }
    bufp->chgBit(oldp+56,(vlSelf->clk));
    bufp->chgBit(oldp+57,(vlSelf->rst));
    bufp->chgBit(oldp+58,(vlSelf->meet_ebreak));
    bufp->chgBit(oldp+59,(((~ (IData)(vlSelf->meet_ebreak)) 
                           & (IData)(vlSelf->top__DOT__reg_wen))));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
