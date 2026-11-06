# Bounded renderer index table

`D_004784C0` is a 32-entry signed-index table consumed by exact C function
`func_003EB720` in `src/u3_m.c`. Its nested loops read exactly 4 × 8 entries
from the `s32 *tp` base and advance that pointer once per element, establishing
a 128-byte extent. Each value is used as an index into the already reconstructed
32-entry tables at `0x00478340` and `0x004783C0`. The table ends at the existing
next owner `0x00478540`; no following bytes were credited.

The new `data_s32_004784C0` object compiles with MWCCPS2 3.0.3 `-O3
-sdatathreshold 0` and matches the retail `SLUS_204.86` image exactly.
`tools/validate_progress_catalog.py` passes.
