# Runtime multiply, uppercase and tangent recovery

Three complete functions match 312 bytes of native code:

- `func_00117448`: GCC `__muldi3`, 116 bytes, from GCC 2.96 revision `db2e2f480c906879dad6930e4fe0784a52814426`. It reuses the existing licensed `gcc_libgcc_udivmod_core.h` types and original MIPS multiplication primitive; this packet adds no new assembly implementation. The generic `__umulsidi3` macro and cross products are the original upstream algorithm.
- `func_00120868`: Newlib `strupr`, 76 bytes, using its original ctype classifiers.
- `func_00117328`: Newlib `tanf`, 120 bytes, using the established PS2 no-denormals / finite-largest-exponent configuration and existing genuine tangent kernel and argument reducer.

Newlib source revision is `ffbf3c2fe5af89ba84aad3359964ead31121b7ad`. Original notices and documentation remain in the source files.

All use SNCPP then EE GCC 2.96 O2/G0 without extra flags. Assemble multiplication and uppercase with SNAS G0; tangent uses the established SNAS MIPS IV/G0 profile. The tangent callee requires the truthful `func_00115E18 = 0x00115E18` symbol alias. The native call targets are 00115E18 and 00113E78.

Each object contains exactly its complete target function, with no data, BSS or readonly payload. The standard object verifier passes all three spans; no data credit or standalone-helper credit is added.
