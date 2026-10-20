# Three additional native effect inputs

Retail code independently loads three inputs into `a0`, sets `a1=0` and `a2=2`, and calls `func_004220B0`:

| Input | Pointer-forming instructions | Call | Next input |
|---|---|---|---|
| 0x004A9360 | 0x0042152C / 0x00421538 | 0x00421540 | 0x004A93D0 |
| 0x004A96B0 | 0x0042173C / 0x00421748 | 0x00421750 | 0x004A9720 |
| 0x004AA7B0 | 0x00421E7C / 0x00421E88 | 0x00421E90 | 0x004AA800 |

These previously lay within raw gaps of the source-callback inventory. The native references establish additional parser inputs. Their read fields occupy 91, 91 and 73 bytes; 8, 8 and 5 skipped bytes remain raw, as do the 13, 13 and 2-byte tails to the next independently referenced input. The preceding gaps (3, 10 and 1 bytes) remain raw as well. Across the three replaced raw owners, all 318 bytes retain unique ownership; 255 bytes receive new reconstructed-data credit.

The 25 replacement objects independently compile and verify with the normal MWCC O3/G0 data recipe. Middle-family receipts regenerated from the retail image and from reconstructed source agree. The updated late-family CSV also reproduces exactly. Generated detailed middle receipts remain private and can be regenerated with `tools/report_effect_timeline_004a9280.py --rom private/SLUS_204.86.rom --output /tmp/effect-middle.json`; omitting `--rom` reconstructs its input from source.

The middle report deliberately ends at its historical import boundary 0x004A9F60. The crossing final program is separately documented through its real next input at 0x004A9F70. An automatic catalog split is not an independent owner.
