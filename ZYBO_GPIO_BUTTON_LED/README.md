# Zybo GPIO Button and LED

A Zynq (Zybo) getting-started example that reads the on-board push buttons and drives the LEDs through two AXI GPIO blocks in the PL, controlled by PS bare-metal software. It is a simple end-to-end PS + PL project that also demonstrates printing status over UART.

## What it does

The PL contains two AXI GPIO instances: one wired to the four buttons (input) and one to the four LEDs (output). The PS bare-metal application initializes both GPIO devices, sets their data directions, then loops continuously:

- Reads the button state over AXI.
- Prints which button (1-4) is pressed over UART, or notes when multiple buttons are pressed.
- Mirrors the button state onto the LEDs, with a short delay between updates.

## Structure

- `rtl/` - block-design wrapper (`PmodIPs_wrapper.v`) connecting the PS and the AXI GPIO blocks.
- `sw_SDK/` - PS bare-metal C application (`main.c`) that reads buttons, drives LEDs, and prints status.
- `tcl/` - Tcl script to regenerate the Vivado project and block design.

## Build and run

Open Vivado, switch to the Tcl Console, `cd` into the `tcl` folder and `source <script>.tcl` to rebuild the project and block design. Generate the bitstream and export the hardware, then in Vitis import `sw_SDK/main.c`, build, and run on the board. Press the buttons and watch the LEDs and the UART console.
