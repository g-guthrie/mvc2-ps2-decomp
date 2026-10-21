# Stream-group storage and callback interfaces

The raw owner at0047D0FC is split into its unchanged0x7004-byte prefix and
a reconstructed pool at00484100. Native003FF358 clears exactly0x9C0 bytes;
003FF3E8 searches at most16 slots at0x9C stride;003FFE60 repeats that sweep;
003FF568 clears one0x9C record. These independently establish16 records and
2496 bytes. The preceding28676 raw bytes remain uncredited.

The shared StreamGroup type covers each156-byte record without opaque fill:

| Offset | Recovered storage |
| --- | --- |
|00–03|active, lifecycle, stream count and mode bytes|
|04–13|engine, resource and two stream pointers|
|14–1B|one request span|
|1C–2B|two per-stream spans|
|2C–47|seven32-bit progress/count/limit words|
|48–57|two callback/context pairs, with one- and four-argument callbacks|
|58–97|64-byte transfer buffer|
|98–9B|one result word|

There are four pointer words before offset14, followed by four more in the
callback/context pairs. The transfer copy has a native lower check of16 bytes
and an upper clamp to64. The result word is assigned by native code; its
narrower meaning is left neutral. The private proposal's summary sentence
counting six early pointer words was corrected here; its field table and
actual C layout already agreed with the native offsets.

Safe creation requires1 <= count <=2 and a valid stream-pointer array with
valid stream objects: the creator reads streams[0] before its uncapped copy
loop. Query/update loops also require the engine-reported stream count not
to exceed two. One native creation path supplies2; the00404720 entry passes
its incoming argument without a local cap, and the full entry contract is
unresolved. These runtime preconditions do not change the independently
bounded physical pool layout. This recovery does not prove all callers safe
or add runtime guards absent from retail.

Root also closed the callback interfaces used by the recovered state:

- Query returns int and receives a byte context plus three int output pointers.
- Commit is a void procedure with context and two integer arguments. Its default
  advances two engine counters; Sony EE GCC reproduces that28-byte void body.
  The previous mixed Metrowerks source returned an incidental register value.
  Moving this already credited body to its verified Sony recipe adds no CODE.
- The setters, both five-site invocation families and the default registrations
  use compatible callback types. A callback setter wrapper now forwards all
  three required arguments explicitly.
- The update procedure no longer has a falling-through int result. Three
  actual getter wrappers return their getter values, including a channel-count
  result consumed by existing registered code.

The DATA compiler now searches src after src/data for shared project types.
The complete production rebuild verifies all10744 DATA units under that recipe.
Root separately rebuilds all261 complete functions in the15 affected CODE
units. These checks cover the changed units and preserved native bytes;
the aggregate gate also passed a fresh split, full hybrid linkage and packed-ELF
byte identity against retail. All118 tests passed. The combined local bank
contains2,081,300 CODE bytes (63.1904%) and259,199 reconstructed DATA bytes
(39.9959%). This packet adds2,496 DATA bytes and zero CODE bytes; the next fixed
CODE publication threshold stays2,113,447 bytes.
