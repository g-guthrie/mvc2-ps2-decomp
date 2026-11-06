# Name-entry DATA ownership

The fifty pointers rooted in the initialized tables at00446AB0 and00446B70
lead to individual NUL-terminated strings in[004B5448,004B55D8). Native
consumers pass each pointer as the first%s argument. The eight-byte spacing
locates each string but does not prove ownership of its post-NUL fill.
The complete strings total107 bytes;293 post-NUL bytes and the following
eight-byte gap remain raw placeholders. The existing16-byte00446B70 table
keeps its earlier credit, with symbolic pointers rebased to the four new
string objects. No credit is added for the other pointer table.

Root compiled all103 newly created or changed DATA objects, including raw
fragments, with the production MWCC3.0.3 O3/G0 recipe and checked every whole
section and relocation against retail. This caught and corrected a worker
proposal that incorrectly zero-filled the final16-byte raw fragment; that
correction added no credit. The immutable107-byte proposal and its51-owner
verification supplement remain private evidence. Root's broader checks cover
the raw fragments needed for complete-image linkage too.

## Overlapping triplet ranges

The former60-byte palette array had an incorrect ownership comment. Native
00173650 scans20 signed three-byte comparisons rooted at004B55E0. Its
index<16 delay-slot flag routes the first16 matches to00173590; only
indices16..19 call00173600. That callee uses base004B55F0 plus3*index,
so its actual reads occupy[004B5620,004B562C), not the first16 triplets.
Both root and an independent native audit pinned the complete130 instruction
words to retail and confirmed this branch routing.

The corrected owners are60 comparison bytes and12 replacement bytes. The
four bytes[004B561C,004B5620) have no proven read and remain raw. This
removes4 falsely credited bytes, adds16 newly recovered comparison bytes,
and preserves56 valid old bytes: net+12 reconstructed bytes. All three
whole DATA objects reproduce retail exactly. No CODE credit is added for the
unmatched consumers. No original source-level table boundary or broader
callback/API type closure is inferred from the layout.

The root aggregate gate independently verifies all changed compilation units,
118 tests, catalog/coverage, fresh split, and complete retail loaded-ROM and
packed-ELF identity. Frozen audit:14,828 unchanged source/object pairs, four
rebuilt existing units, two retired owners,109 new pairs, and47 unchanged
headers. Linked matching CODE is2,079,880 /3,293,696 bytes (63.1473%);
linked reconstructed DATA is256,488 /648,064 bytes (39.5776%). The fixed
next CODE publication threshold remains2,080,510, with630 bytes remaining.
