// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk_28_636", false,-1);
        tracep->declBit(c+2,"clk_25", false,-1);
        tracep->declBit(c+3,"clk_14_318", false,-1);
        tracep->declBit(c+4,"reset", false,-1);
        tracep->declBus(c+5,"inputs", false,-1, 11,0);
        tracep->declBit(c+6,"clk_48", false,-1);
        tracep->declBit(c+7,"clk_12", false,-1);
        tracep->declBit(c+8,"ce_pix", false,-1);
        tracep->declBit(c+9,"VGA_HB", false,-1);
        tracep->declBit(c+10,"VGA_HS", false,-1);
        tracep->declBit(c+11,"VGA_VB", false,-1);
        tracep->declBit(c+12,"VGA_VS", false,-1);
        tracep->declBus(c+13,"VGA_R", false,-1, 5,0);
        tracep->declBus(c+14,"VGA_G", false,-1, 5,0);
        tracep->declBus(c+15,"VGA_B", false,-1, 5,0);
        tracep->declBit(c+16,"SRAM_WE_n", false,-1);
        tracep->declBus(c+17,"SRAM_A", false,-1, 20,0);
        tracep->declBus(c+18,"SRAM_D", false,-1, 7,0);
        tracep->declBit(c+19,"LED", false,-1);
        tracep->declBit(c+20,"AUDIO_L", false,-1);
        tracep->declBit(c+21,"AUDIO_R", false,-1);
        tracep->declBit(c+22,"PS2CLKA", false,-1);
        tracep->declBit(c+23,"PS2CLKB", false,-1);
        tracep->declBit(c+24,"PS2DATA", false,-1);
        tracep->declBit(c+25,"PS2DATB", false,-1);
        tracep->declBit(c+26,"SD_nCS", false,-1);
        tracep->declBit(c+27,"SD_DI", false,-1);
        tracep->declBit(c+28,"SD_CK", false,-1);
        tracep->declBit(c+29,"SD_DO", false,-1);
        tracep->declBit(c+30,"P_A", false,-1);
        tracep->declBit(c+31,"P_U", false,-1);
        tracep->declBit(c+32,"P_D", false,-1);
        tracep->declBit(c+33,"P_L", false,-1);
        tracep->declBit(c+34,"P_R", false,-1);
        tracep->declBit(c+35,"P_tr", false,-1);
        tracep->declBit(c+36,"ioctl_download", false,-1);
        tracep->declBit(c+37,"ioctl_upload", false,-1);
        tracep->declBit(c+38,"ioctl_wr", false,-1);
        tracep->declBus(c+39,"ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+40,"ioctl_dout", false,-1, 7,0);
        tracep->declBus(c+41,"ioctl_din", false,-1, 7,0);
        tracep->declBus(c+42,"ioctl_index", false,-1, 7,0);
        tracep->declBit(c+43,"ioctl_wait", false,-1);
        tracep->declBit(c+44,"top clk_28_636", false,-1);
        tracep->declBit(c+45,"top clk_25", false,-1);
        tracep->declBit(c+46,"top clk_14_318", false,-1);
        tracep->declBit(c+47,"top reset", false,-1);
        tracep->declBus(c+48,"top inputs", false,-1, 11,0);
        tracep->declBit(c+49,"top clk_48", false,-1);
        tracep->declBit(c+50,"top clk_12", false,-1);
        tracep->declBit(c+51,"top ce_pix", false,-1);
        tracep->declBit(c+52,"top VGA_HB", false,-1);
        tracep->declBit(c+53,"top VGA_HS", false,-1);
        tracep->declBit(c+54,"top VGA_VB", false,-1);
        tracep->declBit(c+55,"top VGA_VS", false,-1);
        tracep->declBus(c+56,"top VGA_R", false,-1, 5,0);
        tracep->declBus(c+57,"top VGA_G", false,-1, 5,0);
        tracep->declBus(c+58,"top VGA_B", false,-1, 5,0);
        tracep->declBit(c+59,"top SRAM_WE_n", false,-1);
        tracep->declBus(c+60,"top SRAM_A", false,-1, 20,0);
        tracep->declBus(c+61,"top SRAM_D", false,-1, 7,0);
        tracep->declBit(c+62,"top LED", false,-1);
        tracep->declBit(c+63,"top AUDIO_L", false,-1);
        tracep->declBit(c+64,"top AUDIO_R", false,-1);
        tracep->declBit(c+65,"top PS2CLKA", false,-1);
        tracep->declBit(c+66,"top PS2CLKB", false,-1);
        tracep->declBit(c+67,"top PS2DATA", false,-1);
        tracep->declBit(c+68,"top PS2DATB", false,-1);
        tracep->declBit(c+69,"top SD_nCS", false,-1);
        tracep->declBit(c+70,"top SD_DI", false,-1);
        tracep->declBit(c+71,"top SD_CK", false,-1);
        tracep->declBit(c+72,"top SD_DO", false,-1);
        tracep->declBit(c+73,"top P_A", false,-1);
        tracep->declBit(c+74,"top P_U", false,-1);
        tracep->declBit(c+75,"top P_D", false,-1);
        tracep->declBit(c+76,"top P_L", false,-1);
        tracep->declBit(c+77,"top P_R", false,-1);
        tracep->declBit(c+78,"top P_tr", false,-1);
        tracep->declBit(c+79,"top ioctl_download", false,-1);
        tracep->declBit(c+80,"top ioctl_upload", false,-1);
        tracep->declBit(c+81,"top ioctl_wr", false,-1);
        tracep->declBus(c+82,"top ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+83,"top ioctl_dout", false,-1, 7,0);
        tracep->declBus(c+84,"top ioctl_din", false,-1, 7,0);
        tracep->declBus(c+85,"top ioctl_index", false,-1, 7,0);
        tracep->declBit(c+86,"top ioctl_wait", false,-1);
        tracep->declBit(c+87,"top clk_sys", false,-1);
        tracep->declBit(c+88,"top bios_req", false,-1);
        tracep->declBit(c+89,"top bios_tmp_din", false,-1);
        tracep->declBit(c+90,"top bios_tmp_addr", false,-1);
        tracep->declBus(c+95,"top BIOS DW", false,-1, 31,0);
        tracep->declBus(c+96,"top BIOS AW", false,-1, 31,0);
        tracep->declArray(c+97,"top BIOS FN", false,-1, 175,0);
        tracep->declBit(c+91,"top BIOS clock", false,-1);
        tracep->declBit(c+92,"top BIOS ce", false,-1);
        tracep->declBus(c+93,"top BIOS data_out", false,-1, 7,0);
        tracep->declBus(c+94,"top BIOS out_address", false,-1, 12,0);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Variables
    VlWide<6>/*191:0*/ __Vtemp2;
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk_28_636));
        tracep->fullBit(oldp+2,(vlTOPp->clk_25));
        tracep->fullBit(oldp+3,(vlTOPp->clk_14_318));
        tracep->fullBit(oldp+4,(vlTOPp->reset));
        tracep->fullSData(oldp+5,(vlTOPp->inputs),12);
        tracep->fullBit(oldp+6,(vlTOPp->clk_48));
        tracep->fullBit(oldp+7,(vlTOPp->clk_12));
        tracep->fullBit(oldp+8,(vlTOPp->ce_pix));
        tracep->fullBit(oldp+9,(vlTOPp->VGA_HB));
        tracep->fullBit(oldp+10,(vlTOPp->VGA_HS));
        tracep->fullBit(oldp+11,(vlTOPp->VGA_VB));
        tracep->fullBit(oldp+12,(vlTOPp->VGA_VS));
        tracep->fullCData(oldp+13,(vlTOPp->VGA_R),6);
        tracep->fullCData(oldp+14,(vlTOPp->VGA_G),6);
        tracep->fullCData(oldp+15,(vlTOPp->VGA_B),6);
        tracep->fullBit(oldp+16,(vlTOPp->SRAM_WE_n));
        tracep->fullIData(oldp+17,(vlTOPp->SRAM_A),21);
        tracep->fullCData(oldp+18,(vlTOPp->SRAM_D),8);
        tracep->fullBit(oldp+19,(vlTOPp->LED));
        tracep->fullBit(oldp+20,(vlTOPp->AUDIO_L));
        tracep->fullBit(oldp+21,(vlTOPp->AUDIO_R));
        tracep->fullBit(oldp+22,(vlTOPp->PS2CLKA));
        tracep->fullBit(oldp+23,(vlTOPp->PS2CLKB));
        tracep->fullBit(oldp+24,(vlTOPp->PS2DATA));
        tracep->fullBit(oldp+25,(vlTOPp->PS2DATB));
        tracep->fullBit(oldp+26,(vlTOPp->SD_nCS));
        tracep->fullBit(oldp+27,(vlTOPp->SD_DI));
        tracep->fullBit(oldp+28,(vlTOPp->SD_CK));
        tracep->fullBit(oldp+29,(vlTOPp->SD_DO));
        tracep->fullBit(oldp+30,(vlTOPp->P_A));
        tracep->fullBit(oldp+31,(vlTOPp->P_U));
        tracep->fullBit(oldp+32,(vlTOPp->P_D));
        tracep->fullBit(oldp+33,(vlTOPp->P_L));
        tracep->fullBit(oldp+34,(vlTOPp->P_R));
        tracep->fullBit(oldp+35,(vlTOPp->P_tr));
        tracep->fullBit(oldp+36,(vlTOPp->ioctl_download));
        tracep->fullBit(oldp+37,(vlTOPp->ioctl_upload));
        tracep->fullBit(oldp+38,(vlTOPp->ioctl_wr));
        tracep->fullIData(oldp+39,(vlTOPp->ioctl_addr),25);
        tracep->fullCData(oldp+40,(vlTOPp->ioctl_dout),8);
        tracep->fullCData(oldp+41,(vlTOPp->ioctl_din),8);
        tracep->fullCData(oldp+42,(vlTOPp->ioctl_index),8);
        tracep->fullBit(oldp+43,(vlTOPp->ioctl_wait));
        tracep->fullBit(oldp+44,(vlTOPp->top__DOT__clk_28_636));
        tracep->fullBit(oldp+45,(vlTOPp->top__DOT__clk_25));
        tracep->fullBit(oldp+46,(vlTOPp->top__DOT__clk_14_318));
        tracep->fullBit(oldp+47,(vlTOPp->top__DOT__reset));
        tracep->fullSData(oldp+48,(vlTOPp->top__DOT__inputs),12);
        tracep->fullBit(oldp+49,(vlTOPp->top__DOT__clk_48));
        tracep->fullBit(oldp+50,(vlTOPp->top__DOT__clk_12));
        tracep->fullBit(oldp+51,(vlTOPp->top__DOT__ce_pix));
        tracep->fullBit(oldp+52,(vlTOPp->top__DOT__VGA_HB));
        tracep->fullBit(oldp+53,(vlTOPp->top__DOT__VGA_HS));
        tracep->fullBit(oldp+54,(vlTOPp->top__DOT__VGA_VB));
        tracep->fullBit(oldp+55,(vlTOPp->top__DOT__VGA_VS));
        tracep->fullCData(oldp+56,(vlTOPp->top__DOT__VGA_R),6);
        tracep->fullCData(oldp+57,(vlTOPp->top__DOT__VGA_G),6);
        tracep->fullCData(oldp+58,(vlTOPp->top__DOT__VGA_B),6);
        tracep->fullBit(oldp+59,(vlTOPp->top__DOT__SRAM_WE_n));
        tracep->fullIData(oldp+60,(vlTOPp->top__DOT__SRAM_A),21);
        tracep->fullCData(oldp+61,(vlTOPp->top__DOT__SRAM_D),8);
        tracep->fullBit(oldp+62,(vlTOPp->top__DOT__LED));
        tracep->fullBit(oldp+63,(vlTOPp->top__DOT__AUDIO_L));
        tracep->fullBit(oldp+64,(vlTOPp->top__DOT__AUDIO_R));
        tracep->fullBit(oldp+65,(vlTOPp->top__DOT__PS2CLKA));
        tracep->fullBit(oldp+66,(vlTOPp->top__DOT__PS2CLKB));
        tracep->fullBit(oldp+67,(vlTOPp->top__DOT__PS2DATA));
        tracep->fullBit(oldp+68,(vlTOPp->top__DOT__PS2DATB));
        tracep->fullBit(oldp+69,(vlTOPp->top__DOT__SD_nCS));
        tracep->fullBit(oldp+70,(vlTOPp->top__DOT__SD_DI));
        tracep->fullBit(oldp+71,(vlTOPp->top__DOT__SD_CK));
        tracep->fullBit(oldp+72,(vlTOPp->top__DOT__SD_DO));
        tracep->fullBit(oldp+73,(vlTOPp->top__DOT__P_A));
        tracep->fullBit(oldp+74,(vlTOPp->top__DOT__P_U));
        tracep->fullBit(oldp+75,(vlTOPp->top__DOT__P_D));
        tracep->fullBit(oldp+76,(vlTOPp->top__DOT__P_L));
        tracep->fullBit(oldp+77,(vlTOPp->top__DOT__P_R));
        tracep->fullBit(oldp+78,(vlTOPp->top__DOT__P_tr));
        tracep->fullBit(oldp+79,(vlTOPp->top__DOT__ioctl_download));
        tracep->fullBit(oldp+80,(vlTOPp->top__DOT__ioctl_upload));
        tracep->fullBit(oldp+81,(vlTOPp->top__DOT__ioctl_wr));
        tracep->fullIData(oldp+82,(vlTOPp->top__DOT__ioctl_addr),25);
        tracep->fullCData(oldp+83,(vlTOPp->top__DOT__ioctl_dout),8);
        tracep->fullCData(oldp+84,(vlTOPp->top__DOT__ioctl_din),8);
        tracep->fullCData(oldp+85,(vlTOPp->top__DOT__ioctl_index),8);
        tracep->fullBit(oldp+86,(vlTOPp->top__DOT__ioctl_wait));
        tracep->fullBit(oldp+87,(vlTOPp->top__DOT__clk_sys));
        tracep->fullBit(oldp+88,(vlTOPp->top__DOT__bios_req));
        tracep->fullBit(oldp+89,(vlTOPp->top__DOT__bios_tmp_din));
        tracep->fullBit(oldp+90,(vlTOPp->top__DOT__bios_tmp_addr));
        tracep->fullBit(oldp+91,(vlTOPp->top__DOT__BIOS__DOT__clock));
        tracep->fullBit(oldp+92,(vlTOPp->top__DOT__BIOS__DOT__ce));
        tracep->fullCData(oldp+93,(vlTOPp->top__DOT__BIOS__DOT__data_out),8);
        tracep->fullSData(oldp+94,(vlTOPp->top__DOT__BIOS__DOT__out_address),13);
        tracep->fullIData(oldp+95,(8U),32);
        tracep->fullIData(oldp+96,(0xdU),32);
        __Vtemp2[0U] = 0x2e686578U;
        __Vtemp2[1U] = 0x74313836U;
        __Vtemp2[2U] = 0x2f4e6578U;
        __Vtemp2[3U] = 0x42494f53U;
        __Vtemp2[4U] = 0x72746c2fU;
        __Vtemp2[5U] = 0x2e2fU;
        tracep->fullWData(oldp+97,(__Vtemp2),176);
    }
}
