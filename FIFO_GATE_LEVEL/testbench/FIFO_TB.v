`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/08/2024 03:06:19 PM
// Design Name: 
// Module Name: FIFO_TB
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


module FIFO_TB();

  reg clk;
  reg reset;
  reg [31:0] data_in;
  reg write_enable;
  reg read_enable;
  wire [31:0] data_out;
  wire full;
  wire empty;


FIFO uut(
    .clk(clk),
    .reset(reset),
    .data_in(data_in),
    .write_enable(write_enable),
    .read_enable(read_enable),
    .data_out(data_out),
    .full(full),
    .empty(empty)
    );

always #5 clk = ~clk ;

initial begin

clk =0;
reset = 0;
write_enable = 0;
read_enable =0;
#10 

reset = 1;
write_enable = 0;
read_enable =0;
#10 
 
reset = 0;
write_enable = 0;
data_in = 0;
read_enable =0;
#10 
reset = 0;
write_enable = 1;
data_in = 10;
read_enable =0;
#10  

reset = 0;
write_enable = 1;
data_in = 20;
read_enable =0;
#10  

reset = 0;
write_enable = 1;
data_in = 30;
read_enable =0;
#10  

//reset = 0;
//write_enable = 1;
//data_in = 40;
read_enable =1;
#20  

reset = 0;
write_enable = 1;
data_in = 50;
read_enable =0;
#10  


reset = 0;
write_enable = 1;
data_in = 60;
read_enable =0;
#10  


write_enable = 0;
read_enable =1;
#60;

write_enable = 0;
read_enable =0;
#60;




end






endmodule
