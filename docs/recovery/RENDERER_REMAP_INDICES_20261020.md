# Bounded renderer nibble and byte maps

Recover three 512-byte lookup arrays without expanding their existing catalog ranges. These are source offsets consumed by the renderer, rather than uninterpreted payload words.

`func_003EB4A0` reads the four pointers at `D_00478940` in a fixed four-block loop. Each pointer selects either `data_raw_00478540` or `data_raw_00478740`. The nested loops cover two rows and 32 output pixels per row, reading two 32-bit indices per pixel: exactly 128 entries, or 512 bytes per selected array. Index parity selects a source nibble; signed division by two gives its byte offset. All stored values are nonnegative and below 512, within the 256-byte source block.

`func_003EB810` reads the four pointers at `D_00478B50`, alternating between the two 64-entry halves of `data_u32_00478950`. Each selected half supplies two rows of 32 byte offsets, with eight loads per unrolled iteration. Together the halves cover all 128 signed 32-bit entries. All offsets lie within the 512-byte source block.

The byte-map pointer table now declares signed index targets, and its existing code consumer's declarations agree that the pointer table is const. The consumer remains exactly 228 native bytes; this interface correction adds no code credit. Both pointer lists and all three arrays independently reproduce retail bytes under their production compiler recipes. Whole-image placement, packed ELF identity, and the test suite are checked before catalog promotion.
