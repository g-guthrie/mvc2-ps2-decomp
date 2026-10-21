# Readonly Newlib double constants

Recover 176 initialized bytes: ten double scalars at `0x004ABA68..0x004ABAB8`, the eight-element PIo2 array at `0x004AC038..0x004AC078`, and four scalars through `0x004AC098`. The following unowned gap is unchanged.

The original matching sources define these objects. Their cached exact EE96 production objects provide named symbols, exact sizes, source-section offsets and byte contents. Native section anchors and complete readonly comparisons establish both pools' locations. The 80-byte prefix replaces the preserved raw suffix from the earlier integer-table recovery; previously credited neighboring constants receive no additional credit.

All standalone definitions retain `const double` and use readonly initialized storage. This also emits the two scalar +0 values correctly under MWCC, without integer-word encodings or wrapper objects. The target double width is eight bytes.

Eight original decimal spellings round one ULP differently between the legacy EE96 and MWCC compilers. The recovered numeric literals represent the exact cached EE96/retail values and independently reproduce them under the production MWCC data recipe. The complete PIo2 array remains a double array; it is not inferred from numeric resemblance.

All fifteen objects pass relocated-data verification with MWCCPS2 3.0.3, -O3 -sdatathreshold 0. Cached code ownership, full section comparisons, catalog placement, image and packed ELF identity, and the test suite provide the combined gate. This data recovery adds no code bytes.
