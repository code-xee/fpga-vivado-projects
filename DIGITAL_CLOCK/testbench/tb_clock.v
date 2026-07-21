`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/25/2023 06:46:14 PM
// Design Name: 
// Module Name: tb_clock
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


module tb_clock( );

 reg clk ;
reg reset;
wire [6:0] segment ;
wire [3:0] anodes;



digital_clock uut(
.clk(clk) ,
.reset(reset),
.segment(segment) ,
.anodes(anodes)

    );

initial 
begin
clk = 0;
forever #5 clk= ~clk;
end

initial 
begin

reset = 0;

@(posedge clk)
#1 reset = 1;

@(posedge clk)
#1 reset = 0;


repeat(10000)@(posedge clk);


end
endmodule
