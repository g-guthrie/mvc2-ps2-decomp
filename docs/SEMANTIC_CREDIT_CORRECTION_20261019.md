# Helper-dependent credit correction

Eight callers previously received matching credit while local static functions with native addresses had incorrect semantics, or while the genuine helper exposed a caller size mismatch. Their 1,360 bytes are withdrawn. The original candidates are retained privately; the native image supplies these spans until truthful matching C is recovered.

| Caller | Bytes | Source | Unresolved dependency |
| --- | ---: | --- | --- |
| 00291970 | 172 | t11_e | 00291800 reversed the facing predicate; genuine helper leaves caller 176 bytes |
| 00420AB0 | 80 | b10s_0_j | allocator helpers had unrelated semantics; genuine helpers leave caller 88 bytes |
| 00420B30 | 104 | r3_c | allocator helpers had unrelated semantics; genuine helpers leave caller 108 bytes |
| 003F3700 | 112 | w0_d | parser header helpers had unrelated arithmetic; genuine helpers leave caller 144 bytes |
| 0024C4F0 | 96 | n9 | 0024C590 was an eight-byte stub in place of a 176-byte native helper |
| 003AE390 | 268 | q9_f | 003AE2C0 was an eight-byte stub in place of a 172-byte native helper |
| 00147E50 | 256 | z12_b | 00147D20 was an eight-byte stub in place of a 296-byte native helper |
| 00193210 | 272 | w1710_i | 00193180 used +1 for case 1 instead of +80; caller is 268 bytes under its existing recipe |

A relocated caller-byte match alone cannot establish the truth of its local C dependencies. The three stub-dependent callers above matched with the incorrect helpers, so they remain withdrawn even though the old caller bytes matched. No verifier has been weakened. The callers and unused local helpers are removed from production sources; the two sources with no remaining credited callers and their build recipes are removed. All remaining selected functions in the six retained source units have been independently recompiled and checked with their existing production recipes. Coverage validation confirms every remaining production body is registered.

The 96-byte caller at 0024C4F0 is now restored in its own source unit. Its real 176-byte helper at 0024C590 was already fully matched in x5_e; the caller uses an external declaration rather than a local substitute. The completion function 00126400 takes no argument: its complete native body and existing m2c source read global state, and overwrite a0 before using it. Correcting that interface yields the exact 96-byte caller under the existing modern MWCC O3/G0 profile. The other n9 functions retain their original source and profile; helper credit is not duplicated. The other seven callers from the table remain withdrawn (1,264 bytes).
