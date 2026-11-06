# Sony thread, DECI2 and packet recovery

Eight complete native functions add 1060 exact bytes with the established Sony EE GCC 2.9 O2/G0 and SNAS G0 profile:

| Function | Bytes | Behavior |
| --- | ---: | --- |
| 00104AE0 | 216 | Consumes the existing 512-entry, two-byte thread-command queue and dispatches its three native operations. |
| 00104BB8 | 212 | Creates the semaphore and queue worker, starts it with the actual queue pointer and sets the caller's priority. |
| 00104E40 | 68 | Registers a DECI2 protocol/context/three-argument handler through the actual kernel parameter record. |
| 001043A8 | 124 | Accepts channels one/two, initializes the existing console once and forwards the requested bytes. |
| 00105578 | 176 | Preserves the native bounded line-buffer flushing and newline behavior. |
| 001067F0 | 168 | Allocates a free native 64-byte RPC packet slot, sets its header/ID and enables interrupt delivery. |
| 0010B328 | 56 | Resets the existing RPC state and clears its four-byte client field. |
| 0010BD00 | 40 | Calls the recovered two-name operation with the existing `all` selector and operation one. |

The thread parameters use the public 36-byte thread record and 24-byte semaphore record, with precisely the fields written by the native initializer. The RPC allocator's 28-byte header follows the public SIF layout; the native pool advances by 64-byte slots. It preserves the observed pre-increment/post-increment ID rule with defined unsigned arithmetic. These declarations allocate no new queue, stack, packet pool or selector storage.

DECI2 registration and line output also expose existing source-interface errors. The three syscall-wrapper CUs now preserve the actual integer returns for Close, ReqSend, ExRecv, ExSend, ExReqSend, ExLock, ExUnLock and kernel string output; ExRecv/ExSend receive real byte pointers and a 16-bit length, and string output receives its real pointer. Poll retains its public void return. These contracts are corroborated by [PS2SDK DECI2 declarations](https://github.com/ps2dev/ps2sdk/blob/329e2bb43287e16af16c4dde1c614e2662c24468/ee/kernel/include/deci2.h) and the [kernel thread/semaphore and Deci2Call declarations](https://github.com/ps2dev/ps2sdk/blob/329e2bb43287e16af16c4dde1c614e2662c24468/ee/kernel/include/kernel.h). The [SIF packet-header declarations](https://github.com/ps2dev/ps2sdk/blob/329e2bb43287e16af16c4dde1c614e2662c24468/common/include/sifrpc-common.h) corroborate the packet shape. These public headers are ABI evidence; this reconstruction does not claim they were the retail source.

All nine previously credited functions across the three affected wrapper CUs remain byte-exact, totaling 380 unchanged bytes. Those interface repairs add no credit. All eight new complete bodies pass the current integration tree's standard object verifier, and each final object contains exactly its registered functions with no allocated readonly, data or BSS payload. No data credit, assembly implementation, padding filler or forced volatile is added. Nonmatching DECI2 initialization/send/event and numeric-rounding probes remain private and are excluded.
