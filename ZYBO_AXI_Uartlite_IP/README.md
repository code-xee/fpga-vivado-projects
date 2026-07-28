# Zybo AXI Uartlite IP

A Zynq (Zybo) example that adds a Xilinx AXI Uartlite IP in the programmable logic to give the PS an extra serial port beyond the hard PS UART. The PS bare-metal software drives the Uartlite core over the AXI-Lite bus to send and receive characters.

## What it does

The block design instantiates the AXI Uartlite IP and connects it to the PS via the AXI interconnect. From bare-metal C, the PS initializes the Uartlite driver and uses it to transmit and receive bytes over the PL-side serial link. It is a simple example of adding and driving a soft AXI peripheral from Zynq software.

## Structure

- `sw_SDK/` - PS bare-metal C application that configures and drives the AXI Uartlite core.
- `tcl/` - Tcl script to regenerate the Vivado project and block design (PS + AXI Uartlite IP).

## Build and run

Open Vivado, switch to the Tcl Console, `cd` into the `tcl` folder and `source <script>.tcl` to rebuild the project and block design. Generate the bitstream and export the hardware, then in Vitis import `sw_SDK`, build, and run it on the board, using a serial terminal on the Uartlite pins to exchange characters.
