# C coverage for the host port (Port A)

What the native/browser port can take from `src/` as honest C, and what it
cannot. "Honest C" means a `complete` row in `config/matches.csv`, which is the
only C that `DECOMP.md` credits (verified to match the instructions and
relocations exactly). Regenerate the numbers with:

```
python3 port/tools/list_c_less.py --summary --data          # counts and bytes
python3 port/tools/list_c_less.py --data --csv OUT.csv       # one row per span
```

The snapshot is from `origin/main` at `4c562a821` plus 2 commits (the merge that
added `src/sLb1_b.c` and `src/sLb1_c.c`), taken on 2026-10-28.

## Credited sources

| Set | Sources | Units | Bytes | Host build |
|---|---:|---:|---:|---|
| Game/SDK code, C (`matches.csv`, `.c`) | 6,383 | 20,037 `complete` + 44 `placeholder` | 3,102,928 credited | all compile (see HOST_BUILD_ISSUES.md) |
| Game/SDK code, assembly (`.S`) | 2 | 6 (kernel semaphore and DECI2 syscall stubs) | 96 | not compiled; platform layer |
| Data, C (`data_matches.csv`, not already in the code list) | 10,094 | 7,666 reconstructed + 2,425 alignment padding + 9 placeholder | 598,621 reconstructed | all compile |
| Data, VU1 microcode (`src/vu/*.vsm`) | 10 | 10 | 0x13F60 | not compiled; re-implement as shaders (RENDER_PATH.md) |
| Data, raw assembly (`src/data_asm/*.s`) | 5 | 5 | 0x11A8 | not compiled; must become C arrays before linking |

Text coverage: 20,043 credited functions out of the code and residual spans in
`config/functions.csv`. That is 3,102,928 of 3,185,368 bytes, or **97.41%**.

The 6,383 C sources include 21 files that contain only `placeholder`
functions. They are compiled anyway: hostify drops the barrier (R4/R5), so their
logic is available to read and to run. They stay uncredited.

### Credited C that is not portable C
These are allowed under the DECOMP.md exception for kernel and CPU operations.
The host build turns each of them into an explicit platform-layer hook.

- 3 credited functions are whole-function assembly written with the `FN(...)`
  macro: `func_001048B0` (COP0 Status read, `src/k2s.c`), `func_0010CA68`
  (`src/k5h.c`) and `func_0010CA20` (`src/s0h.c`). Hostify R6 drops them, and
  `port/tools/host_link_check.py` reports them as "no global definition".
- There are 238 inline-asm statement sites in 26 files, which become
  `ps2_asm_stmt(file, line, tmpl)` calls:
  - 156 sit in `src/grok_tiny_leaves.c`, mostly `addiu v1,r0,N; syscall`
    kernel stubs.
  - The rest are VU0 macro-mode blocks (`vu0_a/b/d/f.c`: lqc2/sqc2/vsub/vftoi),
    plus `sync`, `cache`, `mfc0`, `ei` and `di`.
  - The platform layer must give each one a meaning. PLATFORM_SURFACE.md lists
    them as boundary leaves (a_kernel, d_vu0, j_timer).
- 10 files walk the EE varargs register save area by hand with
  `__builtin_next_arg` or `__builtin_args_info`, for example `k5b.c`, `p3.c`,
  `nq32_b.c`, `sdk_format_message_003f5540.c` and
  `sony29_varargs_handler_00105E80.c`. They compile, but they leave an undefined
  `__builtin_next_arg`. Each one needs a host version that uses `va_list`
  (these are printf-style SDK and debug helpers).

## Functions with no honest C

| Class | Spans | Bytes | Meaning |
|---|---:|---:|---|
| unmatched | 93 | 68,176 | `functions.csv` code span with no `matches.csv` row. Only the retail assembly exists |
| residual | 13 | 2,196 | `assembly_residual` span with no row |
| placeholder | 44 | 12,068 | C exists and is readable, but it is uncredited (asm barrier or constraint) |
| **total without credited C** | **150** | **82,440** | 2.59% of the code |
| text gaps (`gaps.csv`) | 13,696 | 104,580 | inter-function padding: every gap is 0x10 bytes or less except one of 0x64 at `0x0042419C`. Not code |
| data placeholder | 9 | 108 | raw arrays or fills (uncredited data) |

By region, using the memory map in ENGINE_MAP.md:

| Region | unmatched | residual | placeholder |
|---|---|---|---|
| Sony SDK `0x100000-0x11FFFF` | 24 / 11,912 B | - | 18 / 2,824 B |
| Game `0x120000-0x3DAFFF` | 35 / 25,388 B | 13 / 2,196 B | 17 / 7,124 B |
| Render library `0x3DB000-0x3F0FFF` | 8 / 7,616 B | - | 4 / 604 B |
| CRI `0x3F1000-0x40FFFF` | 19 / 12,208 B | - | 2 / 1,260 B |
| Engine services `0x410000-0x4241FF` | 7 / 11,052 B | - | 3 / 256 B |

The largest are:

- `func_00412260` (0x12B0, engine services)
- `func_0012ADE0` (0xAF0, placeholder in `src/sc6_d.c`)
- `func_003EC160` (0xA7C, platform init, so it is replaced anyway)
- `func_001428E0` (0x8BC), `func_0038AA30` (0x8B0) and `func_00130040` (0x7D8),
  all game code
- `func_003DB020` (0x75C, render library)

The SDK, render-library and CRI spans are replaced wholesale by the platform
layer, so the port does not need their C. The **game-region** spans need host
C before the game runs end to end:

- 35 unmatched, 25,388 bytes
- 13 residuals, 2,196 bytes
- 17 placeholders, 7,124 bytes. These already compile on the host, with the
  barrier removed.

Data units are also referenced at addresses where no C exists (link-level
view, from `host_link_check.py`). There are 95 C-less function symbols and 635
code labels or tables referenced from C. These show where the game takes the
address of code that has no C. See HOST_BUILD_ISSUES.md, "Link level".
