# Owner tag guard at 003562D0

All 84 bytes of `func_003562D0` are reconstructed in C. The function leaves
mode-6 actors with a nonzero byte at offset 5 alone. Otherwise, when the
owner's unsigned halfword tag at 0x168 differs from the actor's signed
halfword at 0x1C, it raises state values below 2 to 2 and clears byte 0x13C.
The halfword signedness and conditional reset order follow the native loads
and branches. The existing caller in `grok_w5_0034.c` passes the actor pointer.

The exact profile is MWCCPS2 2.4-001213, `-O4,p -sdatathreshold 8`.
The identical C under 3.0-011126, 3.0.1-020123 and 3.0.3-020716 emits 80
bytes by filling the final conditional branch delay slot. The 2.4 compiler
naturally emits the native empty slot, without source padding or assembly.
This establishes a working profile for this body, not a compiler attribution
for the surrounding address range.

The canonical source was independently recompiled and all 21 words verified.
The full loaded image remains exactly 3,941,760 bytes, SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed retail ELF remains exactly 3,942,320 bytes, SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
This adds 84 code bytes and no data credit; raw image regions remain
undecompiled.
