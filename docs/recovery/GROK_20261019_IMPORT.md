# Grok integration checkpoint, 2026-10-19

Imported verified work from [Grok's b40ac496 commit](https://github.com/g-guthrie/mvc2-ps2-decomp/commit/b40ac4968decd2bdaf157d05afc0537baca2ce5f), preserving the current source, function-boundary fixes, and reconstructed data.

The combined catalog contains **1,843,768 / 3,293,696 matching code bytes (55.9787%)** and **174,369 / 648,064 reconstructed data bytes (26.9061%)**. This checkpoint includes all pending verified local recoveries and 587 genuinely new Grok functions (110,124 bytes) in 582 translation units.

[GROK_20261019_IMPORT.csv](GROK_20261019_IMPORT.csv) accounts for all 934 match rows introduced by Grok: 587 imported, 258 already covered by the current sources, 55 held for artificial inline-assembly NOP padding (54) or an algorithmic VU assembly loop (1), and 34 held because they did not match the tested compiler profiles. Unaccepted candidate sources remain recoverable in the original Grok commit; they receive no new C credit.

Integration corrections:

- Canonicalized recovered `residual_` functions to `func_` names and retained current canonical sources for duplicate spans.
- Split verified entries from preceding alignment bytes or native dispatch prefixes. Preserved nonzero prefixes, and resolved the three 00384030 / 003D6AF0 / 003D90A0 ownership exceptions from native flow and entry references.
- Normalized malformed compiler wrappers, added explicit compile/verify pairs for every imported source, and supplied factual relocation labels without changing the existing compiler-helper mapping.
- Replaced three synthetic volatile action-byte self-stores with checked actor-field views. Two offset buffers now have an explicitly aligned eight-byte payload matching the helper's two reads.
- Corrected known frame/action helper return declarations, preserved explicit signed-byte result tests, and modeled 003D90A0's returned dispatch result. Corrected the existing 001830D0 offset parameter to a pointer.
- Retained current data matches and boundary fixes instead of restoring older catalog entries from the input branch.

Validation of the final versions:

- Recompiled all 582 imported translation units using their production recipes and verified complete symbol sizes and every relocated byte against the private retail image.
- Independently replayed the affected local translation units; all 53 tests pass.
- Catalog validation, shell syntax, and build coverage pass: 3,668 sources are both credited and wired for verification; no unregistered function bodies.
- The complete 3,941,760-byte hybrid image is identical to retail: SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
- The packed 3,942,320-byte retail ELF is identical: SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.

Use the existing private toolchain environment, run `tools/compile_matching.sh`, then `make report`, `make test`, `tools/relink_hybrid.sh`, and `tools/pack_hybrid_elf.sh` with the project's virtual-environment Python. Private build inputs and executables are not part of this import.

Required CPU primitives remain allowed under [DECOMP.md](../DECOMP.md); these historical holds concern padding or algorithmic assembly. Later compiler-only recoveries are recorded separately from this original-import ledger.
