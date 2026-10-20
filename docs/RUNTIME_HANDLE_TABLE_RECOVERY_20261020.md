# Bounded runtime-handle table

The first 960 bytes at `0x004854C0` form sixteen 0x3C-byte runtime records.
Verified `func_00404290` scans at most sixteen slots and advances by 0x3C;
verified `func_004045D8` checks the same sixteen records with a descending counter and a forward 0x3C
stride; and `func_00404240`/`func_00404268` clear exactly 960 bytes. The next
independent data owner starts at `0x00485880`.

The source and native consumer establish these typed fields in each record:

- ten 32-bit words at offsets `0x00–0x27`, including the active flag, slot,
  state, result, and fixed arguments used by setup and `func_004044E0`;
- two signed halfwords at `0x30` and `0x32`, written by the rate initializer
  and read by `func_004044E0`;
- two signed halfwords at `0x36` and `0x38`, loaded by `func_004044E0`.

The bytes at `0x28–0x2F`, `0x34–0x35`, and `0x3A–0x3B` remain raw for each
record because the native path only passes/clears the first area and does not
read those bytes as fields. This yields 768 typed bytes and 192 raw gap bytes in
the bounded 960-byte table. The remaining `0x1A60` bytes through the existing
owner at `0x004872E0` remain raw, including the separate four-record table at
`0x00485880`.

All 97 resulting data objects compile with MWCCPS2 3.0.3 `-O3
-sdatathreshold 0` and match the retail image exactly; the data catalog
validator passes.
