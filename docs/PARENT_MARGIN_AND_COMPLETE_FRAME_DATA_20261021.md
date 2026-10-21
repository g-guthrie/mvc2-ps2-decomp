# Parent-margin callbacks and complete frame data

The three parent-margin callbacks at `001B16F0`, `001B18F0`, and `001B1B10` match their complete 508-, 532-, and 516-byte native bodies. They preserve the 196-byte inherited-state copy, repeated stores, actual helper arguments, signed margins, and native single-precision operand order. One signed margin supplies both mirrored boundary calculations. Existing shared headers and earlier matching callbacks remain unchanged.

## Complete coordinate tables

The initialized owners at `[004B3BD0,004B3C50)`, `[004B3CB0,004B3D30)`, and `[004B3DF0,004B3E70)` are each sixteen two-float records, 128 bytes. Every full region is a 4×4 grid of quarter-unit coordinates and ends at another independently referenced data base. Native readers use an eight-byte stride, load both components, and store them at actor `+E0/+E4`.

The observed frame controllers advance and clamp their route index at seven; another callback selects index two. Those routes exercise indices 0–7. Each complete physical array contains sixteen records, with the unchecked accessor requiring index 0–15. Reachability of the upper half is not claimed.

The eight signed-halfword parameters at `[004B3D90,004B3DA0)` are read at two-byte stride and copied into a child argument field. Safe access requires index 0–7. Fixed callers pass four; another caller obtains its index dynamically from `00451C60`, and that producer's complete range remains unresolved.

The ten float samples at `[004B3DC0,004B3DE8)` form a uniform-scale progression: `0.5`, six `1.0` values, `0.66`, `0.33`, `0.0`. The state routine reads frames 0–9 and copies each value to three scale components. Two separate eight-byte gaps, `[004B3DB8,004B3DC0)` and `[004B3DE8,004B3DF0)`, remain raw placeholders.

Within `[004B3BD0,004B3ED0)`, seven prior reconstructed owners retain their source content and 312 bytes of credit. The resulting partition contains 752 reconstructed bytes and sixteen raw bytes. The new DATA credit is therefore 440 bytes.

## Indexed word and frame tables

`[004B41E0,004B41F0)` contains four signed words, indexed by `00163760` and copied into actor `+44`. Its unchecked access requires index 0–3. Direct callers supply the actor's signed `+140` field; no global field invariant is asserted.

`[004B41F0,004B4228)` contains fourteen floats used by `00163120`. It reads a byte index, copies one sample to actor `+78/+7C/+80`, then increments that byte and advances the state at fourteen. The valid entry index is 0–13. Two previously uncataloged words at `4218/421C` belong to this consumed sequence. The eight-byte tail `[004B4228,004B4230)` remains a raw placeholder, and the independently owned table at `4230` is unchanged. These two typed owners add 72 DATA bytes.

The total addition is 1,556 CODE bytes and 512 DATA bytes. All eleven changed/new translation units are compiled with their registered production recipes and verified as whole objects. Unchanged source/object and header hashes supply cached proof, followed by full-image linkage checks. No raw gaps, near matches, or duplicate existing bytes receive reconstructed progress.
