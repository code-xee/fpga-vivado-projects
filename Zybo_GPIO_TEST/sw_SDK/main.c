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
#include "xgpiops.h"
#include "xil_io.h"
#include "sleep.h"
#include "xparameters.h"


#define PMOD_JA XPAR_AXI_GPIO_0_BASEADDR
#define PMOD_JB XPAR_AXI_GPIO_0_BASEADDR + 0x0008
#define PMOD_JC XPAR_AXI_GPIO_1_BASEADDR
#define PMOD_JD XPAR_AXI_GPIO_1_BASEADDR + 0x0008
#define PMOD_JE XPAR_AXI_GPIO_2_BASEADDR


#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0






int main()
{


    print("GPIO_TEST_START\n\r");

//    XGpioPs GPIO;
//    XGpioPs_Config *config;
//    int Status;
//
//    config = XGpioPs_LookupConfig(XPAR_XGPIOPS_0_DEVICE_ID);
//    Status = XGpioPs_CfgInitialize(&GPIO , config , config->BaseAddr);
//    	if(Status != XST_SUCCESS){
//
//    		return XST_FAILURE;
//    	}
//
//
//   XGpioPs_SetDirectionPin(&GPIO, 13, 1);
//   XGpioPs_SetOutputEnablePin(&GPIO, 13, 1);
//
//while(1){
//
//	XGpioPs_WritePin(&GPIO, 13 , 1);
//	sleep(1);
//	XGpioPs_WritePin(&GPIO, 13 , 0);
//	sleep(1);
////	XGpioPs_WritePin(&GPIO, 11 , 4);
////	sleep(1);
////	XGpioPs_WritePin(&GPIO, 12 , 8);
////	sleep(1);
////	XGpioPs_WritePin(&GPIO, 0 , 16);
////	sleep(1);
////	XGpioPs_WritePin(&GPIO, 9 , 32);
////	sleep(1);
////	XGpioPs_WritePin(&GPIO, 14 , 64);
////	sleep(1);
////	XGpioPs_WritePin(&GPIO, 15 , 128);
////	sleep(1);
////
//
//
//}


//   XGpioPs_SetDirectionPin(&GPIO, 10, 1);
//   XGpioPs_SetDirectionPin(&GPIO, 11, 1);
//   XGpioPs_SetDirectionPin(&GPIO, 12, 1);
//   XGpioPs_SetDirectionPin(&GPIO, 0, 1);
//   XGpioPs_SetDirectionPin(&GPIO, 9, 1);
//   XGpioPs_SetDirectionPin(&GPIO, 14, 1);
//   XGpioPs_SetDirectionPin(&GPIO, 15, 1);






  while(1) {

//	    Xil_Out8(PMOD_JA, 1);
//	    usleep(1);
//	    Xil_Out8(PMOD_JA, 2);
//	    usleep(1);
//	    Xil_Out8(PMOD_JA, 4);
//	    usleep(1);
//	    Xil_Out8(PMOD_JA, 8);
//	    usleep(1);
//	    Xil_Out8(PMOD_JA, 16);
//	    usleep(1);
//	    Xil_Out8(PMOD_JA, 32);
//	    usleep(1);
//	    Xil_Out8(PMOD_JA, 32);
//	    usleep(1);
//	    Xil_Out8(PMOD_JA, 32);
//	    usleep(1);
////
//
		Xil_Out8(PMOD_JB, 1);
		usleep(1);
		Xil_Out8(PMOD_JB, 2);
		usleep(1);
		Xil_Out8(PMOD_JB, 4);
		usleep(1);
		Xil_Out8(PMOD_JB, 8);
		usleep(1);
		Xil_Out8(PMOD_JB, 16);
		usleep(1);
		Xil_Out8(PMOD_JB, 32);
		usleep(1);
		Xil_Out8(PMOD_JB, 64);
		usleep(1);
		Xil_Out8(PMOD_JB, 128);
		usleep(1);
//
//
//		Xil_Out8(PMOD_JC, 1);
//		usleep(1);
//		Xil_Out8(PMOD_JC, 2);
//		usleep(1);
//		Xil_Out8(PMOD_JC, 4);
//		usleep(1);
//		Xil_Out8(PMOD_JC, 8);
//		usleep(1);
//		Xil_Out8(PMOD_JC, 16);
//		usleep(1);
//		Xil_Out8(PMOD_JC, 32);
//		usleep(1);
//		Xil_Out8(PMOD_JC, 64);
//		usleep(1);
//		Xil_Out8(PMOD_JC, 128);
//		usleep(1);
//
//
//		Xil_Out8(PMOD_JD, 1);
//		usleep(1);
//		Xil_Out8(PMOD_JD, 2);
//		usleep(1);
//		Xil_Out8(PMOD_JD, 4);
//		usleep(1);
//		Xil_Out8(PMOD_JD, 8);
//		usleep(1);
//		Xil_Out8(PMOD_JD, 16);
//		usleep(1);
//		Xil_Out8(PMOD_JD, 32);
//		usleep(1);
//		Xil_Out8(PMOD_JD, 64);
//		usleep(1);
//		Xil_Out8(PMOD_JD, 128);
//		usleep(1);
//
//		Xil_Out8(PMOD_JE, 1);
//		usleep(1);
//		Xil_Out8(PMOD_JE, 2);
//		usleep(1);
//		Xil_Out8(PMOD_JE, 4);
//		usleep(1);
//		Xil_Out8(PMOD_JE, 8);
//		usleep(1);
//		Xil_Out8(PMOD_JE, 16);
//		usleep(1);
//		Xil_Out8(PMOD_JE, 32);
//		usleep(1);
//		Xil_Out8(PMOD_JE, 64);
//		usleep(1);
//		Xil_Out8(PMOD_JE, 128);
//		usleep(1);



	    //XGpioPs_WritePin(&GPIO, 7 , LOW);   /** MIO13, PMOD JF PIN 1*/
		//sleep(1);
//		XGpioPs_WritePin(&GPIO,7,0);
//	   sleep(1);
//	   XGpioPs_WritePin(&GPIO,7,1);
//		XGpioPs_WritePin(&GPIO, 13 , 0);
//		sleep(1);
//		XGpioPs_WritePin(&GPIO, 10 , LOW);   /** MIO10, PMOD JF PIN 2*/
//		usleep(1);
//		XGpioPs_WritePin(&GPIO, 11 , LOW);   /** MIO11, PMOD JF PIN 3*/
//		usleep(1);
//		XGpioPs_WritePin(&GPIO, 12 , LOW);   /** MIO12, PMOD JF PIN 4*/
//		usleep(1);
//		XGpioPs_WritePin(&GPIO, 0 , LOW);   /** MIO0, PMOD JF PIN 5*/
//		usleep(1);
//		XGpioPs_WritePin(&GPIO, 9 , LOW);   /** MIO9, PMOD JF PIN 6*/
//		usleep(1);
//		XGpioPs_WritePin(&GPIO, 14 , LOW);   /** MIO14, PMOD JF PIN 7*/
//		usleep(1);
//		XGpioPs_WritePin(&GPIO, 15 , LOW);   /** MIO15, PMOD JF PIN 8*/
//		usleep(1);

  }




}
