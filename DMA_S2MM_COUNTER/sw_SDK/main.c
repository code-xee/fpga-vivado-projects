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
#include "xil_io.h"
#include "sleep.h"
#include"custom.h"

int main()
{


while(1){

	xil_printf("Initializing DMA.....\n\r");
	InitializeDma();


	xil_printf("DMA initialized.....\n\r");




	xil_printf("DMA Transfer Start.....\n\r");

	StartDMATransfer(&data, BUFFER_SIZE);





			xil_printf("\r\n");

			uint32_t DMA_status = 0;
			while(1)
			{
				DMA_status = Xil_In32(XPAR_AXIDMA_0_BASEADDR + 0x0034);
				xil_printf("   0x34 = %d \r", DMA_status);
				if ((DMA_status & 0x00000001) == 0x00000001)


				{
					xil_printf("DMA Done\r\n");
					break;
				}
				xil_printf("*\r");
				xil_printf("#\r");
				xil_printf("$\r");





			}

			usleep(100);
			u32 temp;

			//printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%INTERRUPT CALLED%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n\r");
			temp=Xil_In32(XPAR_AXIDMA_0_BASEADDR+OFFSET);
			temp= temp & 0xEFFE;
			Xil_Out32(XPAR_AXIDMA_0_BASEADDR+OFFSET, temp);



			xil_printf("\r\n");


	/***************************************************************************************************************/
	// ZERAK UART




			char start_byte ='0';
			char start_freq[] = "400000000" ;
			char end_byte[] = "5730";
			char end_freq[] = "5900000000" ;

			printf("\n\r*******************************************************************************\n\r");

			printf(" %c >> %s\n\r " , start_byte, start_freq ) ;

		     for(int i = 0 ; i < BUFFER_SIZE ; i++ ){



		    		 printf(" %lld\n" , data[i]) ;

		}

		     printf(" %s >> %s\n " , end_byte , end_freq ) ;

}
}
