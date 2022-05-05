// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

const IData Vtop::var_top__DOT__BIOS__DOT__DW(8U);
const IData Vtop::var_top__DOT__BIOS__DOT__AW(0xdU);

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(_vcontextp__, this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values

    // Reset structure values
    _ctor_var_reset(this);
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-9);
    vlSymsp->_vm_contextp__->timeprecision(-9);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

// Savable
void Vtop::__Vserialize(VerilatedSerialize& os) {
    vluint64_t __Vcheckval = 0xed21fca8c73faae5ULL;
    os << __Vcheckval;
    os << __VlSymsp->_vm_contextp__;
    os<<clk_28_636;
    os<<clk_25;
    os<<clk_14_318;
    os<<reset;
    os<<inputs;
    os<<clk_48;
    os<<clk_12;
    os<<ce_pix;
    os<<VGA_HB;
    os<<VGA_HS;
    os<<VGA_VB;
    os<<VGA_VS;
    os<<VGA_R;
    os<<VGA_G;
    os<<VGA_B;
    os<<SRAM_WE_n;
    os<<SRAM_A;
    os<<SRAM_D;
    os<<LED;
    os<<AUDIO_L;
    os<<AUDIO_R;
    os<<PS2CLKA;
    os<<PS2CLKB;
    os<<PS2DATA;
    os<<PS2DATB;
    os<<SD_nCS;
    os<<SD_DI;
    os<<SD_CK;
    os<<SD_DO;
    os<<P_A;
    os<<P_U;
    os<<P_D;
    os<<P_L;
    os<<P_R;
    os<<P_tr;
    os<<ioctl_download;
    os<<ioctl_upload;
    os<<ioctl_wr;
    os<<ioctl_addr;
    os<<ioctl_dout;
    os<<ioctl_din;
    os<<ioctl_index;
    os<<ioctl_wait;
    os<<top__DOT__clk_28_636;
    os<<top__DOT__clk_25;
    os<<top__DOT__clk_14_318;
    os<<top__DOT__reset;
    os<<top__DOT__inputs;
    os<<top__DOT__clk_48;
    os<<top__DOT__clk_12;
    os<<top__DOT__ce_pix;
    os<<top__DOT__VGA_HB;
    os<<top__DOT__VGA_HS;
    os<<top__DOT__VGA_VB;
    os<<top__DOT__VGA_VS;
    os<<top__DOT__VGA_R;
    os<<top__DOT__VGA_G;
    os<<top__DOT__VGA_B;
    os<<top__DOT__SRAM_WE_n;
    os<<top__DOT__SRAM_A;
    os<<top__DOT__SRAM_D;
    os<<top__DOT__LED;
    os<<top__DOT__AUDIO_L;
    os<<top__DOT__AUDIO_R;
    os<<top__DOT__PS2CLKA;
    os<<top__DOT__PS2CLKB;
    os<<top__DOT__PS2DATA;
    os<<top__DOT__PS2DATB;
    os<<top__DOT__SD_nCS;
    os<<top__DOT__SD_DI;
    os<<top__DOT__SD_CK;
    os<<top__DOT__SD_DO;
    os<<top__DOT__P_A;
    os<<top__DOT__P_U;
    os<<top__DOT__P_D;
    os<<top__DOT__P_L;
    os<<top__DOT__P_R;
    os<<top__DOT__P_tr;
    os<<top__DOT__ioctl_download;
    os<<top__DOT__ioctl_upload;
    os<<top__DOT__ioctl_wr;
    os<<top__DOT__ioctl_addr;
    os<<top__DOT__ioctl_dout;
    os<<top__DOT__ioctl_din;
    os<<top__DOT__ioctl_index;
    os<<top__DOT__ioctl_wait;
    os<<top__DOT____Vcellout__BIOS__out_address;
    os<<top__DOT____Vcellout__BIOS__data_out;
    os<<top__DOT__clk_sys;
    os<<top__DOT__bios_req;
    os<<top__DOT__bios_tmp_din;
    os<<top__DOT__bios_tmp_addr;
    os<<top__DOT__BIOS__DOT__clock;
    os<<top__DOT__BIOS__DOT__ce;
    os<<top__DOT__BIOS__DOT__data_out;
    os<<top__DOT__BIOS__DOT__out_address;
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        os<<top__DOT__BIOS__DOT__d[__Vi0];
    }
    os<<__Vclklast__TOP__top__DOT__clk_sys;
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        os<<__Vm_traceActivity[__Vi0];
    }
    __VlSymsp->__Vserialize(os);
}
void Vtop::__Vdeserialize(VerilatedDeserialize& os) {
    vluint64_t __Vcheckval = 0xed21fca8c73faae5ULL;
    os.readAssert(__Vcheckval);
    os >> __VlSymsp->_vm_contextp__;
    os>>clk_28_636;
    os>>clk_25;
    os>>clk_14_318;
    os>>reset;
    os>>inputs;
    os>>clk_48;
    os>>clk_12;
    os>>ce_pix;
    os>>VGA_HB;
    os>>VGA_HS;
    os>>VGA_VB;
    os>>VGA_VS;
    os>>VGA_R;
    os>>VGA_G;
    os>>VGA_B;
    os>>SRAM_WE_n;
    os>>SRAM_A;
    os>>SRAM_D;
    os>>LED;
    os>>AUDIO_L;
    os>>AUDIO_R;
    os>>PS2CLKA;
    os>>PS2CLKB;
    os>>PS2DATA;
    os>>PS2DATB;
    os>>SD_nCS;
    os>>SD_DI;
    os>>SD_CK;
    os>>SD_DO;
    os>>P_A;
    os>>P_U;
    os>>P_D;
    os>>P_L;
    os>>P_R;
    os>>P_tr;
    os>>ioctl_download;
    os>>ioctl_upload;
    os>>ioctl_wr;
    os>>ioctl_addr;
    os>>ioctl_dout;
    os>>ioctl_din;
    os>>ioctl_index;
    os>>ioctl_wait;
    os>>top__DOT__clk_28_636;
    os>>top__DOT__clk_25;
    os>>top__DOT__clk_14_318;
    os>>top__DOT__reset;
    os>>top__DOT__inputs;
    os>>top__DOT__clk_48;
    os>>top__DOT__clk_12;
    os>>top__DOT__ce_pix;
    os>>top__DOT__VGA_HB;
    os>>top__DOT__VGA_HS;
    os>>top__DOT__VGA_VB;
    os>>top__DOT__VGA_VS;
    os>>top__DOT__VGA_R;
    os>>top__DOT__VGA_G;
    os>>top__DOT__VGA_B;
    os>>top__DOT__SRAM_WE_n;
    os>>top__DOT__SRAM_A;
    os>>top__DOT__SRAM_D;
    os>>top__DOT__LED;
    os>>top__DOT__AUDIO_L;
    os>>top__DOT__AUDIO_R;
    os>>top__DOT__PS2CLKA;
    os>>top__DOT__PS2CLKB;
    os>>top__DOT__PS2DATA;
    os>>top__DOT__PS2DATB;
    os>>top__DOT__SD_nCS;
    os>>top__DOT__SD_DI;
    os>>top__DOT__SD_CK;
    os>>top__DOT__SD_DO;
    os>>top__DOT__P_A;
    os>>top__DOT__P_U;
    os>>top__DOT__P_D;
    os>>top__DOT__P_L;
    os>>top__DOT__P_R;
    os>>top__DOT__P_tr;
    os>>top__DOT__ioctl_download;
    os>>top__DOT__ioctl_upload;
    os>>top__DOT__ioctl_wr;
    os>>top__DOT__ioctl_addr;
    os>>top__DOT__ioctl_dout;
    os>>top__DOT__ioctl_din;
    os>>top__DOT__ioctl_index;
    os>>top__DOT__ioctl_wait;
    os>>top__DOT____Vcellout__BIOS__out_address;
    os>>top__DOT____Vcellout__BIOS__data_out;
    os>>top__DOT__clk_sys;
    os>>top__DOT__bios_req;
    os>>top__DOT__bios_tmp_din;
    os>>top__DOT__bios_tmp_addr;
    os>>top__DOT__BIOS__DOT__clock;
    os>>top__DOT__BIOS__DOT__ce;
    os>>top__DOT__BIOS__DOT__data_out;
    os>>top__DOT__BIOS__DOT__out_address;
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        os>>top__DOT__BIOS__DOT__d[__Vi0];
    }
    os>>__Vclklast__TOP__top__DOT__clk_sys;
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        os>>__Vm_traceActivity[__Vi0];
    }
    __VlSymsp->__Vdeserialize(os);
}

