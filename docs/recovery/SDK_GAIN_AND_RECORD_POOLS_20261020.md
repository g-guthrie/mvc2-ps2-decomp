# Native gain curve and initialized record pools

Recover 5,088 initialized bytes with native type and extent evidence: a 1,000-word linear-gain table, sixteen 24-byte resource records, and eight 88-byte decoder-group records.

`func_0040EDE0` clamps the group's signed value to [-999,0]. The constructor, client-object field and callback registration identify the same group records consumed by `func_0040E008`. The callback performs the lookup even at -999, reading `0x0048DB98 - 4*value`; the full domain is therefore `[0x0048DB98,0x0048EB38)`. Every word independently matches floor(256 * 10^(-index/200)), corroborating Q8.8 gain semantics. The curve contains 482 nonzero values followed by 518 zeros. No later zero bytes are attributed to it.

The resource records occupy `[0x0048EB38,0x0048ECB8)`. Native initialization clears 384 bytes, uses a 24-byte stride, initializes the accessed pointer/word fields, and caps the configured count at 16. Allocation independently hard-stops at slot 16, while cleanup clears each full 24-byte record. The typed object has a byte used flag, padding to the pointer fields, three resource/interface pointers and two native words.

The decoder groups occupy `[0x0048FD38,0x0048FFF8)`. Constructor `func_0040E520`, callback `func_0040E008`, and reverse teardown `func_0040EC90` independently establish eight records at stride 88. The data definition follows the existing constructor's `DecoderGroup` layout. Callback registration belongs to `func_0040E288`; the constructor does not perform that registration.

The intervals `[0x0048ECB8,0x0048FD38)` and `[0x0048FFF8,0x004908D4)` remain raw, untyped and uncredited. All neighboring SJ data and aliases remain at their native addresses. The original physical-zero inventory remains intact; its coverage check verifies that the new typed and raw partitions cover the complete original range.

Every new or preserved data object independently compiles under MWCCPS2 3.0.3, -O3 -sdatathreshold 0 and matches the retail bytes. No new code credit is claimed. Existing owner source/object hashes remain unchanged; different-compiler probes are not substituted for the production recipes. Combined catalog, image identity, packed ELF and test gates precede promotion to linked data.
