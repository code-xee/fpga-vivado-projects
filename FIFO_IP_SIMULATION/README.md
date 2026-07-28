# FIFO IP Simulation

A simulation-only project that exercises a Xilinx FIFO Generator IP in Vivado. A simple counter feeds incrementing values into the FIFO while the testbench drives the write/read control, letting you observe the full and empty flags, data ordering, and latency of the IP on the waveform viewer.

## What it does

- `Counter.v` generates a stream of incrementing data used as the FIFO write input.
- The FIFO Generator IP (rebuilt from the Tcl script) stores and returns that data.
- `FIFO_Simulation_wrapper.v` connects the counter and FIFO together for simulation.
- `test_bench.v` drives the clock, reset, and write/read enables and lets you watch the FIFO fill and drain.

## Structure

- `rtl/` - `Counter.v` and `FIFO_Simulation_wrapper.v`.
- `testbench/` - `test_bench.v` simulation driver.
- `tcl/` - Tcl script to regenerate the Vivado project and the FIFO Generator IP.

## Run the simulation

Open Vivado, switch to the Tcl Console, `cd` into the `tcl` folder and `source <script>.tcl` to rebuild the project (this regenerates the FIFO IP). Set `test_bench` as the simulation top, then run Behavioral Simulation to view the waveforms.

## Requirements

- **Board:** Zybo Z7-20 (simulation-only; no board needed to run the testbench)
- **Vivado:** 2019.1
