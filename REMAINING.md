# What is left

Snapshot after matching rounds 11–17. Code is 3,280,116 of 3,293,696 bytes
(99.59%) and data is 647,956 of 648,064 bytes (99.98%). The spans below are code that no credited C or
`.S` source covers yet: 54 spans, 13,396 bytes. Each one has a blocker class.
For classes (a), (c) and (d), the best near-miss source and notes are in the
session scratch folders (`r11_*` … `r17_*`).

## Hand-written assembly in the original (cannot be C)

These are policy questions, not matching problems. They can be credited only
as `.S` files, like the kernel and DECI2 stubs that are already credited.

| Span(s) | Bytes | What it is |
|---|---:|---|
| `_start` | 448 | crt0 startup (padduw clears, mthi1/mtsah, sync.p, syscall, ei) |
| func_001001D0, func_00106624 | 12 | syscall stub, and a lone `jr $ra` boundary stub |
| func_0010C6C0 | 860 | exception handler ($k0 save area, eret) |
| func_00102CA0, func_00102D70, func_00102DB8, func_00102EF0, func_00102F20, func_00102FC0, func_00103038, func_001030E0, func_00103188, func_00103718, func_001038C8 | 1,224 | libvu0 VU0/MMI fixed-register kernels (sceVu0*) |
| func_00106578 | 172 | cache-flush loop (`cache 0x18` + sync) |
| func_003DE160, func_003DE230, func_003DE7A0 | 472 | VU0 macro-mode matrix product and sqrt |
| func_0011D740, func_0011D7F0, func_0011D8F8 | 628 | newlib `libc/machine/r5900` memcpy/memmove/memset (`.S`). memcpy has been rebuilt byte-exact as `.S` |
| func_0011D5C8, func_0011D6A8, func_0011FC10, func_0011FD40, func_0011FE88, func_0011FFA0, func_001200D8, func_00120288, func_00120440 | 2,896 | newlib r5900 MMI string routines: memchr, memcmp, strcat, strcmp, strcpy, strlen, strncat, strncmp, strncpy |

## Held by the owner (C already matches byte-exact)

| Span | Bytes | Why it is held |
|---|---:|---|
| func_0012ADE0 | 2,800 | Indexes a 3-entry callback table that the data catalog splits into separate units (`data_callback_slot_0043CD08`, `…0C`, plus the first word of `data_u32_0043CD10`). Merging those into one `D_0043CD08[3]` unit would release it. |
| func_002861D0, func_002AB8F0, func_002B2630, func_002FBD80 | 672 | Each 112-byte source record is split across several data units. Each record needs one data unit. |
| func_00335C10, func_003363B0, func_00334F00 | 132 | The recorded reasons (overlapping table ownership, mixed return contracts) look resolved now. Re-check and flip. |
| func_0016EEC0 | 380 | Retail reads the caller's `$s1` before assigning it on the first iteration, so no C without an uninitialised read reproduces it. |

## Needs a compiler build that does not exist publicly (class a)

| Span | Bytes | Evidence |
|---|---:|---|
| residual func_003BFDC0 | 608 | It needs MW 3.0's short-loop padding (loops of ≤7 instructions padded to 8; 3.0.3/b22/2.4 pad ≤6 to 7) together with 3.0.3's float scheduling. No single build does both. The best 3.0.3 build is exact except for that padding nop. |
| func_001E7CB0 | 612 | Floats allocated before scheduling. The register picture matches `#pragma schedule off`, yet loads are still hoisted. |
| func_003F5630, func_003F5710 | 712 | Retail keeps a per-copy register for each unrolled `*s++` with one source register. On 3.0/3.0.3/b22 the post-increment never reaches the backend (pass-by-pass dumps). The MH1 decomp of the same Capcom `fl` library hits the same wall. |

## Structural, not solved (class d)

| Span | Bytes | Evidence |
|---|---:|---|
| func_003D6530 | 740 | The beqz target's first instruction is a HI16 `lui` with several predecessors, so the MW delay-slot filler (same rule in every build) emits a nop and never tries the fall-through. Retail stole from the fall-through. A dead store or a run-once loop would reproduce it, but both are disallowed steering. |

## Data placeholders

Every byte of the data range is now owned by a catalogued unit. The only data
not credited is 9 tiny units (108 bytes) at 0x00439090–0x004B57F0 that are
still placeholders in `config/data_matches.csv`.
