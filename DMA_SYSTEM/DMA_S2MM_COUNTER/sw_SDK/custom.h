/*
 * custom.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Administrator
 */

#ifndef SRC_CUSTOM_H_
#define SRC_CUSTOM_H_



#endif /* SRC_CUSTOM_H_ */

#include "xil_io.h"
#include "sleep.h"
#include "stdio.h"


#define BUFFER_SIZE 8192
#define OFFSET 0x30     //Recieve



uint32_t data[BUFFER_SIZE] = {0};









int InitializeDma(){

	u32 temp;
	Xil_Out32(XPAR_AXIDMA_0_BASEADDR+OFFSET, 0x0004);
	usleep(20);
	temp=Xil_In32(XPAR_AXIDMA_0_BASEADDR+OFFSET);
	temp=temp | 0x0001;
	Xil_Out32(XPAR_AXIDMA_0_BASEADDR+OFFSET, temp);
	temp=Xil_In32(XPAR_AXIDMA_0_BASEADDR+OFFSET);
	xil_printf("Value in DMACR register: %08x \n\r", temp);

	return 0;
}


void StartDMATransfer(unsigned int src_addr, unsigned int length){

	u32 temp;
	temp= Xil_In32(XPAR_AXIDMA_0_BASEADDR + 0x48);
	xil_printf("Address value before: %08x \r\n", temp);
	Xil_Out32(XPAR_AXIDMA_0_BASEADDR + 0x48 , src_addr);
	temp=Xil_In32(XPAR_AXIDMA_0_BASEADDR + 0x48);
	xil_printf("Address value after: %08x \r\n", temp);

	temp= Xil_In32(XPAR_AXIDMA_0_BASEADDR + 0x58);
	xil_printf("Length value before: %d \r\n", temp);

	//DMA will start after writing to lenght register. Make sure the size of length variable is in accordance with value set in DMA IP.

	Xil_Out32(XPAR_AXIDMA_0_BASEADDR + 0x58, length);
//	getchar();



	usleep(1);

	xil_printf("value of length: %d \r\n", length);
}





