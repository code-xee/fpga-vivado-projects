`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////


module tb( );
reg readRand;
reg  ready;
reg clk;
reg enable;
reg [11:0] steps;
wire signed [15:0] outQ;
wire signed [15:0] outI;
reg reset;
integer ii;



top uut(
    .clk(clk),
    .enable(enable),
    .outI(outI),
    .outQ(outQ),
    .ready(ready),
    .steps(steps),
   .reset(reset)


);
always #20 clk = ~clk; 



initial begin 
    //Default values
//    ii = 0;
    

    
     
    clk = 1;
    enable = 1;
    ready = 1;
    steps = 1;
    
    reset = 1;  //Assert reset
    #2000;
    
    reset = 0;  //release reset
    #2000;
    
  #200000
  steps = 2;
    #200000
  steps = 3;
    #200000
  steps = 4;
    #200000
  steps = 5;
    #200000
  steps = 6;
    #200000
  steps = 7;
  

     forever begin
       ready = $random;
       #40;
     end
    
end

endmodule
