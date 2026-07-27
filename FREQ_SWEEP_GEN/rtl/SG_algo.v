`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/22/2024 01:44:54 PM
// Design Name: 
// Module Name: SG_algo
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


module SG_algo(
    input clk, reset,
    input start,stop,
    output reg [31:0] phase_inc,
    output reg valid_phase 
    );
 reg  state_next, state_reg;
 reg [31:0] phase_inc_next;
 reg [31:0] Phase_first,Phase_Last;
 reg valid_phase_next;
 reg [9:0] cntr_next,cntr_reg;
 localparam 
            idle_state = 1'b0,
            data_state = 1'b1;   
    
 always@(posedge clk, posedge reset)
    begin
        if(reset)
            begin
                state_reg <= idle_state;
                phase_inc <= 0;  //1MHz
                cntr_reg  <= 1;
                valid_phase <=0;
            end
        else
            begin
                state_reg <= state_next;
                phase_inc <= phase_inc_next;
                cntr_reg  <= cntr_next;
                valid_phase <= valid_phase_next;
            end
    end
always@*
    begin
        state_next = state_reg;
        phase_inc_next = phase_inc;
        cntr_next = cntr_reg;
        Phase_first = 42949672; //1MHz
        Phase_Last = 1717986918; //40MHz
        valid_phase_next =valid_phase;
        case(state_reg)
            idle_state:
                begin
                    if(start)
                        begin
                            state_next = data_state;
                        end
                     phase_inc_next = 0;
                     cntr_next = 1;
                     valid_phase_next =0;
                end
            data_state:
                begin
                valid_phase_next =1;
                cntr_next = cntr_reg+1;
                      if(stop)
                        state_next = idle_state;
                      else
                        begin
                           phase_inc_next = Phase_first + (41875931 * cntr_reg); 
                            
                            if(cntr_reg == 41)
                                cntr_next = 1;
                        end
                end
            
        endcase
    end
endmodule
