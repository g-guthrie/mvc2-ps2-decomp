# Code recovery and ABI evidence, 2026-10-20

This independent code-lane batch starts at `6ce0e6ba` and adds 1,080 bytes
across eight complete compiled functions. No initialized-data credit changes.

| Entry | Bytes | Source | MWCCPS2 3.0.3 recipe |
| --- | ---: | --- | --- |
| 0032BDF0 | 204 | stage_select_input_0032BDF0.c | O3, G8 |
| 003D7350 | 176 | text_pool_append_003D7350.c | O3, G8 |
| 003B4120 | 284 | linked_effect_children_003B4120.c | O3, G8 |
| 00323610 | 60 | context_dispatchers_20261020.c | O3, G8 |
| 0034FB40 | 52 | context_dispatchers_20261020.c | O3, G8 |
| 00366090 | 52 | context_dispatchers_20261020.c | O3, G8 |
| 00368000 | 52 | context_dispatchers_20261020.c | O3, G8 |
| 00414E30 | 200 | initialize_runtime_tables_00414E30.c | O4,p, G8 |

`G8` means `-sdatathreshold 8`. Production commands are in
`tools/compile_matching.sh`. Each function passes whole-function relocated
byte comparison; this table excludes held candidates.

## Formatting return value and variadic arguments

The existing 84-byte helper `00122340` returns the `int` result of
`001209B8` (vfprintf). Native code uses V1 for the final FILE buffer pointer,
preserving V0. The newly recovered `003D7350` consumes this length to place
its final NUL. The helper and its two already credited caller units were
independently rebuilt after correcting the declarations. This repair adds
zero progress bytes.

