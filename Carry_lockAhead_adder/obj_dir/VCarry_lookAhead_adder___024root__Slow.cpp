// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCarry_lookAhead_adder.h for the primary calling header

#include "VCarry_lookAhead_adder__pch.h"
#include "VCarry_lookAhead_adder__Syms.h"
#include "VCarry_lookAhead_adder___024root.h"

void VCarry_lookAhead_adder___024root___ctor_var_reset(VCarry_lookAhead_adder___024root* vlSelf);

VCarry_lookAhead_adder___024root::VCarry_lookAhead_adder___024root(VCarry_lookAhead_adder__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCarry_lookAhead_adder___024root___ctor_var_reset(this);
}

void VCarry_lookAhead_adder___024root___configure_coverage(VCarry_lookAhead_adder___024root* vlSelf, bool first);

void VCarry_lookAhead_adder___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    VCarry_lookAhead_adder___024root___configure_coverage(this, first);
}

VCarry_lookAhead_adder___024root::~VCarry_lookAhead_adder___024root() {
}

// Coverage
void VCarry_lookAhead_adder___024root::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    std::string fullhier = std::string{VerilatedModule::name()} + hierp;
    if (!fullhier.empty() && fullhier[0] == '.') fullhier = fullhier.substr(1);
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(vlSymsp->_vm_contextp__->coveragep(), VerilatedModule::name(), count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",fullhier,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}
