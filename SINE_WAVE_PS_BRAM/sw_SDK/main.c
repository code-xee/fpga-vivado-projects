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
 * main.c: simple test application
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




/******************************************************************************
* Xilinx Test Application - Write 32-bit IQ Sine Data to BRAM
******************************************************************************/

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"
#include "sleep.h"
#include "iq_wave_32bit.h"   // <-- Include your MATLAB-generated IQ data

#define BRAM XPAR_BRAM_0_BASEADDR   // Base address of AXI BRAM
#define TRIG XPAR_AXI_GPIO_0_BASEADDR // Trigger GPIO for ILA

int main()
{
    init_platform();

    xil_printf(" Starting IQ Data Write to BRAM...\n\r");

    // Ensure trigger is low at start
    Xil_Out32(TRIG, 0);

    // Main loop
    while (1)
    {
        xil_printf("\n\rPress ENTER to write IQ data to BRAM...\n\r");
        getchar();  // Wait for user input (you can trigger manually)

        xil_printf("Writing IQ data to BRAM...\n\r");

        // Write the IQ waveform data to BRAM
        for (uint32_t i = 0; i < sizeof(iq_wave_32bit)/sizeof(iq_wave_32bit[0]); i++)
        {
            Xil_Out32(BRAM + (i * 4), iq_wave_32bit[i]);  // Write 32-bit value to BRAM
        }

        xil_printf(" Data written to BRAM successfully (%d samples)\n\r",
                   sizeof(iq_wave_32bit)/sizeof(iq_wave_32bit[0]));

        // Trigger signal to ILA (optional)
        Xil_Out32(TRIG, 1);
        usleep(10);     // Short pulse
        Xil_Out32(TRIG, 0);

        xil_printf(" Trigger sent to ILA.\n\r");
    }

    cleanup_platform();
    return 0;
}
