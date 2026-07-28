# Zybo AXI DMA

A Zynq (Zybo) example that uses the Xilinx AXI DMA IP to move data between PS DDR memory and the programmable logic without tying up the CPU. The PS bare-metal software sets up the DMA descriptors/transfers, kicks off the movement over the AXI-Stream path, and checks the result.

## What it does

The block design connects the PS to an AXI DMA engine in the PL. From bare-metal C, the PS configures the DMA, starts a memory-to-stream and/or stream-to-memory transfer, waits for completion, and verifies the transferred data, printing status over UART. This is a template for building higher-throughput PS-PL data paths.

## Structure

- `sw_SDK/` - PS bare-metal C application that configures and drives the AXI DMA transfers.
- `tcl/` - Tcl script to regenerate the Vivado project and block design (PS + AXI DMA).

## Build and run

Open Vivado, switch to the Tcl Console, `cd` into the `tcl` folder and `source <script>.tcl` to rebuild the project and block design. Generate the bitstream and export the hardware, then in Vitis import `sw_SDK`, build, and run it on the board while watching the UART console for the transfer status.

## Requirements

- **Board:** Zybo Z7-20
- **Vivado:** 2019.1 (Vitis/SDK 2019.1 for the PS software)
