# Game and RPC registration checkpoint

Linked matching code is 2,016,820 / 3,293,696 bytes (61.2327%),
covering 17,333 / 20,300 functions. Linked reconstructed data is unchanged at
195,314 / 648,064 bytes (30.1381%). This local checkpoint adds
four complete functions / 964 code bytes over `80e71de9`.

The new functions are a 368-byte game mode/command update, 148-/208-byte RPC
queue/server registration routines, and a 240-byte guarded path command.
Every new production object was independently compiled and relocated against
its complete native function. The real three-argument RPC callback ABI and
actual queue/server objects replace incomplete declarations and padding
arrays in the existing caller. All thirteen functions / 2,240 bytes in that
header/callback closure remain exact under their literal compiler profiles.

Both full images match immutable retail byte for byte: ROM 3,941,760 bytes,
SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`;
ELF 3,942,320 bytes,
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 88 tests, catalog validation, shell syntax and production coverage of
4,087 credited sources pass. The three changed existing CUs were replayed;
all other cached source/object hashes and all prior headers are unchanged.
No initialized-data, readonly or BSS credit is added.

A related mode-table candidate is held privately despite matching 90 of 92
instruction words. Its remaining branch-delay move ordering still differs;
no padding, barrier or assembly patch is used to force it into the catalog.
The next scheduled push remains at 2,047,573 code bytes, another
30,753 verified bytes away. Full decompilation remains incomplete.
