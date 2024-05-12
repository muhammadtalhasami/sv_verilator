// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vseven_segments__Syms.h"


//======================

void Vseven_segments::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vseven_segments::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vseven_segments__Syms* __restrict vlSymsp = static_cast<Vseven_segments__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vseven_segments::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vseven_segments::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vseven_segments__Syms* __restrict vlSymsp = static_cast<Vseven_segments__Syms*>(userp);
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vseven_segments::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vseven_segments__Syms* __restrict vlSymsp = static_cast<Vseven_segments__Syms*>(userp);
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"data", false,-1, 3,0);
        tracep->declBus(c+2,"segments", false,-1, 6,0);
        tracep->declBus(c+1,"seven_segments data", false,-1, 3,0);
        tracep->declBus(c+2,"seven_segments segments", false,-1, 6,0);
    }
}

void Vseven_segments::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vseven_segments::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vseven_segments__Syms* __restrict vlSymsp = static_cast<Vseven_segments__Syms*>(userp);
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vseven_segments::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vseven_segments__Syms* __restrict vlSymsp = static_cast<Vseven_segments__Syms*>(userp);
    Vseven_segments* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->data),4);
        tracep->fullCData(oldp+2,(vlTOPp->segments),7);
    }
}
