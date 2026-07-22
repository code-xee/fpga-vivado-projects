`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/05/2023 02:28:25 PM
// Design Name: 
// Module Name: counter
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


module counter(clk,reset,t_ready,t_valid,counter,t_valid_out,t_last);

input clk, reset ;
input t_ready ;
input t_valid;
output reg [31:0] counter = 32'd0 ;
output reg t_valid_out = 0;
output wire t_last ;



always@(posedge clk or posedge reset)
begin
if((~reset) || ( (t_last) && (t_ready & t_valid)))
//if(~reset)
         begin
         counter <= 0;
         end
         else if(t_ready && t_valid)
         begin 
         counter <= counter +1 ;
         t_valid_out<= 1;
         end
         else begin 
          counter <= counter ;
          t_valid_out <=t_valid_out;
          end
end

assign t_last = (counter==32'd8192);   

endmodule
