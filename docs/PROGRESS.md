# Progress stats (decomp.dev)

objdiff v2 field meanings, as decomp.dev displays them:

| decomp.dev | objdiff field | Meaning here |
|---|---|---|
| decompiled | `matched_code_percent` | Exact matching C vs retail `.text` |
| fully linked | `complete_code_percent` | That matching C is **placed by the hybrid linker** |
| data bar | `matched_data_percent` / `complete_data_percent` | Completed-source initialized data in `0x00424200..0x004C2580` |

`complete_*` is **not** “the packed ELF SHA-matches retail.” Hybrid copies unmatched bytes from the dump, so the image can hash 100% while linked C is still ~10%.

## Rules the catalog must keep

Conservative spans (do not change without rewriting the report):

- code: `0x00100000` + `0x324200` bytes
- data: `0x00424200` + `0x9E380` bytes

1. Every `matches.csv` name/address/size exists in `functions.csv`.
2. Every `data_matches.csv` row matches `data_units.csv` exactly.
3. **No overlapping intervals** in code matches or data units. Overlap is a CI failure, not a silent union.
4. `complete_* <= matched_* <= span`. Percents cannot exceed 100.
5. Listed `source` files exist.
6. `assets/progress.svg` is regenerated from the reporter (`make report`) and committed.

`status=complete` means hybrid-placed exact C. Do not mark a function complete if it is not in `compile_matching.sh` and verified.

## Adding a data unit

Do **not** punch or split fills to create extra catalog rows. A raw `u32`/`zero`/`0xFF` dump or numeric jump table is `progress=placeholder` and gets **zero** matching/linked data credit even if hybrid-placed. Only promote `progress=reconstructed` after recovering the object's structure, symbols, and references.

Keep catalog ranges disjoint enough for the linker; do not restack the same bytes as a second credited unit. Then run:

```sh
PYTHONPATH=. python3 -m tools.validate_progress_catalog
PYTHONPATH=. python3 -m tools.objdiff_report --svg assets/progress.svg
```

## Data completion and report structure

