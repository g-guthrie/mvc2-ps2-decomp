# `func_003F3700` source recovery receipt

The standalone `src/file_record_uniformity_003F3700.c` recovers the native 112-byte file-record comparison helper at `0x003F3700`. It reads the record count from tag `0x100`, obtains index 0 from tag `0x400`, then returns 1 on the first later value that differs from index 0; otherwise it returns 0.

The source includes truthful static copies of the shared file-header lookup and the `0x100`/`0x400` accessors so MWCC can model the actual callee clobbers when compiling the caller. These copies are auxiliary codegen only and receive no matching credit. The current global helper owners remain `src/w2_f.c` (`func_003F1F90`), `src/grok_w3_003f.c` (`func_003F1FF0`), and `src/b10s_0_h.c` (`func_003F2060`). Each global helper span was independently replayed from its current root source with its recorded production recipe: 92B, 52B, and 64B respectively.

Using the caller's recorded legacy profile, `MWCCPS2_30` (3.0-011126) with `-O4,p -sdatathreshold 0`, caller-only verification passes exactly at 112B. The source and receipt are committed without catalog or build-script changes; integration should add only the caller row and retain existing global-helper credit.

Integration reuses the current root's canonical nested parser guard and integer-address record access. This preserves the algorithm and also makes every local helper byte-exact under the caller's legacy profile. Production auxiliary checks validate all three helper spans without adding them to progress a second time.
