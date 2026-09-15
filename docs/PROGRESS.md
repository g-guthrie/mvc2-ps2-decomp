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
