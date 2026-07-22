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

// Initialize the data array with zeros
u32 data[1000] = {0};

int main() {
    // Initialize the platform
    init_platform();

    // Disable cache to avoid any inconsistencies during DMA transfer
    Xil_DCacheDisable();
    Xil_ICacheDisable();

    sleep(3);

    // Populate the data array using a for loop
    for (int i = 0; i < 130; i++) {
        data[i] = i + 1;
        xil_printf("data[%d] = %08x \n\r", i, data[i]);
    }

    // Configure and start the DMA transfer
    xil_printf("Starting DMA transfer\n\r");

    // Read and display the current Control Register value
    u32 Cntrl_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x00);
    xil_printf("Before -- Control Register = %08x \n\r", Cntrl_Reg);

    // Write to the Control Register to start the DMA transfer
    Xil_Out32(XPAR_AXI_DMA_0_BASEADDR + 0x00, 0x1);
    Cntrl_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x00);
    xil_printf("After -- Control Register = %08x \n\r", Cntrl_Reg);

    // Read and display the current Source Address Register value
    u32 Source_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x18);
    xil_printf("Before -- Source Register = %08x \n\r", Source_Reg);

    // Write to the Source Address Register with the base address of the data array
    Xil_Out32(XPAR_AXI_DMA_0_BASEADDR + 0x18, (u32)data);
    Source_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x18);
    xil_printf("After -- Source Register = %08x \n\r", Source_Reg);

    // Read and display the current Transfer Length Register value
    u32 Length_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x28);
    xil_printf("Before -- Length Register = %08x \n\r", Length_Reg);

    // Write to the Transfer Length Register with the size of the data array
    Xil_Out32(XPAR_AXI_DMA_0_BASEADDR + 0x28, 130 * sizeof(u32));
    Length_Reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x28);
    xil_printf("After -- Length Register = %08x \n\r", Length_Reg);

    // Read and display the initial Status Register value
    u32 Status_reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x04);
    xil_printf("Initial Status Register = %08x \n\r", Status_reg);

    // Poll the DMA status register to check for completion
    int i = 0;
    while (1) {
        Status_reg = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x04);
        xil_printf("Waiting for DMA Transfer = %08x, i = %d \n\r", Status_reg, i);
        if ((Status_reg & 0x00000002) == 0x00000002) {  // Check if the idle bit is set. Halt bit is not functioning as expected
            break;
        }
        i++;
        sleep(1);
    }

    // Indicate that the DMA transfer is completed
    xil_printf("DMA transfer completed \n\r");
    xil_printf("Final Status Register = %08x \n\r", Status_reg);

    // Cleanup the platform
    cleanup_platform();
    return 0;
}


