# Fixed fields in the runtime-service table at `0x0047C620`

Native `func_004015C8` and `func_00402498` traverse 16 records at a `0xAC` stride, and `func_003FDAA0` clears exactly `0xAC0` bytes. The table is therefore bounded at `[0x0047C620, 0x0047D0E0)`. Exact replays of `src/s4.c` verify the cleanup consumer `func_00401428` and the 16-record scan `func_004015C8`.

Across each record, the active byte at `+0` and signed callback count at `+3` are directly read by the cleanup path. The four 32-bit words at `+4..+0x13` are accessed as resource/handle/callback words in that exact cleanup view. A separate exact lifecycle consumer `func_004017E0` dereferences the word at `+0x14` as an optional vtable object and clears it; `func_00401708` supplies the value copied into that slot by native `func_00401640`. The data source uses a pointer view for this word and does not claim the cleanup view gives it the same role.

Only those fixed fields are typed: 22 bytes per record, 352 bytes total. Bytes `+1..+2` and `+0x18..+0xAB` remain raw. In particular, the original first argument carried into `func_00401150` remains separate from its allocator index, which is reset to zero during the 16-slot scan. Its later `i < original_argument` loop writes the list beginning at `+0x18` and overlaps fixed words set earlier in the function. No input bound for that list is claimed, and no array or following words are credited.

All 96 split objects compile with MWCCPS2 3.0.3 `-O3 -sdatathreshold 0` and verify byte-exact against the retail image. `tools/validate_progress_catalog.py` passes.
