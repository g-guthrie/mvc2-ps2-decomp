# Newlib float atan2 and pow recovery

The complete `atan2f` kernel at 001130F0 (480 bytes) and `powf` kernel at 00113698 (2,016 bytes) match 2,496 native code bytes. The sources retain the genuine algorithms and Sun permission notices from Newlib commit `ffbf3c2fe5af89ba84aad3359964ead31121b7ad`, `libm/math/ef_atan2.c` and `ef_pow.c`.

Both use the original fdlibm `_FLT_NO_DENORMALS` and `_FLT_LARGEST_EXPONENT_IS_NORMAL` configuration supported by the native float representation. Compile with SNCPP and EE GCC 2.96 `-O2 -G0 -ffunction-sections`, with no extra compiler flags, then assemble with SNAS `-mips4 -G0`. Generated assembly is never modified.

The atan2 kernel has two float arguments, forwards the y value to `atanf` when x is 1, and uses the existing float absolute-value routine. Its original scalar constants are typed value macros; no constant's address is used, and the final object has no data or readonly payload.

The pow kernel uses the existing float sqrt, absolute-value and scalbn routines with their actual typed interfaces. Its entire 136-byte readonly section matches retail at 004ABB78. This includes the original lookup arrays, scalar bindings and compiler constants. Standard readonly-section verification must validate the complete section before relocating and comparing the whole function. The readonly span remains uncredited data.
