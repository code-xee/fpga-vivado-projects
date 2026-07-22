`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/07/2024 04:39:33 PM
// Design Name: 
// Module Name: FIFO
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


module FIFO(
    input clk,
    input reset,
    input [31:0] data_in,
    input write_enable,
    input read_enable,
    output  [31:0] data_out,
    output  full,
    output  empty
    );
    
    
   
    
    reg [31:0] mem[5:0];
    wire [2:0] mux_enable;
    wire [31:0] REG_0;
    wire [31:0] REG_1;
    wire [31:0] REG_2;
    wire [31:0] REG_3;
    wire [31:0] REG_4;
    wire [31:0] REG_5;
    
Shift_Reg shift(

.clk(clk),
.reset(reset),
.Data_in(data_in),
.enable(write_enable),
.Data_out_0(REG_0),
.Data_out_1(REG_1),
.Data_out_2(REG_2),
.Data_out_3(REG_3),
.Data_out_4(REG_4),
.Data_out_5(REG_5)
);
    
    
counter  count(
.clk(clk),
.reset(reset),
.increment(write_enable),
.decrement(read_enable),
.count(mux_enable)
    );      
    

  MUX Mux_1(
  .a(REG_0),
  .b(REG_1),
  .c(REG_2),
  .d(REG_3),
  .e(REG_4),
  .f(REG_5),
  .out(data_out),
  .sel(mux_enable)
  );  
    
     assign full = (mux_enable == 6'd6) ? 1'b1 : 1'b0;
     assign empty = (mux_enable == 6'd6) ? 1'b0 : 1'b1;
     
endmodule
