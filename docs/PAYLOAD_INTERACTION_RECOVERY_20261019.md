# Payload callbacks and interaction descriptors

Seven complete C callbacks add 2,360 exact code bytes. Production profiles use MWCCPS2 Version 3.0, runtime built November 26, 2001, O3/Op, with the source unit's recorded small-data threshold.

| Function | Bytes | Native entry | Profile |
| --- | ---: | --- | --- |
| 001C1E10 | 336 | 0044CAA0 | G8 |
| 001A9720 | 336 | 0044B690 | G8 |
| 001CFBB0 | 356 | 0044DED0 | G8 |
| 001AF860 | 332 | 0044BBE0 | G0 |
| 001B11F0 | 408 | 0044BC88 | G0 |
| 001D3240 | 292 | 0044E090 | G0 |
| 001DEB20 | 300 | 0044EE50 | G0 |

The first five entries consume A0 only. Both motion initializers consume actor and owner pointers. For 001D3240, native 001D2C70 loads the owner from actor+0x18 and dispatches through 0044E070[2] -> 001D3220 -> 0044E090[0]. For 001DEB20, native 001DD9A0 loads the owner from actor+0x18, supplies it in the indirect call's delay slot, then selects 0044ED70[13] -> 001DECE0 -> 0044EE50[0]. The latter function's actual dispatcher lies after the body; the earlier 001DEB00 head belongs to another entry table. Source declarations for the two intermediate dispatchers explicitly preserve A1. Downstream motion helpers were checked against their recovered definitions.

The motion initializers use a named float view of the existing actor storage. This reproduces direct floating-point field accesses without the extra address calculation produced by repeated byte-offset casts. The representation changes no storage, volatility, callee effects, or instruction bytes by hand. The native payload is copied as the established 49-word aggregate; actual float vectors retain their three-component types.

The data recovery splits 0044F260..0044F2E0 into eight independently referenced 16-byte interaction descriptors. Each contributes a four-byte count/condition-flags header and four two-byte state masks: 96 reconstructed bytes total. The intervening four-byte owner-key/residual spans remain raw and uncredited, totaling 32 bytes. Native consumers independently address all eight record bases; the next compiled switch table starts at 0044F2E0. Parser 00189500 reads a mask at descriptor+8+2*stateIndex, including the fourth mask when the index reaches three. Existing callers include n2d.c, ordered_initializers.c, state_return_family.c and owner_threshold_latches.c. The symbol map is regenerated from the complete current data-source inventory, preserving other recovered families.

Worker source receipts: 8dfc5ecb and 1a2d098c for the unary callbacks, 37501474 for the interaction records. All changed code units and all 24 split data objects receive independent production compiler replay before root linkage verification. Near matches and opaque bytes receive no new credit.
