module bios(
  input clka,
  input ena,
  input wea,
  input [15:0] addra,
  input [7:0] dina,
  output reg [7:0] douta
);

reg [7:0] bios[8192:0];

initial $readmemh("Next186.hex", bios);

always @(posedge clka)
  if (ena)
		if (wea)
			bios[addra] <= dina;
		else
			douta <= bios[addra];

endmodule