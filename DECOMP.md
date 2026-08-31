# Decompilation rules

- Target only the NTSC-U PS2 executable `SLUS_204.86` documented in the README.
- Keep original game binaries, assets, generated assembly, SDK files, and
  proprietary compiler tools out of Git.
- A function counts as matching C only after the selected Metrowerks PS2
  compiler reproduces its instructions and relocations exactly.
- Assembly placeholders and mechanically translated output count as zero.
- Whole-image linkage and target-hash verification remain the final gate.
- The deterministic ELF packer now reconstructs the complete retail
  `SLUS_204.86` container byte-for-byte from the exact hybrid loaded image.
- The current hybrid relink is byte-exact for the complete loaded image. Raw
  `.word` placeholders still count as zero matching source.
- Progress separately reports the conservative 3,293,696-byte text span and
  648,064-byte initialized-data span. Neither gaps nor mixed data count as C.

## Current unknowns

- The embedded component string is `MW MIPS C Compiler (2.4.1.01)`, but current
  compiler-in-the-loop evidence supports a mixed MWCCPS2 3.0/3.0.3 corpus; each
  unit records and verifies the compiler version that exactly reproduces it.
- The original translation-unit map was stripped; the current function
  inventory is an explicit-size spimdisasm baseline, not recovered source-file
  ownership.
- The disc includes multiple IOP modules; this initial project reports only the
  main Emotion Engine executable.

## Exact C checkpoint

The current sources contain exact address getters, simple/straight leaves,
direct tails, absolute and GP-relative dispatchers, signed-result/reset/call
handlers, and 2,077 verified dispatcher heads split from oversized assembly
ranges. `make match` verifies all 4,894 functions and 208,396/208,396 bytes
directly against retail, resolving HI16/LO16, R_MIPS_26, and GPREL16
relocations. The exact hybrid link places all 4,849 compiled functions at their
retail addresses, so all 208,396 bytes count as `complete_code`; 90,260 bytes
of source-owned initialized data (eight typed-as-zero regions and one symbolic
dispatch table) count as complete data. The split
residual spans remain assembly and count as zero.
