# What is left

Snapshot after matching rounds 11–17. Code is 3,291,484 of 3,293,696 bytes
(99.93%) and data is 647,988 of 648,064 bytes (99.99%). The spans below are code that no credited C or
`.S` source covers yet: 2,212 bytes. Each one has a blocker class.
For classes (a), (c) and (d), the best near-miss source and notes are in the
session scratch folders (`r11_*` … `r17_*`).

## Needs a compiler build that does not exist publicly (class a)

| Span | Bytes | Evidence |
|---|---:|---|
| func_001E7CB0 | 612 | 10 of 153 words, all in block 0's integer part (+0x34..+0x74); everything after is exact (MW 3.0.3 `-O3 -Op`, round 18 near miss). A gdb harness that feeds block 0 a chosen pcode order with the pre-RA schedule skipped gives a byte-exact function, but only if the `p->f50`/`x->f50` loads come after `lh a->v[0]`. The real pre-RA scheduler runs in register-pressure mode (always on: class 2/6 limits are 0) and puts those loads in the idle load slots first, whatever the IR order (best reachable 11 words). Retail's block-0 IR therefore carried a dependence that no tried source shape, volatile, pragma or any of 24 MW builds reproduces. |
| func_003F5630, func_003F5710 | 712 | Retail needs `*s++` to reach IRO as a post-increment whose value is used: each unrolled copy then gets its own temp, while `d++` folds into store offsets 0..7. The PS2 MW front end pulls every post-increment out of an expression statement before IRO (MW 3.0 IRO phase dumps, round 18), so `*d++ = *s++` can never produce it. It survives only in a condition or call argument: `if ((*d = *s++) != 0) { } d++;` is byte-exact on 3.0 and 3.0.3, but an empty `if` used to steer is not credited. The MH1 decomp's flMemcpy/plMemmove stop at the same wall. |

## Structural, not solved (class d)

| Span | Bytes | Evidence |
|---|---:|---|
| func_003D6530 | 740 | One word: retail moves `lui s0,%hi(D_004B91E0)` from the fall-through into the `beqz` slot at +0x21C; the best source (3.0.3, `-O3 -Op`, `opt_propagation off`) emits a `nop` there. The beqz targets the outer join, whose first instruction is a relocated `lui` and has three predecessors; the MW filler then emits `nop` without trying the fall-through, unless the target block is empty (gdb trace of the filler, round 18). An empty inner-join block needs a statement that survives to the backend and emits nothing: `assign_labels` merges adjacent labels and `COpt_Optimize` drops no-op statements, so only a kept dead assignment (`opt_dead_assignments off`) or an allocator-removed copy does it, and nothing after the join reads a variable. Same-TU sibling func_003D44E0 shows the `nop`, as the rule predicts. |

## Data placeholders

Every byte of the data range is owned by a catalogued unit that verifies
byte-exact. Seven small units (76 bytes) stay `placeholder` in
`config/data_matches.csv`, because no code or data reads them, so their type
and owner are unproven, and the catalogue does not credit byte identity alone:

| Unit | Why it is unproven |
|---|---|
| data_u32_00446BD0, data_ff_00446BE0 | No reader and no pointer to them. |
| data_u32_00445758 | Follows the fade curve, which func_00160F90 reads only while its index is below 22. |
| data_u32_00451230 | Follows input descriptor D_00451220; how far its state callbacks read it is not traced. |
| data_u32_0045ECCC | func_0033B9D0 reads D_0045ECBC+12*i at +0 only (i = 0..1), so this word is never read. |
| data_u32_00464EE0 | Floats before gIdentity3x3_00464EEC; no reader or pointer. |
| data_raw_004B57F0 | No reader. |
