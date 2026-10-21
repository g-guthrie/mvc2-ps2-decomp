# Geometry command and render data

The placeholder at `004B48F0` is replaced with complete counted commands,
geometry records, render records and explicitly uncredited gaps. The physical
layout is supported independently of which commands the current game state
can select.

| Owner | Reconstructed bytes | Evidence |
| --- | ---: | --- |
| Sixteen distinct counted commands | 124 | Native count byte, origin-adjustment byte and exactly count vertex IDs |
| Seventeen command pointers at `00446410` | 68 | Symbolic pointers to those commands, preserving the duplicated target |
| Seventy-two geometry records at `004B49A0` | 1,440 | Native 20-byte stride; all four bytes, three floats and final word read |
| Fifty-seven render records at `004B4F40` | 912 | Native 16-byte stride; packed bytes and three floats read |

The geometry array ends at the independently referenced render base
`004B4F40`. Command ID 71 reaches the final record. Four records are not used
by the current command union but remain members of the contiguous physical
array. Render selector 56 reaches the final render record; `004B52D0` is the
next independently referenced base.

Fifteen command objects occupy 121 bytes within the old placeholder. Their 55
inter-list bytes remain raw, including the two bytes after command `004B4960`.
The final 32 bytes at `004B52D0` remain a raw prefix of the next table. The
external command at `004B48E8` contributes three bytes; its following five
bytes remain outside the recovered owner. Duplicate pointer references are
counted once as storage.

These recoveries add 2,544 reconstructed DATA bytes. They do not establish
global runtime safety. The unchecked command selector requires a table index
in `0..16`; the observed caller's `13 + signed B5` requires B5 in `-13..3`.
A state-triggered reset clears B5, but an all-time zero invariant is unproven.
Geometry IDs must be below 72 and render selectors below 57. The concrete
command streams satisfy the geometry bound; mutable renderer producers are
not globally closed by this audit. No guards were added to retail behavior.

All 33 geometry-related objects passed the production compiler recipe and
whole-object retail verification after preserving the original DATA section
for the command objects. Independent review confirmed the field layouts,
exact partition and duplicate-pointer handling. Together with the separate
four-byte animation lookup, 34 changed or new DATA objects were verified.
The remaining 14,948 source/object pairs and all 50 prior headers kept their
recorded hashes. Full linkage and packed retail ELF identity also passed.
