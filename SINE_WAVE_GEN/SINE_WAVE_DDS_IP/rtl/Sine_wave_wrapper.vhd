--Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
--Date        : Sun Jul 26 10:44:49 2026
--Host        : DESKTOP-NKN4FMG running 64-bit major release  (build 9200)
--Command     : generate_target Sine_wave_wrapper.bd
--Design      : Sine_wave_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity Sine_wave_wrapper is
  port (
    sys_clk : in STD_LOGIC
  );
end Sine_wave_wrapper;

architecture STRUCTURE of Sine_wave_wrapper is
  component Sine_wave is
  port (
    sys_clk : in STD_LOGIC
  );
  end component Sine_wave;
begin
Sine_wave_i: component Sine_wave
     port map (
      sys_clk => sys_clk
    );
end STRUCTURE;
