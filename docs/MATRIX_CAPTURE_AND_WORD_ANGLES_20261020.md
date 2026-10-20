# Matrix capture and word-angle interfaces

The complete routine at 001431A0 adds 452 exact C code bytes in
`src/render_matrix_001431a0.c`, compiled with MWCCPS2 3.0.3 using
`-O4 -Op -sdatathreshold 8`.

Its native stack contains three real 16-float matrices: the current-matrix
capture, a copy retained for the draw helper, and a separately generated
translation/rotation matrix or identity. The old sketch reused the capture
buffer for the generated transform. The recovered code preserves the three
buffers and the selected asset-table entry as a pointer. The draw helper
actually dereferences that pointer; it is not an integer selector.

The vector interfaces agree with the existing runtime transform helpers.
The matrix-stack push/pop declarations describe their integer results,
and the capture helper's pointer result is represented explicitly, even
though this caller ignores those results.

The native caller reads full words from actor offsets 0x44 and 0x48. The
rotation helpers at 004172E0, 00417270 and 00417350 mask their inputs to the
low 16 bits. Their C definitions now accept word arguments and express
that narrowing inside the function. This preserves the native loads at
the caller and the existing mask instructions at each callee. The two
existing caller modules use consistent word-angle declarations, including
the direction helpers at 001227A0 and 001227F0. Existing callers of the
latter already pass a word angle; its old pointer formal was inaccurate.

All 29 previously credited functions in the four affected source units
were independently recompiled with their production recipes and remain
byte-exact. The new 452-byte routine also passes whole-span relocated-byte
verification. A private negative control restored the narrow caller
prototypes: the verifier rejected precisely the two LHU instructions that
then replaced native LW loads. No verifier rule was changed.

Three aliases identify existing helper entries at 00417170, 00417200 and
00417FC0. They add no matching bytes or data ownership. The other 13,725
pinned source/object pairs and all 37 shared headers remain unchanged.
No assembly, barriers, fake helper effects or padding were introduced.

A fresh executable split, production coverage, catalog validation and the
existing test suite pass. The loaded ROM remains 3,941,760 bytes, SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed ELF remains 3,942,320 bytes, SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Raw fallback regions remain uncredited.
