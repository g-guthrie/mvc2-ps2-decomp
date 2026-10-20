# Sony CD/DVD read completion

The complete 160-byte callback at `0010E908` matches with Sony EE GCC 2.9 O2/G0 and SNAS G0. Its real unary pointer argument is established by the SIF RPC call at `0010FAE0`: `0010FAB8`/`0010FACC` put this callback in T3, while `0010FAC4` puts the existing 0x90-byte DMA record at 0043AA80 in the ninth callback-argument slot. `0010FA68` supplies the same record's 0x90-byte cache-writeback extent.

That record contains two signed copy counts, two destination pointers and two 64-byte byte fragments. The callback maps the received record through the native 0x20000000 uncached alias and copies each positive-length fragment to its actual destination. It then invokes the already reconstructed CD/DVD event callback at 0010E6D0 with the existing command-status address. The status object keeps its existing shared volatile declaration; no volatility is introduced to affect code generation. The explicit cast at the event API boundary follows its existing `const int *` input contract.

The isolated final object contains exactly one 160-byte function and no allocated readonly, data or BSS sections. The standard object verifier passes the complete function; no new data or helper credit is added. Nearby nonmatching command probes remain private and are excluded from this source checkpoint.
