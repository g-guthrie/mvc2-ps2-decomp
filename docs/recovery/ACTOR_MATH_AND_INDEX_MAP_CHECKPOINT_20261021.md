# Actor code, mathematical objects, and a bounded index map

This checkpoint adds 9,324 exact code bytes in 21 whole functions and 280
initialized-data bytes. Code is 2,062,408 / 3,293,696 (62.6168%); data is
243,420 / 648,064 (37.5611%).

The code includes actor lifecycle and emission callbacks, camera setup,
patterned child spawning, steering, and kernel syscall-table discovery.
Complete native callbacks replace four explicitly sized residual inventory
rows with unchanged extents. The resource-loader callers now share the
actual 16-byte record layout and return/argument contracts. Native CPU
syscall operations retain the permitted inline primitives. See the focused
actor, steering/kernel, and resource-record documents for source details.

The coordinator independently rebuilt all 28 changed production code units,
verifying 1,750 complete functions and their relocations. Nine consumers of
the new resource-record header are included in that set. The other 46
headers and 15,108 unchanged source/object pairs retain their preceding
hashes. No child checkout's whole catalog was copied over canonical state.

| Data object group | Net bytes | Ownership evidence |
| --- | ---: | --- |
| Float power constants | 120 | Three original float[2] symbols and 27 original scalars |
| Double atan2 constants | 48 | Six original double symbols in the exact owner section |
| Formatted-output padding | 32 | Two original char[16] blocks and native bounded use |
| Renderer index map | 80 | Signed words, zero-initialized selector, native 0..19 cycle |

Power's earlier scalar fragments are coalesced into complete arrays. The
separate pre-owner float at ABB74 remains its own object, and all previous
credit is retained exactly once. The 48 atan2 bytes have original local
symbols and source types; native code does not directly load these six
addresses. Their whole owner code and read-only section match. Padding
blocks are fixed character arrays, with no claim that they are strings.
All 41 changed/new data objects were independently compiled and verified;
40 reconstructed entries totaling 296 bytes include 16 previously credited
bytes, yielding the net increase of 280. Six superseded data units retire.

The signed index map at 45ED80 is exactly 20 words. Its successful allocation
path (0,6,1) clears the full 0x1E4-byte object before initializer 1, which
only links list pointers. The constructor installs the callback without
changing its counters. The callback advances its map selector once every ten
ticks and resets at 20. This proves all reads lie within the map even for
reused slots; the proof is specific to this allocation and initialization
path. Adjacent V3 constants and raw spans retain their separate ownership.

Combined validation passes all 95 tests, catalog validation, and fresh
split/link/pack checks. The loaded image (3,941,760 bytes) and packed retail
ELF (3,942,320 bytes) are byte-identical to the target. Newly reconstructed
data entries are complete only after these gates. Unknown neighbors, raw
buffers, and gaps remain uncredited. The fixed next code-publication
threshold remains 2,080,510 bytes, with 18,102 bytes still required.
