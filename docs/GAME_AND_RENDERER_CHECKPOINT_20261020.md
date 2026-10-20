# Game state and renderer checkpoint

Eight additional complete functions contribute 2,220 verified code bytes: six game-state/movement/partner routines (2,020 bytes), descriptor semaphore initialization (92 bytes) and descriptor lookup (108 bytes). Each final production source was independently compiled and checked against its whole relocated retail span. The six game routines use MWCCPS2 3.0.3 O4,p/G8; the two Sony routines use EE GCC 2.9 O2/G0 with SNAS G0. All seven code objects contain no allocated non-code sections. Detailed source/native evidence is in `GAME_STATE_RECOVERY_20261020.md` and the individual recovery receipts.

Bounded data recovery adds 412 bytes: 280 bytes of renderer coordinate rows, a 128-byte index map consumed by a verified 4×8 loop, and the consumed four-byte kernel-hook pointer. All 17 affected data objects, including retained raw gaps, compile and verify exactly. Neighboring data and unread handler cells remain uncredited.

A fresh split succeeded. Both the 3,941,760-byte hybrid ROM and 3,942,320-byte reconstructed retail ELF match the original images byte for byte. All 86 tests pass; coverage finds 4,060 credited sources with verification and no unregistered bodies. Compared with the prior proof cache, all unrelated objects and all headers are unchanged. The only modified previous data source is the reviewed shortened raw gap at 0x00460DC1; three obsolete raw owners were replaced by typed objects.

Verified linked code is 2,004,788/3,293,696 bytes (60.8674%); reconstructed data is 186,770/648,064 bytes (28.8197%). The fixed next push milestone remains 2,014,636 code bytes, leaving 9,848 bytes. This checkpoint is local; public main was last confirmed at `e240ba423bcf3eaded1632e1c826530dcd3bb597`.

The remaining nearby candidates are held without credit. The 0x00220D50 source needs its native early-exit and real mask-helper contract but still differs in complete code generation. The 0x002C9930 conditional float expressions remain short of the native span; no redundant instructions or assembly were inserted to fill that gap.
