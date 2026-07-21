`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/04/2024 01:30:09 PM
// Design Name: 
// Module Name: test_bench
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module test_bench();

  reg clk_0;
  wire [15:0]dout_0;
  wire empty_0;
  wire full_0;
  reg rd_clk_0;
  reg rd_en_0;
  reg reset_0;
  reg rd_rst_0;


FIFO_Simulation_wrapper uut(
    .clk_0(clk_0),
    .dout_0(dout_0),
    .empty_0(empty_0),
    .full_0(full_0),
    .rd_clk_0(rd_clk_0),
    .rd_en_0(rd_en_0),
    .reset_0(reset_0),
    .rd_rst_0(rd_rst_0)
    
    );


always #5 rd_clk_0 = ~rd_clk_0; 

always #10 clk_0 = ~clk_0;


initial begin
rd_clk_0 =0;
clk_0 = 0;
reset_0 = 0;
rd_en_0 = 0;
rd_rst_0 = 0;


#100
reset_0 = 1;
#50
reset_0 = 0;
#20500

rd_rst_0 = 1;
#50
rd_rst_0 = 0;
#200
rd_en_0 = 1;

end



endmodule
