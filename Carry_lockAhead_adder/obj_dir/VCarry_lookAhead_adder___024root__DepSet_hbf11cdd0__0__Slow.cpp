// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCarry_lookAhead_adder.h for the primary calling header

#include "VCarry_lookAhead_adder__pch.h"
#include "VCarry_lookAhead_adder___024root.h"

VL_ATTR_COLD void VCarry_lookAhead_adder___024root___eval_static(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VCarry_lookAhead_adder___024root___eval_initial(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VCarry_lookAhead_adder___024root___eval_final(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCarry_lookAhead_adder___024root___dump_triggers__stl(VCarry_lookAhead_adder___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VCarry_lookAhead_adder___024root___eval_phase__stl(VCarry_lookAhead_adder___024root* vlSelf);

VL_ATTR_COLD void VCarry_lookAhead_adder___024root___eval_settle(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VCarry_lookAhead_adder___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("Carry_lookAhead_adder.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VCarry_lookAhead_adder___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCarry_lookAhead_adder___024root___dump_triggers__stl(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VCarry_lookAhead_adder___024root___ico_sequent__TOP__0(VCarry_lookAhead_adder___024root* vlSelf);

VL_ATTR_COLD void VCarry_lookAhead_adder___024root___eval_stl(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCarry_lookAhead_adder___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VCarry_lookAhead_adder___024root___eval_triggers__stl(VCarry_lookAhead_adder___024root* vlSelf);

VL_ATTR_COLD bool VCarry_lookAhead_adder___024root___eval_phase__stl(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VCarry_lookAhead_adder___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VCarry_lookAhead_adder___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCarry_lookAhead_adder___024root___dump_triggers__ico(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___dump_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCarry_lookAhead_adder___024root___dump_triggers__act(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCarry_lookAhead_adder___024root___dump_triggers__nba(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCarry_lookAhead_adder___024root___ctor_var_reset(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->A = VL_RAND_RESET_I(4);
    vlSelf->B = VL_RAND_RESET_I(4);
    vlSelf->Cin = VL_RAND_RESET_I(1);
    vlSelf->S = VL_RAND_RESET_I(4);
    vlSelf->Cout = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__A = VL_RAND_RESET_I(4);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__B = VL_RAND_RESET_I(4);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__Cin = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__S = VL_RAND_RESET_I(4);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__Cout = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__G = VL_RAND_RESET_I(4);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__P = VL_RAND_RESET_I(4);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__c1 = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__c2 = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__c3 = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p0c = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p1g0 = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p1p0c = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p2g1 = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p2p1g0 = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p2p1p0c = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p3g2 = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p3p2g1 = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p3p2p1g0 = VL_RAND_RESET_I(1);
    vlSelf->Carry_lookAhead_adder__DOT____Vtogcov__p3p2p1p0c = VL_RAND_RESET_I(1);
}
