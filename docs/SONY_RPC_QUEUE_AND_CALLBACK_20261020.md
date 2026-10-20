# Sony RPC queue and callback recovery

Four complete native-derived functions add 248 matching code bytes, using
EE GCC 2.9 (`-O2 -G0 -ffunction-sections`) and the existing SN assembler:

| Entry | Bytes | Behavior |
| --- | ---: | --- |
| 00107B90 | 44 | Invoke an optional callback with its saved argument, then synchronize and enable interrupts. |
| 00107E58 | 52 | Clear the compatibility state and four revision bytes, returning zero. |
| 00107328 | 88 | Disable interrupts, remove the queue head when present, update the busy flag, and enable interrupts. |
| 00107548 | 64 | Drain queued RPC work and sleep until another wakeup. |

The callback is registered by native `00107BC0` through `00106240` with the
record at `004C6C80`. It reads the callback at offset zero and its argument at
offset four. Dispatch and the conditional guard are compiled C; only the
actual `sync` and `ei` hardware operations use inline assembly. The memory
clobber describes the synchronization boundary. No raw function body or
instruction rewriting is involved.

Queue removal reads the head at offset 0x0C, reads its successor at offset
0x3C, and writes the busy flag at offset four. All other prefix bytes remain
opaque in the C views. The routine enables interrupts unconditionally, as in
the native function. The worker processes each returned item through
`00107380` and calls the sleep-thread syscall adapter `00103D00` when empty.
These views add no data credit.

Unused integer-based queue declarations were removed from `s2.c` and `s2m.c`;
neither unit called these functions. Both complete units were recompiled and
verified. The memset-like helper `0011D8F8` uses its existing pointer-returning
interface; the reset intentionally discards that pointer and returns zero.

All four functions pass relocated whole-function comparison. Fresh splitting,
full hybrid linkage, packed retail ELF comparison, and the complete test suites
validate the integrated batch.
