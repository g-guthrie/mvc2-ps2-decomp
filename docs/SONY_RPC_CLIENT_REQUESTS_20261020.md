# Exact SIF RPC client requests

`func_00106A40` (344 bytes) receives other data and `func_00106C98` (320 bytes)
binds a client, with synchronous and asynchronous paths. Native packet writes
and call transfers establish the ABI; public SIF RPC headers at PS2SDK
revision `329e2bb43287e16af16c4dde1c614e2662c24468` corroborate the common
receive prefix, 40-byte client, packet fields, and command constants. These
bodies are native reconstructions; no upstream C implementation was copied.

The shared header expresses the real 16-byte receive prefix with an opaque
packet pointer, client layout and packet pool. Both existing bind callers
include it. The older MWCC caller requires `-i src` for header lookup; its
optimization flags are unchanged. Existing assembly loops in `w1_c.c` are
untouched and receive no additional credit.

Root independently compiled and verified the full closure: both requests
664 bytes, reply callback 180 bytes, packet allocator 168 bytes, clear helper
28 bytes, EE96 caller 208 bytes and older MWCC caller 140 bytes. All seven
functions, totaling 1,388 bytes, are exact; new credit is only the two request
functions. Sony sources use EE GCC 2.9 O2/G0, function sections and SN AS G0.
The other callers retain their existing EE96 O2/G8 and MWCC 3.0-011126
O3/Op/G8 profiles.
