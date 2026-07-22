`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/04/2024 01:15:37 PM
// Design Name: 
// Module Name: Counter
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


module Counter(


input clk,
input reset,
input full,

output reg [15:0]count_out,
output reg valid_out
    );
    
    
    
   always@(posedge clk ) begin
   
   if(reset) begin
       count_out <= 0;     
   end
   else if(count_out < 1024 && ~full) begin
       count_out <= count_out + 1 ; 
         valid_out <= 1;
   end 
   else if(full) begin 
     count_out <= count_out;
     valid_out <= 0;
   end
    
 end   
       
    
endmodule
