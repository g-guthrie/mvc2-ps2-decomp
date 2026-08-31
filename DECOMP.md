# Decompilation rules

- Target only the NTSC-U PS2 executable `SLUS_204.86` documented in the README.
- Keep original game binaries, assets, generated assembly, SDK files, and
  proprietary compiler tools out of Git.
- A function counts as matching C only after the selected Metrowerks PS2
  compiler reproduces its instructions and relocations exactly.
- Assembly placeholders and mechanically translated output count as zero.
- Whole-image linkage and target-hash verification remain the final gate.
- The current hybrid relink is byte-exact for the complete loaded image. Raw
  `.word` placeholders still count as zero matching source.
- Progress separately reports the conservative 3,293,696-byte text span and
  648,064-byte initialized-data span. Neither gaps nor mixed data count as C.

## Current unknowns

- The exact CodeWarrior product build corresponding to the embedded component
  string `MW MIPS C Compiler (2.4.1.01)` still needs compiler-in-the-loop tests.
- The original translation-unit map was stripped; the current function
  inventory is an explicit-size spimdisasm baseline, not recovered source-file
  ownership.
- The disc includes multiple IOP modules; this initial project reports only the
  main Emotion Engine executable.

## Exact C checkpoint

`src/main.c` contains seven 12-byte global-address getters, and
`src/simple_leaves.c` contains 395 exact stubs, constant returns, field
getters/setters, and byte zeroers. `make match` verifies all 402 functions and
3,244/3,244 bytes directly against retail, resolving HI16/LO16 relocations for
the address getters. They are reported as matched, while `complete_code`
remains zero until C object placement is part of the exact hybrid link.
