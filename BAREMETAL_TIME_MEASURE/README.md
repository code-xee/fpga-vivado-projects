# Baremetal Time Measurement

A Zynq bare-metal example that shows how to measure elapsed time and clock cycles from PS software. It combines a custom AXI register IP in the PL (which exposes a free-running counter) with the Zynq PS global timer, so the same interval can be measured from both the hardware side and the processor side.

## What it does

Running on the PS (Zynq ARM core), the application:

- Reads the custom AXI register IP over the AXI-Lite bus and prints its register values, using one register as a hardware cycle counter to measure how long a block of code takes.
- Uses the PS global timer through `XTime_GetTime()` to time a delay loop, then converts the cycle count into seconds using the timer frequency and prints both the cycle count and elapsed time over UART.

## Structure

- `sw_SDK/` - PS bare-metal C application (`main.c`) that performs the measurements and prints results over UART.
- `tcl/` - Tcl script to regenerate the Vivado project and block design (PS + custom AXI register IP).

## Build and run

Open Vivado, switch to the Tcl Console, `cd` into the `tcl` folder and run `source <script>.tcl` to rebuild the project and block design. Generate the bitstream and export the hardware, then launch Vitis, import `sw_SDK/main.c`, build, and run it on the board while watching the UART console for the printed cycle counts and timing.
