`timescale 1ns/1ns

module top (

   input clk_28_636, // i
   input clk_25,     // i
   input clk_14_318, // i
	input reset,

   input [11:0]  inputs /*verilator public_flat*/,
   input clk_48 /*verilator public_flat*/,
   input clk_12 /*verilator public_flat*/,

   //.pal(),        // i
   //.scandouble(), // i

   output ce_pix,     // o

   output VGA_HB,     // o
   output VGA_HS,      // o
   output VGA_VB,     // o
   output VGA_VS,      // o

   output [5:0] VGA_R,      // o 5:0  ?? 7:0
   output [5:0] VGA_G,      // o 5:0  ?? 7:0
   output [5:0] VGA_B,      // o 5:0  ?? 7:0

   output SRAM_WE_n,  // o
   output [20:0] SRAM_A,     // o 20:0
   inout [7:0] SRAM_D,     // io 7:0

   output LED,        // o

   output AUDIO_L,    // o
   output AUDIO_R,    // o

   inout PS2CLKA,    // io
   inout PS2CLKB,    // io
   inout PS2DATA,    // io
   inout PS2DATB,    // io

   output SD_nCS,     // o
   output SD_DI,      // o
   output SD_CK,      // o
   output SD_DO,      // o

   input P_A,        // i
   input P_U,        // i
   input P_D,        // i
   input P_L,        // i
   input P_R,        // i
   input P_tr,        // i	

	input			   ioctl_download,
	input			   ioctl_upload,   
	input			   ioctl_wr,
	input [24:0]	ioctl_addr,
	input [7:0]		ioctl_dout,
	output [7:0]	ioctl_din,   
	input [7:0]		ioctl_index,
	output reg		ioctl_wait=1'b0
);


system ddr_186
(
	.clk_25(clk_sys), 		// VGA i
	.clk_sdr(clk_sys), 		// SDRAM i

	.CLK44100x256(clk_sys), 		// Soundwave i
	.CLK14745600(clk_sys), 		// RS232 clk i
	.clk_50(clk_50), 				// OPL3 i
	.clk_OPL(clk_50), 			// i

	.clk_cpu(clk_cpu),  	// i
	.clk_dsp(clk_sys), 		// i
	.cpu_speed(cpu_speed), 	// CPU speed control, 0 - maximum [1:0] i

	//.sdr_n_CS_WE_RAS_CAS({SDRAM_nCS, SDRAM_nWE, SDRAM_nRAS, SDRAM_nCAS}), // [3:0] o
	.sdr_BA(SDRAM_BA),  	// [1:0] o
	.sdr_ADDR(SDRAM_A),  	// [12:0] o
	.sdr_DATA(SDRAM_DQ), 	// [15:0] io
	//.sdr_DQM({SDRAM_DQMH, SDRAM_DQML}), // [1:0] o

	.sdr_n_CS(SDRAM_nCS),	// o
	.sdr_n_WE(SDRAM_nWE),	// o
	.sdr_n_RAS(SDRAM_nRAS),	// o
	.sdr_n_CAS(SDRAM_nCAS),	// o
	.sdr_DQMH(SDRAM_DQMH), 	// o
	.sdr_DQML(SDRAM_DQML), 	// o	
	.sdr_CKE(SDRAM_CKE),	// o

	.locked(pll_locked),	// i

	.VGA_R(vga_r), 			// [5:0] o
	.VGA_G(vga_g), 			// [5:0] o
	.VGA_B(vga_b), 			// [5:0] o

	.frame_on(),			// o

	.VGA_HSYNC(HSync), 		// o
	.VGA_VSYNC(VSync), 		// o

	.hblnk(HBlank), 		// o
	.vblnk(VBlank), 		// o

	.BTN_RESET(reset),		// Reset i
	.BTN_NMI(1'b0),			// NMI i

	.LED(),					// HALT [7:0] o

	.RS232_DCE_RXD(), 		// i
	.RS232_DCE_TXD(), 		// o
	.RS232_EXT_RXD(), 		// i
	.RS232_EXT_TXD(), 		// o
	.RS232_HOST_RXD(), 		// i
	.RS232_HOST_TXD(), 		// o
	.RS232_HOST_RST(), 		// o

	.SD_n_CS(SD_CS), 		// 1'b1, o
	.SD_DI(SD_MOSI), 		// o
	.SD_CK(SD_SCK), 		// 0, o
	.SD_DO(SD_MISO), 		// i
		 
	.AUD_L(AUDIO_L), 		// o
	.AUD_R(AUDIO_R), 		// o

	.PS2_CLK1_I(ps2_kbd_clk_in), 		// i
	.PS2_CLK1_O(ps2_kbd_clk_out), 		// o
	.PS2_CLK2_I(ps2_mouse_clk_in), 		// i
	.PS2_CLK2_O(ps2_mouse_clk_out), 	// o
	.PS2_DATA1_I(ps2_kbd_data_in), 		// i
	.PS2_DATA1_O(ps2_kbd_data_out), 	// o
	.PS2_DATA2_I(ps2_mouse_data_in), 	// i
	.PS2_DATA2_O(ps2_mouse_data_out), 	// o

	.GPIO(), 				// [7:0] io
	.I2C_SCL(), 			// o
	.I2C_SDA(), 			// io

	.BIOS_ADDR(bios_addr), 	// [12:0] i
	.BIOS_DIN(bios_din), 	// [15:0] i
	.BIOS_WR(bios_wr), 		// i
	.BIOS_REQ(bios_req) 	// o
);

/*
rom #(.DW(8), .AW(13), .FN("./rtl/BIOS/Next186.hex")) BIOS
(
	.clock  	(clk_sys	),
	.ce     	(bios_req	),
	.data_out   (bios_tmp_din	),
	.out_address(bios_tmp_addr  )
);
*/

/*
rom #(.DW(8), .AW(13), .FN("./rtl/BIOS/Next186.hex")) BIOS
(
	.clock  	(clk_sys	    ),
	.ce     	(bios_req	    ),
    .in_address (bios_load_addr ),
	.data_out   (bios_tmp_din	)
);
*/

endmodule
