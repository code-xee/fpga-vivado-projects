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

#define Transfer_length 1024
u32 data[Transfer_length] = {0};

int main() {
    // Initialize the platform
    init_platform();
    // Flush the data cache to ensure cache coherency
    				Xil_DCacheDisable();
    				Xil_ICacheDisable();

	while(1)
	{
		   xil_printf("Starting DMA transfer\n\r");
			// Check the control register
			u32 Cntrl_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x30);
				xil_printf("before -- Control Register = %08x \n\r", Cntrl_Reg);
				Xil_Out32(XPAR_AXI_DMA_0_BASEADDR + 0x30, 0x1);  // Enable S2MM
			Cntrl_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x30);
				xil_printf("after -- Control Register = %08x \n\r", Cntrl_Reg);

			////////////////////////////////////////////////////////////////////////////////////
			// Set up the destination address for the S2MM transfer
			u32 DA_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x48);
				xil_printf("before -- Destination Register = %08x \n\r", DA_Reg);
				Xil_Out32(XPAR_AXI_DMA_0_BASEADDR + 0x48, (u32)data);
			DA_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x48);
				xil_printf("after -- Destination Register = %08x \n\r", DA_Reg);


			// Set the transfer length
			u32 Length_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x58);
				xil_printf("before -- length Register = %08x \n\r", Length_Reg);
				Xil_Out32(XPAR_AXI_DMA_0_BASEADDR + 0x58, Transfer_length * sizeof(u32));
			Length_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x58);
				xil_printf("after -- length Register = %08x \n\r", Length_Reg);

			// Poll the status register until the transfer is complete
			u32 Status_reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x34);
			xil_printf("status_register = %08x \n\r", Status_reg);



				int i = 0;
				while (1)
				{
					Status_reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x34);
					xil_printf("Waiting for DMA Transfer = %08x, i = %d \n\r", Status_reg, i);
					if ((Status_reg & 0x00000001) == 0x00000001) {  // Check if the halt bit is set
						break;
					}
					i++;
					sleep(1);
				}

				// DMA transfer completed
				xil_printf("DMA transfer completed\n\r");
				xil_printf("Final Status Register = %08x \n\r", Status_reg);

				// Verify the received data
				for (int i = 0; i < Transfer_length; i++)
				{
					xil_printf("%d,",data[i]);
				}
				xil_printf("\n\r  Write data printing completed \n\r");

				xil_printf("Press any key to start the next transfer..");
               getchar();
               getchar();

		}

    // Cleanup the platform
    cleanup_platform();
    return 0;
}

