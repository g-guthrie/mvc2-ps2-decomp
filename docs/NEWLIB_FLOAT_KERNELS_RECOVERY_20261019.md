# Remaining sizeable Newlib float kernels

Three complete kernels match 2,032 native code bytes:

| Function | Routine | Bytes | Complete readonly span |
| --- | --- | ---: | --- |
| 001132D0 | logf | 736 | 004ABB30, 48 bytes |
| 00115E18 | kernel_tanf | 644 | 004AC158, 68 bytes |
| 00116CD0 | atanf | 652 | 004AC290, 84 bytes |

The sources preserve the original algorithms and Sun permission notices from Newlib commit `ffbf3c2fe5af89ba84aad3359964ead31121b7ad`, `libm/math/ef_log.c`, `kf_tan.c` and `sf_atan.c`. Original constants and tables remain unchanged. Each complete readonly section matches uniquely in the retail image and passes the standard readonly verifier before whole-function relocation; the pools remain uncredited data.

All use SNCPP, EE GCC 2.96 `-O2 -G0 -ffunction-sections` with no extra compiler flags, and SNAS `-mips4 -G0`. The float format uses the genuine `_FLT_NO_DENORMALS` and `_FLT_LARGEST_EXPONENT_IS_NORMAL` configuration. Generated assembly is never edited. Logf and atanf take and return one float; kernel_tanf takes two floats and an integer selecting tan versus negative reciprocal.
