# Effect spawn and motion data, 2026-10-21

The former raw owners [0x00460890,0x00460CB0) and [0x00460CB0,0x00460CC0)
now contain 1,044 reconstructed bytes and 28 bytes of uncredited raw gaps.
The adjacent reconstructed position table at 0x00460CC0 is unchanged.

| Address | Layout and native role | Bytes |
| --- | --- | ---: |
| 0x00460890 | Six groups of ten spawn points: kind and three float positions | 960 |
| 0x00460C50 | Five signed integer angles in degrees | 20 |
| 0x00460C70 | Five float pairs incrementing actor angles at +0x40 and +0x48 | 40 |
| 0x00460C98 | Three float acceleration components | 12 |
| 0x00460CA8 | Three float acceleration components, including word at 0x00460CB0 | 12 |

The group producer at 0x00344180 calls the constructor with selectors 0..5.
The constructor installs callback 0x00343770 and saves the selector at child
+0x20. That callback uses a 160-byte group stride and loops over ten 16-byte
records. It reads the first word as a kind selector. Kind zero calls the first
spawn constructor with subtypes 0..3; kind one conditionally calls the second
with subtypes 0..4 after comparing the third position component. Both spawn
constructors copy the three float positions to child +0x34/+0x38/+0x3C.
These operations establish the full six-by-ten record extent and five-entry
angle/rotation domain, rather than inferring types from float-looking words.

The paired rotation values increment actor words +0x40 and +0x48 after the
native degree-to-angle conversion. The acceleration consumers copy three
floats to actor +0x68/+0x6C/+0x70. The vector at 0x00460CA8 crosses the old raw
catalog boundary: native load +8 reads 0x00460CB0. Its complete 12-byte source
owner replaces that artificial split.

The gaps [0x00460C64,0x00460C70), [0x00460CA4,0x00460CA8), and
[0x00460CB4,0x00460CC0) remain raw. No original alignment or original translation
unit is claimed. Direct symbol aliases and aligned literal pointer words show
no conflicting view of the reconstructed region; arbitrary computed pointers
and universal indirect caller closure are not proven. The recovered extents
follow the native producer/consumer contracts and distinct neighboring bases.

All eight new data objects compile and verify exact under the existing
production MWCCPS2 3.0.3 recipe, without explicit alignment attributes. An
independent review also freshly compiled every source, compared the objects,
and checked native instructions against retail bytes. The full aggregate gate
checks unchanged source/object hashes, catalog coverage, hybrid linkage and
loaded-ROM/packed-ELF identity. Private input binaries and review dumps remain
excluded from Git. No additional CODE credit is claimed by this recovery.
