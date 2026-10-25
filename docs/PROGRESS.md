# Progress stats (decomp.dev)

objdiff v2 field meanings, as decomp.dev displays them:

| decomp.dev | objdiff field | Meaning here |
|---|---|---|
| decompiled | `matched_code_percent` | Exact matching C vs retail `.text` |
| fully linked | `complete_code_percent` | That matching C is **placed by the hybrid linker** |
| data bar | `matched_data_percent` / `complete_data_percent` | Completed-source initialized data in `0x00424200..0x004C2580` |

`complete_*` is **not** “the packed ELF SHA-matches retail.” Hybrid copies unmatched bytes from the dump, so the image can hash 100% while linked C remains incomplete.

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

## State-mode setup candidate review

Imported the 305690 state-mode setup candidate for further recovery but held it
out of matching credit: an artificial volatile self-write forced an instruction
and did not establish the intended ordinary actor-memory semantics. Removed
that qualifier and typed its 408 stores as pointers. Existing registered
functions in the complete source object still verify exactly. Candidate repair
continues; catalog remains 602,788 code bytes (18.3013%).

## Legacy EE assembler configuration repair

The full registered rebuild passed its data stage but stopped at a legacy EE
assembly step because GNUAS was unset. Added the established AS/default
assembler fallback for GNUAS and resumed at that failed step using the completed
objects. Shell syntax and all 34 project tests pass. Remaining whole-object
checks and full-image validation continue; no new coverage is claimed.

## Full registered source rebuild verification

The complete registered rebuild, resumed at the legacy assembler step after
repairing its missing default, now passes all source-object checks. All 7,865
data units verify exactly. The hybrid places 9,219 isolated compiled-function
sections and 7,865 compiled-data sections. The loaded image (3,941,760 bytes)
and packed ELF (3,942,320 bytes) match retail hashes in full. Catalog remains
602,788 credited code bytes (18.3013%), 9,215 credited functions, and 83,806
reconstructed data bytes (12.9317%). Four placed source functions remain
uncredited; linked image identity does not grant source reconstruction credit.
Queued worker recoveries will be integrated after this verified checkpoint.

## Queued runtime integration checkpoint

Integrated five exact runtime functions: two typed message dispatchers, a
record-release wrapper, a mode setter and a remaining-size output helper.
Their whole EE96/SNAS objects verify exactly; the twelve-function state-slot
source also remains exact with callback/context pointer types. Catalog:
603,036 code bytes (18.3088%), 9,220 functions; data 83,806 bytes (12.9317%).
Full hybrid relink and packed retail ELF identity pass.

## Physics and timed motion integration checkpoint

Integrated three complete caller-grounded handlers: 3061E0 (152 bytes),
30D640 (136 bytes), and 30D8A0 (236 bytes). Both whole source objects verify
all registered functions exactly with their established compiler recipes. The
305690 candidate remains uncredited and ordinary pointer-typed. Catalog:
603,560 code bytes (18.3247%), 9,223 functions; data 83,806 bytes (12.9317%).
Full hybrid linkage and packed retail ELF identity pass.

## Reviewed frame tables and vector integration

Integrated 436 bytes of reconstructed data, including the group-9 22-frame
scalar table, group-8 sixteen-frame timing curve, fixed-selector vectors and
the twelve explicitly selected event vectors. Ordinary float literals verify
exactly. Copied D440B0/D440D0 lanes with unproven selectors stay raw; only
their directly loaded fifth float words receive credit. All changed data
objects, eleven data tests, catalog, full linkage and packed retail ELF pass.
Catalog: 603,560 code bytes (18.3247%), 84,242 data bytes (12.9990%),
2,883 reconstructed data source units.

## Runtime signed-byte accessor checkpoint

Recovered two complete 56-byte record accessors with caller-grounded pointer
inputs, signed-byte returns and native null diagnostic callbacks. Both whole
EE96/SNAS objects verify exactly. Catalog: 603,672 code bytes (18.3281%),
9,225 functions; data 84,242 bytes (12.9990%). Full hybrid linkage and packed
retail ELF identity pass.

## Selected UI and secondary position vectors

Reconstructed two directly selected UI float3 rows and a directly loaded
secondary-position float3. All three compiled data objects, catalog validation,
full hybrid linkage and packed retail ELF identity pass. Data: 84,278 bytes
(13.0046%), 2,886 reconstructed units. Code remains 603,672 bytes (18.3281%).
The UI selector writer audit continues alongside fresh recovery work.

## Runtime descriptor initializer checkpoint

Recovered the complete 48-byte descriptor initializer with caller-grounded
record and three value arguments. It preserves the native conditional writes
and success result. Whole EE96/SNAS object, catalog, full hybrid linkage and
packed retail ELF identity pass. Catalog: 603,720 code bytes (18.3296%),
9,226 functions; data remains 84,278 bytes (13.0046%).

## Runtime field adapter checkpoint

Recovered the complete 36-byte record adapter with its caller-grounded value
arguments and mutable halfword outputs at record+48/+50. The native argument
reordering is preserved. Whole EE96/SNAS object, catalog, full hybrid linkage
and packed retail ELF identity pass. Catalog: 603,756 code bytes (18.3307%),
9,227 functions; data remains 84,278 bytes (13.0046%).

## Runtime service table clear checkpoint

Recovered the complete 36-byte startup clear with a caller-grounded no-argument
void interface and the canonical memory-fill API. Its 960-byte target uses an
interior address alias only; no existing placeholder data gains credit. Whole
EE96/SNAS object, catalog, full linkage and packed retail ELF identity pass.
Catalog: 603,792 code bytes (18.3317%), 9,228 functions; data remains 84,278
bytes (13.0046%).

## Halfword copy and six-step scalar table checkpoint

Recovered the 36-byte record halfword copy with ordinary overlapping-pointer
semantics, and the 24-byte six-step scalar table with initialized counters and
frame-dispatched task groups. Both objects, catalog, full hybrid linkage and
packed retail ELF identity pass. Held twelve bytes at47713C because the selector
nine producer path remains conditional. Catalog: 603,828 code bytes (18.3328%),
9,229 functions; data 84,290 bytes (13.0064%), 2,886 reconstructed units.

## Runtime record field reader checkpoint

Recovered the complete 48-byte signed record-byte reader. Its native caller
passes the referenced record and consumes the returned state byte; the null
path preserves its diagnostic call and -1 result. Whole EE96/SNAS object,
catalog, full hybrid linkage and packed retail ELF identity pass. Catalog:
603,876 code bytes (18.3343%), 9,230 functions; data 84,290 bytes (13.0064%).

## Scaled runtime attribute readers

Recovered two complete 36-byte attribute readers with return-consuming
selector-dispatch evidence. Unsigned widening defines the eleven-bit shift
for negative signed inputs while preserving the native low-word/sign-extension
result; both whole functions remain exact under EE96/SNAS. Catalog, full
hybrid linkage and packed retail ELF pass. Catalog: 603,948 code bytes
(18.3365%), 9,232 functions; data remains 84,290 bytes (13.0064%).

## Animation data pointer selector recovery

Recovered the complete 268-byte pointer selector at175A30, consumed by native
175C00. Ordinary C preserves the actor-kind branches, phase offsets and signed
variant addressing. MWCCPS2 3.0-011126 O3 reproduces the full span; newer MWCC
profiles emitted an extra instruction and remain unsuitable for this unit.
Registered object, catalog, full hybrid linkage and packed retail ELF pass.
Catalog: 604,216 code bytes (18.3446%), 9,233 functions; data 84,290 bytes
(13.0064%). No assembly or forced volatile constraints were used.

## Runtime clear entries and bounded effect vectors

Integrated three caller-grounded clear entries (36,52,36 bytes) and two
float3 effect vectors selected by the explicit0/1 constructor calls. Whole
runtime source objects and all four data partitions verify exactly. Catalog,
full hybrid linkage and packed retail ELF identity pass. Catalog: 604,340 code
bytes (18.3484%), 9,236 functions; data84,314 bytes (13.0101%), 2,888
reconstructed source units. Intervening data spans remain raw placeholders.

## Runtime payload clear checkpoint

Recovered the complete 28-byte record payload clear with a caller-grounded
record pointer and ignored memory-fill result. Whole EE96/SNAS object, catalog,
full hybrid linkage and packed retail ELF identity pass. Catalog: 604,368 code
bytes (18.3492%), 9,237 functions; data 84,314 bytes (13.0101%).

Independent animation-copy helper175B40 probe models the native record stride
and nested halfword-copy loops but remains a compiler-layout mismatch; no
source row or matching credit was added for that candidate.

## Runtime diagnostic and version dispatch integration

Recovered the complete 36-byte diagnostic return and 40-byte version-gated
dispatch. The diagnostic references the existing named string with its verified
address and uses the canonical variadic formatter contract. The dispatcher
accepts the mutable entry it forwards to its callee. Both whole EE96/SNAS
objects, catalog, full hybrid linkage and packed retail ELF pass. Catalog:
604,444 code bytes (18.3515%), 9,239 functions; data84,314 bytes (13.0101%).

## Runtime reset and six-slot vector banks

Recovered the complete 64-byte signed-state record reset and two72-byte
effect-vector banks. Actor setup creates bounded side/slot fields, and slot
swaps preserve the0..5 selector domain; all three components are loaded as
floats. Header and interstitial bytes remain raw. Changed objects, catalog,
full hybrid linkage and packed retail ELF identity pass. Catalog: 604,508 code
bytes (18.3535%), 9,240 functions; data84,458 bytes (13.0324%), 2,890
reconstructed source units.

## Cleanup walker, frame codes and actor vectors

Recovered the complete 96-byte sixteen-entry cleanup walk. Six signed
halfword frame codes and three bounded actor-vector banks add120data bytes;
unused gap bytes remain raw. Changed objects, catalog, full hybrid linkage
and packed retail ELF identity pass. Catalog: 604,604 code bytes (18.3564%),
9,241 functions; data84,578 bytes (13.0509%), 2,899 reconstructed units.
The separately reviewed mode-transition vector table is queued for integration.

## Companion reader, reload setter and transition vectors

Recovered the complete 76-byte companion versioned reader and48-byte reload
count setter. Both versioned readers now load/pass their native pointer handles
with pointer types and still verify exactly. Closed the initialized mode/state
path for nine transition vectors, adding108data bytes; the four-byte tail
remains raw. Changed objects, catalog, full hybrid linkage and packed retail
ELF identity pass. Catalog: 604,728 code bytes (18.3602%), 9,243 functions;
data84,686 bytes (13.0675%), 2,901 reconstructed source units.

## Runtime offset setter checkpoint

Recovered the complete 28-byte object-offset setter, preserving its word store
and forwarded helper result. Whole EE96/SNAS object, catalog, full hybrid
linkage and packed retail ELF identity pass. Catalog: 604,756 code bytes
(18.3610%), 9,244 functions; data remains 84,686 bytes (13.0675%).
Additional SN/EE probes of animation helper175B40 remain size/layout mismatches
and do not receive credit.

## Runtime scalar wrapper and metric dispatch

Recovered the complete 24-byte scalar action wrapper and76-byte signed-mode
metric dispatcher with return-consuming caller evidence. Unsigned multiplication
preserves native low-word doubling without signed overflow; the dispatcher
still verifies exactly. Both whole objects, catalog, full hybrid linkage and
packed retail ELF identity pass. Catalog: 604,856 code bytes (18.3641%),
9,246 functions; data remains84,686 bytes (13.0675%).

## Timer wrappers, bounce transition and target callback

Integrated four whole exact handlers (84,84,120,92 bytes) and corrected their
caller return declarations. Known motion fields use float zeros and the
existing FloatBits constant convention. All ten affected complete source files
verify with their registered recipes, including older MWCC for round2_small.
Catalog, full hybrid linkage and packed retail ELF identity pass. Catalog:
605,236 code bytes (18.3756%), 9,250 functions; data84,686 bytes (13.0675%).
Separate vector-base and JAL-delay-slot reviews rejected unsupported pending
credit before integration.

## Bounded stage data partition checkpoint

Integrated348 reconstructed bytes across packed three-byte parameter words,
bounded stage vectors and six strided frame codes. Explicit actor/mode/frame
producer bounds exclude overlapping stream reads from neighboring vectors.
All21 changed data partitions, eleven data tests, catalog, full hybrid linkage
and packed retail ELF identity pass. Data: 85,034 bytes (13.1212%), 2,913
reconstructed units. Code remains605,236 bytes (18.3756%).
The separate F490 vector-bank correction is queued for integration.

## Corrected F490 actor position bank

Reconstructed672 bytes across vector rows0..23 and27..58 from the true base
F490. The F498 references load each row third component, not a separate table.
Skipped rows24..26, prefix and unrelated tail stay raw. All five partition
objects, catalog, full hybrid linkage and packed retail ELF identity pass.
Data: 85,706 bytes (13.2249%); code remains605,236 bytes (18.3756%).

## Conditional motion, animation event and bounce update

Integrated whole exact callbacks at2F8290 (88bytes),22EEE0 (108bytes) and
22E7E0 (212bytes). Complete source files verify with their registered profiles;
known floating motion constants preserve their bit values through FloatBits.
Catalog, full hybrid linkage and packed retail ELF identity pass. Catalog:
605,644 code bytes (18.3880%), 9,253 functions; data85,706 bytes (13.2249%).

## Reviewed strategy, query and path runtime batch

Integrated five whole exact functions (56,80,92,84,88bytes). Strategy dispatch
uses a void API because its caller does not consume the callee return; the JAL
delay-slot store uses priorV0. The booleanquery uses an integer handle, proved
by1089F0→107670 bounding/scaling it into a32-entry table. Both corrections
remain exact. All five complete objects, catalog, full hybrid linkage and
packed retail ELF identity pass. Catalog: 606,044 code bytes (18.4001%),
9,258 functions; data remains85,706 bytes (13.2249%).

## Bounded sprite coordinate pair bank

Integrated448 bytes across float2 rows0..23 and27..58. The constructor
inputs and composed pair/map lookup both stay in0..58 while excluding24..26;
no selected map output is the FF sentinel. Skipped rows, prefix and tail remain
raw. All five partition objects, catalog, full hybrid linkage and packed retail
ELF identity pass. Data: 86,154 bytes (13.2941%), 2,917 reconstructed units.
Code remains606,044 bytes (18.4001%).

## Indexed motion and linked actor handoff callbacks

Integrated two whole exact callbacks (132,136bytes), preserving float motion
updates, indexed callback dispatch and typed linked-object pointer stores.
Both complete source files, catalog, full hybrid linkage and packed retail
ELF identity pass. Catalog: 606,312 code bytes (18.4083%), 9,260 functions;
data remains86,154 bytes (13.2941%).

## Bounded threshold and scene vector tables

Integrated184 reconstructed bytes: seventeen timer words, seven float3 scene
rows and eight selector-bounded motion thresholds. Native timer initialization
sets both index and byte offset to zero; the offset advances fourbytes per
iteration. Unread tails remain raw. Changed objects, catalog, full hybrid
linkage and packed retail ELF identity pass. Data: 86,338 bytes (13.3224%).
Code remains606,312 bytes (18.4083%).

## Sequential motion integration checkpoint

Integrated three whole exact motion callbacks (132,156,132bytes), including
the floor-clamped update and indexed state dispatch. The complete shared source
file verifies all registered functions with its established compiler profile.
Catalog, full hybrid linkage and packed retail ELF identity pass. Catalog:
606,732 code bytes (18.4210%), 9,263 functions; data86,338 bytes (13.3224%).

## Phase callbacks and selected placement vectors

Integrated two whole exact phase callbacks (132,96bytes) while preserving
existing source functions during conflict resolution. Selected vector rows0/2
add48data bytes; unused rows and gaps stay raw. The complete callback source,
all eight data partitions, catalog, full hybrid linkage and packed retail ELF
identity pass. Catalog: 606,960 code bytes (18.4279%), 9,265 functions;
data86,386 bytes (13.3299%), 2,924 reconstructed units.

## Quadrant sine lookup code recovery

Recovered the complete188-byte float-returning lookup at417440 under older
MWCCPS2. Callers supply16-bit angle values in a32-bit register and consumeF0.
The table uses an incompletef32array/addressalias only; no extent ordata credit
is inferred merely from the code registration. Whole object, catalog, full
hybrid linkage and packed retail ELF identity pass. Catalog:607,148 code bytes
(18.4336%),9,266functions;data86,386bytes(13.3299%). Table recovery is under
separate native-index/consumer review.

## Callback allocation pointer contract

Recovered the complete104-byte allocator callback with pointer return, typed
owner/record slots and both consuming callback APIs corrected. The3DA750
wrapper forwards its owner pointer to the already reconstructed allocator.
The complete source object, catalog, full hybrid linkage and packed retail
ELF identity pass. Catalog:607,252 code bytes(18.4368%),9,267functions;
data remains86,386bytes(13.3299%). The separately bounded quarter-wave data
recovery is queued for independent root verification.

## Quarter-wave table independent verification

Reconstructed65,540 bytes across16,385 finite monotone f32 samples selected
by the native quadrant masks. Root checked contiguouscoverage496A50..4A6A54,
all22 float spans and both rawprefix/gap units against retail. Previously
unowned six-sample bytes are included; adjacent descriptors stay separate.
All24 partition objects, eleven data tests, catalog, full hybrid linkage and
packed retail ELF identity pass. Data:151,926bytes(23.4431%),2,946
reconstructedunits. Code remains607,252bytes(18.4368%); the requested push
threshold still follows verifiedcode progress, next21.0711%.

## Conditional state callback integration

Integrated three whole exact callbacks (84,124,116bytes), preservingexisting
root source during additive conflict resolution. Both complete source files
verify with their registered compiler recipes. Catalog, full hybrid linkage
and packed retail ELF identity pass. Catalog:607,576 codebytes(18.4466%),
9,270functions;data remains151,926bytes(23.4431%).
Descriptor word roles have now been identified as string pointers and are
queued for typed integration rather than generic integer credit.

## Symbolic archive descriptors and bounded scale samples

Reconstructed32bytes of descriptor string-pointer pairs after auditing their
formatter and bytewise path consumers. Numericcasts were replaced with typed
external archive-name/pathbuffer symbols; R32relocations resolve exactly. Six
selected f32 scale samples add24bytes; unread fields andtails stay raw.
Changed objects, catalog, full hybrid linkage and packed retail ELF identity
pass. Data:151,982bytes(23.4517%),2,951reconstructedunits. Code remains
607,576bytes(18.4466%).

## Runtime global initializer verification

Recovered the complete148-byte global reset with its scalarzero/nonzero mode
and void API supported by nativecaller use. The externalstate layout preserves
reservedbytes and evidenced halfword/word writeoffsets; no initializeddata
credit is claimed for that mutable state. Wholeobject, catalog, fullhybrid
linkage and packedretailELF identity pass. Catalog:607,724codebytes(18.4511%),
9,271functions;data remains151,982bytes(23.4517%).

## Project gate and allocator registry audit

All34 projecttests, shellsyntax, and fullassembler splitting pass after recent
source/data integrations; only the five previously documented intentional
alias warnings remain. A newallocatorguard probe matched48bytes, but registry
review found that sameguard already reconstructed in grok_w7_003c. The duplicate
addition was removed before credit, and the canonicalobject-pool object was
restored/reverified. Fullhybrid andpackedretail hashes still pass. Coverage
remains607,724codebytes(18.4511%) and151,982databytes(23.4517%).
A separate uncreditedprobe corrected its LBU/BLEZ gate to zero-only.

## Motion-context profile recovery

Integrated the complete208-byte profile handler with its grounded two-pointer
and integerflag API, preserving the existing companion declaration during
conflict resolution. All three functions in the complete source object verify
exactly. Catalog, fullhybrid linkage and packedretailELF identity pass. Catalog:
607,932codebytes(18.4574%),9,272functions;data151,982bytes(23.4517%).
Fresh Luna worker contexts continue the fullscope recovery.

## Fresh runtime animation integration

Integrated wholeexact76-byte animationmode dispatch and120-byte stateupdate.
The shared175910helper has an existinginteger-return definition; five caller
declarations were corrected fromvoid, with allaffectedcomplete sourceobjects
still exact. Catalog, fullhybrid linkage andpackedretailELF identity pass.
Catalog:608,128codebytes(18.4634%),9,274functions;data151,982bytes(23.4517%).

## Fixed four-float transform recovery

Recovered the 16-byte float vector at 0x004443F0. The native consumer loads
all four components as floats and stores them into four float fields. Both
affected whole data objects verify exactly; hybrid linkage and the packed
retail ELF hash pass. Data reaches 151,998 bytes (23.4542%) across 2,952
reconstructed units. Code remains 608,128 bytes (18.4634%).

The proposed signed-delta bank at 0x004642C0 remains a placeholder because
animation asset copies overwrite its selector and its range is unproven.

## Backend notice initializer

Recovered the complete 124-byte initializer at 0x004207C0, using the existing
backend state type and menu notice interface. Whole-object relocation
verification passes. Code reaches 608,252 bytes (18.4672%) across 9,275
functions. Data remains 151,998 bytes (23.4542%).

## Selector evidence correction

Removed 12 bytes of reconstructed credit at 0x004768A0. Indirect handlers
for the state object at 0x004F7F30 can modify selector byte +2, invalidating
the prior direct-store-only proof. The compiled bytes remain unchanged and
placed as a placeholder. The pending 0x00476BB0 candidate is also held.
Code remains 608,252 bytes (18.4672%); data is 151,986 bytes (23.4523%).

## Velocity floor handler

Recovered the complete 156-byte handler at 0x002E77B0. Both functions in
the changed source object verify exactly; hybrid linkage and the packed
retail ELF hash pass. Code reaches 608,408 bytes (18.4719%), 9,276 functions.
Data remains 151,986 bytes (23.4523%).

## Motion timer sequence

Recovered the complete 172-byte handler at 0x0027C340. Every registered
function in the changed source object remains exact. Catalog validation,
hybrid linkage and the packed retail ELF hash pass. Code is 608,580 bytes
(18.4771%) across 9,277 functions; data is 151,986 bytes (23.4523%).

## Animation copy and deferred motion dispatch

Recovered the complete 192-byte animation record copy helper at 0x00175B40
with MWCCPS2 3.0 O3/Op, and the 196-byte dispatcher at 0x0026FDE0. Whole
source-object verification passes. Code reaches 608,968 bytes (18.4889%)
across 9,279 functions; data remains 151,986 bytes (23.4523%).

## Motion event allocation

Recovered the complete 112-byte child-event allocator at 0x0039E4E0.
Its allocation failure is explicit. The proposed four-record motion stream
at 0x00472854 remains uncredited: its consumer advances the pointer before
allocation, but decrements the record count only on success. Whole-object
verification passes. Code reaches 609,080 bytes (18.4923%), 9,280 functions;
data remains 151,986 bytes (23.4523%).

## Timed state callback

Recovered the complete 196-byte callback at 0x002C1670. All registered
functions in its source object verify exactly. Code reaches 609,276 bytes
(18.4982%), 9,281 functions; data remains 151,986 bytes (23.4523%).

## Motion stream consumer

Recovered the complete 260-byte consumer at 0x0039EE60, including the
stream advance before allocation and the success-only record decrement.
Whole-object verification passes. Code reaches 609,536 bytes (18.5061%),
9,282 functions; data remains 151,986 bytes (23.4523%).

## Complete motion initializer residual

Recovered all 256 bytes of residual_0039ED60, preserving the owner-state
copy, typed float3 copy, timers and tail call. MWCCPS2 3.0 O3/Op produces
an exact whole-object match. Code reaches 609,792 bytes (18.5139%) across
9,283 functions; data remains 151,986 bytes (23.4523%).

## Exit animation sequence

Recovered the complete 200-byte callback at 0x0024AB80. All ten registered
functions in the changed source object verify exactly. Code reaches
609,992 bytes (18.5200%) across 9,284 functions; data remains 151,986 bytes
(23.4523%).

## Runtime callback dispatcher

Recovered the complete 156-byte dispatcher at 0x00411978 under EE GCC
2.96. Native code forwards a 32-bit callback argument and preserves the
original diagnostic conditions. Whole-object verification passes. Code is
610,148 bytes (18.5247%), 9,285 functions; data remains 151,986 bytes
(23.4523%).

## Owner-context motion update

Recovered the complete 124-byte function at 0x002E4690. All eight registered
functions in its source object remain exact. Code reaches 610,272 bytes
(18.5285%), 9,286 functions; data remains 151,986 bytes (23.4523%).

## Scene anchor initializer

Recovered the complete 112-byte initializer at 0x00141250. Native caller
0x003D2344 ignores its result; the source preserves allocation failure,
callback setup and typed float3 position copy. Whole-object verification
passes. Code reaches 610,384 bytes (18.5319%) across 9,287 functions; data
remains 151,986 bytes (23.4523%).

## Owner-linked scene overlay

Recovered the complete 112-byte initializer at 0x0014A220. The source
preserves allocation failure and the exact -0.1f depth representation,
and connects the owner context. Whole-object verification passes. Code
reaches 610,496 bytes (18.5353%), 9,288 functions; data remains 151,986 bytes
(23.4523%).

## Fixed zero-float vector

Recovered exactly 12 bytes at 0x004B192C. Native func_0013E0F0 constructs
a fixed base and loads offsets 0, 4 and 8 as floats. The remaining eight
zero bytes stay untyped. Both changed data objects verify exactly. Data
reaches 151,998 bytes (23.4542%); code remains 610,496 bytes (18.5353%).

## Mode event initializer

Recovered the complete 84-byte initializer at 0x001382F0, preserving
allocation failure, mode byte, timers and callback setup. Whole-object
verification passes. Code reaches 610,580 bytes (18.5378%), 9,289 functions;
data remains 151,998 bytes (23.4542%).

## Owner mode event constructor

Recovered the complete 96-byte constructor at 0x001555A0. It retains
allocation failure and assigns the callback, owner and two byte fields.
Whole-object verification passes. Code reaches 610,676 bytes (18.5408%),
9,290 functions; data remains 151,998 bytes (23.4542%).

## Unit scale event initializer

Recovered the complete 92-byte initializer at 0x0015C130. Ordinary float
assignments reproduce the native three unit-scale stores. Allocation
failure and callback setup remain intact. Whole-object verification passes.
Code reaches 610,768 bytes (18.5435%), 9,291 functions; data remains
151,998 bytes (23.4542%).

## Second unit scale constructor

Recovered the complete 92-byte constructor at 0x0015C3F0 alongside the
related 0x0015C130 function. Both functions in the shared source object
verify exactly. Code reaches 610,860 bytes (18.5463%), 9,292 functions;
data remains 151,998 bytes (23.4542%).

## Runtime fade state reset

Recovered the complete 68-byte reset at 0x0041D5F0. Float state fields
retain the native 0.8 representation through typed bit access, and the
existing empty callback interface is preserved. Whole-object verification
passes. Code reaches 610,928 bytes (18.5484%), 9,293 functions; data remains
151,998 bytes (23.4542%).

## Third unit scale event initializer

Recovered the complete 96-byte initializer at 0x0015C560 in the existing
unit-scale source object. All three functions remain exact. Code reaches
611,024 bytes (18.5513%), 9,294 functions; data remains 151,998 bytes
(23.4542%).

## Fourth unit scale event constructor

Recovered the complete 96-byte constructor at 0x0015C280 in the existing
source object. All four functions remain exact. Code reaches 611,120 bytes
(18.5542%), 9,295 functions; data remains 151,998 bytes (23.4542%).

## Marked and updated event constructors

Recovered all 112 bytes at 0x00135DB0 and all 104 bytes at 0x0015BFB0.
Allocation assignment within the condition reproduces the native branch
sequence. Both whole objects verify exactly. Code reaches 611,336 bytes
(18.5608%), 9,297 functions; data remains 151,998 bytes (23.4542%).

## Fixed storage pointer field

Recovered the four-byte pointer field at 0x004C2534 with a symbolic
relocation to its exact raw byte owner at 0x004BF0C8. The target remains
uncredited; its extent is not inferred from the pointer. Changed data
objects verify exactly. Data reaches 152,002 bytes (23.4548%) across 2,953
reconstructed units; code remains 611,336 bytes (18.5608%).

## Runtime object pointer

Recovered the four-byte Runtime pointer at 0x0043B6F8. Its symbolic
relocation addresses the existing u32 owner plus six words (0x18 bytes),
without introducing overlapping target storage. Consumers return the
pointer and write through it. Surrounding words remain raw. Changed
objects verify exactly. Data is 152,006 bytes (23.4554%) across 2,954 units;
code remains 611,336 bytes (18.5608%).

## Countdown physics integrator

Recovered the complete 136-byte integrator at 0x002B41F0. Every registered
function in the changed source object remains exact under its O4/Op
profile. Code reaches 611,472 bytes (18.5649%), 9,298 functions; data remains
152,006 bytes (23.4554%).

## Second updated event constructor

Recovered the complete 104-byte constructor at 0x0015BB60 in the existing
source object. Both constructors remain exact. Code reaches 611,576 bytes
(18.5681%), 9,299 functions; data remains 152,006 bytes (23.4554%).

## Counted position event constructor

Recovered the complete 128-byte constructor at 0x001571D0. Native caller
0x0015482C supplies the unused middle argument and kind in A2. The source
preserves allocation failure, the signed-byte counter and typed float3
position copy. Whole-object verification passes. Code reaches 611,704 bytes
(18.5720%), 9,300 functions; data remains 152,006 bytes (23.4554%).

## Runtime callback and context fields

