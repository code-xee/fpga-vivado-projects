//Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
//Date        : Mon Nov  4 13:53:01 2024
//Host        : XEE running 64-bit major release  (build 9200)
//Command     : generate_target FIFO_Simulation_wrapper.bd
//Design      : FIFO_Simulation_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module FIFO_Simulation_wrapper
   (clk_0,
    dout_0,
    empty_0,
    full_0,
    rd_clk_0,
    rd_en_0,
    rd_rst_0,
    reset_0);
  input clk_0;
  output [15:0]dout_0;
  output empty_0;
  output full_0;
  input rd_clk_0;
  input rd_en_0;
  input rd_rst_0;
  input reset_0;

  wire clk_0;
  wire [15:0]dout_0;
  wire empty_0;
  wire full_0;
  wire rd_clk_0;
  wire rd_en_0;
  wire rd_rst_0;
  wire reset_0;

  FIFO_Simulation FIFO_Simulation_i
       (.clk_0(clk_0),
        .dout_0(dout_0),
        .empty_0(empty_0),
        .full_0(full_0),
        .rd_clk_0(rd_clk_0),
        .rd_en_0(rd_en_0),
        .rd_rst_0(rd_rst_0),
        .reset_0(reset_0));
endmodule