void Vtop::_settle__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ce_pix = vlTOPp->ce_pix;
    vlTOPp->top__DOT__VGA_HB = vlTOPp->VGA_HB;
    vlTOPp->top__DOT__VGA_HS = vlTOPp->VGA_HS;
    vlTOPp->top__DOT__VGA_VB = vlTOPp->VGA_VB;
    vlTOPp->top__DOT__VGA_VS = vlTOPp->VGA_VS;
    vlTOPp->top__DOT__VGA_R = vlTOPp->VGA_R;
    vlTOPp->top__DOT__VGA_G = vlTOPp->VGA_G;
    vlTOPp->top__DOT__VGA_B = vlTOPp->VGA_B;
    vlTOPp->top__DOT__SRAM_WE_n = vlTOPp->SRAM_WE_n;
    vlTOPp->top__DOT__SRAM_A = vlTOPp->SRAM_A;
    vlTOPp->top__DOT__LED = vlTOPp->LED;
    vlTOPp->top__DOT__AUDIO_L = vlTOPp->AUDIO_L;
    vlTOPp->top__DOT__AUDIO_R = vlTOPp->AUDIO_R;
    vlTOPp->top__DOT__SD_nCS = vlTOPp->SD_nCS;
    vlTOPp->top__DOT__SD_DI = vlTOPp->SD_DI;
    vlTOPp->top__DOT__SD_CK = vlTOPp->SD_CK;
    vlTOPp->top__DOT__SD_DO = vlTOPp->SD_DO;
    vlTOPp->top__DOT__ioctl_din = vlTOPp->ioctl_din;
    vlTOPp->top__DOT__BIOS__DOT__clock = vlTOPp->top__DOT__clk_sys;
    vlTOPp->top__DOT__BIOS__DOT__ce = vlTOPp->top__DOT__bios_req;
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
    vlTOPp->top__DOT__bios_tmp_addr = (1U & (IData)(vlTOPp->top__DOT____Vcellout__BIOS__out_address));
    vlTOPp->top__DOT__bios_tmp_din = (1U & (IData)(vlTOPp->top__DOT____Vcellout__BIOS__data_out));
    vlTOPp->top__DOT__BIOS__DOT__data_out = vlTOPp->top__DOT____Vcellout__BIOS__data_out;
    vlTOPp->top__DOT__BIOS__DOT__out_address = vlTOPp->top__DOT____Vcellout__BIOS__out_address;
}

