`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/12/2025 10:33:33 AM
// Design Name: 
// Module Name: Addr_Gen_TB
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


module Addr_Gen_TB();

reg clk;
reg reset_n;
reg Trigger;

wire [9:0]Addr;
wire  valid;

Address_Generator UUT(
.clk(clk),
.reset_n(reset_n),
.Trigger(Trigger),
.Addr(Addr),
.valid(valid)
);


initial begin
forever #5 clk = ~ clk;
end

initial begin
clk = 0;
reset_n = 0;
Trigger = 0;

#50
reset_n = 1;

#100
Trigger = 1;

#11000
Trigger = 0;

#100
Trigger = 1;

#11000
Trigger = 0;

#100
Trigger = 1;

end

endmodule
