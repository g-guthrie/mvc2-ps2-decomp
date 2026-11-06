# Clock, execution and countdown checkpoint

Linked matching code is 2,017,572 / 3,293,696 bytes (61.2556%),
covering 17,336 / 20,300 functions. Reconstructed linked data remains
195,314 / 648,064 bytes (30.1381%). This local checkpoint adds
three complete functions / 752 code bytes over `76a837fd`.

The new functions are CD/DVD clock read (248 bytes), kernel argv staging
(280 bytes), and animation-command countdown reset (224 bytes). Each entire
production object was independently recompiled and compared against native
instructions after relocation. The two existing execution wrappers now use
their true argv pointer interfaces. All fourteen functions / 1,148 bytes in
that helper/caller closure remain exact.

Five existing semaphore syscall rows move to an original licensed PS2SDK
architecture provider, preserving their exact 80-byte credit total. The old
parameterless void C definitions are removed. All 156 remaining legacy
functions / 2,496 bytes still match. This is zero additional code credit;
other legacy architecture stubs remain explicitly unaudited. A regression
check and in-memory negative controls protect ownership and integer results.

Both complete images match retail: ROM 3,941,760 bytes / SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`;
ELF 3,942,320 bytes / SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 89 tests (60 tool tests and 29 tests under tests/), catalog validation,
shell syntax and production coverage for 4,091 source units pass. The five
changed existing CUs were independently replayed; all other cached source,
object and previous-header hashes are unchanged. No data credit is added.

This checkpoint is local. The next scheduled push remains at 2,047,573 code
bytes, another 30,001 verified bytes away. Full decompilation remains
incomplete; near matches and held compiler-option probes receive no credit.
