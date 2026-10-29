# What is left

Snapshot after matching rounds 11–17. Code is 3,291,484 of 3,293,696 bytes
(99.93%) and data is 647,546 of 648,064 bytes (99.92%). The spans below are code that no credited C or
`.S` source covers yet: 2,212 bytes. Each one has a blocker class.
For classes (a), (c) and (d), the best near-miss source and notes are in the
session scratch folders (`r11_*` … `r17_*`).

## Needs a compiler build that does not exist publicly (class a)

| Span | Bytes | Evidence |
|---|---:|---|
| func_001E7CB0 | 612 | Floats allocated before scheduling. The register picture matches `#pragma schedule off`, yet loads are still hoisted. |
| func_003F5630, func_003F5710 | 712 | Retail needs `*s++` to reach IRO as a post-increment whose value is used: each unrolled copy then gets its own temp, while `d++` folds into store offsets 0..7. The PS2 MW front end pulls every post-increment out of an expression statement before IRO (MW 3.0 IRO phase dumps, round 18), so `*d++ = *s++` can never produce it. It survives only in a condition or call argument: `if ((*d = *s++) != 0) { } d++;` is byte-exact on 3.0 and 3.0.3, but an empty `if` used to steer is not credited. The MH1 decomp's flMemcpy/plMemmove stop at the same wall. |

## Structural, not solved (class d)

| Span | Bytes | Evidence |
|---|---:|---|
| func_003D6530 | 740 | One word: retail moves `lui s0,%hi(D_004B91E0)` from the fall-through into the `beqz` slot at +0x21C; the best source (3.0.3, `-O3 -Op`, `opt_propagation off`) emits a `nop` there. The beqz targets the outer join, whose first instruction is a relocated `lui` and has three predecessors; the MW filler then emits `nop` without trying the fall-through, unless the target block is empty (gdb trace of the filler, round 18). An empty inner-join block needs a statement that survives to the backend and emits nothing: `assign_labels` merges adjacent labels and `COpt_Optimize` drops no-op statements, so only a kept dead assignment (`opt_dead_assignments off`) or an allocator-removed copy does it, and nothing after the join reads a variable. Same-TU sibling func_003D44E0 shows the `nop`, as the rule predicts. |

## Data placeholders

Every byte of the data range is now owned by a catalogued unit that verifies
byte-exact. 57 small units (514 bytes) stay `placeholder` in
`config/data_matches.csv` because no code or data reads them, so their type is
unknown, and the catalogue does not credit byte identity alone. 48 of them
(406 bytes, at most 16 bytes each) sit directly after a table and look like
its unread tail, for example s16 pairs that continue the pattern of the
previous unit. Each could be credited by folding it into the preceding unit's
source, but only once that unit's real element count is established.
