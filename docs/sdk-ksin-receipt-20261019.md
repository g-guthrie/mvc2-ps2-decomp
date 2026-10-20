# Newlib 1.10.0 kernel sine receipt

`src/newlib_k_sin_00115120.c` restores the complete `func_00115120` at `0x00115120`: 0x238 bytes (568 bytes). The source is `newlib/libm/math/k_sin.c` from Newlib 1.10.0 sourceware tag `newlib-1_10_0`, commit `ffbf3c2fe5af89ba84aad3359964ead31121b7ad`, blob `f119916dfbc4a8fecf599e95045233d5bf400fcc`. The source file retains the original Sun Microsystems notice and the upstream pin.

The source uses the three-argument `__kernel_sin(double x, double y, int iy)` interface. Its header adaptation follows the pinned `fdlibm.h` and `sys/config.h`: `__int32_t` is a signed 32-bit `int` and `__uint32_t` is an unsigned 32-bit `int` under the EE EABI64 build; `long` is 64-bit. The little-endian double-word union and `GET_HIGH_WORD` macro follow the Newlib header. The implementation aliases `__kernel_sin` to retail symbol `func_00115120`.

## Compiler and pool proof

The complete relocated function passes the default `tools/verify_object.py` checks against the private `SLUS_204.86.rom` with EE GCC 2.96 `-O2 -G0`, assembled by SNAS with `-G0`. The verifier reports `exact: func_00115120 (568 bytes)`.

The object emits a 0x70-byte `.rodata` section containing `half` and coefficients `S1` through `S6`. The full section matches retail at `0x004AC098`. `config/readonly_sections.csv` records this mapping so the default verifier checks all pool bytes before resolving local relocations. The pool receives no data credit; neither `config/matches.csv` nor `config/data_matches.csv` was changed.

Current C source SHA-256: `8c8e6ebed2dbf5470d75c82d0ab5e72fa342d29f0f808e6f289be1b6c25e46e0`.

The compiler wrapper writes a temporary filename into assembly metadata, so the whole object-file hash can vary between runs. The proof is the full relocated-function match plus the independently validated readonly pool.

## Reproduction

Source `private/build.env` from the private checkout. Create the temporary match list below; `config/symbol_addrs.txt` already supplies the retail address, and the readonly pool is checked from the default `config/readonly_sections.csv`.

```sh
mkdir -p build/sdk_trig
cat > build/sdk_trig/matches-ksin.csv <<'EOF'
name,address,size,source,status
func_00115120,0x00115120,0x238,src/newlib_k_sin_00115120.c,complete
EOF
"$WIBO" "$SNCPP" -P src/newlib_k_sin_00115120.c build/sdk_trig/k_sin.i
EE96CC1="$EE96CC1" "$PYTHON" tools/compile_ee96.py --small-data-threshold 0 --opt O2 --extra-flags="" build/sdk_trig/k_sin.i build/sdk_trig/k_sin.s
"$WIBO" "$SNAS" -G0 -o build/sdk_trig/k_sin.o build/sdk_trig/k_sin.s
"$PYTHON" tools/verify_object.py build/sdk_trig/k_sin.o /path/to/SLUS_204.86.rom --source src/newlib_k_sin_00115120.c
```
