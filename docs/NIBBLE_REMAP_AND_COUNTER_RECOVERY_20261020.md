# Nibble remapping and replacement-counter recovery

This checkpoint reconstructs two complete functions, adding 656 code bytes
and no data credit.

| Function | Bytes | Compiler recipe |
| --- | ---: | --- |
| 003EB4A0 | 296 | MWCCPS2 3.0.3-020716, `-O4,p -sdatathreshold 8` |
| 00191600 | 360 | MWCCPS2 3.0.3-020716, `-O3 -sdatathreshold 8` |

The nibble remapper consumes the existing four-entry pointer list at
`D_00478940`. Each entry supplies 128 mapping words, used as two rows of
32 output bytes with two source-nibble lookups per byte. The source advances
by 0x100 per block, while each destination row advances by `pitch << 8`.
Both mapping arrays contain 128 values ranging from zero to 415, so their
source-byte indices are within each 0x100-byte block. Those arrays and the
pointer list were already reconstructed; this adds no data ownership or
new array-bound claim. Its declaration agrees with the existing unsigned
32-bit mapping data and const pointer entries. The final signed-byte
conversions and the row/pixel/block local order reproduce the native byte
extensions and register allocation without assembly or artificial operations.

The counter replacement routine shares `src/w184_i.c` with the already
credited accumulation routine at 00191480. Their three actor-counter
assignments differ: 00191600 replaces each value from the supplied delta,
whereas 00191480 adds the delta to the previous value. Both still accumulate
the two existing global counters. Signed-halfword narrowing occurs before
the upper-bound comparison against 999; the source retains that order,
including the native initial-history and maximum-counter updates. The
existing translation-unit recipe is unchanged, and both functions were
independently recompiled and verified together (384 existing bytes plus
360 new bytes).

The canonical remapper was independently recompiled and all 74 words
verified after relocation; the new counter routine verifies all 90 words.
Both bodies have production compilation and verification coverage. No
padding, compiler barrier, volatile access, assembly or fabricated helper
is used.

The complete loaded ROM remains exactly 3,941,760 bytes, SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed retail ELF remains exactly 3,942,320 bytes, SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Unreconstructed raw regions remain uncredited.
