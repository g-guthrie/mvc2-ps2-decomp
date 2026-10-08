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
