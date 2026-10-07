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
