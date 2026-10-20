# Placement callbacks and interaction filters

Six complete callbacks add 2,284 exact code bytes under MWCCPS2 Version 3.0 (runtime built November 26, 2001), O3/Op/G0. Four are new placement/effect initializers; two are worker recoveries in the existing payload-copy source unit.

| Function | Bytes | Native entry pointer | Following update |
| --- | ---: | --- | --- |
| 001A79B0 | 404 | 0044B4E0 | 001A7B50 |
| 001BC7C0 | 404 | 0044C1B0 | 001BC960 |
| 001BE910 | 404 | 0044C420 | 001BEAB0 |
| 001AE370 | 356 | 0044BA30 | helper sequence 001E3210, 001754A0 |
| 001DDA20 | 308 | 0044EDC0 | 001DDC30 |
| 001C0A90 | 408 | 0044C770 | 001C0C30 |

Five consume A0 only and load their owner pointer from actor+0x18. The two-argument 001DDA20 receives its owner through native 001DD9A0, which loads actor+0x18 into A1, then 0044ED70[0] -> 001DDC60 -> 0044EDC0[0]. Exact dispatcher bodies and independently checked pointer words establish the native entries. Placement records contain signed 16-bit horizontal and vertical offsets, a signed pose byte and an unsigned animation byte: six bytes with no padding. Native multiplication by six and field reads at offsets 0, 2, 4 and 5 establish that layout. The first two initializers position from owner coordinates; 001BE910 adjusts the actor's existing coordinates. Compound assignments preserve its observed floating-point register allocation. The tables at 0044B470, 0044C0E0 and 0044C3C0 are referenced through unsized declarations; this callback recovery assigns them no data credit and establishes no universal runtime selector bound.

001AE370 is worker source receipt 332622c1, imported without replacing other root metadata. Its ordinary C uses the established 196-byte payload aggregate, facing-dependent owner offsets, an effect helper and animation selection. The second worker receipt fc292e0a adds 001DDA20; the entire twelve-function source unit receives root compiler replay. Root uses actual typed velocity/acceleration constants in place of raw word stores and a matching void-owner declaration for 001DDC30, retaining byte-exact output. The helper declarations match the existing reconstructed definitions.

001C0A90 uses a ten-byte effect-launch record at 0044C530. Native reads establish signed bytes at offsets 0, 1 and 2, signed halfwords at 4 and 6, and unsigned animation bytes at 8 and 9. The byte at offset 3 is natural alignment padding and is not read. No record data credit or selector bound is claimed here.

Worker data receipt 04bde9d6 splits 00458E70..00458F50 into twelve independently referenced interaction-descriptor regions. Typed count/flags headers and known selector-mask fields add 150 reconstructed bytes. All 74 owner/residual bytes remain raw and uncredited. The descriptor at 00458F00 has six transitions and seven masks ending at 00458F16; its following ten-byte gap stays raw. At 00458F30, only the known four-mask prefix is reconstructed; 00458F40..00458F50 remains raw. An independently referenced 80-byte compiler switch table starts at 00458F50. Catalog chunk size is not used by itself as an array-bound proof.

Root validation recompiles all 38 split data objects and both changed code units using production profiles, then verifies the complete loaded-ROM and packed-executable images. Catalog validation, regression tests, build coverage and shell syntax checks accompany the checkpoint. Near matches, opaque fields and alignment bytes receive no new credit.
