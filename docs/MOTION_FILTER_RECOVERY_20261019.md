# Motion initializers and interaction-filter records

Four complete C callbacks add 1,336 code bytes under MWCCPS2 Version 3.0, runtime built November 26, 2001, `-O3 -Op -sdatathreshold 0`. They join the existing `payload_motion_initializers_001d3240.c` source unit.

| Function | Bytes | Native owner path |
| --- | ---: | --- |
| 001D9550 | 304 | 001D9260 -> 0044E820[1] -> 001D9760 -> 0044E850[0] |
| 001D8E10 | 324 | 001D8B30 -> 0044E7B0[1] -> 001D8FF0 -> 0044E7E0[0] |
| 001D5B80 | 356 | 001D56F0 -> 0044E500[1] -> 001D5D70 -> 0044E550[0] |
| 001DA290 | 352 | 001D9E00 -> 0044E890[1] -> 001DA440 -> 0044E8D0[0] |

Each outer dispatcher loads A1 from actor+0x18. The source declarations for 001D9760, 001D8FF0 and 001D5D70 now explicitly carry that second argument; 001DA440 already did so. The physical heads immediately before the initializer bodies select different tables from their actual runtime dispatchers, so table entries and argument flow are checked independently of physical adjacency.

The functions use the established 196-byte payload aggregate. Two apply facing-dependent motion and the other two clear motion, copy position, and add or subtract a displacement. A named float view preserves direct field accesses. Explicit position/displacement temporaries reproduce the observed floating-point addition operand order. No volatility, dummy storage, callee clobbers, fixed registers, assembly, or instruction patching is used. Both downstream two-argument update helpers have existing reconstructed definitions.

Worker receipt 3c9d7488 splits 00457C60..00457D60 into fourteen independently referenced interaction descriptors. Four-byte count/flag headers and bounded state-mask lists recover 174 bytes; all 82 opaque owner/residual bytes remain uncredited. The descriptor at 00457D10 has four transitions and a fifth terminal mask at 00457D20; raw tail begins at 00457D22. The descriptor at 00457D30 has five transitions and a sixth terminal mask at 00457D42; its raw tail begins at 00457D44. Direct references establish each record base, parser reads establish mask fields, and the independently compiled switch table starts at 00457D60. No general runtime index safety claim follows from this physical resource recovery.

Root validation recompiles all 44 split data objects, the complete six-function motion unit, and the complete composite-dispatch source unit, followed by loaded-ROM and packed-ELF identity checks, catalog validation, tests and build coverage.
