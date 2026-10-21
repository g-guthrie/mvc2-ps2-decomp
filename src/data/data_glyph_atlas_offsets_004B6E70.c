typedef unsigned int u32;
typedef struct GlyphAtlasOffset {
    u32 packed_xy;
} GlyphAtlasOffset;
typedef char GlyphAtlasOffset_size_must_be_4[sizeof(GlyphAtlasOffset) == 4 ? 1 : -1];

#define GLYPH_ATLAS_OFFSET(horizontal_step, row_step) \
    ((u32)(horizontal_step) | ((u32)(row_step) << 8))

/*
 * The native character mapper indexes this word table from base 0x004B6E70.
 * Its consumers split each returned word into the low and next bytes. The
 * low byte feeds the texture horizontal-step calculation; the next byte
 * multiplies the texture row stride. The high half is retained verbatim.
 * The table ends at the independent WINS text base 0x004B6FB0 (80 entries).
 * Native lookup does not bounds-check; callers must supply a mapped index <80.
 */
GlyphAtlasOffset data_glyph_atlas_offsets_004B6E70[80] = {
    {GLYPH_ATLAS_OFFSET(0x20, 0x00)}, /* 00: 0x00000020 */
    {GLYPH_ATLAS_OFFSET(0x30, 0x00)}, /* 01: 0x00000030 */
    {GLYPH_ATLAS_OFFSET(0x40, 0x00)}, /* 02: 0x00000040 */
    {GLYPH_ATLAS_OFFSET(0x50, 0x00)}, /* 03: 0x00000050 */
    {GLYPH_ATLAS_OFFSET(0xA0, 0x10)}, /* 04: 0x000010A0 */
    {GLYPH_ATLAS_OFFSET(0xB0, 0x10)}, /* 05: 0x000010B0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x10)}, /* 06: 0x000010C0 */
    {GLYPH_ATLAS_OFFSET(0xD0, 0x10)}, /* 07: 0x000010D0 */
    {GLYPH_ATLAS_OFFSET(0xE0, 0x10)}, /* 08: 0x000010E0 */
    {GLYPH_ATLAS_OFFSET(0x00, 0x20)}, /* 09: 0x00002000 */
    {GLYPH_ATLAS_OFFSET(0x00, 0x10)}, /* 10: 0x00001000 */
    {GLYPH_ATLAS_OFFSET(0x10, 0x10)}, /* 11: 0x00001010 */
    {GLYPH_ATLAS_OFFSET(0x20, 0x10)}, /* 12: 0x00001020 */
    {GLYPH_ATLAS_OFFSET(0x30, 0x10)}, /* 13: 0x00001030 */
    {GLYPH_ATLAS_OFFSET(0x40, 0x10)}, /* 14: 0x00001040 */
    {GLYPH_ATLAS_OFFSET(0x50, 0x10)}, /* 15: 0x00001050 */
    {GLYPH_ATLAS_OFFSET(0x60, 0x10)}, /* 16: 0x00001060 */
    {GLYPH_ATLAS_OFFSET(0x70, 0x10)}, /* 17: 0x00001070 */
    {GLYPH_ATLAS_OFFSET(0x80, 0x10)}, /* 18: 0x00001080 */
    {GLYPH_ATLAS_OFFSET(0x90, 0x10)}, /* 19: 0x00001090 */
    {GLYPH_ATLAS_OFFSET(0x70, 0x00)}, /* 20: 0x00000070 */
    {GLYPH_ATLAS_OFFSET(0x80, 0x00)}, /* 21: 0x00000080 */
    {GLYPH_ATLAS_OFFSET(0x90, 0x00)}, /* 22: 0x00000090 */
    {GLYPH_ATLAS_OFFSET(0xA0, 0x00)}, /* 23: 0x000000A0 */
    {GLYPH_ATLAS_OFFSET(0xB0, 0x00)}, /* 24: 0x000000B0 */
    {GLYPH_ATLAS_OFFSET(0xD0, 0x00)}, /* 25: 0x000000D0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x60)}, /* 26: 0x000060C0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x60)}, /* 27: 0x000060C0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x60)}, /* 28: 0x000060C0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x60)}, /* 29: 0x000060C0 */
    {GLYPH_ATLAS_OFFSET(0x10, 0x20)}, /* 30: 0x00002010 */
    {GLYPH_ATLAS_OFFSET(0x20, 0x20)}, /* 31: 0x00002020 */
    {GLYPH_ATLAS_OFFSET(0x30, 0x20)}, /* 32: 0x00002030 */
    {GLYPH_ATLAS_OFFSET(0x40, 0x20)}, /* 33: 0x00002040 */
    {GLYPH_ATLAS_OFFSET(0x50, 0x20)}, /* 34: 0x00002050 */
    {GLYPH_ATLAS_OFFSET(0x60, 0x20)}, /* 35: 0x00002060 */
    {GLYPH_ATLAS_OFFSET(0x70, 0x20)}, /* 36: 0x00002070 */
    {GLYPH_ATLAS_OFFSET(0x80, 0x20)}, /* 37: 0x00002080 */
    {GLYPH_ATLAS_OFFSET(0x90, 0x20)}, /* 38: 0x00002090 */
    {GLYPH_ATLAS_OFFSET(0xA0, 0x20)}, /* 39: 0x000020A0 */
    {GLYPH_ATLAS_OFFSET(0xB0, 0x20)}, /* 40: 0x000020B0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x20)}, /* 41: 0x000020C0 */
    {GLYPH_ATLAS_OFFSET(0xD0, 0x20)}, /* 42: 0x000020D0 */
    {GLYPH_ATLAS_OFFSET(0xE0, 0x20)}, /* 43: 0x000020E0 */
    {GLYPH_ATLAS_OFFSET(0xF0, 0x20)}, /* 44: 0x000020F0 */
    {GLYPH_ATLAS_OFFSET(0x00, 0x30)}, /* 45: 0x00003000 */
    {GLYPH_ATLAS_OFFSET(0x10, 0x30)}, /* 46: 0x00003010 */
    {GLYPH_ATLAS_OFFSET(0x20, 0x30)}, /* 47: 0x00003020 */
    {GLYPH_ATLAS_OFFSET(0x30, 0x30)}, /* 48: 0x00003030 */
    {GLYPH_ATLAS_OFFSET(0x40, 0x30)}, /* 49: 0x00003040 */
    {GLYPH_ATLAS_OFFSET(0x50, 0x30)}, /* 50: 0x00003050 */
    {GLYPH_ATLAS_OFFSET(0x60, 0x30)}, /* 51: 0x00003060 */
    {GLYPH_ATLAS_OFFSET(0x70, 0x30)}, /* 52: 0x00003070 */
    {GLYPH_ATLAS_OFFSET(0x80, 0x30)}, /* 53: 0x00003080 */
    {GLYPH_ATLAS_OFFSET(0x90, 0x30)}, /* 54: 0x00003090 */
    {GLYPH_ATLAS_OFFSET(0xA0, 0x30)}, /* 55: 0x000030A0 */
    {GLYPH_ATLAS_OFFSET(0x00, 0x00)}, /* 56: 0x00000000 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x60)}, /* 57: 0x000060C0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x60)}, /* 58: 0x000060C0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x60)}, /* 59: 0x000060C0 */
    {GLYPH_ATLAS_OFFSET(0xB0, 0x30)}, /* 60: 0x000030B0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x30)}, /* 61: 0x000030C0 */
    {GLYPH_ATLAS_OFFSET(0xD0, 0x30)}, /* 62: 0x000030D0 */
    {GLYPH_ATLAS_OFFSET(0xE0, 0x30)}, /* 63: 0x000030E0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x60)}, /* 64: 0x000060C0 */
    {GLYPH_ATLAS_OFFSET(0x00, 0x40)}, /* 65: 0x00004000 */
    {GLYPH_ATLAS_OFFSET(0x20, 0x40)}, /* 66: 0x00004020 */
    {GLYPH_ATLAS_OFFSET(0x40, 0x40)}, /* 67: 0x00004040 */
    {GLYPH_ATLAS_OFFSET(0x60, 0x40)}, /* 68: 0x00004060 */
    {GLYPH_ATLAS_OFFSET(0x80, 0x40)}, /* 69: 0x00004080 */
    {GLYPH_ATLAS_OFFSET(0xA0, 0x40)}, /* 70: 0x000040A0 */
    {GLYPH_ATLAS_OFFSET(0xC0, 0x40)}, /* 71: 0x000040C0 */
    {GLYPH_ATLAS_OFFSET(0xE0, 0x40)}, /* 72: 0x000040E0 */
    {GLYPH_ATLAS_OFFSET(0x00, 0x60)}, /* 73: 0x00006000 */
    {GLYPH_ATLAS_OFFSET(0x20, 0x60)}, /* 74: 0x00006020 */
    {GLYPH_ATLAS_OFFSET(0xE0, 0x60)}, /* 75: 0x000060E0 */
    {GLYPH_ATLAS_OFFSET(0x40, 0x60)}, /* 76: 0x00006040 */
    {GLYPH_ATLAS_OFFSET(0x60, 0x60)}, /* 77: 0x00006060 */
    {GLYPH_ATLAS_OFFSET(0x80, 0x60)}, /* 78: 0x00006080 */
    {GLYPH_ATLAS_OFFSET(0xA0, 0x60)}, /* 79: 0x000060A0 */
};
