`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/08/2024 12:45:21 PM
// Design Name: 
// Module Name: MUX
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


module MUX(a,b,c,d,e,f,out,sel);

input [31:0] a;
input [31:0] b;
input [31:0] c;
input [31:0] d;
input [31:0] e;
input [31:0] f;
input [2:0] sel;

output reg [31:0] out;


always@(*) begin

case(sel)

3'd0  :    begin 
           out = a;
            end
3'd1  :  begin
           out = b;
          end
3'd2  :    begin 
           out = c;
           end
3'd3  :    begin 
           out = d;
           end     
3'd4  :    begin 
           out = e;
           end 
3'd5  :    begin 
           out = f;
            end 
            
  default : begin out =32'd0; end       
                 
endcase


end




endmodule
