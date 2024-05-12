// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vseven_segments__Syms.h"


void Vseven_segments::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vseven_segments__Syms* __restrict vlSymsp = static_cast<Vseven_segments__Syms*>(userp);
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vseven_segments::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vseven_segments__Syms* __restrict vlSymsp = static_cast<Vseven_segments__Syms*>(userp);
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlTOPp->data),4);
        tracep->chgCData(oldp+1,(vlTOPp->segments),7);
    }
}

void Vseven_segments::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vseven_segments__Syms* __restrict vlSymsp = static_cast<Vseven_segments__Syms*>(userp);
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
