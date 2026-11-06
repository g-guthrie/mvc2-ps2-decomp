# Pose and velocity data recovery, 2026-10-21

This checkpoint adds 3,828 reconstructed DATA bytes and five exact actor
callbacks totaling 1,604 CODE bytes. Twelve raw bytes remain excluded.

## Relative pose records: 1,416 bytes

The old raw owner [0x0045C270,0x0045C800) becomes 177 natural eight-byte records
and an eight-byte raw tail at 0x0045C7F8. The adjacent callback table is unchanged.
Each record has signed 16-bit x/y offsets, an animation byte, a facing-flags
byte, a signed layer-order byte and an unsigned high-angle byte. Every field
has a direct native read; there are no padding fields.

The reader is 0x003001B0. It uses the current actor's byte +1 for identity and
the linked actor at +0x1DC for a signed byte +0x160 variant. Its combined index
is 3*actor_id + signed_variant%3. The separate 0x003001A0 relationship shim does
not forward to this reader. Native actor initialization and the existing handler
directory support the valid 59-actor domain; three variants give 177 records.
The flat source array preserves signed remainder behavior, including possible
negative remainders. The exact physical-bank precondition is combined index
0..176; ordinary within-group selection additionally requires remainder 0..2.
No clamp, unsigned rewrite or universal caller-domain proof is introduced.

All 59 variant-zero records are zero-valued but belong to the uniformly indexed
schema. The extra eight bytes beyond the 177-record domain remain raw; their
original role is unresolved. Original source bounds versus a possible unused
extra record or alignment are not claimed to be uniquely recoverable.

## Velocity profiles and directory: 2,412 bytes

The 2,400-byte bank at 0x0044CF30 contains three profiles, each with 25 frames,
four phases per frame and two float velocity components per phase. Three native
pointer roots select bases 0x0044CF30, 0x0044D250 and 0x0044D570, each 800 bytes
apart. A following callback table starts at 0x0044D890. The constructor produces
profile selectors 0, 1 and 2, then stores the selected profile pointer at +0xD0.
The directory at 0x0044D8A0 now stores those three typed pointers (12 bytes).
Its fourth zero word at 0x0044D8AC remains raw: an original null slot versus
alignment cannot be distinguished, and no consumed sentinel is claimed.

Sampler 0x001CADD0 increments and masks phase to 0..3. It forms a float-word
index 8*sample + 2*phase through byte +0xD7 before multiplying by four bytes.
The effective frame is therefore sample&31. The physical profile precondition
is (sample&31)<25, together with the observed phase range. The source animation
byte is adjusted/halved by its callers; no local guard or universal bound on that
source byte is claimed. The two floats become velocities at +0x5C/+0x60, with
facing-dependent x negation. This is a native typed layout and resource contract,
not a claim that every possible byte input is safe.

The existing constructor's directory declaration and stored pointer now use
the same profile-array type as the providers. Its whole object remains
byte-identical. No active old consumer or old reconstructed byte is displaced.

## Code and verification

| Function | Bytes | Recovered behavior |
| --- | ---: | --- |
| 0x00357390 | 324 | Signed flash/timer update, ordered landing test and three-float effect position |
| 0x0036C510 | 440 | Owner-relative initialization and facing-dependent wall correction |
| 0x0036D220 | 284 | Linked-actor position, facing and animation initialization |
| 0x0036E280 | 304 | Signed frame remainder, action reset and scale growth |
| 0x0036E5F0 | 252 | Fade/scale update, state transition and owner release |

Native ordered/unordered float comparisons and zero/NaN conditions are
preserved. The landing callback retains the native double state increment on
timer expiry. Its cleanup helper at 0x00357670 now has the actual unary object
input and forwards the actual Object* free interface. Only the named extern and
definition change in tail_leaves; all prior corrections remain. All 641 old
functions and the entire old object stay byte-identical.

All new complete data objects and five complete functions compile exact with
their registered production recipes. Independent review checked the DATA field,
index, extent and alias evidence; parent review checked the CODE native spans,
helper interfaces and float behavior. Direct/static alias checks do not prove
absence of arbitrary computed pointers or original translation-unit boundaries.
Private retail/compiler inputs and native dumps remain excluded from Git.
Aggregate publication requires unchanged-cache checks, tests, fresh splitting,
hybrid linkage and exact loaded-ROM and packed-ELF retail hashes.
