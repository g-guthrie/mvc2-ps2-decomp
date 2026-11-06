# Phase setup, serialized resources and bounded renderer data

This checkpoint adds eight whole C functions (2,208 bytes) and 159 initialized
data bytes. Local verified totals are 2,071,728 / 3,293,696 code bytes
(62.8998%) and 248,935 / 648,064 data bytes (38.4121%). The fixed next code
publication threshold stays at 2,080,510 bytes, with 8,782 bytes remaining.

## Code

Four inherited phase callbacks and two actor setup routines preserve the
native state transitions, owner arguments, linked-list traversal, signed
fields, float operations and bounded masked table accesses. Existing
reconstructed float/vector objects retain their actual declarations.

Two serialized-resource lookup routines replace handwritten assembly with
normal C. They use the existing 16-byte ResourceRecord where applicable and
a separate genuine 12-byte directory record. Serialized payload offsets are
added using 32-bit target address arithmetic: their destination can lie
outside the directory's C array object. Pointer return types and the real
short-pointer copy contract are propagated through three existing callers.

The obsolete assembly owner k0a.c and its build stanza are removed. Two
native table-rooted entries have 16 leading alignment bytes; those bytes
remain uncredited. The root checked their zero words, native table roots,
and all cataloged direct code branches/jumps and initialized data pointers
for entries into those gaps.

Seven production code units independently reproduce all 25 registered
functions, including existing callers. The new code uses existing compiler
profiles: legacy MWCC -O4,p with threshold eight for actor setups, modern
MWCC -O3,p with threshold zero for serialized lookup routines, and the
existing caller profiles. No verifier or compiler flag is changed to force
a candidate to match.

## Data

| Object | Bytes | Complete extent evidence |
| --- | ---: | --- |
| Fixed vectors at 0047713C and 00477158 | 24 | Fixed-address callers and a helper loading all three floats |
| Signed byte lookup at 0045EEA8 | 15 | Zero-initialized selector, one-byte signed loads, increment and reset at 15 |
| Actor compiler switch table at 004B5B30 | 24 | Six-case C switch, full exact anchored readonly section, six relocated words |
| Renderer resource codes at 004A6E70 | 16 | Four-word copy and exactly four loop iterations, word loads and native stores |
| Renderer positions at 004A6E80 | 48 | Three copied quads, four 12-byte records, all XYZ float loads/stores |
| Renderer float pairs at 004A6EB0 | 32 | Two copied quads, four eight-byte records, both float loads/stores |

The renderer routine at 0041D6E0 copies three separate banks to local arrays.
Its loop starts at zero and runs at most four iterations; allocation failure
returns before that iteration's read. Resource words become object fields
at +CC and +20, positions become +34/+38/+3C, and paired floats become
+50/+54. These complete native reads establish all three bounded objects.
The paired-float table joins the previous 24-byte raw tail and eight-byte
EC8 placeholder; the next owner at 004A6ED0 remains unchanged.

The signed-byte lookup's constructor uses the zeroing type-6 allocator and
an initializer that only links the object. Its callback reads the counter,
increments it and resets at 15. Both the initial state and reuse cycle support
the full 0..14 domain. The surrounding four-byte prefix and 121-byte raw tail
remain placeholders.

The compiler table belongs to the newly recovered actor setup C unit. Its
numeric-address placeholder helper is retired. It uses the strict embedded
switch-table verifier and hybrid placement support already on main; the
complete three-function owner and readonly section are checked, including
all neighboring bytes. No arbitrary readonly slice is credited.

The root compiled and independently verified all eight changed/new standalone
data units and the compiler-owned table. It also pinned 406 native instruction
words across eight relevant producer, consumer, helper and allocator functions
to the retail bytes before interpreting the data boundaries.

## Verification

The combined gate runs build wiring/catalog checks, all 111 tests, a fresh
split, complete hybrid linkage and packed-executable verification. Source,
configuration, tests and tool inputs are frozen for that gate. Before linkage,
15,189 unaffected source/object pairs and all 47 headers were checked against
the previous verified checkpoint; six old pairs were rebuilt and four old
source owners retired. New source units receive their own production proofs.

The complete loaded image must match SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`;
the packed executable must match
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Retained placeholders remain part of that hybrid identity and do not count
as reconstructed source.
