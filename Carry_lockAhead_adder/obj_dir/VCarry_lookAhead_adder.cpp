// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VCarry_lookAhead_adder__pch.h"

//============================================================
// Constructors

VCarry_lookAhead_adder::VCarry_lookAhead_adder(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VCarry_lookAhead_adder__Syms(contextp(), _vcname__, this)}
    , A{vlSymsp->TOP.A}
    , B{vlSymsp->TOP.B}
    , Cin{vlSymsp->TOP.Cin}
    , S{vlSymsp->TOP.S}
    , Cout{vlSymsp->TOP.Cout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VCarry_lookAhead_adder::VCarry_lookAhead_adder(const char* _vcname__)
    : VCarry_lookAhead_adder(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VCarry_lookAhead_adder::~VCarry_lookAhead_adder() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VCarry_lookAhead_adder___024root___eval_debug_assertions(VCarry_lookAhead_adder___024root* vlSelf);
#endif  // VL_DEBUG
void VCarry_lookAhead_adder___024root___eval_static(VCarry_lookAhead_adder___024root* vlSelf);
void VCarry_lookAhead_adder___024root___eval_initial(VCarry_lookAhead_adder___024root* vlSelf);
void VCarry_lookAhead_adder___024root___eval_settle(VCarry_lookAhead_adder___024root* vlSelf);
void VCarry_lookAhead_adder___024root___eval(VCarry_lookAhead_adder___024root* vlSelf);

void VCarry_lookAhead_adder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCarry_lookAhead_adder::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VCarry_lookAhead_adder___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VCarry_lookAhead_adder___024root___eval_static(&(vlSymsp->TOP));
        VCarry_lookAhead_adder___024root___eval_initial(&(vlSymsp->TOP));
        VCarry_lookAhead_adder___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VCarry_lookAhead_adder___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VCarry_lookAhead_adder::eventsPending() { return false; }

uint64_t VCarry_lookAhead_adder::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VCarry_lookAhead_adder::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VCarry_lookAhead_adder___024root___eval_final(VCarry_lookAhead_adder___024root* vlSelf);

VL_ATTR_COLD void VCarry_lookAhead_adder::final() {
    VCarry_lookAhead_adder___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VCarry_lookAhead_adder::hierName() const { return vlSymsp->name(); }
const char* VCarry_lookAhead_adder::modelName() const { return "VCarry_lookAhead_adder"; }
unsigned VCarry_lookAhead_adder::threads() const { return 1; }
void VCarry_lookAhead_adder::prepareClone() const { contextp()->prepareClone(); }
void VCarry_lookAhead_adder::atClone() const {
    contextp()->threadPoolpOnClone();
}
