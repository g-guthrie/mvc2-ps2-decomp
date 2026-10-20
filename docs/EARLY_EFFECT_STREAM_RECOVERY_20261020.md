# Early effect command streams

Five inputs referenced by existing callbacks occupy 0x004A8F80–0x004A9280. Their roots are 0x004A8F80, 0x004A9000, 0x004A9060, 0x004A9120 and 0x004A91E0; each is bounded by the next callback input, including the separately referenced 0x004A9280 input at the final boundary.

The 768-byte span contains 646 native-read bytes, 58 skipped payload bytes and 64 bytes between programs. Only native-read fields receive reconstructed credit. The terminator at 0x004A9050 is part of the 0x004A9000 program; the remaining zero tail stays raw. The final program ends at 0x004A9270 and leaves its tail raw to the next root. Prior automatic zero-run boundaries do not establish independent owners.

All 52 replacement objects compile and verify against the retail image. Reproduce the compact receipt with `tools/report_effect_timeline_early_family.py --rom private/SLUS_204.86.rom --output /tmp/early-effect-streams.csv`, then compare it with `docs/effect_timeline_early_family_receipt.csv`. The shared grammar follows native `func_00422150`; this adds data credit, not matching parser code.
