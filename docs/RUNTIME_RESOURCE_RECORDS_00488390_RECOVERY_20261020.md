# Fixed fields in the 40-slot runtime resource table at `0x00488390`

Exact `func_00409C90` scans 40 slots and uses a `0x48` stride; exact `func_00409A10` visits the same 40 records for cleanup, and exact `func_004098F8` inspects the same record flags. This bounds the table at `[0x00488390, 0x00488ED0)`, with 40 records totaling `0xB40` bytes. The remaining `[0x00488ED0, 0x00489018)` tail remains raw.

Exact `func_00409CE8` initializes bytes `+0..+2` and seven signed words at `+4..+0x1C`; exact `func_00409948` reads and updates the signed-word fields at `+0x0C`, `+0x10`, and `+0x1C`, and changes the state byte at `+2`. Byte `+3` is left raw because these consumers do not establish its role. The output words at `+0x20` and `+0x24` are written with `sw` by native `func_0040A9C8` through the output pointer `record + 0x20`; exact creator `func_00409CE8` reads the second word at `+0x24`. The per-row span `+0x28..+0x47` remains raw.

This recovers 39 bytes per row, 1,560 bytes total. The five code-owner TUs containing the table scanner, allocator, creator, cleanup, and state check all replay exactly; native parser stores at `+0x20/+0x24` were checked directly. All 161 split data objects compile with MWCCPS2 3.0.3 `-O3 -sdatathreshold 0` and verify byte-exact against the retail image. `tools/validate_progress_catalog.py` passes.
