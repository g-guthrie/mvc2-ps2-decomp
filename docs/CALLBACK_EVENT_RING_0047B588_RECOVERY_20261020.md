# Callback event ring at `0x0047B588`

Exact `func_003FB510` in `src/r5_b.c` normalizes the write cursor with `% 256`, selects that record in `D_0047B588`, and stores all fields of the source-defined `E3FB` record: two bytes, one halfword, and three words. This establishes a 256 × 16-byte ring extent of 0x1000 bytes. Exact `func_003FB398` in `src/w1_b.c` clears precisely that range, ending at the separate counter table `D_0047C588`.

The following 0x20-byte counter area is cleared before the next global at `D_0047C5A8`. `func_003FB510` increments and reads a `u16` counter at its `idx`, and the exact event callsites in `src/b10s_0_t.c` and `src/runtime_framed_calls_003f.c` pass only indices 2 and 3. Only those two observed counters at `0x0047C58C..0x0047C590` are typed; the other 28 bytes of the cleared counter area remain raw. Five directly declared and updated signed words at `0x0047C5A8..0x0047C5B8` hold the ring cursor and adjacent runtime state. The four-byte prefix at `0x0047B584` and remaining tail `[0x0047C5BC, 0x0047C610)` stay raw.

This packet types 4,120 bytes. The writer, initializer, both event-callsite translation units, and state reset object replay exactly; all 11 split data objects compile with MWCCPS2 3.0.3 `-O3 -sdatathreshold 0` and verify byte-exact against the retail image. `tools/validate_progress_catalog.py` passes.
