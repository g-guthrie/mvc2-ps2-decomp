# Complete early effect-text streams

Four independently rooted records now have complete serialized C owners.
The native callbacks at00421410,00421430 and004214A0 supply their actual
roots to004220B0, which reads the record count and calls00422150. Each
record has count1; the parser's cursor and terminating command establish its
end without consuming the following inter-root gap.

| Start | Exclusive parser end | Complete bytes | Prior reconstructed | Newly reconstructed | Excluded following gap |
| --- | --- | ---: | ---: | ---: | ---: |
| 004A9000 | 004A9051 | 81 | 76 | 5 | 15 |
| 004A9060 | 004A9113 | 179 | 165 | 14 | 13 |
| 004A9120 | 004A91D4 | 180 | 166 | 14 | 12 |
| 004A91E0 | 004A9270 | 144 | 130 | 14 | 16 |
| Total | | 584 | 537 | 47 | 56 |

The C owners express record headers, command opcodes, big-endian parameter
bytes, glyph runs and terminators. Preamble command0C advances over two
operand bytes without loading them. Body command01 reads two parameter bytes
and advances over another three bytes. These skipped operands now belong to
proven complete command records; they retain byte representation without an
invented integer interpretation. Glyph arrays contain actual native-read
codes and stop at control commands.

Thirty-eight old field and opaque-payload fragments are replaced by four
complete owners. The537 previously reconstructed bytes are preserved once;
only47 command-operand bytes add credit. All56 gap bytes retain their existing
separate owners and zero reconstruction credit. The earlier004A8F80 recovery
is already banked separately and is excluded from these totals.

Independent production compilation verifies each complete object against
retail. Native evidence is checked word-for-word against the reference image
for the three callbacks and both parser functions. All116 tests, catalog/build coverage and fresh full-image checks passed.
Both the hybrid loaded image and packed ELF reproduce retail byte-for-byte.
The replacement rows now receive linked credit. The cache audit verified
15,144 unchanged source/object pairs and47 unchanged headers;38 old pairs
were retired and four whole owners added.

Verified local totals are2,074,996 /3,293,696 code bytes (62.9990%) and
255,883 /648,064 reconstructed data bytes (39.4842%). Code is unchanged by
this data recovery. The fixed next publication grid remains2,080,510 code
bytes, with5,514 bytes remaining.
