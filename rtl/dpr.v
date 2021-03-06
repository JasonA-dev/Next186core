//-------------------------------------------------------------------------------------------------
module dpr
//-------------------------------------------------------------------------------------------------
#
(
	parameter DW = 8,
	parameter AW = 14
)
(
	input  wire         clock,

	input  wire         ce1,
	input  wire         we1,  
	input  wire[   7:0] di1,      
	output reg [   7:0] do1,
	input  wire[AW-1:0] a1,

	input  wire         ce2,
	input  wire         we2,
	input  wire[   7:0] di2,
	output reg [   7:0] do2,
	input  wire[AW-1:0] a2
);
//-------------------------------------------------------------------------------------------------

reg[7:0] d[(2**AW)-1:0];
//reg [7:0] d[262143:0];

always @(posedge clock) 
    if(ce1) 
        if(we1) 
            d[a1] <= di1; 
        else 
            do1 <= d[a1];

always @(posedge clock) 
    if(ce2) 
        if(we2) 
            d[a2] <= di2; 
        else 
            do2 <= d[a2];

//-------------------------------------------------------------------------------------------------
endmodule
//-------------------------------------------------------------------------------------------------
