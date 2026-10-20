# Camera and selected character position records

## Bounded selector proof for the position rows

`func_00136D50` calls `func_00136DA0` with the fixed loop values 0 through 58 (`g12f.c`; native 00136D50..00136D84). `func_00136DA0` returns before allocating for values 24, 25, and 26 (native 00136DB0..00136DC4). For each allocated object it stores the original loop value in `+0x21` and derives `+7` from `D_004B1220`/`D_004B1221` and the byte map at `D_0043F960` (native 00136E48..00136E78).

The exact loaded bytes of the 24 pairs at 0x004B1220 and 32 pairs at 0x004B1256, combined with the exact 0x0043F960 lookup bytes, yield 56 unique `+7` values: 0..23 and 27..58. The lookup's 0x0043F960-relative offsets are 1..62; offset 0 and all gaps (7, 8, 15, 48, 55, 56) are never selected. The selector calculation was independently replayed directly from the loaded image.

The creator writes `+7` once, at 00136E78. In the entire callback region reached through `jtbl_0043F940`, later code only reads `+7`; it does not change it. The only other indexed consumers of the same position rows are the callback's own fixed `+7 * 12` reads. Therefore rows 0..23 and 27..58 are the complete reachable set. Rows 24..26 are the existing all-`-1` sentinel block and remain uncredited; the all-zero trailing 12 bytes at 0x0043F484..0x0043F48F remain raw because no selector reaches row 59.

All three position components have native read evidence for every reachable row:

- 00136DA0 loads X, Y, and Z from the `+7 * 12` row at 00136FB4, 00137018, and 00137078 during creation.
- 00137200 reads X/Y from `D_0043F1C0` and `D_0043F1C4`, then reads Z from `D_0043F1C8`, all with the same `+7 * 12` offset.
- 001372B0 loads all three fields from `D_0043F1C0 + +7 * 12` at 001372F8..00137300.

The source aliases `D_0043F1C0`, `D_0043F1C4` (base +4), and `D_0043F1C8` (base +8) are retained in the symbol map. The 56 selected rows are represented as two exact contiguous objects because sentinel rows 24..26 occupy their own 36-byte interval: 24 V3 rows at 0x0043F1C0..0x0043F2DF, then 32 V3 rows (global selectors 27..58) at 0x0043F304..0x0043F483.

## Camera vector

`func_00136C80` is already complete C (`create_scene_resource_event_00136C80.c`, matches catalog 0x80 bytes). It has one fixed reference to `D_0043F1A8` and native loads all three floats at 00136CD0, 00136CD4, and 00136CD8, copying them into actor position. There are no other code/source references to this base. The 12-byte `Position3 D_0043F1A8` preserves the existing symbol name. The following 12 bytes at 1B4..1BF remain raw; the next table base is 1C0.

## Interval ownership

`config/data_units.csv` and `config/data_matches.csv` describe all intervals from 1A0 through 490. Existing raw bytes at 1A0..1A7, 1B4..1BF, the sentinel block 2E0..303, and tail 484..48F stay placeholders. The typed objects add 684 directly selected bytes (12-byte camera + 672 bytes of 56 V3 rows). No credit is claimed for sentinel rows or the trailing zero row.

## Consumer types and verification

The first typed array has 24 records, and the second has 32. The three
unselected sentinel rows between them retain placeholder status. Consumers
must therefore use the target's flat 32-bit address model to select the actual
record, rather than indexing beyond the first C array. Both credited consumers
now compute the native integer address and convert that address to the selected
record or component pointer. The base array extent is explicitly 24; the X/Y/Z
component aliases denote scalar field addresses. The proven selector set means
every dereferenced address belongs to one of the two typed arrays, with no
sentinel or trailing-padding access. This representation depends on the PS2
address model and the repository's fixed linker placement.

Both complete consumer translation units were independently recompiled with
MWCCPS2 3.0.3 `-O3 -sdatathreshold 0`. All 13 catalogued functions in `v10_a.c`
and the complete 176-byte `func_00137200` match. All seven data objects were
independently compiled with the production data profile and verified over
their entire spans, including raw prefixes, gaps, sentinels and trailing bytes.
No matching-code credit is added by these consumer changes.

The existing 12-byte gap at 0043F304..0043F30F is incorporated into the second
active table. The intervals now tile 0043F1A0..0043F48F without overlap or
unclaimed bytes. Unread bytes retain placeholder status. Only the retired raw
unit name is removed from the generated data symbol map; native address aliases
remain unchanged.

A fresh split also checks the completed helper binding change: the signed and
unsigned conversion names intentionally alias their corresponding function
labels. Both unsigned labels carry the duplicate-address annotation required
by the splitter.

Fresh split, full linkage, packed ELF identity, catalog validation and all
91 tests pass. The loaded image SHA-256 remains
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`;
the packed ELF remains
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
The other 13,749 cached source/object pairs and all 37 headers are unchanged.
Matching data increases from 195,398 to 196,082 / 648,064 bytes (30.2566%).
Code remains 2,034,192 / 3,293,696 bytes (61.7602%).
