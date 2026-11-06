# Descriptor creation and actor recovery

The 200-byte function at `00109690` reserves a file descriptor, submits path
operation 9 and returns either the error or the descriptor index. Its existing
allocator returns null or one of 32 sixteen-byte records, supporting the
same-array pointer subtraction. Failure clears the reservation while holding
the semaphore. The existing 12-byte forwarding wrapper now uses the shared
kernel declaration's actual integer result type and still discards that result.

The 356-byte actor initializer at `003B9A90` preserves the native random-call
order, integer masks, floating constants and motion updates. Its four-float
lookup reuses the existing reconstructed owner. The final animation selector
uses `RNG & 3` and an unsigned byte load at `004C2050`; this establishes four
used bytes, now represented as `{0x13, 0x14, 0x15, 0x13}`. The next four bytes
remain untyped and uncredited. This is the minimum bounded lookup used here,
not a claim that the original allocation ended after four bytes.

The 344-byte actor callback at `00231490` advances motion, handles the height
transition and submits the owner's leading position pair to the effect helper.
Its declarations agree with the matched integer animation-step return and
byte-context effect-helper interface. The return is ignored and the vector
pointer conversion is explicit. A three-float position object reproduces the
native stack accesses without the worker proposal's unnecessary fourth float.
Retail initializes only x and y, while effect consumers also copy z. The source
preserves that uninitialized third component; this is a native bug, not a claim
that its value or downstream behavior is deterministic. No zero initialization,
runtime bounds checks, assembly or register assignments were added.

The two available effect-provider definitions and their sole C caller now use
one compatible parameter order and vector type. Their bodies and native call
registers are unchanged. Separate floating-point and integer argument channels
do not uniquely recover the original C parameter order, so the definitions
were made consistent with the caller. The two unmatched effect providers still
have only the observed call-register contract; their original C declarations
remain unrecovered. This repair adds no credit for existing provider bodies.

Root independently compiled all seven affected CODE units and verified their
complete functions. The combined bank adds 900 CODE bytes and 2,548 DATA bytes.
All 118 tests, a fresh split, full hybrid linkage and packed retail ELF byte
identity passed. Totals are 2,082,720 CODE bytes (63.2335%) and 261,775 DATA
bytes (40.3934%). The next fixed CODE milestone remains 2,113,447 bytes.
