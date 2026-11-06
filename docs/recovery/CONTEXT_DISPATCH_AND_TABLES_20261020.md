# Context-value dispatch and bounded switch tables

`003299F0` adds 196 bytes of complete C. Depending on a global mode flag and a
signed context byte, it either mirrors one selected pair of halfwords into four
small-data globals or copies the two independent pairs. It then dispatches using
the context's signed byte at offset 3. The existing tail entry `003D2CA0` now
calls the recovered no-argument interface directly.

The discarded draft confused GP-relative offsets with absolute symbol addresses:
for example, the load encoded with offset B5D0 accesses `004C2840` using the
native GP, rather than `004CB5D0`. The corrected source uses the real symbolic
bindings, explicit small-data addressing, signed byte views, and the native
0x5B8 record stride. Address arithmetic uses the target's 32-bit unsigned address
representation; it does not treat separate scalar symbols as a C array.

MWCCPS2 3.0.3 O4,p/G0 reproduces all 49 instructions and relocations. The final
call reads the existing raw callback-address table; that table and the BSS
fields receive no reconstructed-data credit from this code recovery. All 641
functions in the existing tail unit also pass after the interface correction.

Five independently bounded switch tables add 588 reconstructed data bytes:

| Table | Entries / bytes | Native owner and bound |
| --- | --- | --- |
| 004B5390 | 38 / 152 | 00170170; unsigned selector <0x26 |
| 004B7070 | 32 / 128 | 001E74C0; unsigned selector <0x20 |
| 004AD2C0 | 29 / 116 | 0012E780; unsigned selector <0x1D |
| 004AB130 | 25 / 100 | 001076E0; normalized selector v0-2 <0x19 |
| 004B87C0 | 23 / 92 | 003CAB20; unsigned selector <0x17 |

Each bound precedes the scaled load and indirect jump. All 147 native entries,
95 distinct interior labels, containing-function ranges, and occurrence counts
were independently checked. The typed sources use addresses of code bytes,
with registered interior labels rather than C function declarations. Every
neighboring gap remains unchanged and uncredited. Their owning routines gain
no C credit from these tables. All five complete compiled-data objects match
under the existing MWCCPS2 O3/G0 recipe.

The full provenance audit found an obsolete allowlist row: `00163F90` is an
already reconstructed independent 32-byte callback, rather than a block inside
`00163F40`. Its function, inventory, match record, and 27 table references now
use `func_00163F90`; the stale interior-label exception is removed. The callback
and 1,024-byte table still reproduce their exact bytes. The surrounding 44-byte
dispatcher now explicitly returns the integer result used by its existing
caller, also without changing any native instruction or progress credit.

The regression suite validates all current label owners and all registered
consumer occurrence counts. It reproduces the previous stale range failure,
accepts legitimate casts to the declared table element type, and rejects
cast data pointers and numeric addresses. Both `make test` and report CI now
run these provenance tests alongside the command-stream tests.

Final verification: the loaded image and packed ELF remain byte-identical to retail; all 95 tests pass, including the repository-wide label regression. The callback naming and return-interface repairs add no matching credit.