Recovered 12 bytes at 0x00488314..0x00488320 using the current consumer contracts: message callback, context pointer, and signed state word. Corrected the initial integer-only declarations. All five data objects verify exactly; full linkage and packed retail hash pass. Data reaches 152,018 bytes (23.4573%); code remains 611,704 bytes (18.5720%).

## October 17 recovery continuation

Integrated complete 188-byte timed control decay and 144-byte paired velocity reset functions. Both changed whole source objects verify exactly. Code reaches 612,036 bytes (18.5820%) across 9,302 functions; data remains 152,018 bytes (23.4573%). Callback/context data types now follow current consumer interfaces.

## Runtime backend integration

Integrated four complete runtime helpers totaling 416 bytes: grid update, effect initialization, animation initialization and two-state animation dispatch. Corrected the installed effect callback declaration to its two-pointer contract. Whole-object verification passes. Code is 612,452 bytes (18.5947%), 9,306 functions; data remains 152,018 bytes (23.4573%).

## Fixed runtime field integration

Recovered accessor-proven runtime fields, preserving surrounding raw owners. Callback and context fields at 0x004891AC/B0 use the current pointer contracts rather than stale integer declarations. Data is 152,051 bytes (23.4623%) across 2,966 reconstructed units; code remains 612,452 bytes (18.5947%).

## Owner-kind event constructor

Recovered the complete 116-byte constructor at 0x001569C0, including byte-kind pool selection, allocation failure, callback and owner-context setup. Whole-object verification passes. Code reaches 612,568 bytes (18.5982%), 9,307 functions; data remains 152,051 bytes (23.4623%).

## Paired owner-kind event constructor

Recovered all 116 bytes at 0x00156AD0 in the existing owner-kind source unit. Both complete functions verify exactly. Code is 612,684 bytes (18.6017%), 9,308 functions; data remains 152,051 bytes (23.4623%).

## Variant mode event constructor

Recovered all 104 bytes at 0x00138280. Native callers provide numeric zero/one arguments for the stored variant word; byte mode, callback, timers and allocation failure are preserved. Whole-object verification passes. Code is 612,788 bytes (18.6049%), 9,309 functions; data remains 152,051 bytes (23.4623%).

## Child scale event constructor

Recovered all 120 bytes at 0x0015BE90, preserving owner linkage, unit scale, callback and allocation failure. Whole-object verification passes. Code is 612,908 bytes (18.6085%), 9,310 functions; data remains 152,051 bytes (23.4623%).

## Paired child scale event constructor

Recovered all 120 bytes at 0x0015BA40 in the existing child-scale source object. Both functions verify exactly. Code reaches 613,028 bytes (18.6122%), 9,311 functions; data remains 152,051 bytes (23.4623%).

## Signed move parameter records

Recovered 24 bytes as six bounded four-byte signed records at 0x004C158C..0x004C15A4. Native consumer 0x00184720 loads signed bytes at offsets 0..3; setup paths provide base or base+4 record pointers. All four data objects and the complete move_setup source object verify exactly. Data reaches 152,075 bytes (23.4660%); code remains 613,028 bytes (18.6122%).

## Runtime transform heap reset

Recovered all 24 bytes at 0x004152E0, clearing the runtime word and forwarding the exact memset result for the 0xF700-byte heap. Whole-object verification passes. Code reaches 613,052 bytes (18.6129%), 9,312 functions; data remains 152,075 bytes (23.4660%).

## Adjacent signed move records

Recovered the eight-byte owner at 0x004C150C as two four-byte signed records. Setup paths select the base and base+4, and the native consumer loads signed offsets 0..3. The data object and every registered state_pair_dispatch function verify exactly. Data reaches 152,083 bytes (23.4673%); code remains 613,052 bytes (18.6129%).

## Unit-color event initializer

Recovered all 100 bytes at 0x00140FD0 with ordinary float assignments, callback setup and allocation failure intact. Whole-object verification passes. Code reaches 613,152 bytes (18.6159%), 9,313 functions; data remains 152,083 bytes (23.4673%).

## Gameplay duplicate-family recovery

Recovered three complete gameplay routines at 0x002EA850 (140 bytes), 0x002EADC0 (168 bytes), and 0x002EC8F0 (136 bytes) using their independently verified duplicate-family C bodies. Every registered function in all three affected objects remains exact under its configured compiler profile. Code reaches 613,596 bytes (18.6294%), 9,316 functions; data remains 152,083 bytes (23.4673%).

## Bounded signed move selector banks

Recovered 48 bytes across five signed-byte owners at 0x004C1508 and 0x004C15A4..0x004C15D0. Setup functions select each four-byte row directly; native consumer 0x00184720 supplies signed component accesses. All changed data and whole gameplay source objects verify exactly. Data is 152,131 bytes (23.4747%), 2,976 reconstructed units; code remains 613,596 bytes (18.6294%).

## Scene resource event constructor

Recovered all 128 bytes at 0x00136C80. Source preserves the resource pointer, typed position vector, callback and allocation failure. Whole-object verification passes. Code reaches 613,724 bytes (18.6333%), 9,317 functions; data remains 152,131 bytes (23.4747%).

## Owner position event constructor

Recovered all 144 bytes at 0x0014E7B0, preserving float input, exact position representation, timer, owner linkage and allocation failure. Whole-object verification passes. Code reaches 613,868 bytes (18.6377%), 9,318 functions; data remains 152,131 bytes (23.4747%).

## Owner timer event constructor

Recovered all 116 bytes at 0x0014EEC0, preserving timer, owner linkage, callback and allocation failure. Whole-object verification passes. Code reaches 613,984 bytes (18.6412%), 9,319 functions; data remains 152,131 bytes (23.4747%).

## Ten-function gameplay recovery batch

Integrated ten complete gameplay routines totaling 1,512 bytes, extending verified duplicate families for timers, callbacks, motion and state resets. Every affected source object verifies with its registered compiler profile. Code reaches 615,496 bytes (18.6871%), 9,329 functions; data remains 152,131 bytes (23.4747%).

## Signed move bank at 0x004C0688

Recovered 24 bytes across four signed-byte owners with six explicit four-byte row pointers. The shared native consumer reads signed components 0..3. All four data objects and the complete move_setup source object verify exactly. Data is 152,155 bytes (23.4784%), 2,980 reconstructed units; code remains 615,496 bytes (18.6871%).

## Child position event constructor

Recovered all 128 bytes at 0x001396E0, preserving parent linkage, inherited mode bytes, float position initialization and allocation failure. Whole-object verification passes. Code reaches 615,624 bytes (18.6910%), 9,330 functions; data remains 152,155 bytes (23.4784%).

## Four-function gameplay batch

Recovered four complete functions totaling 492 bytes: live target selection, paired motion integration, animation completion and a two-context callback sequence. All affected whole source objects verify with their registered profiles. Code reaches 616,116 bytes (18.7059%), 9,334 functions; data remains 152,155 bytes (23.4784%).

## Complete signed move banks

Recovered 144 bytes as 36 four-byte signed records across the banks at 0x004C0CC0 and 0x004C0F30. Every row is selected by an explicit setup pointer and consumed with signed loads at offsets 0..3. The unproven prefix at 0x004C0CB0 remains raw. All changed data objects and the complete move_setup object verify exactly. Data is 152,299 bytes (23.5006%), 2,984 reconstructed units; code remains 616,116 bytes (18.7059%).

## Global gameplay dispatcher

Recovered all 100 bytes at 0x001F9250 in the existing source unit. Every registered function in the object verifies exactly. Code reaches 616,216 bytes (18.7090%), 9,335 functions; data remains 152,299 bytes (23.5006%).

## Runtime entry-slot reset

Recovered all 64 bytes at 0x00414FE0, resetting each eight-byte entry handle/state and clearing the count. Whole-object verification passes under O3/Op. Code reaches 616,280 bytes (18.7109%), 9,336 functions; data remains 152,299 bytes (23.5006%).

## Selected signed move records

Recovered 24 bytes as six explicitly selected four-byte signed records in the banks at 0x004BFF34 and 0x004C1134. Leading words and trailing 48-byte spans remain placeholders. All ten changed data objects and the whole move_setup source object verify exactly. Data reaches 152,323 bytes (23.5043%); code remains 616,280 bytes (18.7109%).

## Three-function gameplay batch

Recovered complete functions at 0x00346030 (80 bytes), 0x001ED230 (168 bytes), and 0x00323DC0 (92 bytes). All affected whole objects verify with their registered profiles. Code reaches 616,620 bytes (18.7212%), 9,339 functions; data remains 152,323 bytes (23.5043%).

## Indexed position event constructor

Recovered all 144 bytes at 0x00144260, preserving indexed vector selection, callback setup and allocation failure. The incomplete external vector-pointer array adds no data-extent credit. Whole-object verification passes. Code reaches 616,764 bytes (18.7256%), 9,340 functions; data remains 152,323 bytes (23.5043%).

## Four complete signed move banks

Recovered 264 bytes across four banks with explicit setup pointers for every four-byte row. The shared native consumer reads signed components 0..3. All four data objects and the complete move_setup object verify exactly. Data reaches 152,587 bytes (23.5451%); code remains 616,764 bytes (18.7256%).

## Small-scale scene event initializer

Recovered all 144 bytes at 0x001445A0, preserving typed position, exact 0.1 scale representation, timers, callback and allocation failure. Whole-object verification passes. Code reaches 616,908 bytes (18.7300%), 9,341 functions; data remains 152,587 bytes (23.5451%).

## Consolidated signed move bank

Recovered all 64 bytes at 0x004C03B0 as 16 explicitly selected four-byte signed records. The data object and complete move_setup source object verify exactly. Data reaches 152,651 bytes (23.5549%), 2,995 reconstructed units; code remains 616,908 bytes (18.7300%).

## Cloned scene event constructor

Recovered all 148 bytes at 0x00135600, preserving inherited fields, typed position copy, opacity, callback and allocation failure. Whole-object verification passes. Code reaches 617,056 bytes (18.7345%), 9,342 functions; data remains 152,651 bytes (23.5549%).

## Additional bounded signed move rows

Recovered 60 bytes across the three-row bank at 0x004BFB7C and the twelve-row suffix at 0x004C0E30. The 16-byte prefix at 0x004C0E20 remains raw. Each recovered row has an explicit setup pointer and signed component reads. Changed data and whole move_setup objects verify exactly. Data reaches 152,711 bytes (23.5642%), 2,997 reconstructed units; code remains 617,056 bytes (18.7345%).

## Background scale event constructor

Recovered all 136 bytes at 0x00136B60 with typed position/scale fields, context linkage, callback and allocation failure intact. Whole-object verification passes. Code reaches 617,192 bytes (18.7386%), 9,343 functions; data remains 152,711 bytes (23.5642%).

## Three-row signed move bank

Recovered 12 bytes at 0x004C1690..0x004C169C from explicit setup pointers and signed native component reads. Both data objects and the whole move_setup object verify exactly. Data reaches 152,723 bytes (23.5660%), 2,999 reconstructed units; code remains 617,192 bytes (18.7386%).

## Extended signed move rows

Recovered 24 bytes as six explicitly selected four-byte signed records at 0x004C06AC..0x004C06B8 and 0x004C06C4..0x004C06D0. The unreferenced twelve-byte span at 0x004C06B8 remains raw. All changed data and whole move_setup objects verify exactly. Data reaches 152,747 bytes (23.5697%), 3,002 reconstructed units; code remains 617,192 bytes (18.7386%).

## Indexed runtime callback dispatch

Recovered all 60 bytes at 0x00411818 using EE GCC 2.96, preserving the optional callback and forwarded context. The incomplete external entry array adds no data-extent credit. Whole-object verification passes. Code reaches 617,252 bytes (18.7404%), 9,344 functions; data remains 152,747 bytes (23.5697%).

## Runtime slot callback reader

Recovered all 40 bytes at 0x00411288 using EE GCC 2.96 with G8. The slot at 0x004C2B10 contains the optional callback and context. Whole-object verification passes. Code reaches 617,292 bytes (18.7416%), 9,345 functions; data remains 152,747 bytes (23.5697%).

## Third-state signed move banks

Recovered 48 bytes across four complete three-row signed banks. Setup paths provide explicit row pointers, and the native consumer loads signed components 0..3. All data and whole move_setup objects verify exactly. Data reaches 152,795 bytes (23.5771%), 3,006 reconstructed units; code remains 617,292 bytes (18.7416%).

## Second runtime callback reader

Recovered all 40 bytes at 0x004112B0 in the existing runtime slot-reader source object. Both functions verify exactly using EE GCC 2.96 G8. Code reaches 617,332 bytes (18.7428%), 9,346 functions; data remains 152,795 bytes (23.5771%).

## Offset effect helper

Recovered all 116 bytes at 0x0015D010, preserving facing-dependent horizontal offset, vertical offset, depth and the subsequent effect callback. Whole-object verification passes. Code reaches 617,448 bytes (18.7464%), 9,347 functions; data remains 152,795 bytes (23.5771%).

## Runtime service lookup

Recovered all 40 bytes at 0x00411B00 using EE GCC 2.96. The source preserves unsigned index validation and guarded table access. Whole-object verification passes. Code reaches 617,488 bytes (18.7476%), 9,348 functions; data remains 152,795 bytes (23.5771%).

## Extended bounded move-data batch

Recovered 504 bytes as 126 explicitly selected signed four-byte rows across 21 source banks. Unreferenced surrounding spans remain raw. All 69 changed data objects and the whole move_setup object verify exactly; row-reference coverage was independently checked. Data reaches 153,299 bytes (23.6549%), 3,036 reconstructed units; code remains 617,488 bytes (18.7476%).

## Resource/depth event constructor

Recovered all 152 bytes at 0x0014D9E0 after confirming native callers supply owner, resource, index and initialization mode in A0..A3 and depth in F12. Whole-object verification passes. Code reaches 617,640 bytes (18.7522%), 9,349 functions; data remains 153,299 bytes (23.6549%).

## Nineteen-function gameplay recovery

Integrated nineteen complete gameplay routines totaling 2,584 bytes across fifteen source objects. Preserved the newer signed move-data references while resolving the setup-source overlap. Every registered function in all affected objects verifies with its configured compiler profile. Code reaches 620,224 bytes (18.8306%), 9,368 functions; data remains 153,299 bytes (23.6549%).

## Runtime text callback pair

Recovered the complete text callback helpers at 0x00411380 (76 bytes) and 0x004113D0 (104 bytes). Both objects verify under EE GCC 2.96 G8, preserving bounded text copies and optional callback dispatch. Code reaches 620,404 bytes (18.8361%), 9,370 functions; data remains 153,299 bytes (23.6549%).

## Deferred and extended signed setup rows

Recovered 48 bytes across six explicitly selected signed row owners, preserving the unreferenced prefix at 0x004C0660. All seven changed data objects and both complete setup source objects verify with their registered compiler versions. Data reaches 153,347 bytes (23.6623%), 3,042 reconstructed units; code remains 620,404 bytes (18.8361%).

## Accepted transitions and runtime value command

Recovered two complete 164-byte accepted-transition handlers and a 68-byte runtime command helper. Both affected whole source objects verify with their required compiler versions and flags. Code reaches 620,800 bytes (18.8481%), 9,373 functions; data remains 153,347 bytes (23.6623%).

## Additional deferred signed move banks

Recovered 88 bytes as 22 explicitly selected four-byte signed rows, preserving unreferenced surrounding spans as placeholders. All fourteen changed data objects and the complete deferred_move_setup object verify with the required compiler profile. Data reaches 153,435 bytes (23.6759%), 3,048 reconstructed units; code remains 620,800 bytes (18.8481%).

## Fixed position event constructor

Recovered all 148 bytes at 0x0014EA80, preserving fixed float representations, timer, owner linkage, callback and allocation failure. Whole-object verification passes. Code reaches 620,948 bytes (18.8526%), 9,374 functions; data remains 153,435 bytes (23.6759%).

## Entry group and animation spawn recovery

Recovered complete functions at 0x003419A0 (76 bytes) and 0x00298A30 (164 bytes). Both affected whole source objects verify with their registered compiler version and scheduling options. Code reaches 621,188 bytes (18.8599%), 9,376 functions; data remains 153,435 bytes (23.6759%).

## Additional launch-effect initializer

Recovered all 148 bytes at 0x002C4760 in the existing launch-effect source object. Every registered function in the object verifies with its O3/Op profile. Code reaches 621,336 bytes (18.8644%), 9,377 functions; data remains 153,435 bytes (23.6759%).

## Position/scale/color event pair

Recovered two complete constructors at 0x00157970 (152 bytes) and 0x001576A0 (156 bytes), preserving typed position copies, scale/color fields, callbacks and allocation failure. Both functions verify exactly in one source object. Code reaches 621,644 bytes (18.8738%), 9,379 functions; data remains 153,435 bytes (23.6759%).

## Owner callback constructor

Recovered all 92 bytes at 0x001B0FA0, preserving inherited context, owner linkage, mode byte, callback and allocation failure. Whole-object verification passes. Code reaches 621,736 bytes (18.8765%), 9,380 functions; data remains 153,435 bytes (23.6759%).

## Owner child-event constructor

Recovered all 96 bytes at 0x0019CD70, preserving linked owner context, mode initialization, callback and allocation failure. Whole-object verification passes. Code reaches 621,832 bytes (18.8795%), 9,381 functions; data remains 153,435 bytes (23.6759%).

The proposed transition-table promotion remains held: native animation records can overwrite the column selector, and its binary domain is unproven. No unsupported table credit was integrated.

## Two-context event constructor

Recovered all 100 bytes at 0x001ACDC0, preserving both context pointers, mode byte, callback and allocation failure. Whole-object verification passes. Code reaches 621,932 bytes (18.8825%), 9,382 functions; data remains 153,435 bytes (23.6759%).

## Owner callback and one-time runtime initialization

Recovered complete helpers at 0x0036C050 (92 bytes) and 0x00413D50 (68 bytes). All registered functions in both affected objects verify exactly. Code reaches 622,092 bytes (18.8874%), 9,384 functions; data remains 153,435 bytes (23.6759%).

## Runtime request preparation

Recovered all 108 bytes at 0x00413DF0, preserving stack request preparation and forwarded argument order. Whole-object verification passes. Code reaches 622,200 bytes (18.8906%), 9,385 functions; data remains 153,435 bytes (23.6759%).

## Owner mode child constructor

Recovered all 100 bytes at 0x001978B0, preserving owner pointer, inherited actor byte, mode, callback and allocation failure. Whole-object verification passes. Code reaches 622,300 bytes (18.8937%), 9,386 functions; data remains 153,435 bytes (23.6759%).

## Gameplay transition variant batch

Recovered three complete routines totaling 420 bytes. Both affected source objects verify with their distinct registered compiler versions and scheduling flags. Code reaches 622,720 bytes (18.9064%), 9,389 functions; data remains 153,435 bytes (23.6759%).

## Runtime transform preparation pair

Recovered two complete 104-byte wrappers at 0x00417170 and 0x00417200. The source preserves vector inputs, matrix preparation and native unsigned offset shifting. Both functions verify exactly in one object. Code reaches 622,928 bytes (18.9127%), 9,391 functions; data remains 153,435 bytes (23.6759%).

## Bounded ten-entry map

Recovered 40 bytes at 0x004381E0 from a consumer with an explicit unsigned index<10 guard. The surrounding library-data owners remain raw. All three data objects and the complete SN GCC lookup object verify exactly. Data reaches 153,475 bytes (23.6821%), 3,049 reconstructed units; code remains 622,928 bytes (18.9127%).

## State-specific gameplay setup

Recovered all 104 bytes at 0x00320ED0 in the existing gameplay source object. Every registered function remains exact with its registered O3/G8 profile. Code reaches 623,032 bytes (18.9159%), 9,392 functions; data remains 153,475 bytes (23.6821%).

## Masked signed-byte lookup

Recovered all 32 bytes at 0x0044ED00. The consumer masks the signed timer with 0x1F before each byte lookup, establishing the complete extent. The data object and whole consumer source object verify exactly. Data reaches 153,507 bytes (23.6870%), 3,050 reconstructed units; code remains 623,032 bytes (18.9159%).

## Paired owner mode constructor

Recovered all 100 bytes at 0x001B6750 in the existing owner-mode source object. Both complete functions verify exactly. Code reaches 623,132 bytes (18.9189%), 9,393 functions; data remains 153,507 bytes (23.6870%).

## Owner flags event constructor

Recovered all 100 bytes at 0x001D6B50, preserving unsigned halfword flag transfer, owner pointer, mode, callback and allocation failure. Whole-object verification passes. Code reaches 623,232 bytes (18.9220%), 9,394 functions; data remains 153,507 bytes (23.6870%).

## Event registration and collision response

Recovered complete functions at 0x0037EA30 (100 bytes) and 0x002CE1D0 (112 bytes). Added the missing interleaved compile/verify recipes for both new source units and retained typed representations for motion float fields. Both objects verify exactly. Code reaches 623,444 bytes (18.9284%), 9,396 functions; data remains 153,507 bytes (23.6870%).

## Runtime message-state dispatch

Recovered all 96 bytes at 0x0041B130. Corrected its animation-helper declaration to the existing integer-return interface; bytes remain exact. Code reaches 623,540 bytes (18.9313%), 9,397 functions; data remains 153,507 bytes (23.6870%).

## Parallel Claude reconciliation

Merged origin/main through 122e0677, retaining existing verified callbacks and compiler recipes. Added 41 new independently verified functions (2,768 bytes); fourteen overlapping recoveries keep the existing credited source. All 34 tests pass. Code reaches 626,308 bytes (19.0154%), 9,438 functions; data remains 153,507 bytes (23.6870%). README contains coordination notes for Claude. Full-build gate remains pending in the primary checkout before publication.

## Main-branch parallel-work reconciliation

Merged public main through 1add6e31, deduplicated eight additional overlapping definitions, and independently verified every new source object. Combined code is 633,460 bytes (19.2325%); data is 153,507 bytes (23.6870%). All 34 tests pass; exact combined linkage and packed ELF checked before push. The separate full recompilation remains in progress.

## Post-main conditional gameplay chain

Integrated the complete 300-byte function at 0x001FC080. Four queued worker results overlapped merged public-main functions and were deduplicated without extra credit. The new source object verifies exactly. Code reaches 638,428 bytes (19.3833%), 9,596 functions; data remains 153,507 bytes (23.6870%). Next push milestone remains 20.3742% from the prior published checkpoint.

## Runtime effect float slot

Recovered the four-byte float at 0x004C2530 from its typed native loads/stores and exact 1.0f initialization. Data and initializer source objects verify exactly. Data reaches 153,511 bytes (23.6876%), 3,051 reconstructed units; code remains 638,428 bytes (19.3833%).

## Caller-bounded unsigned-byte lookup

Recovered the 18-byte prefix at 0x0044DDA0. Native call sites pass constant17 or the positive countdown initialized11; lookup is skipped at nonpositive count. No literal function-pointer references were found. The fourteen-byte tail stays raw. Both data and all affected whole source objects verify exactly. Data reaches 153,529 bytes (23.6904%), 3,052 reconstructed units; code remains 638,428 bytes (19.3833%).

## Cleared-mode child constructor

Recovered all 104 bytes at 0x001D36E0, preserving mode initialization, actor byte, owner linkage, callback and allocation failure. Whole-object verification passes. Code reaches 638,532 bytes (19.3865%), 9,597 functions; data remains 153,529 bytes (23.6904%).

## Owner two-mode event constructor

Recovered all 108 bytes at 0x001D2730, preserving both mode bytes, owner pointer, callback and allocation failure. Whole-object verification passes. Code reaches 638,640 bytes (19.3898%), 9,598 functions; data remains 153,529 bytes (23.6904%).

## Owner-mode gameplay dispatch

Recovered all 84 bytes at 0x0039C960 with the owner/object comparison, mismatch handler and indexed callback path preserved. Whole-object verification passes. Code reaches 638,724 bytes (19.3923%), 9,599 functions; data remains 153,529 bytes (23.6904%).

## Address builder and handoff dispatch

Recovered complete functions at 0x003DBA30 (84 bytes) and 0x0020A910 (88 bytes). Both new source objects verify with their registered profiles. Code reaches 638,896 bytes (19.3975%), 9,601 functions; data remains 153,529 bytes (23.6904%).

## Overlay vertex template

Recovered all 64 bytes at 0x004771D0 as four sixteen-byte vertex records. Native setup writes depth/attributes at record+8/+12; renderer 0x00417AE0 loads every coordinate as a float and packed attributes as words. The third float is depth, not opacity. Data object verifies exactly. Data reaches 153,593 bytes (23.7003%), 3,053 reconstructed units; code remains 638,896 bytes (19.3975%).

## Child-mode gameplay dispatch pair

Recovered complete wrappers at 0x0020C040 and 0x0020C230, 76 bytes each. Both functions in the shared source object verify exactly. Code reaches 639,048 bytes (19.4022%), 9,603 functions; data remains 153,593 bytes (23.7003%).

## Collision setup and child dispatch

Recovered complete functions at 0x002E7700 (64 bytes) and 0x00362760 (88 bytes). The external callback array remains incomplete, avoiding an unsupported extent claim. Both source objects verify exactly. Code reaches 639,200 bytes (19.4068%), 9,605 functions; data remains 153,593 bytes (23.7003%).

## Owned-event advance handler

Recovered all 84 bytes at 0x002CE850 with frame completion, state changes and event creation preserved. Whole-object verification passes. Code reaches 639,284 bytes (19.4093%), 9,606 functions; data remains 153,593 bytes (23.7003%).

## Two-context child constructor

Recovered all 108 bytes at 0x001D1B80, preserving distinct context fields, mode, callback and allocation failure. Whole-object verification passes. Code reaches 639,392 bytes (19.4126%), 9,607 functions; data remains 153,593 bytes (23.7003%).

## Parallel-main reconciliation through 81c130a2

Integrated 93 additional non-overlapping functions (7,244 bytes) from Claude, preserving six existing exact recoveries. Independently rebuilt every new source object; catalog and all 34 tests pass. Combined code reaches 646,636 bytes (19.6325%), 9,700 functions; data remains 153,593 bytes (23.7003%). Publication threshold remains 20.3742% from the last Codex main push.

## Threshold activation and physics countdown

Recovered complete functions at 0x001EE480 (128 bytes) and 0x001DDBA0 (140 bytes). Both affected whole source objects verify with their respective registered compiler versions. Code reaches 646,904 bytes (19.6407%), 9,702 functions; data remains 153,593 bytes (23.7003%).

## Ramp-update duplicate audit

Queued worker functions 0x0012A120 and 0x0012A170 already exist in the reconciled public-main sources wave11b.c and wave12b.c. Removed the duplicate import and retained their verified canonical rows. No additional code credit.

## Two-context state constructor

Recovered all 108 bytes at 0x001D8580, preserving both context pointers, mode, state word, callback and allocation failure. Whole-object verification passes. Code reaches 647,012 bytes (19.6440%), 9,703 functions; data remains 153,593 bytes (23.7003%).

## Owner submode dispatch

Recovered all 88 bytes at 0x003C4550 in the existing wave11b source object. All registered functions in the object verify exactly. Code reaches 647,100 bytes (19.6466%), 9,704 functions; data remains 153,593 bytes (23.7003%).

## Linked flags event constructor

Recovered all 108 bytes at 0x001CCC20, preserving copied context/flags, mode initialization, callback and allocation failure. Whole-object verification passes. Code reaches 647,208 bytes (19.6499%), 9,705 functions; data remains 153,593 bytes (23.7003%).

## Mode-event dispatch helper

Recovered all 72 bytes at 0x00334D80 in the existing wave14d object. Both registered functions verify exactly with MWCCPS2 3.0 O3/G8. Code reaches 647,280 bytes (19.6521%), 9,706 functions; data remains 153,593 bytes (23.7003%).

## Alternate transform sequence

Recovered all 84 bytes at 0x003F3BE0 in the existing wave5 source object. Every registered function in the object verifies exactly. Code reaches 647,364 bytes (19.6546%), 9,707 functions; data remains 153,593 bytes (23.7003%).

## Inherited-mode event constructor

Recovered all 108 bytes at 0x00194100, preserving allocator owner input, inherited context/actor fields, signed mode increment, callback and allocation failure. Whole-object verification passes. Code reaches 647,472 bytes (19.6579%), 9,708 functions; data remains 153,593 bytes (23.7003%).

## Alternate SDK reentrant seek

Recovered all 96 bytes at 0x0011EAA0 using the established EE GCC 2.96 pipeline, preserving wide seek arguments and error handling. Whole-object verification passes. Code reaches 647,568 bytes (19.6608%), 9,709 functions; data remains 153,593 bytes (23.7003%).

## Mode and flags child constructor

Recovered all 112 bytes at 0x001CB610, preserving mode initialization, inherited actor byte, unsigned flags transfer, owner pointer, callback and allocation failure. Whole-object verification passes. Code reaches 647,680 bytes (19.6642%), 9,710 functions; data remains 153,593 bytes (23.7003%).

## Owner mode/timer constructor

Recovered all 108 bytes at 0x00199DE0, preserving the byte mode, halfword timer, owner context, callback and allocation failure. Whole-object verification passes. Code reaches 647,788 bytes (19.6675%), 9,711 functions; data remains 153,593 bytes (23.7003%).

## Sony GCC ROM version reader

Recovered all 160 bytes at 0x001004E0 with Sony EE GCC 2.9-991111 `-O2 -G0 -ffunction-sections`. The routine reads `rom0:ROMVER`, closes the file, parses its version suffix and compares it with `0x01315670`. The unmodified compiler/assembler object matches the complete retail function.

