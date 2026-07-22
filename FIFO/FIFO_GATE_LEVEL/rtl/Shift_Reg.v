`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/08/2024 02:06:02 PM
// Design Name: 
// Module Name: Shift_Reg
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


module Shift_Reg(

input clk,
input reset,
input  wire [31:0] Data_in,
input enable,

output reg [31:0]  Data_out_0,
output reg [31:0]  Data_out_1,
output reg [31:0]  Data_out_2,
output reg [31:0]  Data_out_3,
output reg [31:0]  Data_out_4,
output reg [31:0]  Data_out_5
);



reg [5:0] Data_reg;

//assign Data_out = Data_reg;


always@(posedge clk or posedge reset) begin

if(reset) begin
    Data_out_0 <= 0;
    Data_out_1 <= 0;
    Data_out_2 <= 0;
    Data_out_3 <= 0;
    Data_out_4 <= 0;
    Data_out_5 <= 0;
end
else begin
    if(enable) begin
    Data_out_0 <= Data_in ;
    Data_out_1 <= Data_out_0 ;
    Data_out_2 <= Data_out_1 ;
    Data_out_3 <= Data_out_2 ;
    Data_out_4 <= Data_out_3 ;
    Data_out_5 <= Data_out_4 ;
    end
end
end






endmodule
