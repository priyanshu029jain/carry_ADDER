// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCarry_lookAhead_adder.h for the primary calling header

#include "VCarry_lookAhead_adder__pch.h"
#include "VCarry_lookAhead_adder__Syms.h"
#include "VCarry_lookAhead_adder___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VCarry_lookAhead_adder___024root___dump_triggers__stl(VCarry_lookAhead_adder___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VCarry_lookAhead_adder___024root___eval_triggers__stl(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCarry_lookAhead_adder___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void VCarry_lookAhead_adder___024root___configure_coverage(VCarry_lookAhead_adder___024root* vlSelf, bool first) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___configure_coverage\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "Carry_lookAhead_adder.v", 2, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "A[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "Carry_lookAhead_adder.v", 2, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "A[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "Carry_lookAhead_adder.v", 2, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "A[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "Carry_lookAhead_adder.v", 2, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "A[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "Carry_lookAhead_adder.v", 3, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "B[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "Carry_lookAhead_adder.v", 3, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "B[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "Carry_lookAhead_adder.v", 3, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "B[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "Carry_lookAhead_adder.v", 3, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "B[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "Carry_lookAhead_adder.v", 4, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "Cin", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "Carry_lookAhead_adder.v", 5, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "S[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "Carry_lookAhead_adder.v", 5, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "S[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "Carry_lookAhead_adder.v", 5, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "S[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "Carry_lookAhead_adder.v", 5, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "S[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "Carry_lookAhead_adder.v", 6, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "Cout", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "Carry_lookAhead_adder.v", 10, 16, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "G[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "Carry_lookAhead_adder.v", 10, 16, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "G[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "Carry_lookAhead_adder.v", 10, 16, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "G[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "Carry_lookAhead_adder.v", 10, 16, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "G[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "Carry_lookAhead_adder.v", 10, 19, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "P[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "Carry_lookAhead_adder.v", 10, 19, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "P[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "Carry_lookAhead_adder.v", 10, 19, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "P[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "Carry_lookAhead_adder.v", 10, 19, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "P[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "Carry_lookAhead_adder.v", 22, 10, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "c1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "Carry_lookAhead_adder.v", 22, 14, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "c2", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "Carry_lookAhead_adder.v", 22, 18, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "c3", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "Carry_lookAhead_adder.v", 25, 10, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p0c", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "Carry_lookAhead_adder.v", 30, 10, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p1g0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "Carry_lookAhead_adder.v", 30, 16, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p1p0c", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "Carry_lookAhead_adder.v", 36, 10, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p2g1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "Carry_lookAhead_adder.v", 36, 16, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p2p1g0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "Carry_lookAhead_adder.v", 36, 24, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p2p1p0c", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "Carry_lookAhead_adder.v", 43, 10, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p3g2", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "Carry_lookAhead_adder.v", 43, 16, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p3p2g1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "Carry_lookAhead_adder.v", 43, 24, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p3p2p1g0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "Carry_lookAhead_adder.v", 43, 34, ".Carry_lookAhead_adder", "v_toggle/Carry_lookAhead_adder", "p3p2p1p0c", "");
}
