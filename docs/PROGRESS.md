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
