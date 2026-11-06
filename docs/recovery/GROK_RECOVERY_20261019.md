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

## Build bootstrap and validation

A fresh split initially failed because repeated declarations and intentional
address aliases lacked Splat metadata. Consolidating 203 duplicate declarations
and annotating 131 aliases preserves all 18,917 distinct symbol/address bindings
and every existing Splat attribute. The object verifier resolves exactly the
same address dictionary before and after this cleanup. A fresh `make split`
now completes across the entire configured image and generates the BSS assembly.

All 3,946 production code source groups have passed the relocated-object
verifier in this run, including existing uncredited placeholder units. The
remaining compile recipes ran in parallel with their original compiler flags;
objects already compiled and verified earlier in the same run were reused and
verified again. Placeholder code retains zero matching credit.

All 8,304 compiled data sections passed verification. The final hybrid link
places the recovered functions and reproduces the complete 3,941,760-byte
loaded image (SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`).
The deterministic packer also reproduces the complete 3,942,320-byte retail
ELF (SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`).
These image checks include the project's uncredited raw regions; they do not
imply that those regions have been decompiled.

This checkpoint links 1,952,480 /3,293,696 code bytes (59.2793%) and
177,895 /648,064 reconstructed data bytes (27.4502%).
