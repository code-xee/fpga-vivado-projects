# UART Application

A board-level project that puts a custom UART receiver/transmitter to work in the programmable logic. Bytes received over the serial link are decoded and used to drive an RF-switch control block, giving a simple example of controlling on-board hardware from a UART command stream. It includes an XDC constraints file so it can be pinned out and run on a real board.

## What it does

The PL instantiates the custom `UART_RX` and `UART_TX` cores. Incoming serial data is received by `UART_RX`, and the decoded value is passed to the `RF_SWITCH` logic (`RF_SWITCH_wrapper.v`) to set the switch state, with `UART_TX` available to send data back over the link. The `xdc` constraints map the UART and switch signals to physical board pins.

## Structure

- `rtl/` - custom UART cores (`UART_RX.v`, `UART_TX.v`) and `RF_SWITCH_wrapper.v`.
- `sw_SDK/` - PS bare-metal C application for the project.
- `xdc/` - pin/timing constraints for the target board.
- `tcl/` - Tcl script to regenerate the Vivado project and block design.

## Build and run

Open Vivado, switch to the Tcl Console, `cd` into the `tcl` folder and `source <script>.tcl` to rebuild the project. Check the `xdc` constraints match your board before generating the bitstream. Export the hardware, then in Vitis import `sw_SDK`, build, and run on the board, driving the design from a serial terminal.

## Requirements

- **Board:** Zybo Z7-20
- **Vivado:** 2019.1 (Vitis/SDK 2019.1 for the PS software)
