# Grok work recovery, 2026-10-19

Recovered from the original PS2 checkout on `grok/finish-decomp`, tip
`c5694531992a39281025002de6106fdce9648c98`. Its uncommitted patch and candidate
sources were copied to a separate local recovery directory before integration.
Private executables, compiler binaries, and generated objects remain private.

The first replay checked all 17 uncommitted match claims with MWCCPS2 3.0.3,
`-O4,p -sdatathreshold 8`, and the relocated whole-object verifier. Twelve
matched; five did not reproduce retail with that recipe. Of the twelve,
five overlap already credited main sources and one uses a volatile self-copy
solely to influence code generation. Those six receive no new credit.

The six accepted functions contribute 560 bytes:

| Entry | Bytes | Behavior |
| --- | ---: | --- |
| 002DEDA0 | 296 | Motion update and animation/state transition |
| 00246150 | 48 | Conditional state reset and callback dispatch |
| 002464E0 | 48 | Conditional state reset and callback dispatch |
| 00246DE0 | 48 | Conditional state reset and callback dispatch |
| 0034A720 | 68 | Owner-state guard and context callback dispatch |
| 0034DDD0 | 52 | Publish actor/owner views and dispatch |

Inventory promotion preserves every unmatched leading/trailing byte as an
assembly residual. Recovering a dispatcher prefix does not credit the larger
spimdisasm range that originally contained it. Both compilation and verification
are wired into the production build before data compilation.

The five failed local candidates are 00381990, 00386F30, 00388BD0, 0038EC30,
and 0022ADA0. The held volatile candidate is 0022D210. They remain preserved
locally, without additional matching credit.

The committed-source audit recovered another 38 exact functions (8,228 bytes)
from Grok commits `b09008a6` and `c5694531`. Their original compiler profiles
are retained in the production script. Two additional objects already overlap
previously accepted sources and receive no new credit. Entry 00310220 is held
because removing its redundant byte self-copy prevents an exact match.

Together this recovery adds 44 functions and 8,788 bytes of reconstructed C.
Array declarations at 004C1768, 004C2AF0, and 004C2AF8 describe the actual indexed
objects; their small-data placement is explicit. No data credit is added.

Entry 00386F30 was subsequently repaired and independently matched (360 bytes).
The vertical velocity branch now preserves the native ordered comparison,
including NaN behavior, and its animation reset expresses the actual chained
byte/halfword assignment. This raises the accepted recovery to 45 functions
and 9,148 bytes. The original failed source remains in the local recovery copy.

Entry 0022ADA0 was also repaired and matched (384 bytes). Byte wrapping now
occurs at the native animation-ID arithmetic assignments before passing the
full integer argument. The accepted recovery totals 46 functions /9,532 bytes.
