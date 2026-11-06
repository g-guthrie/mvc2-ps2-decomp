# Runtime flag reset and owner spacing recovery

Two complete source functions add 308 verified code bytes:

| Address | Bytes | Compiler | Native behavior |
| --- | ---: | --- | --- |
| 00102A08 | 72 | Sony EE GCC 2.9-991111, O2/G0 | Call the existing reset helper, clear the runtime word at +0x20, update the flags at +0 |
| 0034C720 | 236 | MWCCPS2 3.0.3, O4/Op/G8 | Finish when sufficiently close to the target; otherwise follow the owner and select its previous animation frame |

The Sony routine uses ordinary signed 32-bit bit masks. Its native `sd` saves
are 16 bytes apart. The compiler reproduces them directly without editing its
assembly or object output; the production recipe uses the existing pinned
setup documented in `docs/COMPILER.md`.

The owner-spacing draft had the distance comparison reversed. Native code
performs an ordered floating-point `< 26.66666603088379f` test; only that path
increments the state and clears the active flag. Equality and unordered values
continue through movement. Loading the target view before the owner view in C
also preserves the native register allocation. The animation helper declaration
uses the existing provider's integer result, which this caller ignores.

Both functions pass independent complete relocated-object comparisons using
the canonical ROM and symbols. No assembly, barriers, artificial padding or
fake helper effects are used, and no reconstructed data credit is added.

Production coverage now includes 4,109 credited and verified source units.
Catalog validation and all 91 tests pass. The full hybrid link and deterministic
packer reproduce the loaded image and retail ELF respectively:

- 3,941,760 bytes, SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
- 3,942,320 bytes, SHA-256 `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.

The catalog credits 2,030,696 / 3,293,696 code bytes (61.6540%) and
195,314 / 648,064 reconstructed data bytes (30.1381%).
