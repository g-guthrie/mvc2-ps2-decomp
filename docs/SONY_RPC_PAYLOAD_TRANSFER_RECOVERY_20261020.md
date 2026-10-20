# Sony bounded-payload RPC operations

Two complete 520-byte native functions at `0010B360` and `0010B568` match 1040 bytes with Sony EE GCC 2.9 O2/G0 and SNAS G0. They preserve the existing initializer and compatibility checks, returning the native -65536/-65540 errors, submit operation 6 or 7, and return -65537 on negative transport failure.

The existing 512-byte RPC buffer has two initial 32-bit words, a 252-byte name field at offset eight and a 252-byte payload at offset 260. The name layout is independently visible in adjacent native 0010B970, whose bounded string copy writes at eight and terminates at 259. This packet's functions write their input value at zero and payload length at four. A null payload sets length zero; a size of at least 253 copies exactly 252 bytes; otherwise the real external memory-copy routine copies the supplied length. The source preserves the native signed-size test.

The original compiler builtin `memcpy` naturally generates the complete aligned and unaligned 252-byte copy loops. No hand-transcribed assembly or helper body replaces those transfers. After the eight-byte reply, the functions capture the reply value before storing the reported length through the caller's pointer, preserving native behavior even if that pointer aliases the reply buffer.

The typed record describes existing native storage; it allocates and credits no data object. The final object contains exactly two complete 520-byte functions and no allocated readonly, data or BSS sections. Both standard object-verifier checks pass across their full relocated spans.

The adjacent complete named-operation dispatcher at `0010B970` adds 548 exact bytes. It bounds and terminates the 252-byte name, caps the inline payload at 252 bytes, stores its input length in the first word, preserves the null-payload zero-byte behavior, and submits the caller's actual operation number. Its reply-value capture likewise precedes the caller's reported-length store. The full modified translation unit passes all three complete bodies together (1588 bytes) and still has no allocated non-code payload.
