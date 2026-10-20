# Bounded runtime-record fields at `0x00485880`

`func_00404680` and `func_004050A0` traverse four records with a `0x1C0` stride; `func_00404680` also clears exactly `0x700` bytes from the base. This independently bounds the four-row region at `[0x00485880, 0x00485F80)`. The next existing data owner remains at `0x004872E0`, so the intervening `[0x00485F80, 0x004872E0)` bytes stay in the raw tail object.

Within each row, source-matched `func_00404968` reads and clears the signed byte at `+3`, the word at `+4`, and the object pointer at `+0x8C`; exact native `func_00404BD0` also reads/clears the word at `+8` and calls through the `+0x8C` object's vtable. The signed byte at `+0` is read by both four-slot scans. Those five fixed fields per row are typed, totaling 56 bytes. Bytes at `+1..+2`, `+0x0C..+0x8B`, and `+0x90..+0x1BF` remain raw. In particular, the cleanup loops use a dynamic signed count, so this change does not claim an array bound or credit the pointer/handle arrays in those raw spans.

All 33 split data objects compile with MWCCPS2 3.0.3 `-O3 -sdatathreshold 0` and verify byte-exact against the retail image. `tools/validate_progress_catalog.py` passes.
