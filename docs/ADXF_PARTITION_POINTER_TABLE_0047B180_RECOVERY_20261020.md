# ADXF partition pointer slots at `0x0047B180`

`func_003FBE88` first calls exact `func_003FB5F0`, whose unsigned-index check rejects values `>= 0x100`, then stores the supplied object pointer at `D_0047B180[index]`. Exact `func_003FC900` reads entries as pointers and loads the second word from the selected object. Exact initializer `func_003FB398` clears exactly `0x400` bytes from the base; the next existing owner `D_0047B580` begins at `0x0047B580`. These bounds support 256 four-byte pointer slots covering `[0x0047B180, 0x0047B580)`.

The new `D_0047B180[256]` object compiles with MWCCPS2 3.0.3 `-O3 -sdatathreshold 0` and verifies byte-exact against the retail image. The relevant writer, validator, reader, and initializer C objects replay exactly. `tools/validate_progress_catalog.py` passes.

The retail diagnostic strings at `0x004BAE30` and `0x004BAE68` explicitly
identify the validator as `adxf_ChkPrmPt` and name the partition ID and
partition-info pointer. This is an ADXF table, rather than an ADXT player
handle table. Its pointer-element type and validated extent are unchanged.
