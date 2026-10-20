# ADXT Provider ABI Repairs

The exact `func_00401640` recovery depends on two existing helper providers. Native call registers and the provider bodies show pointer-valued ADXT/SJ arguments, so the old `s32` and unspecified-argument declarations obscured the true interfaces.

`func_003FF5D0` receives A0 as its decoder object and A1 as an SJ pointer. Its native body stores A1 into the decoder's third word, loads the decoder's second word, and tail-calls `func_003F64A0`. The provider now declares `(void *object, void *sj)` and uses a local decoder prefix with a pointer reference at `+0x04` and input SJ at `+0x08`. `func_003F64A0` already has the matching reference-object pointer type (`S64 *`). This keeps the native 32-bit word layout while representing the second argument and stored field as pointers.

`func_003FF628` takes an opaque ADXSJD handle, invokes the reset helper at `func_003FF3B0`, then sets the status byte at `+0x01`. Its provider now uses the public handle shape (`typedef void *ADXSJD`) and an explicit pointer prototype. The `func_003FF3B0` definition and all known callers use the same opaque-pointer ABI; the definition casts locally to its concrete `S3B` layout before clearing fields.

The internal call signatures in `func_00401640` are therefore consistent with the providers: `(void *decoder, void *sj)` for `func_003FF5D0`, and `(void *decoder)` for `func_003FF628`. No inline assembly or forced clobbers were added.

## Literal-profile verification

All changed and affected translation units were recompiled and matched against the retail ROM:

| Translation unit | Profile | Result |
| --- | --- | --- |
| `src/s4.c` | EE GCC 2.96, `-O2 -G0`, SN assembler | All 11 matched functions exact |
| `src/p2.c` | EE GCC 2.96, `-O2 -G0`, SN assembler | All 9 matched functions exact |
| `src/k5.c` | EE GCC 2.96, `-O2 -G0`, SN assembler | All 9 matched functions exact |
| `src/create_stream_group_003FF3E8.c` | EE GCC 2.96, `-O2 -G0 -fno-strength-reduce`, SN assembler | Function exact |
| `src/adxt_start_sj_00401640.c` | EE GCC 2.96, `-O2 -G8`, SN assembler `-mips4` | `func_00401640` exact, 196 bytes |

The ADX Talk public header describes ADXSJD as an opaque handle and declares start functions with pointer-sized handles. The concrete `S3B` reset layout remains local to its provider CU.
