# Path resources and clone callbacks, 2026-10-21

This batch adds four exact callbacks totaling 3,248 CODE bytes and 3,540
reconstructed DATA bytes. Existing opaque neighbors and inter-bank gaps stay
uncredited. The fixed CODE publication grid is unchanged.

## Clone and contact callbacks

| Function | Bytes | Recovered behavior |
| --- | ---: | --- |
| 0x00355CA0 | 988 | Clone fields, mode-dependent action setup and per-player state update |
| 0x003564A0 | 712 | Clone fields, random position/velocity selection and facing changes |
| 0x00357010 | 656 | Clone fields, indexed motion profile and linked-actor placement |
| 0x003663E0 | 892 | Grab/contact state transitions, target setup and owner/effect updates |

The clone copies retain the actual 49 aligned 32-bit words and repeated field
loads/stores. In 0x00357010, the originally captured owner and the later current
owner have distinct uses; collapsing them changes the source behavior. Its
mode-2 creator uses indices 0..7 into eight halfword pairs and eight four-float
motion records. The wider mode-1 creator selects a different callback and is
not evidence for extra records in these two views. No DATA credit is added for
those external tables by this CODE change.

The other callbacks retain signed timers, byte narrowing, real helper return
types, floating-point signs and native operation order. The player-counter view
uses its actual offset and a flexible array rather than an invented capacity.
The random setup's one-element float view matches the existing provider shape;
its indexed pair and velocity reads retain their actual masks. Unused macros
and declarations were removed only after proving object identity. No register
forcing, dummy helper arguments, clamps or alternate NaN behavior are added.

Native evidence separates the old uncredited 0x00366350 composite into a
140-byte dispatcher, four uncredited bytes at 0x003663DC, and the separate
892-byte callable at 0x003663E0. The callback has its own prologue and epilogue,
and its own pointer-table entry. Internal branch targets remain within their
owners. The following raw gap and already credited function at 0x00366760 are
unchanged. The text denominator remains 3,293,696 bytes.

## Fixed-point motion and attachment poses: 600 bytes

The old raw owner at 0x00449460..0x0044A0A0 becomes a 2,304-byte raw prefix,
192 bytes of motion records, 408 bytes of attachment poses and a 232-byte raw
suffix. Four existing descriptor pointers now refer to byte offsets in the
retained raw prefix. Their numeric values and 16 prior credited bytes are
preserved; the retired word-array provider has no remaining C reference.

The motion table at 0x00449D60 contains eight six-word records. Native signed
conversion and division by 65536 establish fixed-point x/y velocities,
acceleration terms and the amounts subtracted from those terms on each update.
Horizontal values receive the actual facing sign and 5/3 scale; vertical values
receive the 15/7 scale. Negative decrements retain the native subtraction.
Every word has a direct consumer. The physical selector contract is 0..7;
the native reader has no local upper guard, and no universal state bound is
claimed.

The table at 0x00449E20 contains 68 natural six-byte records: signed halfword
x/y offsets and signed-byte facing XOR/layer fields. Its effective index is
4*parent_phase + child_slot. The native child slot is locally checked below
four; the physical combined-index contract is 0..67. Large signed offsets
remain full signed values through the native arithmetic; no bitfield masking
is invented. The eight bytes before the distinct 0x00449FC0 table remain raw,
as does the rest of the suffix.

An important native detail is preserved in the evidence: this reader loads the
parent phase with LB and compares it against positive 128. That equality is
unreachable after signed-byte extension. There is no separate zero-phase test.
The earlier helper checks a parent state-map difference, not a global bound on
this phase. Neither an unsigned sentinel fix nor a new runtime guard is part
of this DATA reconstruction. The frozen initial receipt's mistaken description
is corrected by a separate immutable addendum.

## Twelve interpolation paths: 1,500 bytes

Twelve XYZ point arrays occupy the old raw 0x0045F1D0..0x0045F7A0 owner. Three
contain 21 points each; nine contain six points each. Their natural float3
payloads total 1,404 bytes. All 84 bytes between arrays remain separate raw
objects, without a claim that they are original alignment.

The pointer directory at 0x0045F7A0 contributes 48 typed bytes and retains all
twelve retail addresses. The matching count directory at 0x0045F7D0 contributes
48 bytes, including 32 formerly residual bytes before the next owner. Counts
are 21,21,21 followed by nine sixes. The unchanged shared three-float vector
type is reused; no new header is needed.

Reader 0x0033EB00 uses a 12-byte stride and previous/current/next XYZ samples.
Its three weights are 0.5*(1-t)^2, 0.5+(1-t)*t and 0.5*t^2, with t derived from
the frame timer divided by 50. It resets the timer at 50 and the cursor to one
when the advanced cursor plus one fails the comparison against the count.
The ordinary direct-read contract is mode 0..11 and cursor 1..count-2. The
observed creator initializes cursor one and modes zero/one; this does not claim
that every physical path executes or that arbitrary later mutation is safe.
The separate halfword selector rooted at 0x0045F180 is unchanged and uncredited
by this work.

## Three coordinate-pair banks: 1,440 bytes

The old raw 0x00471C30..0x004721D0 owner becomes three 60-row float-pair arrays,
480 bytes each. Existing `F32Pair {x,y}` is reused. Native initialization bodies
within the 0x00393500, 0x00393B80 and 0x003941E0 dispatch regions select by a
resource identity byte, scale it by eight and read both components. The pairs
form linked-object target X/Y coordinates in shared state; Y then feeds actor
placement, while X participates in the interpolation/velocity path.

Physical indices are 0..59. Ordinary character identities 0..58 support normal
use; the homogeneous zero row 59 is not claimed as a sentinel or padding.
There is no local guard. An upstream mask-selection algorithm can structurally
produce values through 63, and complete reachability of those values remains
unresolved. Index 63 can cross these owners. This DATA change preserves every
retail byte and introduces no callback C or clamp; a future reader recovery
must preserve the actual neighboring-byte behavior rather than assume a new
universal range restriction.

## Validation

Independent reviews and fresh compilation cover all new or changed objects.
The cleaned CODE objects remain byte-identical to the frozen worker objects.
Old source/object pairs outside the scoped edits and all prior headers are
checked against the published baseline. Publication requires catalog checks,
the project test suite, fresh splitting, hybrid linkage and both full retail
image hashes. The hybrid still contains native fallback, so image identity
does not imply complete source decompilation.
