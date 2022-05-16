// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk_28_636));
        tracep->chgBit(oldp+1,(vlTOPp->clk_25));
        tracep->chgBit(oldp+2,(vlTOPp->clk_14_318));
        tracep->chgBit(oldp+3,(vlTOPp->reset));
        tracep->chgSData(oldp+4,(vlTOPp->inputs),12);
        tracep->chgBit(oldp+5,(vlTOPp->clk_48));
        tracep->chgBit(oldp+6,(vlTOPp->clk_12));
        tracep->chgBit(oldp+7,(vlTOPp->ce_pix));
        tracep->chgBit(oldp+8,(vlTOPp->VGA_HB));
        tracep->chgBit(oldp+9,(vlTOPp->VGA_HS));
        tracep->chgBit(oldp+10,(vlTOPp->VGA_VB));
        tracep->chgBit(oldp+11,(vlTOPp->VGA_VS));
        tracep->chgCData(oldp+12,(vlTOPp->VGA_R),6);
        tracep->chgCData(oldp+13,(vlTOPp->VGA_G),6);
        tracep->chgCData(oldp+14,(vlTOPp->VGA_B),6);
        tracep->chgBit(oldp+15,(vlTOPp->SRAM_WE_n));
        tracep->chgIData(oldp+16,(vlTOPp->SRAM_A),21);
        tracep->chgCData(oldp+17,(vlTOPp->SRAM_D),8);
        tracep->chgBit(oldp+18,(vlTOPp->LED));
        tracep->chgBit(oldp+19,(vlTOPp->AUDIO_L));
        tracep->chgBit(oldp+20,(vlTOPp->AUDIO_R));
        tracep->chgBit(oldp+21,(vlTOPp->PS2CLKA));
        tracep->chgBit(oldp+22,(vlTOPp->PS2CLKB));
        tracep->chgBit(oldp+23,(vlTOPp->PS2DATA));
        tracep->chgBit(oldp+24,(vlTOPp->PS2DATB));
        tracep->chgBit(oldp+25,(vlTOPp->SD_nCS));
        tracep->chgBit(oldp+26,(vlTOPp->SD_DI));
        tracep->chgBit(oldp+27,(vlTOPp->SD_CK));
        tracep->chgBit(oldp+28,(vlTOPp->SD_DO));
        tracep->chgBit(oldp+29,(vlTOPp->P_A));
        tracep->chgBit(oldp+30,(vlTOPp->P_U));
        tracep->chgBit(oldp+31,(vlTOPp->P_D));
        tracep->chgBit(oldp+32,(vlTOPp->P_L));
        tracep->chgBit(oldp+33,(vlTOPp->P_R));
        tracep->chgBit(oldp+34,(vlTOPp->P_tr));
        tracep->chgBit(oldp+35,(vlTOPp->ioctl_download));
        tracep->chgBit(oldp+36,(vlTOPp->ioctl_upload));
        tracep->chgBit(oldp+37,(vlTOPp->ioctl_wr));
        tracep->chgIData(oldp+38,(vlTOPp->ioctl_addr),25);
        tracep->chgCData(oldp+39,(vlTOPp->ioctl_dout),8);
        tracep->chgCData(oldp+40,(vlTOPp->ioctl_din),8);
        tracep->chgCData(oldp+41,(vlTOPp->ioctl_index),8);
        tracep->chgBit(oldp+42,(vlTOPp->ioctl_wait));
        tracep->chgBit(oldp+43,(vlTOPp->top__DOT__clk_28_636));
        tracep->chgBit(oldp+44,(vlTOPp->top__DOT__clk_25));
        tracep->chgBit(oldp+45,(vlTOPp->top__DOT__clk_14_318));
        tracep->chgBit(oldp+46,(vlTOPp->top__DOT__reset));
        tracep->chgSData(oldp+47,(vlTOPp->top__DOT__inputs),12);
        tracep->chgBit(oldp+48,(vlTOPp->top__DOT__clk_48));
        tracep->chgBit(oldp+49,(vlTOPp->top__DOT__clk_12));
        tracep->chgBit(oldp+50,(vlTOPp->top__DOT__ce_pix));
        tracep->chgBit(oldp+51,(vlTOPp->top__DOT__VGA_HB));
        tracep->chgBit(oldp+52,(vlTOPp->top__DOT__VGA_HS));
        tracep->chgBit(oldp+53,(vlTOPp->top__DOT__VGA_VB));
        tracep->chgBit(oldp+54,(vlTOPp->top__DOT__VGA_VS));
        tracep->chgCData(oldp+55,(vlTOPp->top__DOT__VGA_R),6);
        tracep->chgCData(oldp+56,(vlTOPp->top__DOT__VGA_G),6);
        tracep->chgCData(oldp+57,(vlTOPp->top__DOT__VGA_B),6);
        tracep->chgBit(oldp+58,(vlTOPp->top__DOT__SRAM_WE_n));
        tracep->chgIData(oldp+59,(vlTOPp->top__DOT__SRAM_A),21);
        tracep->chgCData(oldp+60,(vlTOPp->top__DOT__SRAM_D),8);
        tracep->chgBit(oldp+61,(vlTOPp->top__DOT__LED));
        tracep->chgBit(oldp+62,(vlTOPp->top__DOT__AUDIO_L));
        tracep->chgBit(oldp+63,(vlTOPp->top__DOT__AUDIO_R));
        tracep->chgBit(oldp+64,(vlTOPp->top__DOT__PS2CLKA));
        tracep->chgBit(oldp+65,(vlTOPp->top__DOT__PS2CLKB));
        tracep->chgBit(oldp+66,(vlTOPp->top__DOT__PS2DATA));
        tracep->chgBit(oldp+67,(vlTOPp->top__DOT__PS2DATB));
        tracep->chgBit(oldp+68,(vlTOPp->top__DOT__SD_nCS));
        tracep->chgBit(oldp+69,(vlTOPp->top__DOT__SD_DI));
        tracep->chgBit(oldp+70,(vlTOPp->top__DOT__SD_CK));
        tracep->chgBit(oldp+71,(vlTOPp->top__DOT__SD_DO));
        tracep->chgBit(oldp+72,(vlTOPp->top__DOT__P_A));
        tracep->chgBit(oldp+73,(vlTOPp->top__DOT__P_U));
        tracep->chgBit(oldp+74,(vlTOPp->top__DOT__P_D));
        tracep->chgBit(oldp+75,(vlTOPp->top__DOT__P_L));
        tracep->chgBit(oldp+76,(vlTOPp->top__DOT__P_R));
        tracep->chgBit(oldp+77,(vlTOPp->top__DOT__P_tr));
        tracep->chgBit(oldp+78,(vlTOPp->top__DOT__ioctl_download));
        tracep->chgBit(oldp+79,(vlTOPp->top__DOT__ioctl_upload));
        tracep->chgBit(oldp+80,(vlTOPp->top__DOT__ioctl_wr));
        tracep->chgIData(oldp+81,(vlTOPp->top__DOT__ioctl_addr),25);
        tracep->chgCData(oldp+82,(vlTOPp->top__DOT__ioctl_dout),8);
        tracep->chgCData(oldp+83,(vlTOPp->top__DOT__ioctl_din),8);
        tracep->chgCData(oldp+84,(vlTOPp->top__DOT__ioctl_index),8);
        tracep->chgBit(oldp+85,(vlTOPp->top__DOT__ioctl_wait));
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
