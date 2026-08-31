# Decompilation rules

- Target only the NTSC-U PS2 executable `SLUS_204.86` documented in the README.
- Keep original game binaries, assets, generated assembly, SDK files, and
  proprietary compiler tools out of Git.
- A function counts as matching C only after the selected Metrowerks PS2
  compiler reproduces its instructions and relocations exactly.
- Assembly placeholders and mechanically translated output count as zero.
- Whole-image linkage and target-hash verification remain the final gate.
- Progress uses the complete 3,941,760-byte loaded image as the conservative
  denominator until code/data boundaries are recovered.

## Current unknowns

- The exact CodeWarrior product build corresponding to the embedded component
  string `MW MIPS C Compiler (2.4.1.01)` still needs compiler-in-the-loop tests.
- The original translation-unit map and code/data boundaries were stripped.
- The disc includes multiple IOP modules; this initial project reports only the
  main Emotion Engine executable.

