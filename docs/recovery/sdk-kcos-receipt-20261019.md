# Newlib 1.10.0 kernel cosine receipt

`src/newlib_k_cos_001142F8.c` recovers the complete `func_001142F8` span at `0x001142F8`: 0x2D4 bytes (724 bytes). The source is the Newlib 1.10.0 `newlib/libm/math/k_cos.c` from sourceware tag `newlib-1_10_0`, commit `ffbf3c2fe5af89ba84aad3359964ead31121b7ad`, blob `6c60c243856e5e65df87ca45c4efd8bd1e6ce745`. Its original Sun Microsystems permission notice remains in the source.

The header excerpt follows the same pinned Newlib `fdlibm.h` and `sys/config.h` definitions. EE uses 32-bit `int` for `__int32_t` and `__uint32_t`; `long` is 64-bit under its EABI64 build, so the source uses `int` for the fdlibm word types. The little-endian `ieee_double_shape_type`, `GET_HIGH_WORD`, and `INSERT_WORDS` definitions match the pinned header. The function name aliases to the retail symbol `func_001142F8`.

## Compiler and pool proof

The complete body passes `tools/verify_object.py` against the private `SLUS_204.86.rom` with EE GCC 2.96 `-O2 -G0`, assembled by SNAS with `-G0`. The verifier reports `exact: func_001142F8 (724 bytes)` after relocation. This full-span result is the code proof; the whole object-file hash is only an artifact identifier.

The compiler emits one 0x68-byte `.rodata` section. Its full content matches retail at `0x004ABFC0`. `config/readonly_sections.csv` records this whole-section mapping so the default verifier validates every pool byte before resolving local relocations. The pool receives no data credit and no row is added to `config/data_matches.csv`. The function is registered in the production code catalog.

Current C source SHA-256: `1d9e48e708ea85be4bc4a50dbaf5af74daf064db6c3b3ebf4ad427d4ad9d0662`.

Assembled ELF SHA-256: `c26eaf4795a2f62d6c8fdb8db82f619444ff32c9a7c567a36591f2f0eda9aa61`.

## Reproduction

Source `private/build.env` from the private checkout. The production catalog contains the complete function entry; the default `config/symbol_addrs.txt` supplies its retail address. The readonly section is read from the default `config/readonly_sections.csv`.

```sh
mkdir -p build/sdk_callers
"$WIBO" "$SNCPP" -P src/newlib_k_cos_001142F8.c build/sdk_callers/k_cos.i
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" build/sdk_callers/k_cos.i build/sdk_callers/k_cos.s
"$WIBO" "$SNAS" -G0 -o build/sdk_callers/k_cos.o build/sdk_callers/k_cos.s
"$PYTHON" tools/verify_object.py build/sdk_callers/k_cos.o /path/to/SLUS_204.86.rom --source src/newlib_k_cos_001142F8.c
```
