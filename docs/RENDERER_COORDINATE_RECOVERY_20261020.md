# Bounded renderer coordinate recovery

This packet reconstructs 280 bytes of scene-coordinate data from the two
existing raw owners at `0x00460CC0` and `0x00460DC1`. The source and native
callers select only the listed entries; the intervening and trailing bytes
remain raw placeholders.

| Address | Typed extent | Bound evidence |
| --- | ---: | --- |
| `0x00460CC0` | 3 × `V3` (36 bytes) | `func_0034429C` calls `func_00343BE0` for indices 0–2; the consumer loads three floats at offsets 0, 4, and 8. |
| `0x00460CF0` | 4 × `V3` (48 bytes) | `func_003441E0` calls `func_00343C90` for indices 0–3. The created callback stores that index and reads `D_00460CF0[index]`. |
| `0x00460D20` | 4 × `f32` (16 bytes) | The same bounded callback index 0–3 selects the companion scalar. |
| `0x00460D30` | 2 × `V3` (24 bytes) | Native callsites `0x00342DF4` and `0x00342DFC` call `func_003440E0` with indices 0 and 1. |
| `0x00460D60` | 4 × `V3` (48 bytes) | Verified `func_00344700` calls `func_00344740` for indices 0–3. |
| `0x00460D90` | 4 × `V3` (48 bytes) | The same constructor loop bounds `func_00344740`; its callback passes the stored index to `func_00344990`, which reads the selected vector. |
| `0x00460DD0` | 1 × `V3` (12 bytes) | `func_00344D80` reads index 0. |
| `0x00460DE0` | 2 × `V3` (24 bytes) | Verified `func_00345080` calls `func_00344FF0` for indices 0–1. |
| `0x00460E00` | 2 × `V3` (24 bytes) | Verified `func_00345380` calls `func_00345300` for indices 0–1. |

The relevant native loop bounds are visible in `asm/main.s`: the four-entry
loops at `0x00344228`, `0x00344710`, `0x00345090`, and `0x00345390`; the
three-entry loop at `0x0034429C`; and the two explicit `func_003440E0` calls
at `0x00342DF4` and `0x00342DFC`. The matched C implementations are listed in
`config/matches.csv` for `src/t10_e.c`, `src/m14b.c`, `src/n4e.c`,
`src/fixed_entry_updates.c`, `src/t5_b.c`, `src/m6w9d.c`, `src/h8h.c`,
`src/wave22.c`, and `src/wave18.c`.

The gaps retained as placeholders are `0x00460CE4–0x00460CF0`,
`0x00460D48–0x00460D60`, `0x00460DC1–0x00460DD0`,
`0x00460DDC–0x00460DE0`, `0x00460DF8–0x00460E00`, and
`0x00460E18–0x00460E8C`. No remaining coordinate slot was credited solely
because it fell inside a physical raw owner.

All nine typed objects and six raw gap objects compiled with MWCCPS2 3.0.3
`-O3 -sdatathreshold 0` and matched the retail `SLUS_204.86` image exactly.
`tools/validate_progress_catalog.py` also passed.
