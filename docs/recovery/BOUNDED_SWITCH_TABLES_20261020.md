# Bounded native switch tables

Two previously uncredited integer-address arrays are now typed, symbolic
code-location tables. Their destinations are interior blocks, represented as
addresses of code bytes and registered `lbl_` aliases; they are not declared
as independent C functions. The parent routines remain uncredited.

| Table | Entries / bytes | Native bounded consumer |
| --- | --- | --- |
| 004AB000 | 73 / 292 | 001058B8–001058E8 in 00105858 |
| 004B38F0 | 87 / 348 | 00151D50–00151D7C in 00151A90 |

The first consumer reads an unsigned byte, subtracts ASCII `0`, sign-extends
that byte delta, and rejects its unsigned value when it is at least `0x49`.
Only indexes 0–72 reach the four-byte-scaled load and indirect jump. All
11 distinct destinations are aligned instruction locations inside
`[00105858,00105E44)`.

The second consumer masks the selector to a byte, subtracts 5, and rejects
unsigned results at least `0x57`. Only indexes 0–86 reach its scaled load and
indirect jump. Its three distinct destinations are inside
`[00151A90,001520D8)`.

All 160 entries were checked against the native image, including every label's
owner, offset, and occurrence count. Both final typed sources independently
compile and relocate to the exact 292-byte and 348-byte spans with the
existing MWCCPS2 3.0.3 O3/G0 data recipe. The 12-byte and four-byte gaps after
the tables remain uncredited. This adds 640 reconstructed data bytes.

Final validation: all 806 functions in the six changed/new code units and both
data objects pass complete compiled-object verification. A fresh split, full
hybrid relink, and deterministic ELF pack succeed. The 3,941,760-byte loaded
image has SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`;
the 3,942,320-byte ELF has SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 91 tests pass. All 14,043 other cached source/object pairs and all 45
previous headers were checked unchanged.