Recovered all 160 bytes at 0x00101D50 with Sony EE GCC 2.9-991111 `-O2 -G0 -ffunction-sections`. The routine transitions a runtime mode, releases an existing mode before replacing it, stores the returned parameter and reports the previous state. Its unmodified compiler/assembler object matches the complete retail function.

Combined public-main Sony checkpoint after overlap reconciliation: six newly recovered functions, 584 bytes, independently compiled without opcode substitutions and linked as isolated replacements into the exact retail image. Current catalog: 1,342,072 code bytes (40.7467%), 14,416 functions. Worker-local percentages above reflect older bases.

Local Sony follow-on: the enabled buffer-slot byte setter (100 bytes) and two cache-line alignment wrappers (20 bytes each) pass independent unpatched compiler/object verification. The nine-function Sony batch (724 bytes) reproduces the exact image/packed ELF when linked as isolated replacements; other spans remain retail in this batch proof. Local catalog: 1,342,212 bytes (40.7509%), 14,419 functions. Last public checkpoint remains 09d6665d; next scheduled push threshold is 1,375,009 verified code bytes (41.7467%).

Local Sony checkpoint: four RPC command helpers (408 bytes), timed semaphore wait (104 bytes), and four SDK wrappers (132 bytes) add 644 independently verified bytes. The 18-function Sony batch now totals 1,368 bytes and its isolated compiled sections reproduce the retail loaded image and packed ELF, while other spans remain retail in this batch proof. Local catalog: 1,342,856 bytes (40.7705%), 14,428 functions. Public checkpoint remains 09d6665d; next scheduled push threshold remains 1,375,009 code bytes.

Local Sony checkpoint: control-state probe (104 bytes), RPC wait/query helper (108 bytes), four syscall record wrappers (156 bytes) and ring-cursor update (60 bytes) add 428 independently verified bytes. The 25-function Sony batch totals 1,796 bytes and reproduces the loaded image and packed ELF as isolated replacements. Local catalog: 1,343,284 bytes (40.7835%), 14,435 functions. A separate full compiler/link pass is running on frozen snapshot 898a3cbd; this note does not claim its completion. Next push threshold remains 1,375,009 code bytes.

Recovered all 188 bytes at 0x00100908 with Sony EE GCC 2.9-991111 `-O2 -G0 -ffunction-sections`. The routine routes a five-word GS packet to one of two register maps based on the stored system version. Its unmodified compiler/assembler object matches the complete retail function.

Local Sony checkpoint: RPC result helper (108 bytes), two ABI-reviewed variadic wrappers (56 and 96 bytes), GS packet writer (188 bytes), and flag clear (28 bytes) add 476 exact bytes. The 30-function Sony batch totals 2,272 bytes and reproduces the loaded image and packed ELF as isolated replacements. Logger declarations were aligned with the recovered void-return wrapper and recompiled exactly. Local catalog: 1,343,760 bytes (40.7979%), 14,440 functions. The frozen full compiler/link pass remains in progress; next push threshold remains 1,375,009 code bytes.

Local Sony checkpoint: four guarded RPC routines add 448 exact bytes, preserving initialization rejection, four-byte transfer sizes, and unsigned failure sentinels. All 34 Sony functions (2,720 bytes) reproduce the loaded image and packed ELF as isolated replacements. Local catalog: 1,344,208 bytes (40.8115%), 14,444 functions. The separate frozen full build remains in progress. Next push threshold remains 1,375,009 code bytes.

Local Sony checkpoint: four parameterized RPC operations add 496 exact bytes. The eight-function guarded RPC source verifies in full; the 38-function Sony batch totals 3,216 bytes and reproduces the loaded image and packed ELF as isolated replacements. Local catalog: 1,344,704 bytes (40.8266%), 14,448 functions. The frozen full build remains in progress. Next push threshold remains 1,375,009 code bytes.

Local pre-reconciliation callback checkpoint: the three event callback routines add 296 exact bytes. Their internal references require the ownership-checked section resolver, with missing/ambiguous/padded-anchor rejection tests. This local catalog is 1,345,000 bytes (40.8356%), prior to incorporating the parallel wave-16 additions. All initialized-data objects in the frozen full build have passed; its remaining code checks are active.


Reconciled Sony / wave-16 publication: independently compiled all 150 incoming
source files (261 functions), then reverified their objects against the combined
symbol map. No duplicate credited names or conflicting shared addresses were
found. The 41-function Sony batch (3,512 bytes) reproduces the loaded retail
image and packed ELF; this is an isolated replacement proof, while the frozen
full compiler/link run remains active. Combined catalog: 1,417,244 code bytes
(43.0290%), 14,712 functions, 153,593 data bytes (23.7003%). All 38 repository
tests and two Sony tool tests pass. Next scheduled Codex code publication is
1,450,181 verified bytes (44.0290%), subject to fresh parallel reconciliation.


Local follow-on: two Sony message-dispatch helpers add 148 exact code bytes.
The third related helper still differs and remains uncredited. Recovered the
256-byte lookup at 0x004B6A68 after confirming func_001E3BB0 truncates its
index to an unsigned byte; the 32-byte prefix and 152-byte suffix retain
placeholder status. All three split data objects verify against retail.
Local catalog: 1,417,392 code bytes (43.0335%), 153,849 data bytes (23.7398%).
The updated conservative Sony audit found C for 27 of 173 candidates and
38 exact compiler/source/flag profiles, including alternative flag profiles;
this does not establish the original claimed set of 196 functions.

Local Sony handler registration: 0x0010C1A8 (96 bytes) and 0x0010C208 (132 bytes) match unmodified Sony O2/G0 output. The latter preserves the 1..13 index check, prior-handler return and different registration calls for indices 1..3. Combined code reaches 1,417,620 bytes (43.0404%).

Local Sony RPC shutdown: all 128 bytes at 0x0010D540 match. The recovered helper returns the server response and clears the initialized flag only after a response of one. All five functions in the grouped query object reverify exactly; code reaches 1,417,748 bytes (43.0443%).


Full linkage checkpoint: frozen snapshot 898a3cbd completed `make hybrid`,
including all registered compiler recipes and initialized-data objects. Its
loaded image and packed retail ELF match exactly. The current combined catalog
was then linked using those verified objects plus independently recompiled
wave-16 and later Sony/data additions. All current source changes since the
snapshot were covered by those compiler passes. Current hybrid linkage and
packed ELF are exact as well: loaded SHA-256
c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f;
packed ELF SHA-256
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
This remains a hybrid reconstruction: unrecovered spans are retail bytes.

The 92-byte side-packet dispatcher now matches natural C after retaining its
common result epilogue. Sony recoveries total 47 functions / 4,108 bytes.
A separate 12-byte native three-float position vector is now reconstructed,
with both observed consumers reading exactly its three components. Current
catalog: 1,417,840 code bytes (43.0471%), 14,718 functions; 153,861 data bytes
(23.7416%). Public 8126a486 has green CI and decomp.dev shows 43.03% code
and 23.70% data from that commit. The linkage checkpoint is published early
so parallel work can use the confirmed complete build foundation.


Local Sony follow-on after fecb5956: initialization at 0x0010D4A0 adds 156
exact bytes, clearing the observed fields in eight seven-word slots before its
RPC. The three-function compatibility/query source adds 428 exact bytes at
0x0010B298, 0x0010B770 and 0x0010B8A0, preserving signed error returns and
native calls. All objects recompile and verify against the current catalog.
The three-float constant at 0x004443B8 adds 12 reconstructed data bytes, with
direct fixed component loads supporting its finite extent. Current code:
1,418,424 bytes (43.0648%); next scheduled publication threshold from fecb5956
is 1,450,777 bytes (44.0471%).


Local callback and data follow-on: the 160-byte event completion callback at
0x0010E6D0 now matches with volatile shared state and the correct integer-return
semaphore syscall declaration. All four functions in its grouped source verify
in full. The 132-byte record-threshold poll also matches after aligning its
logger declaration with the recovered variadic void function. Fixed vectors at
0x004B8290, 0x004454F8, 0x00442590 and 0x00443E2C are reconstructed from direct
component consumers; split padding remains placeholder. Current catalog before
the assembly-credit audit: 1,418,716 code bytes (43.0737%), 14,724 functions;
153,921 data bytes (23.7509%). A fresh full combined link passed immediately
before the event callback and final vector addition; their objects pass exact
verification and will be included in the next full link.


The additional fixed records at 0x004443D0 (four floats) and 0x004B1E38
(three floats) now compile and verify in their split data units. Both have
direct native consumers of exactly those components; surrounding prefixes
and zero suffixes remain placeholders. Reconstructed initialized data reaches
153,949 bytes (23.7552%) before the assembly-credit audit. The code catalog
is unchanged by this data work.


Assembly-credit correction: the audit found 56 whole-function FN instruction
streams (6,048 bytes). Retained the 112 bytes of existing COP0 status/interrupt
primitives under the explicit CPU-operation exception, including the tightly
coupled DI/SYNC/status-poll sequence. Demoted the other 53 streams (5,936 bytes),
plus the 20-byte vector-subtraction and two NOP spin/delay implementations
(364 bytes). Total correction: 56 functions / 6,320 bytes. Sources and compiler
recipes remain intact for exact hybrid linkage, but these placeholders earn
zero C credit. docs/ASSEMBLY_CREDIT_AUDIT.csv records the initial disposition.
A report gate catches this repository's whole-function FN assembly convention;
its negative control failed on the formerly credited vector stream. Genuine C
neighbors and correctly classified placeholders pass. All 39 repository tests
and two Sony tool tests pass. Empty optimizer barriers are being reverified
separately; this is not a claim that those source constraints are resolved.


Replaced four obsolete assembly copies (0x0010C2A0, 0x0010CAD8,
0x0010CD08 and 0x0010D128) with natural C loops compiled by Sony 2.9 O2/G0.
All four complete 56-byte functions verify independently; deleted their old FN
bodies and registered the new grouped source. These restore 224 bytes of valid
C credit after the audit correction; they are not newly discovered executable
bytes. Code now reaches 1,412,620 bytes (42.8886%) before resolving the empty
barrier audit. The separate non-FN barrier cleanup is still in progress.


Recovered the previously held 160-byte wait/query helper at 0x0010F148 with
unmodified Sony O2/G0 output. Its blocking path waits on the shared busy state
or RPC activity, while the query path returns a boolean. Correct volatile
state and the recovered void variadic logger declaration preserve the target
operations; a combined query condition reproduces its branches. The final
formatted source recompiled and passed full-byte verification. Local code is
1,412,780 bytes (42.8935%), before the pending compiler-barrier audit.


Recovered the full 16-byte ASCII hexadecimal digit table at 0x004959D8.
`func_00410540` masks each of its seven lookup indices to a nibble, establishing
complete coverage of entries 0..15; its existing exact object and the compiled
data object both verify against the private target. Reconstructed data reaches
153,965 bytes (23.7577%).


Completed the optimizer-constraint audit: 42 empty-asm statements across 37
functions were tested without those constraints, using existing recipes.
Five statements could be removed from three functions (412 bytes), preserving
all selected functions in their objects. The other 34 functions (3,232 bytes)
and the 96-byte unused register-pin dependency are now placeholders. Root
independently recompiled the three changed full objects and all passed exact
verification. Supported prototype corrections were tested, but did not solve
the remaining functions under those profiles. Further real compiler-profile
probes are assigned explicitly in README. All 162 MWCC kernel syscall wrappers
were recompiled exactly and retain the required CPU-operation exception.

Corrected publication catalog: 1,409,452 / 3,293,696 code bytes (42.7924%),
14,638 credited functions, and 153,965 / 648,064 reconstructed data bytes
(23.7577%). Sony recovery totals 58 complete C functions / 5,368 bytes, including
four replacements of formerly miscredited assembly. The 173-span probe now has
40 C definitions and 53 exact compiler/source/flag profiles; 133 spans still lack
C definitions. This does not claim verification of the unavailable original
196-function list. Whole-function sizes and relocated-byte checks stay strict.


Final correction gates passed: all 40 repository tests and two Sony tool tests,
catalog/report generation, and the current full combined hybrid/packed-image
checks. The loaded image remains SHA-256
c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f;
the packed retail ELF remains SHA-256
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
Physical assembly replacements remain in that hybrid proof but earn zero C
credit where classified placeholder. The corrected publication checkpoint is
1,409,452 code bytes; the next scheduled code push threshold is 1,442,389 bytes
(43.7924%), subject to reconciliation with parallel verified work.


Larger gameplay recovery: all 436 bytes at 0x00190130 now match MWCCPS2
3.0.3 O3/Op/G8. The routine processes two player records, updates the observed
signed timers and paired values, clamps the values to 1 or 144 as appropriate,
and calls the refresh helper after each change. Natural do-while loops retain
independent record offsets; assignment-expression comparisons preserve the
retail signed-short conversions. No assembly or opcode changes are used.


Real compiler profiles recover eight constraint-free functions (288 bytes)
from the audit: four use Sony 2.9 O2/G0 and four use EE GCC 2.96 O1/G0.
The status-reset pair is grouped, as are the O1 wrappers. Their original
barrier-dependent definitions were deleted; all three new full objects and
all eight affected original source objects independently recompile exactly.
There are 27 remaining optimizer-constraint placeholders. Together with the
436-byte player timer routine, this local follow-on adds 724 verified C bytes
since e7c78e97, reaching 1,410,176 bytes (42.8144%).


First larger gameplay batch: five complete routines total 1,720 bytes:
0x00190130 (436), 0x001804F0 (336), 0x00180890 (404), 0x002004B0 (272), and
0x00201A80 (272). Root independently recompiled every object. The stage state
uses proper two-player arrays at 0x7C/0x80 and a symbolic BSS byte reference;
the entity initializer uses an observed 16-byte-aligned two-float local rather
than unused scratch words. Known animation helper declarations were aligned
with the existing int-returning definitions, and all objects remained exact.
Together with the eight constraint-free compiler matches, this checkpoint adds
2,008 verified C bytes since e7c78e97. The worker ranges are now explicit gameplay
ranges in README, and the next batch continues independently.


The first larger batch passes the complete current hybrid link and packed
retail ELF checks, with the same retail hashes recorded above. Catalog:
1,411,460 code bytes (42.8534%), 14,651 credited functions, 153,965 reconstructed
data bytes (23.7577%). All new and changed objects were independently compiled.
After publishing this coordination checkpoint, the next scheduled full-point
threshold is 1,444,397 code bytes (43.8534%). Further exact worker results are
queued for the next part so publication does not wait for ongoing searches.


The next larger gameplay batch adds 14 complete C functions / 3,724 bytes
since d59cb58f. Runtime state/attachment/motion routines are 0x00200960 (44),
0x00202CA0 (220), 0x00202860 (364), 0x002029D0 (368), 0x00203360 (320), and
0x00207AC0 (236). Other verified routines are 0x001A1230 (232), 0x0015C2E0
(264), 0x00180F20 (556), 0x00167700 (224), 0x0021F740 (204), 0x0021F8E0
(204), 0x0014F9F0 (264), and 0x00378E90 (224). Root separately compiled each
full object and verified relocated bytes against retail. Template similarity was
used only for candidate selection; it did not substitute for verification.

The launch variants use a proper two-player state array. The stage dispatcher
preserves the observed zero second arguments, and the motion setup uses the
observed aligned two-float payload. All recipes are registered in the normal
build script, with no opcode rewriting, assembly lifts or codegen barriers.
Catalog: 1,415,184 / 3,293,696 C code bytes (42.9664%), 14,665 credited functions,
and unchanged 153,965 / 648,064 data bytes (23.7577%).


The publication set also includes 0x001EA110 (296), 0x00209690 (240),
0x002097F0 (240), 0x00349320 (244), 0x001EAB70 (244), and 0x00207C80 (268),
bringing this checkpoint to 20 additional exact C functions / 5,256 bytes since
d59cb58f. Root independently compiled these units, including all 14 registered
functions in the changed y5_e.c object. New animation helper declarations use
the existing int-returning ABI with explicit signed-byte conversions as needed;
the owner-state indicator also uses a proper two-player array. All remain exact.
Catalog: 1,416,716 code bytes (43.0130%), 14,671 credited functions; data remains
153,965 bytes (23.7577%). This checkpoint publishes progress before the existing
full-point threshold of 1,444,397 bytes, which remains the next scheduled gate.


Final combined hybrid relink and retail ELF packing both pass for this
43.0130% checkpoint. Loaded image SHA-256 remains
c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f;
packed retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
The 40 repository tests and two Sony tooling tests pass, as do catalog validation,
report generation, shell syntax and whitespace checks. Each newly added function
has its own full compiler/object verification in addition to that combined proof.


The next batch adds twelve complete genuine-C functions / 3,108 bytes:
0x0036AE90 (236), 0x001EB9C0 (256), 0x0028B4D0 (284), 0x00297B40 (256),
0x0026C020 (208), 0x0029D060 (236), 0x00321A90 (232), 0x002BC230 (284),
0x00218750 (228), 0x00217AD0 (208), 0x002DB600 (440), and 0x0020FA50 (240).
Root independently compiled and verified every new full object, plus all
registered functions in the modified y2_a.c unit. The handoff payload is a real
aligned two-float vector; the retail 0x001548D0 helper reads only offsets 0/4.

Two candidates were rejected: 0x00248B10 needs a fabricated volatile self-read,
and 0x003F2BF0 only matched after importing invented helper bodies from L3_f.c.
Those helpers use unrelated arithmetic and extra unpassed arguments to shape
caller clobbers; they are not retail reconstructions. The natural external-call
version remains a 704-byte near match, without credit. The existing
0x003F2EB0 (736 bytes) has accordingly been changed from complete to placeholder;
its hybrid object still matches retail but no longer earns C credit. The 0x002340F0 probe also stays uncredited.

Together, the two batches since d59cb58f add 32 genuine C functions / 8,364 bytes
and remove the older 736-byte credit, for a net gain of 7,628 code bytes.
Current catalog: 1,419,088 / 3,293,696 code bytes (43.0850%), 14,682 credited
functions, and unchanged 153,965 / 648,064 data bytes (23.7577%). All recipes are
registered; no proprietary inputs or tool binaries are added to the repository.


The corrected second batch passes all 42 tests, catalog/report generation,
shell syntax and whitespace checks. Its full combined hybrid relink and packed
retail ELF checks pass with the same loaded-image and packed-ELF SHA-256 hashes
recorded above. Full-image identity includes unrecovered retail spans; credited
C progress remains 43.0850%.


Rewritten-main refresh: started from 86d737e5 (49.1664%), preserving the old
branch and private probes. Every old symbol address and match record was
unchanged by the incoming waves. Independently recompiled all 502 added or
modified C units relative to the preceding Codex checkpoint; all 722 full-function
comparisons passed. Previously verified unchanged objects were retained.

Added two independently verified complete C functions: 0x001A14D0 (400 bytes),
an owner-state update with timed transitions, and 0x002A4290 (400 bytes), an
animation-driven velocity/displacement update. The first uses MWCC3.0.3 O3/G0;
the second uses MWCC3.0.3 O3/Op/G0. Their normal build recipes and address aliases
are registered. No data credit is added for the second routine's existing table.
Catalog: 1,620,192 code bytes (49.1907%), 15,406 credited functions, and
153,965 reconstructed data bytes (23.7577%). The unrelated 0x00194170 dispatch
inventory span is left untouched because it contains multiple entry bodies;
0x0018CEA0 / 0x0018D030 probes remain private and uncredited.

All 42 tests, catalog/report generation, and the combined hybrid/packed-retail
ELF checks pass. Loaded-image SHA-256:
c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f;
packed-ELF SHA-256:
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
README now separates the previous 43% checkpoint from current progress and
correctly instructs cloud workers to supply their own input archive.


The next post-wave-19 checkpoint adds eleven complete functions / 3,900 C bytes
since 33eb07e6: 001A27A0 (328), 002A4D30 (536), 00196120 (308), 001A09B0 (368),
001A5420 (368), 002140C0 (308), 0023AAD0 (324), 00287220 (324), 0027B340 (324),
001B03B0 (348), and 0038EAC0 (364). Root independently recompiled every changed
object in full. Registered profiles use MWCCPS2 3.0.3 or 3.0-011126 with the
verified per-unit flags.

Genuine helper context replaces fabricated clobber assumptions. The verified
84-byte 00195630 acceleration update now shares one TU with 001956E0, 00197070
and new 00196120. Correct explicit arguments remain exact because the compiler
can see the real helper's register preservation. Its two-actor interface follows
the retail caller; the owner parameter is unused by the helper. Definitions and
callers were moved, with every affected original object reverified. The genuine
76-byte 00213FD0 also moved into w191_m, replacing an invented 8-byte local body;
existing 00214200 and new 002140C0 remain exact. Other same-named local helpers
in w9m2c and w1710_d were checked: those implementations and their caller objects
are genuine and exact. Known animation contracts and two-player prefix arrays
were corrected in the changed TUs without changing their compiled bytes.

Two raw tables now have bounded floating-point reconstructions. 004585C0
(48 bytes) holds three rows of X velocity/acceleration and Y velocity/acceleration
read by 002A4290. 00458610 (16 bytes) holds two X/Y animation-frame corrections
read by 002A4D30. Both typed consumers and data objects remain exact, including
negative zero. Legacy symbol names stay stable. This adds 64 data bytes.

The two 48-byte compiler-generated switch tables in w192_r were independently
relocated and checked against retail at 004B7410 and 004B7470, establishing the
case mappings as well as the instruction bytes. They earn no data credit yet:
the containing raw 192-byte unit still owns four tables.

Catalog: 1,624,092 / 3,293,696 C bytes (49.3091%), 15,417 credited functions;
154,029 / 648,064 reconstructed data bytes (23.7676%). All 42 tests and complete
hybrid/packed-image checks pass with the retail SHA-256 hashes recorded above.
The next scheduled full-point gate remains 1,652,329 code bytes. This smaller
checkpoint also publishes the genuine helper context for parallel work.


### Compiler-owned switch tables and six further C recoveries — October 18

Added six full C functions / 2,156 bytes since the 49.3091% checkpoint:
0036FB20 (324), 00278850 (416), 0027B1A0 (416), 00346180 (320),
003F90B8 (372), and 002742B0 (308). All affected source objects were
independently recompiled with their registered profiles and checked in full.
The existing 0040D738 compiler-constraint placeholder stays uncredited.

Four complete 48-byte compiler-generated switch tables now replace the raw
192-byte unit at 004B73E0. Their C owners are 00278850, 002789F0, 0027B1A0,
and 0027B340 in w192_r.c. The normal data build verifies the already-compiled
code object, including R_MIPS_32 relocations to each owner's case labels.
Hybrid generation selects each symbol's complete section by index and resolves
its compiler-emitted bytes; it never copies target data for these tables.
The obsolete raw pointer-literal source was deleted. Nine tests cover duplicate
section names, relocation and size failures, and missing C/build ownership.

Catalog: 1,626,248 / 3,293,696 C bytes (49.3746%), 15,423 credited functions;
154,221 / 648,064 reconstructed data bytes (23.7972%). All 51 tests pass.
The complete hybrid and packed executable match the retail SHA-256 hashes
recorded above. Unrecovered spans still use retail bytes in the hybrid build.
The next scheduled full-point gate remains 1,652,329 code bytes; this smaller
checkpoint publishes the reusable compiler-table build path for other workers.


### Further actor-state C recovery — October 18

Seven additional complete C spans / 1,548 bytes match under their existing
registered profiles: 001F30A0 (312), 0028B0B0 (300), 001A2A40 (256),
001F4D20 (252), residual_001F69C0 (196), residual_001DB920 (108), and
residual_001F8CF0 (124). The three residual catalog boundaries are unchanged;
the C covers each entire recorded span, including its return sequence.
Every credited function in all seven affected source units was recompiled and
verified. The last motion constructor uses ordinary stores with no volatile
constraints. The existing 001DBA70 caller now explicitly passes its task to
00174240; the corrected caller and all its unit companions remain exact.

Catalog: 1,627,796 / 3,293,696 C bytes (49.4216%), 15,430 credited spans;
154,221 / 648,064 reconstructed data bytes (23.7972%). All 51 tests and the
complete hybrid/packed-image checks pass, with the same retail hashes above.
No near-match probes receive credit. The remaining source recovery is ongoing.


### Gameplay recovery, real helper contracts, and framed SDK calls — October 18

Added 39 complete C spans / 8,220 bytes since the 49.4216% checkpoint:
25 gameplay and residual spans plus 003F9230/404 B, 003F93C8/412 B,
00271820/268 B, 0020BDF0/344 B, 00182AA0/300 B, 002ECA50/220 B, and
eight formerly constrained runtime wrappers / 804 B. Every residual retains
its existing full boundary. Every changed source unit was independently
recompiled and checked in full.

Five gameplay models no longer use volatile self-reads (w180_v, w1812_d,
y1_j, y0_l, z2_b). The 0033F470 model now uses a void state switch instead
of an uninitialized return; its full 240-byte function and new 0033F630 variant
match. The 003A7B20 and 003B2E90 allocation helpers now return their allocated
entry, matching the callers that inspect it. All 21 functions in their unit
remain exact. The 0015B8B0 model now takes and forwards the actual second
argument to 0015BA00; both the 328-byte caller and real 52-byte helper match.
0015BD40 remains uncredited with a two-word instruction-order mismatch.

EE GCC 2.96's `-fno-optimize-sibling-calls` reproduces eight normal runtime
call frames from ordinary C. The new shared unit and registered recipe remove
the old assembly barriers; see the compiler documentation for the exact
profile and reproduction command. Nineteen barrier-dependent placeholders
remain. 0040D738 has a new exact compiler probe but stays uncredited pending
helper-contract review. The discarded-read 00407BC0 candidate also stays a
placeholder. No probe, instruction substitution, or partial function receives
matching credit.

Catalog: 1,636,016 / 3,293,696 C bytes (49.6711%), 15,469 credited spans;
154,221 / 648,064 reconstructed data bytes (23.7972%). All 51 tests and the
complete hybrid/packed-image checks pass with the retail hashes above.
The next scheduled full-point gate remains 1,652,329 code bytes. This smaller
checkpoint makes the compiler profile and source-contract corrections public.


### Typed runtime-object storage and twenty complete C recoveries — October 18

Added twenty complete C spans / 3,188 bytes since bbd8bac4: nine gameplay
functions / 1,980 bytes and eleven SDK functions / 1,208 bytes. The gameplay
batch includes 00241430, 00238A10, 002D00D0, 00254480, 00210F40, 00218910,
0023A940, 00233C90, and 0023F6E0. The SDK batch includes 0040D738, 00405170,
00400148, 004001A8, and the seven routines in runtime_framed_calls_003f.c.
Every changed source unit was independently recompiled with its registered
profile and verified in full.

The 00400148/004001A8 catalog repairs merge adjacent uncredited fragments
into the actual 96/172-byte functions. Both returns and all bytes remain in
the comparison. Direct calls target the real starts; the old interior labels
have no direct-call or initialized-pointer entries. The function catalog's
byte total and fixed code denominator are unchanged; its entry count falls
by two. The existing 00400258 allocator and the bounded 00400AF8 pool processor
also match with the shared RuntimeObjectStorage layout.

The data recovery is a typed array of forty 64-byte runtime objects, initially
inactive. Its size and stride are independently established by the 0xA00-byte
clear, the forty-slot processor, and both partition allocators. The complete
2,560-byte C initializer matches retail. The surrounding 31,172-byte and
7,712-byte raw ranges retain placeholder status. Corrupting the first active
flag makes the private data verifier fail. This adds 2,560 reconstructed data
bytes without changing the data denominator.

The q1d template's two embedded command helpers incorrectly cleared one byte
at 1C0. They now use the genuine halfword-clearing implementation from
pending_commands.c. Both 72-byte helpers, the real 92-byte motion helper, and
all four 92-byte callers match in full. Existing caller credit is unchanged.
The additional framed-call recovery removes eight more empty barriers;
ten empty-barrier placeholders remain. The 140-versus-148-byte
record-search probes stay uncredited.

Catalog: 1,639,204 / 3,293,696 C bytes (49.7679%), 15,489 credited spans;
156,781 / 648,064 reconstructed data bytes (24.1922%). All 51 tests, static
build coverage, and full hybrid/packed-image checks pass with the retail hashes
above. The next scheduled full-point gate remains 1,652,329 code bytes.


### Runtime processor, record searches, and bounded record arrays — October 18

Since 8994dcd1, nine complete functions add 2,116 verified C bytes:
00411720 (160), 00407298 (88), 0040D398/0040D300/0040D268 (148 each),
0040CB30 (96), 00271410 (528), 004007A0 (64), and 004007F0 (736).
The three record searches preserve the original bounded loop and its
post-loop success/failure split. They no longer need empty assembly barriers.
The callback registration and dispatcher also use real callback types and
normal source control flow. Five empty-barrier placeholders remain.

The sector setter uses EE GCC 2.96 -O2 -G0 -fno-schedule-insns. The complete
stream processor uses the ordinary -O2 -G8 profile; its completion, retry,
request, transfer-size limits, callback, and error paths all match retail.
Reviewing its helper exposed two missing forwarded arguments in the old
00406960 declaration. The corrected helper passes count and buffer to the
native callback; all three functions in sdk4d.c still match exactly.

