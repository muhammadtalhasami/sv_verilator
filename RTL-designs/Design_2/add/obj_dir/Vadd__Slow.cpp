// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd.h for the primary calling header

#include "Vadd.h"
#include "Vadd__Syms.h"

//==========

VL_CTOR_IMP(Vadd) {
    Vadd__Syms* __restrict vlSymsp = __VlSymsp = new Vadd__Syms(this, name());
    Vadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vadd::__Vconfigure(Vadd__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vadd::~Vadd() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vadd::_eval_initial(Vadd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd::_eval_initial\n"); );
    Vadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vadd::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd::final\n"); );
    // Variables
    Vadd__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vadd::_eval_settle(Vadd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd::_eval_settle\n"); );
    Vadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vadd::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd::_ctor_var_reset\n"); );
    // Body
    a_i = VL_RAND_RESET_I(1);
    b_i = VL_RAND_RESET_I(1);
    c_o = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
