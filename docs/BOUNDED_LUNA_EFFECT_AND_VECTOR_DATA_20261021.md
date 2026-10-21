# Bounded effect tables and complete vector objects

This checkpoint integrates twelve scoped Luna packets: 364 new data bytes
from the early effect range and 140 from the renderer range. The 19 typed
objects occupy 508 bytes, including four previously credited bytes retained
inside one complete vector. Net reconstructed data increases by 504 bytes.
Code gains no bytes.

| Objects | Extent proof |
| --- | --- |
| Signed setup values at 43F160 | Sole caller supplies precisely selectors 0 through 6; signed halfword loads |
| Ramp at 4452A0 | Two constructors initialize index zero; callbacks read indices 0 through 14 |
| Curve at 4455E0 | Initializer sets zero; callback reads indices 0 through 40 |
| Sequence at 445E20 | Thirteen valid callback IDs followed by FF; next-byte test terminates traversal |
| State callbacks at 440678 | Native constructor selectors and three complete function-pointer slots |
| Positions at 43E970 | Sole caller supplies 0 and 1; complete three-float rows |
| Scale/profile at 443DE0/443DF0 | Four-iteration loop and complete four-row V3 declaration/stride |
| Position at 443E20 | Three fixed native float loads |
| Seven fixed renderer vectors | Complete fixed float loads at offsets 0, 4, and 8 |
| Tables at 45F930 and 45F950 | Two native loops supply indices 0 and 1; twelve-byte stride |
| Runtime vector at 45F988 | Three fixed native float stores establish complete initialized object |

Seven renderer vectors are at 45E470, 45E47C, 45E858, 45E868, 45EB58,
45EE98, and 45FA18. The prior scalar at 45E86C is retained as the middle
field of its complete V3 object. The earlier 45EDD0/45EDE0 vectors and
45ED80 signed map are already credited and receive no duplicate credit.

The state-table constructor and dispatcher are established by native code;
they remain uncredited code bodies. Its two implemented handlers are exact,
and its third function pointer names a native function entry. Callback
sequence traversal starts at its actual first byte on every invocation;
FF is tested before another dispatch, regardless of earlier handler results.

The four-row profile retains its unused row 1 within the bounded complete
array. Its consumers use a separate fixed vector for selector 1 and the
profile for selectors 0, 2, and 3. The array credit follows the complete
source declaration and actual stride/maximum selector, including all fields.

The coordinator independently compiled and verified all 42 final data
objects, including 23 preserved raw partitions. It reverified all registered
functions in the matching owner units and checked 1,392 native instruction
words across 28 relevant function spans against the retail image. Nineteen
superseded baseline data units retire; no raw neighbor receives credit.

Before linkage, 15,150 unchanged source/object pairs and all 47 headers were
checked against the prior proof manifest. Eight old source objects changed;
new units have separate full-span compiler receipts. Source and catalog
changes were merged from immutable commits by scoped unit deltas, preserving
all unrelated canonical work.

The combined gate passed all 95 tests and catalog validation. Fresh loaded
image linkage and packed executable reconstruction match the retail hashes
exactly. These verified rows are now complete. Code remains
2,062,408 / 3,293,696 bytes (62.6168%); data is
243,924 / 648,064 bytes (37.6389%). This is a local checkpoint; the
fixed code-publication threshold remains 2,080,510 bytes.
