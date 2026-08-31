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

The current sources contain exact address getters, simple/straight leaves,
direct tails, absolute and GP-relative dispatchers, and 430 nontrivial
signed-result handlers with real stack/control flow. `make match` verifies all
1,713 functions and 40,300/40,300 bytes directly against retail, resolving
HI16/LO16, R_MIPS_26, and GPREL16 relocations. The exact hybrid link places all
1,713 compiled functions at their retail addresses, so all 40,300 bytes count
as `complete_code`.
