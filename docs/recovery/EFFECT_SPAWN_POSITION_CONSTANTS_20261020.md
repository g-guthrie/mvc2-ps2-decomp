# Effect spawn positions

Recover two independent three-float position constants at 0x004B8010 and
0x004B8020, adding 24 typed initialized-data bytes. Native func_00337850
loads exactly three floats at 0x003378B0..0x003378B8 and stores them into
an allocated effect's position at offsets 0x34,0x38,0x3C. func_00337900
repeats those loads at 0x00337960..0x00337968 for the second constant.

Each V3 object is 12 bytes. The four bytes between them and six bytes after
the second stay raw placeholders. All six coordinate values are 0.0f;
native position reads establish their semantics and extent.

The coordinator independently compiled all four resulting data objects and
verified their whole retail spans. The unchanged consumer unit m6c.c also
recompiled with its production O3/G8 recipe; all four functions remain
exact. No code bytes are added. Linked credit requires the combined image
gate before promotion from matching to complete.

Coordinator combined validation: all 95 tests pass; hybrid loaded image and
packed retail ELF remain byte-identical. These data objects are placed and
catalogued complete. No code credit is added by this data recovery.
