# Secondary state callback entries

Six independently referenced entries were hidden inside assembly residuals after
matching state dispatchers. Each residual contained four alignment bytes followed
by a separate eight-byte function. Only the function bytes receive new credit.

| Entry | Native table reference | Native tail transfer to entry |
| --- | --- | --- |
| 00359A90 | 004C1AFC | 00359AB4 |
| 00359AE0 | 004C1B04 | 00359B04 |
| 00359B30 | 004C1B0C | 00359B54 |
| 00359B80 | 004C1B14 | 00359BA4 |
| 00359BD0 | 004C1B1C | 00359BF4 |
| 00359C20 | 004C1B24 | 00359C44 |

The existing native state dispatchers read the corresponding callback tables and
pass their byte-addressed actor pointer in A0. Five secondary entries tail-call
`00359A70` with that pointer. `00359B30` returns immediately. Ordinary C wrappers
and an empty callback reproduce their complete instructions and relocations;
there is no assembly or manual instruction padding in these implementations.

All six share `src/tail_leaves.c` and its existing MWCCPS2 3.0.3 `-O3
-sdatathreshold 0` recipe. All 635 functions in that compilation unit pass whole
function verification. Splitting the six residuals preserves their exact combined
extents and all four-byte alignment prefixes; the code-byte denominator is
unchanged. This adds 48 matching code bytes and six functions.

Validation: a fresh split succeeded, both the full loaded image and packed ELF
match retail exactly, and all 91 tests pass. All 14,049 other cached
source/object pairs, 45 headers, and the production script are unchanged.
