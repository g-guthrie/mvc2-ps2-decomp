# SIF command sending and RPC call dispatch

Three complete native-derived functions add 260 matching code bytes with
Sony EE GCC 2.9 O2/G0 and the existing SN assembler:

| Entry | Bytes | Behavior |
| --- | ---: | --- |
| 001063D0 | 60 | Forward the six public send arguments to the seven-argument backend with mode zero. |
| 00106410 | 60 | Forward the same arguments with mode one. |
| 00106DD8 | 140 | Queue a server request, copy its fields and wake its idle server thread. |

The call dispatcher appends the server to its queue, preserves the packet/client
pointer load order, and copies the request number, byte count, receive-buffer
fields and request ID. It calls the existing integer-returning wakeup adapter
only for a nonnegative thread ID whose queue is idle. Its two void-pointer
arguments match the command-handler interface; the second is unused.

The dispatcher uses the existing SonyRpcHeader, SonyRpcClient, SonyRpcServer
and SonyRpcQueue definitions. Its compilation disables strict alias analysis
for the packet and server views. The packet/client pointers are captured before
either field is stored, matching the retail sequence.

The previously recovered queue-removal and worker functions now reuse those
same shared server/queue types. Both remain exact (88 and 64 bytes); their fields
are first/active and the server's next link. The unused backend declaration in
k4.c was removed, and all seventeen functions in that unit remain exact.
No packet pool or queue storage is newly allocated, and no data credit is added
for these code/interface changes.

All three new functions pass whole-function relocated comparison. Fresh
splitting, full hybrid-image linkage, packed retail ELF comparison and all 91
tests pass for the integrated code/data batch.
