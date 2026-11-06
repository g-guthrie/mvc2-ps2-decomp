# SDK compatibility token at 0043824C

`func_0010B298` and `func_00107DC8` compare exactly four bytes at
`D_0043824C` with the current and remote SDK revision tokens. The native bytes
are `2550`; the recovered object is a four-byte character array.

Only those four bytes receive reconstructed-data credit. The former 112-byte
placeholder is partitioned into a 68-byte raw prefix, this four-byte token,
and a 40-byte raw tail. The following eight-byte fill remains separate.
The tail begins at `D_00438250`, a separately mutable console state word
written by `func_00104260` and `func_001043A8`'s console path. Its initial
zero byte is not credited as a token terminator.

All three replacement data objects reproduce their entire retail spans using
the production MWCCPS2 3.0.3 profile. The unchanged Sony 2.9 consumer source
unit reproduces all four functions. A fresh split, full hybrid relink, and
packed ELF comparison also pass. This adds four data bytes and no code bytes.
