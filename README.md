# FPGA Vivado Projects

A collection of complete Xilinx Vivado projects targeting Zynq-based boards (e.g. Zybo), combining programmable-logic (RTL) designs with PS bare-metal software where applicable. Each project folder contains RTL sources, a Tcl script to regenerate the Vivado project and block design, and any matching testbench or software needed to run it. New projects are added over time, so browse the folder list in this repository to see what's currently available.

## Getting Started

### 1. Clone the repository

```
git clone https://github.com/code-xee/fpga-vivado-projects.git
cd fpga-vivado-projects
```

### 2. Rebuild a project in Xilinx Vivado

1. Open Vivado and switch to the Tcl Console.
2. `cd` into the project's `tcl` folder and run `source <project-name>.tcl` to regenerate the Vivado project and block design.
3. If the folder includes a `testbench`, add it as a simulation source and run Behavioral Simulation to verify the RTL in isolation.
4. If the folder includes `sw_SDK`, generate the bitstream/platform, launch Vitis, import the C source, and run it on the board to exercise the PS-PL system end to end.

## Notes

- These are board-level Zynq projects (PS + PL), not simulation-only RTL modules - most require Vivado's IP Integrator / block-design flow rather than plain RTL simulation.
- Some projects target a specific board (e.g. Zybo); check each Tcl script/XDC before building for a different board.
