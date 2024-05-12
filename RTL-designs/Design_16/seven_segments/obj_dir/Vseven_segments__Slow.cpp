// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vseven_segments.h for the primary calling header

#include "Vseven_segments.h"
#include "Vseven_segments__Syms.h"

//==========
CData/*6:0*/ Vseven_segments::__Vtable1_segments[16];

VL_CTOR_IMP(Vseven_segments) {
    Vseven_segments__Syms* __restrict vlSymsp = __VlSymsp = new Vseven_segments__Syms(this, name());
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vseven_segments::__Vconfigure(Vseven_segments__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vseven_segments::~Vseven_segments() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vseven_segments::_eval_initial(Vseven_segments__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseven_segments::_eval_initial\n"); );
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vseven_segments::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseven_segments::final\n"); );
    // Variables
    Vseven_segments__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vseven_segments::_eval_settle(Vseven_segments__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseven_segments::_eval_settle\n"); );
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vseven_segments::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseven_segments::_ctor_var_reset\n"); );
    // Body
    data = VL_RAND_RESET_I(4);
    segments = VL_RAND_RESET_I(7);
    __Vtableidx1 = 0;
    __Vtable1_segments[0] = 0x7eU;
    __Vtable1_segments[1] = 0x30U;
    __Vtable1_segments[2] = 0x6dU;
    __Vtable1_segments[3] = 0x79U;
    __Vtable1_segments[4] = 0x33U;
    __Vtable1_segments[5] = 0x5bU;
    __Vtable1_segments[6] = 0x5fU;
    __Vtable1_segments[7] = 0x70U;
    __Vtable1_segments[8] = 0x7fU;
    __Vtable1_segments[9] = 0x73U;
    __Vtable1_segments[10] = 0U;
    __Vtable1_segments[11] = 0U;
    __Vtable1_segments[12] = 0U;
    __Vtable1_segments[13] = 0U;
    __Vtable1_segments[14] = 0U;
    __Vtable1_segments[15] = 0U;
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