void Vtop::_initial__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<6>/*191:0*/ __Vtemp1;
    // Body
    vlTOPp->ioctl_wait = 0U;
    vlTOPp->PS2DATB = 0U;
    vlTOPp->PS2DATA = 0U;
    vlTOPp->PS2CLKB = 0U;
    vlTOPp->SRAM_D = 0U;
    vlTOPp->PS2CLKA = 0U;
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x74313836U;
    __Vtemp1[2U] = 0x2f4e6578U;
    __Vtemp1[3U] = 0x42494f53U;
    __Vtemp1[4U] = 0x72746c2fU;
    __Vtemp1[5U] = 0x2e2fU;
    VL_READMEM_N(true, 8, 8192, 0, VL_CVT_PACK_STR_NW(6, __Vtemp1)
                 ,  &(vlTOPp->top__DOT__BIOS__DOT__d)
                 , 0U, ~0ULL);
    vlTOPp->top__DOT__ioctl_wait = vlTOPp->ioctl_wait;
}

void Vtop::_settle__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ioctl_wait = vlTOPp->ioctl_wait;
    vlTOPp->top__DOT__PS2DATB = vlTOPp->PS2DATB;
    vlTOPp->top__DOT__PS2DATA = vlTOPp->PS2DATA;
    vlTOPp->top__DOT__PS2CLKB = vlTOPp->PS2CLKB;
    vlTOPp->top__DOT__SRAM_D = vlTOPp->SRAM_D;
    vlTOPp->top__DOT__PS2CLKA = vlTOPp->PS2CLKA;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vclklast__TOP__top__DOT__clk_sys = vlTOPp->top__DOT__clk_sys;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlTOPp->_settle__TOP__5(vlSymsp);
}

