# GCC floating-point parts comparison

The complete 288-byte parts comparator at 00119998 matches the genuine GCC 2.95.3 `fp-bit.c::__fpcmp_parts`, source `7f236610e99c7a11fb18f056b6446b3c7c40979`. The full original GPL notice and linking exceptions are retained.

The source preserves the original inline `isnan`, `isinf` and `iszero` classifier bodies. Replacing those functions with approximate classifier macros changed generated control flow; restoring the actual upstream inline definitions gives an exact match. These genuine helpers only read the actual class field, introduce no fabricated clobbers, and emit no separate native bodies.

The native record contains a class, sign, signed exponent and 64-bit fraction, with the original natural alignment. Compile with SNCPP and EE GCC 2.96 O2/G0 with no extra flags, then SNAS G0. The object contains exactly one 288-byte function and no data, BSS or readonly payload. No data credit is added.