`003D7350` has four named parameters: byte x, byte y, a byte attribute widened
to a halfword, and a format pointer. T0 through T3 contain its initial
variadic arguments. Its argument-list initialization follows the pointer
EABI definition in GCC 2.95.2's
[va-mips.h](https://github.com/gcc-mirror/gcc/blob/releases/gcc-2.95.2/gcc/ginclude/va-mips.h),
lines 81–86 and 113–117. The supported `__builtin_args_info(2)` reports the
named GPR argument count; the register-save slots are eight bytes. The C
expression uses these compiler interfaces instead of assuming a stack
offset. The earlier failing `args_info(0)` probe used a different operand.

Native code proves the record stride of 64 bytes, the count limit of 128,
the two coordinate bytes, the attribute halfword, and text beginning at +4.
The source represents that layout directly. `0032BDF0` passes five actual
arguments to this helper: x, 22, zero, the format string at 004B7668, and
the stage byte at 004C27D0. It reads pad halfwords based at 004C291C and
wraps the stage index modulo 17.

## Child allocation

`003B4120` creates an initial child and attempts five further allocations.
The callback at 003B4240 receives an actor pointer. Native stores in the
second loop deliberately address the first child at +88/+8C; the recovered
C preserves those stores.

An initial allocation failure leaves the pool unchanged: 003DA750 returns
NULL when signed count 004C27A4 is nonpositive; 003DA780 returns NULL when
signed count 004C27A0 is zero. These failure paths have no writes or
callbacks. Consequently a failed first call cannot become a successful
later call within this synchronous routine's own failed-call path. The
matching source does not depend on undefined behavior to force codegen.

## Dispatcher boundaries

The four recovered dispatch entries terminate at their computed tail jumps
and delay slots. Their former 64-byte residual ranges included trailing
alignment. Only the compiled 60/52/52/52 bytes receive credit; the remaining
4/12/12/12 zero bytes are recorded as gaps. The fixed text denominator is
unchanged. No static branch, jump, or stored absolute code pointer targets
those alignment bytes.

00323610 is rooted by the entry at 0045DE20. Existing exact constructors
0034FA80, 00365F60, and 00367F90 install the other three callbacks. Their
declarations now describe the actor parameter, and both affected constructor
units were rebuilt and verified. The three entries snapshot the parent
pointer before publishing their context pointers, matching native aliasing
and load order. The existing jtbl_00462460 binding is reused.

## Runtime initialization

00414E30 initializes 4,096 unsigned packed-handle words, 256 slots containing
a signed handle and unsigned state, two counts, and the 0xE00-byte lookup
table. Existing cleanup consumers establish the packed unsigned handle
representation and the runtime-slot layout. The C retains ordinary bounded
loops; `-O4,p` performs the native unrolling. No section qualifiers are
needed for this match.

## Validation and exclusions

All changed source units were rebuilt with their production recipes and
relocated against retail. The other 14,048 cached source/object pairs and
all 45 existing headers were unchanged. The complete loaded image and packed
ELF remain byte-identical to retail, and all 95 tests pass.

002603C0 remains uncredited: a two-float local differs in stack placement;
enlarging its local array matches bytes but lacks native extent evidence.
003DC2F0 and 0033C6E0 also remain uncredited near matches. No assembly lifts,
NOP padding, forced registers, or artificial local extents receive credit.

### SJ chunk and pool methods: 1,212 new C bytes

Recovered SJMEM UngetChunk, SJRBF GetChunk/UngetChunk, pool reset, the transfer
count accessor and the separate error callback. The old 52-byte assembly lift
is replaced by the actual 24-byte accessor and 28-byte callback; adjacent padding
remains uncredited. The shared 48-byte pool prefix and canonical constructor
remain intact. Cumulative byte counts use unsigned arithmetic for wraparound;
chunk address validation uses the target's 32-bit address representation.

Five production units verify 16 spans, including the unchanged 88-byte VU
placeholder, which receives no new C credit. All 95 tests and build/catalog
gates pass; both complete rebuilt image hashes match retail. No DATA sources
or DATA credit changed. Frozen evidence:
`private/code-lane/sdk-methods-integration/FINAL_VERIFICATION.json`.

### Inherited actor setups: 1,168 new C bytes

Recovered D9290/448, DA890/356 and CE070/364 in one production unit. Native
callback tables establish the true entries and owner arguments. The 28 leading
alignment bytes remain padding. The compiler's complete 24-byte switch section
verifies against the existing DATA owner without changing its source or credit.
All 95 tests, build/catalog gates and both complete retail image comparisons
pass. Frozen evidence: `private/code-lane/round13/early-integration/FINAL_VERIFICATION.json`.

### Actor launch, randomized start and owner resume: 2,012 new C bytes

Recovered 3A16D0/660, 3A1970/604, 3B84C0/464 and DC820/284. The two launch
patterns share one source unit. DC820 uses the genuine one-argument DC940
callee and forwards the owner only to the actual two-argument DC9D0 callee.
Twelve leading alignment bytes remain uncredited. DCA50 also forwards its
actually consumed owner explicitly. No heterogeneous adapter head is changed.

The randomized-start mode table is declared as 16 four-byte signed-char records;
its native byte-zero load does not establish a 32-bit enum type. No overlapping
DATA definition or DATA credit is added. PollSema now captures and returns its
real kernel result; FlushCache accepts its actual operation input. The 30FF90
wrapper calls the genuine one-argument target with one actor. These repairs
add zero credit; the wider callback-table ISO C limitation remains documented.

Six complete production units verify 212 functions. All 95 tests, build/catalog
gates, fresh split, loaded ROM and packed ELF comparisons pass. Frozen evidence:
`private/code-lane/round14/root/FINAL_VERIFICATION.json`.

### Phase setups, action starts and serialized lookups: 2,208 new C bytes

Four early phase setups add 1,112 bytes, two action starts add 936 bytes and
two directory lookups add 160 bytes. Native callback entries and full extents
are verified; 16 leading padding bytes remain excluded. Serialized offsets
are decoded with target-width unsigned address arithmetic, allowing payloads
outside the directory array. Three caller units use the actual pointer result
and the decompressor's signed-halfword pointer contract. The now-obsolete k0a
assembly placeholder and its production recipe are removed.

The 474270 consumer proves float XY pairs by full float loads/arithmetic. Its
separate typed DATA replacement proposal remains for the DATA owner; CODE
changes no DATA definition or credit. The other action start uses existing
bounded float tables and their actual declared record fields.

Seven production units verify 25 functions, including 17 existing caller-owned
functions. All 95 tests, build/catalog gates and both complete retail image
comparisons pass. Evidence: `private/code-lane/round15/root/FINAL_VERIFICATION.json`.

### Owner start profiles and active object queue: 1,228 new C bytes

Four owner-dependent actor starts add 1,028 bytes; their actual native table
entries exclude 48 leading alignment bytes. Existing owner-consuming helpers
receive both arguments. The active-object priority queue adds 200 bytes: it
checks active kind<5, enforces the native96-entry row limit, appends an object
and moves it toward the row start while its signed priority is lower. Its
Object definition is identical to the existing allocator/caller type.

The second caller now declares the actual opaque struct Object parameter
and casts its byte view explicitly. Unused byte-array declarations of the
queue table are removed from two other units. All three complete objects are
byte-identical before and after these source-contract repairs, preserving the
passing image/test gates without repeating unchanged suites. Five production
units verify 40 functions; all95 tests, coverage/catalog and complete retail
ROM/ELF identity pass. DATA sources/credit are unchanged. Frozen proof:
`private/code-lane/round17/root/FINAL_VERIFICATION.json`.

### Cache-tag range control: 328 new C bytes

Both 164-byte routines now express all iteration, address reconstruction and
inclusive range decisions as C. Inline assembly contains only the required
sync/cache/CP0 tag-read CPU operations; volatile and memory effects describe
those real operations. No assembly loop, branch, address arithmetic or NOP
padding remains in either recovered body. The obsolete two assembly lifts
are removed from their old source units; unrelated primitives/VU placeholders
remain unchanged and retain their existing credit status.

Sony29 O2/G0 with SNAS -mips4 uses the repository's supported assembler ISA
setting for this native integer/COP0 sequence, avoiding extra assembler hazard
NOPs absent in retail. Existing callers already use the actual two-pointer,
void-return contract. Three production units verify 13 spans, including two
uncredited VU placeholders (124 bytes); only the two new C bodies add credit.
All95 tests, coverage/catalog and both complete retail image comparisons pass.
Evidence: `private/code-lane/round19/root/FINAL_VERIFICATION.json`.

### Queue storage contract follow-up (zero credit)

The queue accepts opaque object storage and accesses only its actual shared
prefix through the active byte at13C. Its private prefix view has a distinct
tag; it does not claim a total1E4-byte extent for the larger5B8-byte caller pool.
Both named callers declare the same void(void*) API. The pointer table stores
opaque object pointers. The allocator retains its independent complete Object
type. This avoids incompatible same-tag complete structures across units.
All23 functions in the three affected CUs verify exactly, and allthree complete
objects are byte-identical to the passing prior image/test gate. No new credit.
Proof: `private/code-lane/queue-opaque-followup/FINAL_VERIFICATION.json`.

### Parent setup and byte-color setup: 544 new C bytes

DB430/268 uses its actual one-input callback contract and loads its parent
from18. Its existing residual interval is renamed without changing any extent.
3C81F0/276 is a proven native table entry, split from the preceding48-byte
dispatch head; the combined324-byte span is unchanged, with no internal gap.
Only the complete body is credited, and the head remains uncredited.

The color table is read through an unsigned-character four-byte record view,
matching allfour native byte loads and color-byte stores. Its outer extent
is unspecified, with no new global selector bound or word-type claim. Both
bodies reuse the existing196-byte ActorState. No DATA definition/credit changes.
All95 tests, coverage/catalog and both complete retail images pass. Adopting
the final byte-only color declaration leaves the entire object byte-identical
to the passing gate. Proof: `private/code-lane/round20/root/FINAL_VERIFICATION.json`.

### Heap growth and actor callbacks: 1,184 new C bytes

Recovered heap growth1044E0/172, edge launchC62A0/260, palette setup3AE020/320
and team-owned phaseD1700/432. The edge-launch interval becomes an uncredited
72-byte native head, eight padding bytes and the whole260-byte body. The
palette residual is renamed without changing its extent. The team callback
joins its existing owner-start unit, alongside its actual D1610 initializer.

D1700's unsigned shift is defined under a concrete native player-pool contract:
1801E0 writes team0 into slots0/2/4;1802A0 writes team1 into slots1/3/5. The
native player setup/dispatch chain reachesD1550, preserves the owner pointer,
and D1610 copies its team byte before entering state1. D1700 preserves that
byte, so the opposing-team index is0 or1. This is a scoped caller/phase
contract, not an arbitrary-byte or whole-program memory-safety claim. Full
native evidence: `private/code-lane/round16/d1700-domain/DOMAIN_EVIDENCE.txt`.

The heap loop, interrupt retry and unsigned address/boundary decisions are C;
assembly contains only real CPU interrupt/status operations. EndOfHeap now
returns its actual pointer inV0; all156 existing primitive functions remain
exact. The errno write aliases the first actual unsigned word through its
corresponding signed type. Runtime structure declarations and DATA stay
unchanged. Root accepted the separate zero-credit DATA repair: the existing pointer
initializer now names the real six-word target owner at0043B408 instead of
forming an out-of-bounds element6 of a different four-word array. The pointer
remains byte-exact, and no Runtime aggregate extent or DATA credit is added.

### Animation selector contract correction (zero credit)

1754A0 already had integer-selector declarations inside its own source unit,
but its definition used byte parameters. The native callee explicitly masks
both selector inputs to bytes before indexing. The definition now accepts
integers and makes that exact byte conversion explicit at each lookup. Its
byte field stores retain their ordinary truncation. Existing integer callers
now agree with the definition; eleven narrow/mixed declarations are aligned,
including their actual integer return type. Two callers retain their former
implicit byte conversions as explicit casts; nine need declaration-only
changes. No register, barrier, dummy value or padding is introduced.

All12 complete provider/caller objects are byte-identical to the baseline,
including all21 functions in the provider. The source contract is corrected
without changing a native instruction. The new team callback uses this same
integer API, preserving its real byte-valued animation selection.

Seventeen production units verify259 registered whole functions. All95 child
tests, coverage/catalog, fresh split and both complete retail image comparisons
pass. Nine minimized caller objects are also byte-identical to the objects
used by that gate. Frozen proof:
`private/code-lane/round21/root/FINAL_VERIFICATION.json`.

Root's six reserved forcing-audit units are unchanged. The raw child catalog
predates root's672-byte legacy quarantine; root's corrected counter and fixed
2,080,510 publication grid remain authoritative. This packet adds only1,184
new C bytes and zero DATA bytes.


Root integration independently rebuilt all17 units and verified259 complete
functions. Root's source-credit quarantine now has three unresolved bodies,
400 bytes total; three repaired bodies are credited again. Those corrections
are separate from this packet's1,184 new bytes. Root passed the current116-test suite and independently reproduced both
complete retail images before marking these four new rows linked. The split
producer also reproduced its ignored auto-label output on a second run; all
actual frozen inputs stayed unchanged. Root code reaches2,074,996 bytes
(62.9990%), with DATA unchanged at255,836. The fixed publication grid remains
2,080,510 code bytes;5,514 remain to that threshold.

### Sibling effects, facing setup and GS pages: 1,048 new C bytes

D4C10/412 inherits its owner state and allocates16 siblings with actual context,
parent links, ordinals and signed priorities. Allocation failure selects its
termination path and marks the real owner work byte. D4EE0/196 initializes the
child and returns the actual175910 result; its numeric callback table is not
recast as a uniform return type. The concrete ordinal1..16 producer chain
bounds the byte lookup. Its declaration remains unsized, with no invented
32-byte DATA object. Each true body is separated from a72-byte uncredited
head and eight real padding bytes; existing trailing gaps remain unchanged.

3A9FE0/240 inherits its parent and updates the actual halfword facing field,
then tail-calls its genuine one-actor next handler. The existing residual is
renamed at unchanged extent. Its DATA callback declaration already agrees.

1009C8/200 calculates image-page dimensions from actual signed16 inputs and
returns the native signed16 result. The packed mode word uses an eight-byte
builtin memcpy snapshot, not an incompatible u64 lvalue over the u32 storage.
The getter's address is aligned+16 within the real96-byte owner. All arithmetic
is bounded by the signed16 inputs; no new helper signature, header or DATA
change is needed. Source is ordinary C with no assembly or forcing.

Three production units verify four whole functions. All95 child tests,
coverage/catalog, fresh split and complete retail ROM/ELF identity pass. Frozen
proof: `private/code-lane/round23/root/FINAL_VERIFICATION.json`. Root's corrected
source-credit counter remains authoritative; the raw child catalog predates
its three repaired forcing bodies and400-byte quarantine. The fixed2,080,510
publication threshold is unchanged. No DATA credit or CODE push.


### Correct the actual00340A40 entry and its caller (zero credit)

The inventory split a single160-byte function into a four-byte stack prologue
at00340A40 and a156-byte row at00340A44. Its native caller at0034099C calls
00340A40, and its normal epilogue ends at00340AE0. The inventory now represents
that complete body once. No direct jumps or initialized-data pointer cells
reference00340A44 in the checked text/data spans. Neighboring credited
00340AE0 and00340AF0 bodies retain their extents.

The existing00340970 caller now explicitly passes its actor pointer through
the actual one-pointer prototype. All13 functions in its production unit still
verify exactly. The160-byte callee remains unmatched and receives no credit;
correcting the boundary does not turn a near match into matching C.

Root independently rebuilt allthree new CODE1048 units and verified allfour
whole functions. Root also corrected the middle text report's actual next-root
boundary and added two source-backed regressions. Final whole-image checks
use the current118-test suite, keeping child95-test evidence separate.


The associated thread-start follow-up also removes its unused fixed local and
restores148 bytes under the existing EE96 production recipe, with its used
condition binding retained. Together with the four new functions (1,048 bytes),
root's verified linked code reaches2,076,192 bytes (63.0353%). The real-entry
inventory correction and caller ABI repair add zero bytes. The next fixed
publication grid remains2,080,510 code bytes;4,318 bytes remain.

Root passed all118 tests and reproduced the complete retail loaded image and
packed ELF byte-for-byte before promoting these rows to linked status.


### Complete384FC0 callback and two real owner boundaries:216 new bytes

The table at00464740 selects the actual216-byte callback beginning00384FC0.
The old00385048 inventory entry was inside that body. Its tail enters the
existing one-actor handler003850A0. Root independently checked all native
words, the actual callback-table pointer, and the absence of direct call or
initialized-pointer references to the false interior entry.

The source uses the established196-byte ActorState type for its inherited
copy, followed by the actual identity, scale and signed-byte fields. Its two
timer stores use signed16-bit fields. This replaces the worker's raw49-word
copy view with the shared field-aware type and retains exact216-byte code.
The legacy recipe adds the existing src include directory for that header.
The eight-byte following padding gap remains uncredited.

A second table at00464600 proves003824E0 is a492-byte owner ending003826CC;
00382634 was another interior inventory split. That boundary is corrected
without adding source credit: the492-byte body still lacks an exact C match.
The following four-byte padding gap is untouched. Both merges preserve the
exact combined spans and neighboring credited functions.


Root independently compiled the refined216-byte callback and144-byte accessor
repair, passed all118 tests, and reproduced the complete retail loaded image
and packed ELF byte-for-byte. The cache audit verifies14,822 unchanged pairs,
one rebuilt existing unit, one new source/object pair and47 unchanged headers.
Both functions now receive linked credit. Local matching code is2,076,552
/3,293,696 bytes (63.0463%); reconstructed data remains256,328 /648,064
(39.5529%). The fixed next code publication threshold is2,080,510, with3,958
bytes remaining. Only the108-byte RPC wrapper remains source-credit quarantined.

### GS packet methods and actor setups: 1,688 new C bytes

Recovered GS environment100A90/484, sprite packet100C78/260 and GIF DMA
submission100D80/232, plus actor setupsCE7B0/316 and3C1A40/396. The two GS
builders share one real value/register-pair type. All packing and branching
are C; the builders' only assembly is the actual final CPU sync. Coordinate
scaling uses bounded signed32 multiplication and unsigned64 packing, avoiding
negative signed shifts. The128-byte environment retains the native read-modify-write bytes for its
three one-bit controls. Root uses actual bitfield assignments for those flags,
without a raw-value C read or an added zero-initialization assumption.
The96-byte sprite packet assigns every output word. DMA polling uses actual
volatile MMIO, a bounded counter and a safe8-byte memcpy tag snapshot.

CE7B0's one-actor callback and current integer animation API agree.3C1A40's
generic context input and typed owner helper agree at their direct call. It
uses the real owner Z field, not an uninitialized local. Native LH/stride4
and numeric float conversion support a signedXY view of475CA0. Its raw DATA
storage remains a placeholder, with no new whole-object type or extent credit. The native valid-variant protocol remains
a precondition; no guessed global index bound or padding extent is added.

Both existing residual rows are renamed without changing boundaries. Four
production units verify five whole functions. All95 child tests, coverage/
catalog, fresh split and both complete retail image comparisons pass. All
14104 other source/object pairs and47 headers remain unchanged. Frozen proof:
`private/code-lane/round25/root/FINAL_VERIFICATION.json`; explicit packet math
and source/ABI review: `private/code-lane/round25/root/GS_SOURCE_REVIEW.md`.
Root's corrected counter and fixed2,080,510 grid remain authoritative.


Root's GS review replaces three raw64-bit OR/AND updates with writes to their
actual single-bit controls. Both methods remain exactly484 and260 bytes
under the unchanged Sony29 recipe. This preserves the native physical updates
without evaluating prior uninitialized reserved storage as a raw C value.
The value/register pair remains16 bytes and the environment remains128 bytes.
The396-byte actor method retains only its native signed-halfword field view;
three standard packed-word/byte-copy alternatives were privately tested and
remain non-matching, without changing the uncredited DATA owner.

Root independently rebuilt all five complete functions using their production
recipes. The aggregate gate passed 118 tests, catalog validation, fresh split,
full loaded-ROM identity and packed-ELF identity. The frozen input audit
checked 14,830 unchanged source/object pairs and 47 unchanged headers, plus
four new compilation units. Linked matching code is now 2,078,240 / 3,293,696
bytes (63.0975%); reconstructed data remains 256,369 / 648,064 bytes
(39.5592%). The next fixed code publication threshold remains 2,080,510,
with 2,270 verified code bytes remaining. These are root aggregate counts;
the worker snapshot above excludes intervening parent integrations.

### Actor motion, field selection and image DMA: 1,300 new C bytes

Four complete functions add D8700/440, 3AAA60/332, 100E68/148 and 101540/380.
The scoped existing DMA caller repair retains all three functions exactly.
All inventory boundaries and DATA ownership remain unchanged. Native state and
record views, valid constructor domains, target signed shifts and actual MMIO
preconditions are documented in round26/root/SOURCE_REVIEW.md. No forced
registers, dummy locals, padding or algorithmic assembly are introduced.

Five production CUs verify seven whole functions. The child's 95 tests,
coverage/catalog, fresh split, complete retail ROM and packed ELF identity pass.
All 14,107 other cached source/object pairs and all 47 headers are unchanged;
only the existing DMA caller is modified. Root's corrected counter and fixed
2,080,510 publication grid remain authoritative. The unrelated 340-byte callback
and its DATA proposal remain excluded and held for integrator review. Frozen
receipt: private/code-lane/round26/root/FINAL_VERIFICATION.json.

### Owner launch callback and storage type

003C7880 is a complete340-byte callback taking actor and owner context. Its
existing48-byte dispatcher already converts stored callbacks back to that
actual two-input type. The DATA declaration for this slot now names both
inputs and casts solely for storage; the dispatcher table declaration now
agrees with the const DATA object. Root rebuilt the new complete callback,
all303 functions in argument_dispatch_heads, and the complete200-byte table.
Every relocated byte remains exact. Other legacy callback-slot contracts are
outside this scoped correction. The residual is renamed at unchanged
[003C7880,003C79D4) bounds; neither head nor following padding is recounted.

The root aggregate gate independently verifies all changed compilation units,
118 tests, catalog/coverage, fresh split, and complete retail loaded-ROM and
packed-ELF identity. Frozen audit:14,828 unchanged source/object pairs, four
rebuilt existing units, two retired owners,109 new pairs, and47 unchanged
headers. Linked matching CODE is2,079,880 /3,293,696 bytes (63.1473%);
linked reconstructed DATA is256,488 /648,064 bytes (39.5776%). The fixed
next CODE publication threshold remains2,080,510, with630 bytes remaining.

### State-transition pair and required owner ABI

002C0730/368 and002C0BA0/412 are complete one-input actor state callbacks.
Their existing caller002C06A0 supplies the actor. Root pins324 native words
covering both functions, that caller and the unmatched byte-selector helper.
The known threshold helper00184110 takes an owner pointer AND a float. The
worker candidate omitted the pointer, despite matching instructions because
A0 incidentally retained it. Both new sources now pass the actual owner
explicitly, sharing the provider's real partial-owner view in a header. Its
existing implementation and both new callers remain whole-exact.

The animation helper returns int, ignored here; the sound-selector helper
takes actor plus an8-bit selector. The shared-state counter uses a flexible
signed-halfword view with its actual7C offset, without a guessed capacity.
Byte-table address views are unsized and retain their actual GP-relative
storage through the compiler's small-data declaration; the surrounding raw
DATA owner stays unchanged. Root also removed the candidate's unnecessary
volatile read qualifier: ordinary C still reproduces both complete functions.
No DATA credit or following4-byte gap credit comes from these CODE views.

The same audit covers all registered00184110 callers in the source tree.
Three existing caller units now include the shared real provider declaration.
The sibling transition routines pass their missing owner pointers; the
existing wrapper stops inventing a third helper argument while retaining its
own legitimate third parameter for the later vertical comparison. These are
zero-credit ABI repairs and are independently rebuilt in their entirety.

Root's aggregate frozen-input gate passes118 tests, catalog and build coverage,
fresh split, complete loaded-ROM identity and packed-ELF identity. The audit
checks14,934 unchanged source/object pairs, seven rebuilt existing units,
eight new pairs,47 unchanged headers and one new shared ABI header. Linked
matching CODE is2,080,660 /3,293,696 bytes (63.1710%); linked reconstructed
DATA is256,703 /648,064 bytes (39.6107%). This crosses the existing fixed
CODE threshold2,080,510 by150 bytes. After this checkpoint's publication,
the next fixed threshold advances to2,113,447; the surplus is retained.

### Random motion and fall transition: 640 new C bytes

DD020/272 and3A7110/368 recover two complete native callbacks. DD020 preserves
ordered NaN behavior and explicit native unsigned vertical wrap. Its528-byte
conflated inventory entry is conservatively split into44-byte dispatcher,
4-byte padding, uncredited200-byte initializer,8-byte padding and272 new C
bytes. The original denominator is unchanged; padding is never credited.
3A7110 reuses the existing signed16-entry random lookup with RNG&15 bounds.
Its team-index constructor evidence and native callback/helper contracts are
frozen separately; no DATA view or owner changes are introduced.

Both production units are exact. All95 child tests, coverage/catalog, fresh
split, complete ROM and packed ELF identity pass. All14,112 prior cached
source/object pairs and all47 headers remain unchanged. Root's corrected
counter and fixed2,080,510 grid remain authoritative; against canonical6b079f7e
this640-byte packet conditionally yields2,080,520, ten past the same threshold.
Frozen receipt: private/code-lane/round28/root/FINAL_VERIFICATION.json.

Root independently rebuilt both complete functions and checked294 native
instruction PCs covering the split entry, complete bodies and visibility
helper, plus the supplied constructor/roster-domain excerpts. All118 tests,
catalog/coverage, fresh split, loaded-ROM identity and packed-ELF identity
pass. Frozen audit verifies14,949 unchanged source/object pairs and48
headers, plus two new units. Linked CODE is2,081,300 /3,293,696 bytes
(63.1904%); DATA remains256,703 /648,064 (39.6107%). The fixed next
CODE threshold remains2,113,447, leaving32,147 bytes. This local bank adds
640 source bytes; it does not reset the publication grid.


### Inheritance, direction/timer transition and grid lookup: 472 C bytes

C5890/184,3B0BC0/168 and41CCA0/120 are complete exact native functions. The
C5890 residual is renamed without extent changes. The216-byte3B0B90 row splits
into uncredited dispatcher40,padding8 and new BC0/168, preserving its interval
and fixed denominator. No dispatcher, padding or DATA credit is added.

C5890 uses the existing ActorState and actual one-input owner-loading helper.
BC0 uses the true integer animation/RNG interfaces and bounded byte-direction/
timer arithmetic.41CCA0 has bounded8x8 short reads and true status result; its
sole existing C caller's one-line void-to-int declaration correction preserves
its whole276-byte function and complete object hash. Existing key-present
preconditions remain explicit; no behavior-changing fallback is invented.
Source, partial-view and ABI limits are in round31/root/SOURCE_REVIEW.md.

Four production units verify four functions; only three new bodies get472B.
All95 child tests,coverage/catalog,fresh split and full ROM/ELF hashes pass.
All14115 other cached pairs and47 child headers remain unchanged. No public
header,DATA,canonical or shared-handoff writes; root counters/2113447 grid and
publication remain authoritative. Frozen receipt:
private/code-lane/round31/root/FINAL_VERIFICATION.json.
