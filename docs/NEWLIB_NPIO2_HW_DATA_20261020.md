# Newlib float reduction high-word constants

Recover `data_s32_004ABF18`, a 32-element signed-word table of truncated IEEE-754 encodings of multiples of pi/2. Its 128 bytes occupy `[0x004ABF18, 0x004ABF98)` without overlapping another owner or extending into the following unowned range.

The existing matching rem_pio2f source defines these 32 words as `npio2_hw`. Its cached, exact code object emits the array with symbol size 128, immediately after the 792-byte 2/pi digit table. Every initializer word, compiled source-table byte, and retail word agrees. A standalone data compilation independently matches the same span.

Native code guards `n < 32` and uses an adjusted base at `D_004ABF14` with scaled n, corresponding to `npio2_hw[n-1]`. On this path n is positive, so the guarded lookup selects entries 0..30. Entry 31 belongs to the proven 32-word source object; the guard alone is not used to infer its extent. The adjusted base is the final word of the preceding table and is not a new array alias.

The standalone recipe is MWCCPS2 3.0.3, -O3 -sdatathreshold 0. No code credit is added. The packet's separate nonmatching owner probe is not used as evidence of code matching. Catalog placement, all tests, loaded-image identity and packed retail ELF identity are checked before linked credit is promoted.
