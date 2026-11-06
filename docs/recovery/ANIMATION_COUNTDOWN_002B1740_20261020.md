# Exact animation countdown

`func_002B1740` matches all 204 bytes using MWCCPS2 3.0-011126
`-O4,p -sdatathreshold 8`. The routine uses an embedded animation countdown
at actor offset `0x2B8 + 0x15`, optionally decrements it while animation is
active, and otherwise decrements the actor timer before switching state and
animation. The actor timer is signed 16-bit; the earlier candidate incorrectly
narrowed its comparison to a signed byte. The embedded partial structure and
older compiler preserve the native address calculation. Modern MWCC output
for this corrected source is eight bytes shorter and is not credited.

The complete production object was independently compiled and relocated
against retail. This recovery introduces no assembly, padding, or data credit.
