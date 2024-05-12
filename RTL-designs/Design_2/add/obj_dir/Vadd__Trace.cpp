// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd__Syms.h"


void Vadd::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vadd__Syms* __restrict vlSymsp = static_cast<Vadd__Syms*>(userp);
    Vadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vadd::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vadd__Syms* __restrict vlSymsp = static_cast<Vadd__Syms*>(userp);
    Vadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->a_i));
        tracep->chgBit(oldp+1,(vlTOPp->b_i));
        tracep->chgBit(oldp+2,(vlTOPp->c_o));
    }
}

void Vadd::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vadd__Syms* __restrict vlSymsp = static_cast<Vadd__Syms*>(userp);
    Vadd* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