The record-table data contributes sixteen fully typed 0x400-byte arrays,
16,384 additional reconstructed bytes. Its shared layout and consumer/bounds
evidence are documented in DATA_INTEGRATION.md. Every unknown outer prefix
retains placeholder status. All 33 replacement data objects and all affected
code units were independently compiled and compared over their complete spans;
a changed first record key is rejected by the private data verifier.

Catalog: 1,641,320 / 3,293,696 C bytes (49.8322%), 15,498 credited spans;
173,165 / 648,064 reconstructed data bytes (26.7204%). The next scheduled
full-point gate remains 1,652,329 code bytes. This smaller checkpoint publishes
the shared layouts and verified compiler recipes for other workers.

All 51 tests and build-coverage validation pass. The combined hybrid link
matches all 3,941,760 retail bytes, and the packed 3,942,320-byte retail ELF
also matches exactly. Their SHA-256 values remain c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f and
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
Unrecovered ranges still come from the private retail input.


### Whole callbacks, verified local candidates, and bounded animation data — October 18

Since c4149b12, 21 additional whole functions contribute 3,672 C bytes.
These include the 003FF810 stream query, three-way motion setups, a separately
referenced 0041A730 motion callback, Sony RPC command/compatibility routines,
the 003F3AE0 matrix transform, and runtime validation/seek callbacks.
Eleven of the recoveries came from existing local Grok candidates: all were
independently compiled and compared in full before integration, including the
already written 00165720 collision routine. The original working tree and its
uncommitted files were preserved.

The shared source audit withdrew 196 bytes for 0040A378. Its old calls omitted
object arguments required by the real helpers. Explicit, properly typed
arguments still produce different instructions, so it and its 0040BDC8
candidate remain uncredited. The net code gain is 3,476 bytes. Affected code
units were checked in full, including their existing credited functions.

Three source-contract repairs preserve existing exact spans without adding
credit: 003F7FC8 explicitly returns the native zero recognition result;
0040D040 passes the real resource pointer to 00400740; and 0011F938 returns
the actual formatting helper's result. The imported 001C6D00 candidate now
uses the animation helper's real one-argument signature. The 002A2800 source
retains the retail facing test whose two branches assign the same acceleration;
removing that redundant native branch would break the whole-function match.

The data recovery adds 756 bytes: thirteen Sony handler pointers (52),
32 bounded animation samples (256), and 56 fully reachable animation commands
(448). DATA_INTEGRATION.md records their field, extent, and traversal proof.
The unused handler words and the unproven half of the sample area remain
placeholders.

Catalog: 1,644,796 / 3,293,696 matching C bytes (49.9377%), 15,518 credited spans;
173,921 / 648,064 reconstructed data bytes (26.8370%). The next scheduled
full-point gate remains 1,652,329 C bytes.

All 51 tests and build-coverage validation pass. The combined hybrid relink
reproduces the 3,941,760-byte retail image, and the packed 3,942,320-byte ELF
also matches exactly. SHA-256 remains c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f for the image
and 48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7 for the ELF.
This smaller checkpoint publishes the source-contract corrections and the
previously unpublished, independently verified C recoveries. Unrecovered
ranges still use the private retail input; full source decompilation remains
incomplete.


### Full-point milestone: independent callback recovery — October 18

Recovered 59 complete C functions / 8,208 bytes since 758aa75b, bringing the
catalog to 1,653,004 / 3,293,696 matching C bytes (50.1869%), with 15,577
credited spans. Reconstructed initialized data remains 173,921 / 648,064 bytes
(26.8370%). This crosses the scheduled 1,652,329-byte full-point gate; the next
scheduled gate is 1,685,266 bytes (51.1664%).

Fifty-eight recoveries were mislabeled residual spans, although actual callback
tables enter them directly after a completed dispatcher. Each recovered body
has a complete native return or tail exit and independently matches its entire
compiler-generated function. INDEPENDENT_CALLBACK_ENTRIES.csv records each
pointer witness, preceding dispatcher, and source owner. The preceding dispatcher
is the physical neighbor, not necessarily the consumer of the recorded table.
Native register arguments are preserved even where an older callback-table type
still models fewer parameters. No inventory address, size, end, overall function
count, or denominator changed; entries already credited under residual names
were excluded from new progress.

The other recovery is the 416-byte runtime slot cleanup at 00401428, including
its optional callbacks, nested callback tables, and resource cleanup. Its full
11-function source unit was independently recompiled after integrating its
required verifier anchors. Every other changed source unit was also compiled
with its registered compiler and checked over complete spans. The working tree
containing earlier local candidates was only read; its uncommitted work remains
untouched.

All 51 tests and build-coverage validation pass. The combined hybrid image is
byte-identical to the 3,941,760-byte retail input, and the packed 3,942,320-byte
ELF also matches exactly. Their SHA-256 values remain
c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f and
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7. Unrecovered
ranges still use private retail input; complete source decompilation is ongoing.

### Newlib stream setup recovery — October 19

Recovered `func_00122560` (268 bytes) as the Newlib 1.10.0 `__swsetup` routine.
Its existing `FILE`/`Reent` ABI types and buffer helpers reproduce the complete
retail span with EE GCC 2.96 `-O2 -G0`; no data credit was added. The catalog
now contains 1,689,392 / 3,293,696 matching C bytes (51.2917%). All 51 local
tests and progress-catalog validation pass.

Recovered `func_00122260` (220 bytes), the Newlib `vfprintf.c` exponent helper.
Its 308-byte scratch bound is the original `MAXEXP` from `floatio.h`; the 2000
Newlib ChangeLog records the later reduction to a smaller exponent buffer. The
EE GCC 2.96 `-O2 -G0` object verifies exactly. Catalog code now stands at
1,689,612 / 3,293,696 bytes (51.2984%).

Recovered `func_001220A0` (448 bytes), the Newlib `vfprintf.c` `cvt()` helper.
It calls the already matched dtoa implementation and preserves the source-era
soft-float conversions. EE GCC 2.96 `-O2 -G0` verifies the full body; catalog
code now stands at 1,690,060 / 3,293,696 bytes (51.3120%).

The existing `func_001208B8` (`__sprint`) now uses the verified `FILE *`
and 12-byte `__suio` request types, and explicitly forwards both arguments
to `func_0011C458` (`__sfvwrite`). The original argument-omitting declaration
is removed. Its EE GCC 2.96 O2/G0 object remains byte-exact at 72 bytes;
this improves the recovered ABI without increasing matching-byte credit.

### Combined Grok and independent recovery checkpoint — October 19

Matching and hybrid-linked C now covers 1,898,764 / 3,293,696 bytes
(57.6484%), across 16,801 credited function spans. This adds 140 functions /
36,192 bytes since main's 56.5496% checkpoint. Reconstructed initialized data
is 174,409 / 648,064 bytes (26.9123%); two bounded four-byte objects add eight
bytes of data credit. Raw fallback ranges continue to earn no source credit.

A read-only snapshot of newer Grok work supplied 92 independently replayed
functions / 26,152 bytes. Their per-source compilers, flags, and source audits
are recorded in [the replay manifest](grok-new-primary-20261019-replay.csv).
Thirty-five use MWCCPS2 3.0-011126 with genuine `#pragma padloop on`; the
compiler emits the native loop padding without inline NOPs or opcode patching.
Other recoveries include callback bodies and dispatch heads, with native
entry references and disjoint whole-function boundaries. The integration
preserves uncredited prefixes and alignment gaps.

Source audits corrected helper argument/return types, callback signatures,
open pointer views, and local vector extents. Two local vectors contain only
x/y and retain their native 16-byte alignment. Another native Vec3 call leaves
z uninitialized; its recovered source documents and preserves that behavior.
No opaque extra elements were added just to shape the stack frame.

All 135 changed code translation units were independently compiled and
verified against the private retail input; every subsequent audit correction
was replayed again. All eight changed data units were recompiled and verified.
The 53 tests, progress-catalog validation, shell syntax, and build coverage
(3,827 credited source units, no unregistered bodies) pass. Full linkage and
packing reproduce the retail loaded image and ELF:

- Loaded image: 3,941,760 bytes, SHA-256
  `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
- Packed ELF: 3,942,320 bytes, SHA-256
  `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.

This crosses the scheduled 1,882,888-byte checkpoint. The next scheduled
checkpoint is 1,915,825 code bytes (58.1664%). Complete source decompilation
remains unfinished; exact hybrid reconstruction still uses private retail
bytes for unrecovered regions.

### Build-verification repair and combined recovery — October 19

Code is now 1,907,432 / 3,293,696 bytes (57.9116%), adding 37 complete
functions / 8,668 bytes since the previous public checkpoint. Reconstructed
initialized data is 175,425 / 648,064 bytes (27.0691%), adding 1,016 bytes of
bounded offset, motion, and selector records. The per-function recipes and
native entry witnesses are in `window-clone-frontier-20261019-replay.csv` and
`grok-asm-source-candidates-20261019-replay.csv`. Leading alignment words remain
uncredited; input-gate return types preserve the selected-target pointers.

The compile script had a verification stanza with its command head missing:
the shell attempted to execute `grok_w5_001d2390.o` instead of verifying it.
The command head is restored, and the coverage checker now rejects detached
object-verification arguments as well as detached compiler arguments. Regression
tests cover quoted/unquoted failures and valid multiline continuations. The
272-byte affected function was recompiled with its production recipe and
verified exactly. The entire compiler script has not been rerun end to end for
this repair; all changed source units and data objects were replayed separately.

All 55 tests, catalog validation, 3,860-source build coverage, and shell syntax
checks pass. Hybrid linkage and ELF packing again reproduce the retail SHA-256
values recorded above. This publication repairs the build before the next
scheduled code checkpoint; that checkpoint remains 1,915,825 bytes (58.1664%),
8,393 bytes beyond this revision. Exact source decompilation remains incomplete.

### Window recovery checkpoint — October 19

The next local checkpoint adds 28 compiler-verified functions / 3,468 code
bytes and a bounded 32-byte state lookup. Linked matching code is
1,910,900 / 3,293,696 bytes (58.0169%); reconstructed initialized data is
175,457 / 648,064 bytes (27.0740%). The trajectory function at 0x001A9650
now has actual C in place of its uncredited opcode placeholder. All affected
source units were recompiled and verified with their production recipes.

All 55 tests, catalog validation, 3,862-source build coverage, and shell syntax
checks pass. Hybrid linkage and ELF packing reproduce the retail hashes above.
A separate fresh build of the published build repair is still running; these
results do not establish completion of that full compile-script replay.
The next scheduled publication remains 1,915,825 code bytes (58.1664%),
4,925 bytes beyond this local checkpoint. Complete source recovery is unfinished.

### Dispatch recovery and clean-build ordering — October 19

Linked matching code reaches 1,916,016 / 3,293,696 bytes (58.1722%). This
adds 148 complete functions / 5,116 bytes to the previous local checkpoint;
the combined gain since the previous public checkpoint is 176 functions /
8,584 bytes. Reconstructed initialized data reaches 175,473 / 648,064 bytes
(27.0765%), including the 16-byte signed correction lookup bounded by its
consumer's `& 0xF`. Whole production source units were recompiled, including
all previously credited members. Each new function includes its native ending
and has an independent pointer, direct-call, or tail-jump entry witness.

An independent ABI review identified a return-value/context contract at
0x00163F70. Its definition now explicitly forwards the context argument and
integer callback result required by the caller at 0x00169BC0. Newly referenced
callback arrays have unspecified extents; actual GP addressing uses the
small-data section rather than guessed array lengths.

The build from an empty object directory exposed another ordering defect:
the data verifier ran before `src/w192_r.c`, its switch-table owner, was
compiled. Data compilation/verification now runs after all code compilation.
The coverage gate rejects premature data calls, with regression cases for
both direct compilation and the existing `for unit` loops. The corrected
fresh build is running; completion of that entire script remains unproven.

All 56 tests, catalog validation, source coverage, and shell syntax checks
pass. Hybrid linkage and ELF packing reproduce the retail hashes recorded
above. This checkpoint crosses the scheduled 1,915,825-byte threshold;
the next scheduled checkpoint is 1,948,762 code bytes (59.1664%). Complete
source decompilation remains unfinished.

### Native routines, interface recovery, and compiler-argument repair — October 19

Linked matching code is 1,917,468 / 3,293,696 bytes (58.2163%), adding six
complete functions / 1,452 bytes. These include phase-based height adjustment,
owner-relative landing, owner-effect setup, slot-list restoration, move setup,
and a perspective matrix. Production compiler verification covers every full
new symbol and all existing members of modified source units. Native callers
also establish the owner-context and floating-point argument/return interfaces;
the affected call sites, callback entry, and trig thunks now express them.

Reconstructed initialized data is 175,721 / 648,064 bytes (27.1148%), adding
248 bytes of bounded motion/state lookups and 12 UI format literals. Literal
credit stops at each terminating NUL. Padding and unrelated bytes remain
placeholders. Shared string/raw translation units initially passed individual
object checks but failed whole-image placement. Giving each catalog unit its
own source object restored exact linkage without changing credited extents.

The fresh build exposed a malformed `jump_motion_002357f0.c` command: a
backslash escaped a space before `-o`, introducing a whitespace-only filename.
The continuation is fixed. The checker parses compiler argument fragments and
rejects whitespace-only arguments while accepting escaped spaces inside real
filenames. The affected 520-byte source unit verifies with its actual recipe.
The initially empty build's verified prefix is retained, and the corrected
suffix has now completed code compilation and entered the final data stage.
The entire compiler-script run is still in progress; terminal success is not
claimed.

All 57 tests, catalog validation, 3,867-source coverage, shell syntax, and diff
checks pass. Final hybrid linkage and ELF packing reproduce the retail hashes
recorded above, including the interface corrections and per-unit data layout.
This publication delivers the compiler-command repair before the next normal
code threshold. That threshold remains 1,948,762 bytes (59.1664%), 31,294 bytes
beyond this revision. Complete source decompilation remains unfinished.


## Core state handlers and parallel data verification (2026-10-19)

This checkpoint adds 18 exact C functions (2,580 bytes): native actor/state
initializers, random-pair motion, owner-aware setup, and six core state handlers.
Each complete symbol was compiler/relocation-verified, then all replacements
were linked into the byte-identical loaded ROM and packed retail ELF.
Native table slots and incoming contexts were independently checked. Known
callback declarations now preserve the event/owner arguments, including the
owner-aware interior table at 0x0045E1A0. That interior table shares storage
with a unary dispatch table whose visible constructors select only slots 0–7;
its owner callback at slot 32 is not evidence of a valid unary owner call.

Linked matching code is 1,920,048 / 3,293,696 bytes (58.2946%). Reconstructed
linked data remains 175,721 / 648,064 bytes (27.1148%). This is partial source
recovery; unchanged retail bytes still supply the unmatched image regions.

`tools/compile_matching_data.sh` now defaults to four independent workers.
After setting the documented private toolchain variables, use
`DATA_JOBS=1 make hybrid` for serial data compilation. Compiler flags and
verification recipes are unchanged. Worker failures cancel queued jobs, join
active jobs, and fail the build. Output names retain the relinker's source-path
convention, and colliding output paths fail before compilation.

The actual parallel script verified all 8,085 standalone data units and four
compiler-owned switch tables in 457.837 seconds. A real invalid-C control
failed in 0.303 seconds and canceled 59 queued jobs. The 76 units whose symbol
names differ from source filenames were rechecked after the filename fix;
all objects matched the paths required by the linker. An earlier 40-unit
comparison measured a 3.22x speedup over serial data compilation.

The next normal code checkpoint remains 1,948,762 bytes (59.1664%), another
28,714 bytes beyond this revision. This additional tooling publication does
not reset that grid.


## Resource binding and float conversion (2026-10-19)

Four additional functions contribute 820 bytes of exact C: resource-relative
section binding at 0016F1B0, two resource passes at 0016FD80, a context dispatcher
at 002F7540, and double-to-float conversion at 00119C90. Whole modified translation
units compile and verify exactly. The conversion uses EE GCC 2.96 with its normal
float-return ABI: native caller 001AD4F8 passes the double bits in A0 and consumes
F0 at 001AD500. Its existing pack wrapper now explicitly returns float, matching
the pack helper and callers. Instruction equality alone would not establish that
source interface. Resource binding resolves 14 offsets; header word +4 and the
individual meanings of copied resource-record fields remain unclassified.

Four bounded lookup objects contribute another 72 reconstructed data bytes.
The random state tables at 004537A0 and 004577A0 each hold 16 two-byte records;
masked native lookups establish the domains, and separately referenced dispatch
tables establish their endpoints. The four-entry maps at 004BF480 and 004C0080
have independent masked consumers and endpoint references. Unclassified prefixes,
suffixes, and the four-byte gap at 004C0084 remain uncredited placeholders.

The verified totals are 1,920,868 / 3,293,696 code bytes (58.3195%) and
175,793 / 648,064 reconstructed data bytes (27.1259%). Final linkage and ELF
packing reproduce the retail hashes recorded above. The next normal publication
threshold remains 1,948,762 code bytes (59.1664%), another 27,894 bytes beyond this
batch. Full source recovery remains unfinished.


## Event setup, owner dispatch, and command profiles (2026-10-19)

Four further functions add 360 bytes of exact C: the indexed event constructor
00137B00, the signed-selector dispatcher 002C17C0, and owner dispatchers 003AB400
and 003AB430. The constructor uses MWCC with `-fp off` for its float constant stores; its direct caller supplies byte arguments.
The 28-byte 002C17C0 body excludes its trailing NOP. Two callers set its selector
to 0 or 1, proving the complete eight-byte callback table at 004C0DE8. Both callback
targets already have exact unary source. The const table and its consumer now
agree on pointer types and explicit GP-relative placement.

Thirteen structured data objects add 90 bytes: that callback table, two four-entry
symbolic command-profile pointer tables, eight bounded command streams, and two
masked byte lookups. The profile names resolve to actual byte arrays through
R_MIPS_32 relocations. Native 00280AE0 establishes opcode/operand semantics and
reset behavior; the shared header names the recovered commands. Opcodes 1 and 2
consume one operand and return, while some other commands continue parsing within
the same call. Unclassified alignment bytes and remaining pointer words retain
placeholder status. The larger parser is not credited: a private C++ candidate
is still two instructions away from exact, despite matching its generated table.

The verified totals are 1,921,228 / 3,293,696 code bytes (58.3305%) and
175,883 / 648,064 reconstructed data bytes (27.1398%). All 57 tests, catalog and
build-coverage checks pass. Final loaded ROM and packed retail ELF hashes match
the references above. The next normal push remains 1,948,762 code bytes
(59.1664%), another 27,534 bytes beyond this batch; full source recovery remains
unfinished.

## 2026-10-21 — Complete thread stacks and animation map bank

Nine complete actor/state/motion functions add 3,976 verified C bytes. Actual
parent/context contracts and signed owner-state fields close the inherited-state
and callback dispatch routines; the position-cycle reader uses the real BE40
dispatch base and indices 0–4 of the existing six-pair float owner. The related
ABI repairs preserve all 783 existing functions in eight compilation units,
including whole-object byte identity. Unmatched candidates remain uncredited.

Five CreateThread stack buffers recover all 28,672 bytes at
`0x0047D100..0x00484100`; their explicit runtime stack lengths establish the
capacities. The four-byte preceding prefix remains opaque. The complete
59-by-64-byte animation remap bank plus its 59 symbolic pointer directory adds
4,012 reconstructed bytes. This replaces 78 fragmented placeholder bank units,
includes the pending 64-byte map once, and leaves the unproven directory zero
word and external alignment gap uncredited. Net new DATA is 32,684 bytes.

All 118 tests, build coverage, catalog validation, and a fresh split pass. All
new/changed objects verify exactly; 14,889 unchanged source/object pairs and
52 headers retain their prior hashes. The full linked ROM and packed ELF match
retail byte-for-byte. After status promotion, all 17 catalog tests pass and the
progress graphic/report are regenerated. Pinned, tested DVP tool setup is now
documented separately; the VU roundtrip and partial authored VCL prototype earn
no matching credit.

Verified totals are **2,090,344 / 3,293,696 code bytes (63.4650%)** and
**296,923 / 648,064 reconstructed data bytes (45.8169%)**. This DATA publication
does not reset the fixed CODE grid: the next checkpoint remains 2,113,447 bytes,
23,103 beyond this batch. Full source decompilation remains incomplete.

## 2026-10-21 — Scene callbacks and complete memory-card icon

Fourteen complete functions add 5,024 verified C bytes. The batch closes actual
scene lifecycle, position, signed animation cycle, colour, resource-stream,
owner signalling and lifetime callbacks, plus three real inherited-state/timer
entries. Two callable inventory splits preserve the conservative text span;
adjacent alignment and remaining near matches stay uncredited. Eighteen old
compilation units receive coherent type/signature declarations while retaining
whole-object byte identity.

Scene/effect tables add 160 net reconstructed bytes, preserving their one
previously reconstructed byte once. Four actor-table owners add another 82:
a three-float spawn vector, four ten-byte launch records, six float heights and
six signed animation codes. Their 118 opaque adjacent bytes remain placeholders.
The actual float/signed-byte providers unlock the exact 304-byte rise callback.
See `SCENE_TABLES_AND_CALLBACKS_RECOVERY_20261021.md` for native roles, valid-input
contracts and ownership boundaries.

The complete 50,968-byte `mvsc2.ico` owner contains a standard PS2 icon header,
756 typed vertices, a complete animation sequence, and 128-by-128 PSMCT16 texture.
Its native memory-card write path fixes the file length. The file replaces 377
raw placeholder units and covers 1,328 previously unowned internal bytes; none
of those units had reconstructed credit. Net new DATA is 51,210 bytes including
the actor/scene tables. `MEMORY_CARD_ICON_RECOVERY_20261021.md` records the parse,
file selection and standard format references.

All changed/new compilation units verify exactly. The aggregate gate runs all
118 tests, catalog/build coverage, fresh splitting, hybrid linkage and retail
ELF packing. It checks the unchanged hashes of 14,509 source/object pairs and
52 headers; 18 old pairs are recompiled, 28 are new and 385 raw pairs retire,
leaving 14,555 pairs. Full linked ROM and packed ELF retain the retail hashes
listed above. Status promotion is followed by all 17 catalog tests and report
regeneration.

Verified totals are **2,095,368 / 3,293,696 code bytes (63.6175%)** and
**348,133 / 648,064 reconstructed data bytes (53.7189%)**. This DATA checkpoint
does not reset the fixed CODE grid: the next normal checkpoint remains
2,113,447 bytes, another 18,079 bytes. Source recovery remains incomplete.

## 2026-10-21 — CD/DVD read records and further owner callbacks

Four complete callbacks add 1,860 verified C bytes. The animation-velocity
callback uses actual float storage and acceleration fields. The resource-depth
callback receives its real two-word stack context through synchronous dispatch;
the owner/counterpart pulse retains native unordered floating comparisons; and
the phase callback preserves mixed integer/float helper arguments and a real
GP-relative byte lookup. The last lookup remains an unsized extern over an
unrecovered DATA region, with explicit valid phase input and no new DATA credit.

CD/DVD request, completion, position and client records add 212 DATA bytes within
a former 4,476-byte raw zero owner. Four modified existing compilation units
preserve their whole object bytes while using compatible client and completion
types. The existing Sony RPC header is reused unchanged. Its other 4,264 bytes
remain raw placeholders. A separate 32-byte velocity table replaces the middle
of a 196-byte raw owner; its 164 surrounding bytes remain uncredited. Total new
DATA is 244 bytes. See `CDVD_READ_STORAGE_RECOVERY_20261021.md` for owners,
preconditions and source-level type corrections.

The aggregate verification covers all changed/new complete objects, unchanged
hashes for 14,549 prior source/object pairs and 52 headers, all 118 tests, fresh
splitting, hybrid linkage and packed ELF identity. Four old compilation units
are recompiled, 16 pairs are new and two raw pairs retire, leaving 14,569 pairs.
The loaded ROM and packed ELF retain their retail hashes. Post-promotion catalog
checks and report generation retain the raw exclusions.

Verified totals are **2,097,228 / 3,293,696 code bytes (63.6740%)** and
**348,377 / 648,064 reconstructed data bytes (53.7566%)**. The fixed normal CODE
checkpoint remains 2,113,447 bytes, another 16,219 bytes; this source/data recovery
checkpoint does not reset that grid. Full source decompilation remains unfinished.


## 2026-10-21: motion inventories and three actor callbacks

Three whole-function compiler matches add 1,024 CODE bytes; the typed motion
bank adds 4,804 DATA bytes. Its three eight-byte raw regions remain uncredited.
See `MOTION_BANK_RECOVERY_20261021.md` for ownership and array-bound limits.
Three existing compilation units preserve whole object identity; two more
preserve every exported function after relocation while adopting coherent
packed-record symbols. No existing CODE credit is added for these corrections.

Verification pins 14,563 unchanged source/object pairs and all 52 headers,
recompiles five old units and eleven new units, and retires one raw owner,
leaving 14,579 pairs. The aggregate gate runs catalog checks, the existing test
suite, fresh splitting, hybrid linkage and packed-image comparison. Publication
requires the loaded ROM and packed ELF to retain the retail hashes.

The bank's totals are **2,098,252 / 3,293,696 CODE bytes (63.7051%)** and
**353,181 / 648,064 reconstructed DATA bytes (54.4979%)**. The normal fixed CODE
checkpoint remains 2,113,447 bytes, another 15,195 bytes. This additional DATA
checkpoint does not reset the grid. Full source decompilation remains unfinished.

## 2026-10-21: effect spawn groups and motion parameters

Two formerly raw owners now provide 1,044 reconstructed DATA bytes. Six groups
of ten typed spawn points, five integer angles, five rotation pairs and two
acceleration vectors follow native producer and consumer contracts. One vector
crosses the old catalog boundary at 0x00460CB0. Three gaps totaling 28 bytes
remain raw and uncredited. See `EFFECT_SPAWN_DATA_RECOVERY_20261021.md`.

All eight new whole data objects compile exact and have independent review.
The aggregate verification checks 14,577 unchanged source/object pairs and all
52 headers, retires two raw owners and adds eight new units, leaving 14,585
pairs. Publication requires catalog checks, the existing test suite, fresh
splitting, linkage and the same full retail ROM and packed ELF hashes.

Totals are **2,098,252 / 3,293,696 CODE bytes (63.7051%)** and
**354,225 / 648,064 reconstructed DATA bytes (54.6590%)**. The normal fixed
CODE checkpoint remains 2,113,447 bytes, another 15,195 bytes. Full source
decompilation remains unfinished.

## 2026-10-21: five actor callbacks, pose records and velocity profiles

Five complete actor callbacks add 1,604 CODE bytes. Typed relative-pose records
add 1,416 DATA bytes; three phased velocity profiles and their three-pointer
directory add another 2,412. Twelve unresolved bytes remain raw and uncredited.
See `POSE_AND_VELOCITY_DATA_RECOVERY_20261021.md` for the signed-selector and
physical-profile preconditions, native float behavior and excluded tails.

Two existing CUs are recompiled: the constructor now uses its actual profile
pointer type, and the unary cleanup helper has its actual object input. Both
whole objects stay byte-identical; no extra credit is claimed for old functions.
The bank verifies 14,580 unchanged source/object pairs and all 52 headers,
adds ten new pairs and retires three raw owners, leaving 14,592 pairs.
Publication requires the existing 118 tests, catalog checks, fresh splitting,
hybrid linkage and the full retail ROM and packed ELF identity checks.

Totals are **2,099,856 / 3,293,696 CODE bytes (63.7538%)** and
**358,053 / 648,064 reconstructed DATA bytes (55.2496%)**. The normal fixed
CODE checkpoint remains 2,113,447 bytes, another 13,591 bytes. These extra DATA
publications do not reset that grid. Full source decompilation remains unfinished.

## 2026-10-21: action streams, motion rows and callback interface repairs

Seven whole actor callbacks add 2,528 CODE bytes. Two old bodies totaling 460
bytes are withdrawn because their matching sources used an unsupported third
cleanup-helper input; truthful candidates remain uncredited under docs/nonmatching.
Net CODE gain is 2,068 bytes. The native fallback preserves their original spans.

Action records add 2,152 DATA bytes, phase durations add 32, and independently
reviewed motion resources and seven-float rows add 2,795. Total new reconstructed
DATA is 4,979 bytes. Raw gaps and tails remain excluded. See
`ACTION_MOTION_DATA_AND_ABI_REPAIR_20261021.md` for field roles, local resource
preconditions, mixed-use neighboring anchors, and the source interface repairs.

The bank checks 14,558 unchanged source/object pairs and all 52 old headers,
freshly compiles 28 changed old units and 40 new units, and retires six raw
owners, leaving 14,626 pairs. One new shared action header has exactly 37
includers, all freshly compiled. Remaining exports in four changed code objects
are checked against the full registered name/size sets; other changed old code
objects retain whole object identity. Publication requires the project test suite,
catalog checks, fresh splitting, hybrid linkage and both full retail image hashes.

Totals are **2,101,924 / 3,293,696 CODE bytes (63.8166%)** and
**363,032 / 648,064 reconstructed DATA bytes (56.0179%)**. The fixed CODE
checkpoint remains 2,113,447 bytes, another 11,523 bytes. This DATA and
integrity publication does not reset the grid. Full source decompilation remains
unfinished.

## 2026-10-21: clone callbacks and path resources

Four exact callbacks add 3,248 CODE bytes. Native evidence separates an old
uncredited composite dispatcher/callback span into its real 140-byte dispatcher,
four raw bytes and 892-byte callable. The next credited function is unchanged;
the text denominator is unchanged.

