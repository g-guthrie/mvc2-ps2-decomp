# Fixed fields in the runtime callback table at `0x00479E00`

The table contains 16 records of `0x138` bytes. Exact `func_003FC918` scans indices 0 through 15 at that stride when it chooses a free record; `func_003FB398` clears exactly `0x1380` bytes from `0x00479E00`; and exact `func_003FCD80`/`func_003FD2A0` traverse the same 16 records. The table therefore ends at `0x0047B180`. The adjacent `0x400`-byte callback area `[0x0047B180,0x0047B580)` and the remaining following owners are preserved as they were.

The record consumers prove only selected fixed fields here. Exact `func_003FD2A0` tests `+0` and passes the record payload to `func_003FD228`. That callback reads and updates the signed mode byte at `+1`, reads the signed resource handle at `+4`, accumulates a signed word at `+0x14`, and stores a signed result at `+0x20`. Exact `func_003FCD80`/`func_003FCCF0` independently read the active and mode bytes and the handle, then clear the whole `0x138` record. These five fields total 14 bytes per row, 224 bytes overall. The gaps at `+2..+3`, `+8..+0x13`, `+0x18..+0x1F`, and `+0x24..+0x137` remain raw. No dynamic payload/array extent is inferred.

All 129 split objects compile with MWCCPS2 3.0.3 `-O3 -sdatathreshold 0` and verify byte-exact against the retail image. `tools/validate_progress_catalog.py` passes.
