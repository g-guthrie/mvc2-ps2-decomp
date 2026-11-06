# Exact file-service device control

`func_00108D68` is a complete 476-byte native C reconstruction, independently
verified with Sony EE GCC 2.9 O2/G0 and SN assembler G0. Its actual six input
arguments include a descriptor, device operation, input buffer/unsigned size,
and output buffer/unsigned size. Both lengths must fit 1,024 bytes. The
request sends the native 1,056-byte packet and preserves the descriptor,
semaphore, cache writeback, uncached reply read, and completion/error paths.

The null-input branch first clears the input-size word; after reading the
actual descriptor handle, the native code stores the incoming size into that
same word. Both observed stores are preserved. The real descriptor read
between them naturally prevents the compiler from eliminating the first
store under possible aliasing; no artificial alias, clobber, helper, volatile
qualifier, padding, or assembly was introduced. No data credit is claimed.
