# Bounded SDK handle-pool fields

The region `[00487344,00488310)` previously had one raw 0xFCC-byte owner.
This recovery adds 2,028 reconstructed data bytes and retains 2,016 raw bytes:

- Three independently referenced signed words at 00487344, 00487348 and 0048734C
  contribute twelve bytes. Native code reads the first as an error value;
  existing C accessors and state logic read/update the adjacent counters.
- The 32-slot pool spans `[00487358,00487B58)`, with stride 0x40. The allocator
  searches at most 32 slots, the sweep visits 32 slots, and reset clears exactly
  0x800 bytes. Each row contributes 63 typed bytes; byte three remains raw.
- The eight bytes preceding the pool and the complete 0x7B8-byte following span
  remain raw. The following catalog owner at 00488310 is preserved.

The [field evidence ledger](SDK_HANDLE_POOL_FIELD_EVIDENCE_20261020.csv) records
direct native accesses for each byte and word. A broad zeroing operation is
used to corroborate the pool bound, not to infer the interior field types.

Each row contains three state bytes, two I/O object pointers, two eight-byte
RuntimeSpan values, a sixteen-byte SIF DMA descriptor, its transfer ID, and four
remaining signed state words. The spans reuse the existing runtime_span_types.h
record with start/length members. The native processor copies each complete
span with paired unaligned load/store instructions after using the complete
004104E0 span operation; these are two-word records, not scalar 64-bit values.

The descriptor at row +0x1C contains source and destination addresses, size and
attributes. Native code masks the source, fills all four fields and passes the
record to syscall 0x77 with count one; the returned transfer ID is stored at
+0x2C. A small shared SonySifDmaTransfer declaration captures this layout. The
existing syscall primitive now takes that pointer/count and explicitly returns
the syscall result; all 156 functions in its source unit remain exact.

Every row is split into a three-byte header, its raw byte-three gap, and a
60-byte typed run. Alongside the adjacent words and outer raw spans, all 101
compiled objects tile the prior region exactly without gaps or overlap. The
allocator/sweep row address is calculated in the target's 32-bit integer address
space before selecting the current row. The C sweep remains exact.

The 101 objects were independently recompiled under the production MWCCPS2
3.0.3 profile and verified over their entire spans. A marker probe including
the actual RuntimeSpan and DMA declarations confirms all fifteen words in the
60-byte run have their native offsets. All 68 functions across seven relevant
consumer units remain exact; the sweep's unused backend declaration removal
also replays exactly. Fresh splitting, complete image linkage, packed ELF
comparison and all 91 tests pass. Native-only allocator/release/process code
retains its existing code status.
