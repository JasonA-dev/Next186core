// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

VerilatedContext* Vtop::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 6000)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 3, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 6000)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__clk_28_636 = vlTOPp->clk_28_636;
    vlTOPp->top__DOT__clk_25 = vlTOPp->clk_25;
    vlTOPp->top__DOT__clk_14_318 = vlTOPp->clk_14_318;
    vlTOPp->top__DOT__reset = vlTOPp->reset;
    vlTOPp->top__DOT__inputs = vlTOPp->inputs;
    vlTOPp->top__DOT__clk_48 = vlTOPp->clk_48;
    vlTOPp->top__DOT__clk_12 = vlTOPp->clk_12;
    vlTOPp->top__DOT__P_A = vlTOPp->P_A;
    vlTOPp->top__DOT__P_U = vlTOPp->P_U;
    vlTOPp->top__DOT__P_D = vlTOPp->P_D;
    vlTOPp->top__DOT__P_L = vlTOPp->P_L;
    vlTOPp->top__DOT__P_R = vlTOPp->P_R;
    vlTOPp->top__DOT__P_tr = vlTOPp->P_tr;
    vlTOPp->top__DOT__ioctl_download = vlTOPp->ioctl_download;
    vlTOPp->top__DOT__ioctl_upload = vlTOPp->ioctl_upload;
    vlTOPp->top__DOT__ioctl_wr = vlTOPp->ioctl_wr;
    vlTOPp->top__DOT__ioctl_addr = vlTOPp->ioctl_addr;
    vlTOPp->top__DOT__ioctl_dout = vlTOPp->ioctl_dout;
    vlTOPp->top__DOT__ioctl_index = vlTOPp->ioctl_index;
    vlTOPp->top__DOT__SRAM_D = vlTOPp->SRAM_D;
    vlTOPp->top__DOT__PS2CLKA = vlTOPp->PS2CLKA;
    vlTOPp->top__DOT__PS2CLKB = vlTOPp->PS2CLKB;
    vlTOPp->top__DOT__PS2DATA = vlTOPp->PS2DATA;
    vlTOPp->top__DOT__PS2DATB = vlTOPp->PS2DATB;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_28_636 & 0xfeU))) {
        Verilated::overWidthError("clk_28_636");}
    if (VL_UNLIKELY((clk_25 & 0xfeU))) {
        Verilated::overWidthError("clk_25");}
    if (VL_UNLIKELY((clk_14_318 & 0xfeU))) {
        Verilated::overWidthError("clk_14_318");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((inputs & 0xf000U))) {
        Verilated::overWidthError("inputs");}
    if (VL_UNLIKELY((clk_48 & 0xfeU))) {
        Verilated::overWidthError("clk_48");}
    if (VL_UNLIKELY((clk_12 & 0xfeU))) {
        Verilated::overWidthError("clk_12");}
    if (VL_UNLIKELY((PS2CLKA & 0xfeU))) {
        Verilated::overWidthError("PS2CLKA");}
    if (VL_UNLIKELY((PS2CLKB & 0xfeU))) {
        Verilated::overWidthError("PS2CLKB");}
    if (VL_UNLIKELY((PS2DATA & 0xfeU))) {
        Verilated::overWidthError("PS2DATA");}
    if (VL_UNLIKELY((PS2DATB & 0xfeU))) {
        Verilated::overWidthError("PS2DATB");}
    if (VL_UNLIKELY((P_A & 0xfeU))) {
        Verilated::overWidthError("P_A");}
    if (VL_UNLIKELY((P_U & 0xfeU))) {
        Verilated::overWidthError("P_U");}
    if (VL_UNLIKELY((P_D & 0xfeU))) {
        Verilated::overWidthError("P_D");}
    if (VL_UNLIKELY((P_L & 0xfeU))) {
        Verilated::overWidthError("P_L");}
    if (VL_UNLIKELY((P_R & 0xfeU))) {
        Verilated::overWidthError("P_R");}
    if (VL_UNLIKELY((P_tr & 0xfeU))) {
        Verilated::overWidthError("P_tr");}
    if (VL_UNLIKELY((ioctl_download & 0xfeU))) {
        Verilated::overWidthError("ioctl_download");}
    if (VL_UNLIKELY((ioctl_upload & 0xfeU))) {
        Verilated::overWidthError("ioctl_upload");}
    if (VL_UNLIKELY((ioctl_wr & 0xfeU))) {
        Verilated::overWidthError("ioctl_wr");}
    if (VL_UNLIKELY((ioctl_addr & 0xfe000000U))) {
        Verilated::overWidthError("ioctl_addr");}
}
#endif  // VL_DEBUG
