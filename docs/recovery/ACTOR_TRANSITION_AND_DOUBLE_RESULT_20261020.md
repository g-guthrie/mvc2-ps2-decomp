# Actor transition and double-result interfaces

The actor transition at 0017DFB0 adds 288 exact C code bytes. It selects a
28-byte record from the owner table at offset 0x184, updates actor state,
clamps the vertical position, and selects animation 13. The selected record
address is calculated in the target's 32-bit address representation and
stored as a pointer. This preserves the native arithmetic and register
allocation without asserting table bounds or adding data credit.

The animation helper's int return agrees with its existing definition.
Ordinary single-precision literals replace the old sketch's raw bit stores
for acceleration, angle and scale. MWCCPS2 3.0.3 with
`-O4 -Op -sdatathreshold 8` reproduces all 288 relocated bytes.

The existing floating-point conversion chain also had two incorrect void
interfaces. 00119058 now returns the double produced by 00119C60, which
returns the double produced by the already reconstructed packer 00119118.
The intermediate fraction is explicitly unsigned 64-bit, consistent with
the packer's fraction representation and the widening caller. This fixes
source-level interfaces; it awards no additional matching bytes. EE GCC
2.96 O2 with small-data threshold zero reproduces all sixteen existing
functions across `p2.c` and `s3.c` after the corrections.

All seventeen affected function spans were independently compiled and
verified with the production compiler recipes. The other 13,718 pinned
source/object pairs and all 37 shared headers remain unchanged. Build
coverage and catalog validation pass. Both reconstructed images remain
exactly identical to retail:

- Loaded ROM: 3,941,760 bytes, SHA-256
  `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
- Packed ELF: 3,942,320 bytes, SHA-256
  `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.

Raw fallback regions remain uncredited; image identity is not a claim of
complete source reconstruction.
