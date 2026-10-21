# Enforce source-credit rules and recover text helpers

The existing DECOMP.md rule excludes empty asm barriers used only to force
code generation and unused fixed-register locals. The catalog checker caught
whole assembly bodies but missed these constructs inside ordinary C bodies.
Six older credited functions (768 bytes) still contained them.

Three functions now match without their excluded constructs: 003FDA00 (96
bytes) and 003FDD28 (188 bytes) no longer need empty barriers; 003FDCD0 (84
bytes) uses an ordinary staged C temporary instead of an unread fixed local.
Its decrement, volatile observations and post-callback reload retain the native
behavior. The 003FDD28 recipe also disables sibling-call optimization; its
existing fixed locals are actually read and remain within the documented rule.
Three bodies, totaling 400 bytes, remain placeholders:

| Function | Source | Bytes |
| --- | --- | ---: |
| 004109C0 | w181_a.c | 108 |
| 0040D1D8 | w1912_b.c | 144 |
| 003FE258 | w192_c.c | 148 |

Their current objects can still replay retail exactly and remain wired into
the hybrid build. That machine-code equality does not justify C credit while
the source depends on the excluded workarounds. Clean candidates and failed
compiler-profile receipts are retained privately. Hardware primitives, real
compiler memory fences and fixed locals actually read by C or asm operands
are distinguished from the forbidden cases; this change does not impose a
blanket ban on every compiler extension.

The source-credit checker now selects function definitions with balanced
parentheses/braces, ignoring comments and literals. It checks only credited
function bodies in mixed units. Token checks detect empty/whitespace-only
asm and fixed-register locals used only as assignment destinations. Negative
fixtures cover both forms, mixed credited/placeholder units, quoted examples
and misleading function calls; positive fixtures retain hardware operations,
real memory fences and actual fixed-register reads. Five new tests extend
the suite from 111 to 116.

## New exact C

Three new complete functions add 384 verified bytes:

- 00421200, 100 bytes: prepare and submit a quadword packet tag.
- 00421C00, 156 bytes: select a text stream from the counter and shared state.
- 00421E70, 128 bytes: format a counter and draw it at the computed position.

Each has its own production MWCCPS2 3.0.3 recipe. The shared state is modeled
as its actual BSS word with a signed-character view for the native byte read;
an incomplete array is not used to disguise a scalar or force addressing.
The text-formatting routine uses an ordinary 200-byte buffer compatible with
the native reserved stack region, and the length result uses its unsigned
standard-library type. Both refinements retain exact native code. The buffer
size is a reconstructed implementation choice within that reservation; the
binary does not uniquely identify its original source spelling.

Four more complete functions add 872 bytes: two Sony cache-tag range routines
(164 bytes each), an actor color-start callback (276 bytes), and an actor
parent-start routine (268 bytes). The cache loops and address calculations are
C; short inline asm blocks implement required CPU cache and coprocessor
operations. The color callback is separated from its previously oversized
inventory span; the 48-byte dispatch head remains uncredited. The queue's
public pointer API remains opaque, with only the fields actually accessed
modeled in its internal prefix view.

## One complete serialized command stream

The record at 004A8F80 is now one complete 120-byte object rather than nine
separate runs. The native parser reads count one, consumes its preamble and
body, and stops at the NUL at 004A8FF7. The independent next root begins at
004A9000. The eight-byte intervening region, including the separately written
state byte at 004A8FF9, remains outside the object.

Eleven bytes are explicitly consumed by cursor advances but not loaded:
two after preamble command 0C and three after each of three body command-01
operands. They are opaque byte fields inside the complete command stream,
without invented integer interpretations. Consolidation preserves 109 already
reconstructed bytes and adds 11, rather than counting all 120 as new. The
source models record fields, command operands, glyph runs and terminator;
it is not a raw CPU instruction array.

## Five complete SDK strings

Five NUL-terminated strings add 222 reconstructed bytes: the ADXT parameter
error message and the AIXP, CVFS, SJRMT and SJX component banners. Native
references establish their starts. The ADXT message starts at 004BC818, eight
bytes before its former opaque fragment; the native null-parameter path uses
that complete prefix. Two opaque owners are replaced by five strings and six
padding fragments. The 30 padding bytes retain zero reconstruction credit.
Each string includes exactly its terminating NUL, with no alignment-tail credit.

## Validation and accounting

Fourteen changed or new code units receive independent whole-function compiler
proofs, covering 47 functions. The complete stream and all eleven SDK string
and padding units receive whole-object byte proofs. The cache audit pins 15,153
unaffected source/object pairs and all 47 unchanged headers against the prior
verified local checkpoint. Eleven old data owners are retired, eight existing
code owners are rebuilt and eighteen new source/object pairs are added.
Inputs stay frozen during all 116 tests, coverage/catalog checks, fresh split
and full relink/pack. All checks passed, including byte-identical reconstruction of both the
complete loaded image and packed retail ELF. The verified rows now receive
linked credit.

The verified checkpoint has code at 2,073,812 / 3,293,696 bytes (62.9631%) and
data at 255,836 / 648,064 bytes (39.4770%). Relative to the preceding local
checkpoint, code adds 1,256 new bytes and removes 400 unsupported old bytes:
a net increase of 856. Relative to the last published checkpoint, the new
code and prior local packet yield a net increase of 2,084 bytes; data adds 245.

The fixed next code publication threshold remains 2,080,510 bytes, with
6,698 bytes remaining. Corrections and extra publications do not reset it.


## Follow-up: remove the remaining unused thread-start local

003FE258 now matches at148 bytes under its unchanged production EE96 O2/G8
recipe after removing the unused fixed-register local k. The existing j local
is read by the actual thread-id condition. The post-callback volatile observation
now reuses j, preserving its load and native ordering without adding a fixed
binding, empty barrier, dummy use or manual padding. This retains the same
explicit distinction between used bindings and unused codegen destinations
as the earlier003FDD28 repair.

Only004109C0 (108 bytes) and0040D1D8 (144 bytes) remain quarantined:252 bytes
total. The148 bytes are restored source credit, not a newly discovered function.
The current118-test suite and both complete retail-image comparisons passed;
the restored148-byte function now receives linked credit.


## Follow-up: ordinary ring-accessor failure flow

0040D1D8 now matches all144 bytes without its empty asm. Both validation errors
call the real variadic logging function, then share one failure return. Its
successful path retains the original signed modulo16 and slot access. The
source uses no fixed register, artificial volatility or manual padding; the
production EE96 O2/G0 recipe is unchanged. The logging declaration agrees
with the existing const-char-pointer variadic provider.

Fifteen bounded source/profile probes retained the unsuccessful compiler
frontier. The shared failure-return source is exact under the unchanged
production flags. These144 bytes are restored credit for an existing function.
Only004109C0 (108 bytes) remains quarantined. Its latest scalar-copy candidate
is five of27 words off; ordinary aggregate and compiler-profile trials remain
uncredited. Neighboring credited functions in that unit remain untouched.

The144-byte accessor repair passed the current118-test suite and both full
retail-image comparisons; its source credit is now linked. The108-byte RPC
wrapper remains uncredited.
