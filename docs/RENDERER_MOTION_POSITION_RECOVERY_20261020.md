# Bounded renderer motion positions

`func_00140370` in verified `src/w9c.c` reads both a `V3` from
`D_00440C80[idx]` and an `f32` from `D_00440CD0[idx]`, then stores the index in
the created effect record. Its native caller at `0x003D1E04–0x003D1E78` has six
branches whose delay slots supply indices 0 through 5. The recovered extents are
therefore six V3 entries (72 bytes) at `0x00440C80` and six f32 values (24 bytes)
at `0x00440CD0`.

The remaining bytes in the original `0x00440C80–0x00440E70` owner remain raw:
`0x00440CC8–0x00440CD0` (8 bytes) and `0x00440CE8–0x00440E70` (392 bytes).
The typed objects and both raw gaps compile with MWCCPS2 3.0.3 `-O3
-sdatathreshold 0` and match the retail image exactly. The catalog validator passes.
