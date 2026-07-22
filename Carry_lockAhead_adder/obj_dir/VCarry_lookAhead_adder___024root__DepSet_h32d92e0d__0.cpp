// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCarry_lookAhead_adder.h for the primary calling header

#include "VCarry_lookAhead_adder__pch.h"
#include "VCarry_lookAhead_adder__Syms.h"
#include "VCarry_lookAhead_adder___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VCarry_lookAhead_adder___024root___dump_triggers__ico(VCarry_lookAhead_adder___024root* vlSelf);
#endif  // VL_DEBUG

void VCarry_lookAhead_adder___024root___eval_triggers__ico(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___eval_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCarry_lookAhead_adder___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void VCarry_lookAhead_adder___024root___ico_sequent__TOP__0(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ Carry_lookAhead_adder__DOT__G;
    Carry_lookAhead_adder__DOT__G = 0;
    CData/*3:0*/ Carry_lookAhead_adder__DOT__P;
    Carry_lookAhead_adder__DOT__P = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__c1;
    Carry_lookAhead_adder__DOT__c1 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__c2;
    Carry_lookAhead_adder__DOT__c2 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__c3;
    Carry_lookAhead_adder__DOT__c3 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p0c;
    Carry_lookAhead_adder__DOT__p0c = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p1g0;
    Carry_lookAhead_adder__DOT__p1g0 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p1p0c;
    Carry_lookAhead_adder__DOT__p1p0c = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p2g1;
    Carry_lookAhead_adder__DOT__p2g1 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p2p1g0;
    Carry_lookAhead_adder__DOT__p2p1g0 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p2p1p0c;
    Carry_lookAhead_adder__DOT__p2p1p0c = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p3g2;
    Carry_lookAhead_adder__DOT__p3g2 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p3p2g1;
    Carry_lookAhead_adder__DOT__p3p2g1 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p3p2p1g0;
    Carry_lookAhead_adder__DOT__p3p2p1g0 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT__p3p2p1p0c;
    Carry_lookAhead_adder__DOT__p3p2p1p0c = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_5;
    Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_5 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_8;
    Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_8 = 0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_9;
    Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_9 = 0;
    // Body
    if (((IData)(vlSelfRef.Cin) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__Cin))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__Cin 
            = vlSelfRef.Cin;
    }
    if ((1U & ((IData)(vlSelfRef.A) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A)))) {
        ++(vlSymsp->__Vcoverage[0]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A 
            = ((0xeU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A)) 
               | (1U & (IData)(vlSelfRef.A)));
    }
    if ((2U & ((IData)(vlSelfRef.A) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A)))) {
        ++(vlSymsp->__Vcoverage[1]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A 
            = ((0xdU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A)) 
               | (2U & (IData)(vlSelfRef.A)));
    }
    if ((4U & ((IData)(vlSelfRef.A) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A)))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A 
            = ((0xbU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A)) 
               | (4U & (IData)(vlSelfRef.A)));
    }
    if ((8U & ((IData)(vlSelfRef.A) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A)))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A 
            = ((7U & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__A)) 
               | (8U & (IData)(vlSelfRef.A)));
    }
    if ((1U & ((IData)(vlSelfRef.B) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B)))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B 
            = ((0xeU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B)) 
               | (1U & (IData)(vlSelfRef.B)));
    }
    if ((2U & ((IData)(vlSelfRef.B) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B)))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B 
            = ((0xdU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B)) 
               | (2U & (IData)(vlSelfRef.B)));
    }
    if ((4U & ((IData)(vlSelfRef.B) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B)))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B 
            = ((0xbU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B)) 
               | (4U & (IData)(vlSelfRef.B)));
    }
    if ((8U & ((IData)(vlSelfRef.B) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B)))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B 
            = ((7U & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__B)) 
               | (8U & (IData)(vlSelfRef.B)));
    }
    Carry_lookAhead_adder__DOT__G = ((IData)(vlSelfRef.A) 
                                     & (IData)(vlSelfRef.B));
    Carry_lookAhead_adder__DOT__P = ((IData)(vlSelfRef.A) 
                                     ^ (IData)(vlSelfRef.B));
    if ((1U & ((IData)(Carry_lookAhead_adder__DOT__G) 
               ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G)))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G 
            = ((0xeU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G)) 
               | (1U & (IData)(Carry_lookAhead_adder__DOT__G)));
    }
    if ((2U & ((IData)(Carry_lookAhead_adder__DOT__G) 
               ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G)))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G 
            = ((0xdU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G)) 
               | (2U & (IData)(Carry_lookAhead_adder__DOT__G)));
    }
    if ((4U & ((IData)(Carry_lookAhead_adder__DOT__G) 
               ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G)))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G 
            = ((0xbU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G)) 
               | (4U & (IData)(Carry_lookAhead_adder__DOT__G)));
    }
    if ((8U & ((IData)(Carry_lookAhead_adder__DOT__G) 
               ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G)))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G 
            = ((7U & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__G)) 
               | (8U & (IData)(Carry_lookAhead_adder__DOT__G)));
    }
    if ((1U & ((IData)(Carry_lookAhead_adder__DOT__P) 
               ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P)))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P 
            = ((0xeU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P)) 
               | (1U & (IData)(Carry_lookAhead_adder__DOT__P)));
    }
    if ((2U & ((IData)(Carry_lookAhead_adder__DOT__P) 
               ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P)))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P 
            = ((0xdU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P)) 
               | (2U & (IData)(Carry_lookAhead_adder__DOT__P)));
    }
    if ((4U & ((IData)(Carry_lookAhead_adder__DOT__P) 
               ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P)))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P 
            = ((0xbU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P)) 
               | (4U & (IData)(Carry_lookAhead_adder__DOT__P)));
    }
    if ((8U & ((IData)(Carry_lookAhead_adder__DOT__P) 
               ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P)))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P 
            = ((7U & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__P)) 
               | (8U & (IData)(Carry_lookAhead_adder__DOT__P)));
    }
    Carry_lookAhead_adder__DOT__p3g2 = (IData)((((IData)(Carry_lookAhead_adder__DOT__P) 
                                                 >> 3U) 
                                                & ((IData)(Carry_lookAhead_adder__DOT__G) 
                                                   >> 2U)));
    Carry_lookAhead_adder__DOT__p1g0 = (1U & (((IData)(Carry_lookAhead_adder__DOT__P) 
                                               >> 1U) 
                                              & (IData)(Carry_lookAhead_adder__DOT__G)));
    Carry_lookAhead_adder__DOT__p2g1 = (1U & (((IData)(Carry_lookAhead_adder__DOT__P) 
                                               >> 2U) 
                                              & ((IData)(Carry_lookAhead_adder__DOT__G) 
                                                 >> 1U)));
    Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_8 
        = (IData)((0xcU == (0xcU & (IData)(Carry_lookAhead_adder__DOT__P))));
    Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_5 
        = (IData)((6U == (6U & (IData)(Carry_lookAhead_adder__DOT__P))));
    Carry_lookAhead_adder__DOT__p0c = ((IData)(Carry_lookAhead_adder__DOT__P) 
                                       & (IData)(vlSelfRef.Cin));
    if (((IData)(Carry_lookAhead_adder__DOT__p3g2) 
         ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p3g2))) {
        ++(vlSymsp->__Vcoverage[31]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p3g2 
            = Carry_lookAhead_adder__DOT__p3g2;
    }
    if (((IData)(Carry_lookAhead_adder__DOT__p1g0) 
         ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p1g0))) {
        ++(vlSymsp->__Vcoverage[26]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p1g0 
            = Carry_lookAhead_adder__DOT__p1g0;
    }
    if (((IData)(Carry_lookAhead_adder__DOT__p2g1) 
         ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p2g1))) {
        ++(vlSymsp->__Vcoverage[28]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p2g1 
            = Carry_lookAhead_adder__DOT__p2g1;
    }
    Carry_lookAhead_adder__DOT__p3p2g1 = ((IData)(Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_8) 
                                          & ((IData)(Carry_lookAhead_adder__DOT__G) 
                                             >> 1U));
    Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_9 
        = ((IData)(Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_8) 
           & ((IData)(Carry_lookAhead_adder__DOT__P) 
              >> 1U));
    Carry_lookAhead_adder__DOT__p2p1g0 = ((IData)(Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_5) 
                                          & (IData)(Carry_lookAhead_adder__DOT__G));
    if (((IData)(Carry_lookAhead_adder__DOT__p0c) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p0c))) {
        ++(vlSymsp->__Vcoverage[25]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p0c 
            = Carry_lookAhead_adder__DOT__p0c;
    }
    Carry_lookAhead_adder__DOT__c1 = (1U & ((IData)(Carry_lookAhead_adder__DOT__G) 
                                            | (IData)(Carry_lookAhead_adder__DOT__p0c)));
    Carry_lookAhead_adder__DOT__p1p0c = (((IData)(Carry_lookAhead_adder__DOT__P) 
                                          >> 1U) & (IData)(Carry_lookAhead_adder__DOT__p0c));
    Carry_lookAhead_adder__DOT__p2p1p0c = ((IData)(Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_5) 
                                           & (IData)(Carry_lookAhead_adder__DOT__p0c));
    if (((IData)(Carry_lookAhead_adder__DOT__p3p2g1) 
         ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p3p2g1))) {
        ++(vlSymsp->__Vcoverage[32]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p3p2g1 
            = Carry_lookAhead_adder__DOT__p3p2g1;
    }
    Carry_lookAhead_adder__DOT__p3p2p1g0 = ((IData)(Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_9) 
                                            & (IData)(Carry_lookAhead_adder__DOT__G));
    Carry_lookAhead_adder__DOT__p3p2p1p0c = ((IData)(Carry_lookAhead_adder__DOT____VdfgRegularize_h1488fce1_0_9) 
                                             & (IData)(Carry_lookAhead_adder__DOT__p0c));
    if (((IData)(Carry_lookAhead_adder__DOT__p2p1g0) 
         ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p2p1g0))) {
        ++(vlSymsp->__Vcoverage[29]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p2p1g0 
            = Carry_lookAhead_adder__DOT__p2p1g0;
    }
    if (((IData)(Carry_lookAhead_adder__DOT__c1) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__c1))) {
        ++(vlSymsp->__Vcoverage[22]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__c1 
            = Carry_lookAhead_adder__DOT__c1;
    }
    if (((IData)(Carry_lookAhead_adder__DOT__p1p0c) 
         ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p1p0c))) {
        ++(vlSymsp->__Vcoverage[27]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p1p0c 
            = Carry_lookAhead_adder__DOT__p1p0c;
    }
    Carry_lookAhead_adder__DOT__c2 = (1U & (((IData)(Carry_lookAhead_adder__DOT__G) 
                                             >> 1U) 
                                            | ((IData)(Carry_lookAhead_adder__DOT__p1g0) 
                                               | (IData)(Carry_lookAhead_adder__DOT__p1p0c))));
    if (((IData)(Carry_lookAhead_adder__DOT__p2p1p0c) 
         ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p2p1p0c))) {
        ++(vlSymsp->__Vcoverage[30]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p2p1p0c 
            = Carry_lookAhead_adder__DOT__p2p1p0c;
    }
    Carry_lookAhead_adder__DOT__c3 = (1U & (((IData)(Carry_lookAhead_adder__DOT__G) 
                                             >> 2U) 
                                            | ((IData)(Carry_lookAhead_adder__DOT__p2g1) 
                                               | ((IData)(Carry_lookAhead_adder__DOT__p2p1g0) 
                                                  | (IData)(Carry_lookAhead_adder__DOT__p2p1p0c)))));
    if (((IData)(Carry_lookAhead_adder__DOT__p3p2p1g0) 
         ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p3p2p1g0))) {
        ++(vlSymsp->__Vcoverage[33]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p3p2p1g0 
            = Carry_lookAhead_adder__DOT__p3p2p1g0;
    }
    if (((IData)(Carry_lookAhead_adder__DOT__p3p2p1p0c) 
         ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p3p2p1p0c))) {
        ++(vlSymsp->__Vcoverage[34]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__p3p2p1p0c 
            = Carry_lookAhead_adder__DOT__p3p2p1p0c;
    }
    vlSelfRef.Cout = (IData)(((((((IData)(Carry_lookAhead_adder__DOT__G) 
                                  >> 3U) | (IData)(Carry_lookAhead_adder__DOT__p3g2)) 
                                | (IData)(Carry_lookAhead_adder__DOT__p3p2g1)) 
                               | (IData)(Carry_lookAhead_adder__DOT__p3p2p1g0)) 
                              | (IData)(Carry_lookAhead_adder__DOT__p3p2p1p0c)));
    if (((IData)(Carry_lookAhead_adder__DOT__c2) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__c2))) {
        ++(vlSymsp->__Vcoverage[23]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__c2 
            = Carry_lookAhead_adder__DOT__c2;
    }
    if (((IData)(Carry_lookAhead_adder__DOT__c3) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__c3))) {
        ++(vlSymsp->__Vcoverage[24]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__c3 
            = Carry_lookAhead_adder__DOT__c3;
    }
    vlSelfRef.S = ((((IData)((((IData)(Carry_lookAhead_adder__DOT__P) 
                               >> 3U) ^ (IData)(Carry_lookAhead_adder__DOT__c3))) 
                     << 3U) | (4U & ((0xfffffffcU & (IData)(Carry_lookAhead_adder__DOT__P)) 
                                     ^ ((IData)(Carry_lookAhead_adder__DOT__c2) 
                                        << 2U)))) | 
                   ((2U & ((0xfffffffeU & (IData)(Carry_lookAhead_adder__DOT__P)) 
                           ^ ((IData)(Carry_lookAhead_adder__DOT__c1) 
                              << 1U))) | (1U & ((IData)(Carry_lookAhead_adder__DOT__P) 
                                                ^ (IData)(vlSelfRef.Cin)))));
    if (((IData)(vlSelfRef.Cout) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__Cout))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__Cout 
            = vlSelfRef.Cout;
    }
    if ((1U & ((IData)(vlSelfRef.S) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S)))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S 
            = ((0xeU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S)) 
               | (1U & (IData)(vlSelfRef.S)));
    }
    if ((2U & ((IData)(vlSelfRef.S) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S)))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S 
            = ((0xdU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S)) 
               | (2U & (IData)(vlSelfRef.S)));
    }
    if ((4U & ((IData)(vlSelfRef.S) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S)))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S 
            = ((0xbU & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S)) 
               | (4U & (IData)(vlSelfRef.S)));
    }
    if ((8U & ((IData)(vlSelfRef.S) ^ (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S)))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S 
            = ((7U & (IData)(vlSelfRef.Carry_lookAhead_adder__DOT____Vtogcov__S)) 
               | (8U & (IData)(vlSelfRef.S)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCarry_lookAhead_adder___024root___dump_triggers__act(VCarry_lookAhead_adder___024root* vlSelf);
#endif  // VL_DEBUG

void VCarry_lookAhead_adder___024root___eval_triggers__act(VCarry_lookAhead_adder___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VCarry_lookAhead_adder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCarry_lookAhead_adder___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCarry_lookAhead_adder___024root___dump_triggers__act(vlSelf);
    }
#endif
}
