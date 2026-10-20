# Uncredited runtime-handle update

`runtime_handle_update_004044E0.c` reconstructs the native state transition and both decoding calls at 0x004044E0. It describes the same 0x3C-byte record whose accessed fields are reconstructed in the data catalog. State one advances to two; state two dispatches by mode, records the result, optionally requests the global update, and advances to three. The integer-returning update helper agrees with the verified definition in `src/gp_leaf_batch2.c`.

The source is **not matching and receives no progress credit**. EE GCC 2.96 `-O2 -G0 -ffunction-sections`, followed by SNAS `-G0`, produces exactly 244 bytes and agrees with 60 of the 61 instruction words after relocation. At function offset +0xC8, the compiler emits a branch-likely conditional while retail uses the corresponding ordinary branch. No object or generated assembly was patched.

Equivalent goto/early-exit C forms, the O3 profile, and the corrected update-helper return declaration leave that difference unchanged. This compiler rejects `-fno-guess-branch-probability`; that flag is not a working recipe. The candidate stays outside `src/`, the production build and `config/matches.csv` so the remaining difference cannot be mistaken for an exact function.

A separate verifier ledger must use address 0x004044E0 and size 0xF4. Helper addresses observed directly in the retail calls are `func_003FA728 = 0x003FA728`, `func_003FB040 = 0x003FB040` and `func_004044D0 = 0x004044D0`. The decoder argument widths/pointers reflect the actual register and stack transfers; they are reconstruction views rather than a claim to possess the original library headers.
