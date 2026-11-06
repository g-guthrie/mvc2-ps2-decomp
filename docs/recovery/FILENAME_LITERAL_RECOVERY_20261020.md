# Native filename literals

Recover 983 individually bounded filename strings totaling 11,666 bytes. Every unit contains its text and terminating NUL only. The surrounding pool spans 15,720 bytes from `0x004AD338` to `0x004B10A0`; its remaining 4,054 alignment bytes receive zero credit. Two old raw integer chunks are retired, leaving unclaimed gaps as raw fallback bytes.

The 983 native pointer words at `0x0043CDA0` identify the string starts. `func_0012DF30` selects a pointer at `0x0012E07C` and passes it as the first argument to `func_003FCA60`. The file-opening path forwards it through `func_003FC9C8`, `func_00400468`, and `func_004064E8` to `func_00406688`, whose native byte loop reads until NUL or a path separator. This establishes the character-string role independently of how each file ID is selected.

The first 914 literals contain 10,949 bytes; the final 69 contain 717 bytes. Each source initializer was decoded independently, checked against the corresponding native pointer, and compared with the retail bytes through its first NUL. Literal extents do not overlap one another or other catalog owners. The last terminator ends at `0x004B1094`; the next table starts at `0x004B10A0`.

The full 983-word pointer table retains its existing extent and placeholder progress. The producer counter path and possible array terminator still require separate ownership evidence; no pointer-array bytes are credited here, and no claim is made that every selector state is valid.

All 983 final sources are independently compiled with MWCCPS2 3.0.3, -O3 -sdatathreshold 0 and relocated-object verified. Catalog validation, the test suite, hybrid placement, loaded-image identity, and packed retail ELF identity are required before linked credit is promoted.
