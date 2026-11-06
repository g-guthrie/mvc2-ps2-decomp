# Client and callback recovery checkpoint

Verified linked code is 2,008,000 / 3,293,696 bytes (60.9649%), covering
17,307 / 20,300 functions. Verified linked reconstructed data is
193,754 / 648,064 bytes (29.8974%). This checkpoint adds 1,264 code bytes
and 5,144 data bytes over `6bb7000d`.

New complete C functions are the 216-byte recovery-vector initializer,
204-byte animation countdown, 180-byte RPC reply completion, and 344-byte
other-data plus 320-byte RPC bind requests. Root independently compiled
all new functions and their affected caller/header closure. The older
animation-countdown compiler profile is retained explicitly in production.

The data additions are the 4,096-byte bounded event ring, two proven u16
counters (four bytes), five fixed state words (20 bytes), and 1,024 bytes
of validated ADXF partition pointers. Other cleared counter slots remain raw:
physical clearing and adjacency were not accepted as semantic width proof.
The ADXF name comes from native diagnostic strings, not a compiler-band
assumption. Every replacement object was independently compiled and verified.

Both full rebuilt images match immutable retail byte for byte: ROM
3,941,760 bytes / SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`;
ELF 3,942,320 bytes / SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 88 tests, catalog validation, shell syntax and production coverage of
4,073 credited sources pass. Unchanged prior source/object hashes and
prior headers were checked against the compiled proof cache.

An isolated 684-byte ADXT_GetTime candidate adapted from AGPL upstream source
is held outside this checkout and receives no code credit pending license
compatibility review. It is not represented as an independent reconstruction.

`origin/main` was refreshed and remains `e240ba42`. This checkpoint is local;
6,636 additional verified code bytes are needed for the scheduled publication
threshold of 2,014,636 bytes. The full decompilation goal remains incomplete.
