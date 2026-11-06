# Calloc and integer conversion recovery

Three complete routines add 496 matching code bytes: Newlib `_calloc_r` at 00119DC8 (180 bytes), and GCC fp-bit double-to-signed32/unsigned32 conversions at 00119BC0 (156 bytes) and 00119CE8 (160 bytes). The native signed conversion saturates at signed 32-bit limits; the unsigned conversion rejects negative inputs and saturates at the unsigned limit. Their integer types match those actual semantics.

Calloc selects the existing allocator source's original DEFINE_CALLOC component, preserving Doug Lea's public-domain notice and pinned Newlib source. All four existing heap functions remain exact. Conversion bodies and genuine classification definitions come from GCC `fp-bit.c`, source `7f236610e99c7a11fb18f056b6446b3c7c40979`; the full upstream GPL notice and linking exceptions are retained.

Compile both with SNCPP and EE GCC 2.96 O2/G0; conversions use `-msoft-float`, while the heap unit has no extra compiler flags. Assemble with SNAS G0. Complete object checks pass for all seven functions across the two CUs. Both objects have no data, BSS or readonly payload. No shared header or multiprecision source changes are included, and no data credit is added.
