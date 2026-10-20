# Sony RPC and native-root checkpoint

Nine additional complete functions contribute 2,844 code bytes: three bounded-payload RPCs (1,588 bytes), four string/scalar RPCs (876 bytes), kernel-hook initialization (196 bytes), and pad close (184 bytes). Each production object independently verifies across every complete relocated function with Sony EE GCC 2.9 O2/G0 and SNAS G0. The new sources describe existing buffers and syscall contracts; they add no data ownership or fabricated helper bodies.

Three independently referenced command inputs contribute 255 reconstructed-data bytes in 25 verified objects. Native callsites, real bounds and retained opaque/gap bytes are documented in `NATIVE_EFFECT_ROOTS_RECOVERY_20261020.md`. Middle receipts reconstructed from source agree with the retail-image receipt. The quad-selector report now includes all five documented native-only roots alongside 47 source roots, with explicit next-root bounds. Their selectors add no additional rows: table1 remains 96 individually supported rows and table2 remains raw.

All 86 tests pass (57 tools and 29 tests under `tests/`). Build coverage finds 4,053 credited sources with verification and no unregistered bodies. The complete hybrid ROM and reconstructed retail ELF remain byte-identical to their original targets. Cached source/object/header comparisons found no unrelated changes; only the three reviewed raw gap sources were replaced in place.

Verified linked code is 2,002,568/3,293,696 bytes (60.8000%); reconstructed data is 186,358/648,064 bytes (28.7561%). The next normal push remains at 2,014,636 verified code bytes, leaving 12,068 bytes. This checkpoint is local; public main was last confirmed at `e240ba423bcf3eaded1632e1c826530dcd3bb597`.

The fresh game-code candidates at 0x003C5DD0, 0x00396030 and 0x0024F000 remain uncredited. Replacing the last candidate's float bit casts with the native arithmetic removes excess stack traffic, but its instruction schedule still differs. The 0x004220B0 wrapper also remains seven instruction words short of an exact register assignment; debug-enabled compilation does not resolve it. Private candidates and diagnostic output are retained separately.
