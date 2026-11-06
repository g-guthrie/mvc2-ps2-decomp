# Actor callback recovery

Four whole C functions add 1,080 verified bytes: 00384C40 (276), 002648F0
(288), 0017D270 (284), and 001C1160 (232). Native dispatch tables establish the
entry points, and full compiler/object comparisons cover every byte and
relocation. Three use modern Metrowerks O4,p/G0; 002648F0 uses the older
Metrowerks O3/Op/G0 profile.

The former residuals at 002648F0 and 0017D270 are complete callbacks with their
own native frame setup and return. Their entire existing inventory extents are
reclassified as C, preserving the surrounding spans and uncredited padding.
The already credited sixteen bytes at 0017D260 remain separately owned.

The new source retains meaningful native details: random state/action choices,
the ordering of state writes before calls, immediate return paths, signed-byte
checks, and pointer-based attachment dispatch. Callback 001C1160 supplies the
fourth 00175580 animation argument from the context byte's low nibble. The
callee's native shift at 0017558C consumes that argument as an eight-byte frame
index; omitting it was a real draft error.

Six local helpers in wave2b, y9_c, z2_a, x3_i, n8, and n9 now implement genuine
position, state-gate, clamp, vector, and copied-field behavior. Five helper
bodies verify independently. The y9_c body matches the canonical wave2 state
gate source, while its local compiler variant receives no additional helper
credit. All existing credited caller functions continue to match. An unused
fabricated 0030A450 duplicate in n0 is deleted rather than retained beside its
already owned canonical implementation.

Root verification covers eleven changed/new code translation units and five
independent helper spans. Fresh splitting, catalog validation, build coverage,
shell syntax, staged whitespace checks, and 57 tests pass. Unchanged source,
object, and header hashes were checked before artifact reuse. The final hybrid
ROM and packed retail ELF reproduce their pinned SHA-256 hashes exactly.
