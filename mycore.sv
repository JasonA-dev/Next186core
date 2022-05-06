//============================================================================
//
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the Free
//  Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
//  more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program; if not, write to the Free Software Foundation, Inc.,
//  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//============================================================================

module emu
(
	//Master input clock
	input         CLK_50M,

	//Async reset from top-level module.
	//Can be used as initial reset.
	input         RESET,

	//Must be passed to hps_io module
	inout  [48:0] HPS_BUS,

	//Base video clock. Usually equals to CLK_SYS.
	output        CLK_VIDEO,

	//Multiple resolutions are supported using different CE_PIXEL rates.
	//Must be based on CLK_VIDEO
	output        CE_PIXEL,

	//Video aspect ratio for HDMI. Most retro systems have ratio 4:3.
	//if VIDEO_ARX[12] or VIDEO_ARY[12] is set then [11:0] contains scaled size instead of aspect ratio.
	output [12:0] VIDEO_ARX,
	output [12:0] VIDEO_ARY,

	output  [5:0] VGA_R,
	output  [5:0] VGA_G,
	output  [5:0] VGA_B,
	output        VGA_HS,
	output        VGA_VS,
	output        VGA_DE,    // = ~(VBlank | HBlank)
	output        VGA_F1,
	output [1:0]  VGA_SL,
	output        VGA_SCALER, // Force VGA scaler

	input  [11:0] HDMI_WIDTH,
	input  [11:0] HDMI_HEIGHT,
	output        HDMI_FREEZE,

`ifdef MISTER_FB
	// Use framebuffer in DDRAM (USE_FB=1 in qsf)
	// FB_FORMAT:
	//    [2:0] : 011=8bpp(palette) 100=16bpp 101=24bpp 110=32bpp
	//    [3]   : 0=16bits 565 1=16bits 1555
	//    [4]   : 0=RGB  1=BGR (for 16/24/32 modes)
	//
	// FB_STRIDE either 0 (rounded to 256 bytes) or multiple of pixel size (in bytes)
	output        FB_EN,
	output  [4:0] FB_FORMAT,
	output [11:0] FB_WIDTH,
	output [11:0] FB_HEIGHT,
	output [31:0] FB_BASE,
	output [13:0] FB_STRIDE,
	input         FB_VBL,
	input         FB_LL,
	output        FB_FORCE_BLANK,

`ifdef MISTER_FB_PALETTE
	// Palette control for 8bit modes.
	// Ignored for other video modes.
	output        FB_PAL_CLK,
	output  [7:0] FB_PAL_ADDR,
	output [23:0] FB_PAL_DOUT,
	input  [23:0] FB_PAL_DIN,
	output        FB_PAL_WR,
`endif
`endif

	output        LED_USER,  // 1 - ON, 0 - OFF.

	// b[1]: 0 - LED status is system status OR'd with b[0]
	//       1 - LED status is controled solely by b[0]
	// hint: supply 2'b00 to let the system control the LED.
	output  [1:0] LED_POWER,
	output  [1:0] LED_DISK,

	// I/O board button press simulation (active high)
	// b[1]: user button
	// b[0]: osd button
	output  [1:0] BUTTONS,

	input         CLK_AUDIO, // 24.576 MHz
	output [15:0] AUDIO_L,
	output [15:0] AUDIO_R,
	output        AUDIO_S,   // 1 - signed audio samples, 0 - unsigned
	output  [1:0] AUDIO_MIX, // 0 - no mix, 1 - 25%, 2 - 50%, 3 - 100% (mono)

	//ADC
	inout   [3:0] ADC_BUS,

	//SD-SPI
	output        SD_SCK,
	output        SD_MOSI,
	input         SD_MISO,
	output        SD_CS,
	input         SD_CD,

	//High latency DDR3 RAM interface
	//Use for non-critical time purposes
	output        DDRAM_CLK,
	input         DDRAM_BUSY,
	output  [7:0] DDRAM_BURSTCNT,
	output [28:0] DDRAM_ADDR,
	input  [63:0] DDRAM_DOUT,
	input         DDRAM_DOUT_READY,
	output        DDRAM_RD,
	output [63:0] DDRAM_DIN,
	output  [7:0] DDRAM_BE,
	output        DDRAM_WE,

	//SDRAM interface with lower latency
	output        SDRAM_CLK,
	output        SDRAM_CKE,
	output [12:0] SDRAM_A,
	output  [1:0] SDRAM_BA,
	inout  [15:0] SDRAM_DQ,
	output        SDRAM_DQML,
	output        SDRAM_DQMH,
	output        SDRAM_nCS,
	output        SDRAM_nCAS,
	output        SDRAM_nRAS,
	output        SDRAM_nWE,

`ifdef MISTER_DUAL_SDRAM
	//Secondary SDRAM
	//Set all output SDRAM_* signals to Z ASAP if SDRAM2_EN is 0
	input         SDRAM2_EN,
	output        SDRAM2_CLK,
	output [12:0] SDRAM2_A,
	output  [1:0] SDRAM2_BA,
	inout  [15:0] SDRAM2_DQ,
	output        SDRAM2_nCS,
	output        SDRAM2_nCAS,
	output        SDRAM2_nRAS,
	output        SDRAM2_nWE,
`endif

	input         UART_CTS,
	output        UART_RTS,
	input         UART_RXD,
	output        UART_TXD,
	output        UART_DTR,
	input         UART_DSR,

	// Open-drain User port.
	// 0 - D+/RX
	// 1 - D-/TX
	// 2..6 - USR2..USR6
	// Set USER_OUT to 1 to read from USER_IN.
	input   [6:0] USER_IN,
	output  [6:0] USER_OUT,

	input         OSD_STATUS
);

