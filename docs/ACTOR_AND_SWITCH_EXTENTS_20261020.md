# Actor transitions and bounded switch extents

Two complete game callbacks add 636 code bytes. Both have independently rooted
`void (unsigned char *)` interfaces in the existing typed dispatch tables:
`002B7DA0` at table slot `00459244`, and `002B4710` at `00459014`.

`002B7DA0` advances position/velocity, clamps on the native threshold transition,
and resets or transfers linked-actor state according to animation status.
`002B4710` integrates motion, applies the orientation-dependent displacement on
that transition, publishes the native flags, and dispatches animation helpers.
Both preserve the native `!(threshold <= y)` comparison, including its unordered
floating-point path. Actor back-references are actual pointer stores, and the
existing animation helper's integer return declaration is retained.

The callbacks share `actor_state_transfer_002B7580.c` with the previously
credited 364-byte routine. Its recipe now uses MWCCPS2 3.0.3 O3,p/G0; all three
functions match their whole relocated spans, 1,000 bytes combined.

Five symbolic switch tables add 896 reconstructed data bytes:

| Table | Bounded entries | Bytes | Native bound / owner |
| --- | ---: | ---: | --- |
| 004BA560 | 92 | 368 | unsigned selector <0x5C; 003DFF80 |
| 004BA6D0 | 8 | 32 | unsigned selector <8; 003E0390 |
| 004BA6F0 | 6 | 24 | low nibble <6; 003E06D0 |
| 004AABC0 | 59 | 236 | unsigned selector <0x3B; 00101218 |
| 004AADD0 | 59 | 236 | unsigned selector <0x3B; 001016C0 |

Each guard precedes the scaled load and indirect jump. All 224 entries and
33 distinct targets were independently checked against the native image,
including their instruction alignment, containing function, and occurrence
counts. Destinations use byte-addressed code-location pointers and registered
interior labels; the parent functions gain no C credit from these tables.

The old BA560 catalog stopped after 91 words. Its guarded 92nd word at BA6CC
is part of the table, which ends exactly at BA6D0. BA6F0's last eight previously
cataloged bytes have no guarded reads and remain a separate raw placeholder.
The four-byte gaps after AABC0 and AADD0 are unchanged and uncredited.

All five typed tables and the raw tail independently compile and relocate to
the exact image bytes with the existing MWCCPS2 O3/G0 data recipe.

Validation: the compiled-data verifier rejects a negative control that drops
the 92nd table target. The three complete actor routines, five typed tables,
and raw tail all pass the production object checks; all 14,045 other cached
source/object pairs and all 45 headers remain unchanged. A fresh split and
full relink reproduce the 3,941,760-byte loaded image with SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The 3,942,320-byte packed ELF has SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 91 tests pass.
