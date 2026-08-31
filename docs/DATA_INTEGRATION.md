# Source-safe data integration package

This package is an integration plan, not a claim that the data units are
complete. It substitutes nine compiled source units in the hybrid linker only
after each unit passes a private-ROM verifier.

Included units:

- eight all-zero initialized C ranges (88,408 bytes total); and
- `gMvc2Dispatch_00445A20`, a 0x400-byte symbolic table of code labels.

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
   included post-gate records total 88,408 zero bytes and 1,024 dispatch bytes.
   Do not credit any assembly-only zero range.

## Tests

Run from the target repository after copying the package:

```sh
PYTHONPATH=. python3 -m unittest tests/test_data_integration.py
```

The test suite checks catalog scope, source-derived dispatch labels, metadata,
and collision rejection. The private-object verifier is intentionally a
separate local gate because it requires the user-owned image.
