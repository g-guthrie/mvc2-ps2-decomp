# Paired record copy at 003DAE10

All 124 bytes of `func_003DAE10` match with MWCCPS2 3.0.3-020716,
`-O4 -Op -sdatathreshold 8`. The routine copies eleven pairs of signed
halfwords to a record with a 44-byte stride, then tail-calls the existing
`func_003ED8E0(int, short, short, short)` provider with attributes at record
offsets 0x24, 0x26 and 0x28. Its signed loads, paired load-before-store
ordering and local pointer advance retain the native behavior and register
lifetimes. There are no artificial operations, barriers or assembly.

Root independently compiled the canonical source and compared all 31 words
after relocation. Four address aliases identify native BSS field views;
the fifth declaration identifies the already credited tail-call provider.
They assert no new initialized-data bounds or credit. A fresh full split
and production build coverage pass.

The full loaded image is still exactly 3,941,760 bytes, SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed retail ELF is still exactly 3,942,320 bytes, SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
This adds 124 code bytes and no data credit. Unreconstructed regions remain
uncredited.