void Vtop::_ctor_var_reset(Vtop* self) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    if (false && self) {}  // Prevent unused
    self->clk_28_636 = 0;
    self->clk_25 = 0;
    self->clk_14_318 = 0;
    self->reset = 0;
    self->inputs = 0;
    self->clk_48 = 0;
    self->clk_12 = 0;
    self->ce_pix = 0;
    self->VGA_HB = 0;
    self->VGA_HS = 0;
    self->VGA_VB = 0;
    self->VGA_VS = 0;
    self->VGA_R = 0;
    self->VGA_G = 0;
    self->VGA_B = 0;
    self->SRAM_WE_n = 0;
    self->SRAM_A = 0;
    self->SRAM_D = 0;
    self->LED = 0;
    self->AUDIO_L = 0;
    self->AUDIO_R = 0;
    self->PS2CLKA = 0;
    self->PS2CLKB = 0;
    self->PS2DATA = 0;
    self->PS2DATB = 0;
    self->SD_nCS = 0;
    self->SD_DI = 0;
    self->SD_CK = 0;
    self->SD_DO = 0;
    self->P_A = 0;
    self->P_U = 0;
    self->P_D = 0;
    self->P_L = 0;
    self->P_R = 0;
    self->P_tr = 0;
    self->ioctl_download = 0;
    self->ioctl_upload = 0;
    self->ioctl_wr = 0;
    self->ioctl_addr = 0;
    self->ioctl_dout = 0;
    self->ioctl_din = 0;
    self->ioctl_index = 0;
    self->ioctl_wait = 0;
    self->top__DOT__clk_28_636 = 0;
    self->top__DOT__clk_25 = 0;
    self->top__DOT__clk_14_318 = 0;
    self->top__DOT__reset = 0;
    self->top__DOT__inputs = 0;
    self->top__DOT__clk_48 = 0;
    self->top__DOT__clk_12 = 0;
    self->top__DOT__ce_pix = 0;
    self->top__DOT__VGA_HB = 0;
    self->top__DOT__VGA_HS = 0;
    self->top__DOT__VGA_VB = 0;
    self->top__DOT__VGA_VS = 0;
    self->top__DOT__VGA_R = 0;
    self->top__DOT__VGA_G = 0;
    self->top__DOT__VGA_B = 0;
    self->top__DOT__SRAM_WE_n = 0;
    self->top__DOT__SRAM_A = 0;
    self->top__DOT__SRAM_D = 0;
    self->top__DOT__LED = 0;
    self->top__DOT__AUDIO_L = 0;
    self->top__DOT__AUDIO_R = 0;
    self->top__DOT__PS2CLKA = 0;
    self->top__DOT__PS2CLKB = 0;
    self->top__DOT__PS2DATA = 0;
    self->top__DOT__PS2DATB = 0;
    self->top__DOT__SD_nCS = 0;
    self->top__DOT__SD_DI = 0;
    self->top__DOT__SD_CK = 0;
    self->top__DOT__SD_DO = 0;
    self->top__DOT__P_A = 0;
    self->top__DOT__P_U = 0;
    self->top__DOT__P_D = 0;
    self->top__DOT__P_L = 0;
    self->top__DOT__P_R = 0;
    self->top__DOT__P_tr = 0;
    self->top__DOT__ioctl_download = 0;
    self->top__DOT__ioctl_upload = 0;
    self->top__DOT__ioctl_wr = 0;
    self->top__DOT__ioctl_addr = 0;
    self->top__DOT__ioctl_dout = 0;
    self->top__DOT__ioctl_din = 0;
    self->top__DOT__ioctl_index = 0;
    self->top__DOT__ioctl_wait = 0;
    self->top__DOT____Vcellout__BIOS__out_address = 0;
    self->top__DOT____Vcellout__BIOS__data_out = 0;
    self->top__DOT__clk_sys = 0;
    self->top__DOT__bios_req = 0;
    self->top__DOT__bios_tmp_din = 0;
    self->top__DOT__bios_tmp_addr = 0;
    self->top__DOT__BIOS__DOT__clock = 0;
    self->top__DOT__BIOS__DOT__ce = 0;
    self->top__DOT__BIOS__DOT__data_out = 0;
    self->top__DOT__BIOS__DOT__out_address = 0;
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        self->top__DOT__BIOS__DOT__d[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        self->__Vm_traceActivity[__Vi0] = 0;
    }
}
