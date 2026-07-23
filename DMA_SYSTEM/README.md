# DMA System

Four Zynq PS+PL projects exercising the AXI DMA IP: `DMA_M2SS` streams a PS-side buffer out to a custom IP over AXI-Stream (MM2S), `DMA_S2MM` captures an AXI-Stream source into memory (S2MM), `DMA_S2MM_COUNTER` streams the output of a custom RTL counter into memory, and `DMA_S2MM_M2SS` chains both directions through a custom inverter IP for a full PS -> PL -> PS loopback test.
