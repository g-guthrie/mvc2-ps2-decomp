# Scene scale-motion initializer at 00145B10

The complete 444-byte initializer is now reconstructed in
`scene_scale_motion_init_00145b10.c`. It initializes the actor's phase and
motion values, derives its interpolation steps from the signed frame field,
advances its state, and invokes the existing 00145CD0 callback.

MWCCPS2 3.0-011126 with `-O4,p -sdatathreshold 8` reproduces the entire native
function. The float divisor remains inline in the first interpolation
expression; the later double divisions retain actual `litodp` helper calls.
These are calls to the reconstructed signed integer-to-double implementation
at 00119B08 with its real double-return interface. No helper prototype or
clobber is fabricated, and no optimization pragma is needed.

The 0.7 numerator is a double literal: retail encodes
0x3FE6666666666666. The earlier candidate's float-rounded value differs.
The two scalar data aliases are bound to their catalogued `.data` objects,
matching native absolute loads. The first scalar at 004B3428 is zero in the
complete three-float source table; native references only load it. Its phase
conversion is signed before unsigned low-bit wrapping and calls the real
signed conversion helper. The scalar at 004B343C is 720.0f.

The initializer keeps the existing callback's compatible context and actor
prefix views. Character access to the frame field preserves the memory view
used by the target while retaining the callback's actual pointer interface.
The callback source itself and all existing data objects are unchanged.
Three existing native addresses are exposed in the code symbol map; they add
no data ownership or additional function credit.

All 13,757 earlier source/object pairs and 37 shared headers remain unchanged.
Production build coverage includes 4,125 credited source units. A fresh split,
full loaded-image linkage, packed ELF identity, catalog validation and all
91 tests pass. Image SHA-256 values remain
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f` and
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Code is 2,034,636 / 3,293,696 bytes (61.7736%); data remains 30.2566%.
