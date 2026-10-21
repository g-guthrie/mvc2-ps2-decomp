# Actor cycles and resource formats, 2026-10-20

This follow-on to `25cb2846` adds 4,224 whole verified code bytes in eleven
functions. Local linked code reaches 2,053,084 / 3,293,696 bytes (62.3337%).
It is a separate import from the preceding fixed-threshold batch; publication
and the existing threshold grid remain the coordinator's responsibility.

| Functions | New bytes | Production recipe |
| --- | ---: | --- |
| 001CCF60, 001CD130, 001CD320, 001CD520 | 2,124 | MWCC 3.0, O4,p/G8 |
| 001B8B70, 001B9480 | 676 | MWCC 3.0, O4,p/G8 |
| 001B8B40, 001B9450 dispatch entries | 80 | MWCC 3.0.3, O3/G8 |
| 003B47C0 launch variant | 588 | MWCC 3.0, O4,p/G8 |
| 00415020 resource loader | 280 | MWCC 3.0.3, O3,p/G8 |
| 00415F30 palette format builder | 476 | MWCC 3.0.3, O3/G8 |

The actor cycle source groups four adjacent implementations with common real
motion and signed timer/count fields. It retains the inherited 196-byte
aggregate, parent-identity checks, sixteen-tick transitions, mirrored offsets,
and velocity-reversal tests. Conditional negation preserves the native NaN
and signed-zero behavior; it is not replaced by a different absolute-value
operation. Call declarations agree with the existing animation definitions.

The two state setup callbacks are rooted by native tables 0044BF10/0044BF60.
Their dispatcher entries and callback bodies are now separate complete
functions. Sixteen trailing zero alignment bytes remain uncredited gaps;
integer and coprocessor branch/jump scans and absolute-word scans found no
alignment targets. The fixed text denominator is unchanged. The existing
constructor source was rebuilt after correcting the two actor parameters.

003B47C0 uses signed halfword x/y records and actual float velocity fields.
Its zero assignments use float lvalues. The unchanged production verifier
checks the complete generated 24-byte switch table at 004B8780, in addition
to all 588 text bytes. This adds no initialized-data credit.

00415020 walks typed sixteen-byte resource records, checks signed byte free
markers, maintains the 4,096-entry packed-handle table and 256-entry tag table,
and preserves the native failure ordering. Its descriptor loader returns an
integer handle. 00415F30 constructs the native 72-byte palette format record
for sixteen or 256 colors and sixteen-, twenty-four-, or thirty-two-bit
entries. Signed sixteen-bit image dimensions keep their product within a
signed word; output palette byte counts are bounded by 1,024. Neither match
uses undefined arithmetic or artificial volatile fields.

All seven changed/new compilation units passed complete relocated-object
verification with their production recipes. The other 14,066 cached
source/object pairs and all 46 headers remained unchanged. A fresh split,
full loaded-image link, packed-ELF check, and all 95 tests passed. The ROM and
ELF retain the retail SHA-256 identities recorded in the preceding recovery
document. No initialized-data catalog, label registry, `u3_k.c`, `L0_e.c`, or
generated progress graphic was changed.

Unmatched candidates, including 003B42F0, 003C4D30, 001B16F0, and the image
format builder, remain uncredited. Earlier frozen objects and receipts are
preserved independently of this batch.
