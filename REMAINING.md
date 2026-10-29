# What is left

Snapshot after matching rounds 11–17. Code is 3,290,876 of 3,293,696 bytes
(99.91%) and data is 647,546 of 648,064 bytes (99.92%). The spans below are code that no credited C or
`.S` source covers yet: 2,820 bytes. Each one has a blocker class.
For classes (a), (c) and (d), the best near-miss source and notes are in the
session scratch folders (`r11_*` … `r17_*`).

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

Every byte of the data range is now owned by a catalogued unit that verifies
byte-exact. 57 small units (514 bytes) stay `placeholder` in
`config/data_matches.csv` because no code or data reads them, so their type is
unknown, and the catalogue does not credit byte identity alone. 48 of them
(406 bytes, at most 16 bytes each) sit directly after a table and look like
its unread tail, for example s16 pairs that continue the pattern of the
previous unit. Each could be credited by folding it into the preceding unit's
source, but only once that unit's real element count is established.