Fixed-point motion and attachment poses add 600 DATA bytes, twelve interpolation
paths with their pointer/count directories add 1,500, and three coordinate-pair
banks add 1,440. Total new reconstructed DATA is 3,540 bytes. Raw gaps and opaque
neighbors stay excluded. See `PATH_RESOURCES_AND_CLONE_CALLBACKS_20261021.md`
for fields, actual source interfaces, resource preconditions and native selector
limits. Two existing shared vector types are reused without changing headers.

The bank checks 14,617 untouched source/object pairs and all 53 existing headers,
freshly compiles five changed old DATA units and 36 new units, and retires four
raw owners, leaving 14,658 source/object pairs. All four cleaned CODE objects
retain the frozen worker object hashes. Publication requires catalog checks,
the project test suite, fresh splitting, hybrid linkage and both full retail
image hashes.

Totals are **2,105,172 / 3,293,696 CODE bytes (63.9152%)** and
**366,572 / 648,064 reconstructed DATA bytes (56.5642%)**. The fixed CODE
checkpoint remains 2,113,447 bytes, another 8,275 bytes. This extra DATA
publication does not reset that grid. Complete source decompilation remains
unfinished.

## 2026-10-21: motion tables and context callbacks

Eighteen complete functions add 8,652 CODE bytes. Character motion variants,
scale blocks and their pointer directory, GS address/data commands, and EE TLB,
syscall-hook and semaphore records add 7,312 reconstructed DATA bytes. Opaque
gaps and the copied executable payload remain uncredited. See
`MOTION_TABLES_AND_CONTEXT_CALLBACKS_20261021.md` for layouts, actual callback
and math-helper interfaces, local resource preconditions and exact accounting.

The bank checks 14,614 unchanged source/object pairs and all 53 old headers,
freshly compiles 13 changed old and 35 new source units, and retires 31 raw
providers, leaving 14,662 pairs and 55 headers. Both new headers' six includers
are freshly compiled. Existing code objects retain identity, with one explicit
exception limited to the Sony compiler's generated hexadecimal filename in
non-loaded debug metadata; all other bytes and strict code matches are checked.
Publication requires catalog coverage, all 118 project tests, fresh splitting,
hybrid placement and both full retail image identities.

Totals are **2,113,824 / 3,293,696 CODE bytes (64.1779%)** and
**373,884 / 648,064 reconstructed DATA bytes (57.6925%)**. This crosses the
fixed CODE checkpoint at 2,113,447 bytes. The following fixed checkpoint is
2,146,384 bytes, another 32,560 CODE bytes. Full source decompilation remains
unfinished; identical hybrid images do not establish complete source recovery.

## 2026-10-22: related-actor state predicate

`func_001F7260` adds 120 exact CODE bytes under MWCCPS2 3.0-011126
`-O3,p -sdatathreshold 0`. It checks the actor kind and a byte-sized
state on the related actor, accepting the native individual states and
unsigned inclusive intervals. The full function matches every retail word.
Its stored callback declaration now agrees with the actual `int(actor *)`
interface; this declaration repair adds no DATA credit.

Build coverage, the progress catalog, all 126 tests, and a full hybrid
relink/pack pass. Both reconstructed retail image hashes remain identical.
Verified CODE is 2,660,116 / 3,293,696 bytes; DATA remains
468,869 / 648,064 bytes. Full source recovery is still incomplete.

## 2026-10-22: motion-stop callback in compiler-matched C

`func_00229040` replaces an uncredited assembly placeholder with 92 bytes of
exact C under MWCCPS2 3.0.3 `-O3 -sdatathreshold 0`. The actor view exposes
the native position, velocity, acceleration, and state-six prefix. The
callback definition agrees with the existing typed dispatch table. Its
negated `<= 0.0f` test preserves the native unordered-comparison behavior.
No volatility, assembly, fixed registers, or artificial padding instructions
are used.

Build coverage, catalog validation, all 126 tests, and the full hybrid
relink/pack pass with both retail image hashes unchanged. Verified CODE is
2,660,208 / 3,293,696 bytes; DATA remains 468,869 / 648,064 bytes.

## 2026-10-22: faithful timed-effect callback interfaces

`func_003CD5A0` now uses a typed actor view rather than volatile floating-point
accesses to reproduce the native load order. Its 96-byte body remains exact.
The live `func_003CD100` dispatcher passes `(actor, owner)`, establishing the
shared table protocol and the legitimately ignored owner argument.

`func_003CD310` now has the table's void return type and owner parameter.
Its call to the bounds predicate explicitly passes the actor that the native
callee consumes, and its animation/vector helper declarations agree with
their implementations. The neighboring cleanup callback retains only the
real two-argument protocol. All 648 caller bytes and all 8 cleanup bytes
remain exact; every other registered body in the shared leaves object also
passes fresh verification. No source-credit totals change.

Catalog/build coverage, all 126 tests, and full hybrid relink/pack pass.
Both reconstructed retail image hashes remain unchanged.

## 2026-10-22: projected actor bounds predicate and caller contracts

`func_00174470` adds 312 exact CODE bytes under MWCCPS2 3.0-011126
`-O3,p -sdatathreshold 0`. It projects the actor position into a two-float
stack buffer, computes the native scaled extents and orientation selection,
updates the projected coordinate, and compares the two explicitly narrowed
16-bit conversion results. The intermediate stack write, floating-point
operation order, conversion calls, and final branch sequence all match retail.

The active callers now consistently declare the actual read-only actor-pointer
interface. Seven calls explicitly pass the actor previously left incidental
in a0, four unnecessary context arguments are removed, and the old signed-byte
return declaration agrees with the actual integer predicate result. All 838
registered bodies across the 137 affected old caller units remain exact after
fresh compilation; the new function is separately verified as a whole object.
No unrelated source, uncompiled historical candidates, or DATA units change.

Build wiring, catalog validation, all 126 tests, and full hybrid relink/pack
pass. Both retail image hashes remain unchanged. Verified CODE is
2,660,520 / 3,293,696 bytes; DATA remains 468,869 / 648,064 bytes.

## 2026-10-22: explicit name-entry replacement arguments

The registered `func_00173650` caller now passes the actor and selected signed
index to `func_00173600`, and the actor to the existing randomized-name
helper. Their integer return declarations agree with the native setters.
The caller's 328 bytes remain exact after these inputs become explicit.

The native loop reaches the replacement helper only for selectors 16..19;
its three-byte stride addresses the four triplets already owned by
`gNameEntryReplacements_004B5620`. This establishes the actual resource
precondition. The helper's bounded C candidate remains uncredited because
its address generation still differs; the biased native alias is preserved
and no data-symbol address is changed.

Build coverage, catalog checks, all 126 tests, and full hybrid relink/pack
pass with both retail image hashes unchanged. Matching totals are unchanged.

## 2026-10-22: facing-dependent horizontal exit predicates

Recovered `func_003797D0` (124 bytes) and `func_0037BDE0` (116 bytes)
as ordinary C using the actor's float position at 0x34 and signed facing
field at 0x140. Their respective margins are 146.666656494140625 and 160.
The left-facing test retains the native negated <= comparison, including
its unordered floating-point result. The native callers pass one actor
pointer and consume the integer result. No extra callback arguments or
register constraints are needed.

Both complete bodies match with MWCCPS2 3.0.3 at -O3,p and a zero
small-data threshold. Catalog/build checks, all 126 tests, and full hybrid
relink/packing pass. The retail ELF remains SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
CODE is 2,660,760 / 3,293,696 bytes (80.7834%); DATA remains
468,869 / 648,064 bytes. The fixed next publication grid remains
2,673,376 CODE bytes.

## 2026-10-22: owner-driven fade, input launch and air-action eligibility

Recovered three complete functions (716 bytes):

- `func_00132B00` (208 bytes) updates the effect's signed active byte and
  opacity using its owner's enable byte, signed timer and per-side state.
  The typed views preserve the native reloads and the crossing-below-zero
  fade reset. Its existing caller passes the effect and owner explicitly.
- `func_00178BE0` (288 bytes) chooses one of three four-halfword launch
  presets from input bits 0xC00. Signed direction -1, 0 or 1 gives record
  indices 0..2 within the existing sixteen-halfword data object. Vertical
  and horizontal coefficients, division by 256, and the facing reversal
  preserve the native single-precision operations. The existing dispatch
  table has the same unary actor signature.
- `func_0018A6C0` (220 bytes) rejects disallowed states/actions, an opponent
  flag and ineligible airborne positions before testing the action table.
  Both native floating-point predicates retain their unordered behavior.
  Its existing caller consumes an integer result from one actor pointer.

The fade and launch compile exactly with MWCCPS2 3.0 at -O3,p; the
eligibility helper uses -O4,p with that compiler. Each uses a zero
small-data threshold. No data coverage is added or retyped by this batch.

Catalog/build checks, all 126 tests, and full hybrid relink/packing pass.
The resulting retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
CODE is 2,661,476 / 3,293,696 bytes (80.8052%); DATA remains
468,869 / 648,064 bytes. The next fixed full-percentage checkpoint is
2,673,376 CODE bytes; an interim publication does not reset this grid.

## 2026-10-22: linked-actor detachment and explicit owner dispatch

Recovered `func_001A4A80` (188 bytes) using native parent, position,
velocity, acceleration and state fields. The stopping test is the negation
of a strict floating comparison, preserving the native unordered result.
MWCCPS2 3.0 with -O3,p and a zero small-data threshold reproduces the
whole body.

The live path starts at `func_001A44C0`, which loads the owner from actor
+0x18. Its `func_001A4630` dispatcher now explicitly forwards that owner
through `jtbl_0044B150`. `func_001A4770` derives owner +0x2B8 and passes
actor, owner and workspace through `jtbl_0044B160`. Both table declarations
and the affected C definitions agree with these actual arguments. The
cleanup callback keeps its genuine ignored owner argument and loses two
invented extra arguments. No data credit changes.

All affected old bodies, the new whole function, catalog/build gates,
126 tests and the full hybrid relink/retail-ELF pack pass. ELF SHA-256:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
CODE is 2,661,664 / 3,293,696 bytes (80.8109%); DATA remains
468,869 / 648,064 bytes.

## 2026-10-22: explicit actor input for the shared motion routine

`func_0027FA90` now explicitly passes its actor pointer to
`func_0018F320`, rather than depending on the still-live incoming A0
register while making a zero-argument C call. Its full 284-byte body
remains exact. Nine active translation units now use the same unary
byte-pointer declaration; the typed caller uses an explicit byte view.
The animation helper declaration in the repaired caller also agrees with
its integer return, and its vertical acceleration uses the exact float
value -1.47321426868438720703125 instead of a raw float bit pattern.

Every registered function in the changed objects (45 bodies) passes
whole-function verification. Catalog/build checks, all 126 tests and the
full hybrid relink/packed retail ELF pass. The missing input is repaired
without changing CODE or DATA coverage. `func_0018F320` itself remains
uncredited because its reconstructed body still differs. CODE remains
2,661,664 / 3,293,696 bytes; DATA remains 468,869 / 648,064 bytes.

## 2026-10-22: two-word activation-mask differences

Recovered `func_0013CC50` (396 bytes) as ordinary C with MWCCPS2 3.0.3,
-O3,p and a small-data threshold of 8. The mode byte selects masks from
two pairs of existing global words. Each combined word is XORed with
the record's saved word at 0xD0 or 0xD4. For each differing bit, the native
algorithm ORs that bit into the saved word and invokes the already
verified `func_0013CB50` with its bit index. It deliberately retains this
XOR/OR behavior rather than replacing it with a different edge detector.

The two signed-byte-normalized loops visit exactly word indices 0..1 and
bit indices 0..31. Unsigned shifts preserve bit 31 without signed-shift
overflow; the callback receives indices 0..63. The input-word declarations
retain their unsigned type, with explicit signed read views as consumed
by the native expressions. No static calls or pointer references to this
retained function were found in the pinned retail image; the unary input
contract follows its live A0 accesses and complete native body.

The complete compiled body matches after relocation. Catalog/build checks,
all 126 tests and the full hybrid relink/retail-ELF packing pass. CODE is
2,662,060 / 3,293,696 bytes (80.8229%), 18,718 matched functions. DATA
remains 468,869 / 648,064 bytes. The retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The fixed next full-percentage checkpoint remains 2,673,376 CODE bytes.

## 2026-10-22: owner-relative positioning and mixed callback-table contracts

Recovered `func_001BD7D0` (348 bytes) with MWCCPS2 3.0.3 at -O3,p and
a zero small-data threshold. It advances/clears the effect when the owner
leaves state 0x1D/3 or the animation helper returns a negative signed-byte
result; otherwise it follows signed record offsets relative to the owner.
The facing value is captured before copying it into the effect, exactly
as native code does. The real `func_00175670` integer return is explicitly
narrowed before testing.

The adjacent arrays share three existing DATA owners, so their C models
now preserve the actual native boundaries and relevant callback contracts:

- 0044C1B0: four unary lifecycle entries, followed at 0044C1C0 by 22
  owner callbacks. The existing `func_001BC960` already loads the owner from effect
  +0x18; the unary entry dispatcher remains unary.
- 0044C270: four unary setup entries, followed at 0044C280 by three
  owner callbacks. The setup wrapper accepts the common ignored owner;
  the owner wrapper explicitly forwards it.
- 004BF960: existing groups surround three two-entry owner tables at
  004BF990/004BF998/004BF9A0. Their wrappers forward the owner. The GP
  code view preserves native addressing while the full owner stays in
  its original .data section.

Public owner callback definitions and declarations agree, including the
previously typed actor/owner views. The lifecycle cleanup loses its three
fabricated unused arguments. A callback storage declaration now records
the actual unary target type. All 2,672 previously credited bodies in the
affected translation units remain byte-exact, alongside the new whole
function. Each complete DATA owner remains exactly 104, 28 or 120 bytes;
these interface corrections add no DATA coverage.

The only initialized pointers to `func_001BD7D0` are the four owner-table
entries selected by mode values 10..13; there are no direct calls in the
retail text. The animation helper does not modify the mode byte. These
native edges select rows 10..13 of the existing 34-record, six-byte table
at 0044C0E0.

Catalog/build checks, all 126 tests and full hybrid relink/packing pass.
CODE is 2,662,408 / 3,293,696 bytes (80.8334%), 18,719 matched functions.
DATA remains 468,869 / 648,064 bytes. The packed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,673,376 CODE bytes.

## 2026-10-22: three callbacks recovered from residual spans

Recovered 572 bytes in three complete functions with MWCCPS2 3.0.3,
-O3,p and a zero small-data threshold:

- `func_001BC990` (296 bytes) checks the owner's action/animation state,
  copies facing and follows the signed position record before initializing
  its animation. Its only native dispatch selector is mode 0.
- `func_001BDA80` (240 bytes) initializes its phase and opacity, follows an
  owner-relative coordinate pair, then tail-calls the existing animation
  completion handler with the genuine owner argument.
- `func_001BDDB0` (36 bytes) copies the owner's parent ground height, sets
  vertical scale to 1.5 and tail-calls its existing completion handler.

Each entry was already named by a native callback table but hidden inside
an inventory assembly residual following a matched dispatcher. The
inventory now records the actual entries and complete extents. Their 20
preceding alignment bytes move to the gap catalog and remain uncredited.
The clean split succeeds and the conservative CODE denominator is unchanged.

The code views now bound the state records to 22 six-byte entries and the
coordinate view at 0044C170 to fourteen signed pairs. The latter selector
is zero in freshly cleared objects or comes from the native mode/variant
pairs at 0044C350. The parent producer explicitly creates modes 0..25;
nonzero child modes 15/20 select coordinate indices 0..13. The separate
custom constructor is called with modes 1/7/8 and does not enter this
coordinate path. The larger existing DATA owner's single-record-array
spelling still needs layout refinement; this CODE batch changes no DATA
ownership or credit.

`func_001BC660` and `func_001BC720` now explicitly return their allocated
object pointer or null, matching the callers that use those results.
Their declarations are consistent across active callers; the custom
constructor retains its genuine byte-sized mode parameter.
`func_001BC6C0` keeps its void return and consistent input declarations.
All 127 previously credited bodies in the affected files remain exact.

Clean splitting, catalog/build checks, all 126 tests and full hybrid
relink/packing pass. CODE is 2,662,980 / 3,293,696 bytes (80.8508%),
18,722 matched functions. DATA remains 468,869 / 648,064 bytes.
The retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,673,376 CODE bytes.

## 2026-10-22: glyph startup, owner gate and parent-effect initialization

Recovered another 516 bytes from three callback entries previously grouped
inside assembly residuals:

- `func_00136390` (60 bytes) initializes the glyph script cursor, position
  and index, then tail-calls the existing dispatcher. The seven script
  pointers are selected by the fixed factory arguments 0..6. Its ordinary
  C body matches with MWCCPS2 3.0.3, -O3,p and a zero small-data threshold.
- `func_0013AFB0` (72 bytes) clears byte 0x13C and advances its phase when
  owner depth is strictly below 170 or owner phase is at least two. The
  strict floating comparison remains the native instruction sequence.
  It uses the same compiler profile.
- `func_001BE040` (384 bytes) copies the 196-byte owner payload and visual
  metadata, initializes visibility/timing and follows the selected signed
  position record before initializing animation and entering its handler.
  It matches with MWCCPS2 3.0, -O3,p and a zero small-data threshold.
  The row is selected before assigning the render pose, preserving the
  native selector capture and field-update order.

The parent factory explicitly supplies modes 0..25, bounding both the
26-entry placement view at 0044C290 and timer view at 0044C330. No DATA
coverage is added by these code views. Function boundaries now use the
actual callback entries and complete compiled extents; four preceding
alignment bytes remain in the uncredited gap catalog.

Three cleanup definitions now take their genuine single pointer argument,
removing fabricated unused arguments. The no-op handler accepts the
callback's real ignored pointer. All fourteen related callback targets
now agree with their unary invocation interfaces. All 1,037 previously
credited bodies in the affected shared source files remain exact.

Clean splitting, catalog/build checks, all 126 tests and full hybrid
relink/packing pass. CODE is 2,663,496 / 3,293,696 bytes (80.8665%),
18,725 matched functions. DATA remains 468,869 / 648,064 bytes.
The retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,673,376 CODE bytes.

## 2026-10-22: panel transition and two countdown handlers

Recovered 768 bytes in three complete callback bodies:

- `func_00135910` (604 bytes) initializes a winning-side panel, selects its
  direct or table-driven motion and computes velocity toward the target.
  Position, scale, velocity and target use their actual float-vector
  fields. Signed palette division, facing arithmetic, byte alternate-row
  selection and all native field reloads are retained. It matches with
  MWCCPS2 3.0, -O3,p and a small-data threshold of 8.
- `func_00162670` (80 bytes) resets/counts down the effect timer using its
  controller, then installs its next callback. The unsigned timer update
  preserves native 32-bit wrapping.
- `func_001ACA30` (84 bytes) gates on owner state 0x16 and advances its
  phase when the narrowed signed-short countdown reaches zero.
  These two handlers use MWCCPS2 3.0.3, -O3,p and a zero threshold.

The actual table boundaries now separate three four-entry unary groups
from five controller/effect callbacks in the 68-byte owner at 00445770.
The 28-byte owner at 0044B850 separates four unary lifecycle entries from
three owner callbacks. Native dispatch argument order is explicit; the
complete DATA owners and all their pointer values remain unchanged.
No DATA credit is added by these interface corrections or motion views.

`func_00152550` stores a unary callback at offset 0x28, so its definition
and active declarations now take that function-pointer type. All six
nonzero callback values used by active callers have the same genuine
unary signature; other callers clear the slot with null. This preserves
native argument construction without converting code pointers to integers.
Related lifecycle cleanups lose fabricated unused parameters, and typed
actor views retain a consistent public byte-pointer callback interface.
All 2,577 previously credited bodies in affected files remain exact.

Three inventory residuals become their real callback entries; twelve
alignment bytes stay uncredited in the gap catalog. Clean splitting,
catalog/build checks, all 126 tests and full hybrid relink/packing pass.
CODE is 2,664,264 / 3,293,696 bytes (80.8898%), 18,728 matched functions.
DATA remains 468,869 / 648,064 bytes. The retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,673,376 CODE bytes.

## Fade and transition callbacks

Recovered `func_0013C800` (272 bytes), `func_00149900` (364 bytes), and
`func_0014E100` (208 bytes): 844 additional exact CODE bytes. The source
retains native unordered float comparisons, signed short timer reloads,
and double precision transition arithmetic. Four preceding alignment bytes
remain uncredited. Resource cleanup declarations now accept the native
32-bit resource argument, and related lifecycle callbacks use their actual
unary interfaces. All affected previously credited bodies remain exact.

Catalog/build checks, all 126 tests, and full hybrid relink/packing pass.
CODE is 2,665,108 / 3,293,696 bytes (80.9154%), 18,731 matched functions.
DATA remains 468,869 / 648,064 bytes. Retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,673,376 CODE bytes.

## Motion and character-state callback batch

Recovered 21 complete callbacks, adding 3,972 exact CODE bytes. This includes
transition timers, randomized placement, landing behavior, inherited actor
state, four initialization/integration steps, two range-based state
selectors, and six character-state entry handlers. Whole-function proofs
use MWCCPS2 3.0.3, 3.0-011126, and 2.4 with each source's verified profile.
The inherited state copies preserve the full 0xC4-byte native region; strict
and unordered float comparisons and signed timer behavior remain explicit.

Two public helper interfaces now describe the genuine unary animation
callback and two-pointer position-copy helper. All 643 previously credited
bodies in affected files remain exact. The function catalog separates
52 alignment bytes as uncredited gaps; no DATA credit is added.

Clean splitting, catalog/build checks, all 126 tests, and full hybrid
relink/packing pass. CODE is 2,669,080 / 3,293,696 bytes (81.0360%), with
18,752 matched functions. DATA remains 468,869 / 648,064 bytes. The retail
ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,673,376 CODE bytes.

## State transitions and motion entry checkpoint

Recovered 24 complete callbacks, adding 4,456 exact CODE bytes. The batch
includes paired actor positioning, timed motion transitions, target
selection, landing and collision handling, randomized animation entry,
and motion initialization. The random pick table view is bounded by the
native four-bit selector. Strict/unordered floating comparisons and signed
short timer behavior remain explicit. MWCCPS2 3.0.3 and 3.0-011126 verify
each complete body with its actual production profile.

The animation wrapper `func_0018C6E0` takes one actor pointer and supplies
mode 8 to `func_0018C4B0`. Active declarations now agree, and calls in
`func_002CB820` and `func_002BE800` explicitly supply their actor. The
inherited-position helper and two typed motion views retain their local
layouts behind consistent public byte-pointer interfaces. All 1,565
previously credited bodies in affected files remain exact.

Catalog entries now name the real functions; 104 alignment bytes remain
uncredited gaps. No DATA credit is added. Clean splitting, catalog/build
checks, all 126 tests, and full hybrid relink/packing pass. CODE is
2,673,536 / 3,293,696 bytes (81.1713%), with 18,776 matched functions.
DATA remains 468,869 / 648,064 bytes. Retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The fixed CODE checkpoint of 2,673,376 bytes is reached; the next fixed
full-percentage checkpoint is 2,706,313 bytes.

## Contact, recovery, and sound forwarding

Recovered six complete callbacks, adding 2,636 exact CODE bytes:
`func_00200690` (488), `func_00201430` (504), `func_0031E0B0` (524),
`func_0027DD50` (480), `func_00192360` (192), and `func_00273160` (448).
They reconstruct contact recovery, animation transitions, owner updates,
and timed palette/effect behavior. MWCCPS2 3.0.3 verifies the four larger
handlers; 3.0-011126 verifies the two event handlers.

`func_001E3270` now explicitly accepts and forwards the floating scale
already consumed by the native `func_001E4EB0` backend. Its declarations
and a caller using a different argument order now agree. That caller also
explicitly passes its actor to animation update and tests the signed byte
result. The reset wrapper and four forwarding lifecycle wrappers now use
their genuine one-pointer input; the reset backend still receives mode 0.
A typed motion view retains its layout behind the unary byte-pointer API.
All 1,171 previously credited bodies in affected files remain exact.

Eight alignment bytes remain uncredited gaps. No DATA credit is added.
Clean splitting, catalog/build checks, all 126 tests, and full hybrid
relink/packing pass. CODE is 2,676,172 / 3,293,696 bytes (81.2513%), with
18,782 matched functions. DATA remains 468,869 / 648,064 bytes. The retail
ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.

## Action setup and scaling callback boundaries

Recovered five complete functions, adding 1,704 exact CODE bytes:
`func_0021F110` (560), `func_0025E440` (120), `func_0025E4C0` (476),
`func_002E6130` (300), and `func_0031FEE0` (248). They reconstruct action
setup, ground/air initialization, parameter selection, and scaling dispatch.
The constructor consumes only four float fields at each selected movement
parameter prefix; remaining bank bytes stay opaque and add no DATA credit.

The former 604-byte residual at 0025E440 contained a 120-byte dispatcher,
eight alignment bytes, and the separate 476-byte constructor. Both actual
functions now have whole compiler proofs. The nine-entry callback table
uses matching unary signatures, including public byte-pointer interfaces
for three existing typed views. All pointer values remain unchanged, and
all 449 previously credited bodies in affected files remain exact.

The constructor's MOVZ instructions match MWCCPS2 3.0.3 at -O3,p: MOVZ
alone cannot identify Sony/GCC code. The new functions use that verified
compiler profile. Sixteen total alignment bytes remain uncredited gaps.
Clean splitting, catalog/build checks, all 126 tests, and full hybrid
relink/packing pass. CODE is 2,677,876 / 3,293,696 bytes (81.3031%), with
18,787 matched functions among 20,345 cataloged spans. DATA remains
468,869 / 648,064 bytes. The retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.

## Label-named callback families

Recovered 17 complete functions, adding 2,076 exact CODE bytes. Three
owner/effect dispatch families now have their real 40-byte heads and
80-byte gate callbacks. Three parent-phase dispatch families separate
their 36-byte heads from the actual visibility/scaling callbacks. The
batch also recovers the 252-byte scene reset and four paired-effect entry
handlers. Six coarse catalog spans become their separate native functions;
104 alignment bytes remain uncredited gaps.

Callback tables now use the actual unary, owner/effect, and no-argument
interfaces, preserving all original pointer values. The effect factory
`func_001DD470` explicitly returns its allocation result, including null
on failure, as required by native callers that update the returned object.
`func_001DC6D0` retains the unused reserved word explicitly supplied by its
sole retail caller at 0030E544. Mode selection uses an integer argument;
queue-clear wrappers take no arguments. Related public views, no-op and
cleanup callbacks agree with their actual callers. All 1,608 previously
credited bodies in affected files remain exact.

MWCCPS2 3.0.3 -O3,p verifies all new functions. Clean splitting, catalog
and build checks, all 126 tests, and full hybrid relink/packing pass. CODE
is 2,679,952 / 3,293,696 bytes (81.3661%), with 18,804 matched functions
among 20,351 cataloged spans. DATA remains 468,869 / 648,064 bytes; no new
DATA credit is added by the callback type corrections. Retail ELF SHA-256
remains `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.

## Motion labels and the one-entry context table

Recovered six complete functions, adding 592 exact CODE bytes:
`func_001F88A0` (124), `func_00201740` (120), `func_0030A9D0` (76),
`func_0032AFB0` (76), `func_002FFE70` (124), and `func_0032AF60` (72).
They reconstruct motion/event responses, randomized animation selection,
team-specific state clearing, and the preceding actor-bank dispatcher.
The former 156-byte span at 0032AF60 now separates the actual dispatcher
and callback, with eight alignment bytes uncredited. Total newly exposed
alignment gaps are 32 bytes.

The context dispatcher at 002FFEF0 supplies both actor and scratch-state
pointers. Its callback now expresses both inputs, and the embedded table
at 004C1464 has its real one-entry extent. Adjacent script bytes are not
a second callback. Function-pointer table definitions preserve all original
values and use the native callable signatures. The activation entry used
as a no-result callback discards the animation helper's scalar status, and
a signed-byte view retains its layout behind the public actor interface.
All 323 previously credited bodies in affected files remain exact.

MWCCPS2 3.0.3 -O3,p verifies all six new functions. Clean splitting,
catalog/build checks, all 126 tests, and full hybrid relink/packing pass.
CODE is 2,680,544 / 3,293,696 bytes (81.3841%), with 18,810 matched
functions among 20,352 cataloged spans. DATA remains 468,869 / 648,064
bytes; these interface corrections add no DATA credit. Retail ELF SHA-256
remains `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Owner and context entry callbacks

Recovered eight complete functions for 1,036 additional exact CODE bytes:
`001A3AE0` (280), `001A57C0` (80), `001A5810` (104), `001C3430` (72),
`001C3480` (136), `00242A20` (124), `0026CA30` (96), and `002FDBC0` (144).
The two dispatchers are separate native functions from their entry callbacks;
32 bytes of intervening/prefix alignment remain uncredited.

The callbacks reconstruct inherited effect state, related-object animation
responses, facing selection, context initialization, and randomized animation
entries. Six callback owners now declare the native callable argument lists.
The related-object protocol supplies actor, owner, and related actor; the owner
pointer is retained through the existing callback and object constructor rather
than represented as an integer. Existing cleanup callbacks explicitly accept
the owner/context arguments their dispatchers supply. The small related-object
table uses the native GP-relative code view without changing its DATA owner.

