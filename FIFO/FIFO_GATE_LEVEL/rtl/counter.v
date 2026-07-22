`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07/07/2024 04:42:38 PM
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


module counter(
    input clk,
    input reset,
    input increment,
    input decrement,
    output reg [2:0] count
    );
    
    reg enable;
    reg [3:0] mux_count;
    
    
    
    always@(*) begin
        enable = increment ^ decrement ;
    end
    
    always@(*) begin
    
    case(increment)
    
    1'b0 : mux_count = count - 1;
    1'b1 : mux_count = count + 1;
    
    endcase
    end
    
    
    
    always@(posedge clk) begin
    if(reset)
    
    count <= 1'b0;
    
    else if(enable) 
    
     count <= mux_count;
    
    
    end
endmodule
