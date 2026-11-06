# Sony RPC command reply recovery

Two complete handlers contribute 272 bytes of exact C.

`func_00106BE8` (176 bytes) allocates a reply packet, copies the incoming client and packet identities, looks up the requested server across registered queues, fills the server and buffer pointers or clears them when absent, and sends a 64-byte bind reply.

The request metadata is snapshotted before the reply writes. Loading the packet pointer before the client pointer reproduces the native load schedule. Both whole functions match with Sony EE GCC 2.9, `-O2 -G0 -ffunction-sections -fno-strict-aliasing`, and the existing SN assembler. No inserted assembly, volatile accesses, or register constraints are used.

The packet allocator and server lookup now use the shared `SonyRpcPacketPool`, `SonyRpcQueue`, and `SonyRpcServer` layouts. The indexed reply allocator explicitly passes its existing pool argument to the fallback allocator; the previous unprototyped call depended on the argument register surviving implicitly. An unused conflicting declaration was removed. Whole translation units are recompiled and verified for these interface changes.

`func_001069E0` (96 bytes) sends the other-data completion reply with the requested source, destination, and size. The packet and receive identities are snapshotted before the metadata stores; this also reproduces the native tail-call schedule with the same compiler profile. Both handlers share the reply layout in one source file.
