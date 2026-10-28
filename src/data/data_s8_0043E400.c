typedef struct { signed char resource_bank, glyph_mode, transform, glyph; float advance; } GlyphCommand;
typedef char GlyphCommand_size8[(sizeof(GlyphCommand)==8)?1:-1];
/* Terminator element of the GlyphCommand stream at D_0043E3D0 (stored to p+0xD8 at 0x00134838).  func_00134850 walks the stream
 * with an 8-byte stride (addiu 8 at 0x00134BB0) and stops when resource_bank (lb 0x0 at
 * 0x00134BB8) is negative; the other fields keep the stream element pattern. */
GlyphCommand data_s8_0043E400 = { -1, -1, 0, 0, 0.0f };