Whole-object verification and full hybrid linkage reproduce the retail ROM and
packed ELF. Catalog/build checks and all 126 tests pass. CODE is now
2,681,580 / 3,293,696 bytes (81.4155%), with 18,818 matched functions among
20,359 cataloged spans. DATA remains 468,869 / 648,064 bytes; no new DATA
credit is claimed. The retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Context entries and owner-dependent motion

Recovered six complete functions, adding 1,148 exact CODE bytes:
`002678B0` (204), `002CA050` (160), `001C59D0` (252), `003488E0` (188),
`0035E3D0` (184), and `0035E690` (160), using MWCCPS2 3.0.3 -O3,p.
The C reconstructs scratch-state initialization, launch placement, event-driven
motion, and landing transitions. The landing tests retain the retail unordered
floating-point behavior instead of substituting a less-than-or-equal test.
Native function spans are separated from adjacent dispatch heads and alignment;
no padding or raw instructions receive new credit.

Three existing effect dispatchers now explicitly forward their owner argument,
as required by their constructors and the already typed outer dispatch table.
The effect's internal callbacks and cleanup entries share that actual protocol.
The small landing table has three native entries, and GP-relative code views
retain the correct section annotation. The mixed owner at 004C19A0 now exposes
its two motion callbacks at offset eight as function pointers, preserving the
other address fields and all 128 original bytes. Existing scratch and owner
callbacks accept the real second argument supplied by their native producers.
The animation call in 002673D0 now explicitly supplies its actor argument.

Catalog/build checks and all 126 tests pass. Whole compiler verification and
full hybrid linkage reproduce the retail ROM and packed ELF. CODE is now
2,682,728 / 3,293,696 bytes (81.4504%), with 18,824 matching functions among
20,365 cataloged spans. DATA remains 468,869 / 648,064 bytes: these table
interface repairs add no DATA credit. The retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Vertical motion event callbacks

Recovered `0035D880` and `0035DD40`, each 116 bytes, for 232 additional
exact CODE bytes under MWCCPS2 3.0.3 -O3,p. Both advance vertical motion,
update animation and queue the actor, then change velocity and clear vertical
acceleration when the animation event byte becomes nonzero. Their actual owner
callbacks accept the second argument supplied by the existing GP dispatchers.
The seven-entry and two-entry callback owners retain their native addresses
with callable pointer types; the existing 0035CFE0 callback exposes the same
provided owner argument. DATA receives no additional credit.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,682,960 / 3,293,696 bytes
(81.4574%), with 18,826 matching functions among 20,367 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.
The larger inherited-state candidates investigated in this batch do not yet
match as whole objects and receive no catalog credit.


## 2026-10-22 — Capture entry and trajectory launch

Recovered two complete functions under MWCCPS2 3.0.3 -O3,p:
`0031F3F0` (492 bytes) validates and captures a target, records it in the
actor's scratch context, and handles cancellation/failure motion;
`001A8E70` (508 bytes) positions an effect from a sixteen-byte movement
record and solves its horizontal velocity and phase rate using the native
vertical-trajectory step counter. Total new CODE is 1,000 bytes.

The launch solver and existing landing update now share the same sixteen-byte
record layout. This is a CODE view of the existing bank, with no new DATA
extent or reconstruction credit. The trajectory helper exposes its actual actor
pointer argument while retaining its typed motion view internally.

The 76-byte owner at 0044B620 contains four unary lifecycle callbacks,
twelve binary mode callbacks, and three binary launch callbacks. Its C layout
now preserves those distinct native contracts. The top-level lifecycle
callback stays unary; the mode selector loads the owner from actor+0x18,
and the two subordinate dispatchers now forward that real second argument.
The related seven-entry state table and no-op/cleanup callbacks use their
actual callable signatures. All original pointer values and owner bytes remain
unchanged; these repairs add no DATA credit.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,683,960 / 3,293,696 bytes
(81.4878%), with 18,828 matching functions among 20,368 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Launch initialization and complete capture sequences

Recovered three complete functions for 1,476 additional exact CODE bytes:
`001A8D70` (168) initializes inherited launch state and enters the mode
selector; `002DF5E0` (728) handles airborne capture, failure motion, and landing;
`0026D340` (580) implements a complete four-phase ground-capture sequence.
The initializer matches MWCCPS2 3.0-011126 -O3,p; both capture routines match
MWCCPS2 3.0.3 -O3,p. All use their actual native callback interfaces.

The 44-byte owner at 0045AD80 has four unary entry callbacks followed by
seven callbacks receiving actor-local scratch state through the 0045AD90 alias.
Its shared C layout now represents those two protocols. The initial dispatcher
remains unary; the context dispatcher still supplies actor+0x2B8. Existing
callbacks that ignore this provided context expose that input explicitly.
The capture branch records its target in context+8 and uses the retail
player-side selection. Shared height assignment preserves the native single
load and ordered stores. Original callback addresses and owner bytes remain
unchanged; DATA receives no new credit.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,685,436 / 3,293,696 bytes
(81.5326%), with 18,831 matching functions among 20,369 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Recover ordinary C from the older Grok branch

Reviewed 63 old uncredited catalog rows against the current retail target.
Thirty-six rows reproduced their claimed bytes under the old profiles, but
byte identity alone was insufficient: several used handwritten instructions,
manual NOPs, simplified static callees, or an unproven ambient-register contract.
Those candidates remain uncredited. Recovered six complete ordinary C entries:
`0020F440` (68), `00293710` (288), `00197E40` (148), `00328CA0` (140),
`00328EF0` (140), and `00329540` (140), adding 924 CODE bytes. All six match
MWCCPS2 3.0.3 -O4,p -sdatathreshold 8 after prototype and view cleanup.
Their true native entry names replace old residual names; 68 prefix alignment
bytes remain uncredited. The counter bank uses a flexible tail view rather
than asserting a one-element array bound for a dynamic selector.

The linked-effect bank at 0045E120 now represents its unary selectors/states,
three four-entry owner slices, eight intervening unary entries, and final
four-entry owner slice. The three new linked constructors use the owner
supplied explicitly by their existing dispatchers. The 00197920 family now
retains its owner through mode and side dispatch, with matching callback
declarations; integer-address function casts have been removed from its
seven-entry owner table. The small side bank preserves its two owner entries
and four unrelated unary entries. Native tail helpers express the real owner
argument they move into A0 instead of forwarding four fabricated integers.
All original callback values and DATA owner bytes remain unchanged; these
interface repairs add no DATA credit.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,686,360 / 3,293,696 bytes
(81.5607%), with 18,837 matching functions among 20,375 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Airborne response and owner-linked animation entries

Recovered three complete functions for 1,668 additional exact CODE bytes:
`00218BC0` (576), `001B3450` (488), and `003CD750` (604). The airborne
response matches MWCCPS2 3.0.3 -O3,p; the two linked animation/effect entries
match MWCCPS2 3.0-011126 -O3,p. All use -sdatathreshold 0.

The airborne routine reconstructs hit response, input-dependent animation
changes, landing, and the animation-completion transition. The mode detector
caches the owner's frame/animation pair and selects the corresponding linked
state. The randomized entry copies inherited state, selects layer and frame
bytes, and reproduces the native unsigned-to-float random-motion calculation.
The RNG declaration retains its actual signed return type; unsigned conversion
is explicit at the call sites that require it. Its two byte banks remain opaque
native CODE views, with no new DATA extent or reconstruction credit.

The twelve-entry linked callback table now shares actor/owner pointer
signatures with its actual producer and existing implementations. No-op and
cleanup callbacks explicitly accept their provided arguments. The existing
positioning and motion callbacks keep their typed field views behind public
actor pointers; all original body bytes and table pointer values remain exact.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,688,028 / 3,293,696 bytes
(81.6113%), with 18,840 matching functions among 20,376 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Scaled motion state entry

Recovered the complete 504-byte function `002E2350` under MWCCPS2 3.0.3
-O3,p -sdatathreshold 0. The entry initializes action state, selects the
animation, creates three indexed effects, and divides velocity and acceleration
by eight. Its update path preserves the native ordered ground/height comparison,
then uses animation completion to select the next movement state. Helper
prototypes retain their actual scalar and byte parameters. No DATA credit is added.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,688,532 / 3,293,696 bytes
(81.6266%), with 18,841 matching functions among 20,376 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.
The linked-trail and direction-selection candidates investigated alongside this
entry remain compiler mismatches and receive no catalog credit.


## 2026-10-22 — Linked hit responses

Recovered `0035C0B0` (600 bytes) and `0035F660` (588 bytes), adding 1,188
exact CODE bytes under MWCCPS2 3.0.3 -O3,p -sdatathreshold 0. Both retain
owner-relative placement while their owning action remains active, handle
successful and rejected contact, and initialize color plus signed fixed-point
fade velocity when the action ends. The differing visibility/owner-state writes
are preserved. Negative byte sentinels and GP-relative animation-bank views
retain their actual native representations.

The two three-entry inner callback tables now use actor/owner signatures,
and their existing outer dispatchers forward the provided owner. The effect
creation helpers expose actor pointers and preserve their actual integer return
values; allocated callbacks and owner arguments are stored with pointer types.
Existing typed field views remain internal to the motion updater. Color,
velocity, and animation banks remain opaque CODE views with no new DATA extent
or reconstruction credit.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,689,720 / 3,293,696 bytes
(81.6627%), with 18,843 matching functions among 20,376 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Linked contact capture

Recovered the complete 760-byte function `0035B800` under MWCCPS2 3.0.3
-O3,p -sdatathreshold 0. The callback follows the existing actor/opaque-owner
interface supplied by 0035B560 and the 004631B0 bank. It reconstructs contact
validation, per-target hit-flag updates, target capture and placement, movement
slowing, duration selection, and rejection/landing transitions. Its per-target
flag address uses native 32-bit address arithmetic; the selected frame is cached
for both the actor field and animation call. The vertical-velocity test retains
the retail unordered floating-point behavior. No DATA credit is added.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,690,480 / 3,293,696 bytes
(81.6857%), with 18,844 matching functions among 20,376 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.
The owner-following update investigated alongside this entry remains a whole-
function compiler mismatch and receives no credit.


## 2026-10-22 — Variant motion, motion lanes, and collision transition

Recovered three complete functions, adding 1,500 exact CODE bytes:
`002B4E90` (532) selects action/motion values and cycles its animation state;
`002FDF60` (484) selects ground/air variants and initializes four signed
fixed-point motion lanes; `0029F170` (484) handles landing, timed emissions,
and positive/negative collision notifications. The first two match MWCCPS2
3.0.3 -O3,p; the collision transition matches 3.0-011126 -O3,p. All use
-sdatathreshold 0.

The context entry matches the existing actor/opaque-context callback contract.
Its context is explicitly supplied from actor+0x2B8 through the existing
0045C1C0/0045C170 dispatch path. The collision transition uses typed views for
its actual timers, motion fields, and signed status word while retaining the
public actor-pointer interface. Its unordered ground comparison and the
distinct positive/negative writes remain unchanged. Animation and motion banks
remain opaque CODE views; no DATA extent or reconstruction credit is added.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,691,980 / 3,293,696 bytes
(81.7313%), with 18,847 matching functions among 20,377 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Weighted position and landing phases

Recovered the complete 832-byte function `002F1870` with MWCCPS2 3.0.3
-O3,p -sdatathreshold 0. It handles jump motion, a weighted position adjustment,
landing, and the subsequent capture and launch phases. The existing unary
callback interface and actual helper arguments are preserved. The four-byte
preceding alignment remains uncredited; no DATA credit is added.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,692,812 / 3,293,696 bytes
(81.7565%), with 18,848 matching functions among 20,378 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Contact lanes, grounded capture, and owner motion

Recovered six complete functions, adding 1,240 exact CODE bytes:
`002FB6C0` (280) grounds a captured target, applies the hit offset, and releases
it on timeout; `00325120` (264) initializes contact-lane motion and visibility;
`003250F0` (40) dispatches the four contact-lane phases; `00221F60` (176)
sets the facing-dependent offset and restarts the animation; `001ABE90` (180)
and `001ABCC0` (300) select owner-relative motion and transition by distance.
The first three match MWCCPS2 3.0-011126 -O3,p; the remaining three match
3.0.3 -O3,p. All use -sdatathreshold 0.

The contact-lane caller tests the allocation returned by `001E0A60`. Its
existing wrapper now explicitly returns its actual event pointer, preserving
all 92 native bytes. The four-entry contact-lane table names its verified
unary callbacks. The existing owner dispatcher now declares the actual
16-entry callback bank instead of a two-entry array. These interface repairs
add no DATA credit. Owner arguments are forwarded through the existing
`001A9D20` dispatcher; unordered float comparisons retain the native branch
behavior. Alignment gaps remain uncredited.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,694,052 / 3,293,696 bytes
(81.7942%), with 18,854 matching functions among 20,383 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Child events, recovery choices, and motion phases

Recovered ten complete functions, adding 3,504 exact CODE bytes:
`001A8320` (300), `0020AE50` (416), `0020A9A0` (368), `002415E0` (320),
`0022EC90` (332), `0026EAC0` (336), `002B1E20` (380), `0034E3C0` (304),
`00306B80` (408), and `00396A70` (340). These cover child-event creation,
input/action selection, grounded and center-directed launches, recovery
choices, capture/release conditions, and owner-relative motion decay.
The action selector matches MWCCPS2 3.0-011126 -O3,p; the remaining entries
match 3.0.3 -O3,p. All use -sdatathreshold 0.

The three work-context entries receive actor+0x2B8 through the existing
0020AE20, 002415B0, and 00306B50 dispatchers. The owner-motion entry uses
the existing actor/opaque-owner callback contract. The child-event routine
preserves the typed unary callback installed on its successor. Its downstream
001A8140 helper now explicitly accepts the supplied, unused owner argument;
the existing 004BF790 code view declares its actual 14-entry extent and
GP-relative addressing. Existing bodies and all pointer bytes remain exact.
No DATA credit is added, and alignment gaps remain uncredited. The investigated
0036BDD0 scale update remains a whole-function mismatch and receives no credit.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,697,556 / 3,293,696 bytes
(81.9006%), with 18,864 matching functions among 20,393 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-22 — Motion-bank launches and owner-provided phase entries

Recovered six complete functions, adding 1,328 exact CODE bytes:
`001C5E30` (264) initializes an effect on the opposite owner-facing stage edge;
`001C5DE0` (72) updates owner work and forwards the owner through its phase bank;
`002E6290` (424) selects and applies four fixed-point motion lanes;
`003639B0` (352) advances after a target crossing or native readiness check;
`001290A0` (104) gates mode callbacks; and `0034A950` (112) advances its
owner work on animation completion. All match MWCCPS2 3.0.3 -O3,p
-sdatathreshold 0.

The existing 001C5950 mode dispatcher supplies actor+0x18 through the
0044CCB0 bank; the recovered 001C5DE0 phase dispatcher forwards that owner
to 001C5E30 through 0044CD10. The 001C5F40 helper now explicitly accepts
the actual unused owner argument, preserving its original 120 bytes.
The 0034A950 entry explicitly supplies both arguments read by 0034B040.
The launch entry receives actor+0x2B8 from its existing context dispatcher;
motion records retain their native four-word layout. Unordered float
comparisons, signed selectors, full function extents, and alignment gaps
are preserved. No DATA credit is added.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,698,884 / 3,293,696 bytes
(81.9409%), with 18,870 matching functions among 20,399 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.
The investigated input selector, inherited entries, global-request update,
and controller-slot selector remain whole-function mismatches and uncredited.


## 2026-10-22 — Typed actor motion and linked-trail recovery

Recovered three complete functions, adding 1,792 exact CODE bytes:
`002C8C20` (428) handles airborne input, horizontal movement, and landing;
`001FAD10` (684) handles context-matched motion, landing, and stage wrapping;
`003539D0` (680) updates linked trails, their native work fields, and spawned
callbacks. All match MWCCPS2 3.0-011126 -O3,p -sdatathreshold 0.

Partial actor views name the actual native fields accessed by each function.
They replace raw address casts and the mismatched timer views that prevented
the original scheduling and complete compiler matches. The trail's vertical
offset is initialized after its horizontal adjustment, preserving the native
order. The first two entries retain the existing actor/work callback contract:
001FA8F0 and 002C83B0 explicitly supply actor+0x2B8 through 0044FD60 and
00459EE0. The linked-trail entry remains unary, copies the actual callback,
and uses the allocator's pointer return. Unordered comparisons, full extents,
and existing bank bytes remain intact. No DATA credit is added.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,700,676 / 3,293,696 bytes
(81.9953%), with 18,873 matching functions among 20,400 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.
Investigated controller-slot and roster selectors, hit-motion branches,
input-motion lanes, and the repeat-jump transition remain uncredited.


## 2026-10-23 — Rising motion and three-slot target search

Recovered two complete 320-byte functions, adding 640 exact CODE bytes.
`002AF510` handles the rise event, motion-sign changes, and the descending
transition. It matches MWCCPS2 3.0.3 -O3,p -sdatathreshold 0 with its real
`002ADC20` motion helper present in the compiler unit. That complete 76-byte
helper independently matches retail and receives no additional credit.
`00319480` searches the three native target slots, initializes pursuit motion,
and retains the original rejection/default-action path. It matches
3.0-011126 -O3,p -sdatathreshold 0. Its work pointer is established before
the phase change, preserving the native lifetime and addressing.

Both entries retain their unary actor callback interfaces and use typed
views of the actual fields accessed. No DATA credit is added. Larger pose,
clipping, initializer, and fade/dash candidates remain compiler mismatches
and are retained privately without credit.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,701,316 / 3,293,696 bytes
(82.0147%), with 18,875 matching functions among 20,400 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.


## 2026-10-23 — Boundary snap update

Recovered the complete 316-byte `002645D0` with MWCCPS2 3.0.3 -O3,p
-sdatathreshold 0. It updates motion, preserves the retail marker assignment
and subsequent clear, and snaps to the stored boundary using the distinct
team-zero and other-team float comparisons. The latter retains native
unordered/NaN behavior. Its actor callback interface remains unary.
No DATA credit is added.

Catalog/build checks, all 126 tests, whole compiler-object verification, and
full hybrid linkage/packing pass. CODE is 2,701,632 / 3,293,696 bytes
(82.0243%), with 18,876 matching functions among 20,400 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed full-percentage checkpoint remains 2,706,313 CODE bytes.

## Five actor, selection, and menu functions

Recovered five complete functions: script action initialization (308 bytes),
direction exit motion (436 bytes), owner direction exit (440 bytes), selection
confirmation phases (632 bytes), and menu strip rendering (656 bytes). Each
object matches its whole retail function; no data credit is added.

All 126 tests, catalog and build coverage checks, and full hybrid linkage/packing
pass. CODE is 2,704,104 / 3,293,696 bytes (82.0994%), with 18,881 matching
functions among 20,400 cataloged spans. The reconstructed ELF retains retail
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,706,313 bytes.

## Owner spark setup and cycle rotation

Recovered three whole functions: owner-relative spark initialization
(`00348550`, 344 bytes), cycle rotation (`0033F260`, 340 bytes), and owner-state
copy/dispatch (`00348800`, 220 bytes). The owner argument in the last function
is supplied by native caller `00348520` and forwarded to the selected callback.
The four alignment bytes after its return remain uncredited.

All 126 tests, build/source coverage, catalog validation, and full hybrid
linkage/packing pass. CODE is 2,705,008 / 3,293,696 bytes (82.1268%), with
18,884 matches among 20,401 cataloged spans. DATA remains 468,869 / 648,064
bytes. The full reconstructed ELF retains retail SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,706,313 bytes, 1,305 bytes away.

## Owner-state checkpoint at 2,706,316 code bytes

Seven whole functions add 1,308 bytes: origin-height bounce damping (160),
cached owner position copy (224), cached owner dispatch (188), animation
entry (20), slow drift entry (220), facing offset entry (252), and following
effect initialization (244). Each whole object is verified against retail.
The split owner span retains its four alignment bytes as an uncredited residual.

All 126 tests, catalog validation, source/build coverage, and full hybrid
linkage/packing pass. CODE is 2,706,316 / 3,293,696 bytes (82.1665%), with
18,891 matches among 20,403 cataloged spans. DATA remains 468,869 / 648,064
bytes. The reconstructed ELF retains retail SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The fixed 2,706,313-byte CODE checkpoint is crossed; the next is 2,739,250 bytes.

## Owner animation and visibility setup

Eight whole functions add 1,548 bytes: two visible-owner animation entries
(200 bytes each), table-selected owner animation (208), hidden owner-state
copy (200), visible layer-seven entry (200), hidden owner-layer entry (180),
and the first and second animation entries (168 and 192). The live owner
argument is forwarded where required by the native following phase.
No additional DATA credit is added.

All 126 tests, catalog validation, source/build coverage, whole-object checks,
and full hybrid linkage/packing pass. CODE is 2,707,864 / 3,293,696 bytes
(82.2135%), with 18,899 matches among 20,403 cataloged spans. DATA remains
468,869 / 648,064 bytes. The reconstructed ELF retains retail SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes.

## Owner dispatch and directional motion entries

Six whole functions add 1,240 bytes: owner-state dispatch (184), its wait-state
transition (64), ground-position entry (188), directional drift setup (288),
acceleration entry (276), and direction-dependent offset entry (240).
The owner argument is preserved at the dispatcher and supplied where native
state handlers read it. The eight alignment bytes between the first two
functions remain uncredited. No additional DATA credit is added.

All 126 tests, catalog and source/build coverage checks, whole-object
verification, and full hybrid linkage/packing pass. CODE is 2,709,104 /
3,293,696 bytes (82.2512%), with 18,905 matches among 20,405 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF retains retail
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes.

## Inherited motion and linked effect entries

Ten whole functions add 2,688 bytes across inherited drift, owner-state
dispatch, facing setup, ground/velocity placement, linked effect entries,
and parameter-driven initialization. The state-dispatch span is split at
its two real function boundaries, leaving its four alignment bytes uncredited.
The complete local copy of `func_001CFEA0` is independently verified at its
native address (196 bytes); it adds no extra CODE credit. DATA is unchanged.

All 126 tests, catalog and source/build coverage checks, whole-object
verification, and full hybrid linkage/packing pass. CODE is 2,711,792 /
3,293,696 bytes (82.3328%), with 18,915 matches among 20,407 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF retains retail
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes.

## Owner-relative movement and scatter initialization

Four whole functions add 1,848 bytes: saved-mode velocity setup (324),
circular-motion initialization (504), signed table-offset animation setup
(468), and randomized scatter initialization (552). Their original owner
reads, floating-point calculations, and animation-call order are preserved.
The twelve-byte velocity view models the two consumed floats and leaves
its remaining word opaque; it adds no DATA credit.

All 126 tests, catalog and source/build coverage checks, whole-object
verification, and full hybrid linkage/packing pass. CODE is 2,713,640 /
3,293,696 bytes (82.3889%), with 18,919 matches among 20,407 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF retains retail
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes.

## Owner-relative launch and delayed-scatter variants

Eight whole functions add 2,900 bytes: side placement (280), two directional
launches (368 and 372), table-selected velocity (348), indexed side launch
(360), timed upward entry (340), indexed-height entry (308), and delayed
scatter (524). The shared position routines select the signed offset before
adding the owner coordinate. The scatter routine preserves its signed
16-bit countdown and the original fixed -15 negative-offset behavior.
No additional DATA credit is added.

All 126 tests, catalog and source/build coverage checks, whole-object
verification, and full hybrid linkage/packing pass. CODE is 2,716,540 /
3,293,696 bytes (82.4769%), with 18,927 matches among 20,407 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF retains retail
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes.

## Rotated attachment and randomized drift entries

Three whole functions add 1,284 bytes: a side-launch variant (360), a rotated
linked-actor attachment initializer (604), and bounded random drift (320).
The attachment retains its facing snapshot and its signed six-byte parameter
row view. The drift preserves the original fixed-point calculation while
expressing its bounded integer scaling without a negative signed shift.
DATA credit is unchanged.

`func_001C1DA0` now explicitly returns the allocation pointer that its native
caller tests. All thirteen functions in its object still match retail exactly;
this API correction adds no extra CODE credit.

All 126 tests, catalog and source/build coverage checks, whole-object
verification, and full hybrid linkage/packing pass. CODE is 2,717,824 /
3,293,696 bytes (82.5159%), with 18,930 matches among 20,407 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF retains retail
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes.

## Counted emission and offset interpolation

Two whole functions add 908 bytes: the counted emission-stream controller
(380) and owner-offset interpolation setup (528). The controller preserves
the unsigned stream header and the signed running-count interpretation.
The interpolation routine snapshots its two offset rows into the same
40-byte, sixteen-byte-aligned local object used by the native code.
No additional DATA credit is added.

All 126 tests, catalog and source/build coverage checks, whole-object
verification, and full hybrid linkage/packing pass. CODE is 2,718,732 /
3,293,696 bytes (82.5435%), with 18,932 matches among 20,407 cataloged spans.
DATA remains 468,869 / 648,064 bytes. The reconstructed ELF retains retail
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes.

## Owner dispatch, scale growth, and linked following

Five complete functions add 1,396 verified CODE bytes: owner inheritance and
callback dispatch (180), scaled callback dispatch (196), owner-relative scale
growth (348), side-offset setup (396), and linked-effect following (276).
The callback entries preserve the native owner argument. The follower retains
the allocation failure check and updates both links only on success. The two
12-byte alignment gaps remain uncredited. No DATA credit is added.

All 126 tests, catalog and build coverage checks, whole-object verification,
and full hybrid linkage/packing pass. CODE is 2,720,128 / 3,293,696 bytes
(82.5859%), with 18,937 matches among 20,410 cataloged spans. DATA remains
468,869 / 648,064 bytes. The reconstructed ELF retains retail SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (19,122 bytes away).

## Owner-relative facing and queue-status return

The complete 180-byte facing initializer now matches: it selects horizontal
velocity from the owner-relative target and preserves the animation transition.
The queue-status wrapper at 0x001E5700 now returns its native signed status
instead of declaring it void. Its caller tests that status; all 19 functions
in the wrapper's object remain byte-exact. This ABI correction adds no credit.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,720,308 / 3,293,696 bytes (82.5914%),
with 18,938 matches among 20,410 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (18,942 bytes away).

## Launch, speed adjustment, and airborne movement

Five complete functions add 1,532 verified CODE bytes: launch setup (364),
signed speed adjustment (280), movement reset (276), airborne integration
(324), and fixed-point velocity-bank selection (288). Mode-dependent event
counts, acceleration reversal, animation completion, and the existing action
reset behavior are preserved. The two 12-byte leading alignment gaps remain
uncredited. The external tables add no DATA credit.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,721,840 / 3,293,696 bytes (82.6379%),
with 18,943 matches among 20,412 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (17,410 bytes away).

## Button-selected movement and effect initialization

Six complete functions add 2,608 verified CODE bytes: action selection (508),
center-following movement (620), mode-dependent launch (336), action reset
(220), center-relative jump (400), and spawned-effect initialization (524).
The movement controller uses the native signed 32-bit integer conversion
helpers, confirmed against their reconstructed implementations. The jump
preserves the shared double-to-float rounding point before computing velocity.
Two leading 12-byte alignment gaps remain uncredited. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,724,448 / 3,293,696 bytes (82.7170%),
with 18,949 matches among 20,414 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (14,802 bytes away).

## Facing-relative direction pair and linked velocity bank

Two complete functions add 1,040 verified CODE bytes: the position-pair
controller (528) and linked velocity-bank initializer (512). The controller
uses a contiguous pair of native 12-byte vectors and preserves the unsigned
direction byte and signed interpretation during facing reversal. The bank
initializer preserves both action-reset paths and the native velocity and
acceleration tables. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,725,488 / 3,293,696 bytes (82.7486%),
with 18,951 matches among 20,414 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (13,762 bytes away).

## Linked placement and landing state transitions

Four complete functions add 1,380 verified CODE bytes: linked ground
placement (244), airborne landing control (560), linked height adjustment
(220), and airborne event integration (356). The placement calls use the
native offset helper's two-float input; its implementation and native loads
confirm that the unused third local float is never read. Landing preserves
the separate cancellation paths, phase initialization, motion, and completion
callbacks. Two leading 12-byte alignment gaps remain uncredited. No DATA
credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,726,868 / 3,293,696 bytes (82.7905%),
with 18,955 matches among 20,416 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (12,382 bytes away).

## Animation choice, entry setup, and landing clamp

Five complete functions add 1,436 verified CODE bytes: animation choice
(232), mode-dependent launch (280), entry-mode setup (324), linked-work
initialization (332), and landing clamp (268). The launch preserves facing
reversal of velocity and acceleration, including signed zero. The landing
routine stops horizontal reversal and selects the native animation after
landing. Its integer selectors are narrowed to bytes at the call boundary.
The leading 12-byte gap before 0x00236070 remains uncredited. No DATA credit
is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,728,304 / 3,293,696 bytes (82.8341%),
with 18,960 matches among 20,417 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (10,946 bytes away).

## Input choice, offset placement, and ground reset

Five complete functions add 1,496 verified CODE bytes: input-dependent offset
placement (248), floating work initialization (292), input-based action choice
(436), stage-edge movement selection (280), and ground/air reset dispatch
(240). The offset routine reads both coordinates from one native table entry.
The new call declarations agree with the reconstructed unary reset dispatcher
and byte-argument allocator helper. Leading alignment gaps of 12, 12, and 8
bytes remain uncredited. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,729,800 / 3,293,696 bytes (82.8795%),
with 18,965 matches among 20,420 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (9,450 bytes away).

