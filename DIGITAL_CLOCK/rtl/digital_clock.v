`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/25/2023 04:52:48 PM
// Design Name: 
// Module Name: digital_clock
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


module digital_clock(
input clk ,
input reset,
output reg [6:0]  segment ,
output reg [3:0]  anodes

    );
    
   
    reg [32:0] count ;
    reg clr_count;
    reg [5:0] mins;
    reg clr_mins;
    reg [4:0] hours;
    reg clr_hrs;
    reg [32:0] seg_count;
    
    
    wire [6:0]mins_msb ;
    wire [6:0]mins_lsb ;
    wire [6:0] hrs_msb ;
    wire [6:0] hrs_lsb;
  
  
  
  
  ///////////////////////count//////////////////////////////
    
  always@(posedge clk)
  begin
  if(reset || clr_count)
  
  count <= 0;
  else
   count <= count + 1;
  end 
  
  always@(*) 
  begin
  clr_count = count == 33'd59 ;
  end
  
  
////////////////////minutes//////////////////////////////////

always@(posedge clk)
begin 
      if(reset || clr_mins)
  
  mins <= 0;
  else if(clr_count)
  begin
   mins <= mins + 1;  
  end 
 end  
    
  always@(*)
  begin 
  clr_mins = clr_count & (mins  == 6'd59) ;
  end
  
////////////////////hours////////////////////////////////////////////////// 
  always@(posedge clk)
begin 
      if(reset || clr_hrs)
  
  hours <= 0;
  else if(clr_mins)
  begin
   hours <= hours + 1;  
  end 
 end  
    
  always@(*)
  begin 
  clr_hrs = clr_mins & (hours  == 5'd23) ;
  end
  
  ///////////////////segments///////////////////////
  
  segments s1( 
 .number(mins) ,
 .segments({mins_msb,mins_lsb})
 );
 
 
   segments s2( 
 .number({1'b0,hours}) ,
 .segments({hrs_msb,hrs_lsb})
 );
 
//////////////////////////segment counter////////////////

always@(posedge clk)
begin 
if(reset)

seg_count <= 0;

else

seg_count <= seg_count +1 ;

end 

//////////////////MUX//////////////////////////////////
always@(*)
begin 

case(seg_count[18:17])

2'd0 : segment = mins_lsb;
2'd1 : segment = mins_msb;
2'd2 : segment = hrs_lsb;
2'd3 : segment = hrs_msb;
endcase
end

//////////////////////

always@(*)
begin 

case(seg_count[18:17])

2'd0 : anodes = 4'b1110;
2'd1 : anodes = 4'b1101;
2'd2 : anodes = 4'b1011;
2'd3 : anodes = 4'b0111;
endcase
end

endmodule
