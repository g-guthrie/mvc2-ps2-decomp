# Sony memory-card file operations

Five complete native routines match 1368 bytes under the established Sony EE GCC 2.9 O2/G0 and SNAS G0 profile:

- `00110070` (196 bytes): synchronous memory-card service priority request; releases the semaphore on both outcomes and reads the RPC result on success.
- `00110138` (292 bytes): open a path with the requested mode.
- `001104B8` (276 bytes): asynchronous file read, with cache writeback of the destination and existing 192-byte completion record.
- `001107B8` (224 bytes): poll or wait for the pending command, publish command/result outputs, and release the semaphore on completion.
- `001108F0` (380 bytes): request card type, available space and formatted status, enabling only requested output fields.

The source reconstructs the Sony native variant. Historical PS2SDK libmc revision `01d625018c3fde3044292446c910b8ea508adfdc` corroborates its 48-byte file command and 1044-byte name command. The native server/semaphore/error behavior is independently recovered from each complete function; this packet does not claim PS2SDK was the native source.

The file command stores the descriptor at offset 0, port/slot at offsets 4/8, size/offset/origin at 12/16/20, buffer/parameter pointers at 24/28, and a 16-byte prefix payload. Get-info reuses fields for requested-output flags, as the native routine does. No new buffers are defined or credited.

The existing read and get-info callbacks at 00110428 and 00110898 receive one pointer through the real SIF RPC completion interface. Their prior integer-address formals are corrected to pointer formals; the existing CPU uncached address conversion remains explicit inside each callback. The get-info output globals are consistently declared as pointers to integer results. Both complete existing translation units pass their original production compiler profiles: p2c with SN GCC 2.95.2 and p3 with EE GCC 2.96, all O2/G0. All eleven previously credited functions in those units remain exact; these interface corrections add no credit.

The new file-operations object contains exactly its five complete functions and no allocated readonly, data or BSS sections. The standard object verifier passes every full span. No fabricated helpers, assembly implementation, forced volatile or incomplete prefix matches are used.
