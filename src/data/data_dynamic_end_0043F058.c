typedef struct { signed char resource_bank, glyph_mode, transform, glyph; float advance; } GlyphCommand;
typedef char GlyphCommand_size8[(sizeof(GlyphCommand)==8)?1:-1];
/* Stream terminator record: func_00134850 steps GlyphCommand records by 8 (0x00134BB0) and stops
 * when resource_bank (lb 0x0 at 0x00134BB8) is negative; the other fields are unread. */
GlyphCommand data_dynamic_end_0043F058 = { -1, -1, 0, 0, 0.0f };
