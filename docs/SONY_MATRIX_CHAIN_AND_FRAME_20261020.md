# Sony matrix helper chain and frame builder

Two C routines add 256 matching bytes with Sony EE GCC 2.9-991111
`-O2 -G0 -ffunction-sections` and the existing SN assembler:

| Function | Bytes | Native operations |
| --- | ---: | --- |
| 00103230 | 80 | Chain three matrix helpers using scalar components 2, 1 and 0; retain the final tail call |
| 001032A8 | 176 | Initialize a matrix, build and normalize vector rows, apply an offset, and transform the result into the destination |

The frame builder's 80-byte work area contains the native 64-byte matrix
and the 16-byte temporary vector at +0x40. Every region is used by the observed
helper calls; no unused padding is introduced. Four input pointers follow
the native A0–A3 interface. The first routine preserves the two pointer inputs
and scalar arguments passed through F12 to its existing helpers.

Five existing callee names are exposed in the code address map at their
configured native entry points so the production verifier can resolve calls.
These aliases add no matching bytes. Several callees remain uncredited raw
placeholders: this recovery credits only the two reconstructed C callers.
No assembly, compiler output or object bytes are rewritten.

Both scratch candidates were independently recompiled and verified from the
production sources. All 13,741 prior source/object pairs and 37 shared headers
remain unchanged from checkpoint `e5795eec`.

A fresh split, production coverage (4,119 sources), catalog validation and
all 91 tests pass. The complete loaded image and packed ELF remain byte-exact
with SHA-256 values respectively
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f` and
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Code credit is 2,032,888 / 3,293,696 bytes (61.7206%);
data remains 195,314 / 648,064 bytes (30.1381%).
