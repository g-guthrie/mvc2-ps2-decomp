# Partner transition and frame parameters

`func_00366CA0` is a complete 356-byte match. It handles controller flags, a signed-halfword countdown, the partner transition and motion reset, and the fallback actor update. The call to `func_001E7F60` passes the actual actor pointer. `func_00179160` retains its provider's `void(void *, void *)` contract. The `+0x118` assignment and motion clears use float storage; whole-function verification remains exact with those types.

The float parameter array at `[0x004B4250,0x004B428C)` contains fifteen values:
`0, .25, .5, .75, 1, 1, 1, 1, 1, 1, 1, .75, .5, .25, 0`.
Native `func_00163880` uses unsigned byte field `+5` as its index, loads one sample, and copies it to fields `+0x78`, `+0x7C`, and `+0x80`. It then increments the byte and advances the state once the new byte is at least fifteen. The unchecked table read requires an entry index in `0..14`; this is a phase precondition, not a claim about arbitrary calls or writes.

The complete observed read domain forms one 60-byte `float[15]` owner. The preceding word at `0x004B424C` and following word at `0x004B428C` remain separate raw placeholders. The native label continues through the latter word, whose historical role as unused data or alignment is not established here. Its zero bytes receive no reconstruction credit. The catalog's previously omitted float at `0x004B427C` is part of the same native indexed sequence and is now included.

Three old placeholder fragments are replaced by the typed array and the two raw words. This adds 60 reconstructed DATA bytes and preserves eight uncredited raw bytes. Both source/type review and full-object compiler verification cover the complete owners; unchanged consumer source and aliases remain valid under the stated index precondition.

## Complete parallel frame tables at 004B3B70

The float parameters `[0x004B3B70,0x004B3BB0)` and signed-halfword delays `[0x004B3BB0,0x004B3BD0)` each contain sixteen entries. The dispatcher `0015AED0` selects handler `0015AEF0`; on its table-reading path it uses signed `field1C - 1`, skips reads at zero, and requires `field1C` in `1..16` otherwise. It stores the parameter into `+0x74` and the delay into countdown `+0x1E`. The constructor/update path starts at zero, advances the frame on timer expiry, and stops at seventeen. This supports the normal path and does not add a runtime guard or assert a global field invariant.

These two complete objects replace six fragments. Forty-eight bytes were already reconstructed; that credit is retained once. The remaining forty-eight bytes become reconstructed, so the 96-byte physical recovery adds only 48 new DATA bytes. The independent next pair-table base at `0x004B3BD0` is untouched.

## Additional target vectors and coordinate grid

The three-component target tables at `[0x004B3F80,0x004B3FA4)` and `[0x004B3FB0,0x004B3FD4)` contain three float vectors each. Their native readers load all components at offsets 0/4/8, either selecting the indexed path with selector 1–3 or cycling a separate byte index modulo three. The two following triples of 1.0 floats remain unchanged placeholders because their use is not established.

The coordinate-pair owner `[0x004B3FE0,0x004B4060)` contains sixteen pairs and ends at the independent child-frame table. Its reader `00162810` uses signed frame index times eight and copies the two floats into `+0xE0/+0xE4`. Its observed animation route advances and clamps that index at seven. The full physical owner remains sixteen records; this note does not claim that route selects its upper eight records. The unchecked accessor's in-range precondition is index 0–15.

These three complete owners replace eight placeholder fragments and add 200 reconstructed bytes. Alongside the sixty frame samples and the forty-eight newly recovered parallel-frame bytes above, the DATA addition is 308 bytes. Existing reconstructed coverage is preserved once; all unproven raw words and vector tails remain uncredited.
