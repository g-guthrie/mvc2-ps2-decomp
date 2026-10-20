# CRI SJ memory stream objects

The retail UUID at `0x004BE9D0` is `DD9EEE41-1679-11D2-936C-0060089448BC`. All 16 bytes match the SJMEM identity recorded in the [3s-decomp SJ memory module](https://github.com/crowded-street/3s-decomp/blob/be9b9bc69dc19822a8eca9ce3e72ba560d5a3835/src/anniversary/cri/libadxe/sj_mem.c). The native interface at `0x004908C8` also has the three null COM slots followed by Destroy, GetUuid, Reset, GetChunk, UngetChunk, PutChunk, GetNumData, IsGetChunk, and EntryErrFunc in the order declared by the [SJ interface header](https://github.com/crowded-street/3s-decomp/blob/be9b9bc69dc19822a8eca9ce3e72ba560d5a3835/include/cri/sj.h). These are interface and identity cross-checks; implementation code was reconstructed from this repository's native instructions, rather than imported from that project's implementation.

## Bounded data ownership

The array starts at `0x004908F8` and contains 32 records of 0x24 bytes, ending at `0x00490D78`. The allocator `func_0040F0B8` scans exactly 32 records at that stride; `func_0040F030` and `func_0040F070` clear exactly 0x480 bytes. Record release clears 0x24 bytes. The following 12 bytes remain raw, ending at the next independently owned interface method array, `jtbl_00490D84`.

This replaces the placeholder beginning at `0x00490900`, which started eight bytes inside the actual array and extended eight bytes beyond it. The new typed array contributes 1,152 reconstructed bytes. The 12-byte suffix contributes no reconstruction credit. The preceding method array remains a separate owner.

## Record layout

| Offset | Field | Evidence |
| --- | --- | --- |
| 0x00 | interface pointer | allocator stores `0x004908C8`; native interface order matches SJ |
| 0x04 | active integer | allocator scans zero and sets one; release clears it |
| 0x08 | UUID pointer | allocator stores `0x004BE9D0`; GetUuid loads this field |
| 0x0C | remaining bytes | reset copies size here; GetNumData and chunk methods consume it |
| 0x10 | buffer offset | reset clears it; chunk methods update it |
| 0x14 | buffer pointer | allocator's first argument; chunk address arithmetic uses it as a base |
| 0x18 | buffer size | allocator's second argument; reset and range clamps read it |
| 0x1C | error callback | setter installs a code pointer; native dispatch passes context and error -3 |
| 0x20 | error context | allocator installs self; setter can install any context pointer |

`cri_sj_memory_types.h` is shared by the data definition, allocator, reset consumers, and recovered record helpers. The nine-word marker probe confirms each field offset using the actual target compiler. A compile-time assertion checks the record's 0x24-byte size.

## Interface correction

The old reset model returned the word temporarily loaded into V0. That register is also needed to copy size to remaining; it does not establish a return-value contract. Reset occupies the SJ interface's void-return reset slot. Its definition and declarations now consistently use `void`, and its complete 16-byte body matches EE GCC 2.96. The remaining four functions in its former translation unit retain their original compiler and verify independently. This changes no credited code byte count.

GetUuid now returns a pointer, and EntryErrFunc stores a correctly typed error callback and a separate `void *` context. The allocator takes a buffer pointer and size. These corrections preserve their complete native functions. Whole translation units, both replacement data objects, full-image linkage, and packed retail ELF identity are verified before committing.

## New complete code

`func_0040F478` reconstructs the 164-byte IsGetChunk method. It enters the existing critical section, selects zero available bytes for the free line or the lesser of remaining/requested bytes for the data line, reports invalid lines through the error callback, stores the available count, unlocks, and returns whether the request can be satisfied. Every branch assigns the local count before use. Both this method and the existing 16-byte reset share one source and the EE GCC 2.96 `-O2 -G0` profile.

`func_0040EFF8` reconstructs the 24-byte unlock helper. The existing shared volatile counter is decremented and then read, exactly as in the native instructions. The [SJ critical-section interface](https://github.com/crowded-street/3s-decomp/blob/be9b9bc69dc19822a8eca9ce3e72ba560d5a3835/src/anniversary/cri/libadxe/sj_crs.c) corroborates its void return. The corresponding recovered wrappers and server loop now use void consistently; the context-taking unlock wrapper retains its ignored pointer argument. Their complete translation units still match. These interface repairs add no code credit beyond the new 24-byte helper.

The original inventory merged unlock and the following fatal-error callback into one 52-byte function. Native unlock ends at `0x0040F010` after `jr ra` and its delay slot. The allocator separately installs `func_0040F010` as its error callback, and that 28-byte body branches back to its own entry. The inventory now records the independent 24-byte unlock and 28-byte error loop. Their combined extent is unchanged; only unlock receives C credit. The error loop remains uncredited.

Validation completed: 608 whole functions in the affected translation units, both replacement data objects, 14,033 unchanged cached source/object pairs, full loaded-image identity, packed retail ELF identity, and all 91 tests. The new code totals 188 bytes; the corrected reset and interfaces receive no additional byte credit.
