# Action and motion data, and callback interface repairs

This batch reconstructs 4,979 initialized DATA bytes. The action-bank gaps,
motion-bank tail, and five-byte character-map tail remain raw and uncredited.
Seven new CODE bodies add 2,528 bytes; a separate 460-byte credit withdrawal
leaves a net 2,068-byte CODE gain. These are accounted for independently.

## Action streams: 2,152 bytes

The old raw owner at 0x00455C00..0x00456670 becomes seventeen action streams
containing 269 eight-byte records and seven raw intervals totaling 520 bytes.
The shared `Mvc2ActionRecord` has four byte fields (delay, mode, source frame,
copy count) followed by a signed 32-bit cursor stride. The two native parsers
at 0x0028D810 and 0x00294B20 consume every field. Positive-delay holds and
backward jumps are retained; signed cursor movement is not rewritten as an
unsigned array index. The examined streams have no zero-delay infinite cycle.

Twenty existing code units now use declarations compatible with the providers
and explicit byte views where the parser interface requires them. Two existing
four-pointer directories retain their 32 credited bytes and the same eight
retail pointer values into raw storage. Their raw target bytes gain no credit.
The header is included by exactly those twenty code units and seventeen new
stream units. All pre-existing headers are unchanged.

Removing an unsupported third parser argument required preserving the genuine
byte increment expression in two callers. No dummy input or register-forcing
argument is retained. A separate one-line declaration repair in `float_clamp.c`
keeps its complete old object byte-identical. This is scoped source compatibility
work, not a claim that every historical parser declaration has been recovered.

## Phase durations: 32 bytes

The signed halfword bank at 0x004646C0 contains sixteen durations. Its native
lookup increments and narrows a phase byte before indexing. Physical valid
post-increment indices are 0..15; the examined constructor and normal update
path use phases 0..9. No clamp or universal animation-state bound is introduced.
Unused homogeneous entries remain part of the typed bank. Neighboring callback
storage at 0x004646E0 is unchanged.

## Motion resources: 331 bytes

The 336-byte raw owner at 0x00463B30..0x00463C80 becomes six source units:

| Address | Typed bytes | Recovered format |
| --- | ---: | --- |
| 0x00463B30 | 80 | Five float records containing x velocity, x acceleration, y velocity, y acceleration |
| 0x00463B80 | 48 | Twelve horizontal progress offsets |
| 0x00463BB0 | 59 | Lead-actor state offsets, added to animation state 0x25 |
| 0x00463BEB | 0 | Five raw bytes, excluded |
| 0x00463BF0 | 16 | One fixed motion coefficient record |
| 0x00463C00 | 128 | Sixteen X and sixteen Y spawn offsets |

The coefficient reader at 0x0036C380 uses a 16-byte stride; another reader at
0x0036D550 starts at interior address 0x00463B50 and uses the latter three
records. These views establish the common format without uniquely recovering
whether the original declaration was one array or two adjacent arrays. Valid
local selectors are 0..4 and 0..2 respectively. The fixed BF0 provider retains
the exact four-member `MotionCoefficients` interface used by 0x0036C740.

The progress-offset readers require direct indices 0..11; a separate state-12
path does not read this array. Actor-map identity is 0..58. Both scatter indices
are masked by 15 in native code. The five-byte tail is not claimed as five extra
character entries or as proven alignment.

An earlier private replay of unchanged `y6_d.c` omitted `-Op`. Replaying its
registered MWCCPS2 3.0.3 `-O3 -Op -sdatathreshold 0` recipe verifies all six old
functions and reproduces its cached object byte-for-byte; no source repair was
needed there.

## Seven-float motion rows: 2,464 bytes

The old 2,584-byte owner at 0x0045FBB0..0x004605C8 becomes 88 seven-float records
and a 120-byte raw suffix. The callback at 0x003413B0 uses a 28-byte stride,
first-triplet previous/current/next samples, a segment-time endpoint, and
second-triplet two-prior/prior/current samples. Neutral `sample[7]` member names
preserve that established format without inventing original resource names.

Main creation initializes selector +0x1E to one. Companion objects start at zero
through allocator clearing. Segment completion increments the selector by one;
the +1/+2 alternatives elsewhere increment frame counter +0x1C. The callback
resets the narrowed selector to one when new_selector+2 fails its unsigned
comparison against 0x59. Persistent selectors on those paths are 0..86, and the
maximum next-row first-triplet lookup reaches row 87. Other homogeneous fields
in row 87 need not execute to belong to its recovered record format.

Selector zero also reads earlier anchors outside this new owner. Actual loads
begin at 0x0045FB88; some words belong to the existing callback-pointer table
at 0x0045FB80 and are read as floats by the retail callback. Those mixed-use
words, the intervening gap, and all other preceding storage gain no new credit.
A future C implementation must model the actual separate anchors rather than
index negatively within the new array. The trailing 120 bytes also have other
native consumers and remain raw. Existing aliases retain their retail addresses.

## Conservative callback credit repair

Two formerly credited functions (0x0037B670, 152 bytes, and 0x0037AFC0, 308 bytes)
used an unsupported third cleanup-helper argument to reproduce code generation.
The owned cleanup provider at 0x0037B400 has a two-pointer interface; the native
event dispatcher does not establish a shared three-input callback contract.
Some leaf routines consume ambient argument registers, whose provenance remains
an unresolved separate frontier. Reading only two inputs does not by itself
uniquely prove an original historical parameter count, but incompatible current
provider/caller declarations cannot justify completed source credit.

The 460 bytes are withdrawn from the matching catalog. Truthful candidates remain
under `docs/nonmatching/`, unregistered and uncredited; native fallback bytes retain
the original function boundaries and image behavior. No provider is altered to
make an invented third formal parameter appear valid. The heterogeneous callback
directory preserves all numeric payloads with explicit storage casts; those casts
do not assert that an unknown ambient-register context is valid.

## Verification scope

Each new or changed source unit is freshly compiled and verified against the
retail image. Remaining exports in the four code objects whose bytes legitimately
change are checked against the complete registered function sets and sizes.
Other changed old code objects must remain byte-identical. Untouched source/object
pairs and all prior headers are checked against the published baseline manifest.
Publication additionally requires catalog tests, the project test suite, hybrid
linkage, and exact loaded-ROM and packed-ELF identity. Those image checks include
retail fallback and therefore do not imply 100% reconstructed source.
