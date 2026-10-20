# Sony memory-card file metadata and rename

Six complete native routines match 1860 bytes with Sony EE GCC 2.9 O2/G0 and SNAS G0:

- `func_00111090`, 456 bytes: update selected file metadata, with flags restricted to the native low three bits and an exact 64-byte file-info copy.
- `func_00111258`, 344 bytes: rename an existing file, with a 1023-byte terminated old-path field and a 32-byte terminated new-name field inside the file-info buffer.
- `func_00110AE0`, 328 bytes: request directory entries, writing back the existing result buffer when the requested maximum count is nonnegative.
- `func_00110CB0`, 320 bytes: change directory using the existing DMA directory buffer and the real completion callback.
- `func_00110C28`, 132 bytes: completion callback copies at most 1023 bytes from the DMA buffer's uncached alias, then terminates the destination. Its two `strlen` calls follow the native conditional expression.
- `func_00110EC0`, 280 bytes: delete a named file.

This is reconstructed C for the native Sony variant. Historical PS2SDK libmc corroborates the command packet and file-info layout; its code is a separate implementation, and this recovery does not claim the native code was built from PS2SDK. The corroborating source is `ps2dev/ps2sdk` revision `01d625018c3fde3044292446c910b8ea508adfdc`, `ee/rpc/memorycard/src/libmc.c` (2004-04-15).

The native variant checks the RPC client server at offset 0x24, acquires the existing semaphore, and returns -100/-200/-210 for the observed initialization/acquisition/argument failures. Both submit RPC command 14 with the existing 0x414-byte name-command record, a four-byte response and no callback. Successful metadata writes set command status 14; rename sets status 19. Failure releases the semaphore.

The file-info record is 64 bytes: its last 32 bytes hold the rename name. The command record contains port, slot, flags, maximum entries at offset 12, a four-byte table pointer and a 1024-byte path. These declarations describe existing buffers; this packet defines no new data objects and claims no data credit. The client prefix stays opaque because these functions only observe its server field.

The standard object verifier checks all six complete spans. The generated object contains precisely the six function bodies and no allocated readonly, data or BSS payload. Sony's genuine builtin fixed-size `memcpy` generates the native unaligned 64-byte transfer; the source includes no assembly or fabricated helper bodies. The truthful `D_004C8940 = 0x004C8940` buffer alias is required for the metadata/name buffer.

The directory operations use the existing native data-cache writeback routine at 00106578 with a pointer and byte count, and the callback uses the existing memory copy routine at 0011D740. The callback declaration is the actual unary RPC completion ABI; no cast hides an incompatible callback. Additional truthful aliases are `D_004C8EC0`, `func_00110C28`, `func_00106578` and `func_0011D740` at their named addresses.
