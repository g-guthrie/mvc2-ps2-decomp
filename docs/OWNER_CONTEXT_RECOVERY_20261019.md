# Owner-context and helper-source correction

This batch adds sixteen complete compiler-exact functions (6,320 bytes),
including ordinary aggregate payload copies, state transitions, a gate
predicate, and the pinned Newlib kernel cosine and sine functions. The runtime
units retain the Sun notices and strict full readonly-section checks; those
compiler pools remain uncredited data.

All 39 known C targets in the 00475CB0/00475D10 family, including its 00475CE0
subtable, now describe the actual actor/context argument contract. Dispatchers
forward the native context. Handlers that ignore context retain a genuine
unused argument rather than incompatible function-pointer casts.

The static 003C15F0 definition in m12b previously wrote an unrelated task pointer.
Its caller's instruction match did not validate that local helper body. It is
replaced by the actual coordinate helper: read the direction and quantized
short position, then update the float x position. The full 64-byte helper and
156-byte 003C1700 caller now independently match retail. The existing helper
credit moves from grok_r2_003c to m12b, and the old duplicate definition is
removed. Its static definition supplies genuine callee register-use knowledge.
The existing 8-byte 003C3A50 release wrapper similarly moves from the generic
tail collection to its actual actor/context interface and unary object release.
Neither ownership move adds code credit.

Coordinate recovery at 0044ED30 comprises ten signed (x,y) pairs, paired with
ten animation bytes at 0044ED58. The next independently owned callback table
starts at 0044ED70. The 16-byte prefix and 14-byte suffix remain placeholders.
At 004BF770, two coordinate pairs precede the four signed offsets at 004BF778.
Only four corresponding pose bytes at 004BF780 are reconstructed; the twelve
following bytes have a different unproved shape and remain placeholders. These
families add 70 bytes, with no claim of a universal runtime selector cap.

Root validation passed all 31 new or changed code units and every one of the
15 changed/new data objects and neighboring boundaries. Existing source,
object, and header hashes were checked before reusing compiled artifacts.
The rebuilt hybrid ROM and packed retail ELF match the pinned target hashes.
