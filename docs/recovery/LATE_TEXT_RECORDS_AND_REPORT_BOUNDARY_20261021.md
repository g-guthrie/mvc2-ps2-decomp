# Complete late text records and the middle-family boundary

Twenty-two records from004A9F70 through004AA962 now have complete serialized
owners, bounded by their parser returns. The native callbacks materialize all
22 roots in00421B00–004220B0;364 native words in that span were checked
against retail. The three formerly native-only roots at004AA160,004AA240
and004AA7B0 also have explicit callsite evidence.

| Root | Exclusive end | Complete bytes | Prior reconstructed | New bytes | Excluded gap |
| --- | --- | ---: | ---: | ---: | ---: |
| 004A9F70 | 004A9FD5 | 101 | 93 | 8 | 11 |
| 004A9FE0 | 004AA00C | 44 | 42 | 2 | 4 |
| 004AA010 | 004AA09C | 140 | 126 | 14 | 4 |
| 004AA0A0 | 004AA0F4 | 84 | 76 | 8 | 12 |
| 004AA100 | 004AA151 | 81 | 76 | 5 | 15 |
| 004AA160 | 004AA239 | 217 | 197 | 20 | 7 |
| 004AA240 | 004AA31A | 218 | 198 | 20 | 6 |
| 004AA320 | 004AA3AC | 140 | 126 | 14 | 4 |
| 004AA3B0 | 004AA428 | 120 | 109 | 11 | 8 |
| 004AA430 | 004AA4D2 | 162 | 148 | 14 | 14 |
| 004AA4E0 | 004AA50D | 45 | 43 | 2 | 3 |
| 004AA510 | 004AA538 | 40 | 38 | 2 | 8 |
| 004AA540 | 004AA56B | 43 | 41 | 2 | 5 |
| 004AA570 | 004AA5C1 | 81 | 76 | 5 | 15 |
| 004AA5D0 | 004AA683 | 179 | 165 | 14 | 13 |
| 004AA690 | 004AA744 | 180 | 166 | 14 | 12 |
| 004AA750 | 004AA77B | 43 | 41 | 2 | 5 |
| 004AA780 | 004AA7AF | 47 | 45 | 2 | 1 |
| 004AA7B0 | 004AA7FE | 78 | 73 | 5 | 2 |
| 004AA800 | 004AA84E | 78 | 73 | 5 | 2 |
| 004AA850 | 004AA89E | 78 | 73 | 5 | 2 |
| 004AA8A0 | 004AA962 | 194 | 177 | 17 | 30 |
| Total | | 2393 | 2202 | 191 | 183 |

The164 old fragments are replaced by22 owners. Existing2,202 reconstructed
bytes are retained once;191 cursor-consumed command operands add credit.
The183 gap bytes retain separate owners and zero credit. Glyph bytes are
native reads; skipped operands retain byte representation within complete
command records. Each complete object independently compiles and verifies
against retail under the existing production data recipe.

## Correct the middle-family report boundary

The middle-family report stopped at its old import cutoff004A9F60. The real
next callback root is004A9F70. The last record, rooted at004A9ED0, contains
its terminating byte at004A9F60 and returns with its cursor at004A9F61.
Existing native-read fragments already cover that byte, and the separate
alignment owner begins at004A9F61. The old report therefore mislabeled the
record as truncated.

The report now uses the actual next root and counts all25 middle-family
records once:2,845 native-read bytes,254 skipped operands,213 gap bytes and
zero held bytes. A regression demonstrates that the former cutoff truncates
the record, then verifies its real end and15-byte following gap. A second
regression runs the public source-backed report and verifies full coverage.

The final middle-family record is now a complete145-byte C owner as well.
Nine fragments are retired, preserving134 previously reconstructed bytes and
adding11 skipped operand bytes. Its15-byte alignment owner is unchanged.
Together with the22 late records, this batch recovers202 new data bytes across
23 complete owners (2,538 total bytes), retaining2,336 old reconstructed bytes
and excluding198 gap bytes.

All118 tests, build/catalog checks, fresh split and full-image checks passed.
The complete loaded image and packed ELF reproduce retail byte-for-byte.
All23 replacement records now receive linked credit. The cache audit verifies
14,795 unchanged pairs, two rebuilt code units,173 retired fragments and26
new source/object pairs, with all47 headers unchanged.

Including the accompanying four new code functions and restored thread-start
credit, verified totals are2,076,192 /3,293,696 code bytes (63.0353%) and
256,328 /648,064 reconstructed data bytes (39.5529%). The fixed next code
publication grid remains2,080,510;4,318 bytes remain. Extra reporting and data
checkpoints do not reset it.