///////// Default values for ports not used in this core /////////

assign ADC_BUS  = 'Z;
assign USER_OUT = '1;
assign {UART_RTS, UART_TXD, UART_DTR} = 0;
assign {SD_SCK, SD_MOSI, SD_CS} = 'Z;
assign {SDRAM_DQ, SDRAM_A, SDRAM_BA, SDRAM_CLK, SDRAM_CKE, SDRAM_DQML, SDRAM_DQMH, SDRAM_nWE, SDRAM_nCAS, SDRAM_nRAS, SDRAM_nCS} = 'Z;
assign {DDRAM_CLK, DDRAM_BURSTCNT, DDRAM_ADDR, DDRAM_DIN, DDRAM_BE, DDRAM_RD, DDRAM_WE} = '0;  

assign VGA_SL = 0;
assign VGA_F1 = 0;
assign VGA_SCALER = 0;
assign HDMI_FREEZE = 0;

assign AUDIO_S = 0;
assign AUDIO_MIX = 0;

assign LED_DISK = 0;
assign LED_POWER = 0;
assign BUTTONS = 0;

//////////////////////////////////////////////////////////////////

wire [1:0] ar = status[9:8];

assign VIDEO_ARX = (!ar) ? 12'd4 : (ar - 1'd1);
assign VIDEO_ARY = (!ar) ? 12'd3 : 12'd0;

`include "build_id.v" 
localparam CONF_STR = {
	"MyCore;;",
	"-;",
	"O89,Aspect ratio,Original,Full Screen,[ARC1],[ARC2];",
	"O2,TV Mode,NTSC,PAL;",
	"O34,CPU Speed,/1,/2,/3,/4;",
	"-;",
	"T0,Reset;",
	"R0,Reset and close OSD;",
	"V,v",`BUILD_DATE 
};

wire  [1:0] cpu_speed = status[4:3];

wire forced_scandoubler;
wire  [1:0] buttons;
wire [31:0] status;

wire ps2_kbd_clk_out;
wire ps2_kbd_data_out;
wire ps2_kbd_clk_in;
wire ps2_kbd_data_in;

wire ps2_mouse_clk_out;
wire ps2_mouse_data_out;
wire ps2_mouse_clk_in;
wire ps2_mouse_data_in;

wire        ioctl_download;
wire        ioctl_wr;
wire [24:0] ioctl_addr;
wire [15:0] ioctl_dout;
wire [15:0] ioctl_index;
wire        ioctl_wait;

hps_io #(.CONF_STR(CONF_STR), .WIDE(1)) hps_io
(
	.clk_sys(clk_sys),
	.HPS_BUS(HPS_BUS),
	.EXT_BUS(),
	.gamma_bus(),

	.forced_scandoubler(forced_scandoubler),

	.buttons(buttons),
	.status(status),
	.status_menumask({status[5]}),
	
	.ioctl_download(ioctl_download),
	.ioctl_wr(ioctl_wr),
	.ioctl_addr(ioctl_addr),
	.ioctl_dout(ioctl_dout),
	.ioctl_index(ioctl_index),
	.ioctl_wait(ioctl_wait),

	.ps2_kbd_clk_out(ps2_kbd_clk_out),
	.ps2_kbd_data_out(ps2_kbd_data_out),
	.ps2_kbd_clk_in(ps2_kbd_clk_in),
	.ps2_kbd_data_in(ps2_kbd_data_in),

	.ps2_mouse_clk_out(ps2_mouse_clk_out),
	.ps2_mouse_data_out(ps2_mouse_data_out),
	.ps2_mouse_clk_in(ps2_mouse_clk_in),
	.ps2_mouse_data_in(ps2_mouse_data_in)
);

///////////////////////   CLOCKS   ///////////////////////////////

wire clk_25, clk_70;

/*
wire clk_sys = clk_25;
wire clk_sdr = clk_70 * 2;
wire clk_cpu = clk_70;
wire clk_dsp = clk_70;
assign SDRAM_CLK = clk_70 * 2;
*/

assign SDRAM_CLK = clk_sys;

wire clk_sys = clk_25;
wire clk_sdr = clk_25 * 2;

pll pll
(
	.refclk(CLK_50M),
	.rst(0),
	.outclk_0(clk_25),
	.outclk_1(clk_70)	
);

reg  reset;
always @(posedge clk_sys) reset <= status[0] | buttons[1] | !bios_loaded;

//////////////////////////////////////////////////////////////////

wire HBlank;
wire HSync;
wire VBlank;
wire VSync;

