# Newlib argument reduction recovery

The complete double reducer at 00112818 (1,464 bytes) and float reducer at 00113E78 (944 bytes) match 2,408 native code bytes. Both retain the genuine fdlibm algorithms and Sun permission notices from Newlib commit `ffbf3c2fe5af89ba84aad3359964ead31121b7ad`, `libm/math/e_rem_pio2.c` and `ef_rem_pio2.c`.

Each routine returns a quadrant index and stores the reduced argument in two parts. Word access uses the original IEEE double/float union macros with actual 32-bit word types. The float configuration uses the original PS2 format macros, including finite largest exponent. Callees have their real typed interfaces: absolute value and the six-argument double or float kernel reducer.

Both compile with SNCPP and EE GCC 2.96 `-O2 -G0 -ffunction-sections`, without extra compiler flags. Double assembles exactly with SNAS `-G0`; float uses SNAS `-mips4 -G0`. With the same generated float assembly, the default assembler profile produces 968 bytes, while MIPS IV produces the exact 944 bytes. Generated assembly is never changed. The current double source is 1,464 bytes under both assembler profiles; no causal claim is made about an earlier different 1,496-byte probe.

Complete readonly sections pass standard verification before function relocation: 592 bytes at 004AB8E0 for double, and 960 bytes at 004ABC00 for float. Every byte matches the retail section, including tables, original scalar constants and generated constants. The pools remain uncredited data. No literals were adjusted to their comments' intended bit patterns; the original decimal values were retained.
