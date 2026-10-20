# Bounded SJRBF ring-buffer objects

The object array at `0x00490DA8` contains 256 records of 0x40 bytes, ending at `0x00494DA8`. The allocator scans 256 slots, and both pool resetters clear 0x4000 bytes from this exact base. The array contributes 16,384 reconstructed data bytes. The following 12 bytes remain a raw owner before the next method array at `0x00494DB4`.

The previous placeholder began eight bytes inside the array and extended eight bytes past its end. Replacing that owner corrects the boundaries while preserving the adjacent SJMEM objects and both neighboring interface tables.

The complete native UUID at `0x004BEA10` is `3B9A9E81-0DBB-11D2-A6BF-444553540000`. Its identity, the 12-slot interface order at `0x00490D78`, and the record geometry agree with the [pinned SJRBF type and identity reference](https://github.com/crowded-street/3s-decomp/blob/be9b9bc69dc19822a8eca9ce3e72ba560d5a3835/src/anniversary/cri/libadxe/sj_rbf.c). The reference supplies API and layout facts; the target's instructions supply the implementation and field-access evidence.

`cri_sj_ring_buffer_types.h` represents all 16 native words: interface prefix, active state, UUID, private counters/cursors, buffer pointer, buffer and extra sizes, and the error callback/context. Every word has an explicit native access; the private words keep neutral names. A 16-word marker initializer verifies the target compiler's actual offsets. The size assertion is 0x40, and there are no untyped gaps within a record. The [field ledger](CRI_SJRBF_FIELD_EVIDENCE_20261020.csv) records the native uses.

Reset (`func_0040F728`) now has the SJ interface's void return and accepts the object prefix. Its 40-byte body clears the private state and copies the buffer size. Ordinary independent assignments reproduce the native ordering under EE GCC 2.96 O2/G0. The creator, UUID getter, callback setter, counters, and range query share the record definition and retain their complete native functions. Moving reset out of the old MWCC unit corrects its interface without changing its credited byte count.

The SJMEM get-chunk method (`func_0040F228`) adds 188 exact code bytes in the same GCC unit. It writes an empty output for the free/invalid line, or returns a bounded buffer span and updates remaining bytes and offset for the data line. Reversing the two ordinary empty-output assignments in both branches reproduces the native store order. The existing saved-offset local preserves the correct pointer/state dataflow.

The default error handlers at `0x0040F010` and `0x0040F530` compile to their full 28-byte bodies from ordinary infinite C loops. The compiler automatically emits the five leading NOPs and backward branch. The additional 8-byte SJMEM buffer-size getter at `0x0040F528` returns the typed size field; the existing buffer getter now returns a pointer.

The inventory previously combined the 8-byte size getter and following 28-byte callback into one 36-byte range. The native getter returns before the independently referenced error entry. The split preserves their combined extent and credits each complete function separately.

The complete reconstructed table and raw suffix are independently compiled and relocated against retail. Whole translation units, loaded-image identity, packed ELF identity, and the project test suites are verified before committing this recovery.

Validation: all affected functions passed whole-function relocated object checks. The full hybrid image and packed ELF are byte-identical to retail; all 91 tests pass.
