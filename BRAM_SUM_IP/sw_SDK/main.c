/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xtime_l.h"


int main()
{
    init_platform();

    print("Hello World\n\r");


    unsigned int* Bram_ptr = XPAR_AXI_BRAM_CTRL_0_S_AXI_BASEADDR ;

    for(int i=0 ; i < 5 ; i++)
    	Bram_ptr[i] = i;


    for(int i=0 ; i<10 ; i++)
    	xil_printf("Bram[%d]=%d\n\r", i , Bram_ptr[i]) ;

 unsigned int* axi_reg = XPAR_AXI_REG_SUM_IP_0_S00_AXI_BASEADDR;

    XTime time1 , time2 ;

    XTime_GetTime(&time1);

    for(int i=0 ; i < 1024 ; i++)
       	Bram_ptr[i] = i;

////////start//////
    axi_reg[0]=1;

/////done//////////
   while( axi_reg[1] != 1) ;


///sum/////////////
   int sum = axi_reg[3];


 /////start= 0 ;
   axi_reg[0]=0 ;

   XTime_GetTime(&time2);

xil_printf("SUM=%d\n\r", sum);


printf("Time for HW: t =%15.51f msec\n" , ((1000*(double)(time2-time1))/(XPAR_PS7_CORTEXA9_0_CPU_CLK_FREQ_HZ)));


///////////////////////////////////////Time For Processor/////////////////


unsigned int Bram2[1024] = {0} ;


XTime_GetTime(&time1);

for(int i=0 ; i < 1024 ; i++)
   	Bram2[i] = i;
sum= 0;
for(int i=0 ; i<1024 ; i++)
	sum += Bram2[i];


XTime_GetTime(&time2);

xil_printf("Sum = %d\n\r",sum);

printf("Time for PS: t =%15.51f msec\n" , ((1000*(double)(time2-time1))/(XPAR_PS7_CORTEXA9_0_CPU_CLK_FREQ_HZ)));






    cleanup_platform();
    return 0;
}
