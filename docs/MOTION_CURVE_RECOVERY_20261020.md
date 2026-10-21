# Bounded signed motion curve at 00475E00

The 128-byte table at `0x00475E00` is a signed-byte motion curve. Exact C
`func_003C45B0` reads the signed `field1C`, subtracts one, masks the result with
`0x7F`, writes that bounded value back, and indexes the table with it. Retail
instructions at `0x003C45E4` and `0x003C45F0` establish the selector's complete
0–127 range; the `lb` at `0x003C460C` establishes signed-byte elements and a
one-byte stride. This supports the complete 128-byte extent without assuming
anything about the field's initial value.

The object compiled with the production data recipe, MWCCPS2 3.0.3,
`-O3 -sdatathreshold 0 -i src/data`; `tools/verify_data_object.py` verified
its complete symbol size and all 128 relocated bytes against the pinned retail
image. It is catalogued as `progress=reconstructed`, `status=matching`, pending
the root combined hybrid link. No neighboring bytes or code are credited.

Coordinator combined validation: all 95 tests pass; hybrid loaded image and
packed retail ELF remain byte-identical. These data objects are placed and
catalogued complete. No code credit is added by this data recovery.
