# Sine Wave Generator

Two approaches to generating sine wave samples on a Zynq board: `SINE_WAVE_PL` streams pre-computed I/Q samples from a PL lookup table at a rate set by a `steps` input, while `SINE_WAVE_PS_BRAM` has the PS software populate a BRAM with sine values for the PL to read.
