// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+60,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"meet_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+60,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"meet_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"next_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+3,0,"inner_meet_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+5,0,"meet_ebreak_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"reg_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"reg_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+8,0,"reg_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+10,0,"rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"imm_ext_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+63,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+64,0,"alu_l_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"alu_r_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"mem_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"memw_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+18,0,"mem_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"memr_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+20,0,"wb_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+21,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"alu_l",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"alu_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"alu_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"mem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+10,0,"alu_l",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"alu_r",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+23,0,"alu_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("control", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+4,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"imm_ext_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+63,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+64,0,"alu_l_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"alu_r_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"jalr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"mem_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"memw_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+18,0,"mem_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"memr_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+6,0,"reg_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"wb_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("immgen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+4,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"imm_ext_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+21,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("regfile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+60,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+8,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"raddr_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+10,0,"rdata_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"raddr_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"rdata_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("storage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+27+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+59,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+63,(0U),4);
    bufp->fullBit(oldp+64,(0U));
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__pc),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__next_pc),32);
    bufp->fullBit(oldp+3,((0x100073U == vlSelf->top__DOT__instruction)));
    bufp->fullIData(oldp+4,(vlSelf->top__DOT__instruction),32);
    bufp->fullBit(oldp+5,(vlSelf->top__DOT__meet_ebreak_r));
    bufp->fullBit(oldp+6,(vlSelf->top__DOT__reg_wen));
    bufp->fullCData(oldp+7,((0x1fU & (vlSelf->top__DOT__instruction 
                                      >> 7U))),5);
    bufp->fullIData(oldp+8,(((2U & (IData)(vlSelf->top__DOT__wb_type))
                              ? ((1U & (IData)(vlSelf->top__DOT__wb_type))
                                  ? vlSelf->top__DOT__mem_rdata
                                  : vlSelf->top__DOT__alu_out)
                              : ((1U & (IData)(vlSelf->top__DOT__wb_type))
                                  ? ((IData)(4U) + vlSelf->top__DOT__pc)
                                  : vlSelf->top__DOT__imm))),32);
    bufp->fullCData(oldp+9,((0x1fU & (vlSelf->top__DOT__instruction 
                                      >> 0xfU))),5);
    bufp->fullIData(oldp+10,(((0U == (0x1fU & (vlSelf->top__DOT__instruction 
                                               >> 0xfU)))
                               ? 0U : vlSelf->top__DOT__regfile__DOT__storage
                              [(0x1fU & (vlSelf->top__DOT__instruction 
                                         >> 0xfU))])),32);
    bufp->fullCData(oldp+11,((0x1fU & (vlSelf->top__DOT__instruction 
                                       >> 0x14U))),5);
    bufp->fullIData(oldp+12,(((0U == (0x1fU & (vlSelf->top__DOT__instruction 
                                               >> 0x14U)))
                               ? 0U : vlSelf->top__DOT__regfile__DOT__storage
                              [(0x1fU & (vlSelf->top__DOT__instruction 
                                         >> 0x14U))])),32);
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__imm_ext_type),3);
    bufp->fullBit(oldp+14,(((1U & (~ (vlSelf->top__DOT__instruction 
                                      >> 6U))) && (
                                                   (1U 
                                                    & (vlSelf->top__DOT__instruction 
                                                       >> 5U)) 
                                                   && ((1U 
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
    bufp->fullBit(oldp+15,(((1U & (vlSelf->top__DOT__instruction 
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
    bufp->fullBit(oldp+16,(((1U & (~ (vlSelf->top__DOT__instruction 
                                      >> 6U))) && (
                                                   (1U 
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
                                                                & (~ 
                                                                   (vlSelf->top__DOT__instruction 
                                                                    >> 2U))) 
                                                               && ((1U 
                                                                    & (vlSelf->top__DOT__instruction 
                                                                       >> 1U)) 
                                                                   && (1U 
                                                                       & vlSelf->top__DOT__instruction)))))))));
    bufp->fullCData(oldp+17,(((0x40U & vlSelf->top__DOT__instruction)
                               ? 0U : ((0x20U & vlSelf->top__DOT__instruction)
                                        ? ((0x10U & vlSelf->top__DOT__instruction)
                                            ? 0U : 
                                           ((8U & vlSelf->top__DOT__instruction)
                                             ? 0U : 
                                            ((4U & vlSelf->top__DOT__instruction)
                                              ? 0U : 
                                             ((2U & vlSelf->top__DOT__instruction)
                                               ? ((1U 
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
    bufp->fullBit(oldp+18,(((1U & (~ (vlSelf->top__DOT__instruction 
                                      >> 6U))) && (
                                                   (1U 
                                                    & (~ 
                                                       (vlSelf->top__DOT__instruction 
                                                        >> 5U))) 
                                                   && ((1U 
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
    bufp->fullCData(oldp+19,(vlSelf->top__DOT__memr_mask),3);
    bufp->fullCData(oldp+20,(vlSelf->top__DOT__wb_type),2);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__imm),32);
    bufp->fullIData(oldp+22,((((1U & (~ (vlSelf->top__DOT__instruction 
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
                                                                   & vlSelf->top__DOT__instruction)))))))
                               ? ((0U == (0x1fU & (vlSelf->top__DOT__instruction 
                                                   >> 0x14U)))
                                   ? 0U : vlSelf->top__DOT__regfile__DOT__storage
                                  [(0x1fU & (vlSelf->top__DOT__instruction 
                                             >> 0x14U))])
                               : vlSelf->top__DOT__imm)),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__alu_out),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__mem_rdata),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__tmp),32);
    bufp->fullBit(oldp+26,(((~ (IData)(vlSelf->top__DOT__meet_ebreak_r)) 
                            & (IData)(vlSelf->top__DOT__reg_wen))));
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__regfile__DOT__storage[0]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__regfile__DOT__storage[1]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__regfile__DOT__storage[2]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__regfile__DOT__storage[3]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__regfile__DOT__storage[4]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__regfile__DOT__storage[5]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__regfile__DOT__storage[6]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__regfile__DOT__storage[7]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__regfile__DOT__storage[8]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__regfile__DOT__storage[9]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__regfile__DOT__storage[10]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__regfile__DOT__storage[11]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__regfile__DOT__storage[12]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__regfile__DOT__storage[13]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__regfile__DOT__storage[14]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__regfile__DOT__storage[15]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__regfile__DOT__storage[16]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__regfile__DOT__storage[17]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__regfile__DOT__storage[18]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__regfile__DOT__storage[19]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__regfile__DOT__storage[20]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__regfile__DOT__storage[21]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regfile__DOT__storage[22]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regfile__DOT__storage[23]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regfile__DOT__storage[24]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__regfile__DOT__storage[25]),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__regfile__DOT__storage[26]),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__regfile__DOT__storage[27]),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__regfile__DOT__storage[28]),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__regfile__DOT__storage[29]),32);
    bufp->fullIData(oldp+57,(vlSelf->top__DOT__regfile__DOT__storage[30]),32);
    bufp->fullIData(oldp+58,(vlSelf->top__DOT__regfile__DOT__storage[31]),32);
    bufp->fullIData(oldp+59,(vlSelf->top__DOT__regfile__DOT__i),32);
    bufp->fullBit(oldp+60,(vlSelf->clk));
    bufp->fullBit(oldp+61,(vlSelf->rst));
    bufp->fullBit(oldp+62,(vlSelf->meet_ebreak));
}
