# Sony pad actuator query

The complete 288-byte native actuator-query function at `0010DB30` matches with Sony EE GCC 2.9 O2/G0 and SNAS G0. It checks the existing slot, snapshot validity and mode, rejects indices beyond the snapshot's actuator count, returns that count for index -1, and selects the requested function/subfunction/size/current byte for selectors 1–4.

The source uses the actual four-byte descriptor view established by the native indexed loads at offsets 48–51 with stride four. Historical PS2SDK libpad revision `01d625018c3fde3044292446c910b8ea508adfdc` independently corroborates the 128-byte snapshot and flat 32-byte payload at offset 48. The descriptor array is a view over those bytes, not a claim that eight actuators are usable: the native count controls valid entries, and the combination-query API also views bytes starting at 64 within the same payload. No snapshot storage or new data objects are defined or credited.

The real native double-buffer selector at 0010D860 remains an external pointer-returning function. The final object contains precisely the complete 288-byte query, no synthetic helpers, and no allocated readonly, data or BSS payload. The standard verifier passes its complete relocated span.

Three adjacent complete functions add 788 exact bytes, for a 1076-byte four-function object:

- `0010DC50` (284 bytes): reads the combination count at snapshot offset 107, supports index -1 as a count query, and selects bytes from four-byte combination descriptors beginning at offset 64.
- `0010DD70` (312 bytes): reads the current mode, extended mode table, current table index or table entry/count after the native validity/request checks. It preserves the native F3 sentinel and selector-specific mode restrictions.
- `0010DF60` (192 bytes): validates the DMA snapshot, copies six actuator bytes to the existing command buffer at slot offset 4, writes request 1 and length 6, then submits through the real native 0010D248 routine. The result is one only when submission returns one.

The snapshot explicitly represents the overlapping actuator/combination payload views. The newly used slot field at offset four is an actual pointer to the existing command buffer, established by the native load and subsequent writes; it was previously an unexamined reserved word in the slot view. No command buffer is allocated or credited. The command's unknown first word remains unaccessed, with request/length at offsets four/eight and the six-byte payload at twelve. All four complete functions pass together under the original Sony profile, and the final object has exactly four functions with no allocated non-code payload.
