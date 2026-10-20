# Scene selector position fields at 0043F180

This recovery retains the existing C base symbol `data_f32_0043F180` and all existing address aliases, including the `D_0043F1A8` camera alias; the code address map records the internal `D_0043F180` and `D_0043F184` aliases used by native references.

The directly typed fields add 20 bytes over the existing 8-byte pair: row0 xyz (12 bytes), row1 xy (8 bytes), and row2 xy (8 bytes). Row1 Z at 0x43F194, row2 Z at 0x43F1A0, the 0x43F1A4 alignment word, the camera vector at 0x43F1A8, and all following bytes remain raw in the catalog interval layout.

## Native bound and lifecycle

- `func_00136830` creates 32 kind-6 callback actors, initializes each `+0xDC` to zero, and loads the fixed row0 xyz from `D_0043F180 + {0,4,8}` at 0x001368B8..0x001368C0 and 0x00136950..0x00136958. It installs `func_00136A10` as the callback. Setup calls it from `func_00329C50` and `func_0032C990`.
- `func_00136A10` computes `delta = (p[0xDC] ^ D_00583BC3) & 0xFF`. If global is 3, it reads unindexed row0 X/Y. Otherwise, when delta is nonzero, it uses `delta * 12` to read row X/Y. It ORs delta into `p[0xDC]`.
- `D_00583BC3` is written by four functions: reset to 0 in `func_00329C50`; set to 3 in `func_0032C990`; set to 3 for option 3 in `func_0013BD10`; OR `p[0x20]` or 3 in `func_0013BE20`. Complete sources `t2_b.c`, `x6_c.c`, and `g1.c` show option p20 values 1/2, and the exceptional 3.
- Every zero-reset path first calls `func_003DA410 -> func_003DA4A0`, which clears/rebuilds all 256 object-pool records, kind-6 list heads/counts, and free-list state before clearing the selector and respawning actors. Thus no old `+0xDC` values survive a reset. Within an epoch, global only grows via OR; pDC starts at zero and only ORs `delta`, so `pDC` is a subset of global. A nonzero indexed delta while global is not 3 can only be 1 or 2.
- The called `func_0032D390` and its helpers do not write `p[0xDC]` or the selector: it reads actor +0x34/+0x38, computes motion, and writes +0x5C/+0x68/+0x60/+0x6C.
- Binary rows are `(0,190,0)`, `(80,190,0)`, `(-80,190,0)` at stride 12. Only row0 Z is directly read; row1/2 Z remain raw. The next independent camera vector starts at 0x43F1A8.

## Verification

Each of the five complete data sections was independently recompiled with the
production MWCCPS2 3.0.3 `-O3 -sdatathreshold 0` profile and verified against
the private loaded image: 12, 8, 4, 8 and 320 bytes. The previous 352-byte
interval is preserved exactly, including the unread fields. Matching data
increases by 20 bytes; matching code is unchanged. No matching-code credit
is awarded for the native consumers used to establish these bounds.

Fresh split, full loaded-image linkage, packed ELF identity, catalog validation,
and all 91 tests pass. Data is 195,398 / 648,064 bytes (30.1510%); code remains
2,034,192 / 3,293,696 bytes (61.7602%). The source-derived data map drops the
retired raw-unit name and its incidental duplicate function label; the code
address map retains `func_0032D390` at its unchanged native address.