system ddr_186
(
	.clk_25(clk_sys), 		// VGA i
	.clk_sdr(clk_sys), 		// SDRAM i

	.CLK44100x256(), 		// Soundwave i
	.CLK14745600(), 		// RS232 clk i
	.clk_50(), 				// OPL3 i
	.clk_OPL(), 			// i

	.clk_cpu(clk_sys),  	// i
	.clk_dsp(clk_sys), 		// i
	.cpu_speed(cpu_speed), 	// CPU speed control, 0 - maximum [1:0] i

	.sdr_n_CS_WE_RAS_CAS({SDRAM_nCS, SDRAM_nWE, SDRAM_nRAS, SDRAM_nCAS}), // [3:0] o
	.sdr_BA(SDRAM_BA),  	// [1:0] o
	.sdr_ADDR(SDRAM_A),  	// [12:0] o
	.sdr_DATA(SDRAM_DQ), 	// [15:0] io
	.sdr_DQM({SDRAM_DQMH, SDRAM_DQML}), // [1:0] o

	.VGA_R(VGA_R), 			// [5:0] o
	.VGA_G(VGA_G), 			// [5:0] o
	.VGA_B(VGA_B), 			// [5:0] o

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

reg [15:0] bios_tmp;
reg [12:0] bios_addr = 0;
reg [15:0] bios_din;
reg        bios_wr = 0;
wire       bios_req;
reg        bios_loaded;

/*
always @(posedge clk_sys) begin
	reg [7:0] dat;
	reg       bios_reqD;
	reg       ioctl_downlD;

	ioctl_downlD <= ioctl_download;
	if (ioctl_download & ~ioctl_downlD) begin
		bios_addr <= 0;
		bios_wr <= 0;
	end

	if (ioctl_downlD & ~ioctl_download) bios_loaded <= 1;

	if (ioctl_download & ioctl_wr) begin
		if (ioctl_addr[0]) begin
			bios_tmp[ioctl_addr[6:1]] <= {ioctl_dout, dat};
			if (&ioctl_addr[5:1]) bios_wr <= 1;
		end else begin
			dat <= ioctl_dout;
		end
	end

	bios_reqD <= bios_req;
	if (bios_reqD & ~bios_req) bios_wr <= 0;

	if (ioctl_download & bios_req) begin
		bios_addr <= bios_addr + 1'd1;
		bios_din <= bios_tmp[bios_addr[5:0]];
	end
end
*/

reg [13:0] bios_addr_counter = 0;
reg [13:0] bios_load_addr;
reg [7:0]  bios_tmp_din;

always @(posedge clk_sys) begin
   	reg [7:0]   dat;
   	reg         dat_set;

    // 0. if address is over 8191, then return that bios is Loaded
	if (bios_addr_counter >= 14'd8192) begin
		bios_loaded <= 1;
		bios_wr <= 0;
	end
	else begin
      	// 1. check if there is a bios request in 
      	if (bios_req) begin
         	// 2. check if bios is ready, and send the request
         	if(dat_set) begin
				bios_load_addr <= bios_load_addr + 1'd1;

				// Intel order correct LB+HB
				bios_tmp[15:8] <= bios_tmp_din;
				bios_tmp[7:0] <= dat;

            	bios_addr_counter <= bios_addr_counter + 1'd1;
            	dat_set <= 1'b0;
            	if (bios_load_addr > 1) begin
			    	bios_addr <= bios_load_addr[12:0] - 1;      
					bios_din <= bios_tmp;
	   	      		bios_wr <= 1;
                	//$display("dat_set %x bios_addr %x bios_tmp %x bios_tmp_din %x bios_load_addr %x dat %x", dat_set, bios_addr, bios_tmp, bios_tmp_din, bios_load_addr, dat);
            	end
         	end
        	else begin
        	// 3. if not, then create the bios data_out
        		dat <= bios_tmp_din;
            	dat_set <= 1'b1;
		    	bios_wr <= 0;
        	end
      	end
   	end
end

rom #(.DW(8), .AW(14), .FN("./rtl/BIOS/Next186.hex")) BIOS
(
	.clock  	(clk_sys	    ),
	.ce     	(bios_req	    ),
    .in_address (bios_load_addr ),
	.data_out   (bios_tmp_din	)
);

/*
rommif #(.DW(8), .AW(14), .FN("./rtl/BIOS/Next186.mif")) BIOS
(
	.clock  	(clk_sdr	    ),
	.ce     	(bios_req	    ),
    .in_address (bios_load_addr ),
	.data_out   (bios_tmp_din	)
);
*/

assign CLK_VIDEO = clk_sys;
assign CE_PIXEL = 1'b1;

assign VGA_DE = ~(HBlank | VBlank);
assign VGA_HS = HSync;
assign VGA_VS = VSync;

reg  [26:0] act_cnt;
always @(posedge clk_sys) act_cnt <= act_cnt + 1'd1; 
assign LED_USER    = act_cnt[26]  ? act_cnt[25:18]  > act_cnt[7:0]  : act_cnt[25:18]  <= act_cnt[7:0];

endmodule
