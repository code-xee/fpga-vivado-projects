`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/25/2023 05:32:59 PM
// Design Name: 
// Module Name: segments
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


module segments(
input [5:0] number ,
output reg [13:0] segments
    );
    
    
    always@(*)
    begin
    
    case(number)
    
    6'd0 : segments = 14'b1111110_1111110;
    6'd1 : segments = 14'b1111110_0110000;
    6'd2 : segments = 14'b1111110_1101101;
    6'd3 : segments = 14'b1111110_1111001;
    6'd4 : segments = 14'b1111110_0110011;
    6'd5 : segments = 14'b1111110_1011011;
    6'd6 : segments = 14'b1111110_1011111;
    6'd7 : segments = 14'b1111110_1110000;
    6'd8 : segments = 14'b1111110_1111111;
    6'd9 : segments = 14'b1111110_1111011;
    
    6'd10 : segments = 14'b0110000_1111110;
    6'd11 : segments = 14'b0110000_0110000;
    6'd12 : segments = 14'b0110000_1101101;
    6'd13 : segments = 14'b0110000_1111001;
    6'd14 : segments = 14'b0110000_0110011;
    6'd15 : segments = 14'b0110000_1011011;
    6'd16 : segments = 14'b0110000_1011111;
    6'd17 : segments = 14'b0110000_1110000;
    6'd18 : segments = 14'b0110000_1111111;
    6'd19 : segments = 14'b0110000_1111011;
    
    6'd20 : segments = 14'b1101101_1111110;
    6'd21 : segments = 14'b1101101_0110000;
    6'd22 : segments = 14'b1101101_1101101;
    6'd23 : segments = 14'b1101101_1111001;
    6'd24 : segments = 14'b1101101_0110011;
    6'd25 : segments = 14'b1101101_1011011;
    6'd26 : segments = 14'b1101101_1011111;
    6'd27 : segments = 14'b1101101_1110000;
    6'd28 : segments = 14'b1101101_1111111;
    6'd29 : segments = 14'b1101101_1111011;
    
    6'd30 : segments = 14'b1111001_1111110;
    6'd31 : segments = 14'b1111001_0110000;
    6'd32 : segments = 14'b1111001_1101101;
    6'd33 : segments = 14'b1111001_1111001;
    6'd34 : segments = 14'b1111001_0110011;
    6'd35 : segments = 14'b1111001_1011011;
    6'd36 : segments = 14'b1111001_1011111;
    6'd37 : segments = 14'b1111001_1110000;
    6'd38 : segments = 14'b1111001_1111111;
    6'd39 : segments = 14'b1111001_1111011;
    
    
    6'd40 : segments = 14'b0110011_1111110;
    6'd41 : segments = 14'b0110011_0110000;
    6'd42 : segments = 14'b0110011_1101101;
    6'd43 : segments = 14'b0110011_1111001;
    6'd44 : segments = 14'b0110011_0110011;
    6'd45 : segments = 14'b0110011_1011011;
    6'd46 : segments = 14'b0110011_1011111;
    6'd47 : segments = 14'b0110011_1110000;
    6'd48 : segments = 14'b0110011_1111111;
    6'd49 : segments = 14'b0110011_1111011;
    
    
    6'd50 : segments = 14'b1011011_1111110;
    6'd51 : segments = 14'b1011011_0110000;
    6'd52 : segments = 14'b1011011_1101101;
    6'd53 : segments = 14'b1011011_1111001;
    6'd54 : segments = 14'b1011011_0110011;
    6'd55 : segments = 14'b1011011_1011011;
    6'd56 : segments = 14'b1011011_1011111;
    6'd57 : segments = 14'b1011011_1110000;
    6'd58 : segments = 14'b1011011_1111111;
    6'd59 : segments = 14'b1011011_1111011;
  
    
    
    
    endcase 
    end
    
endmodule
