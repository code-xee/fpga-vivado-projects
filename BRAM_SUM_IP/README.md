# BRAM Sum IP

A Zynq PS + PL example built around custom AXI4-Lite peripherals. The PS writes values into a register/BRAM-backed IP in the programmable logic, the PL adds them, and the PS reads the accumulated result back. It is a hands-on example of packaging your own AXI IP and driving it from bare-metal software.

## What it does

The PL contains two custom AXI IP cores (packaged in `ip/ip_repo`): a general AXI register block and an AXI "sum" block that adds the values written to it. From bare-metal C, the PS writes operands over the AXI-Lite bus, triggers the addition in hardware, and reads the resulting sum back through the memory-mapped registers, printing the values over UART.

## Structure

- `ip/ip_repo/` - Custom AXI IP cores: `AXI_REG_IP_1.0` (register block) and `AXI_REG_SUM_IP_1.0` (the summation block).
- `rtl/` - Block-design wrapper (`Bram_SUM_wrapper.v`) tying the PS and the custom IP together.
- `sw_SDK/` - PS bare-metal C application that writes operands, reads the sum, and prints results.
- `tcl/` - Tcl script to regenerate the Vivado project and block design.

## Build and run

Open Vivado, switch to the Tcl Console, `cd` into the `tcl` folder and `source <script>.tcl` to rebuild the project. Make sure the IP repository under `ip/ip_repo` is on the project's IP path so the custom cores resolve. Generate the bitstream, export the hardware, then in Vitis import `sw_SDK/main.c`, build, and run on the board while watching the UART console.

## Requirements

- **Board:** Zybo Z7-20
- **Vivado:** 2019.1 (Vitis/SDK 2019.1 for the PS software)
