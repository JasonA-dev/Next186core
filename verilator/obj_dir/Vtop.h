// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_H_
#define VERILATED_VTOP_H_  // guard

#include "verilated_heavy.h"
#include "verilated_save.h"
#include "Vtop__Dpi.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk_28_636,0,0);
    VL_IN8(clk_25,0,0);
    VL_IN8(clk_14_318,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(clk_48,0,0);
    VL_IN8(clk_12,0,0);
    VL_OUT8(ce_pix,0,0);
    VL_OUT8(VGA_HB,0,0);
    VL_OUT8(VGA_HS,0,0);
    VL_OUT8(VGA_VB,0,0);
    VL_OUT8(VGA_VS,0,0);
    VL_OUT8(VGA_R,5,0);
    VL_OUT8(VGA_G,5,0);
    VL_OUT8(VGA_B,5,0);
    VL_OUT8(SRAM_WE_n,0,0);
    VL_INOUT8(SRAM_D,7,0);
    VL_OUT8(LED,0,0);
    VL_OUT8(AUDIO_L,0,0);
    VL_OUT8(AUDIO_R,0,0);
    VL_INOUT8(PS2CLKA,0,0);
    VL_INOUT8(PS2CLKB,0,0);
    VL_INOUT8(PS2DATA,0,0);
    VL_INOUT8(PS2DATB,0,0);
    VL_OUT8(SD_nCS,0,0);
    VL_OUT8(SD_DI,0,0);
    VL_OUT8(SD_CK,0,0);
    VL_OUT8(SD_DO,0,0);
    VL_IN8(P_A,0,0);
    VL_IN8(P_U,0,0);
    VL_IN8(P_D,0,0);
    VL_IN8(P_L,0,0);
    VL_IN8(P_R,0,0);
    VL_IN8(P_tr,0,0);
    VL_IN8(ioctl_download,0,0);
    VL_IN8(ioctl_upload,0,0);
    VL_IN8(ioctl_wr,0,0);
    VL_IN8(ioctl_dout,7,0);
    VL_OUT8(ioctl_din,7,0);
    VL_IN8(ioctl_index,7,0);
    VL_OUT8(ioctl_wait,0,0);
    VL_IN16(inputs,11,0);
    VL_OUT(SRAM_A,20,0);
    VL_IN(ioctl_addr,24,0);

    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ top__DOT__clk_28_636;
    CData/*0:0*/ top__DOT__clk_25;
    CData/*0:0*/ top__DOT__clk_14_318;
    CData/*0:0*/ top__DOT__reset;
    CData/*0:0*/ top__DOT__clk_48;
    CData/*0:0*/ top__DOT__clk_12;
    CData/*0:0*/ top__DOT__ce_pix;
    CData/*0:0*/ top__DOT__VGA_HB;
    CData/*0:0*/ top__DOT__VGA_HS;
    CData/*0:0*/ top__DOT__VGA_VB;
    CData/*0:0*/ top__DOT__VGA_VS;
    CData/*5:0*/ top__DOT__VGA_R;
    CData/*5:0*/ top__DOT__VGA_G;
    CData/*5:0*/ top__DOT__VGA_B;
    CData/*0:0*/ top__DOT__SRAM_WE_n;
    CData/*7:0*/ top__DOT__SRAM_D;
    CData/*0:0*/ top__DOT__LED;
    CData/*0:0*/ top__DOT__AUDIO_L;
    CData/*0:0*/ top__DOT__AUDIO_R;
    CData/*0:0*/ top__DOT__PS2CLKA;
    CData/*0:0*/ top__DOT__PS2CLKB;
    CData/*0:0*/ top__DOT__PS2DATA;
    CData/*0:0*/ top__DOT__PS2DATB;
    CData/*0:0*/ top__DOT__SD_nCS;
    CData/*0:0*/ top__DOT__SD_DI;
    CData/*0:0*/ top__DOT__SD_CK;
    CData/*0:0*/ top__DOT__SD_DO;
    CData/*0:0*/ top__DOT__P_A;
    CData/*0:0*/ top__DOT__P_U;
    CData/*0:0*/ top__DOT__P_D;
    CData/*0:0*/ top__DOT__P_L;
    CData/*0:0*/ top__DOT__P_R;
    CData/*0:0*/ top__DOT__P_tr;
    CData/*0:0*/ top__DOT__ioctl_download;
    CData/*0:0*/ top__DOT__ioctl_upload;
    CData/*0:0*/ top__DOT__ioctl_wr;
    CData/*7:0*/ top__DOT__ioctl_dout;
    CData/*7:0*/ top__DOT__ioctl_din;
    CData/*7:0*/ top__DOT__ioctl_index;
    CData/*0:0*/ top__DOT__ioctl_wait;
    SData/*11:0*/ top__DOT__inputs;
    IData/*20:0*/ top__DOT__SRAM_A;
    IData/*24:0*/ top__DOT__ioctl_addr;

    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;

    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(VerilatedContext* contextp, const char* name = "TOP");
    Vtop(const char* name = "TOP")
      : Vtop(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);

    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();

    // INTERNAL METHODS
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vtop__Syms* __restrict vlSymsp);
  private:
    static void _ctor_var_reset(Vtop* self) VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__4(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
  public:
    void __Vserialize(VerilatedSerialize& os);
    void __Vdeserialize(VerilatedDeserialize& os);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


inline VerilatedSerialize& operator<<(VerilatedSerialize& os, Vtop& rhs) {
    Verilated::quiesce(); rhs.__Vserialize(os); return os; }
inline VerilatedDeserialize& operator>>(VerilatedDeserialize& os, Vtop& rhs) {
    Verilated::quiesce(); rhs.__Vdeserialize(os); return os; }

#endif  // guard
