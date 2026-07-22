// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCarry_lookAhead_adder.h for the primary calling header

#ifndef VERILATED_VCARRY_LOOKAHEAD_ADDER___024ROOT_H_
#define VERILATED_VCARRY_LOOKAHEAD_ADDER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"


class VCarry_lookAhead_adder__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCarry_lookAhead_adder___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(A,3,0);
    VL_IN8(B,3,0);
    VL_IN8(Cin,0,0);
    VL_OUT8(S,3,0);
    VL_OUT8(Cout,0,0);
    CData/*3:0*/ Carry_lookAhead_adder__DOT____Vtogcov__A;
    CData/*3:0*/ Carry_lookAhead_adder__DOT____Vtogcov__B;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__Cin;
    CData/*3:0*/ Carry_lookAhead_adder__DOT____Vtogcov__S;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__Cout;
    CData/*3:0*/ Carry_lookAhead_adder__DOT____Vtogcov__G;
    CData/*3:0*/ Carry_lookAhead_adder__DOT____Vtogcov__P;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__c1;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__c2;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__c3;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p0c;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p1g0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p1p0c;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p2g1;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p2p1g0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p2p1p0c;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p3g2;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p3p2g1;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p3p2p1g0;
    CData/*0:0*/ Carry_lookAhead_adder__DOT____Vtogcov__p3p2p1p0c;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VCarry_lookAhead_adder__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCarry_lookAhead_adder___024root(VCarry_lookAhead_adder__Syms* symsp, const char* v__name);
    ~VCarry_lookAhead_adder___024root();
    VL_UNCOPYABLE(VCarry_lookAhead_adder___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
};


#endif  // guard
