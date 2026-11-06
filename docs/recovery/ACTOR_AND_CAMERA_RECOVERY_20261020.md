# Actor and camera recovery

This packet adds eleven whole functions, 4,788 code bytes, with no initialized-data credit or function-boundary changes.

| Source | New functions | Bytes |
| --- | --- | ---: |
| actor_emission_cycles_001CCF60.c | 001CD7D0, 001D3F00, 001D4400, 001D0850, 001E0090 | 2,632 |
| actor_motion_preset_003BD2E0.c | 003BD2E0 | 292 |
| actor_pause_motion_003C8BD0.c | 003C8BD0 | 244 |
| actor_scene_preset_003CFA40.c | 003CFA40 | 340 |
| actor_input_history_003B5F30.c | 003B5F30 | 360 |
| initialize_camera_00122DA0.c | 00122DA0 | 568 |
| select_camera_presets_00123250.c | 00123250 | 352 |

The five lifecycle additions reuse the existing genuine 196-byte inherited-state layout. Their allocator, RNG and animation contracts agree with recovered definitions; signed-byte animation results are consumed explicitly where native code does so. The one-byte pause flag is declared in its actual BSS section, while native GP references retain their small-data declarations. No guessed array extent is used to alter addressing.

The motion preset has actual 8-byte position deltas and 16-byte velocity/acceleration records. Scene presets expose only observed signed selector and position fields. These are external data views, not claims to reconstruct the tables. The paused-motion callback uses the engine's frame index, whose native writer masks it to 0–15, making the pause-mask shift defined. The input-history callback reads and writes a real 16-entry ring; both indices wrap with a mask of 15.

The camera initializer uses the repaired unsigned-angle-to-float tangent API and natural float constants. Its speed-oriented compiler profile reproduces immediate stores without a constant-pool placement dependency. The selector uses the existing two five-entry pointer tables with their canonical const-void-pointer declaration. Six scalar float locals preserve coordinates across secondary-preset updates and are all subsequently used.

Legacy MWCCPS2 3.0, `-O4,p`, builds the actor units. The two motion callbacks with absolute references use a small-data threshold of zero; the other actor units use eight. Camera initialization uses modern MWCCPS2 3.0.3, `-O3,p`, and camera selection uses `-O3`, both with threshold zero. The existing lifecycle unit keeps its genuine loop-alignment pragma and source-header include path.

Every affected complete compilation unit is checked against the retail instructions and relocated operands. Whole-image reconstruction and executable packing establish placement; tool tests and the progress catalog remain separate checks. Private frozen receipts preserve the final source/object hashes and compiler recipes independently of subsequent work.
