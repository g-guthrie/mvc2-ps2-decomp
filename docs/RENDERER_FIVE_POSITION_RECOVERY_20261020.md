# Five bounded renderer positions

The native setup function `func_0013F880` stores its second argument at
`p[0x22]` and indexes `D_00440820` only for selector modes zero and three.
Its native caller supplies selector zero when the source index is zero, and for
source indices 1–19 supplies `source_index % 5`; source indices 20 and above use
a different table. The five selected V3 values (indices 0–4) are also read by
verified callback `func_0013FAC0` in `src/wave25b.c`.

The typed extent is 60 bytes at `0x00440820`. Bytes
`0x0044085C–0x00440900` remain raw through the independently owned callback
table at `0x00440900`. The typed and raw objects compile with MWCCPS2 3.0.3
`-O3 -sdatathreshold 0` and match the retail image exactly; the catalog
validator passes.
