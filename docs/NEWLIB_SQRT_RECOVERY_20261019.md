# Newlib square-root kernel recovery

The complete double kernel `00112DD0` (796 bytes) and float kernel `00114228` (204 bytes) match 1,000 native code bytes. Both retain the genuine fdlibm bit-by-bit algorithms and Sun permission notices from Newlib commit `ffbf3c2fe5af89ba84aad3359964ead31121b7ad`, `libm/math/e_sqrt.c` and `ef_sqrt.c`.

Both use SNCPP and EE GCC 2.96 `-O2 -G0 -ffunction-sections` with no extra compiler flags. Assemble double with SNAS `-G0`; assemble float with SNAS `-mips4 -G0`. The latter is an existing supported assembler profile and avoids the extra MFC1 hazard NOP and consequent alignment NOP produced by the default profile. Generated assembly is never edited.

The float kernel uses fdlibm's original `_FLT_NO_DENORMALS` and `_FLT_LARGEST_EXPONENT_IS_NORMAL` configuration. Native code tests exponent-zero representations against 0x00800000 and treats the largest exponent as normal, which establishes those settings independently of matching trials.

Original `one` and `tiny` constants are value-only macros with their original double/float types and values. Their addresses are never used; this avoids emitting unused static objects that are absent from retail. Both final objects contain no readonly, initialized-data or BSS payload. No pool or data credit is added.

Standard object verification checks every native byte of both complete kernels. Native entry calls include double tail jumps at `00111B50` and `001173DC`, and float tail jumps at `001137C0` and `0011743C`.
