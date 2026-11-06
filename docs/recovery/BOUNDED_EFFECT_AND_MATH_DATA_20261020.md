# Bounded effect data, math constants, and SJ interface

This checkpoint adds 620 initialized-data bytes after retaining existing
credit exactly once. Unknown neighbors, alignment gaps, and raw buffers
remain uncredited.

| Recovery | Net new bytes | Type and extent evidence |
| --- | ---: | --- |
| Cosine kernel constants | 104 | Seven original double symbols and six native-loaded literals |
| Float pi reduction scalars | 40 | Ten original four-byte local objects in an exact owner section |
| Float logarithm scalars | 44 | Eleven original four-byte local objects |
| Double power arrays and scalars | 240 | Three whole double[2] arrays and 27 scalars; prior 24 bytes retained |
| Effect scale lookup | 64 | Constructor starts at 0; callback reads 0..15 and stops at 16 |
| Effect ramp lookup | 44 | Three constructor/callback paths read0..10 and stop at 11 |
| Fixed position vector pair | 24 | Two independent three-float native loads |
| Additional fixed position | 12 | Three float loads into an effect's x/y/z fields |
| Complete SJMEM interface | 48 | Twelve pointer slots, actual constructor base, and method contracts |

The scale lookup coalesces three raw fragments and an eight-byte catalog
gap into its full 16-float extent; eight following bytes remain raw. The
ramp lookup has 11 floats, preserving its 20-byte prefix and 148-byte suffix.
The two fixed vectors retain their intervening gap and surrounding raw
bytes. Their new source types follow native reads and bounded lifetimes,
rather than assuming that a label or numeric pattern defines an array.

The power tables use the original complete bp[2], dp_h[2], and dp_l[2]
objects. Earlier scalar fragments and raw tails are replaced by those
arrays. A legacy trig helper ends eight bytes earlier so it no longer
includes bp[0] from the next owner. Existing values remain represented
once; no duplicate progress is added.

The original math functions and their complete anchored readonly sections
match retail. Original named local objects are supported by source types
and cached ELF sizes/offsets, including constants materialized as instruction
immediates instead of loaded from their stored copies. Unnamed literal-pool
objects require direct native loads. Every changed/new standalone data
object is independently compiled and verified across its full span.

## SJ interface consistency

The 48-byte table at 0x004908C8 is one complete interface, with three null
COM slots followed by nine methods. Its layout follows the native pointer
words and constructor, with the API contract documented in the
[pinned SJ header](https://github.com/crowded-street/3s-decomp/blob/be9b9bc69dc19822a8eca9ce3e72ba560d5a3835/include/cri/sj.h#L123-L152).
The old 36-byte jump-table placeholder covered only its method tail and is
retired. The 2,256-byte raw prefix remains untyped; the original 2,268-byte
physical-zero inventory is unchanged, including the three null slots.

Eight existing method definitions now agree with the interface signatures.
The coordinator rebuilt all 15 affected code units and verified 612 existing
whole functions, plus all four affected data objects. The source include
closure was checked recursively. An unregistered duplicate reset candidate
was removed after preserving it privately. UngetChunk has a native table
entry and header contract but no reconstructed C definition; it gains no
code credit. These interface repairs add zero code bytes.

Combined linkage passed, and all 71 pending typed entries are now complete.
The hybrid ROM and packed ELF are byte-identical to retail (3,941,760 and
3,942,320 bytes respectively). All 95 tests pass. Data coverage is
243,140 / 648,064 bytes (37.5179%); code remains
2,053,084 / 3,293,696 bytes (62.3337%).

Before linkage, 15,038 unchanged source/object pairs and 44 unchanged
headers were checked against the preceding proof manifest. The changed
objects and two shared headers were independently rebuilt and verified;
13 superseded data units were retired. Gross pending typed data was 772
bytes, including 152 bytes already credited in the old object boundaries,
so the net increase is 620 bytes.
