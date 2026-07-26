#include "xparameters.h"
#include "xil_printf.h"
#include "xgpio.h"
#include "xil_types.h"

// Get device IDs from xparameters.h
#define BTN_ID XPAR_AXI_GPIO_0_DEVICE_ID
#define LED_ID XPAR_AXI_GPIO_LED_DEVICE_ID
#define BTN_CHANNEL 1
#define LED_CHANNEL 1
#define BTN_MASK 0b1111
#define LED_MASK 0b1111

int main() {
	XGpio_Config *cfg_ptr;
	XGpio led_device, btn_device;
	u32 data;
		xil_printf("Entered function main\r\n");
		// Initialize LED Device
		cfg_ptr = XGpio_LookupConfig(LED_ID);
		XGpio_CfgInitialize(&led_device, cfg_ptr, cfg_ptr->BaseAddress);

		// Initialize Button Device
		cfg_ptr = XGpio_LookupConfig(BTN_ID);
		XGpio_CfgInitialize(&btn_device, cfg_ptr, cfg_ptr->BaseAddress);

		// Set Button Tristate
		XGpio_SetDataDirection(&btn_device, BTN_CHANNEL, BTN_MASK);

		// Set Led Tristate
		XGpio_SetDataDirection(&led_device, LED_CHANNEL, 0);

		while (1) {
			data = XGpio_DiscreteRead(&btn_device, BTN_CHANNEL);
			data &= BTN_MASK;
			 if(data == 0b00000){} //do nothing

			 else if(data == 0b0001)
			         xil_printf("button 1 pressed\n\r");

			 else if(data == 0b0010)
			         xil_printf("button 2 pressed\n\r");

			 else if(data == 0b0100)
			         xil_printf("button 3 pressed\n\r");

			 else if(data == 0b1000)
			         xil_printf("button 4 pressed\n\r");

			  else
			         xil_printf("multiple buttons pressed\n\r");

			      usleep(200000);			//delay

			XGpio_DiscreteWrite(&led_device, LED_CHANNEL, data);
		}
	}
