# FIR Low-Pass Filter Design

An end-to-end low-pass FIR filter example for Zynq, taking the design from MATLAB down to a running PS + PL system. MATLAB is used to design the filter and generate a noisy test signal, the programmable logic implements the FIR, and the PS software streams samples through it and collects the filtered output.

## Workflow

- In MATLAB, `DATA_NOISE.m` builds a test signal corrupted with noise, and `FIR_design_plots.m` designs the low-pass FIR filter and plots its frequency/impulse response and the filtering result.
- The resulting filter coefficients are implemented in the PL (via the Vivado project rebuilt from the Tcl script).
- The PS bare-metal software feeds the noisy samples through the FIR and reads back the smoothed output.

## Structure

- `matlab/` - `DATA_NOISE.m` (noisy test-signal generator) and `FIR_design_plots.m` (filter design and plots).
- `sw_SDK/` - PS bare-metal C application that streams samples through the filter.
- `tcl/` - Tcl script to regenerate the Vivado project and block design.

## Build and run

Run the MATLAB scripts first to design the filter and generate test data. Then open Vivado, switch to the Tcl Console, `cd` into the `tcl` folder and `source <script>.tcl` to rebuild the project. Generate the bitstream, export the hardware, and in Vitis import `sw_SDK`, build, and run on the board.
