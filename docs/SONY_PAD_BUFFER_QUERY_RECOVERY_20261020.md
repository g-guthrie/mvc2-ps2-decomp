# Sony pad buffer and capability queries

Seven complete native routines match 760 bytes with the established Sony EE GCC 2.9 O2/G0 and SNAS G0 profile:

- `0010D8C0` (80 bytes): read the selected DMA buffer's frame counter.
- `0010D910` (124 bytes): copy the selected pad report and return its native length.
- `0010D990` (120 bytes): read pad state, including the native stable/busy adjustment and disconnected fallback.
- `0010DAA8` (80 bytes): read the current request state.
- `0010E0F8` (180 bytes): read capability bytes after the native validity and mode checks.
- `0010E260` (92 bytes): test the recovered capability mask against 0x3ffff.
- `0010E2C0` (84 bytes): issue the existing button-information request with mask 4095.

The 28-byte slot layout and `[port][4]` indexing reuse the existing `sony29_buffer_slot_control.c` convention. These functions call the real native double-buffer selector at 0010D860, which returns a byte pointer; this packet adds no substitute body for it. The selector's native cache synchronization covers 256 bytes and selects between two 128-byte frames by their counters at offsets 88 and 216.

Historical `ps2dev/ps2sdk` libpad revision `01d625018c3fde3044292446c910b8ea508adfdc`, `ee/rpc/pad/src/libpad.c`, independently corroborates the 128-byte snapshot and offsets: frame 88, report length 96, mode validity 100, state 112, request state 113 and validity 114. The native capability path additionally reads bytes 102 and 121–124; the 64-bit byte assembly and signed 32-bit return follow the actual native shifts, additions and narrowing. The historical source is corroboration, not a claim that the native library was built from PS2SDK.

The final isolated object contains exactly these seven functions and no allocated readonly, data or BSS sections. The standard verifier passes every complete span. No data credit is added. Nonmatching selector and actuator-query candidates are kept private and excluded from the source packet.
