# Horizontal camera tracking at 001254F0

The complete 520-byte routine tracks the two actors' horizontal positions
against the camera center. It computes excess beyond a 200-unit allowance
for each actor. If their separation exceeds 400 units, it centers between
them; otherwise it adjusts toward the actor with greater excess. It then
clamps the center using the existing bounds helper, copies the target value,
and invokes both eight-step smoothing helpers.

The source retains the native `>= 0.0f` ternary clamps and branch ordering.
An if-statement candidate was not exact. MWCCPS2 3.0.3-020716 with
`-O3 -Op -sdatathreshold 8` reproduces the entire relocated function.

All four helper interfaces were checked against their existing reconstructed
definitions: the float absolute-value routine, the two-float-pointer bounds
helper, and the two signed-integer-argument smoothing routines. The camera
values are declared as the actual scalar floats in `.bss`; this retains their
native absolute accesses and removes opaque byte-array casts. Their native
aliases already exist in the code map and are unchanged. No data credit is
added for these BSS declarations.

The routine was independently compiled in scratch and at its production
source path. The source uses ordinary comparisons, arithmetic and calls;
there is no assembly, padding or fabricated helper interface.

All 13,758 earlier source/object pairs and all 37 headers are unchanged.
Build coverage includes 4,126 credited source units. Fresh split, full linkage,
packed ELF identity, catalog validation and all 91 tests pass. SHA-256 values
remain `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`
for the loaded image and
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`
for the packed ELF. Code is 2,035,156 / 3,293,696 bytes (61.7894%);
data remains 196,082 / 648,064 bytes (30.2566%).
