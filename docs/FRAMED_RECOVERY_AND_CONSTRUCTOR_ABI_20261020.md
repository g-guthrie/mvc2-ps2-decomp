# Five complete framed-function recoveries

This checkpoint adds 1,620 exact code bytes and no data credit.

| Entry | Bytes | Source/profile |
| --- | ---: | --- |
| 00146040 | 424 | `y10_b.c`, MWCCPS2 3.0.3, `-O4,p -sdatathreshold 8` |
| 002866F0 | 324 | `interaction_transition_002866f0.c`, MWCCPS2 3.0, `-O4,p -sdatathreshold 8` |
| 001F5470 | 396 | `frame_motion_001f5470.c`, MWCCPS2 3.0.3, `-O4,p -sdatathreshold 8` |
| 002876B0 | 204 | `interaction_mode_002876b0.c`, MWCCPS2 3.0.3, `-O3 -sdatathreshold 8` |
| 00134D30 | 272 | `create_flagged_effect_00134d30.c`, MWCCPS2 3.0, `-O4,p -sdatathreshold 8` |

The preserved Grok source for 00146040 already matched instructions, but its
called helper 001461F0 was incorrectly declared `void` in the existing
reconstruction. The new caller consumes that helper's returned actor pointer,
and the native helper preserves the allocator result in V0 on both paths.
Its definition now returns the pointer explicitly. The new caller and helper
share their existing source file, so restoring the incorrect void definition
causes real compilation errors at the result assignments. A private negative
control confirmed those errors; the verifier was not weakened.

The constructor's three inputs remain 32-bit, with the native low-byte test
expressed explicitly. Its two known caller files now consistently declare
the pointer return and three 32-bit arguments. All eleven pre-existing
functions in `y10_b.c` remain exact under the new profile, and all 23 spans
in the two caller files were independently recompiled and verified. The
helper's 180 existing bytes receive no new credit. The O4 profile emits the
native immediate float stores for -0.1f and -0.12f; O3 emits a different,
shorter implementation for the new constructor.

002866F0 fixes the actual signed control-byte access at 0x1E8, including
its increment. Reading an unsigned byte then applying a value cast had
emitted LBU where native uses LB. Its interaction helper declarations agree
with their existing definitions, with no fabricated register-clobber model.

001F5470 clears byte 0x151 before calling 001266A0, matching the native
JAL delay slot. The old sketch cleared it after the callee returned, which
was a real ordering difference. Animation helper return declarations now
agree with `animation_frames.c`, and the source retains explicit signed-byte
interpretation where the native caller narrows the result. Float literals
reproduce the original single-precision constants without integer bit stores.
Its one-argument action interface agrees with the existing state dispatcher.

00134D30 uses a byte view of the actual 0x5B8-stride record, then reads the
32-bit flags at offset 0x428. This naturally preserves the native base
address plus field-offset instruction instead of folding the field offset
into the relocation base. The source retains proper allocator/callback
interfaces and ordinary float initializations. The record and vector-array
views assert no new array element bounds or data ownership.

002876B0 passes the required mode argument 1 to 00385A20, agreeing with
the existing two-argument helper definition and native A1 value. The old
sketch omitted that argument. The animation helper declaration now agrees
with its definition; signed-byte narrowing remains explicit. Ordinary float
literals reproduce the four native motion constants.

All 39 function spans in the seven affected source units were independently
recompiled and verified. Unchanged source/object pairs and every shared
header were checked against the preceding pinned proof manifest. Nine
address declarations identify existing native functions or data views;
they award no progress themselves. No assembly, padding, volatile access,
compiler barrier or fake helper is introduced.

A fresh executable split passes. The complete loaded ROM remains exactly
3,941,760 bytes, SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed retail ELF remains exactly 3,942,320 bytes, SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Unreconstructed raw regions remain uncredited.
