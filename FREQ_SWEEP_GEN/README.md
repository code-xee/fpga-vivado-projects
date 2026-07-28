# Frequency Sweep Generator

A frequency-sweep (chirp) signal generator for FPGA. The core produces a ramping phase-increment word intended to drive a DDS, sweeping the output tone from roughly 1 MHz up to 40 MHz. It is provided with a testbench so the sweep behaviour can be verified in simulation.

## How it works

`SG_algo.v` implements a small two-state FSM (idle / data). While idle it waits for a `start` pulse; once started it steps the DDS `phase_inc` output from a low starting value (about 1 MHz) up to a high value (about 40 MHz), asserting `valid_phase` for each new sample and returning to idle when `stop` is asserted. Feeding `phase_inc` into a DDS/phase accumulator produces the swept-frequency waveform.

## Ports (SG_algo)

- `clk`, `reset` - clock and asynchronous reset.
- `start`, `stop` - begin and end the sweep.
- `phase_inc` - DDS phase-increment word that ramps across the sweep range.
- `valid_phase` - high when `phase_inc` holds a new valid value.

## Structure

- `rtl/` - `SG_algo.v`, the sweep-generation algorithm.
- `testbench/` - simulation driver for the sweep.
- `tcl/` - Tcl script to regenerate the Vivado project.

## Run the simulation

Open Vivado, switch to the Tcl Console, `cd` into the `tcl` folder and `source <script>.tcl` to rebuild the project. Set the testbench as the simulation top and run Behavioral Simulation to watch `phase_inc` ramp across the sweep.
