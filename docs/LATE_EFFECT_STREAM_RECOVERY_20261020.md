# Late effect command streams

The 0x004A9F70–0x004AA980 span contains 21 command programs: 19 inputs referenced by existing C callbacks and two additional inputs selected by native `func_00421C00`. Retail instructions at 0x00421C2C/30 and 0x00421C64/68 form pointers to 0x004AA160 and 0x004AA240; the calls at 0x00421C44 and 0x00421C7C pass them to `func_004220B0`. Each branch also patches a byte within its selected program from the signed runtime byte at 0x004D17CC plus 17. These are mutable programs, not arbitrary constant blobs.

The parser grammar follows native `func_00422150`. Each input is bounded by the next independently referenced input. The final boundary is the separately referenced `gPs2SystemText_004AA980` string (`rom0:ROMVER`), used by the existing ROM-version reader. Old zero-run splits at 0x004AA150 and 0x004AA5C0 fall inside programs: their first byte is a consumed terminator; the following 15 bytes remain raw.

Across the 2,576-byte span, 2,129 bytes have native read semantics and receive reconstructed-data credit. The 186 skipped payload bytes and 261 bytes between programs remain raw placeholders. The 180 replacement objects cover the complete span and independently verify against the retail image with the normal data verifier. No parser code receives new matching credit.

Reproduce the compact per-input receipt with:

```sh
python tools/report_effect_timeline_late_family.py --rom private/SLUS_204.86.rom --output /tmp/late-effect-streams.csv
cmp docs/effect_timeline_late_family_receipt.csv /tmp/late-effect-streams.csv
```

The root inventory is source/native evidence for this bounded family, rather than a claim that every runtime parser input has been found.
