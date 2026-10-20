# Remaining local helper repairs

Nine source units now use the native helper behavior rather than incomplete or unrelated substitutes. Existing credited callers remain exact after independently replaying each entire source unit with its production compiler recipe.

| Source | Local native helper | Corrected behavior |
| --- | --- | --- |
| m11, y8_c | 00191F50 | clamp actor y to floor + 34.28571319580078125 |
| r1l | 002B5100 | use the native negated less-than-or-equal test, preserving unordered behavior |
| s2m | 003F1530 | return the incoming file header, rather than an unrelated global |
| v3_a | 001CB680 | copy the complete entity state from the supplied owner |
| v7_a | 002CFA20 | reset the full command state and increment the per-player table entry |
| w174_h, w178_a | 00150520 | store the three vector components at +0x78/+0x7C/+0x80 |
| w190_c | 002555E0 | update command state based on the signed timer at +0x2B8 |

Native disassembly confirms the identity accessor, vector stores, and negated comparison. The floor clamp, complete entity copy, command reset and timer-state logic agree with existing verified same-address implementations. The v7_a unit requires the compiler's small-data threshold 8 profile; all fourteen existing selected functions pass with that profile. The other eight units retain their existing production recipes. Local helper variants that are semantically complete but have different compiler instruction layouts receive no extra matching credit.

The nine source snapshots and every selected caller's independent verification receipts are retained privately. This change adds no code credit; it makes the existing C dependencies truthful. Two separate null-initialized callback pointer slots at 0043CD08 and 0043CD0C add eight reconstructed data bytes, supported by native stores, loads, and indirect calls. No callback signature is inferred for CD0C, whose callers use different prototypes. The unknown preceding gap remains unclaimed.
