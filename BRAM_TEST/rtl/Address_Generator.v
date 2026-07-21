`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/12/2025 10:11:40 AM
// Design Name: 
// Module Name: Address_Generator
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


module Address_Generator(
input clk,
input reset_n,
input Trigger,

output [9:0]Addr,
output  valid
);

localparam [1:0] IDLE = 2'b00 ,
                 START = 2'b01,
                 COUNT = 2'b10,
                 END = 2'b11;
                 
                 
 reg [1:0] current_state , next_state;
 reg trigger_reg;
 wire posedge_trig;
 reg [10:0] counter;
 
 assign posedge_trig = Trigger & ~trigger_reg;
 assign Addr = counter;
 
 assign valid = (current_state == COUNT) ? 1'b1 : 1'b0;
 
 
 always@(posedge clk) begin
    if(!reset_n) begin
        current_state <= IDLE ;
        trigger_reg <= 0;
    end
    else begin
        current_state <= next_state ;
        trigger_reg <= Trigger;
    end 
 end
 
 
 always@(posedge clk) begin
 if(!reset_n || current_state == IDLE ) begin
    counter <= 0;
 end
 else if(current_state == COUNT) begin
    counter <= counter + 1;
 end else begin
    counter <= counter;
 end
 
 end
 
 
 always@(*) begin
 
 case(current_state)
 
 IDLE : begin
         if(posedge_trig) begin
         next_state <= START;
         end
         else begin
         next_state <= IDLE;
         end
        end
 
START  : begin
         next_state <= COUNT;
        end
        
COUNT : begin
         if(counter < 1023) begin
         next_state <= COUNT;
         end
         else begin
         next_state <= END;
         end
        end
        
END : begin
        next_state <= IDLE;
        end
        
        default : next_state <= IDLE;
        
        endcase
 
 end
 
 
 
                












endmodule
