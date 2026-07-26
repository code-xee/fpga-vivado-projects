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

//#include <stdio.h>
//#include "platform.h"
//#include "xil_printf.h"
//
//
//int main()
//{
//    init_platform();
//
//    print("Hello World\n\r");
//
//    cleanup_platform();
//    return 0;
//}



#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"
#include "xgpio.h"
#include "sleep.h"

#define GPIO_0  XPAR_AXI_GPIO_0_BASEADDR  // Tx_byte and flag_Tx
#define GPIO_1  XPAR_AXI_GPIO_1_BASEADDR  // check busy
#define GPIO_2  XPAR_AXI_GPIO_2_BASEADDR  // Rx_byte and flag_Rx

void sendChar(char ch) {
    u8 Busy = Xil_In8(GPIO_1);
    xil_printf("Busy = %d\n\r", Busy);

    // Send the character
    Xil_Out8(GPIO_0 + 0x0008, ch);
    char TX_Byte = Xil_In8(GPIO_0 + 0x0008);
    xil_printf("TX_Byte = %c\n\r", TX_Byte);

    // Set the flag to indicate transmission
    Xil_Out8(GPIO_0, 0x1);

    // Check busy status
    Busy = Xil_In8(GPIO_1);
    xil_printf("Busy = %d\n\r", Busy);

    // Small delay to allow the flag to be set
    usleep(9);

    // Clear the flag
    Xil_Out8(GPIO_0, 0x0);

    // Delay based on the busy status

    while(Busy != 0){} ;
//    if (!Busy) {
//        sleep(1);
//    }
    xil_printf("Character %c sent successfully\n\r", ch);

    // Read back the status
    Busy = Xil_In8(GPIO_1);
    xil_printf("Busy = %d\n\r", Busy);

    // Read received data
    u8 Flag_Rx = Xil_In8(GPIO_2);
    xil_printf("Flag Rx = %d\n\r", Flag_Rx);

    char RX_Byte = Xil_In8(GPIO_2 + 0x0008);
    xil_printf("RX_Byte = %c\n\r", RX_Byte);
}

int main() {
    char ch;
    init_platform();

    while (1) {



        xil_printf("Enter a character or press z to quit:\n\r");
        ch = getchar();
        xil_printf("ch = %c\n\r", ch);
        // Check for valid input
        if (    ch == 'a'|| ch == 'b'|| ch == 'c'|| ch == 'd'|| ch == 'e'||  // LNA 1,2,3,4,5=ON
        		ch == 'j'|| ch == 'k'|| ch == 'l'|| ch == 'm'|| ch == 'n'||  // LNA 1,2,3,4,5=OFF
				ch == 't'|| ch == 'f'|| ch == 'o'|| ch == 'u'|| ch == 'v'||  //RESET Arduino Hardware , Buzzer ON, Buzzer OFF, Led ON, Led OFF
			    ch == 'p'||  												 // Shut down (All Switches OFF)
				ch == 'q'||  												 //RFC connected to J1 (BAND A ON),
				ch == 'r'||  												 //RFC connected to J2 (BAND B ON)
				ch == 's'||  												 //RFC connected to J3 (BAND C ON)
			    ch == 'h'|| ch == 'g'|| ch == 'i')							 //ACS712 Scale,LM35 Scale,15.5V => 3.3V (1023)
        {
            sendChar(ch);
        } else if (ch == 'z') {
            xil_printf("****** Exit *****\n\r");
            break;  // Exit the loop if 'q' is pressed
        } else {
            xil_printf("Please enter a character:\n\r");
        }
        getchar();

        // Clear the input buffer
        //while (getchar() != ch);
    }

    cleanup_platform();
    return 0;
}