## Clock-based choice and allocation-result initialization

Two complete functions add 552 verified CODE bytes: clock-based animation
choice (260) and allocation-result initialization (292). The event allocator
at 0x00367F90 now returns its allocated Event pointer or null, matching the
native caller's success test. All 30 functions in its object remain exact;
this return-type correction adds no separate CODE credit. The leading
12-byte alignment gap before 0x00250EC0 remains uncredited. No DATA credit
is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,730,352 / 3,293,696 bytes (82.8963%),
with 18,967 matches among 20,421 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (8,898 bytes away).

## Launch variants and timed event cloning

Five complete functions add 1,392 verified CODE bytes: mode-specific air
launch (392), timed launch (232), timed event cloning (240), offset-effect
setup (296), and facing-reversal launch (232). The event-clone call preserves
its third native argument, confirmed against the reconstructed callee. The
offset-effect position uses vector and floating-array views of the same
local object to agree with the effect helper's input type. Four leading
12-byte alignment gaps remain uncredited. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,731,744 / 3,293,696 bytes (82.9386%),
with 18,972 matches among 20,425 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (7,506 bytes away).

## Verified duplicate, object queries, and launch snapshot

Five complete functions add 1,204 verified CODE bytes: linked-phase following
(116), SDK object-query dispatch (196), linked-phase effects (300), launch-table
snapshot setup (340), and airborne entry (252). The object-query routine and
its existing counterpart explicitly forward their object to the reconstructed
getters. Their compiler output remains exact. The superseded placeholder and
unmatched legacy body were retired; a private recovery copy is preserved.
The 12-byte alignment gap before 0x002BF790 remains uncredited. No DATA credit
is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,732,948 / 3,293,696 bytes (82.9751%),
with 18,977 matches among 20,426 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (6,302 bytes away).

## Ground-work and draw-attribute initialization

Three complete functions add 1,008 verified CODE bytes: grounded work
initialization (232), draw-attribute initialization (408), and draw/work setup
(368). The draw routines preserve the native attribute index ranges and mask
updates using ordinary C loops. Unsigned 16-bit attributes and the inclusive
loop bound reproduce the compiler-generated unrolling without manual expansion.
The signed duration calculation and work-context callback are preserved.
Two leading 12-byte alignment gaps remain uncredited. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,733,956 / 3,293,696 bytes (83.0057%),
with 18,980 matches among 20,428 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (5,294 bytes away).

## Event launch and movement-bank variants

Five complete functions add 1,748 verified CODE bytes: pending-event launch
(436), full movement-bank selection (440), ground launch-bank setup (328),
NPC-dependent work timeout (240), and facing-dependent launch velocity (304).
The event routine preserves the native effect target and scaled position
snapshot. The work initializer retains both the reset and subsequent 0x40
action-word write. The effect helper declaration uses its reconstructed
integer argument type. The leading 12-byte gap before 0x00283FE0 remains
uncredited. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,735,704 / 3,293,696 bytes (83.0588%),
with 18,985 matches among 20,429 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (3,546 bytes away).

## Fixed-point launch and cloned speed-adjustment variants

Four complete functions add 1,360 verified CODE bytes: fixed-point ground
launch (476), mode-dependent air launch (356), speed adjustment with event
cloning (304), and NPC-dependent work reset (224). Ground and air paths keep
their separate callbacks. The launch and adjustment variants preserve their
own velocity constants, sign reversals, event counters, and timer increments.
Two leading 12-byte alignment gaps remain uncredited. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,737,064 / 3,293,696 bytes (83.1001%),
with 18,989 matches among 20,431 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,739,250 bytes (2,186 bytes away).

## Motion-bank launches and actor phase transitions

Eight complete functions add 2,360 verified CODE bytes: launch motion-bank
selection (428), palette/work reset (216), linked-work launch (268), contact
and motion-bank setup (308), variant air launch (344), direction-dependent
speed adjustment (280), height-triggered phase transition (224), and palette
and ground reset (292). Helper declarations retain the reconstructed integer
and pointer return types. Three leading 12-byte alignment gaps remain
uncredited. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,739,424 / 3,293,696 bytes (83.1717%),
with 18,997 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The fixed 2,739,250-byte CODE checkpoint is passed; the next is 2,772,187
bytes (32,763 bytes away).

## Actor movement, landing, and effect transitions

Seven complete functions add 2,452 verified CODE bytes: random state
selection (468), ground speed launch (272), landing response (336),
direction-sensitive speed adjustment (292), air launch and braking (296),
boundary launch (372), and linked effect transition (416). The effect paths
retain their distinct position vectors and the helper's four actual arguments.
The callback allocator at 0x001CE4A0 now returns its allocated entry; all
three callers use the matching pointer return declaration. The allocator
object and both existing caller objects remain exact. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,741,876 / 3,293,696 bytes (83.2462%),
with 19,004 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (30,311 bytes away).

## Actor workflows, parent anchors, and throw velocity

Seven complete functions add 2,416 verified CODE bytes: completion-event
state handling (264), midpoint launch (300), two state workflows (500 each),
palette and animation setup (308), parent-anchor transition (292), and throw
velocity setup (252). The workflows retain their distinct action, callback
mode, and animation constants. Parent-anchor changes copy the full native
position vectors and use the actual matrix helper interfaces. Throw setup
preserves the original position snapshots across both attachment calls.
No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,744,292 / 3,293,696 bytes (83.3195%),
with 19,011 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (27,895 bytes away).

## Target selection and movement cycles

Four complete functions add 1,400 verified CODE bytes: input target
selection (256), air-motion damping (268), bounce and rotation cycle (552),
and distance-driven animation stepping (324). Target selection returns the
actual actor pointer. The bounce cycle uses the reconstructed signed integer
to double conversion and preserves the native signed remainder and angle
arithmetic. Movement stepping retains the distance accumulated after the
absolute-value helper call. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,745,692 / 3,293,696 bytes (83.3620%),
with 19,015 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (26,495 bytes away).

## Owner-dependent launch and frame following

Two complete functions add 704 verified CODE bytes: owner-dependent launch
(276) and frame-dependent owner following (428). The launch retains both
owner-action paths, their facing-dependent velocities, timers, and separate
work resets. Following copies the owner's facing, uses the native signed
frame selector and six-byte table stride, and preserves the callback's actual
pointer return type. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,746,396 / 3,293,696 bytes (83.3834%),
with 19,017 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (25,791 bytes away).

## Owner record copying and bounded event spawning

Four complete functions add 1,224 verified CODE bytes: owner-record child
initialization (276), owner animation initialization (328), bounded event
spawn initialization (364), and owner-ground transition (256). The record
initializers copy the complete 49-word native block and preserve the following
field updates. Child initialization passes the actual owner argument to its
helper. The spawn loop retains its signed 16-bit index, byte-sized remaining
count, allocation-failure exit, and per-success mask update. Its allocator
at 0x00387C40 now returns the actual event pointer; its whole object remains
exact. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,747,620 / 3,293,696 bytes (83.4206%),
with 19,021 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (24,567 bytes away).

## Ancestor initialization and recursive chain positioning

Two complete functions add 744 verified CODE bytes: ancestor-based position
initialization (312) and recursive chain positioning (432). The initializer
copies the complete native 49-word inherited record, uses the second ancestor,
and retains the facing-dependent position adjustment. The recursive routine
updates both linked positions, preserves the signed byte countdown and signed
short flip, and passes all three required inputs to its final helper. Its
partial record views retain the native field offsets without assembly or
register constraints. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,748,364 / 3,293,696 bytes (83.4432%),
with 19,023 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (23,823 bytes away).

## Position samples and inherited offsets

Three complete functions add 1,176 verified CODE bytes: four-sample position
initialization (372), table-driven offset initialization (492), and inherited
facing-offset initialization (312). A four-iteration C loop reproduces all
eight native float-to-integer conversions and sample writes. Offset setup
retains both signed short components, native facing handling, and the action
sentinel. The inherited-position routine preserves its initial coordinate
writes before the facing-dependent update. No DATA credit is added.

All 126 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,749,540 / 3,293,696 bytes (83.4789%),
with 19,026 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (22,647 bytes away).

## Owner-context callback contract and palette/motion initialization

The lifecycle and nested state tables at 0x004761D0, 0x004761F0, and
0x00476220 were declared with zero- or one-argument callbacks, although
states in this family consume the owner context. The lifecycle dispatcher
now explicitly binds the owner from actor field 0x18 and forwards it through
both nested dispatchers. The tables and ignored-owner state signatures use
the existing owner-state callback contract. The direct caller at 0x003C86E0
also uses the same two-argument interface. Every affected code object and
all three complete tables remain byte-exact.

A host C fixture compiles the actual table sources and dispatcher bodies,
then checks that a leaf receives the original actor and owner. A negative
control deliberately drops the owner and must fail that check. This catches
an interface error that retail-byte comparisons alone cannot detect.

The palette/motion initializer at 0x003C8A70 adds 344 verified CODE bytes.
It retains the 16-byte descriptor stride, all four palette channels, facing
update, velocity components, animation selector, and timer setup. No DATA
credit is added for the callback type correction.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,749,884 / 3,293,696 bytes (83.4893%),
with 19,027 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (22,303 bytes away).

## Fixed-point movement and floor transition phases

Five complete functions add 704 verified CODE bytes: fixed-point speed setup
(176), facing-dependent animation reset (136), control-mode selection (128),
palette and ground-phase setup (132), and a floor-motion transition (132).
The transition passes the actual actor argument to its event allocator.

The transition object also contains the real 100-byte floor-integration
helper at 0x00270B60. Compiling that body locally supplies its actual register
preservation behavior; the entire helper is independently verified at its
own retail address on every normal build. It adds no extra progress credit.
The helper and caller both match without stand-ins, assembly, or inserted
padding. No DATA credit is added.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,750,588 / 3,293,696 bytes (83.5107%),
with 19,032 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (21,599 bytes away).

## Delayed launch, animation phases, and contact dispatch

Five complete functions add 664 verified CODE bytes: delayed launch (172),
stage gating (120), queued-command phase (136), animation-event phase (136),
and contact dispatch (100). The launch keeps its one-frame initial gate and
native velocities. The stage gate retains both native paths and work updates.

Three callers compile with their real helper bodies: the 72-byte queued
command consumer, 92-byte signed animation-event offset handler, and 32-byte
state transition. The normal build verifies every complete helper at its own
retail address. These copies supply actual register behavior and add no extra
progress credit. The contact table's two targets require the actor argument;
no extra owner parameter is introduced. No DATA credit is added.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,751,252 / 3,293,696 bytes (83.5308%),
with 19,037 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (20,935 bytes away).

## Single-event spawning and owner-frame synchronization

Two complete functions add 300 verified CODE bytes: single-event spawning
(128) and owner-frame synchronization (172). The constructor preserves its
allocation-failure behavior, callback, owner, mode bytes, and native loop.
The synchronizer uses an opaque object input with a byte-record view, copies
the owner's position and palette, handles hide and release signals, and
advances animation until the masked frame matches. No extra inputs, padding,
assembly, or DATA credit are introduced.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,751,552 / 3,293,696 bytes (83.5400%),
with 19,039 matches among 20,434 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (20,635 bytes away).

## Whole-function boundaries and descriptor-driven spawning

Two catalog entries ended in the middle of their native control-flow graphs.
The ranges 0x003433A0–0x003436F8 and 0x00343770–0x00343954 each have one
entry stack frame and one shared return. Their former interior labels
0x00343438 and 0x0034383C use that frame and saved registers. No external
references to those labels were found in the decoded retail listing or
aligned pointer words. Each pair is now one function. The adjacent alignment gaps remain
uncredited.

The complete second function adds 484 verified CODE bytes. Its ordinary C
loops visit ten 16-byte descriptors and preserve the four- or five-emission
paths, the position threshold, timer gate, and lifecycle states. The complete
856-byte candidate for the first function remains private and uncredited:
seven register-choice differences are unresolved. No matching credit is
awarded for correcting its catalog boundary.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,752,036 / 3,293,696 bytes (83.5546%),
with 19,040 matches among 20,432 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (20,151 bytes away).


## Menu-model construction and actor recovery

Two complete functions add 400 verified CODE bytes: the menu-model
constructor at 0x00134C60 (196) and the actor recovery routine at 0x00185080
(204). The constructor preserves allocation failure, model/position selection,
and the alternate callback path. The recovery routine preserves signed
16-bit countdown narrowing, input masks, randomized transition, and its
zero return value. Typed partial record views recover native field-access
code generation without padding instructions or register forcing.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,752,436 / 3,293,696 bytes (83.5668%),
with 19,042 matches among 20,432 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (19,751 bytes away).


## Indexed menu-model spawning and scripted position steps

Three complete functions add 752 verified CODE bytes. The 296-byte indexed
constructor preserves the alternate-mode flag, 36-byte position-record stride,
model and scale selection, and timer expression. The 316-byte pair constructor
preserves both allocation-failure exits, the two signed-short loop iterations,
owner/context/attachment pointers, selector-dependent positions, and scale.
The 140-byte scripted position step preserves the preceding update call,
owner-state change, signed-byte script read, positive-step gate, conditional
cursor advance, facing, and floating-point position calculation.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,753,188 / 3,293,696 bytes (83.5896%),
with 19,045 matches among 20,432 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (18,999 bytes away).


## Menu-position transitions with a verified real helper

The complete routine at 0x0014C280 adds 260 verified CODE bytes. It snapshots
three complete 12-byte tables into native-aligned local records, queries the
current menu position, selects the next signed-byte state and optional reset
position, and installs the callback and state bytes. A static copy of the real
176-byte helper at 0x0014C1D0 independently matches its own retail body; the
normal build verifies that copy too. The helper and table references add no
extra CODE or DATA credit.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,753,448 / 3,293,696 bytes (83.5975%),
with 19,046 matches among 20,432 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (18,739 bytes away).


## Owner-state initialization and animation event dispatch

Two complete functions add 296 verified CODE bytes. The 172-byte owner-state
initializer preserves its eight-byte clear, owner field copy, byte-state
comparison, mode-dependent transition, and timed animation path. The 124-byte
dispatcher preserves signed animation-result handling, the single mode-2
case, the signed frame flag, and the flag clear before event creation. Both
event helpers receive their actual required mode argument, 2.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,753,744 / 3,293,696 bytes (83.6065%),
with 19,048 matches among 20,432 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (18,443 bytes away).


## Animation-table selection and command-flag gating

Two complete functions add 484 verified CODE bytes. The 220-byte animation
selector uses the native mode-dependent byte tables and masked frame index,
then preserves each timer, state and animation path. Its inventory entry was
still named `residual_002C7640`; it is now the complete `func_002C7640` callback.
The native table at 0x00459E00 points directly to its own stack-frame entry.
The adjacent 32-byte tail dispatcher and catalog span count are unchanged.

The 264-byte flag gate preserves its mode cases, signed flag checks, mask
lookup and flag updates, including the native negation-before-mask expression.
Its call explicitly forwards the input kind. The existing 8-byte tail wrapper
at 0x0016B240 now declares the actual two inputs and returns the mask from
0x0016A210, replacing a void four-argument declaration. The lookup's object
tag agrees with that opaque declaration. Both existing bodies remain exact;
neither receives additional CODE credit. This does not audit all historical
callers of that wrapper.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,754,228 / 3,293,696 bytes (83.6212%),
with 19,050 matches among 20,432 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (17,959 bytes away).


## Initial selection-mask callback creation

The complete initializer at 0x0013CA00 adds 336 verified CODE bytes. It
preserves allocation failure, installs the real callback, clears two saved
mask words, combines the selected players' masks, and visits exactly two
words and 32 bits per word. Set bits dispatch indices 0..63 to the native
byte-index helper. Unsigned shifts preserve bit 31 without signed-shift
undefined behavior. The mask-array declarations and signed read casts agree
with the already verified sibling update routine. No helper or DATA credit
is added.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,754,564 / 3,293,696 bytes (83.6314%),
with 19,051 matches among 20,432 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (17,623 bytes away).


## Owner-relative actor placement and launch initialization

The complete initializer at 0x0017FF30 adds 296 verified CODE bytes. It
preserves byte-state increments, the preceding state update, visibility,
angle and scale setup, animation arguments, velocity and acceleration,
the signed timer, owner-position copy, and both facing-dependent X-offset
branches. Its exported opaque byte-pointer input agrees with the native
callback table. No helper or DATA credit is added.

The former `residual_0017FF30` catalog row is now the complete callback
`func_0017FF30`. The retail table at 0x00448CE8 points directly to this entry,
which owns its stack frame and return. The adjacent 32-byte dispatcher and
the catalog span count remain unchanged.

All 128 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,754,860 / 3,293,696 bytes (83.6404%),
with 19,052 matches among 20,432 cataloged spans. DATA remains 468,869 /
648,064 bytes. Retail ELF SHA-256 is unchanged:
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (17,327 bytes away).


## Complete owner-state initialization and mixed callback contracts

The complete callback at 0x00193500 adds 732 verified CODE bytes. It copies
49 state words, inherits the native fields, initializes animation and palette
state, applies the five signed-short table scales, handles facing, and updates
owner-relative position. Typed position and velocity views preserve native
field access and floating-point order without forced registers or padding.
Its residual catalog entry is now the complete callback; span count is unchanged.

The 20 stored pointers at 0x004492D0 are five distinct four-entry ranges,
selected through native aliases at +0x10, +0x20, +0x30 and +0x40. The first
four ranges take one input; only the last takes actor and owner. The readonly
record at 0x004BF520 similarly contains two unary controller callbacks, two
owner callbacks and a four-short cooldown table. The binder at 0x001934B0
loads the owner from actor+0x18. Both owner dispatch heads and the seven-entry
table at 0x00449400 now preserve that contract; unary paths stay unary.
Shared ignored-owner leaves use the correct owner signature, and three unary
release leaves no longer declare spurious extra arguments. All previously
credited C bodies remain credited and byte-exact.

The apparent pointer at 0x004BF530 was actually the first two cooldowns.
The complete signed-short table is `{16,16,12,10}` at 0x004BF530..0x004BF538.
The initializer sets the work selector to 3; 0x00193970 resets it to zero or
decrements it while nonzero, establishing indices 0..3. Reconstructing its
whole eight-byte span adds the previously uncredited final four DATA bytes.
The backing data stays readonly; native GP-relative consumers retain their
addressing form. No callback-pointer bytes change.

A host fixture compiles the actual tables and dispatch heads, exercises all
logical ranges, and rejects a negative control that drops the owner. All 130
tests, catalog/build coverage, whole-object verification and full hybrid
linkage/packing pass. CODE is 2,755,592 / 3,293,696 bytes (83.6626%), with
19,053 matches among 20,432 spans. DATA is 468,873 / 648,064 bytes (72.3498%).
Retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (16,595 bytes away).


## Relative-motion transfer with original-coordinate snapshots

The complete callback at 0x00253A20 adds 204 verified CODE bytes. It advances
the phase, captures the original X separation and both original X positions,
invokes the real two-input repositioning helper, restores those positions,
clears both actors' velocity/acceleration fields, and applies opposite X
velocities with the native timer. Capturing the separation before the individual
coordinates preserves all three native float saves across the helper call.
The exported unary signature agrees with the callback table at 0x004534E0.

Its former residual catalog label is now the complete callback. The adjacent
32-byte tail dispatcher, alignment gap, and catalog span count are unchanged.
No helper or DATA credit is added.

All 130 tests, catalog/build coverage, whole-object verification, and full
hybrid linkage/packing pass. CODE is 2,755,796 / 3,293,696 bytes (83.6688%),
with 19,054 matches among 20,432 spans. DATA remains 468,873 / 648,064 bytes.
Retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (16,391 bytes away).


## Facing-dependent launch and complete segment-chain positioning

Two complete functions add 864 verified CODE bytes. The 184-byte launch state
at 0x001F2D80 preserves subtype-specific byte setup, state advancement, facing-
dependent velocity and acceleration, the timer, and both animation/effect calls.
The launch table's declarations now reflect the unary actor input instead of
asserting zero arguments. Its former residual label is the complete callback;
the neighboring dispatcher, native alignment and span count are unchanged.

The 680-byte routine at 0x001A6690 computes the planar target, rounds wrapped
headings, walks the linked segments, applies signed-short endpoint offsets and
facing, then places the owner relative to the tail. The already verified sibling
0x001A2F20 has the same instruction/branch/register structure. Only seven native
immediate fields differ: owner-work coordinates, endpoint table address and
final coordinate offsets. The new C applies those semantic changes to the real
algorithm. The angle helper is declared with its actual signed-word return and
two byte-pointer inputs; the sibling source declarations are corrected too.

The direct caller at 0x001A5F10 now explicitly passes actor and owner to the
new routine and the actor to its visibility helper. It remains byte-exact and
receives no extra credit. No callee stand-ins, opcode emission, fixed registers,
manual padding, helper credit or DATA credit are introduced.

All 130 tests, catalog/build coverage, whole-object verification and full
hybrid linkage/packing pass. CODE is 2,756,660 / 3,293,696 bytes (83.6950%),
with 19,056 matches among 20,432 spans. DATA remains 468,873 / 648,064 bytes.
Retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The next fixed CODE checkpoint remains 2,772,187 bytes (15,527 bytes away).


### Owner-position following callback

Recovered `func_003C0B30` as 176 bytes of exact compiled C. The callback
uses the attachment at actor+0xD8, reverses a 40-unit horizontal offset for
the owner's facing, and eases each coordinate one quarter of the way toward
the owner-relative target. The vertical target includes 342.85711669921875.
When animation status is negative, it clears visibility and releases the actor.
The existing allocation path already installs this unary callback. Its genuine
animation and release helper interfaces are retained; no helper or DATA credit
is added.

