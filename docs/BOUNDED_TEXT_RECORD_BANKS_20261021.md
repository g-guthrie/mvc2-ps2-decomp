# Complete byte-indexed text record banks

Two native text-rendering lookups establish complete 256-entry banks of
four signed 32-bit components at 004A6F80 and 004A7F80. Each bank occupies
4096 bytes. The primary bank previously had 37 fragmented source owners,
with 1536 reconstructed bytes and 2560 placeholders. The secondary bank was
one 4096-byte zero-valued placeholder. The two complete typed arrays add
6656 reconstructed bytes; the previous 1536 bytes are counted once.

## Native layout and bounds

Both lookups are in func_00422150, spanning 00422150–00422740. Root pinned
all 380 instruction words in that span to the retail image before examining
the paths. The general text byte is loaded unsigned at 004223C4. Non-command
bytes reach the primary-bank lookup, where 00422580 masks the byte to 0xFF
and 00422584 multiplies it by 16. The subsequent loads read all four words
at offsets 0, 4, 8 and 12. Byte 255 reaches the final primary record at
004A7F70, ending exactly at the separate secondary bank at 004A7F80.

For command byte 10, the following byte is loaded unsigned at 004224F0;
004224F8 multiplies it by 16 and the secondary bank is loaded at
00422500–0042250C. There is no narrower selector check on that following
byte: row 255 ends at 004A8F80, immediately before an existing independently
reconstructed timeline owner.

The lwc1 instructions initially move integer bit patterns through floating
registers. They do not establish floating-point table elements. Each of the
four lanes is subsequently converted with cvt.s.w before division by 512
(primary: 004225D8–004225E4; secondary: 00422530–0042253C). The declarations
therefore use signed integer components. The four precise human field names
remain unknown; the source retains component0 through component3.

The secondary bank's zero initializer represents a proven 256-record typed
object. Its capacity comes from the byte domain, record stride and complete
field access, together with the independently bounded next owner. It does
not come from guessing the size of a zero-filled buffer.

## Consolidation and verification

The primary bank is one logical array; its previous partially recovered
fragments are retired. A source-reference scan confirmed no old fragment
symbol is used outside its own data helper. The source-derived address map
is regenerated after consolidation. Thirty-eight old source owners become
two complete source owners, reducing the object count by 36. No code unit,
compiler recipe, header or runtime behavior changes.

Both new whole 4096-byte objects are independently compiled with the
production MWCCPS2 3.0.3 profile (-O3, threshold zero) and checked with the
strict standalone whole-symbol/whole-section data verifier. Before the
combined image gate, 15,166 unaffected cached source/object pairs and all
47 headers were pinned to the preceding verified checkpoint. The 38 retired
owners were checked against that checkpoint; the new objects receive their
own compiler and retail-byte proofs.

The metadata loader fixture now names the complete banks and checks their
actual source, kind, address and full size. The retired raw-fragment names
are obsolete. Existing negative checks against arbitrary data slices remain
unchanged.

## Checkpoint accounting

Code remains 2,071,728 / 3,293,696 bytes (62.8998%). Reconstructed data reaches
255,591 / 648,064 bytes (39.4392%). The code publication grid is unchanged:
2,080,510 bytes is next, with 8,782 bytes remaining. Publishing this data
checkpoint does not reset that grid.

The combined validation requires all 111 tests, build/catalog checks, a fresh
split, full hybrid ROM identity and packed-executable identity. Expected
SHA-256 hashes remain:

- ROM: c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f
- Executable: 48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7

Retained code/data placeholders remain uncredited even when the hybrid image
matches retail. Neither native consumer receives new C credit in this change.

All required checks above passed on the canonical checkpoint. The gate
verified frozen source/configuration/test/tool inputs before accepting both
complete retail-image hashes. No compiler or private retail file is published.
