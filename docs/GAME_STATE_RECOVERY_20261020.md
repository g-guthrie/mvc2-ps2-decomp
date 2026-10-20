# State, movement and partner recovery

Six complete game routines have independently verified production objects under MWCCPS2 3.0.3 `-O4,p -sdatathreshold 8`:

| Function | Bytes | Native behavior recovered |
|---|---:|---|
| 0x00310220 | 324 | Three state transitions, small-data pointer selection and motion initialization. |
| 0x0022D210 | 352 | Three transitions conditioned on a subrecord flag, selected state byte, pointer and shared cleanup. |
| 0x0022A410 | 280 | Timed movement/cleanup, target selection, hit setup and planar offset callback. |
| 0x002C8230 | 372 | Movement integration, one-shot target state, effect reset and landing cleanup. |
| 0x002E8920 | 348 | Separate active/grounded paths, native ground comparison and movement reset. |
| 0x002C3D50 | 344 | Partner linkage, positive/negative event paths, launch values and planar position callback. |

The two planar callback locals have 16-byte alignment, matching their native stack addresses and the repository's existing `PlanarOffset` convention. The target-selection assignment is part of the conditional in 0x0022A410, matching its return-register branch and delay slot. The landing routine retains the actual field pointers saved across callbacks while using direct field expressions for integration; these correspond to the native memory operands and preserved registers.

The 0x002E8920 ground comparison is `position <= ground`, exactly as the native `c.le.s` instruction specifies, including unordered inputs. Its grounded path follows the landing block in the native control flow; explicit labels keep those paths clear without duplicating callbacks. The 0x002C3D50 positive event branch joins the common epilogue through its structured `else` rather than an extra early-return epilogue.

The 0x0022D210 state-byte reload/rewrite appears in native code. Its signed-byte conversion replaces the candidate's unsupported volatile read; no volatile qualifier, assembly, NOP insertion, fabricated helper or padding is used for any new match. Existing external helpers retain their own credit.

The untracked Grok originals remain preserved separately. The 0x00220D50 candidate is held: native evidence corrects an early-exit case and establishes its real two-argument mask helper, but the complete instruction sequence still differs. No portion of that pending caller is credited.
