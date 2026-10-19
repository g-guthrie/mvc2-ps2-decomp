# Source-safe data integration package

This package is an integration plan, not a claim that the data units are
complete. It substitutes nine compiled source units in the hybrid linker only
after each unit passes a private-ROM verifier.

Included units:

- nine all-zero initialized C ranges (88,472 bytes total); and
- symbolic dispatch/jump tables reconstructed as compiled C.

The 12 unaligned zero ranges from `zero_initialized_regions.csv` are
intentionally absent: they presently require assembly `.space` placement and
must not receive C/data completion credit.

## Integration steps

1. Copy `src/data/`, `config/data_units.csv`, `config/data_matches.csv`, and the tools into the
   project. Add `src/data` to the source tree; no private ROM, object, or
   toolchain file is part of this package.
2. Add `tools/compile_matching_data.sh`, then invoke it at the end of
   `tools/compile_matching.sh`. It compiles every listed data C file with the
   established MWCCPS2 configuration and `-O3 -sdatathreshold 0`, resolves the
   public dispatch header with `-i src/data`, generates the source-derived
   symbol map, and runs every private unit check.
3. Run `verify_data_object.py` once for every `data_units.csv` row against the
   user-owned `private/SLUS_204.86.rom`. The verifier resolves only symbolic
   MIPS `R_MIPS_32` table relocations, and then compares the resulting unit to
   the private image.
4. Replace `tools/generate_hybrid_relink.py` with the supplied version. It
   rejects replacement overlap, validates each compiled data object is exactly
   one named source symbol/section, and inserts that actual object section at
   its retail address between raw chunks. It does not emit target data bytes.
5. Run `make hybrid`, `make pack-elf`, and the complete test suite. The full
   loaded-image and retail-ELF comparisons remain the final exactness gate.
6. Replace `tools/objdiff_report.py` with the supplied version. It grants data
   credit only for `data_matches.csv` rows whose catalog ranges are exact. The
   included post-gate records total 88,472 zero bytes plus dispatch and jump tables.
   Do not credit any assembly-only zero range.

## Tests

Run from the target repository after copying the package:

```sh
PYTHONPATH=. python3 -m unittest tests/test_data_integration.py
```

The test suite checks catalog scope, source-derived dispatch labels, metadata,
and collision rejection. The private-object verifier is intentionally a
separate local gate because it requires the user-owned image.

### Runtime entry records at 00489818

The runtime entry pool has sixteen slots with a 0x438-byte stride. Each slot
contains a 0x38-byte control prefix and sixteen 0x40-byte inner records.
`0040D118` scans all sixteen slots; `0040D6A0` clears the complete 0x4380-byte
pool; `0040CBD0` uses the same bounds and stride to find a free slot.

The inner layout is shared in `src/runtime_entry_table.h`. The searches
`0040D398`, `0040D300`, and `0040D268` inspect sixteen keys at record offset
0 and respectively return the value at +0x3C, the word at +0x38, and the name
at +4. `0040D738` passes that name to the open helper, reads the three integer
arguments at +0x2C/+0x30/+0x34, and writes +0x38 and +0x3C. The inline name
occupies the region from +4 to the first argument at +0x2C. The argument
names describe their observed uses, without asserting unknown writer behavior.

Only the sixteen 0x400-byte record arrays are reconstructed data: 16,384
bytes in total. Every 0x38-byte outer prefix and the four leading bytes
remain separate placeholders. All thirty-three replacement data objects
match their complete retail spans, and the five changed code units match
with their original compiler profiles. A negative control setting the first
record key to one is rejected by `verify_data_object.py`.

### Bounded handler and animation tables

The Sony handler registration guard in `sony29_handler_registration.c`
accepts indices 1 through 13. These thirteen `void (*)(void)` entries at
00438664–00438698 contribute 52 reconstructed bytes. The preceding four
bytes and trailing eight bytes retain placeholder status.

The first 256 bytes at 0044A410 contain 32 eight-byte animation samples:
two signed halfwords, one signed byte, one implicit alignment byte, and a
final signed halfword. `00198B50` advances its selector with `(old + 4) &
0x7C` and multiplies that selector by two, bounding every read to one of
these 32 records. Its four aliases select offsets 0, 2, 4, and 6. The
alignment byte at offset 5 is zero in every retail sample; the next 256
bytes remain an uncredited raw placeholder.

The 448-byte command table at 0044C890 contains 56 records with four byte
fields followed by a signed record stride. `001C1CA0` reads those fields and
advances its record pointer by that stride. The actual entry roots in g7.c
and v8_a.c select records 0 and 14. The first path visits 0–13 and loops to
0; the second visits 14–55 and then cycles over 42–55. Independently walking
the retail strides confirms both paths remain within their ranges and their
union visits all 56 records. This supports the entire 448-byte typed object.
All changed data objects and their code consumers were compiled and checked
over their complete spans.

### Object state callback tables at 00440240–00440348

The four six-entry tables at 00440240, 00440260, 00440280, and 00440330
contain unary object callbacks. Their actual consumers are 0013A9D0,
0013ABD0, 0013ADA0, and 0013B4A0; each forwards the object in A0. The
0013ADA0 consumer follows the extra context pointer before reading the
selector. The shared AA00/ADD0 callbacks copy the signed state byte, and
ADD0 also copies the three-float vector. ABC0 and B5E0 tail-call the
unary object-pool unlink routine 003DAA40. Their old generic four-argument
source wrappers were corrected before assigning typed table credit.

All four complete 24-byte data objects match after symbolic relocation.
The complete affected w1911_s, g8, and tail_leaves code objects were also
recompiled and verified. Only these 96 table bytes are promoted here;
alignment gaps and adjacent ranges retain their existing classifications.
