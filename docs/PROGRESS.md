# Progress stats (decomp.dev)

objdiff v2 field meanings, as decomp.dev displays them:

| decomp.dev | objdiff field | Meaning here |
|---|---|---|
| decompiled | `matched_code_percent` | Exact matching C vs retail `.text` |
| fully linked | `complete_code_percent` | That matching C is **placed by the hybrid linker** |
| data bar | `matched_data_percent` / `complete_data_percent` | Exact matching initialized data in `0x00424200..0x004C2580` |

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

Keep the new range disjoint from every existing `data_units.csv` row. If it sits inside a fill, punch the fill first (shrink/split the `data_u32_*` / `data_zero_*` unit) instead of stacking. Then run:

```sh
PYTHONPATH=. python3 -m tools.validate_progress_catalog
PYTHONPATH=. python3 -m tools.objdiff_report --svg assets/progress.svg
```
