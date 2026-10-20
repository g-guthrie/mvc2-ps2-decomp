# File-service descriptor close

`func_00108118` now contributes 380 bytes of exact C under Sony EE GCC 2.9, O2/G0. It obtains the descriptor, takes the operation-1 file-service lock, rejects an unready service or missing/inactive entry, and submits a close request through RPC.

The five-word request carries a semaphore handle, completion pointer and size, remote handle, and local descriptor-table index. The shared request prefix is exactly 20 bytes. The shared descriptor is 16 bytes, and the lookup's 32-entry bound makes the signed pointer difference used for the index well-defined. Lookup, reservation, descriptor buffer operations, device control, and close now use one descriptor type; the existing descriptor request prefix is also reused.

After a successful RPC submission, close clears the local active flag and reads the four-byte acceptance reply through its native uncached alias. Rejection and RPC failure preserve the native -11 paths. An accepted request waits for completion, releases its semaphore, preserves negative completion errors, and normalizes nonnegative results to zero. Early service and descriptor errors remain -1 and -9 respectively.

The canonical semaphore parameter type is reused. Only the native max-count, initial-count, and option assignments are performed. Other fields retain the native partial-initialization behavior. Whole-function verification includes the handle/index stores, semaphore ownership, transport/acceptance branches, and final signed result comparison.

Validation: all affected functions passed whole-function relocated object checks. The full hybrid image and packed ELF are byte-identical to retail; all 91 tests pass.
