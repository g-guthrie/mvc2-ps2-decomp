# Motion pair recovery

Two complete motion routines add 684 exact C code bytes with MWCCPS2 3.0.3,
using `-O4 -Op -sdatathreshold 8`:

| Entry | Bytes | Source |
| --- | ---: | --- |
| 0024F000 | 392 | `motion_shift_0024f000.c` |
| 0024EDA0 | 292 | `motion_recoil_0024eda0.c` |

The old sketches built float constants through integer temporaries and
pointer casts. The reconstructed sources instead use single-precision
literals that round to those same constant bits. Conditional expressions
select the signed values. This removes the temporary stack slot and
reproduces the native constant materialization.

0024F000 uses the ordinary C truth test on its converted signed control
byte. This emits the native floating-point comparison operand order; an
explicit inequality in the tested compiler emitted reversed operands.
Its counter access reuses the established manager view at offset 0x7C.

0024EDA0 expresses the velocity-plus-acceleration update directly through
its two actor fields, preserving the native loads and addition order. Its
zero stores also use float assignments. Both animation helper interfaces
agree with their existing definitions, including explicit signed-byte
narrowing of the integer animation result where native narrows it.

Every relocated byte in both complete functions verifies exactly. The
13,722 preceding source/object pairs and all 37 shared headers remain
unchanged. No new data bounds or data ownership are credited.

Production coverage, catalog validation and all 89 tests pass. The full
loaded ROM remains exactly 3,941,760 bytes with SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed ELF remains exactly 3,942,320 bytes with SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Raw fallback regions remain uncredited.
