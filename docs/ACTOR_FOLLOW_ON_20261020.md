# Actor lifecycle follow-on

Two whole callbacks add 1,136 code bytes: `001E0280` (592 bytes) and `001E0540` (544 bytes). Both reuse the existing inherited-state source and its genuine 196-byte copied region.

`001E0280` checks the parent's identity and lifecycle, initializes inherited state and movement, and follows parent animation state. Its native call at `001E0478` forwards the parent as the second argument to `003C9850`. The existing leaf definition now accepts that unused argument; its complete compilation unit remains byte-exact. There are no other existing C calls to that leaf.

`001E0540` follows the entity referenced by the parent, copies its inherited state, dispatches an animation event and applies a one-time random position offset. Each table index is masked to 0–7, supporting the two eight-float external views. No table data is reconstructed or credited. Display priority uses signed-byte operations and the native 0–7 clamp.

The lifecycle unit retains legacy MWCCPS2 3.0 `-O4,p -sdatathreshold 8 -i src`; the corrected leaf unit retains modern MWCCPS2 3.0.3 `-O3 -sdatathreshold 0`. Both whole units, all 33 existing/new functions, reproduce instructions and relocations exactly. This packet makes no function-boundary, readonly-section, DATA-source or data-catalog changes. Frozen private receipts record placement, executable hashes and tool-test results separately from compiler matching.
