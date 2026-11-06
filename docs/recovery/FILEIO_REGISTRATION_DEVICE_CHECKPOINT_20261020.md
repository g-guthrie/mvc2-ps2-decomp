# File-service registration and device-control checkpoint

Linked matching code is 2,015,856 / 3,293,696 bytes (61.2035%),
covering 17,329 / 20,300 functions. Reconstructed linked data remains
195,314 / 648,064 bytes (30.1381%). This local checkpoint adds
three complete functions / 764 code bytes over published `e1553fec`.

The new source recovers completion-hook replacement, descriptor reservation
and device control. All complete objects were independently compiled with
literal Sony EE GCC 2.9 O2/G0 and SN AS G0 recipes. There are no affected
old providers or headers. All previously verified source/object/header hashes
remain unchanged. A proposed placeholder upgrade relying on false helper
ABIs was rejected and receives no credit; `func_0040A378` remains placeholder.

Both full images reproduce retail exactly: ROM 3,941,760 bytes / SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`;
ELF 3,942,320 bytes / SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
All 88 tests, catalog validation, shell syntax and production coverage of
4,084 credited source units pass.

The next scheduled publication threshold remains 2,047,573 code bytes,
another 31,717 verified code bytes away. This checkpoint is local;
full decompilation remains incomplete.
