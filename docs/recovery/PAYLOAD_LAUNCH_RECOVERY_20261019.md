# Payload launch initializers and update helper

Four functions add 1,124 exact code bytes. Complete source units are replayed with their production compiler profiles before linkage verification.

| Function | Bytes | Profile | Native entry evidence |
| --- | ---: | --- | --- |
| 001A7340 | 368 | MWCC 3.0 O3/Op/G0 | 0044B440[0] |
| 001DE300 | 356 | MWCC 3.0 O3/Op/G0 | 0044EE10[0] |
| 001BF6A0 | 340 | MWCC 3.0 O3/Op/G0 | 0044C490 |
| 001A7500 | 60 | MWCC 3.0.3 O3/G8 | direct call at 001A7494 and pointer at 0044B444 |

Native 001A7130 loads A1 from actor+0x18, selects 0044B420[1] -> 001A7540, then 0044B440[0] -> 001A7340. Native 001DD9A0 supplies the same owner argument through 0044ED70[6] -> 001DE4E0 -> 0044EE10[0] -> 001DE300. The intermediate source dispatchers now carry the second argument explicitly. Their physical predecessors belong to different tables; function extent is established by independent entry references and exact complete-function output.

001A7340 copies the established 196-byte payload, reads the interleaved signed-short components at 004BF770 and 004BF772 with stride four, scales velocity and applies facing. These are field aliases with native GP-relative addressing, not newly credited data arrays or claims of a runtime selector bound. 001A7500 updates actor position from owner position plus actor velocity, then forwards both arguments through the existing GP-relative table at 004BF794. Its four-byte trailing alignment gap stays uncredited.

001DE300 copies the payload and position, applies facing-dependent displacement, raises the vertical position and calls its update helper. Meaningful position/displacement temporaries preserve native floating-point operand order. Unary 001BF6A0 comes from worker source receipt e0517cf9; its full ten-function source unit is independently replayed. Root expresses its scale constants as 1.01f and 1.0f, rather than raw integer bit patterns, with unchanged exact output. Actual helper prototypes are checked against reconstructed definitions or native parameter reads. The new 001A7500 declaration exactly matches its owner-pointer definition across source units.

No assembly, raw instruction rewriting, fake callee effects, volatile fields, or padding locals are used. No data progress is added by this batch.
