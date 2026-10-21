# Complete callback text records at004A9280–004A9EC4

Twenty-four records now have complete serialized C owners, bounded by their
actual count1 parser return points. Their headers, control operands, native
glyph runs and terminators are represented explicitly. As in the early
family, parser-skipped command operands retain byte representation inside a
proven complete record, without claiming an integer or padding meaning.

| Root | Exclusive end | Complete bytes | Prior reconstructed | New bytes | Excluded gap |
| --- | --- | ---: | ---: | ---: | ---: |
| 004A9280 | 004A9322 | 162 | 148 | 14 | 14 |
| 004A9330 | 004A935D | 45 | 43 | 2 | 3 |
| 004A9360 | 004A93C3 | 99 | 91 | 8 | 13 |
| 004A93D0 | 004A9467 | 151 | 140 | 11 | 9 |
| 004A9470 | 004A9498 | 40 | 38 | 2 | 8 |
| 004A94A0 | 004A9525 | 133 | 122 | 11 | 11 |
| 004A9530 | 004A95AA | 122 | 111 | 11 | 6 |
| 004A95B0 | 004A95DB | 43 | 41 | 2 | 5 |
| 004A95E0 | 004A96A6 | 198 | 181 | 17 | 10 |
| 004A96B0 | 004A9713 | 99 | 91 | 8 | 13 |
| 004A9720 | 004A9748 | 40 | 38 | 2 | 8 |
| 004A9750 | 004A97DF | 143 | 132 | 11 | 1 |
| 004A97E0 | 004A980B | 43 | 41 | 2 | 5 |
| 004A9810 | 004A988D | 125 | 114 | 11 | 3 |
| 004A9890 | 004A98DE | 78 | 73 | 5 | 2 |
| 004A98E0 | 004A9985 | 165 | 151 | 14 | 11 |
| 004A9990 | 004A9A37 | 167 | 153 | 14 | 9 |
| 004A9A40 | 004A9AE7 | 167 | 153 | 14 | 9 |
| 004A9AF0 | 004A9B99 | 169 | 155 | 14 | 7 |
| 004A9BA0 | 004A9C43 | 163 | 149 | 14 | 13 |
| 004A9C50 | 004A9D25 | 213 | 193 | 20 | 11 |
| 004A9D30 | 004A9E06 | 214 | 194 | 20 | 10 |
| 004A9E10 | 004A9E6B | 91 | 83 | 8 | 5 |
| 004A9E70 | 004A9EC4 | 84 | 76 | 8 | 12 |
| Total | | 2954 | 2711 | 243 | 198 |

The202 old fragment owners are retired; their2,711 reconstructed bytes are
preserved once. Only243 command-operand bytes add reconstruction credit.
All198 inter-root gap bytes retain their existing separate owners and zero
credit. The004A9ED0 record was initially held at the old report import boundary.
A later native/parser check established its actual terminator and corrected
that boundary; see LATE_TEXT_RECORDS_AND_REPORT_BOUNDARY_20261021.md.

The native callback span004214E0–00421B60 was checked word-for-word against
retail (416 words), including materialization of all24 record addresses.
Parser cursor traces prove each complete span. Each replacement was separately
compiled under the production MWCCPS2 recipe and verified against retail.
All116 tests, catalog/build coverage, fresh split and full-image linkage
passed. The hybrid loaded image and packed ELF reproduce retail byte-for-byte.
The24 replacement records now receive linked credit. The cache audit pins
14,946 unchanged source/object pairs and47 unchanged headers;202 old fragment
pairs are retired and24 new owners are added.

Verified totals: code2,074,996 /3,293,696 bytes (62.9990%), data256,126
/648,064 bytes (39.5217%). The fixed next code grid remains2,080,510,
with5,514 bytes remaining. Extra data checkpoints do not reset that grid.
