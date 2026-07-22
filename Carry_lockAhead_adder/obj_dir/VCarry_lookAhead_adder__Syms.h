// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCARRY_LOOKAHEAD_ADDER__SYMS_H_
#define VERILATED_VCARRY_LOOKAHEAD_ADDER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VCarry_lookAhead_adder.h"

// INCLUDE MODULE CLASSES
#include "VCarry_lookAhead_adder___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VCarry_lookAhead_adder__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VCarry_lookAhead_adder* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VCarry_lookAhead_adder___024root TOP;

    // COVERAGE
    uint32_t __Vcoverage[35];

    // CONSTRUCTORS
    VCarry_lookAhead_adder__Syms(VerilatedContext* contextp, const char* namep, VCarry_lookAhead_adder* modelp);
    ~VCarry_lookAhead_adder__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