The Metrowerks 3.0-011126 whole-object comparison, source/build coverage, all
130 tests, and complete hybrid linkage and packing pass. The retail ELF hash
remains `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
CODE is 2,756,836 / 3,293,696 bytes (83.7004%), with 19,057 matches among
20,432 spans. DATA remains 468,873 / 648,064 bytes (72.3498%). The fixed next
CODE checkpoint remains 2,772,187 bytes, now 15,351 bytes away.


## Rotation return and owner callback interfaces

Recovered the complete 328-byte `func_0015BD40`, which approaches a target
rotation in ten-degree steps, clamps the signed degree accumulator at zero
or minus 180, and converts it to the native unsigned 16-bit turn angle. The
existing 328-byte sibling at `func_0015B8B0` has the same algorithm; only two
prologue instructions differ in order. Keeping the actual facing-state helper
with the caller reproduces the native register preservation and instruction
order. Its complete 52-byte body is independently byte-exact at `0x0015BA00`;
no helper credit is added. A signed-short/byte union models the two native
views of the owner's facing field without fabricated register constraints.

The already credited caller at `0x0015BC90` now explicitly passes actor and
owner to the recovered routine, and its real helper copy is also independently
exact. The sibling initializer at `0x0015B7F0` now explicitly supplies both
helper arguments. Both existing whole callers remain exact.

The physical 48-byte callback owner at `0x004BF450` is six adjacent two-state
tables: one unary lifecycle pair, two owner-aware rotation pairs, and three
unary meter pairs. Native producers at `0x0015B730` and `0x0015BBD0` select
the owner pointers at `0x004D18B8` and `0x004D18C4` before calling the two
rotation groups at `0x004BF458` and `0x004BF460`. The C table now preserves
these distinct signatures and its existing byte layout. The lifecycle GP
dispatcher still matches in full. A host fixture links the real table, caller,
callee and helper and detects replacing the owner between caller and callee.
This adds two tests; no DATA bytes or old callers receive extra credit.

All 132 tests, source/build coverage, whole-object verification and full
hybrid linkage/packing pass. CODE is 2,757,164 / 3,293,696 bytes (83.7103%),
with 19,058 matches among 20,432 spans. DATA remains 468,873 / 648,064 bytes.
The retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The fixed next CODE checkpoint remains 2,772,187 bytes (15,023 bytes away).


## Owner-height opposite-edge entry

Recovered `func_001C6AE0` as a complete 264-byte C callback. It has its own
stack frame, return and callback-table reference, immediately after the
32-byte dispatcher at `0x001C6AC0`; its former residual catalog label is now
promoted without changing either boundary or the surrounding gap. The body
increments phase, initializes the four extent bytes, clears depth, reverses
the owner's facing, chooses the opposite screen edge and horizontal velocity,
and places the actor at owner+0x430 plus 4.285714149475098. It initializes
zero acceleration/vertical velocity, selects animation (25,21), then calls
the genuine owner-aware continuation at `0x001C6BF0`. The new symbol-map entry
for that already credited continuation resolves the direct relocation.

The physical 36-byte callback owner at `0x0044CD60` contains a four-state
group and the five-state group beginning at `0x0044CD70`. Both native tail
dispatchers preserve the owner argument, and their C now explicitly forwards
it. The table signatures reflect that shared calling contract, including the
handlers that ignore owner. The eight-byte animation tail drops its former
four-argument placeholder signature in favor of the actual two-input phase
contract. All changed existing functions remain whole-object exact; no extra
credit is added for these interface repairs or for the unchanged table bytes.
A host fixture exercises both real dispatch heads and the complete new entry
callback; its negative control detects substituting the owner before dispatch.

All 134 tests, source/build coverage, whole-object verification and full
hybrid linkage/packing pass. CODE is 2,757,428 / 3,293,696 bytes (83.7184%),
with 19,059 matches among 20,432 spans. DATA remains 468,873 / 648,064 bytes.
The retail ELF SHA-256 remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The fixed next CODE checkpoint remains 2,772,187 bytes (14,759 bytes away).


## Input-branch setup and high interaction launch

Recovered two complete compiler-exact functions, adding 556 CODE bytes.
func_00216760 (324 bytes) selects the existing signed-byte script rows
at 0x004BFED0, 0x004BFED4, and 0x004BFED8 for selector cases 0..2.
The third case distinguishes the 0x800 flag: the special branch sets the
substate and command 18, clears motion, chooses strength 5 and skips the
ordinary animation helper. The ordinary branch uses command 8 and a
facing-dependent horizontal velocity of five. No default values or extra
resets are introduced. The existing unary caller already supplies the actor.
The 12-byte script owner retains its existing signed-byte DATA credit.

func_00348F50 (232 bytes) is a separate framed function referenced by slot
four of jtbl_00461F00, following the already credited 44-byte controller
and its separate four-byte alignment gap. The residual label is promoted
without changing boundaries. The callback initializes the collision extents
and action 69, applies horizontal speed 146.666656494140625 and vertical
speed 100.71427917480469, reverses horizontal direction for facing, saves
the owner's 16-bit type, selects animation (22,29), sets depth offset minus
four and calls the genuine two-input continuation. The velocity constants
retain the verified sibling's integer-bit store representation. They are
floating-point data values, not instruction encodings.

The actual controller at 0x00348F20 loads owner from actor+0x18 and passes
actor and owner through a typed callback table, replacing the integer-array
function-pointer cast. The two handlers that ignore owner now declare the
same phase contract; the release tail's previous four-argument placeholder
is removed. All modified existing functions and all 40 table bytes remain
exact, receiving no additional credit. Host tests exercise the real controller,
table and launch callback and detect owner substitution before dispatch.

All 136 tests, source/build coverage, whole-object comparisons and complete
hybrid linkage/packing pass. CODE is 2,757,984 / 3,293,696 bytes (83.7352%),
with 19,061 matches among 20,432 spans. DATA remains 468,873 / 648,064 bytes.
The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
The fixed next CODE checkpoint remains 2,772,187 bytes (14,203 bytes away).


## Inherited-effect entry and nested owner flow

Recovered func_003611D0 as 316 bytes of complete exact C. A dedicated frame,
return and incoming callback-table slot establish the function boundary after
the existing 32-byte dispatcher at 0x003611B0; the residual catalog entry is
promoted without changing the span or following alignment gap. The callback
copies the complete 196-byte inherited state, team, kind, scale and mode fields,
copies depth and Z, sets the signed depth offset to minus one, initializes
action 14, clears animation counters, increments the team counter, sets both
interaction bytes to 0x42, chooses animation (23,20), sets timer one and calls
the genuine owner-aware continuation at 0x00361310.

The native copy-loop scheduling matches Metrowerks 3.0-011126 at -O3,p with
small-data threshold eight. The team counter uses a partial record view with
a flexible trailing array, avoiding the inherited template's artificial
one-element bound; no DATA extent or additional DATA credit is claimed.

The 28-byte table at 0x004634F0 holds four lifecycle callbacks followed by
three phase callbacks beginning at 0x00463500. The root dispatcher and nested
phase dispatcher now explicitly forward owner through both groups. The first
phase at 0x00361340 now supplies owner to the actual two-input positioning
helper at 0x00361880; its complete 64 bytes remain exact. The handlers that
ignore owner declare the same callback contract, and the release tail drops
its former four-argument placeholder signature. All modified existing bodies
and table bytes remain exact and receive no additional credit.

A host fixture executes the real root dispatcher, entry callback, nested
phase dispatcher, first phase and positioning helper. Its negative control
substitutes owner immediately before the positioning call and is detected.
All 138 tests, source/build coverage, whole-object comparisons and complete
hybrid linkage/packing pass. CODE is 2,758,300 / 3,293,696 bytes (83.7448%),
with 19,062 matches among 20,432 spans. DATA remains 468,873 / 648,064 bytes.
The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
The fixed next CODE checkpoint remains 2,772,187 bytes (13,887 bytes away).


## Work-context dispatcher and four-selector initializer

The previous 428-byte catalog entry at 0x00351060 contained two functions
and intervening alignment. Recovered the 52-byte dispatcher at 0x00351060
and the separate 364-byte initializer at 0x003510A0. Both whole functions
are independently exact under Metrowerks 3.0-011126 at -O3,p, small-data
threshold eight. The 12 bytes from 0x00351094 to 0x003510A0 remain a separate,
uncredited native-alignment span. The total CODE denominator is unchanged.

The dispatcher stores actor+0xD0 in D_004C2960 and owner+0x2B8 in D_004C295C,
then selects the second four-state group of jtbl_004624C0 using actor+4.
The initializer increments that state, copies 196 inherited bytes and the
explicit team, kind, scale, mode, shade and depth fields, then initializes
visibility, facing, interaction bytes, X/Y position, collision extents,
timers and motion. It selects the X/Y velocity pair by actor+0x20 and tail
calls the genuine animation helper with group 21 and animation 29+selector.

The already credited constructor at 0x00350FF0 makes four allocation attempts
and assigns selectors 0..3. Its owner parameter and callback store now use
pointer types, matching the actual native interface; all 108 constructor
bytes remain exact. The allocator declaration uses its actual pointer-first
contract. The existing eight-float DATA owner at 0x004624E0 supplies four
interleaved velocity pairs. The component aliases used by native code are
added to the symbol map; no DATA bytes receive additional credit.

A host fixture runs the actual constructor, dispatcher and initializer across
all four selectors, sourcing velocity values from the canonical DATA C. It
also verifies that a failed allocation does not prevent later attempts. A
negative control detects an owner-work pointer displaced by four bytes.
All 140 tests, source/build coverage, whole-object comparisons and complete
hybrid linkage/packing pass. CODE is 2,758,716 / 3,293,696 bytes (83.7575%),
with 19,064 matches among 20,434 catalog spans. DATA remains 468,873 / 648,064
bytes. The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
The fixed next CODE checkpoint remains 2,772,187 bytes (13,471 bytes away).


## Three vector-cycle callbacks and explicit height-helper input

Recovered complete 160-byte callbacks at 0x00161530, 0x00161780 and
0x001619D0, adding 480 CODE bytes. Each begins four bytes after the start of
its former residual catalog span and is named by the existing callback table.
The four-byte native alignment before each entry remains uncredited. Boundaries
now separate each alignment word from the independently verified full function.
The CODE denominator is unchanged.

The callbacks increment an eight-bit key, then reduce the wrapped byte modulo
three. They select a complete three-float target from the existing bounded
three-row tables at 0x004B3ED0, 0x004B3F80 and 0x004B3FB0. A typed object view
models the current vector, primary delta vector, alternate delta fields at
0x5C/0x60/0x68, phase byte and 32-bit timer. Each prepares a 20-update transition,
advances phase, and tail calls its genuine update helper. That first update is
included in the 20 updates: the timer is 19 when the callback returns. No fixed
registers, assembly, manual padding or fake helper bodies are used.

The existing 112-byte func_001C1590 caller now explicitly passes actor to
func_001C1630 through its typed one-input declaration. The caller remains exact;
the still-unreconstructed helper body receives no new credit. A host fixture
checks the actual caller and detects substituting owner for actor.

A separate fixture executes all three real callbacks, their actual callback
table, the real update helpers and the canonical DATA C tables. It checks
selectors 0/1/2/255, all 20 updates, phase reset, and preservation of the unused
slot at offset 0x64. Its negative control detects moving remainder before the
eight-bit wrap. Both fixtures include positive and negative controls.

All 144 tests, source/build coverage, whole-object comparisons and complete
hybrid linkage/packing pass. CODE is 2,759,196 / 3,293,696 bytes (83.7720%),
with 19,067 matches among 20,437 catalog spans. DATA remains 468,873 / 648,064
bytes. The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
The fixed next CODE checkpoint remains 2,772,187 bytes (12,991 bytes away).

### Outstanding DATA ownership issue found during this CODE work

The pre-existing catalog partly labels 0x0044AC20..0x0044ACA0 as callback
pointers. The actual consumer, func_0019E0F0, masks its random selector to
0..15 and reads four signed shorts per eight-byte record through
D_0044AC20/22/24/26. That proves a 128-byte velocity/acceleration table,
including the last 16 bytes currently attached to jtbl_0044ABA0. The DATA
owner split and pointer interpretations need repair. They are unchanged in
this CODE batch; byte equality alone does not validate those existing C types.


## Inheritance dispatcher with the actual work-context input

Recovered func_0019E670 as a complete 224-byte C function. It increments
lifecycle state, copies 196 inherited bytes and the explicit identity, scale,
mode, shade and depth fields, then dispatches one of eleven effect phases.
Its second input is the supplied work pointer, not the owner pointer used
for inheritance. The existing 48-byte caller at 0x0019DFD0 explicitly supplies
actor+0x88 through the last four-entry view at 0x0044AC10. That native caller
and the complete new body are independently exact.

The phase table at 0x0044ACC0 now declares the two-input actor/work contract.
Nine already credited C phases now expose that shared contract even when
work is unused; their full bodies remain exact and receive no extra credit.
The remaining existing two-input C phase already consumes work, and the
unreconstructed first phase has the same external call contract. These are
actual inputs supplied by the native caller, not unused parameters inserted
to influence register allocation. The legacy heterogeneous parent address
owner retains an explicit function-address conversion for the two-input
entry; its separate velocity-record ownership error remains pending.

A host fixture executes the actual work-pointer producer and inheritance
body, uses the real phase table and checks all eleven phase-boundary calls.
Its negative control detects substituting owner for actor+0x88. The fixture
checks argument flow and inherited fields; full compiler-object verification
covers the actual existing phase implementations.

All 146 tests, source/build coverage, whole-object comparisons and complete
hybrid linkage/packing pass. CODE is 2,759,420 / 3,293,696 bytes (83.7788%),
with 19,068 matches among 20,437 catalog spans. DATA remains 468,873 / 648,064
bytes. No DATA credit is added for the callback declarations. The retail ELF
SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
The fixed next CODE checkpoint remains 2,772,187 bytes (12,767 bytes away).


## Owner-derived initializers, owner handoff and frame attributes

Recovered two full inherited-state entry bodies: func_001BE590 (172 bytes)
and func_001C3F40 (196 bytes). Both increment lifecycle state, set the native
kind identifier (0x1802 or 0x1C04), cache owner from actor+0x18, copy all 196
inherited bytes and the explicit identity/scale/mode/signed fields, and tail
call their actual continuations. The first starts hidden. The second sets
collision extents (24,24,16,16) and clears depth before continuation. Incoming
table references and complete entry/return flow prove both former residuals
are whole functions; no neighboring bytes are credited.

The continuations at 0x001BE640 and 0x001C4010 had exposed overwritten owner
and scratch parameters as inputs. Those are now real locals. Their actual
inputs are unary; they derive owner internally and explicitly supply it to
the outgoing two-input phase calls. This real argument flow reproduces all
80 and 152 bytes, without keeping fake incoming formals to constrain registers.
Five mode dispatch heads now forward owner through their 3/3/2/2/3 phase
groups. The relevant callback tables expose that shared contract, including
phases that ignore owner. Both lifecycle release tails now declare their
actual unary input. Every modified old body remains exact and gets no new
credit. Local GP access attributes preserve native small-table addressing;
the actual read-only DATA objects remain in their original sections.

The physical callback owner at 0x0044CB90 now represents four lifecycle
entries followed by five owner-mode entries. The already typed owner at
0x004BF960 separates its two owner-aware inherited callbacks from the ten
following unary callbacks. Their byte layouts and existing DATA credit are
unchanged. No new initialized DATA values are introduced.

Also recovered func_001B5A40 as a full 152-byte entry after its separate
four-byte alignment word. It advances an eight-bit counter, hides the actor,
selects the 48-byte frame record at owner.frame+2, sets its dirty word, then
updates three 16-bit attributes. Their low 12 bits are preserved and their
high nibble becomes nine. The typed frame view follows the native record
stride and observed fields; no BSS or DATA extent is credited.

Host fixtures run the real lifecycle initializers, continuations, dispatch
heads, callback tables and release tails. They check both owner-dependent
families, all five modes and their phase entries, cancellation and release,
and detect substituting actor for owner. The frame fixture checks signed
frame indices, byte-counter rollover, untouched neighboring records and
fields, and detects a wrong keep mask.

All 150 tests, source/build coverage, whole-object comparisons and complete
hybrid linkage/packing pass. CODE is 2,759,940 / 3,293,696 bytes (83.7946%),
with 19,071 matches among 20,438 catalog spans. DATA remains 468,873 / 648,064
bytes; the previously documented 0x0044AC20 ownership issue remains pending.
The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
The fixed next CODE checkpoint remains 2,772,187 bytes (12,247 bytes away).


## Two-frame palette update (+384 CODE bytes)

Recovered func_0021D280 as a complete 384-byte Metrowerks 3.0.3 function.
It selects the frame after the actor's signed frame index. If that frame's
first editable attribute already has palette nibble C, it returns without
writing. Otherwise it sets the actor's work flag and dirties both adjacent
48-byte frames, replacing the high nibble of attributes 1 through 15 with C
while preserving their low twelve bits. Attribute zero and neighboring fields
are untouched. This adds no initialized DATA or BSS credit.

The host fixture checks signed frame selection, both adjacent records, every
attribute, neighboring fields and the no-write early exit. A negative control
that retains the previous high bits fails. All 152 tests, source/build coverage,
whole-object comparisons and full retail-exact hybrid linkage/packing pass.
CODE is 2,760,324 / 3,293,696 bytes (83.8063%), with 19,072 matching spans among
20,438 catalog spans. DATA remains 468,873 / 648,064 bytes; the documented
0x0044AC20 ownership issue remains pending. The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
The next fixed CODE checkpoint remains 2,772,187 bytes (11,863 bytes away).


## Correct the six-effect position interface (no new byte credit)

The native func_00380160 reads three floats from its second input and copies
all three into the allocated effect. Its already matched six-spawn wrapper,
func_003801F0, incorrectly declared that input as a 32-bit integer. The wrapper
now takes a three-float position pointer and declares the actual callee's
pointer and signed-integer inputs consistently with its definition. Whole-object
comparison preserves every existing h4e.c match; no new function is credited.

A host fixture executes the actual wrapper and actual allocation body, checking
six calls, owner/callback pointers, all XYZ coordinates, child indices, neighboring
bytes, and each possible failed allocation. This also exercises full host-width
pointers, exposing the previous integer declaration. All 153 tests and complete
retail-exact hybrid linkage/packing pass. CODE remains 2,760,324 / 3,293,696 bytes
(83.8063%); DATA remains 468,873 / 648,064 bytes (72.3498%).


## Model curvature callback (+384 CODE bytes)

Recovered the complete func_00331350 callback with Metrowerks 3.0, -O4,p,
and small-data threshold zero. It reads and writes model samples through
their actual callbacks, deforming only negative-Y samples along Z. The
angle uses the actor phase plus separately truncated Y and half-X components,
then the native double-precision turn conversion. Curvature multiplies the
squared Y coordinate and one plus the sine term. Both iterator state pairs
are cleared before the destination iterator is released.

The registering func_00330EF0 supplies the actor through the callback's signed
32-bit context input. Using that actual interface, then converting the context
to the actor pointer, resolves the saved-register differences that remained
under a guessed pointer formal. The complete 384-byte compiler object matches;
no forced registers, padding, substitute callees or duplicate credit is used.

All 153 tests, source/build coverage, whole-object comparisons and full
retail-exact hybrid linkage/packing pass. CODE is 2,760,708 / 3,293,696 bytes
(83.8179%), with 19,073 matches among 20,438 catalog spans. DATA remains
468,873 / 648,064 bytes. The next fixed CODE checkpoint remains 2,772,187 bytes
(11,479 bytes away). The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.


## Correct the model interpolation registration contract (no new byte credit)

The actual func_00170E60 walker invokes callbacks with two model-node data
regions and a signed 32-bit context. The func_0033A700 registration had instead
declared its callback as a one-argument function and its context as a pointer.
It now uses the engine's actual callback and descriptor-pointer types, passing
the stack context through the explicit 32-bit address conversion. The context
fields are identified as the frame-block address, two frame indices, and the
interpolation fraction.

The registration and walker share one header containing their existing element
and node definitions and function contract. Their record layouts are unchanged.
Both build stanzas include the header search path. Whole-object verification
preserves all previously credited functions in h1b.c and w1910_f.c, including
the real static node helper. All 153 tests, source/build coverage and full
retail-exact linkage/packing pass. No new CODE or DATA bytes are credited:
CODE remains 2,760,708 / 3,293,696 bytes (83.8179%); DATA remains 468,873 /
648,064 bytes (72.3498%). The interpolation callback body remains uncredited
until its complete compiler comparison passes.


## Actor motion transitions with verified helper bodies (+696 CODE bytes)

Recovered four whole functions with Metrowerks 3.0.3, -O3,p and small-data
threshold zero:

- func_001BF860, 52 bytes: advances the phase, sets a ten-tick timer and restores
  vertical scale when the owner's signed timer expires, then runs the actual
  frame-clock continuation.
- func_00299A20, 204 bytes: integrates unfrozen motion, performs the landing
  transition, selects the byte-wrapped animation event, and consumes any queued
  command through its real continuation.
- func_002B09B0, 208 bytes: consumes a queued command, updates motion, clamps a
  horizontal reversal using new velocity times old velocity, and changes phase
  and animation when vertical velocity becomes negative.
- func_002CFA90, 232 bytes: initializes a ground-level launch, including the
  special mode flags, facing-dependent velocity, counter update, animation and
  pending-command continuation.

Making genuine callee bodies visible resolves compiler register differences
without fake parameters, stand-ins, register pinning or opcode edits. The
complete helpers at 0x001BF550 (100 bytes), 0x00296FB0 (72 bytes), 0x002ADC20
(76 bytes), and 0x002CFA20 (72 bytes) each independently match their own native
address. They were already credited and receive no additional credit here.
The normal build checks these copies as well as each new caller.

The formerly residual 0x002CFA90 span has a real 32-byte stack frame, complete
return at 0x002CFB70 with stack restoration in its delay slot, and a retail
function-pointer entry in slot zero of jtbl_0045A260. The pinned image word at
0x0045A260 is 0x002CFA90, and the existing phase dispatcher indexes that table.
Its catalog span is promoted without changing its 232-byte extent or crediting
neighboring alignment.

Host fixtures execute all four new bodies and their real static helper bodies.
They check owner/frame-clock gates, timer and byte rollover, freeze behavior,
landing/event selection, horizontal reversal, falling transitions, both launch
orientations, command consumption, and exact counter increments. A reversed
horizontal clamp fails. The host harness widens only address arithmetic and
relocates the owner pointer slot to accommodate host pointer width; separate
whole-object comparisons validate the unchanged PS2 layouts and ABI.

All 155 tests, source/build coverage, complete compiler comparisons and full
retail-exact hybrid linkage/packing pass. CODE is 2,761,404 / 3,293,696 bytes
(83.8391%), with 19,077 matches among 20,438 catalog spans. DATA remains
468,873 / 648,064 bytes; its documented ownership issue remains unresolved.
The next fixed CODE checkpoint remains 2,772,187 bytes (10,783 bytes away).
The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.


## Actor approach transition (+360 CODE bytes)

Recovered func_00377390 as a complete 360-byte Metrowerks 3.0.3 function with
-O3,p and small-data threshold zero. It decrements the signed timer on a
negative frame-advance result, delegates contact handling, and returns immediately when
that helper handles a hit. An active animation marker selects motion
integration. Otherwise, the actor advances its subphase when its X position
is strictly inside (target.X-80, target.X+80) and the target is not airborne,
or when the timer equals one. The owner variant selects animation event eight
or nine. The other path sets the native vertical velocity and acceleration;
normal paths then enqueue the actor.

The snapshots of actor/target X and their shared half-width reproduce the
native floating-point comparison and addition order. Merely reversing the
lower comparison's C operands had produced a different instruction, despite
ordinary finite arithmetic looking equivalent. The recovered body requires
no forced registers, artificial parameters, stand-ins or manual padding.
The already matched contact helper at 0x003777B0 is added to the symbol map
so the new direct call resolves under normal object verification.

Fixtures execute the new body with the actual contact and queue helpers,
using controlled animation and event calls. They cover both strict interval
boundaries, airborne-target rejection, timer fallback after frame advancement,
both owner variants, marker-driven motion, contact early return, hit effects,
queue suppression and saturation at 94 entries. Making the lower bound
inclusive fails the negative control.

All 157 tests, source/build coverage, whole-object comparisons and full
retail-exact hybrid linkage/packing pass. CODE is 2,761,764 / 3,293,696 bytes
(83.8500%), with 19,078 matches among 20,438 catalog spans. DATA remains
468,873 / 648,064 bytes (72.3498%). The next fixed CODE checkpoint remains
2,772,187 bytes (10,423 bytes away). The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.


## Correct the capture constructor's pointer result (no new byte credit)

The native func_001D7CE0 leaves the allocated object pointer in V0, including
null when allocation fails. The uncredited caller at 0x003A98C0 tests that
result before advancing its phase and emitting the next event. Its reconstructed
definition had incorrectly returned void, so a correctly typed C caller could
not observe the result despite the existing object passing byte comparison.

The constructor now returns Obj* explicitly on every path. Its allocator
declaration also uses the existing allocator's pointer input and result types.
All five previously credited functions in q7_a.c retain their exact bytes;
no new function or data span is credited by this correction.

The host fixture calls the real constructor and checks pointer identity on
success, null on failure, no source/object writes on failed allocation, capture
of the owner and source fields, zero extension of the 16-bit and byte inputs,
and callback selection from the full mode value before narrowing its stored
byte fields. A null source is also safe when allocation fails. The old void
result fails this fixture's C type checking. Native whole-object comparisons
separately prove the unchanged PS2 layouts and register-level interface.

All 158 tests, source/build coverage and full retail-exact hybrid linkage and
packing pass. CODE remains 2,761,764 / 3,293,696 bytes (83.8500%); DATA remains
468,873 / 648,064 bytes (72.3498%). The new 0x003A98C0 caller remains uncredited
because its complete compiler comparison has not passed.


## Animation signal handler and allocation result (+240 CODE bytes)

Recovered func_0035F270 as a complete 240-byte Metrowerks 3.0 function with
-O3,p and small-data threshold zero. A selected bit in the 16-bit frame-phase
mask suppresses its state updates, while normal paths always enqueue the
actor. An unmasked update runs the real timer helper and frame advance,
consumes any new animation command, updates the counter and clears its timer.
An animation marker advances the byte subphase and creates the next object.
Failed allocation sets only the signed status byte at context offset four.

The frame driver func_00172760 normalizes D_004D18DB with AND 15 at
0x00172840 and stores it at 0x00172844 before actor updates. The handler uses
that 0..15 engine invariant for its shift; no speculative wider table or DATA
extent is credited.

Native callers test the pointer returned by func_0035EF90, but its definition
had incorrectly returned void. It now explicitly returns the allocated object
or null and accepts the promoted mode value before narrowing the stored byte.
The allocator and existing caller declarations are consistent with that
interface. All 40 previously credited functions across m6.c and grok_w5_0024.c
retain their exact bytes; the already credited 128-byte constructor gets no
additional credit.

Fixtures execute the handler with its actual timer, creation and queue bodies.
They cover all sixteen clock phases, selected/unrelated mask bits, helper order,
fresh animation commands and markers, timer clearing, exact counter updates,
subphase rollover, allocation success/failure, copied position/context and the
single-byte failure marker. Inverting the phase-mask gate fails the negative
control. Host-only address calculations are widened while native-width stores
remain unchanged; compiler comparisons independently check the PS2 ABI.

All 160 tests, source/build coverage, whole-object comparisons and complete
retail-exact hybrid linkage/packing pass. CODE is 2,762,004 / 3,293,696 bytes
(83.8573%), with 19,079 matches among 20,438 catalog spans. DATA remains
468,873 / 648,064 bytes (72.3498%). The next fixed CODE checkpoint remains
2,772,187 bytes (10,183 bytes away). The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.


## Referenced handlers recovered from residual spans (+188 CODE bytes)

Recovered func_001C0C60 (96 bytes) and func_001CA5C0 (92 bytes) with
Metrowerks 3.0.3, -O3,p and small-data threshold zero. Both have complete
native stack frames and returns, plus real callback-table references.
The pinned words at 0x0044C7E8 and 0x0044C7F4 reference the depth/animation
handler. Six slots in jtbl_0044D8C0 reference the random-start handler.
Twelve no-op bytes at 0x001C0C54..0x001C0C60 remain uncredited alignment;
only the complete 96-byte body is promoted. No neighboring padding is credited.

The depth handler runs the actual owner-relative position helper, copies its
owner's signed depth byte, and advances phase and hides the actor on a negative
frame-advance result. The random-start handler initializes only subphase zero,
sets its timer from the random low nibble, runs direction/angle initialization,
and always invokes its updater.

The physical owner at 0x0044C770 now represents four unary lifecycle callbacks
followed by 57 actor/owner mode callbacks. Its mode alias and the three-entry
subphase table at 0x0044C868 use that real two-input contract. Dispatchers now
forward owner explicitly; the nested GP-relative pair remains unary because
it does not consume the outer owner context. Shared mode callbacks that ignore
owner declare that interface explicitly. The lifecycle release tail now takes
its real actor pointer instead of four fabricated integer inputs.

Also repaired func_001C0CC0's omitted owner argument to func_001C1330. Frame
advance declarations in the affected source use the actual integer result,
with explicit signed-byte tests where native code narrows it. Every modified
old body and both complete callback objects retain their exact bytes. Their
existing CODE/DATA credit is unchanged.

Fixtures use actual tables, lifecycle/mode/subphase dispatchers, the new depth
handler, owner-position helper and motion/release bodies. They check owner
identity, mirrored offsets, depth extremes, phase rollover and cleanup; passing
actor in place of owner fails. The random fixture checks all six callback
bindings, initial/repeated entry, helper ordering, low-nibble bounds and the
always-run updater; widening the random mask fails.

All 164 tests, source/build coverage and complete compiler/data comparisons
pass. The full hybrid relink and packed ELF remain retail-exact. CODE is
2,762,192 / 3,293,696 bytes (83.8630%), with 19,081 matches among 20,439 catalog
spans. The extra catalog span explicitly separates the uncredited alignment;
the conservative text denominator is unchanged. DATA remains 468,873 / 648,064
bytes (72.3498%). The next fixed CODE checkpoint remains 2,772,187 bytes
(9,995 bytes away). The retail ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.


## Owner-action gate and follow startup (+160 CODE bytes)

Recovered func_00197490 (132 bytes) and func_001C0E40 (28 bytes), each
compiled with Metrowerks 3.0.3, -O3,p and small-data threshold zero. The
retail pointer at 0x0044A210 selects the owner-action gate through
func_00194AA0. The follow pair at 0x004BF9D0 contains the startup and
func_001C0E60; func_001C0E20 selects them using actor subphase. Two four-byte
alignment gaps remain uncredited. No padding or partial bodies are counted.

Corrected the previous entry's claim that the nested follow pair is unary:
func_001C0E60 consumes the owner, so both its dispatcher and startup now
forward that input. The actual startup resets its timer, sets depth to 15,
advances subphase and invokes that updater. The typed physical table retains
all original bytes. The owner-action gate compares signed owner identifiers,
clears changed identifiers, or selects the normal/alternate phase table.
Those phase tables now forward actor and owner explicitly; the normal table
has four entries. Removed the unused third argument from the real acceleration
handler and its leading dispatcher interface. Every affected old function
retains its complete native bytes.

Native tests exercise the real startup, follow update, owner-position helper,
identifier helper, phase dispatchers and acceleration handler. They cover all
four normal and two alternate routes, signed identifier extremes, parent
lifecycle state, phase rollover and timer visibility. Wrong owner forwarding
fails a negative control. All 166 tests, catalog/source/build checks and whole
compiler objects pass. The hybrid loaded image and packed ELF remain exact,
with ELF SHA-256
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.

CODE is 2,762,352 / 3,293,696 bytes (83.8678%), with 19,083 matches among
20,441 catalog spans. DATA remains 468,873 / 648,064 bytes (72.3498%). The
next fixed CODE checkpoint remains 2,772,187 bytes, 9,835 bytes away.


## Owner copy startup and bounded player round gate (+460 CODE bytes)

Recovered func_0019D860 (268 bytes, Metrowerks 3.0) and func_00133970
(192 bytes, Metrowerks 3.0.3), both at -O3,p with small-data threshold zero.
Both match as complete compiler functions. The copy startup has a real
pointer at 0x0044ABF0, selected by func_0019D830 from actor phase; its twelve
preceding alignment bytes remain uncredited. The menu gate is referenced at
0x0043E918 and selected by func_00133950 from subphase. Its native frame and
return occupy the complete former 192-byte residual.

The copy startup advances phase, hides and resets inactive actors, or copies
all 196 owner-state bytes plus position, scale, identity and facing fields.
It adjusts depth and animation state, selecting animation 28 only for signed
owner selectors at least 32. The real two-entry copy phase pair now has
actor/owner signatures in the physical table, and the dispatcher uses those
types. Neighboring legacy DATA ownership issues remain unresolved and receive
no new credit here.

The menu gate checks scene mode and round state, reads the nonzero player
selection, and either resets to an alternate state or advances phase, sets up
position, tests current sound flags and clears the timer. The bit shift uses
the actual player-slot contract: func_00133720 calls the constructor for slots
0 and 1, and func_00133760 stores that slot at actor byte 2. The menu phase
dispatcher now forwards the owner to all three handlers; their real native
bodies consume that input. No unused argument was added to force a match.

Tests compare the complete actor buffer for active/inactive owner copying,
check signed animation selection and reject a shortened state copy or wrong
owner. The menu tests cover every byte selection value, both constructed
player slots, round guards and flags changed across the helper call. Wrong
owner forwarding and caching flags before the helper both fail.

All 172 tests, source/build/catalog checks and compiler objects pass. The
full linked image and packed executable remain retail-exact; ELF SHA-256 is
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
CODE is 2,762,812 / 3,293,696 bytes (83.8818%), with 19,085 matches among
20,442 catalog spans. DATA remains 468,873 / 648,064 bytes (72.3498%). The
next fixed CODE checkpoint remains 2,772,187 bytes, 9,375 bytes away.


## Owner-relative velocity setup (+340 CODE bytes)

Recovered func_00195D30, a complete 340-byte function compiled with
Metrowerks 3.0.3, -O3,p and small-data threshold zero. Its retail pointer is
at 0x004BF578; the native GP-relative consumer is func_00195F40. Four bytes
before the entry remain uncredited alignment. The neighboring func_00195D10
uses the different pair at 0x004BF570 and is unchanged.

The handler advances subphase and accepts only selectors below four. It calls
the real no-input func_00197600, copies owner facing and position, computes
velocity from signed table coordinates with the native floating-point order,
and selects a random frame from the low two bits. The table consists of four
six-byte rows at 0x00449FC0; signed X/Y columns and the signed depth byte are
accessed through their native aliases. These aliases add no DATA credit.
The phase consumer now explicitly forwards actor and owner to both entries.
The helper's declaration retains its real zero-input contract.

Tests cover all four rows, every invalid byte selector, zero/positive/negative
facing, helper order and all low random bits. They compare every actor byte;
wrong owner forwarding and a widened random mask both fail. All 175 tests,
catalog/build/source checks and complete compiler objects pass. The complete
loaded image and packed ELF remain retail-exact, with ELF SHA-256
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
CODE is 2,763,152 / 3,293,696 bytes (83.8921%); 19,086 matches are recorded
among 20,443 catalog spans. DATA remains 468,873 / 648,064 bytes (72.3498%).
The next fixed CODE checkpoint is unchanged at 2,772,187 bytes, 9,035 bytes
away. Decompilation remains incomplete.


## Mirrored owner offsets and native address-derived depth (+412 CODE bytes)

Recovered func_00195490, all 412 bytes, with Metrowerks 3.0.3 at -O3,p and
small-data threshold zero. Its real pointer at 0x004BF560 is selected by
func_00195990. The separate func_00195470 uses 0x004BF558 and is unchanged.
The four-byte gap before the new function remains uncredited alignment.

The handler copies owner facing and position, applies mirrored horizontal
and vertical table offsets, and selects an animation frame from random low
two bits. Its table selector is produced by func_00194A20's eight-iteration
construction loop and stored at actor byte 0x21. The eight rows at 0x0044A270
have six-byte stride. Column aliases add no DATA credit.

Preserved an unusual native operation: at 0x001955F8 the row address is
computed, and the delay slot at 0x00195600 stores its low byte into actor
field 0x31. There is no intervening row-content load. The source therefore
stores the low byte of the row address, rather than substituting the signed
third column. The actual phase dispatcher now forwards both actor and owner.

Tests cover all eight native rows, both facing directions, signed facing,
subphase rollover and random frame selection. An aligned host fixture retains
the retail table's low address byte so the resulting depth bytes are checked
explicitly. Replacing the address byte with table contents or forwarding the
wrong owner fails. All 178 tests, build/catalog/source checks and whole
compiler objects pass; the linked image and executable remain retail-exact.
ELF SHA-256 remains
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
CODE is 2,763,564 / 3,293,696 bytes (83.9046%), with 19,087 matches among
20,444 catalog spans. DATA remains 468,873 / 648,064 bytes (72.3498%). The
next fixed CODE checkpoint remains 2,772,187 bytes, 8,623 bytes away.
