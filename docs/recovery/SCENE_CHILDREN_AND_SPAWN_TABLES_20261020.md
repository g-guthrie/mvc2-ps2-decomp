# Scene child initialization and bounded spawn tables

`src/scene_angle_children_00145560.c` reconstructs the complete 544-byte
routine at 00145560. It allocates at most two child objects, installs their
callback, copies complete three-float positions, converts the configured
angles to masked phases, and sets their remaining fields. MWCCPS2
3.0.3-020716 with `-O4,p -sdatathreshold 8` produces an exact relocated match.
The negative angle uses signed conversion before unsigned masking, matching
the native signed conversion helper. The callback is exposed at its existing
address 00145780; this adds no credit for that callback.

The native constructor at 0014D7A0 bounds its loop to four iterations
(0014D8E0–0014D8F0). Its position offset starts at zero, increases by twelve,
and reads all three floats per iteration (0014D804–0014D840). Its node-index
offset starts at zero, increases by four, and selects one signed word from
004442C0 (0014D884–0014D894 or 0014D8C4–0014D8CC). An allocation failure
returns early without extending either bound. This supports the four 3D
positions at 00444290 (48 bytes) and four node indices at 004442C0 (16 bytes).
The constructor itself receives no matching-code credit in this change.

The previous raw unit at 004440F0 is partitioned into its unchanged 416-byte
prefix and these two typed tables. All three compiled data sections match
their entire native spans; the prefix retains placeholder status. Existing
data symbol bindings are preserved and only the two new table names are added.

Production coverage verifies 4,124 credited code source units. All 13,747
previous source/object pairs and 37 headers were unchanged before integration;
the modified raw unit and three new source units were compiled and verified.
A fresh split and full linkage preserve the loaded image (3,941,760 bytes,
SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`)
and packed retail ELF (3,942,320 bytes,
SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`).
All 91 tests pass. Matching code is 2,034,192 / 3,293,696 bytes (61.7602%);
reconstructed data is 195,378 / 648,064 bytes (30.1479%).
