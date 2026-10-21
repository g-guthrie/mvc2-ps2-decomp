# Context code, bounded renderer data, and SJ interfaces

This checkpoint adds 2,544 whole matching code bytes and 272 initialized-data
bytes. All newly matching entries are complete after the combined image gate below.

## Code

Five whole functions cover context-driven actor setup and input/motion state:
001DC460 (412 bytes), 001D1C10 (508), 003A3050 (740), 003AABB0 (484), and
003AB270 (400). Two previously explicit residual inventory rows are renamed
at exactly their original extents. No alignment bytes or new inventory rows
are included in those renames. The coordinator independently rebuilt the
five production units and verified all 1,467 registered functions.

The unused D45ED20 declaration in v11_b now agrees with the recovered matrix;
all four existing functions in that unit also remain exact. The separate
actor-context callback-table proposals remain unapplied while the actual
heterogeneous callback contracts are reviewed. A table declaration alone
cannot establish the function definitions' parameter types.

## Bounded game data

The 96-byte D45ED20 object is eight rows of three signed words. The existing
20-word map at D45ED80 selects rows 0..7. Its callback counter begins at zero
on the verified (0,6,1) allocation/initializer path and cycles 0..19. The sole
constructor caller group supplies columns 0, 1, and 2. The final possible cell
is at 45ED7C, ending at 45ED80. Twelve preceding zero bytes remain raw; the
already reconstructed map and neighboring vectors receive no duplicate credit.

The 32-byte signed lookup at 448FE0 uses the native random selector masked
with 31. Its signed byte load and separate following native object base prove
the complete byte map. The 192 following bytes retain their raw ownership.
The root independently rebuilt both new lookup/neighbor objects, checked the
original consumer source hash, and reverified both unchanged owner units.

## SJ tables and UUIDs

| Object | Address | Reconstructed bytes |
| --- | --- | ---: |
| Complete SJRBF interface | 490D78 | 48 |
| Complete SJRM interface | 494DA8 | 48 |
| SJMEM UUID | 4BE9D0 | 16 |
| SJRBF UUID | 4BEA10 | 16 |
| SJRM UUID | 4BEA20 | 16 |

Each interface has three null COM slots and nine SJ method pointers. Its
whole native extent follows the constructor-installed base and the
[pinned SJ interface definition](https://github.com/crowded-street/3s-decomp/blob/be9b9bc69dc19822a8eca9ce3e72ba560d5a3835/include/cri/sj.h#L123-L152).
The root checked all 24 pointer words independently. The former prefix and
method-tail placeholders are coalesced into complete interface objects.

Each UUID has the four API fields totaling 16 bytes, following the
[pinned UUID definition](https://github.com/crowded-street/3s-decomp/blob/be9b9bc69dc19822a8eca9ce3e72ba560d5a3835/include/cri/sj.h#L87-L95).
Native constructors store its address in record field +8, and the matching
GetUuid method returns that field. The mixed 194-byte owner is retained as
three complete UUIDs and three raw banner/prefix spans. Version banners and
padding receive no new credit.

Implemented method definitions and prototypes use the actual SJ_OBJ/SJCK
contracts, with typed implementation views inside the methods. The
constructors declare the actual UUID and interface object types and take
addresses explicitly. Interface initializers use function names directly,
without casts concealing incompatible signatures. Only minimal local API
declarations are added; vendor SDK source and toolchain binaries are not
part of this checkpoint. Unknown method bodies remain uncredited.

All 22 SDK-dependent production code units, covering 625 existing functions,
were rebuilt and verified whole. Eleven SDK data objects, including existing
record arrays and the SJMEM interface affected by the shared header, were
independently compiled and verified. The UUID follow-up's scratch CSV had
mislabelled simple_leaves as EE GCC; the coordinator used its actual MWCC
production recipe. These signature and declaration repairs add zero code bytes.

## Combined verification

Before linkage, the coordinator checked 15,142 unchanged source/object pairs
and 46 unchanged headers against the preceding proof manifest. Thirty-one
old source objects were independently rebuilt; nineteen superseded raw data
units retire. The changed shared header's project include closure was checked
recursively. Compiler receipts cover 2,096 whole functions across 28 changed
code units, plus 15 data objects (including retained raw partitions).

All 95 tests pass, and the fresh split, full loaded-image relink and packed
ELF reconstruction are retail exact. The ROM is 3,941,760 bytes with SHA-256
c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f;
the ELF is 3,942,320 bytes with SHA-256
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
Code is 2,064,952 / 3,293,696 bytes (62.6941%); data is
244,196 / 648,064 bytes (37.6808%). The fixed next code-publication threshold
remains 2,080,510, with 15,558 more verified code bytes required.
