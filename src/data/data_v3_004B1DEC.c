typedef struct { float x, y, z; } V3;
/* No direct reader. Typed from its neighbours: the scale vectors D_004B1DE0 and
 * D_004B1E28 are read as x/y/z lwc1 triples by the same renderer, and this word
 * triple sits on the same 12-byte grid between them. */
V3 data_v3_004B1DEC = { 1.0f, 1.0f, 3.0f };
