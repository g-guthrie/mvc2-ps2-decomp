# Camera sequence1 parallel channels

Recover the 192-byte parallel channel array at 0x0043C450 as 48 floats.
The mode1 duration header at 0x0043C370 begins with signed bound7.
The exact updater func_001234D0 reads six floats per key with 24-byte
stride; its initialized key index reaches0..7. D_0043CB50[1] selects
this array; mode4 shares its initial keys through D_0043CB50[4].
All48 channel values are zero, but ownership follows native typed reads
and the key bound, rather than the length of a zero-filled region.
The next table starts at0x0043C510, exactly after eight six-float keys.

The mixed header/key object at0x0043C370 stays unchanged and uncredited.
Its terminal duration lookup can alias the first key word, so splitting
it into a short integer header and separate float array would introduce
an invalid C object boundary. This recovery claims only the independent
parallel channel array.

MWCCPS2 3.0.3 -O3 -sdatathreshold0 reproduces the whole array and both
pointer relocations in the unchanged20-byte selector table. The combined hybrid and packed ELF match retail byte for byte; all 95 tests pass.
This adds no code credit.