Reports expose one unit per data source file, with `source_path`, per-unit
measures and `metadata.complete`, plus an uncredited residual unit. The sum
of unit data sizes remains 648,064 bytes. This follows the source-object report
structure used by [Metroid Prime](https://github.com/PrimeDecomp/prime/blob/main/configure.py),
[Melee](https://github.com/doldecomp/melee/blob/master/tools/project.py), and
[Twilight Princess](https://github.com/zeldaret/tp/blob/main/tools/project.py).
Objdiff's complete flag means a completed linked source object; it is not a
universal measure of semantic understanding.

MVC2 uses a hybrid linker and has no recovered original translation-unit map.
Its per-file data units are current source ownership, not claimed original
object boundaries. A raw binary replacement expressed in C remains placeholder
work even though the hybrid image physically links it.

`config/data_matches.csv` explicitly classifies each range with `progress`:

- `placeholder`: raw integer arrays, untyped zero/fill runs, and numeric-address
  jump/pointer tables. These earn neither matching nor completed data credit.
- `reconstructed`: recovered structures, symbolic dispatch/handler tables, and
  identified typed objects. Exact matching earns matching credit; `status=complete`
  additionally earns linked credit. This is a project completion policy, not an
  objdiff rule that all projects must use.

Both classes remain in the build catalog and all address, overlap, span, and
source-existence checks. Missing/unknown classifications fail report generation.
Do not promote a placeholder merely by changing its name or expressing the same
bytes with another scalar type. Recover the object's boundaries, representation
and references; verify its compiled bytes and hybrid placement before promotion.
The public reporting job validates catalog declarations; it does not rebuild the
private retail image or independently prove those declarations.

At this correction, 12 reconstructed ranges contribute 4,200 / 648,064 data bytes
(0.648096%). Another 628,674 catalogued bytes are placeholders; 15,190 bytes remain
outside the replacement catalog. The former 97.656096% counted both classes.
Code progress is unaffected.

## Continuing checkpoint (2026-10-04)

Nineteen inline-assembly/raw-word replacements (1,508 bytes) are now
`status=placeholder`. They remain compiler-verified and hybrid-linked, but earn
zero matching C credit. Kernel syscall wrappers remain credited source because
the syscall instruction requires inline assembly. A recovered dispatcher tail
at `0x0026ECA0` adds 12 bytes of exact C.

The corrected starting checkpoint is 411,164 / 3,293,696 code bytes
(12.483357%). Push after each additional five percentage points of verified,
hybrid-linked C: first at 575,849 code bytes (at least 17.483357%).

The next recovered batch contributes nine functions / 1,152 bytes: two bounded
frame-scale callers, their typed keyframe interpolator, and six object-pool
allocation, release, and insertion routines. The existing allocator wrapper
retains its original source owner. Total credited C is now 412,328 bytes
(12.518695%); the five-point push threshold remains 575,849 bytes.

The strength-selecting move-setup batch adds 77 compiler-matched functions /
21,304 bytes in three shared C state-machine families. Each handler preserves
its animation calls, symbolic data choice, timer and per-player counter reset,
and (where present) the conditional nibble-counter decrement. The repeated
command write in retail is retained as an explicit volatile byte write. No
assembly or raw instruction words are used. Total credited C is now
433,632 / 3,293,696 bytes (13.165514%). The push threshold is unchanged.

The next batch adds 56 functions / 10,592 bytes: twelve move handlers with
late third-state animation, twenty ground-reset callbacks, twenty-three
facing-dependent motion callbacks, and an active-object traversal. The twenty
ground-reset entries follow four-byte nop padding and are 16-byte aligned;
each is independently referenced by an initialized-data callback table. Their
164-byte C bodies replace the residual code, while all twenty padding words
remain uncredited. The twenty-three motion entries are also callback-referenced
aligned prologues and replace their complete 184-byte residual ranges.
No range bytes were dropped. Splitting the twenty padding/code ranges raises
the inventory to 19,862 units. Current credited code is 444,224 / 3,293,696
bytes (13.487098%); the push threshold remains 575,849 bytes.

The next batch adds 27 functions / 6,632 bytes: six move setup handlers
reusing the existing state machine, sixteen handlers with deferred animation
and MWCCPS2 3.0 scheduling, and five airborne frame updates. All comparisons
include their relocated calls and symbolic data references. Current credited
code is 450,856 / 3,293,696 bytes (13.688452%); the five-point push
threshold remains 575,849 bytes.

Four shared animation-record routines add 880 bytes: record progression,
stream initialization, encoded command dispatch, and indexed frame selection.
The recovered 20-byte record format preserves zero-duration traversal and
relative jumps. A larger angle-conversion family remains a private, uncredited
candidate because its divisor construction still differs from retail. Current
credited code is 451,736 / 3,293,696 bytes (13.715170%); the five-point
push threshold remains 575,849 bytes.

Shared animation record progression, initialization, command dispatch, and
indexed selection add four functions / 880 bytes. Two more bounded keyframe
scale handlers add 208 bytes. All six have exact compiler and hybrid-placement
proof. The larger angle-conversion family remains a private, uncredited
candidate because fifteen divisor-construction instruction words differ.
Current credited code is 451,944 / 3,293,696 bytes (13.721485%); the five-point
push threshold remains 575,849 bytes.

The final published batch adds 33 functions / 3,528 bytes: eleven accepted
transition handlers, thirteen priority dispatchers, and nine dependent-object
creation handlers. Their compiled instructions, relocations, and complete
hybrid placement match retail. Credited code is 455,472 / 3,293,696 bytes
(13.828599%). Work is paused after the user-requested GitHub checkpoint.

Resumed checkpoint: system selector `func_0010C480` adds 64 exact C bytes.
Credited code is 455,536 / 3,293,696 bytes (13.830542%). The last published
checkpoint was 455,472 bytes; the next five-point push is at 620,157 bytes.

Ten command-predicate state transitions add 920 exact C bytes on MWCCPS2
3.0-011126 with -O3 -sdatathreshold 0. Each preserves its predicate, state,
mode, and counter-clear ordering. Credited code is 456,456 / 3,293,696 bytes
(13.858474%); the next push threshold remains 620,157 bytes.

Thirty record-enabled transitions and fourteen one-shot transitions add
6,312 exact C bytes. Both units match on MWCCPS2 3.0-011126 with
-O3 -sdatathreshold 0. Each preserves its table, buffer offset, state and
branch behavior. Credited code is 462,768 / 3,293,696 bytes
(14.050113%); next push remains 620,157 bytes.

Eight enabled-record one-shot handlers add 1,440 exact C bytes on
MWCCPS2 3.0-011126 with -O3 -sdatathreshold 0. Credited code is now
464,208 / 3,293,696 bytes (14.093833%); next push remains
620,157 bytes.

Seven accepted-record flag handlers add 644 exact C bytes; together with
the enabled one-shot batch, fifteen functions add 2,084 bytes. The flag
handlers preserve the enabled-record test and success-only flag write.
Credited code is 464,852 / 3,293,696 bytes (14.113385%).

Six positive-animation command resets and four state-first command gates
add 832 exact C bytes. The resets use MWCCPS2 3.0.3 with small data 8;
the gates use 3.0-011126 with small data 0. Credited code is
465,684 / 3,293,696 bytes (14.138645%).

Five parent-state dispatch routines add 460 exact C bytes on MWCCPS2
3.0.3 with -O3 -sdatathreshold 0. Credited code is 466,144 / 3,293,696
bytes (14.152612%); next push remains 620,157 bytes.

Four pending animation-command consumers add 288 exact C bytes on
MWCCPS2 3.0.3 with -O3 -sdatathreshold 8. Credited code is
466,432 / 3,293,696 bytes (14.161356%).

Twelve callback-referenced animation entries add 528 exact C bytes: four
initialization/progression callbacks and eight activation tails. Every entry
follows an uncredited four-byte nop and is 16-byte aligned. Splitting the
padding from their exact C bodies preserves all bytes and raises the inventory
to 19,874 units. Credited code is 466,960 / 3,293,696 bytes
(14.177386%).

Five airborne handlers with post-animation command setup and seven
rotation initializers add 2,924 exact C bytes. The initializers have aligned
callback-table entries following uncredited four-byte padding; every original
range remains fully represented. Inventory is 19,881 units and credited code
is 469,884 / 3,293,696 bytes (14.266162%).

Six parent-animation layer-following handlers add 1,272 exact C bytes.
Each uses its own eight-byte callback pair from the existing placeholder
table catalog, enabling the retail GP-relative address. The layer sum is
clamped to 0..7 after dispatch. Credited code is 471,156 / 3,293,696 bytes
(14.304781%); no data credit is added.

Six shared actor-state update handlers add 1,824 exact C bytes on
MWCCPS2 3.0-011126 with -O3 -sdatathreshold 0. Each reproduces the
pending-state resolution, global flags, conditional transition, and signed
animation result. Credited code is 472,980 / 3,293,696 bytes
(14.360160%).

Four callback-referenced initialization/continuation entries add 272 exact
C bytes. Their four preceding nop words remain uncredited, and all original
range bytes remain represented. Inventory is 19,885 units; credited code is
473,252 / 3,293,696 bytes (14.368418%).

A periodic visibility toggle and state-pointer dispatcher add 84 exact C
bytes. Both match MWCCPS2 3.0.3 -O3 with small-data threshold 8.
Credited code is 473,336 / 3,293,696 bytes (14.370968%).

The signed-index pair-table copy adds 40 exact C bytes on MWCCPS2
3.0.3 with -O3 -sdatathreshold 0. Its table-pointer declaration and explicit
Y-before-X loads reproduce retail registers and floating load/store order.
Credited code is 473,376 / 3,293,696 bytes (14.372182%).

Six parent-state block copies add 1,296 exact C bytes. Their shared
49-word copy helper takes count before destination/source, reproducing retail
register allocation with MWCCPS2 3.0-011126 -O3 -Op and small data 0.
Credited code is 474,672 / 3,293,696 bytes (14.411530%).

A clamped global counter and table-driven state-completion routine add
160 exact C bytes on MWCCPS2 3.0.3 with -O3 -sdatathreshold 0.
Credited code is 474,832 / 3,293,696 bytes (14.416388%).

The callback-referenced mode-exit/drift entry at 0x0013B140 adds 96
exact C bytes. Its pointer reference at 0x004402E8 and aligned entry justify
replacing the entire residual range without changing its extent. Credited
code is 474,928 / 3,293,696 bytes (14.419303%).

A signed-state dispatcher, its increment handler, and a timed animation-flag
callback add 92 exact C bytes. The dispatcher range splits at the handler
entry referenced by 0x00446B98. The timed callback is referenced by
0x004BF8B8; its preceding padding word stays uncredited. Inventory is
19,887 units; credited code is 475,020 / 3,293,696 bytes
(14.422096%).

Twenty-six floating-parameter effect callbacks add 832 exact C bytes with
MWCCPS2 3.0.3 -O4 -Op -sdatathreshold 0. These flags materialize the
retail immediate constants instead of literal-pool loads. Current credited
code is 475,852 / 3,293,696 bytes (14.447356%).

The upper-height limit at 0x00316940 is now native C instead of an
uncredited assembly placeholder. MWCCPS2 3.0.3 -O4 -Op small-data 0
reproduces all 52 bytes, including the strict upper-limit comparison.
Credited code is 475,904 / 3,293,696 bytes (14.448935%).
The last published checkpoint was 475,852 bytes; the next five-point push
is at 640,537 credited bytes (19.4474%).

The active fade-step handler at 0x001356A0 adds 80 exact C bytes on
MWCCPS2 3.0.3 -O4 -Op small-data 0. It preserves the immediate decrement,
inclusive zero comparison, field store, and release call. Credited code is
475,984 / 3,293,696 bytes (14.451364%).

Cooldown expiry at 0x001BDA10 and negative-velocity clamping at 0x001822B0
now use native C rather than uncredited assembly placeholders. Both match
MWCCPS2 3.0.3 -O4 -Op small-data 0, adding 136 credited bytes and removing
the obsolete assembly source/build entries. Current code is 476,120 /
3,293,696 bytes (14.455493%).

Four motion/fade transitions now use exact native C instead of uncredited
assembly placeholders: velocity-zero state advance, clamped fade completion,
and two velocity-sign-change acceleration updates. MWCCPS2 3.0.3 -O4 -Op
small-data 0 matches all 324 bytes. Obsolete assembly sources/build entries
are removed. Credited code is 476,444 / 3,293,696 bytes
(14.465330%).

Merged upstream through 52f5c0d: all eight additional native functions
match locally. Three typed launch-record initializers add another 624
exact C bytes on MWCCPS2 3.0.3 -O3 -sdatathreshold 8. Combined code is
507,660 bytes across 8,410 functions; full image and retail ELF match.

Recovered three mode/stance move-setup routines (912 bytes), compiled with MWCC 3.0.3 `-O3 -sdatathreshold 8`. All three objects and the full linked image and retail ELF match exactly. Credited total: 508,572 bytes across 8,413 functions; decompilation remains active.

Recovered 16 further native routines (2,328 bytes): live stance gates, free-slot interaction commits, selected-target callers and their selector, and child/owner stance dispatch. Reconstructed the 68-byte grouped symbolic callback table at 0x004C1C98. Individual objects and full image/retail ELF match. Totals: 8,429 functions, 510,900 linked C bytes, and 42,008 reconstructed data bytes. The 100% goal remains active.

Recovered eleven child-spawn and uniform scale/motion-key routines (1,348 bytes) plus eight typed frame/value curves (152 bytes). Preserved the intervening padding and remaining raw tail as uncredited data. Individual code/data objects and the full image and retail ELF match exactly. Credited totals: 8,440 functions, 512,248 code bytes, and 42,160 data bytes.

Recovered thirteen live interaction, planar floor contact, directional target, and contact-effect dispatch routines (1,728 bytes) plus the grouped 56-byte symbolic effect callback table. Preserved the six/four/four callback extents. Individual objects and the full linked image and retail ELF match exactly. Totals: 8,453 functions, 513,976 code bytes, 42,216 data bytes; goal remains active.

Recovered four unoccupied stance/mode commits, three owner/animation wait routines, and two former assembly-only float placeholders (1,140 bytes). Callback `jtbl_00464100` entry 0x00379190 and its complete 132-byte native match establish that former residual as a callable entry; its range and inventory count are unchanged. Individual objects and full image/retail ELF match. Total: 8,462 functions and 515,116 code bytes; data remains 42,216 bytes.

Recovered three elevated position effect spawns (504 bytes), including typed three-component position copies and the retail unit-scale setup. All three native objects, the full linked image, and the packed retail ELF match exactly. Total: 8,465 functions and 515,620 linked C bytes; reconstructed data remains 42,216 bytes. The 100% goal remains active.

Recovered five preset-scale effect spawns and three stored-position effect spawns (1,128 bytes). Typed three-component copies reproduce the retail load/store sequence. The scale family preserves the distinct owner-field versus supplied-position inputs. All individual objects, the full linked image, and the packed retail ELF match exactly. Total: 8,473 functions and 516,748 linked C bytes; reconstructed data remains 42,216 bytes.

Recovered three signed axis-mode selectors and three owner-generation dispatchers (528 bytes). The dispatchers preserve both callback arguments and destroy stale-generation objects before dispatch. All individual objects, the full linked image, and the packed retail ELF match exactly. Total: 8,479 functions and 517,276 linked C bytes; reconstructed data remains 42,216 bytes. The 100% goal remains active.

Recovered fifteen native effect/child routines (2,376 bytes): four positioned zero-motion initializers, four indexed-angle spawns, three owner-linked planar-offset spawns, and four stance-flip launch routines. Recovered three typed unit-scale vectors (36 bytes) and two side-angle tables (16 bytes) from their exact consumers. Split the containing raw angle block without dropping or crediting its remaining prefix/tail. All code/data objects, full linked image, and packed retail ELF match exactly. Totals: 8,494 functions, 519,652 linked C bytes, and 42,268 reconstructed data bytes across 1,409 units.

Recovered thirteen native routines (1,708 bytes): three owner-generation child spawns, three preset-position spawns with follow-up initialization, four animation-first planar floor-contact handlers, and three two-parameter child spawns. The floor handlers preserve animation-before-motion order and exact contact behavior. All individual objects, the full linked image, and the packed retail ELF match exactly. Totals: 8,507 functions and 521,360 linked C bytes; reconstructed data remains 42,268 bytes.

Recovered six native countdown routines (984 bytes): three planar-motion position restores and three owner-phase gates. The gates preserve active-owner, mode, side, countdown, and phase checks and both callback arguments. All individual objects, the full linked image, and the packed retail ELF match exactly. Totals: 8,513 functions and 522,344 linked C bytes; reconstructed data remains 42,268 bytes.

Replaced the former assembly-only `func_003ABFE0` placeholder with its exact 60-byte native linked-opponent height clamp. Unsigned address arithmetic reproduces the retail member-address calculation while preserving the unordered-comparison behavior. The object, full linked image, and packed retail ELF match exactly. Totals: 8,514 functions and 522,404 linked C bytes; reconstructed data remains 42,268 bytes.

Replaced the former assembly-only `func_001863F0` placeholder with its exact 68-byte native acceleration/velocity reset. The float truth test and negated nonpositive-product comparison preserve retail behavior for zero and unordered values. The object, full linked image, and packed retail ELF match exactly. Totals: 8,515 functions and 522,472 linked C bytes; reconstructed data remains 42,268 bytes.

Recovered nine native routines (888 bytes): three signed owner-animation synchronizers, three global phase/frame-hook dispatchers, and three owner-stance dispatchers. Reconstructed their three no-argument phase tables (36 bytes) and three two-argument owner tables (24 bytes), preserving unverified prefixes and trailing raw pointers without credit. The existing frame-hook entry at 0x00152570 is referenced symbolically without changing the function inventory or claiming its body as recovered. All code/data objects, full linked image, and packed retail ELF match exactly. Totals: 8,524 functions, 523,360 linked C bytes, and 42,328 reconstructed data bytes across 1,415 units.

Recovered three side-inhibit callback dispatchers (252 native C bytes), preserving the ordinary-BSS mask access and small-data callback access. Object relocations, linked image, and packed retail ELF match exactly. Totals: 8,527 functions and 523,612 linked C bytes; reconstructed data remains 42,328 bytes across 1,415 units.

Recovered five native inhibit-state routines (532 bytes): three owner-phase gates, the slowdown selector, and the side-mask initializer. All function bytes and relocations, the linked image, and the packed ELF match exactly. Totals: 8,532 functions and 524,144 linked C bytes; reconstructed data remains 42,328 bytes across 1,415 units.

Recovered two native owner-motion synchronizers (392 bytes), retaining side-mask inhibition, owner-state fallback, signed facing copies, and motion-gated callback dispatch. All code objects, full linked image, and packed ELF match exactly. Totals: 8,534 functions and 524,536 linked C bytes; reconstructed data remains 42,328 bytes across 1,415 units.

Recovered the native character-state dispatcher at 0x001793B0 (196 bytes), including preset character flags, shared-mask inhibition, side-bit gating, and its activity fallback. The object, linked image, and packed ELF match exactly. Totals: 8,535 functions and 524,732 linked C bytes; reconstructed data remains 42,328 bytes across 1,415 units.

Recovered twenty-one native loop routines (1,584 bytes): six linked child-list destruction routines and fifteen fixed-size entry update loops. MWCC 3.0's loop-padding setting reproduces the retail comparison/backedge padding without embedding assembly. Every object, full linked image, and packed retail ELF matches exactly. Totals: 8,556 functions and 526,316 linked C bytes; reconstructed data remains 42,328 bytes across 1,415 units.

Recovered three native parameterized update loops (276 bytes): a ten-entry update and two six-entry groups gated by a signed byte mode. MWCC 3.0's loop-padding setting preserves their retail backedges and argument setup. All objects, full linked image, and packed ELF match exactly. Totals: 8,559 functions and 526,592 linked C bytes; reconstructed data remains 42,328 bytes across 1,415 units.

Recovered four native indexed child-spawn routines (496 bytes), including per-child indices, owner references, typed callbacks, allocation-failure handling, and byte-counter truncation. All objects, full linked image, and packed retail ELF match exactly. Totals: 8,563 functions and 527,088 linked C bytes (16.003%); reconstructed data remains 42,328 bytes across 1,415 units.

Reconstructed the three two-entry side-inhibit callback tables at 0x004BF7C8, 0x004BF7D0, and 0x004BF7D8 (24 bytes), sharing their two-argument contract with exact native consumers. The original 144-byte range is preserved as a 56-byte raw prefix, 24 typed bytes, and 64-byte raw tail; the raw ranges receive no credit. All data objects, consumers, full linked image, and packed ELF match exactly. Reconstructed data totals 42,352 bytes across 1,418 units; code remains 8,563 functions and 527,088 linked C bytes.

Recovered nine native routines (944 bytes): the owner-facing animation gate, a 49-word owner-state snapshot, three generation-tagged parameter spawners, and four fixed launch-effect initializers. Reconstructed the three four-entry owner-generation callback tables (48 bytes), preserving the original 32-byte and 120-byte ranges with their remaining raw prefixes/tail uncredited. The planar launch offsets retain the observed 16-byte stack alignment and only the two floats read by their helper. All code/data objects, full linked image, and packed ELF match exactly. Totals: 8,572 functions, 528,032 linked C bytes, and 42,400 reconstructed data bytes across 1,421 units.

Recovered four native owner-substate animation entries (400 bytes). The child advances its state and starts animation 13/18 in bank 21, then clears the owner's substate flag when their sides match. All function bytes and relocations, full linked image, and packed ELF match exactly. Totals: 8,576 functions and 528,432 linked C bytes; reconstructed data remains 42,400 bytes across 1,421 units.

Recovered three native timed-effect spawners (444 bytes), including typed callback setup, context reference, three-float position copies, encoded angles, and cleared motion fields. All complete objects, full linked image, and packed ELF match exactly. Totals: 8,579 functions and 528,876 linked C bytes; reconstructed data remains 42,400 bytes across 1,421 units.

Recovered three native unit-scale positioned effect spawners (456 bytes), preserving typed callbacks, context access, three-float position copies, unit scale, and cleared motion fields. All function bytes and relocations, full linked image, and packed retail ELF match exactly. Totals: 8,582 functions and 529,332 linked C bytes; reconstructed data remains 42,400 bytes across 1,421 units.

## 2026-10-08 Luna medium team integration

Recovered 17 additional native C routines (1,028 bytes): small wrappers,
countdown transitions, animation state transfers, floating predicates and
position bounds, a timer update, packed-field extraction, and SN runtime
leaves. A callback's false interior boundary at 0x00303030 was removed after
complete compiler span and entry-reference verification.

Restored 48 omitted compiler recipes from a628e5d and the 624-byte launch-record
family recipe. Every restored object verifies against retail; these repairs
restore reproducible linkage of existing credit and do not add credit.
SN GCC 2.95.2 -O2 -G0 -ffunction-sections proves three early runtime leaves;
the owner-authorized public build bundle now includes its pinned compiler,
preprocessor, and assembler. Bootstrap and compiler-pipeline smoke tests pass.

All code objects and all 5,608 compiled data objects passed direct verification.
The full hybrid loaded image and packed 3,942,320-byte retail ELF match target
hashes. All 32 tests and catalog validation pass. Totals are 8,599 exact linked
C functions and 530,360 / 3,293,696 C bytes; reconstructed data remains
42,400 / 648,064 bytes. Assembly placeholders and raw-data fills retain zero
source credit. Further agent batches remain separate until independently
verified and linked.

## 2026-10-08 continued team integration

Added 19 independently verified native routines (776 bytes): fourteen SN
runtime global/indexed accessors, a merged state-reference check, a directional
motion transition, a GP tail wrapper, a record-position adjustment, and a
300-byte conditional callback chain. The state-reference check's interior
0x002C5C58 boundary was removed after complete span and entry-reference proof.
All affected source units verify exactly, including all 40 functions in the
conditional-chain unit. The complete loaded image and packed retail ELF retain
byte-identical target hashes. Catalog totals are 8,618 linked C routines and
531,136 / 3,293,696 bytes. Reconstructed data remains 42,400 / 648,064 bytes.

## 2026-10-08 callback and runtime checkpoint

Added 14 native routines (1,816 bytes): five conditional-engine chains, two
status predicates/fallbacks, a conditional physics dispatcher, an alternate
physics response initializer, and five compact SN runtime initialization
helpers. All affected complete source units pass compiler/relocation checks;
full-image linkage and packed retail ELF hashes match exactly. The math-wrapper
compiler probes still differ and remain outside the credited catalog. Totals:
8,632 exact linked C routines and 532,952 / 3,293,696 bytes. Reconstructed data
remains 42,400 / 648,064 bytes.

## 2026-10-08 initializer and dispatch checkpoint

Added seven native routines (696 bytes): three selector/initializer variants,
a stance-restore transition, a zero-count motion completion handler, a callback
dispatcher, and a direction-dependent float offset. All affected source units
pass direct compiler verification; loaded-image linkage and packed retail ELF
remain byte-identical. Totals: 8,639 linked C routines and
533,648 / 3,293,696 bytes, with reconstructed data unchanged at
42,400 / 648,064 bytes.

## 2026-10-08 runtime field checkpoint

Added thirteen native C routines (524 bytes): a state action callback, three
packed-field conversions, two global-pair setters, three pointer-table/indexed
field routines, two initializer variants, and two conditional state helpers.
All affected units verify exactly; full hybrid and packed ELF hashes pass.
Totals: 8,652 linked C routines and 534,172 / 3,293,696 bytes; reconstructed
data remains 42,400 / 648,064 bytes.

Separately, Linux EE GCC 2.96-ee-001003-1 reproduces seven early math wrappers
(140 bytes) with -O2 -G0 -ffunction-sections. Those private probes remain
uncredited until the reproducible compiler recipe and linkage are integrated.

## 2026-10-08 EE runtime compiler integration

Integrated seven native math wrappers (140 bytes) with EE GCC
2.96-ee-001003-1 -O2 -G0 -ffunction-sections. The reproducible runner and
checksum-pinned compiler are included in the build inputs. Both native Linux
and Mac VM runner paths pass relocation-aware comparisons for every wrapper.
Bootstrap smoke tests, catalog validation, full loaded-image linkage, and
packed retail ELF identity pass. Totals: 8,659 linked C routines and
534,312 / 3,293,696 bytes; reconstructed data is unchanged.

## 2026-10-08 state and callback integration

Added fifteen native routines (1,220 bytes): six comparison/flag/mask/state
helpers, eight initializer/countdown/reference/physics/callback routines, and
a signed-byte normalizer. Every affected complete source unit passes exact
compiler and relocation comparisons. Catalog validation, full loaded-image
linkage, and packed retail ELF hashes pass. An unrelated 0x002CEC90 catalog
entry from merge context was excluded because its source change and proof were
not part of the integrated batch. Unverified 0x002958C0 remains uncredited.
Totals: 8,674 exact linked C routines and 535,532 / 3,293,696 bytes;
reconstructed data is unchanged at 42,400 / 648,064 bytes.

## 2026-10-08 countdown and catalog validation

Added two native routines (232 bytes): a four-field motion countdown and
a conditional selector initializer. All affected source units verify exactly;
full hybrid and retail ELF hashes pass. Totals: 8,676 linked C routines and
535,764 / 3,293,696 bytes, with data unchanged.

An actual merge-conflict catalog exposed silent omission of malformed CSV
rows. Both compiler and report loaders now reject missing/extra fields before
status filtering. The regression test covers conflict markers and broken
CSV rows through both loaders; all 33 tests pass. Valid assembly placeholders
still remain uncredited.

## 2026-10-08 typed EE thunk and dispatch checkpoint

Added twenty-one native routines (608 bytes): eighteen EE96 wrappers with
caller/callee-supported argument and return contracts, two selector
initializers, and a complete state dispatcher. Corrected the dispatch boundary
to include its full 40-byte body and identified the next callback at 0x002C2C40
after the 8-byte gap. Entire affected source units pass relocated compiler
comparisons; full hybrid and packed retail ELF hashes match exactly.
Totals: 8,697 linked C routines and 536,372 / 3,293,696 bytes. Data remains
42,400 / 648,064 bytes. The 204-byte restoring-square-root C probe matches
size but differs in scheduling/register allocation, so remains uncredited.

## 2026-10-08 motion, initializer, and matrix checkpoint

Added fourteen native routines (2,824 bytes), including a 304-byte motion
update, three particle initializers totaling 588 bytes, a 900-byte 4x4
row-by-column matrix multiply, and supporting state/callback routines.
Every affected complete source unit passes independent compiler and relocation
checks. Full hybrid loaded-image and packed retail ELF hashes pass. Totals:
8,711 linked C routines and 539,196 / 3,293,696 bytes. Reconstructed data
remains 42,400 / 648,064 bytes.

Rechecked boundary evidence using virtual_address - 0x00100000, after a worker
found a header-offset error in an exploratory scan. Fixed pointer words,
direct calls/jumps, and nearby HI/LO address loads show no references to the
discarded interior entries 0x00303030, 0x002C5C58, 0x002C2824, and 0x002C2C2C.
The actual entries have expected table/call references; e.g. 0x00303000 at
0x0045CA04 and 0x00302FE4, 0x002C27A0 at 0x004C0DFC, and 0x002C2C40 at
0x00459B30. Compiler-exact complete spans and these references support the
existing boundary corrections.

## 2026-10-08 callback and initialized-data checkpoint

Added eleven native callbacks (568 bytes), covering table-verified tail entries,
view-angle results, command resets, and motion setup. All affected complete
source units verify exactly.

Added 2,620 reconstructed initialized-data bytes across consumer-backed vector
pairs/presets, scale arrays and records, relative streams, signed-short value
tables, position offsets, and boot string payloads. Unsupported prefixes,
suffixes, inter-pair gaps, and string alignment remain placeholder. The proposed
288-byte vector bank was reduced to its four consumed 24-byte pairs; the
224-byte boot pool credits only 184 payload/NUL bytes. These corrected catalogs
were integrated before reporting progress.

Every changed data owner was independently compiled and compared against
retail. Generated data-symbol addresses, catalog validation, full hybrid link,
and packed retail ELF hashes pass. Totals: 8,722 linked C routines,
539,764 / 3,293,696 C bytes, and 45,020 / 648,064 reconstructed data bytes.

## 2026-10-08 continued state callback checkpoint

Added twenty native routines (1,892 bytes) for state/event initialization,
input helpers, boundary resets, movement ramps, inhibit gates, and conditional
updates. Entire affected source units pass independent compiler/relocation
checks. Catalog validation, full loaded-image linkage, and packed retail ELF
hashes pass. Totals: 8,742 linked C routines and 541,656 / 3,293,696 bytes.
Reconstructed data remains 45,020 / 648,064 bytes at this integrated checkpoint;
newer worker data batches remain pending independent integration.

## 2026-10-08 typed runtime and diagnostic string checkpoint

Added thirteen EE96 wrappers (260 bytes) with supported scalar, callback,
context, cleanup, string, and validation signatures. Their entire source
units pass relocated-byte comparisons. Added 3,230 referenced startup and
diagnostic string payload/NUL bytes; unsupported fragments, binary records,
and every alignment gap remain placeholder. All 176 changed data owners
were independently compiled and byte-verified. Full hybrid and packed retail
ELF hashes pass. Totals: 8,755 linked C routines and 541,916 / 3,293,696 code
bytes; reconstructed data is 48,250 / 648,064 bytes.

## 2026-10-08 selector and reset callback checkpoint

Added twelve native routines (1,300 bytes), including parity-selected modes,
a callback-return gate, split compiler/source inventory registration, position
resets, selector updates, and latched vertical motion. Entire affected source
units pass independent relocated-byte verification. The state-return family
uses its proven MWCCPS2 3.0 -O4 recipe. Catalog validation, full hybrid, and
packed retail ELF hashes pass. Totals: 8,767 linked C routines and
543,216 / 3,293,696 code bytes. Data remains 48,250 / 648,064 at this
integrated checkpoint; later worker data is pending verification/linkage.

## 2026-10-08 filesystem and resource diagnostics

Added 4,131 reconstructed initialized-data bytes from directly referenced
filesystem, SRD, DVCI, DTR, and DTX diagnostic/path/format string payloads and
NUL terminators. All alignment gaps and unsupported fragments remain
placeholder. Every one of the 250 changed data owners was independently
compiled and compared against retail. Catalog validation, full hybrid loaded
image, and packed retail ELF hashes pass. Reconstructed data is now
52,381 / 648,064 bytes; linked C remains 543,216 / 3,293,696 bytes.

## 2026-10-08 owner and attachment callback checkpoint

Added six native routines (764 bytes): a vertical-angle mode callback, paired
owner boundary callbacks, paired attachment dispatchers, and a chained minor
action. The complete merged source unit passes independent relocated-byte
verification. Catalog validation, full hybrid loaded image, and packed retail
ELF hashes pass. Totals: 8,773 linked C routines and
543,980 / 3,293,696 code bytes. Integrated reconstructed data remains
52,381 / 648,064 bytes; later worker batches are pending consolidation.

## 2026-10-08 referenced status text and indexed floats

Added 607 reconstructed data bytes: referenced paths, serial/status formats,
UI labels and icon/resource names, parser-supported file-mode strings, the
sound-driver version message, and a bounded three-row/four-column float table
read by the movement routine. Payload/NUL bytes are credited; all string
alignment and unknown neighboring data remain placeholders. Every changed
data owner passes independent compiler/byte verification. Catalog validation,
full hybrid, and packed retail ELF hashes pass. Data is now
52,988 / 648,064 bytes; C remains 543,980 / 3,293,696 bytes.

## 2026-10-08 boundary callbacks and vector cache family

Added eleven native routines (1,340 bytes): indexed boundary resets, chained
motion, velocity stance and signed-angle callbacks, a zero-motion wrapper,
and the vector-cache comparison/store/reset family (264/104/88 bytes).
Recorded the distinct MWCCPS2 3.0 comparison recipe and 3.0.3 store/reset
recipes in the build runner. The canonical rename of an existing verified
0x00230320 callback adds no byte credit. All affected complete source units
verify exactly; catalog, full hybrid, and packed retail ELF hashes pass.
Totals: 8,784 linked C routines and 545,320 / 3,293,696 bytes. Integrated
data remains 52,988 / 648,064 bytes.

## 2026-10-08 flag masks and consumed float-vector data

Added 348 reconstructed initialized-data bytes: eight short masks and bounded
scalar/pair/triple float spans used by movement, interpolation, animation,
and startup routines. C/assembly reads establish the specific field widths
and ranges; unsupported neighbors remain raw placeholders. Every changed
data owner passes independent compiler and byte comparison. Catalog validation,
full hybrid loaded image, and packed retail ELF hashes pass. Reconstructed
data is 53,336 / 648,064 bytes; linked C stays 545,320 / 3,293,696 bytes.

## 2026-10-08 signed callbacks and canonical entry labels

Added three native callbacks (288 bytes): signed motion setup, negative-result
reset logic, and a table-backed signed-result dispatcher. Corrected canonical
code names for 91 already verified callback wrappers in dispatch, tail, and
sequential families; those renames add no bytes. Entire affected source units
pass independent relocated-byte verification. Catalog validation, full hybrid
loaded-image linkage, and packed retail ELF hashes pass. Totals: 8,787 linked
C routines and 545,608 / 3,293,696 bytes. Data stays 53,336 / 648,064 bytes.

## 2026-10-08 bounded transition and state-default data

Added 168 reconstructed initialized-data bytes: directly loaded transition
float vectors/scalars, threshold constants, runtime float state values,
position/state-default shorts, and bounded indexed short values. For the
index*4 short tables only the LH-consumed halfwords are typed; the other
halfwords remain placeholders. Every changed data owner independently compiles
and byte-matches retail. Catalog validation, full hybrid, and packed retail
ELF hashes pass. Data totals 53,504 / 648,064 bytes; C stays
545,608 / 3,293,696 bytes.

## 2026-10-08 signed motion-vector callback checkpoint

Added eleven native callbacks (1,388 bytes): signed velocity/vector setup,
conditional state advance, motion resets, and a signed-result active-object
gate. The full motion source unit verifies with MWCCPS2 3.0.3
-O4 -Op -sdatathreshold 0; the signed-result source unit also verifies exactly
with its recorded O3 recipe. Catalog validation, full hybrid loaded-image
linkage, and packed retail ELF hashes pass. Totals: 8,798 linked C routines
and 546,996 / 3,293,696 bytes. Integrated data remains
53,504 / 648,064 bytes; later worker batches are pending consolidation.

## 2026-10-08 bounded renderer profiles and key data

Added 446 reconstructed initialized-data bytes: directly consumed profile
float triples/selectors/short defaults, renderer vector rows, bounded
frame-selected vectors, interpolation key pairs, indexed scalar offsets,
zero/vector defaults, and timing constants. Only observed ranges and fields
are typed; all unconsumed profile bytes, skipped table fields, and neighboring
zero regions stay placeholders. Every changed data owner independently
compiles and byte-matches retail. Catalog validation, full hybrid loaded
image, and packed retail ELF hashes pass. Data is now
53,950 / 648,064 bytes; C stays 546,996 / 3,293,696 bytes.

## 2026-10-08 motion callback checkpoint

Added eight exact native C motion callbacks totaling 1,200 bytes. The full
positioned-motion source unit verifies with MWCCPS2 3.0.3 -O4 -Op
-sdatathreshold 0. Catalog validation, the complete hybrid loaded-image
relink, and packed retail ELF hashes pass. Linked C coverage is now
548,196 / 3,293,696 bytes (16.6438%), across 8,806 functions.
Initialized reconstructed data remains 53,950 / 648,064 bytes.
Unmatched retail spans remain placeholders; full decompilation is incomplete.

## 2026-10-08 callback and consumed-float consolidation

Added five exact native C callbacks totaling 616 bytes, with complete
positioned-motion and round3_0 source-unit compiler verification. Added
240 reconstructed initialized-data bytes from concrete floating-point
loads/stores and bounded vector fields. All 78 changed data owners and
the consolidated mutable animation float array byte-match retail.
Catalog validation, full hybrid linkage, and packed retail ELF hashes pass.
Totals: 8,811 linked C routines, 548,812 / 3,293,696 code bytes (16.6625%),
and 54,190 / 648,064 data bytes (8.3618%) across 1,855 reconstructed units.
The remaining retail spans remain uncredited placeholders.

## 2026-10-08 effect-state pair data

Recovered sixteen consumed two-float state pairs, adding 128 initialized
data bytes. Fixed swc1 destinations establish the field types and bounds;
intervening gaps and suffixes stay raw placeholders. All 32 changed data
owners compile and match retail bytes. Catalog validation, full hybrid
linkage, and packed retail ELF hashes pass. Code remains 548,812 bytes
(16.6625%); reconstructed data is 54,318 / 648,064 bytes (8.3816%).

## 2026-10-08 velocity and animation-state checkpoint

Added the exact 132-byte callback func_00270330 and eight consumed
two-float animation-state pairs (64 bytes). The entire positioned-motion
source unit and all 17 changed data owners verify against retail. Catalog
validation, full hybrid linkage, and packed retail ELF hashes pass.
Totals: 8,812 linked C routines and 548,944 code bytes (16.6665%);
reconstructed data is 54,382 / 648,064 bytes (8.3915%).

## 2026-10-08 signed speed callbacks

Added func_0027D8D0 and func_0026C560, totaling 248 exact native C bytes.
The complete positioned-motion unit compiles with MWCCPS2 3.0.3
-O4 -Op -sdatathreshold 0 and byte-matches retail. Catalog validation,
full hybrid loaded-image linkage, and packed retail ELF hashes pass.
Totals: 8,814 linked C routines and 549,192 / 3,293,696 bytes (16.6740%).
Reconstructed initialized data remains 54,382 / 648,064 bytes (8.3915%).

## 2026-10-08 TIM2 writer and vector callback families

Recovered the complete 504-byte TIM2 header writer at 00416290 with
MWCCPS2 3.0-011126 -O3 -sdatathreshold 0. Its normal compiler recipe is
now part of compile_matching.sh. Also recovered four table-backed native
C direction/vector callbacks totaling 524 bytes; the full positioned-motion
unit verifies with MWCCPS2 3.0.3 -O4 -Op -sdatathreshold 0.
All 33 tests, catalog validation, full hybrid loaded-image linkage, and
packed retail ELF hashes pass. Totals: 8,819 linked C routines and
550,220 / 3,293,696 code bytes (16.7052%). Reconstructed initialized
data remains 54,382 / 648,064 bytes (8.3915%).

## 2026-10-08 append-words writer and bounded animation records

Added the complete 208-byte append-words buffer writer at 00423AA0,
verified with MWCCPS2 3.0.3 -O3 -sdatathreshold 8 and included in the
normal compiler runner. Four additional table-backed motion callbacks
add 564 exact C bytes; the entire source unit verifies with O4/Op.
Recovered 248 initialized-data bytes from a 28-byte-stride float table.
The initializer sets index 1, the updater stores index+1, and its
termination check prevents reading index 8: actual read indices are
1 through 7. Their consumed field-address union supports all 62 words
without gaps; the prefix and suffix remain placeholders. All changed
data owners byte-match retail. Catalog validation, full hybrid linkage,
and packed retail ELF hashes pass. Totals: 8,824 linked C routines,
550,992 code bytes (16.7287%), and 54,630 data bytes (8.4297%).

## 2026-10-08 paired angle callback

Added the complete 164-byte native C callback func_0023B670. Its
positioned-motion source unit verifies under MWCCPS2 3.0.3 -O4 -Op
-sdatathreshold 0. Catalog validation, full hybrid loaded-image linkage,
and packed retail ELF hashes pass. Linked C is 551,156 / 3,293,696
bytes (16.7337%) across 8,825 functions; reconstructed data remains
54,630 / 648,064 bytes (8.4297%).

## 2026-10-08 address remapping and signed callback checkpoint

Added the complete 40-byte address remapping leaf func_00102520.
SN GCC 2.95.2 -O2 -G0 -ffunction-sections produces its exact native C
object; the recipe is now in the normal compiler runner. Four additional
state-gated callbacks add 564 exact C bytes under the recorded full-unit
MWCCPS2 O4/Op recipe. Recovered two bounded stage mapping payloads
(count byte plus 17 mapping bytes each), totaling 36 data bytes; alignment
and neighboring fields stay placeholders. All changed data owners verify.
Catalog validation, full hybrid linkage, and packed retail ELF hashes pass.
Totals: 8,830 linked C routines, 551,760 code bytes (16.7520%), and
54,666 reconstructed data bytes (8.4353%) across 1,882 units.

## 2026-10-08 callback classification and signed movement

Corrected five already-exact callback manifest rows from assembly
residual to code; these receive no additional credit. The entire
duplicate-family object independently byte-verifies. Added the complete
108-byte native C func_002EEEE0; the full positioned-motion source unit
verifies with MWCCPS2 3.0.3 -O4 -Op -sdatathreshold 0. Catalog validation,
full hybrid linkage, and packed retail ELF hashes pass. Totals:
8,831 linked C routines and 551,868 / 3,293,696 bytes (16.7553%);
reconstructed data remains 54,666 / 648,064 bytes (8.4353%).

## 2026-10-08 bounded lookup and UI byte fields

Recovered the complete 40-byte bounded lookup func_00102580 with SN GCC
2.95.2 -O2 -G0 -ffunction-sections; its recipe is in the normal runner.
Renamed three already-exact motion table entries from residual symbols
to their function names and corrected manifest classifications, with no
additional byte credit; the entire changed source object verifies.
Recovered only sixteen consumed byte fields from the UI ID table.
The selector mask bounds indices to 0..15 and the reader uses lbu at
stride four; all 48 upper bytes remain placeholders. This supersedes
the unintegrated u32-table proposal. All 33 changed data owners verify.
Catalog validation, full hybrid linkage, and packed retail ELF hashes
pass. Totals: 8,832 linked C routines, 551,908 code bytes (16.7565%),
and 54,682 reconstructed data bytes (8.4377%) across 1,898 units.

## 2026-10-08 record copy leaf

Recovered the complete 56-byte native C record-copy function 00102860.
A naturally four-byte-aligned 20-byte record reproduces the observed
unaligned doubleword pairs and final word copy. SN GCC 2.95.2 -O2 -G0
-ffunction-sections byte-verifies exactly; its normal runner recipe is
included. Catalog validation, full hybrid linkage, and packed retail ELF
hashes pass. Totals: 8,833 linked C routines, 551,964 code bytes
(16.7582%), and 54,682 reconstructed data bytes (8.4377%).

## 2026-10-08 bounded UI byte maps

Recovered three 16-byte UI maps and sixteen low-byte fields from a
four-byte-stride ID table, adding 64 initialized-data bytes. The setup
paths use func_00220260, whose 0x3C00 bitfield decode returns 0..15;
one caller additionally masks the stored selector with 0xF. Padding
remains raw, and B71E0 stays uncredited because its different selector
range is unknown. All 36 changed data owners byte-verify. All 33 tests,
catalog validation, full hybrid linkage, and packed retail ELF hashes
pass. C remains 551,964 bytes (16.7582%); reconstructed data is
54,746 / 648,064 bytes (8.4476%).

## 2026-10-08 large motion dispatch callback

Recovered the complete 444-byte native C func_002DA6C0. Its state
initialization, GP-relative counter update, vector integration, clamp,
and signed callback transitions compile exactly with MWCCPS2 3.0.3
-O3 -sdatathreshold 8 in the established grok_w5_0030 unit. The whole
source unit byte-verifies. Catalog validation, full hybrid linkage, and
packed retail ELF hashes pass. Totals: 8,834 linked C routines and
552,408 / 3,293,696 bytes (16.7717%); reconstructed data remains
54,746 / 648,064 bytes (8.4476%).

## 2026-10-08 MMIO exchange and dispatch targets

Recovered the complete 20-byte MMIO exchange func_00102898 as native C
with volatile load/store semantics. EE GCC 2.96 -O2 -G0
-ffunction-sections matches exactly, and its normal runner recipe is
included. Added func_002DA8A0 (232 bytes) under the established
grok_w5_0030 O3/sdata8 recipe and func_002DB7D0 (104 bytes) under the
full positioned-motion O4/Op recipe. All changed source units byte-verify.
Catalog validation, full hybrid linkage, and packed retail ELF hashes
pass. Totals: 8,837 linked C routines and 552,764 / 3,293,696 bytes
(16.7825%); reconstructed data remains 54,746 bytes (8.4476%).

## 2026-10-08 three-float copy and audio lookup

Recovered the complete 28-byte three-float copy func_001037B8 with
SN GCC 2.95.2 -O2 -G0 -ffunction-sections and added its runner recipe.
Renamed an already-exact dispatcher callback without additional credit.
Recovered the bounded 256-entry float lookup at BBA88 (1,024 bytes).
The compressed-input lbu bounds indices to 0..255; table values load
through lwc1 and feed mul.s. The nearby cvt.s.w converts an independent
block scale, so the initial s32 proposal was corrected to float before
canonical verification. The changed data object byte-matches retail.
Catalog validation, full hybrid linkage, and packed retail ELF hashes
pass. Totals: 8,838 linked C routines, 552,792 code bytes (16.7833%),
and 55,770 reconstructed data bytes (8.6056%) across 1,918 units.

## 2026-10-08 paired audio lookup and stage format

Recovered the second bounded 256-entry float lookup at BB688, adding
1,024 initialized-data bytes. The same compressed-input byte indices
prove 0..255; lwc1 results feed float multiplication. Its complete
0x400-byte source owner replaces the old split zero/raw placeholders,
while the preceding raw prefix remains uncredited. Also recovered only
the 15-byte stage debug format payload plus NUL, preserving its raw
prefix and suffix. Every changed owner byte-verifies with the normal
MWCCPS2 3.0.3 O3/sdata0 data recipe. Catalog validation, full hybrid
linkage, and packed retail ELF hashes pass. Code remains 552,792 bytes
(16.7833%); reconstructed data is 56,809 / 648,064 bytes (8.7660%)
across 1,920 units.

## 2026-10-08 motion reset and lifetime callbacks; loader messages

Added two complete native C callbacks totaling 436 bytes: 002DB880
under the established grok_w5_0030 O3/sdata8 recipe, and 002DB130 under
the full positioned-motion O4/Op recipe. Both entire source units verify.
Recovered four texture diagnostics and one BMP diagnostic, totaling
250 initialized-data bytes. Credit includes each consumed string payload
plus NUL only; intervening raw bytes and suffixes remain placeholders.
Every changed data owner byte-verifies, and superseded byte-array
sources are removed. Catalog validation, full hybrid linkage, and packed
retail ELF hashes pass. Totals: 8,840 linked C routines, 553,228 code
bytes (16.7966%), and 57,059 data bytes (8.8045%) across 1,925 units.

## 2026-10-08 timed callback and ADX diagnostics

Added the complete 112-byte native C callback func_002DB920; the entire
positioned-motion source unit byte-verifies under its O4/Op/sdata0 recipe.
Recovered 45 directly consumed diagnostic/signature payloads from the
audio/BMP string pool, adding 1,881 initialized-data bytes. Each char
owner ends at its NUL terminator; all 39 intervening raw gaps remain
placeholders. All 84 changed data owners independently compile and
byte-match retail. Catalog validation, full hybrid linkage, and packed
retail ELF hashes pass. Totals: 8,841 linked C routines, 553,340 code
bytes (16.8000%), and 58,940 data bytes (9.0948%) across 1,970 units.

## 2026-10-08 mode flags, state initialization, and bounded decode data

Recovered complete native C functions 0041DE10 (268 bytes; MWCCPS2
3.0.3 O3/sdata8, with normal runner recipe) and 002F03F0 (136 bytes;
full motion-speed-transition O4/Op/sdata8 unit). Both source units verify
exactly. Recovered a 16-entry signed-nibble lookup bounded by &0xF,
an eight-byte double consumed by the double-multiply helper, and a
4x4 byte swizzle map with selectors masked to &3. These add 88 data
bytes; all remaining gaps stay placeholders. Every changed data owner
byte-verifies. All 33 tests, catalog validation, full hybrid linkage, and
packed retail ELF hashes pass. Totals: 8,843 linked C routines,
553,744 code bytes (16.8122%), and 59,028 data bytes (9.1084%).

## 2026-10-08 GP-backed callback and six-ID map

Added the complete 152-byte native C callback func_002E5F00. The
entire motion-speed-transition source unit verifies with MWCCPS2 3.0.3
-O4 -Op -sdatathreshold 8. Recovered six bounded u32 IDs from B6A30,
adding 24 data bytes: the consumer reads full words using selectors
resolved to the current or earlier iteration of an outer 0..5 loop.
The remaining 440 bytes stay raw. Both changed data owners byte-match.
Catalog validation, full hybrid linkage, and packed retail ELF hashes
pass. Totals: 8,844 linked C routines, 553,896 code bytes (16.8169%),
and 59,052 data bytes (9.1121%) across 1,974 reconstructed units.

## 2026-10-08 indexed slots and ADXT diagnostics

Recovered native C getter/setter functions 00105F10 and 00105F28,
totaling 52 bytes. Their whole source unit matches with SN GCC 2.95.2
-O2 -G0 -ffunction-sections; the normal runner recipe is included.
Renamed an already-exact preaction tail callback with no extra credit;
its whole source object verifies. Recovered 45 ADXT diagnostic strings
and the consumed 0.85 double scalar, adding 1,952 data bytes. String
owners end at NUL; all 42 raw gaps remain placeholders. Every one of
the 88 changed data owners independently byte-verifies. Catalog
validation, full hybrid linkage, and packed retail ELF hashes pass.
Totals: 8,846 linked C routines, 553,948 code bytes (16.8184%), and
61,004 data bytes (9.4133%) across 2,020 reconstructed units.

## 2026-10-08 signed-speed callback and device format maps

Added the complete 140-byte native C callback func_002D3270, verified
with the whole motion-speed-transition O4/Op/sdata8 source unit.
Recovered three stream-open diagnostics (134 bytes) and two six-entry
u32 device-format maps (48 bytes). Each diagnostic owner ends at NUL;
the map readers check the byte selector <6 before loading full words.
All remaining gaps and the neighboring unbounded table stay raw.
Every changed data owner independently byte-verifies. Catalog
validation, full hybrid linkage, and packed retail ELF hashes pass.
Totals: 8,847 linked C routines, 554,088 code bytes (16.8227%), and
61,186 data bytes (9.4414%) across 2,025 reconstructed units.

## 2026-10-08 indexed record store and boot strings

Added the complete 28-byte native C record-indexed word store
func_00105EE0 to the existing indexed-slot source unit. All three
functions in that unit byte-verify with SN GCC 2.95.2 -O2 -G0
-ffunction-sections. Recovered ten directly consumed module/config
and texture-diagnostic strings, adding 324 initialized-data bytes.
Every string owner ends at NUL; all ten intervening gaps stay raw.
All 20 changed data owners independently compile and byte-match.
Catalog validation, full hybrid linkage, and packed retail ELF hashes
pass. Totals: 8,848 linked C routines, 554,116 code bytes (16.8235%),
and 61,510 data bytes (9.4913%) across 2,035 reconstructed units.

## 2026-10-08 state header initialization and fixed label

Added the complete 36-byte native C state-header initializer
func_00105020 to the existing SN-compiled source unit. All four functions
in that unit byte-verify with SN GCC 2.95.2 -O2 -G0 -ffunction-sections.
Recovered only four fixed WINS character bytes, consumed individually
by a proven 0..3 loop; neighboring labels and padding stay raw. All
three changed data owners independently byte-match. Catalog validation,
full hybrid linkage, and packed retail ELF hashes pass. Totals:
8,849 linked C routines, 554,152 code bytes (16.8246%), and 61,514
data bytes (9.4920%) across 2,036 reconstructed units.

## 2026-10-08 bounded variants and battle labels

Recovered a 4x6 byte effect-type variant matrix (24 bytes). Its reader
masks the row selector with 3, scales by six, and reads each of six
column bases. Recovered five formatter-consumed battle labels/formats
(59 bytes), including only their exact payloads plus NUL. All remaining
mixed-table bytes and string gaps stay placeholders. Every one of the
12 changed data owners independently byte-verifies. Catalog validation,
full hybrid linkage, and packed retail ELF hashes pass. Code remains
554,152 bytes (16.8246%); reconstructed data is 61,597 / 648,064 bytes
(9.5048%) across 2,042 units.

## 2026-10-08 palette tuples and result labels

Recovered a bounded 20x3 byte palette tuple table (60 bytes), whose
reader computes index*3 and whose caller scans indices <20. Recovered
seven directly formatter-consumed result labels/formats (59 bytes),
including exact payloads plus NUL only. All remaining table bytes,
neighboring constants, and eight label gaps stay raw placeholders.
All 18 changed data owners independently compile and byte-match.
Catalog validation, full hybrid linkage, and packed retail ELF hashes
pass. C remains 554,152 bytes (16.8246%); reconstructed data is
61,716 / 648,064 bytes (9.5231%). Native C palette-consumer drafts
remain uncredited because full compiler matching is not yet achieved.

## 2026-10-08 nested callback context ABI and menu labels

Recovered func_002FE8D0 (144 bytes) and the complete 40-byte dispatch
head func_002FF2A0. Retail tracing proves the outer head computes
context = object+696 and passes it through the C1C0/C170 dispatch path.
Six affected tables, their heads, and reconstructed members now declare
that second pointer consistently; unused contexts are explicit parameters.
All six changed code units and ten data owners independently byte-verify.
The new typed outer callback table adds 28 reconstructed data bytes;
two menu labels add 34 bytes with payload-plus-NUL credit only.
Added the missing O4/Op/sdata0 runner recipe for all 13 already-credited
animation-position callbacks. The other credited sources are covered by
existing direct recipes or compiler loops. All 33 tests, catalog
validation, full hybrid linkage, and packed retail ELF hashes pass.
Totals: 8,851 linked C routines, 554,336 code bytes (16.8302%), and
61,778 data bytes (9.5327%) across 2,053 reconstructed units.

## 2026-10-08 packet marker and motion callback batch

Recovered the complete 108-byte packet queue marker writer 00423650
with MWCCPS2 3.0.3 O3/sdata8 and added its normal runner recipe. Seven
additional typed motion callbacks add 932 exact native C bytes under
the existing full-unit O4/Op recipes. The shared 001757E0 helper retains
its int third parameter; an observed byte truncation is explicit at the
caller. All three source units independently byte-verify. The three
D_00630000 views now extend to the actual BSS end at 00634380, covering
all queue slots; this type-extent correction preserves exact code bytes.
Every affected region-view unit verifies again. Catalog validation, full
hybrid linkage, and packed retail ELF hashes pass. Totals: 8,859 linked
C routines and 555,376 code bytes (16.8618%); reconstructed initialized
data remains 61,778 bytes (9.5327%).

## 2026-10-08 SDK diagnostic and format strings

Recovered 45 directly consumed SDK diagnostic, format, path, and token
strings, adding 1,288 initialized-data bytes. Each owner ends at its
actual NUL terminator; all 43 intervening raw gaps/constants remain
placeholders. All 88 changed data owners independently compile and
byte-match retail. Catalog validation, full hybrid linkage, and packed
retail ELF hashes pass. Code remains 555,376 bytes (16.8618%);
reconstructed data is 63,066 / 648,064 bytes (9.7314%) across 2,098
units. Decompilation and full source linkage remain incomplete.

## 2026-10-08 packet writer and queue-state batch

Recovered seven complete native C packet/queue functions totaling
836 bytes. Their recorded MWCCPS2 3.0.3 O3 recipes use sdata0 or
sdata8 as appropriate and are now in the normal runner. The queue
validator explicitly forwards its two caller-provided arguments, and
all region aliases use the actual BSS extent. Fixed a missing signed
cursor typedef before canonical compilation. Every complete source
unit independently byte-verifies; all 33 tests, catalog validation, full
hybrid linkage, and packed retail ELF hashes pass. Totals: 8,866
linked C routines and 556,212 code bytes (16.8872%). Reconstructed
data remains 63,066 bytes (9.7314%); full decompilation is incomplete.

## 2026-10-08 disc and memory-card diagnostics

Recovered 25 directly consumed CD/DVD/Memory Card diagnostic and
format strings, adding 606 initialized-data bytes. Only exact payloads
plus NUL count; all 21 raw gaps and binary suffixes remain placeholders.
All 46 changed owners independently compile and byte-match retail.
Catalog validation, full hybrid linkage, and packed retail ELF hashes
pass. Code remains 556,212 bytes (16.8872%); reconstructed data is
63,672 / 648,064 bytes (9.8250%) across 2,123 units.

## 2026-10-08 bounded scoreboard prefix and additional diagnostics

Recovered only the three consumed WIN prefix characters; the remaining
S and NUL stay raw because the reader stops at index2. Added fourteen
directly consumed miscellaneous strings and two BMP diagnostics, with
exact payload-plus-NUL ownership and all gaps preserved. Together this
adds375 reconstructed data bytes. All42 changed owners independently
compile and byte-match retail. Catalog validation, full hybrid linkage,
and packed retail ELF hashes pass. Code remains556,212 bytes(16.8872%);
reconstructed data is64,047/648,064 bytes(9.8828%) across2,140 units.

## 2026-10-08 bounded leading-byte lookup tables

Recovered four 256-entry byte lookup tables, adding 1,024 data bytes.
Their divide/normalize consumers choose shifts of 0, 8, 16, or 24
after unsigned thresholds, so each lookup index is bounded to 0..255.
The raw prefix stays uncredited. All five changed data owners compile
and byte-match retail. Catalog validation, full hybrid linkage, and
packed retail ELF hashes pass. Code remains 556,212 bytes (16.8872%);
reconstructed data is 65,071 / 648,064 bytes (10.0408%) across 2,144 units.

## 2026-10-08 consolidated motion callback batch

Added ten complete native C callbacks totaling 1,292 bytes. Both full
source units independently byte-verify with MWCCPS2 3.0.3 -O4 -Op,
using sdata0 for positioned_motion_constants and sdata8 for
motion_speed_transition. Catalog validation, full hybrid linkage, and
packed retail ELF hashes pass. Totals: 8,876 linked C routines and
557,504 code bytes (16.9264%). Reconstructed initialized data remains
65,071 bytes (10.0408%); full decompilation remains incomplete.

## 2026-10-08 exact float callback batch

Added four complete native C callbacks totaling 612 bytes, using exact
retail float values and the established MWCCPS2 3.0.3 O4/Op recipe.
The animation helper retains its supported int return signature, and
caller narrowing is explicit where required. All three affected source
units independently byte-verify. Catalog validation, full hybrid linkage,
and packed retail ELF hashes pass. Totals: 8,880 linked C routines and
558,116 code bytes (16.9450%). Reconstructed data remains 65,071 bytes
(10.0408%); full decompilation remains incomplete.

## 2026-10-08 packet queue initializer

Recovered the complete 84-byte native C queue initializer 00422CC0.
MWCCPS2 3.0-011126 O3/sdata0 with supported padloop pragma matches
the retail loop exactly, and its normal compiler recipe is included.
Whole-function verification, catalog validation, full hybrid linkage,
and packed retail ELF hashes pass. Totals: 8,881 linked C routines and
558,200 code bytes (16.9475%). Data remains 65,071 bytes (10.0408%).

## 2026-10-08 motion selector and state callbacks

Added seven complete native C callbacks totaling 564 bytes. The three
complete affected source units byte-verify under their recorded O3/sdata8
or O4/Op recipes. Additive merge resolution preserved canonical source
and excluded unrelated stale-branch context. Catalog validation, full
hybrid linkage, and packed retail ELF hashes pass. Totals: 8,888 linked
C routines and 558,764 code bytes (16.9647%). Data remains 65,071 bytes
(10.0408%); full decompilation remains incomplete.

## 2026-10-08 shared animation-helper interface audit

Aligned legacy caller declarations in 116 source files with the canonical
int func_001757E0(u8 *, int, int) interface. This restores consistent
return and argument contracts without adding byte credit. Every changed
unit was freshly compiled using its existing direct or loop-based recipe;
all 1,785 source-selected functions byte-verify exactly. All 33 tests,
catalog validation, full hybrid linkage, and packed retail ELF hashes
pass. Coverage remains 16.9647% code and 10.0408% data.

## 2026-10-08 graphics initialization records

Recovered five bounded 44-byte graphics initialization records, adding
220 data bytes. Packed u32 storage supports both the observed full-word
mask reads and the documented signed-halfword-pair view; no conflicting
s16-only representation remains. The trailing 20 bytes stay raw. All six
changed owners independently compile and byte-match. Catalog validation,
full hybrid linkage, and packed retail ELF hashes pass. Code remains
558,764 bytes (16.9647%); reconstructed data is 65,291 bytes (10.0748%)
across 2,149 units.

## 2026-10-08 state-transition callback batch

Added five complete native C callbacks totaling 824 bytes. The full
motion-speed-transition source unit independently byte-verifies with
MWCCPS2 3.0.3 -O4 -Op -sdatathreshold 8. Catalog validation, full
hybrid linkage, and packed retail ELF hashes pass. Totals: 8,893 linked
C routines and 559,588 code bytes (16.9897%). Reconstructed data remains
65,291 bytes (10.0748%); full decompilation remains incomplete.

## 2026-10-08 referenced callback entry boundary

Recovered the complete 24-byte callback 002350D0 from a previously
oversized residual span. The preceding four-byte alignment padding
is tracked separately and receives no C credit. Its whole dispatcher
source unit byte-verifies with the existing O3/sdata0 recipe. Catalog
validation, full hybrid linkage, and packed retail ELF hashes pass.
Totals: 8,894 linked C routines, 559,612 code bytes (16.9904%), and
65,291 reconstructed data bytes (10.0748%).

## 2026-10-08 callback argument-contract follow-up

Corrected fourteen wrappers to the one-pointer contract proven by
their actual target, removing unsupported unused forwarded arguments.
Preserved owner context through the second nested dispatch chain and
aligned the reconstructed handler with its table signature. Five full
code units and three table owners independently byte-verify. All 33
tests, catalog validation, full hybrid linkage, and packed retail ELF
hashes pass. These interface corrections add no credit; coverage remains
16.9904% code and 10.0748% data.

## 2026-10-08 exact callback inventory cleanup

Corrected naming/classification for 34 already-matched callback entries.
These were existing verified C spans, so no new byte credit is claimed.
All ten affected or supporting complete source units were freshly
compiled under their recorded recipes and byte-verified. Catalog
validation, full hybrid linkage, and packed retail ELF hashes pass.
Coverage remains 16.9904% code and 10.0748% initialized data.

## 2026-10-08 owner-context transition callback

Added the complete 128-byte native C callback 002F4BB0. Its second
parameter uses the dispatcher-compatible void-pointer context contract;
the full argument-dispatch source unit byte-verifies under the existing
MWCCPS2 O3/sdata8 recipe. Catalog validation, full hybrid linkage, and
packed retail ELF hashes pass. Totals: 8,895 linked C routines and
559,740 code bytes (16.9943%). Data remains 65,291 bytes (10.0748%).

## 2026-10-08 tagged record value writer

Recovered the complete 36-byte native C function 00420B00. Its caller
supplies the record pointer; observed fields are an output pointer at
offset0 and signed halfword at0x1C. The original O3/sdata8 compiler
recipe is included. Whole-function verification, catalog validation,
full hybrid linkage, and packed retail ELF hashes pass. Totals:
8,896 linked C routines and 559,776 code bytes (16.9954%). Data remains
65,291 bytes (10.0748%); full decompilation remains incomplete.

## 2026-10-08 launch initializer callback batch

Added three complete native C callbacks totaling 412 bytes. The full
fixed-launch source unit independently byte-verifies with its recorded
MWCCPS2 O3/Op/sdata0 recipe. Catalog validation, full hybrid linkage,
and packed retail ELF hashes pass. Totals: 8,899 linked C routines and
560,188 code bytes (17.0079%). Data remains 65,291 bytes (10.0748%).
The next scheduled publication threshold remains 21.0711% code.

## 2026-10-08 fixed-speed transition callback

Added the complete 128-byte native C callback 002F5F50. The full
motion-speed source unit byte-verifies under its recorded O4/Op/sdata8
recipe. Catalog validation, full hybrid linkage, and packed retail ELF
hashes pass. Totals: 8,900 linked C routines and 560,316 code bytes
(17.0118%). Data remains 65,291 bytes (10.0748%).

## 2026-10-08 child-state propagation callbacks

Added two complete native C callbacks totaling 388 bytes. The full
argument-dispatch source unit independently byte-verifies under its
recorded O3/sdata8 recipe. Catalog validation, full hybrid linkage, and
packed retail ELF hashes pass. Totals: 8,902 linked C routines and
560,704 code bytes (17.0236%). Data remains 65,291 bytes (10.0748%).

## 2026-10-08 direct transform and selector scalars

Recovered a directly consumed three-float transform vector and eight
individually accessed byte fields, adding 20 initialized-data bytes.
Only the observed scalar widths count; every neighboring gap and
unbounded lookup region stays explicitly placeholder-owned. All24
changed owners compile and byte-match. Catalog validation, full hybrid
linkage, and packed retail ELF hashes pass. Code remains560,704 bytes
(17.0236%); data is65,311 bytes(10.0779%) across2,158 reconstructed units.

## 2026-10-08 texture allocation diagnostics

Recovered seven directly consumed texture diagnostics, adding 456
initialized-data bytes. Exact payloads plus NUL are credited, including
terminators crossing old owner boundaries; all gaps remain placeholders.
All thirteen split owners independently compile and byte-match. Catalog
validation, full hybrid linkage, and packed retail ELF hashes pass.
Code remains560,704 bytes(17.0236%); reconstructed data is65,767 bytes
(10.1482%) across2,165 units.


### Animation result audit and runtime records

Corrected the canonical int return declaration across 100 whole translation units,
with explicit signed-byte narrowing where retail requires it. All 100 units
compile and verify exactly using the canonical compiler recipes. Three callers
that rely on helper-specific register preservation remain unresolved.

Added the 200-byte physics collision callback, 36-byte nonzero float flag setter,
and 68-byte tagged counter writer. Their compiled objects pass exact relocation
verification, and the hybrid image and packed executable match retail. Removed
a redundant callback build recipe after verifying its existing loop recipe.

Decimal and allocator data owners were individually compiled and byte-verified.
The unused powers-of-five entry stays placeholder-owned; the unbounded negative
exponent factor loop remains uncredited pending a domain proof. Corrected the
stale alignment-owner extent before accepting the split.

Code is 561,008 bytes (17.0328%); reconstructed data is 65,959 bytes
(10.1779%) across 2,172 units. Full source decompilation remains incomplete.


### Motion floor updates, math constants, and rendered text

Added two 160-byte floor handlers, an 88-byte animation state setter, and
two 244-byte directional motion updates. Both changed translation units
verify completely; the directional unit needs sdata8 for its GP-relative table.

Recovered 24 bytes of directly loaded conversion doubles, 32 bytes of
descriptor headers, 472 bytes of directly loaded math constants, 895 bytes
of legal notice strings, and 1,509 bytes of credits text and controls.
Every changed owner compiled and privately verified. Renderer loops prove
the legal string extents and credits stop byte; padding remains uncredited.
The credits initializer now uses readable text with explicit control escapes.

All 33 project tests pass. The hybrid loaded image and packed retail executable
match their reference hashes. Code is 561,904 bytes (17.0600%); reconstructed
data is 68,891 bytes (10.6303%) across 2,204 units. Full source decompilation
and linkage remain incomplete; unmatched spans still come from retail bytes.


### Event motion handlers and reentrant heap wrapper

Added four complete motion handlers totaling 768 bytes. Every function in
the changed unit remains exact with its canonical MWCC3.0.3 recipe.
Recovered the 88-byte reentrant SDK heap helper: it clears the SDK error,
requests heap growth, and copies a nonzero failure error into the caller field.
EE GCC2.96 plus the original SN assembler reproduces the full native unit;
the GNU assembler encodes its register moves differently. No generated
assembly or object bytes were patched. The build runner includes the proven recipe.

Typed 44 bytes of consumed counters, callbacks, allocation pointer, and renderer
state. Every changed owner was compiled and privately verified; residual
bytes remain explicit placeholders. Removed three superseded placeholder
sources from these splits. A queued vector table was held after the consumer
showed a next-frame read beyond its proposed extent.

The hybrid loaded image and packed retail executable match their references.
Code is 562,760 bytes (17.0860%); reconstructed data is 68,935 bytes
(10.6371%) across 2,215 units. Full source decompilation remains incomplete.


### Initialized motion states, driver startup, and sprite table extents

Added eight motion handlers totaling 1,792 bytes and the 236-byte packet
runtime initializer. All affected whole translation units compile and
relocation-verify exactly. The initializer uses MWCC3.0-011126 O3/sdata8;
its final version message uses the verified variadic printf contract.

Audited the sprite interpolator and reconstructed 42 rows of three floats
for both motion and rotation. Current row40 reads look-ahead row41 before
the stored index wraps. Six animation codes are also reconstructed.
The pair-table caller scans selectors0..58 and skips24..26, so only the
two consumed pair ranges count; the six skipped bytes remain placeholders.
Every changed data owner was freshly compiled and private-byte verified.

The hybrid image and packed executable match retail. Code is 564,788 bytes
(17.1475%); reconstructed data is 70,049 bytes
(10.8090%) across 2,219 units. Full source decompilation remains
incomplete. The next scheduled code push remains21.0711%.


### Packet polling, waiting, and consumed service state

Recovered the 140-byte bounded packet poller, 80-byte wait helper, and
68-byte queue handle refresh wrapper. All three whole functions and the
existing initializer compile and relocation-verify exactly with their
canonical source recipes. The initializer now names the SDK semaphore
request fields from their native consumers.

Reconstructed 208 bytes of directly consumed service state, 52 bytes of
allocation state, and 12 bytes of memory-pool fields. All resulting owners
were freshly compiled and privately verified. The service-state split
retains the entire original208-byte span without gaps; the other splits
keep unconsumed words explicitly placeholder-owned.

The hybrid image and packed executable match retail. Code is 565,076 bytes
(17.1563%); reconstructed data is 70,321 bytes
(10.8509%) across 2,271 units. A private 100-byte SDK output
callback probe is byte-exact but remains uncredited until its helper
return contract is resolved. Full source decompilation remains incomplete.


### Floor handlers, release callback, and renderer controls

Recovered four complete friction/floor handlers totaling 1,032 bytes,
a 44-byte subsystem initializer, and the 36-byte packet release callback.
The floor handlers retain the retail comparison direction explicitly, including
the unordered fallthrough. All affected whole source units compile and verify
exactly. The release callback forwards its token in C and uses the required
CPU barrier/interrupt-enable operations. Like the existing syscall exception,
these hardware operations require inline assembly; algorithmic instruction
streams and assembly placeholders remain uncredited.

Reconstructed 48 bytes of signed API handles and consumed renderer selectors,
limits, counters, and flags. Every changed owner was freshly compiled and
private-byte verified; the unconsumed magic words remain placeholders.

The hybrid loaded image and packed executable match retail. Code is 566,188
bytes (17.1901%); reconstructed data is 70,369 bytes
(10.8583%) across 2,283 units. GitHub main remains b1b061f9 at
529,332 code bytes, so the next scheduled code push remains21.0711%.
Full source decompilation remains incomplete.


### SDK seek helpers, record actions, and symbolic data ownership

Recovered the native 96-byte reentrant seek helper and 100-byte file callback
with consistent wide offset/result contracts and the signed 32-bit position cache.
EE GCC 2.96 plus SNAS verifies both whole units. They use separate source files
so calls retain named relocations under the existing verifier convention.
Added two record-action handlers, six motion/floor handlers, and two isolated
recovery handlers totaling 1,640 bytes; all affected units verify exactly.

Corrected the alarm callback contracts against the SDK and native helper:
GetThreadId takes no argument, alarm common data is opaque, and the wakeup
helper receives its signed thread ID. Both existing whole units remain exact.

Reconstructed 36 bytes of buffer/resource state and symbolic pointers. The
source-owned target at 0x4C2428 now uses a real relocation. The 0x70000000
memcpy destination is the scratchpad pointer, while the unclassified queue
word at 0x4C2440 stays placeholder. The symbol generator now recognizes data
owners without dropping suffixed legacy labels; its regression passes.

All 34 project tests pass. Every changed data object was compiled and privately
verified; the hybrid image and packed executable match retail. Code is 568,024
bytes (17.2458%); reconstructed data is 70,405 bytes
(10.8639%) across 2,292 units. Full source decompilation remains incomplete.

SDK references: [kernel contracts and ExitHandler](https://github.com/ps2dev/ps2sdk/blob/master/ee/kernel/include/kernel.h),
[scratchpad packet buffer](https://github.com/ps2dev/ps2sdk/blob/master/ee/packet/src/packet.c).


### Backend lifecycle, motion checks, and bounded menu/vector data

Added 1,572 bytes of matching source code: four motion/check handlers and
eight transfer/backend units. All affected whole units compile and relocation-
verify exactly. Dispatcher declarations now agree with the existing raw table
providers and integer callback-address setter. Raw table providers remain
uncredited until their own reconstruction is accepted.

Recovered 225 initialized-data bytes: two signed timer halfwords, a bounded
four-record menu prefix with four symbolic label pointers, and an eight-entry
float3 vector-pair table. Unconsumed record bytes, later menu rows, and
dispatch-pointer tails remain placeholders. All changed owners compiled and
private-byte verified, including the pointer relocations.

The global-label matcher now supports address-suffixed data names while
preserving legacy labels. Integration tests preserve coverage of every original
zero span and independently sum reconstructed/complete declarations rather
than asserting obsolete checkpoint totals. All 34 core and 11 data tests pass.
The hybrid loaded image and packed retail executable match their references.

Code is 569,596 bytes (17.2935%); reconstructed data is 70,630 bytes
(10.8986%) across 2,306 units. Full source decompilation remains incomplete.
The next scheduled code push remains 21.0711%.


### Runtime storage, DMA context, and bounded UI scale values

Added 812 matching code bytes across two storage/backend initializers,
the DMA context initializer, and three motion/frame-completion handlers.
The string operations now use the native strcpy and variadic sprintf
contracts; character buffers and the five-byte clear have correct C extents.
All changed whole units compile and relocation-verify exactly.

Recovered the 64-byte, sixteen-entry float scale lookup. Its consumer masks
the selector with0xF before scaling by four and loading a float. The complete
compiled owner matches retail; mixed pointer tables and unbounded selectors
remain uncredited.

The hybrid loaded image and packed executable match retail. Code is 570,408
bytes (17.3182%); reconstructed data is 70,694 bytes
(10.9085%) across 2,307 units. Full source decompilation remains incomplete;
the next scheduled code push remains 21.0711%.


### Verified motion, chain counters, and typed data checkpoint

Six whole functions add 832 exact linked code bytes: three motion handlers,
two runtime linked-list counters, and the effect-parameter initializer. The
effect provider is now a typed structure, avoiding incompatible float pointer
access. Bounded animation records and menu strings add reconstructed data;
unproven selectors and string-bank gaps remain raw and uncredited.

The catalog reports 571,240 code bytes (17.3434%) and 70,818 reconstructed
data bytes (10.9276%) across 2,312 data owners. Targeted object checks and
all 45 tests pass. The hybrid loaded image and packed executable also match
retail hashes. Full source decompilation and linkage remain incomplete.


### Bounded sprite tables and allocation messages

Native func_0033A590 wraps its signed frame selector at 34; its constructor
receives a 484-byte cleared record, and the allocator insertion callback writes
only list links. The two 34-entry tables therefore have complete consumer bounds.
The threshold table participates in signed comparison and integer-to-float
conversion; the pattern entries participate in signed frame-index multiplication.
Both are signed 32-bit source arrays and verify exactly (272 bytes).

Three allocation-failure callsites pass the SSCACHE, TEXTURE, and PALETTE
messages to the variadic formatter. Their 34-byte text-plus-NUL objects add 102
reconstructed bytes; all padding remains raw. Code stays 571,240 (17.3434%);
data is 71,192 (10.9853%) across 2,317 reconstructed owners. Changed objects,
catalog validation, loaded-image hash, and packed-ELF hash all pass.


### Reentrant input and thread priority checkpoint

The reentrant read helper 0011F640 is now exact C (96 bytes): it forwards an
integer low-level result through a wide signed return and propagates the error
word only for a failed read. The file callback 0011F9C8 (100 bytes) narrows that
result, advances its cached position on success, and clears flag0x1000 on failure.
Both whole units compile with EE GCC2.96 and SNAS, resolve their external calls,
and link exactly. The previous uncredited callback probe now has a consistent
callee contract.

Five directly consumed I/O descriptor fields are signed thread priorities,
passed to ChangeThreadPriority at00103C70. Their20 bytes are reconstructed;
the rest of the original zero region remains placeholder coverage.

Catalog:571,436 linked matching code bytes (17.3494%) and71,212 reconstructed
data bytes (10.9884%),8,972 functions and2,322 data owners. Targeted native
verification, data tests, loaded-image hash, and packed-ELF hash pass.


### Archive preparation, first-frame reset, and animation lookup

The first-frame reset handler 002F11B0 adds 184 exact bytes. Archive preparation
00410688 adds 92: it clears the buffer, copies up to seven string bytes with
NUL padding, then formats the length. Its formatter and wrapper return void.
The helper 00120440 is strncpy, as proven by its NUL scan and padding loop.

Following the low-level descriptor branches corrects the prior SDK labels:
0011F640 and 0011F9C8 are input/read routines (descriptor 0), with mutable
buffers. Their corrected declarations still match. The output/write error
wrapper 00122500 (descriptor 1 or 2) adds 96 exact bytes; its 128-byte file
callback remains an uncredited private probe.

Fixed-selector animation records add 96 reconstructed bytes. The signed
halfword bank 004A6DF0 adds 128: four 32-byte copies and a 64-entry LH loop
prove the complete prefix; its 88-byte tail remains raw.

Current catalog: 571,808 code bytes (17.3607%), 71,436 data
bytes (11.0230%), 8,975 functions and 2,328 reconstructed data owners.

Changed objects verify exactly, and both the hybrid loaded-image and packed
retail-ELF hashes pass. Source decompilation remains incomplete.


### Paired acceleration resets and file output callback

Two whole acceleration-reset handlers (002F0330 and002F0790) add296 bytes.
Their float predicate uses !(product <0), preserving the native unordered
comparison path as well as nonnegative products.

The file output callback0011FA30 adds128 bytes. Its opaque cookie is cast to
the file structure; append mode seeks to end, it clears the cached-position
flag, then narrows the reentrant write result. This source form also reproduces
the native register allocation. The normal EE GCC2.96/SNAS recipe verifies it
without instruction or object patches.

Catalog:572,232 exact linked code bytes (17.3736%),8,978 functions; data remains
71,436 bytes (11.0230%). The targeted units, complete hybrid loaded image, and
packed executable all match retail.


### File close, flush, and archive segment checkpoint

The flag-gated flush0011F6A0 (52 bytes), file close callback0011FB18 (28 bytes),
and reentrant close helper00119E80 (88 bytes) now compile exactly. The close
stub declaration accepts its native descriptor argument. The seek stub now
uses the wide return/offset signature already proven by its consumers. All
credited functions in the affected simple-leaves source still verify.

Archive segment derivation004106E8 adds52 bytes: it writes data+16 and the
computed value from data+8 to an ordinary output structure. The unsupported
volatile qualifier from its worker draft was removed before root credit.

Catalog:572,452 linked matching code bytes (17.3802%),8,982 functions. Data
remains71,436 bytes (11.0230%).

The targeted functions, affected simple-leaves unit, complete hybrid image,
and packed executable all verify exactly.


### Animation stream consumer and pointer audit

The parser at00134850 consumes payload bytes0–2 and float+4. Byte3 is read
only when field1 is negative. At each negative terminator it reads only byte0.
The two direct stream prefixes and the sixteen masked selector pointers now
reconstruct only those consumed fields. All padding, skipped payload bytes,
terminator tails, and inter-stream gaps retain raw placeholder owners. The
empty stream at004BF358 contributes only its terminating signed byte.

The pointer bank uses symbolic references with declarations matching the
record providers. Its entries and every selected stream have bounded consumer
proof. This batch adds1,054 data bytes:989 stream bytes,64 pointer bytes, and
one empty-stream terminator. Current data is72,490 (11.1856%) across2,384
reconstructed owners. Code stays572,452 (17.3802%). Changed objects, data
tests, loaded-image hash, and packed-ELF hash pass.

An independent typed file-refill candidate0011F6D8 remains private and
uncredited. EE GCC2.96 plusSNAS emits372 bytes versus380 retail; relocated
instruction comparison identifies two missing NOPs and corresponding branch
layout differences. SN GCC2.95.2 emits376 bytes with additional register/frame
differences. No instruction or object patches are used.


### Runtime query, cleanup, and bounded animation checkpoint

Runtime slot query004103D8 adds140 bytes. It clears the actual-value output,
bounds its four-entry index, invokes the fallback with error-3 for invalid
indices, copies the node value, and selects equality or inclusive threshold
comparison by the signed mode byte. SDK cleanup wrappers0011B768/0011B788
add56 bytes; the context initializer installs the former as its callback.

Substate handler002E6040 adds140 bytes with its negative-state path preserved.
Seven-character lookup004105D8 adds172 bytes. Its index declaration now agrees
with the const-char caller, and explicit signed-byte casts preserve native LB
loads. The accumulator uses unsigned32-bit arithmetic; its table alias is an
incomplete array, correcting the false48-entry extent inferred from a raw
zero span. ASCII0–9/A–F/a–f map across the following physical owners.

Data additions total476 bytes: five bounded float3 vectors and their eight
pointers(92), eight signed seven-halfword rows(112), four bounded eight-pair
float banks(256), and eight consumed low-halfwords(16). Unused fourth vector
words, upper halfwords, table tails, and prefixes remain raw and uncredited.

Current catalog:572,960 linked code bytes(17.3957%),8,987 functions;72,966
reconstructed data bytes(11.2591%) across2,400 owners. All changed units,
data tests, full loaded image, and packed executable verify exactly.


### File traversal, runtime release, and bounded table checkpoint

Runtime release 00410BD8 adds 60 exact bytes. It decrements the unsigned
reference count and invokes cleanup only when the new value is zero. SDK
file walker 0011C838 adds 148 exact bytes: it traverses context glue nodes,
walks their 88-byte file records, invokes the supplied callback for nonzero
flags, and combines callback results. Its callback declarations agree with
the previously recovered cleanup wrappers. Both use verified EE GCC 2.96
and SNAS recipes.

The animation pair table at 00472F80 adds 64 data bytes. Its state initializer
zeros the selector; the update reads both floats and masks the incremented
selector with 7. A direct float load at 00472F68 adds four bytes, preserving
the surrounding raw 64-bit load and unused words. The four-pair table at
0044DD50 adds 32 bytes with a mask of 3 before its two float loads. The signed
byte-pair table at 0044FFE0 adds 32 bytes with its masked 16-row selector.

The catalog reports 573,168 exact linked code bytes (17.4020%), 8,989
functions, and 73,098 reconstructed data bytes (11.2794%) across 2,404
owners. Changed objects, data tests, the complete hybrid loaded image, and
the packed executable all verify exactly.


### SDK initialization, timer semantics, and selector tables

SDK initializer 0011B7A8 adds 140 exact bytes. Its recovered context layout
places the initialization flag at 0x38, cleanup callback at 0x3C, file-group
header at 0x1D8, and three 88-byte file records at 0x1E4. It installs cleanup,
initializes the three standard files, and publishes the file-group header.
The layout agrees with the previously recovered file walker and cleanup.

Timer handler 002F0F70 adds 204 exact bytes. Its gates affect only the minimum
timer clamp; decrement and expiry handling occur outside those gates. Both
unsupported volatile casts from the draft were removed before verification.
The archive decoder and segment output now identify their result as an
unsigned hexadecimal payload length, with agreeing caller declarations.

Data additions are a masked 16-byte unsigned lookup, the four-byte resource
reference count, three bounded tables at 0044DA30/50/60 (80 bytes), two
bounded halfword tables at 0044E800/10 (32 bytes), and the 16-byte signed
lookup at 00450C60. Remaining resource fields retain raw ownership.

Catalog: 573,512 exact linked code bytes (17.4124%), 8,991 functions, and
73,246 reconstructed data bytes (11.3023%) across 2,412 owners. Changed code
and data objects, data tests, full loaded-image hash, and packed-ELF hash pass.


### Runtime span operations and audited data checkpoint

Whole units 00410000 (308 bytes), 00410290 (324 bytes), 0040FEA8 (52 bytes),
and 0040FF88 (116 bytes) add 800 exact linked code bytes. They consume or
merge spans, initialize the state buffer, and total indexed-list lengths.
The shared context header now records the pool and capacity fields at +12
and +16, the moved list at +20, four indexed lists at +24, and the fallback
at +40. Existing query and list-count units also use that common model and
still reproduce their full native instructions.

Data adds 103 bytes: sixteen even-position lookup bytes at 00454C10 (odd
bytes raw), a single six-float array at 004641E0 (24 bytes), bounded pair and
float tables at 00462C00/30 (48 bytes), and Infinity/NaN/zero strings (15
bytes including NULs). The six-float array consolidates adjacent owners so
its declared extent agrees with the guarded 0–5 consumer. Unused prefixes,
interleaved bytes, and string tails remain raw.

The proposed 00453EC0 contiguous-prefix recovery remains uncredited: native
0025E3DC doubles the masked index, so the actual footprint is sixteen even
bytes across the 32-byte bank. A corrected consumed-field split is pending.

Current catalog: 574,312 exact linked code bytes (17.4367%), 8,995 functions;
73,349 reconstructed data bytes (11.3182%) across 2,434 owners. All changed
code/data objects, data tests, full loaded-image hash, and packed-ELF hash
pass. Full source reconstruction remains incomplete.


### Runtime mode, lifecycle, and state-layout checkpoint

Nine mode wrappers add 224 exact bytes and now propagate the signed callback
results observed in the native callees. Reference acquisition/release and
service reset add 228 bytes. The reset declares seven word counters, while
its native loop deliberately clears only the first four. Cleanup, state
transition, scale, and size helpers add 212 bytes. Their shared owner/state
header records the proven pointer/index and flag/type/size offsets, avoiding
conflicting declarations.

The EE compiler runner accepts small-data thresholds 0 and 8, with 0 still
the default. GP-relative lifecycle units use both EE GCC -G8 and SNAS -G8;
the default -G0 path was checked against the existing 148-byte file walker.
All affected whole objects verify under their recorded recipes.

The corrected 00453EC0 lookup contributes its sixteen even bytes, with every
odd byte raw. It replaces the previously held false contiguous-prefix
candidate without integrating that candidate. A masked 16-float lookup and
eight four-float vectors at 004741A0/E0 add 192 bytes.

Catalog: 574,976 exact linked code bytes (17.4569%), 9,011 functions;
73,557 reconstructed data bytes (11.3503%) across 2,452 owners. All 45
tests, changed code/data objects, full loaded-image hash, and packed-ELF hash
pass. Full source reconstruction remains incomplete.


### SDK file layout and actor state checkpoint

A shared 88-byte SDK file layout replaces eight repeated opaque definitions.
Its cursor/count/buffer/cookie fields and four callbacks agree with the native
initializer at 0011B598. Read and seek callbacks now accept opaque cookies
matching their installed function-pointer types; all eight existing whole
units retain exact native code. The initializer adds 92 exact bytes, using
normal stdio assignment order rather than scheduling or object patches.

Eight actor handlers add 1,284 bytes: 002F3410, 002F0480, 002F0B10, 002F1430,
002F1360, 002F1600, 002F1780, and 002F5390. The position handlers use typed
union bit views instead of incompatible integer-pointer writes into floats.
New animation helper declarations use the canonical int return. Every
affected whole translation unit verifies under its recorded MWCC recipe.

Catalog: 576,352 exact linked code bytes (17.4986%), 9,020 functions. Data
stays 73,557 bytes (11.3503%). All changed code objects, the complete hybrid
loaded image, and the packed executable match retail. Larger motion-table
and additional bounded-data candidates remain queued for consumer review.


### Reviewed actor, runtime, and bounded data batch

Ten whole-function exact matches add 1,224 code bytes. Bounded motion vectors,
spawn vectors, lookup entries, and consumed formatting strings add 736 data
bytes; unread stride padding and unconsumed string terminators remain raw.
Startup selector and normalized mode assignments prove all twelve motion rows.

Catalog: 577,576 exact linked code bytes (17.5358%), 9,030 functions;
74,293 reconstructed data bytes (11.4638%). All changed native objects,
45 tests, catalog validation, full hybrid image, and packed retail ELF pass.
The next requested five-point code publication threshold remains 694,017 bytes.


### Runtime switch and masked byte lookup

The 108-byte runtime switch handler is compiler-exact. Its compiler-local
jump-table symbol is aliased in the canonical object used by the linker;
the existing raw jump table remains uncredited data. The byte lookup at
0x43EDF0 now credits 16 entries, bounded by the factory argument mask.

Catalog: 577,684 exact linked code bytes (17.5391%), 9,031 functions;
74,309 reconstructed data bytes (11.4663%). Changed native objects and
both full-image hash gates pass. Remote main remains b1b061f9; the next
five-point code push remains due at 694,017 bytes.


### File-record allocator and corrected conversion ABI

The 120-byte SDK file-glue allocator uses the verified 88-byte file layout.
The 76-byte conversion chain now declares double intermediates and a float
return, matching the native helpers and callers. The 148-byte offset-launch
initializer and sixteen-entry float lookup also verify exactly.

Catalog: 578,028 exact linked code bytes (17.5495%), 9,034 functions;
74,373 reconstructed data bytes (11.4762%). Every changed object, catalog
validation, full loaded-image hash, and packed ELF hash pass.


### Conditional actor chain and fixed vectors

Two exact handlers add 508 code bytes: the conditional phase chain and
gated offset-launch initializer. Four fixed three-component float vectors
add 48 reconstructed data bytes, with direct native loads documented.
Catalog: 578,536 linked matching code bytes (17.5649%), 9,036 functions;
74,421 reconstructed data bytes (11.4836%). Whole affected objects,
catalog validation, loaded-image hash, and packed ELF hash pass.


### Timed acceleration transition

The 200-byte actor transition now matches exactly within the complete
27-function motion source object. Catalog: 578,736 linked matching code
bytes (17.5710%), 9,037 functions. Data remains 74,421 bytes (11.4836%).
The full loaded-image and packed ELF hashes pass. An SDK string-output
probe remains uncredited because two store positions differ from retail.


### Complete lookup banks and allocator interface

Four banks of twelve code-point lookup entries add 192 reconstructed data
bytes. Native selection and the twelve-word scan prove the full extent.
The allocator wrappers now accept unsigned byte counts and return pointers;
both affected source objects remain byte-exact. Catalog: 578,736 linked
code bytes (17.5710%), 74,613 reconstructed data bytes (11.5132%).
Changed objects and both full-image hashes pass.


### Ground-clamp actor motion

The 188-byte ground-clamp handler matches as part of its complete
28-function source object. Catalog: 578,924 linked matching code bytes
(17.5767%), 9,038 functions. Data stays 74,613 bytes (11.5132%).
Changed code, catalog validation, and both full-image hashes pass.
The palette-byte patch is held for correction of its selector pair order.


### Corrected palette reachability and default SDK record

Palette reachability follows the native second-byte times eight plus
first-byte expression. Only 56 reachable bytes receive reconstructed
credit; gaps and the unread tail remain raw. The 28-byte SDK wrapper
passes the default context to the static-record getter, whose declaration
now records that ignored argument. Both source objects are exact.
Catalog: 578,952 linked matching code bytes (17.5776%), 9,039 functions;
74,669 reconstructed data bytes (11.5219%). Changed objects and both
full-image hash gates pass.


### Signed 64-bit integer parsing wrapper

The 44-byte default-context integer parser wrapper is compiler-exact.
The callee uses signed 64-bit limits, a text pointer, an end-pointer output,
and a base argument. Catalog: 578,996 linked matching code bytes
(17.5789%), 9,040 functions; data remains 74,669 bytes (11.5219%).
The native object, catalog validation, and both full-image hashes pass.


### Mutable sentinel word

Only the consumed first word at 0x4399C0 receives reconstructed credit;
three trailing words remain raw. Native load/store sites are documented.
Catalog: 578,996 linked code bytes (17.5789%), 74,673 reconstructed data
bytes (11.5225%). Both split data objects, catalog validation, and both
full-image hashes pass. The uppercase routine probe remains uncredited.


### Size-class free-list insertion

The 44-byte SDK routine returns a non-null node to its size-class free
list. The source records the native next pointer, class index, and context
list offset. Catalog: 579,040 linked matching code bytes (17.5803%),
9,041 functions. Data remains 74,673 bytes (11.5225%). The native object,
catalog validation, and both full-image hashes pass.


### Directional acceleration restart

The 192-byte actor restart handler now matches within the complete
29-function motion source. Catalog: 579,232 linked matching code bytes
(17.5861%), 9,042 functions. Four catalog placeholders remain excluded
from credit. Data stays 74,673 bytes (11.5225%). Whole-source verification,
catalog validation, and both full-image hashes pass.


### Mode pointer tables and timed floor check

Three bounded five-entry tables now use symbolic C object pointers with
verified relocations; native selector writes prove entries 0..4. They add
60 reconstructed bytes. A 164-byte actor floor-check handler matches within
the complete 30-function motion source. Catalog: 579,396 linked code bytes
(17.5911%), 9,043 functions; 74,733 reconstructed data bytes (11.5317%).
Affected objects, catalog validation, and both full-image hashes pass.


### Spawn position and seven asset pointers

The 164-byte spawn handler now matches within its two-function source.
The asset table has seven symbolic pointers selected by fixed factory
arguments 0..6; the native consumer is func_00136390 at load 0x1363BC.
Catalog: 579,560 linked matching code bytes (17.5960%), 9,044 functions;
74,761 reconstructed data bytes (11.5361%). Changed native objects,
catalog validation, and both full-image hashes pass.


### Runtime point transform and matrix types

The 120-byte point-transform helper matches exactly. Matrix storage and
the identity initializer now consistently use float elements, preserving
every affected function byte. Four complete source objects verify.
Catalog: 579,680 linked matching code bytes (17.5997%), 9,045 functions;
data remains 74,761 bytes (11.5361%). Both full-image hashes pass.


### SDK size-class allocation

The 164-byte allocator initializes the class lists, reuses a free node or
allocates its header and word capacity, then resets usage and sign fields.
It shares the native 20-byte header with the previously recovered return
routine. Both complete objects verify exactly. Catalog: 579,844 linked
matching code bytes (17.6047%), 9,046 functions; data remains 74,761 bytes
(11.5361%). Catalog validation and both full-image hashes pass.


### Global callback gate, matrix translation, and preset pointers

Two exact functions add 228 code bytes. The matrix translation setter
now uses float element pointers consistently with its caller, without
changing bytes. Four bounded random-selector tables add 64 symbolic
pointer bytes; every selector is masked to 0..3. Catalog: 580,072 linked
matching code bytes (17.6116%), 9,048 functions; 74,825 reconstructed data
bytes (11.5459%). Affected objects, catalog validation, and both full-image
hashes pass.


### Single-word SDK value and actor countdown

Two exact functions add 156 code bytes: the SDK constructor initializes
one word after the allocated 20-byte node header, and the actor callback
counts down its gated 16-bit timer. Catalog: 580,228 linked matching code
bytes (17.6163%), 9,050 functions; data remains 74,825 bytes (11.5459%).
Both native objects, catalog validation, and both full-image hashes pass.


### Bounded quit-menu records

The native loop visits exactly three eight-byte records. Their consumed
byte fields and symbolic text pointers, plus the three terminated labels,
add 39 reconstructed bytes. Each unused record byte and the unvisited
37-row tail remains raw. Catalog: 580,228 linked matching code bytes
(17.6163%), 74,864 reconstructed data bytes (11.5519%). All changed data
objects, catalog validation, and both full-image hashes pass.


### Runtime menu notice and backend state

The 132-byte menu-notice handler is compiler-exact. Four related sources
now share the backend-state layout and use the canonical void notice
setter declaration. All five affected functions retain exact bytes.
Catalog: 580,360 linked matching code bytes (17.6203%), 9,051 functions;
data remains 74,864 bytes (11.5519%). Catalog validation and both
full-image hashes pass.


### Loop-bounded integer lookup

The native loop reads exactly 31 signed words, offsets 0..0x78 of the
0x4B1160 table. Its leading bytes and final unconsumed word remain raw.
This adds 124 reconstructed bytes. Catalog: 580,360 linked matching code
bytes (17.6203%), 74,988 reconstructed data bytes (11.5711%). All three
split objects, catalog validation, and both full-image hashes pass.


### Indexed actor transition

The 92-byte indexed transition helper now matches. Its GP-addressed byte
table is declared as an array, rather than indexing beyond a scalar;
the unresolved extent receives no data credit. Callback argument types
match the existing owner-state dispatch table. Catalog: 580,452 linked
matching code bytes (17.6231%), 9,052 functions; data remains 74,988 bytes
(11.5711%). Native object, catalog validation, and both full-image hashes
pass.


### Renderer position vector

Direct native float loads prove all three components at 0x4B31EC.
Only that 12-byte vector is reconstructed; the remaining 0x170-byte bank
tail stays raw. Catalog: 580,452 linked matching code bytes (17.6231%),
75,000 reconstructed data bytes (11.5729%). Both split objects, catalog
validation, and both full-image hashes pass.


### Seven graphics-bank choices

The factory loop creates every selector 0..6 for the point-bank pointer
table. Its seven entries now use symbolic references and verified
relocations, adding 28 reconstructed bytes. Catalog: 580,452 linked code
bytes (17.6231%), 75,028 reconstructed data bytes (11.5773%). Native
object, catalog validation, and both full-image hashes pass.


### Indexed transition motion

The 148-byte helper now matches alongside its 92-byte caller. Its native
GP-relative lookup uses an incomplete byte-array declaration, and the
three-float position copy uses a typed aggregate. Both callback signatures
match the owner-state dispatch table. Catalog: 580,600 linked matching
code bytes (17.6276%), 9,053 functions; data remains 75,028 bytes
(11.5773%). Whole source, catalog, and both full-image hashes pass.


### Character output wrapper and point-bank starts

The 36-byte default-context character-output wrapper is exact. Seven
selector-proven point-bank starts add 84 reconstructed float-vector bytes;
all gaps and later dynamically indexed frames remain raw. Catalog:
580,636 linked matching code bytes (17.6287%), 9,054 functions; 75,112
reconstructed data bytes (11.5902%). All changed objects, catalog
validation, and both full-image hashes pass.


### Actor reset and masked transition

Two complete 104-byte handlers add 208 matching code bytes. The reset
uses the canonical animation result and typed float representations;
the transition gates its callbacks with the native flag masks. The
ignored helper declaration matches the existing source convention.
Catalog: 580,844 linked matching code bytes (17.6350%), 9,056 functions;
data remains 75,112 bytes (11.5902%). Both whole sources, catalog
validation, and both full-image hashes pass.


### External state actor trigger

The 112-byte actor callback now matches, including the signed flag gate,
optional external request, and known callback invocation. Catalog:
580,956 linked matching code bytes (17.6384%), 9,057 functions; data
remains 75,112 bytes (11.5902%). Whole-source verification, catalog
validation, and both full-image hashes pass. The SDK buffered character
output candidate remains uncredited at 132 versus 152 native bytes.


### Indexed flag transition

The 124-byte actor transition now matches, including its GP-relative
lookup and typed float representations. Catalog: 581,080 linked matching
code bytes (17.6422%), 9,058 functions; data remains 75,112 bytes
(11.5902%). Native object, catalog validation, and both full-image hashes
pass. The buffered character-output variants remain private and uncredited.


### Velocity transfer actor state

The 172-byte handler now matches, including float position/velocity
updates, the signed low-byte animation result, and secondary-object state
dispatch. Catalog: 581,252 linked matching code bytes (17.6474%), 9,059
functions; data remains 75,112 bytes (11.5902%). Whole-source proof,
catalog validation, and both full-image hashes pass.


### Buffered character output and complete bounded point paths

The 152-byte buffered-output routine matches with the native byte
read-back and common return paths. Object zero-initialization and the
48-transition termination state prove 49 vec3 frames per point path and
49 timing words. The seven paths and timing table add 4,228 reconstructed
bytes beyond the previously credited first vectors; gaps and tail stay raw.
Catalog: 581,404 linked matching code bytes (17.6520%), 9,060 functions;
79,340 reconstructed data bytes (12.2426%). All affected objects, 45 tests,
catalog validation, and both full-image hashes pass.


### Indexed state selector and bounded byte table

The 200-byte handler matches within its complete source. Its flag mask
proves all sixteen byte lookup entries; provider and consumer declarations
now agree on the byte-array type. Nearby helper/caller signatures were
aligned without changing bytes. Catalog: 581,604 linked matching code
bytes (17.6581%), 9,061 functions; 79,356 reconstructed data bytes
(12.2451%). All affected whole sources, data object, catalog validation,
and both full-image hashes pass.


### Indexed-state callbacks

Two complete handlers add 228 matching code bytes. Their shared source
now verifies four functions, retaining the corrected byte-table provider
declaration. Catalog: 581,832 linked matching code bytes (17.6650%),
9,063 functions; data remains 79,356 bytes (12.2451%). Whole-source
verification, catalog validation, and both full-image hashes pass.


### SDK string output and event-gated actor setup

Two exact functions add 188 code bytes: the SDK string-output wrapper
and actor initializer. The event factory now explicitly returns its native
allocated pointer, matching the caller that tests allocation success.
All affected whole sources retain exact bytes. Catalog: 582,020 linked
matching code bytes (17.6707%), 9,065 functions; data remains 79,356 bytes
(12.2451%). Catalog validation and both full-image hashes pass.


### Reset callback family and sole SYS label

Three exact handlers add 316 code bytes within the four-function reset
source. Eight native callers and the absence of stored function pointers
support the sole selected label slot; only its symbolic pointer and SYS
string add eight reconstructed bytes. Other slots and surrounding bytes
stay raw. Catalog: 582,336 linked matching code bytes (17.6803%), 9,068
functions; 79,364 reconstructed data bytes (12.2463%). Affected whole
sources and data objects, catalog, and both full-image hashes pass.


### State setup callback pair and fixed renderer pointer

The setup/callback pair adds 232 exact code bytes. Fixed native loads
prove the first renderer-bank pointer; only that symbolic pointer adds
four reconstructed bytes, with the other slots raw. Catalog: 582,568
linked matching code bytes (17.6874%), 9,070 functions; 79,368
reconstructed data bytes (12.2469%). Both whole sources, split data
objects, catalog validation, and both full-image hashes pass.


### Default SDK heap wrappers and actor dispatch

The 84-byte allocation and 72-byte release wrappers preserve the native
lock/reentrant-operation/unlock sequence and allocation result. A 100-byte
flag-gated actor callback also matches within its six-function source;
its raw numeric dispatch table remains uncredited data. Catalog: 582,824
linked matching code bytes (17.6951%), 9,073 functions; data remains
79,368 bytes (12.2469%). All affected whole sources, catalog validation,
and both full-image hashes pass.


### Six curve metadata choices

Constructor calls prove selectors 0..5 for the six symbolic curve
pointers and six record counts. Native signed comparison determines the
count type; interleaved payloads and padding stay raw. This adds 48
reconstructed bytes. Catalog: 582,824 linked matching code bytes
(17.6951%), 79,416 reconstructed data bytes (12.2543%). All affected data
objects, catalog validation, and both full-image hashes pass.


### Graphics transforms, motion family, and bounded curve fields

Seven exact functions add 876 code bytes: two graphics transforms and
five motion handlers. The zero-filled initial counter and signed count
guard prove all 32 curve rows; only each consumed halfword and float
receive credit, adding 192 bytes. A fixed renderer threshold adds four
more bytes. Every two-byte row gap and surrounding data remains raw.
Catalog: 583,700 linked matching code bytes (17.7217%), 9,080 functions;
79,612 reconstructed data bytes (12.2846%). All affected whole source
objects and 104 data objects, catalog validation, and both full-image
hashes pass.


### Multi-branch actor mode initializer

The 272-byte actor initializer matches within its seven-function reset
source. Catalog: 583,972 linked matching code bytes (17.7300%), 9,081
functions; data remains 79,612 bytes (12.2846%). Whole-source proof,
catalog validation, and both full-image hashes pass. The quad-builder
candidate remains uncredited: its initially proposed extra float
parameters are not supported by the native caller/callee contract.


### Owner-context callback chain

The native two-argument dispatch chain now passes its context through
func_002F9080 and jtbl_004C1388. The new 184-byte helper consumes the six
context bytes. Both complete dispatcher objects, the new source, and
both callback-table objects verify exactly. The table declaration keeps
its native GP-relative access and agrees with its const provider.
Catalog: 584,156 linked matching code bytes (17.7356%), 9,082 functions;
data remains 79,612 bytes (12.2846%). All 45 tests, catalog validation,
and both full-image hashes pass.


### Context sequence, periodic gate, cleanup, and matrix initialization

Four exact functions add 364 code bytes. The periodic callback uses the
random helper’s native no-argument contract; removing the unused actor
argument preserves all bytes. The complete reset and context source
objects and the graphics matrix initializer verify exactly. Catalog:
584,520 linked matching code bytes (17.7466%), 9,086 functions; data
remains 79,612 bytes (12.2846%). Catalog validation and both full-image
hashes pass.


### BMP pixel-data pointer

The 76-byte helper validates the native BM signature and reconstructs
the little-endian pixel offset from two halfwords. Its diagnostic call
uses the reporter’s native variable-argument interface. Catalog: 584,596
linked matching code bytes (17.7489%), 9,087 functions; data remains
79,612 bytes (12.2846%). Native object, catalog validation, and both
full-image hashes pass.


### Graphics alignment and context-control callbacks

Four exact functions add 436 code bytes. Context helper signatures now
agree with their explicit two-argument caller; the latch ignores the
provided context. The callback gate reads its existing raw integer table
and converts the chosen address at the call site, keeping that table
uncredited data. Catalog: 585,032 linked matching code bytes (17.7622%),
9,091 functions; data remains 79,612 bytes (12.2846%). All affected whole
sources, catalog validation, and both full-image hashes pass.


### Signed thresholds and renderer variants

Six directly loaded signed threshold bytes and two constructor-proven
float3 variants add 30 reconstructed bytes. Other selectors and the
remaining banks stay raw. The SDK registration-pair proposal is held
for correction: native reads include the 0x5B pair, and its five-entry
loop reads only first words. Catalog: 585,032 linked matching code bytes
(17.7622%), 79,642 reconstructed data bytes (12.2892%). Changed data
objects, catalog validation, and both full-image hashes pass.


### Format record count and callback counter

Two exact helpers add 116 code bytes. The record lookup declaration
matches the existing signed-word/tag interface, and the callback walker
uses its caller-proven object pointer. Catalog: 585,148 linked matching
code bytes (17.7657%), 9,093 functions; data remains 79,642 bytes
(12.2892%). Both whole sources, catalog validation, and both full-image
hashes pass.


### Nine-step sequence and manifest-sized actor setup

Nine consumed signed halfwords and their signed limit add 22 data bytes;
upper-half gaps and neighbors stay raw. The actor setup function matches
its complete 0xEC manifest extent, adding 236 code bytes. Its four-byte
suffix is already a separate config/gaps.csv gap and receives no credit.
Catalog: 585,384 linked matching code bytes (17.7729%), 9,094 functions;
79,664 reconstructed data bytes (12.2926%). Whole affected objects,
catalog validation, and both full-image hashes pass.


### Phase setup family

Six complete functions add 1,748 exact code bytes within the shared
move-setup source. Their data references use actual providers or the
explicit native GP address alias; no data bytes receive new credit.
Catalog: 587,132 linked matching code bytes (17.8259%), 9,100 functions;
data remains 79,664 bytes (12.2926%). The complete source object, catalog
validation, and both full-image hashes pass.


### Zero-variant renderer constants

Both native callers pass selector zero. The selected scale and float3
vector add 16 reconstructed bytes; unselected values and surrounding
bytes stay raw. Catalog: 587,132 linked matching code bytes (17.8259%),
79,680 reconstructed data bytes (12.2951%). All split data objects,
catalog validation, and both full-image hashes pass.


### Six bounded UI effect records

The native constructor loop selects records 0..5. Each six-byte record
consumes two signed halfwords and one signed byte; the remaining byte
stays raw. This adds 30 reconstructed bytes, with prefix and neighboring
records unclaimed. Catalog: 587,132 linked matching code bytes
(17.8259%), 79,710 reconstructed data bytes (12.2997%). All changed data
objects, catalog validation, and both full-image hashes pass.


### SDK reset flags and selector maps

The fixed ten-word reset loop proves every flag, including zero-valued
slots. Three independent selector checks bound the ten-byte maps. These
add 70 reconstructed bytes; each map suffix remains raw. Catalog:
587,132 linked matching code bytes (17.8259%), 79,780 reconstructed data
bytes (12.3105%). All changed data objects, catalog validation, and both
full-image hashes pass.


### Constant vector reset

The 140-byte handler uses typed float representations and preserves
the native signed flag gate and orientation-dependent negation. Catalog:
587,272 linked matching code bytes (17.8302%), 9,101 functions; data
remains 79,780 bytes (12.3105%). Whole-source verification, catalog
validation, and both full-image hashes pass.


### Corrected SDK registration and selected label mappings

Registration credit is limited to 40 consumed bytes: IDs, symbolic code
addresses, and the loop’s first words. Its unused second words and kernel
address remain raw. The fixed 21-row label bank and 23 proved map bytes
add 107 bytes; other banks also select G, which remains pending. Catalog:
587,272 linked matching code bytes (17.8302%), 79,927 reconstructed data
bytes (12.3332%). All affected data objects, catalog validation, and both
full-image hashes pass.


### Timed reset family

Three complete timed-reset handlers add 448 exact code bytes, preserving
the signed countdown, float-word representations, and native callback
order. Catalog: 587,720 linked matching code bytes (17.8438%), 9,104
functions; data remains 79,927 bytes (12.3332%). All three whole source
objects, catalog validation, and both full-image hashes pass.


### Masked effect reset

The 196-byte handler matches with the effect helper’s canonical byte
arguments, preserving the signed result gate and independent flag clears.
Catalog: 587,916 linked matching code bytes (17.8497%), 9,105 functions;
data remains 79,927 bytes (12.3332%). Whole-source verification, catalog
validation, and both full-image hashes pass.


### Velocity update and format payload copy

Two whole functions add 288 verified C bytes. The payload helper uses the
canonical signed format-entry declaration and copies the declared word count.
Catalog: 588,204 exact code bytes (17.8585%), 9,107 functions, and
80,015 reconstructed data bytes (12.3468%). Both whole objects, catalog
validation, and full loaded-image and packed-ELF hashes pass.


### Bounded selector fields and timing

Three signed halfwords selected by the observed 0/1/2/4 callers and a
two-entry signed timing table add 14 data bytes. The callback increments
its zero-initialized index and leaves the lookup state at two.
Catalog: 588,204 exact code bytes (17.8585%), 80,029 reconstructed
data bytes (12.3489%). Changed data objects, catalog, and both hashes pass.


### Zero phase transition

The complete 140-byte handler preserves both random-state reads and uses
the allocator helper’s pointer return and canonical no-argument random API.
Catalog: 588,344 exact code bytes (17.8627%), 9,108 functions; data remains
80,029 bytes (12.3489%). Whole-object and full-image checks pass.


### Renderer variants

Three observed signed selector fields and four float pairs add 38 data
bytes. Call sites restrict the selector fields to 0/1/2; the float-pair
consumer maps its byte selector to 0..3, including the default case.
Catalog: 588,344 exact code bytes (17.8627%), 80,067 reconstructed
data bytes (12.3548%). Changed objects, catalog, and both image hashes pass.


### Fixed vector and bounded animation curves

A three-float vector, two interpolation records, and seven signed ID/float
steps add 86 data bytes. Native callback allocation clears the object;
its counters/selectors start at zero and exit at five or seven, preserving
the proven table bounds. Catalog: 588,344 code bytes (17.8627%), 80,153
data bytes (12.3681%). Changed data objects, catalog, and both hashes pass.


### Velocity reset, timer transition, and indexed format access

Three complete functions add 468 exact C bytes. The format lookup uses
the canonical signed-tag prototype. The existing allocator wrapper now
explicitly forwards its three real arguments and returns the allocated
pointer; all four functions in that source remain exact.
Catalog: 588,812 matching code bytes (17.8769%), 9,111 functions; data
remains 80,153 bytes (12.3681%). Whole-object, catalog, and both image
hash checks pass.


### Random-state update, format count, and complete label columns

The random-state update and format count helper add 132 exact code bytes.
The three fixed 21-row label banks prove another 148 data bytes: the
first bank’s label column, remaining second-bank characters, and the G
map entry. Other copied numeric fields remain uncredited until their
roles are established. Catalog: 588,944 exact code bytes (17.8809%),
9,113 functions, 80,301 reconstructed data bytes (12.3909%). Changed
whole objects, catalog, and both image hashes pass.


### Point transform and gated motion

A 100-byte point wrapper and 148-byte motion handler now match. All three
direct calls to the matrix-reset helper supply the same two legacy float
parameters; its definition now records that API and remains exact. The
transform helper reads three floats and writes three float outputs.
Catalog: 589,192 code bytes (17.8885%), 9,115 functions; data remains
80,301 bytes (12.3909%). Whole objects, catalog, and both image hashes pass.


### Ordinal label selectors and suffixes

Twenty-one signed selector IDs, symbolic suffix pointers, and four-byte
ordinal labels add 189 data bytes. The text consumer reads exactly four
characters for each selected pointer; all intervening padding remains raw.
Catalog: 589,192 code bytes (17.8885%), 80,490 data bytes (12.4201%).
All changed objects, symbolic relocations, catalog, and both hashes pass.


### Timed position setup and shared workspace initialization

Two complete position handlers and the gated workspace reset add 448
exact code bytes. Both file-header identity accessors now return pointers,
as required by every observed caller; their complete source object
remains exact. The workspace scale is a float, confirmed by native
LWC1/SWC1 consumers. Catalog: 589,640 code bytes (17.9021%), 9,118
functions, 80,490 data bytes (12.4201%). Whole objects, catalog, and
both loaded-image and packed-ELF hashes pass.


### Match-choice initialization and additional phase transitions

Four complete functions add 564 code bytes. The 32-byte choice workspace
models only the two observed halfword fields; other bytes remain opaque.
Global phase advancement preserves signed byte gates and its idle fallback.
Catalog: 590,204 matching code bytes (17.9192%), 9,122 functions; data
remains 80,490 bytes (12.4201%). Whole objects, catalog, and both hashes pass.


### Signed motion vectors and timed flag transition

The 140-byte transition handler and 288 bytes of signed motion-vector
pairs are exact. Sector construction reduces an 8-bit angle to 0..31;
step updates mask with 0x1F. Native LH loads convert the offsets to
floats for X/Y updates, and the secondary lookup masks its eight-pair
index. Catalog: 590,344 code bytes (17.9235%), 9,123 functions,
80,778 data bytes (12.4645%). Changed objects, catalog, and both hashes pass.


### Timed three-word reset

The complete 180-byte reset handler matches its flag gate, state clear,
and aligned three-word position representation. Catalog: 590,524 exact
code bytes (17.9289%), 9,124 functions, 80,778 reconstructed data bytes
(12.4645%). Whole-object, catalog, and both full-image hashes pass.


### Flag updates, randomized state, and object vector initialization

Six complete functions add 800 code bytes; consumed motion-pattern bytes
and float vector templates add 128 data bytes. The randomized initializer
uses MWCCPS2 3.0, while the vector constructors use ordinary struct copies.
The random wrapper now has its actual no-argument integer-return API.
Identical symbol duplicates and stale residual aliases were removed; five
intentional same-address alias pairs are explicitly marked for the splitter.
Splitting, baseline relinking, all 45 tests, changed whole objects, catalog,
and both hybrid hashes pass. Catalog: 591,324 code bytes (17.9532%),
9,130 functions, 80,906 data bytes (12.4843%).


### SDK random generator, callbacks, cleanup, and mirrored transitions

Eight complete functions add 1,088 exact C bytes. The SDK random generator
uses the native unsigned 64-bit recurrence in its reentrant context.
Registered callbacks take the proven context/buffer pointers and ignore
return values. Mirrored handlers use typed owner-pointer reloads and float
zero stores, with all affected whole source objects still exact.
Catalog: 592,412 matching code bytes (17.9862%), 9,138 functions; data
remains 80,906 bytes (12.4843%). Whole-source proofs, catalog validation,
and both full-image hashes pass.


### Animation transitions, bounded config rows, and pointer APIs

Three complete handlers add 548 code bytes; bounded animation records,
signed coordinate pairs, and side vectors add 128 data bytes. Sample
pointers have opaque pointee types because the mutable sample owner
remains uncredited. The allocation finalizer now returns/links object
pointers; both affected source objects remain exact. Dispatcher thunks
explicitly forward two arguments with void returns, as native callers
require. Catalog: 592,960 exact code bytes (18.0029%), 9,141 functions,
81,034 data bytes (12.5040%). Whole-source, data, catalog, and both
full-image hash checks pass.


### Countdown transitions and bounded float curves

Three phase/countdown handlers and another vector-template initializer
add 688 code bytes. Three bounded callback curves add 100 data bytes;
their counters start in cleared objects and leave the lookup states at
their proven endpoints. Unread trailing words remain raw.
Catalog: 593,648 matching code bytes (18.0238%), 9,145 functions,
81,134 reconstructed data bytes (12.5194%). Whole source objects,
changed data units, catalog, and both full-image hashes pass.


### Phase exits, packed alpha, and record cleanup

Four complete actor handlers, a scaled alpha submitter, and the 1,024-slot
cleanup loop add 824 code bytes. The existing conditional object-free
wrapper now explicitly forwards its real owner pointer; the whole
22-function source group remains exact. Catalog: 594,472 matching code
bytes (18.0488%), 9,151 functions; data remains 81,134 bytes (12.5194%).
All changed whole objects, catalog, and full-image hashes pass.


### Owner-state motion and deadline handlers

Five complete handlers add 1,116 exact C bytes, preserving ordered float
comparisons, signed status gates, object-pointer results, and GP-relative
state access. Catalog: 595,588 matching code bytes (18.0827%), 9,156
functions; data remains 81,134 bytes (12.5194%). Each source object,
catalog validation, and both full-image hashes pass.


### Masked geometry and bounded animation data

The batch adds 756 data bytes from fixed vectors, bounded float streams,
and explicit 4/8/16-entry masks. The 64-float bank feeds velocity and
acceleration pairs; eight-vector geometry and signed/byte selectors have
independent native range checks. The signed 00472E70 bank’s source comment
now names its actual 003A6E40/003A7110 consumers and exact LH sites.
Catalog: 595,588 code bytes (18.0827%), 81,890 data bytes (12.6361%).
All changed data objects, relocations, catalog, and both image hashes pass.


### CA40/CA70 owner-context contract

The native outer dispatcher supplies p+0x2B8 through CA70 into CA40.
Both tables and the C dispatcher now use the proven two-argument callback
contract. The complete 228-byte context handler matches, and CA70 adds
40 reconstructed pointer bytes. The context’s byte state and actor float
zero stores have explicit types. Catalog: 595,816 code bytes (18.0896%),
9,157 functions, 81,930 data bytes (12.6423%). Both full caller objects,
the isolated handler, table relocations, catalog, and both image hashes pass.


### Resource status, descriptors, and activation callback

Four complete functions add 548 exact C bytes. Pool-release status is
forwarded through its real one-handle wrappers; the native upper-bound
behavior is preserved. The activation gate and tail wrapper now use the
actor-only API established by their callback table, with unsupported
extra parameters removed. Catalog: 596,364 code bytes (18.1062%),
9,161 functions, 81,930 data bytes (12.6423%). All affected whole
objects, catalog, and both full-image hash checks pass.


### Recursive transforms and runtime size/state helpers

Four complete functions add 340 exact code bytes. Child links are read as
pointers, while size/offset helpers preserve the signed word arithmetic
and conditional state writes observed in their native callers.
Catalog: 596,704 code bytes (18.1165%), 9,165 functions, 81,930 data
bytes (12.6423%). Changed whole objects, catalog, and both image hashes pass.


### Contextual movement and allocation results

Eight complete handlers add 1,508 exact code bytes. The event constructor
now returns its allocated pointer, and callers store/link that pointer
with the canonical API. Its whole existing source group remains exact.
Catalog: 598,212 code bytes (18.1623%), 9,173 functions, 81,930 data
bytes (12.6423%). All changed source objects, catalog, and both full-image
hashes pass.


### Bounded decoder, palette, timeline, and motion data

The integrated batch adds 1,165 verified data bytes from fixed decoder
indices, symbolic pointer tables, finite timeline/palette selectors, and
explicitly masked float/byte banks. The 004B6E10 nibble-pair candidate
remains uncredited pending producer-domain proof. Unknown target payloads
and unread padding remain raw. Catalog: 598,212 matching code bytes
(18.1623%), 83,095 reconstructed data bytes (12.8220%). Changed data
objects, relocations, catalog, and both full-image hashes pass.


### EE96 object lifecycle and narrowed TIM2 selectors

Nine complete runtime helpers add 620 code bytes. Native argument audit
confirms the logger takes one text input and the value dispatcher targets
a scalar-state pointer with a void result; the corrected API remains exact.
The TIM2-derived lookup now credits only rows0..4 and10 (48 bytes), with
other rows raw. Catalog: 598,832 code bytes (18.1812%), 9,182 functions,
83,143 data bytes (12.8294%). All changed objects, 45 tests, catalog,
script syntax, and both full-image hashes pass.


### Actor handoffs and pointer accessors

Five complete handlers add 972 exact code bytes. The indexed accessors
and handoff fields now read/write actual pointers, with their complete
source objects still exact. The dispatcher’s interior callback address
uses an incomplete array alias without claiming a new table extent.
Catalog: 599,804 code bytes (18.2107%), 9,187 functions, 83,143 data
bytes (12.8294%). Changed whole objects, catalog, and both image hashes pass.


### Signed phase banks and fixed geometry

The batch adds 504 reconstructed data bytes from two signed-byte banks,
nine modulo-selected geometry vectors, masked float-record fields, fixed
vectors, and two 64-entry signed phase banks. Padding and unused record
words remain raw. Catalog: 599,804 code bytes (18.2107%), 83,647 data
bytes (12.9072%). Changed data objects, catalog, and both image hashes pass.


### Runtime message slots and scalar state clamp

The typed callback/context setter, two message adapters, and scalar-state
clamp add 116 exact code bytes. Their actual native interfaces are recorded
in source. Catalog: 599,920 code bytes (18.2142%), 9,191 functions,
83,647 data bytes (12.9072%). Whole object, catalog, and full-image checks pass.


### Message dispatcher reserved-argument contract

The 44-byte indirect dispatcher matches. Its native wrapper explicitly
passes the context-slot address, message pointer, and zero reserved word;
the callback uses the stored context and the same message/reserved tuple.
Setter and adapter types share that verified contract. Catalog: 599,964
code bytes (18.2155%), 9,192 functions, 83,647 data bytes (12.9072%).
All four affected functions, catalog, and both full-image hashes pass.

## Actor timers and runtime workspace reset checkpoint

Twelve additional whole functions match relocated retail bytes: actor timer,
phase, callback, position and flag handlers, plus the expanded runtime workspace
reset. The single-flag callback uses the verified byte arguments of its callee.
Catalog: 601,320 code bytes (18.2567%), 9,204 functions, and 83,647 data bytes
(12.9072%). All twelve objects, catalog validation, full relink and packed retail
ELF identity pass. The next code push threshold remains 21.0711%.

## Masked byte table checkpoint

Reconstructed signed waveform, category, effect, flag, nonzero, even-offset,
delta and variation table entries. Adjacent unused bytes remain placeholders.
Catalog: 601,320 code bytes (18.2567%) and 83,950 data bytes (12.9540%),
with 2,853 reconstructed data source units. Changed data objects, eleven data
tests, catalog validation, full relink and packed retail ELF identity pass.
Reachable waveform and nibble selector coverage remains under additional audit.

## Context motion reset checkpoint

The 104-byte contextual motion reset matches in full, using known floating-point
velocity and acceleration fields and the existing bit-preserving float constant
representation. Catalog: 601,424 code bytes (18.2599%), 9,205 functions.
Whole-object and full retail image identity checks pass.

## Motion floor clamp and selector coverage audit

The 116-byte motion floor clamp matches in full. Catalog: 601,540 code bytes
(18.2634%), 9,206 functions. Full relink and packed ELF match retail.

Removed 144 bytes of reconstructed data credit: the waveform callback lifetime
does not yet prove a full 128-index cycle, and the hex formatter caller does not
establish all sixteen input nibbles. Their exact typed sources remain held
placeholders. Data: 83,806 bytes (12.9317%), 2,851 reconstructed source units.

## Negative flag callback checkpoint

Recovered the 112-byte negative flag reset and its 128-byte masked sibling,
with callback signatures grounded by the native tables and dispatchers. The
shared object verifies both complete spans. Catalog: 601,780 code bytes
(18.2707%), 9,208 functions; data remains 83,806 bytes (12.9317%).
All 34 project tests, assembly splitting, catalog validation and full retail
link/packed ELF identity pass.

## Timed motion acceleration checkpoint

Recovered the complete 168-byte timed motion acceleration callback. Its
callback signature is grounded by the native table and dispatcher; floating
point motion and signed timer behavior are preserved. The entire shared object
verifies all 31 credited functions after the addition. Catalog: 601,948 code
bytes (18.2758%), 9,209 functions. Data remains 83,806 bytes (12.9317%).
Full hybrid relink and packed ELF identity match retail.

## Owner timer and palette selector checkpoint

The 136-byte owner-context timer reset matches in full with its two-argument
callback contract. Reconstructed sixteen even-address palette selector bytes;
interleaved and prefix bytes remain raw placeholders. Changed objects, catalog
validation, full relink and packed retail ELF identity pass. Catalog: 602,084
code bytes (18.2799%), 9,210 functions, and 83,822 data bytes (12.9342%) across
2,867 reconstructed source units. Additional producer-domain audits continue.

## Selector producer correction

Confirmed the native random recurrence and its seeded cycle independently:
43,534 visited states cover all low four- and five-bit selectors. This supports
the five random-selected byte banks. The deterministic delta table at 446D40
has unproven input-field domains, so its sixteen bytes are held placeholders.
Data credit is 83,806 bytes (12.9317%), 2,866 reconstructed units.

## Owner allocation callback checkpoint

Recovered the complete 188-byte owner allocation callback and corrected the
allocation helper to return its entry pointer. The new callback checks that
result; the existing timer action intentionally ignores it. All affected whole
objects verify exactly, including the twenty-one-function allocator source.
Catalog: 602,272 code bytes (18.2856%), 9,211 functions. Data remains 83,806
bytes (12.9317%). Full relink and packed retail ELF identity pass.

## Context timer flag and position checkpoint

Recovered the complete 184-byte timer/flag/position handler. Its unused context
parameter matches the native callback table contract; the allocator callback
uses its canonical byte arguments. Whole-function, catalog and full retail
link/packed ELF verification pass. Catalog: 602,456 code bytes (18.2912%),
9,212 functions. Data remains 83,806 bytes (12.9317%).

## Random helper caller contract correction

Corrected four source groups to declare and call func_00174170 as int(void),
matching its native two-global state recurrence. One former void declaration
now preserves its actual return contract even though that caller ignores it.
All four whole objects remain exact under their established compiler recipes
(including MWCCPS2 3.0-011126 for state_return_family). Full hybrid linkage and
packed ELF identity pass. Credit remains 602,456 code bytes (18.2912%).

## Runtime service pool reset checkpoint

Recovered the complete 200-byte runtime service pool reset, preserving native
handle checks, entry stride, cleanup calls and counter-clear ordering before
the workspace fills. Ordinary counter globals suffice for an exact match;
unnecessary volatile qualifiers were removed. Whole object, catalog and full
retail link/packed ELF identity pass. Catalog: 602,656 code bytes (18.2973%),
9,213 functions. Data remains 83,806 bytes (12.9317%).

## Expanded workspace reset interface correction

Removed an unnecessary volatile qualifier from the ordinary workspace counter
and corrected the memory-fill helper declaration to return its destination
pointer. The caller ignores that pointer. The complete 24-byte reset remains
exact; full hybrid linkage and packed retail ELF identity pass. Code credit
remains 602,656 bytes (18.2973%).

## Runtime service workspace initializer checkpoint

Recovered the complete 100-byte initializer for the three service workspaces.
Counter resets and zero/negative fills preserve native ordering and extents;
its no-argument signature is grounded by the native 12F4C0 caller. Whole-object,
catalog, full relink and packed retail ELF verification pass. Catalog: 602,756
code bytes (18.3003%), 9,214 functions; data 83,806 bytes (12.9317%).

## Memory-fill declaration correction

Corrected grok_tail_r2 to use the verified destination-pointer return and
unsigned byte-count contract of func_0011D8F8. Removed an unused conflicting
declaration from round2_pairs1. Both whole source objects verify exactly;
full hybrid linkage and packed retail ELF identity pass. Code remains
602,756 bytes (18.3003%); no additional percentage credit is claimed.

## Object-pool memory fill contract correction

Corrected the memory-fill declaration in the object pool and two initialization
callbacks to preserve the helper destination-pointer return and unsigned byte
count. All seven pool functions and both initialization callbacks remain exact
in their complete source objects. Full retail hybrid linkage and packed ELF
identity pass; credited code remains 602,756 bytes (18.3003%).

## Remaining typed memory-fill callers

Corrected five source groups with explicit memory-fill prototypes to the native
destination-pointer return and unsigned byte-count interface: grok_r2_0014,
grok_w3_0026, grok_w5_0018, grok_w3_0024 and grok_r2_0024. All five complete
objects verify exactly. Full hybrid linkage and packed retail ELF identity pass.
Code remains 602,756 bytes (18.3003%); no new coverage credit is claimed.

## Typed memory-fill tail declarations

Replaced the remaining five loose memory-fill declarations with the verified
three-argument destination-pointer API in tail_call_leaves, leaves7, leaves13,
leaves20 and grok_w5_0028. Every complete source object verifies exactly. Full
hybrid linkage and packed retail ELF identity pass. This interface correction
adds no coverage credit; code remains 602,756 bytes (18.3003%).

## Runtime option setter checkpoint

Recovered the complete 32-byte four-argument option setter with EE96/SNAS.
Native registration callers pass three record words for byte truncation and a
fourth word for the selector, including explicit zero arguments on null paths.
Whole object, catalog, full hybrid linkage and packed retail ELF identity pass.
Catalog: 602,788 code bytes (18.3013%), 9,215 functions; data remains 83,806
bytes (12.9317%).
