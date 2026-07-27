`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/22/2024 02:20:39 PM
// Design Name: 
// Module Name: sim_SG
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


module sim_SG();
  reg clk_0;
  wire [31:0]m_axis_data_tdata_0;
  wire m_axis_data_tvalid_0;
  reg reset_0;
  reg start_0;
  reg stop_0;
  wire [31:0]S_0;
sweep_generator_wrapper uut
   (.clk_0(clk_0),
    .m_axis_data_tdata_0(m_axis_data_tdata_0),
    .m_axis_data_tvalid_0(m_axis_data_tvalid_0),
    .reset_0(reset_0),
    .start_0(start_0),
    .stop_0(stop_0),
    .S_0(S_0));

always #5 clk_0 =~clk_0;
initial
begin
    clk_0 =0;
    reset_0 =1;
    start_0 =0;
    stop_0  =0;
    
    #100;
    reset_0 =0;
    start_0 =0;
    stop_0  =0;
    
    #100;
    start_0 =1;
    stop_0  =0;
    
    #1000;
    start_0 =0;
    stop_0  =1;
    
    #100;
    start_0 =1;
    stop_0  =0;
    
    
end

endmodule
