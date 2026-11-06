# Exact selector sweep update

`func_002C3080` is a complete 360-byte portable C match with modern MWCCPS2
3.0.3, `-O4,p -sdatathreshold 8`. The native countdown uses a signed byte;
the adjacent step is negated as a signed byte and converted to an unsigned
byte when added to the selector. Declaring both fields signed and using the
explicit unsigned conversion reproduces those native operations and the
original register allocation. No volatile qualifiers, assembly, padding,
or helper substitutions are used.

The two input key masks are 16-bit. The countdown gates the existing update
helpers; automatic sweep reverses its signed step outside selectors 3–7,
while manual input decrements above zero or increments below nine. The source
uses the two actual existing helper addresses and the native small-data
pointer. This change claims code only; it adds no table/data credit.

The existing `func_002C31F0` wrapper forwards its incoming object pointer to
`func_002C3200`. Its old parameterless source signature was corrected to
express that real native ABI; the entire 11-function wrapper CU remains exact
and its compiled object is byte-identical to the previous verified object.

Both complete rebuilt images remain byte-identical to retail. Catalog and
production coverage pass, as do all 59 affected tool tests. Code now totals
2,006,736 / 3,293,696 bytes (60.9266%), 17,302 / 20,300 functions.
Data remains 188,610 / 648,064 bytes (29.1036%). This is a local checkpoint;
7,900 more code bytes are needed for the next scheduled push threshold.
