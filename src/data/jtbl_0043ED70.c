typedef struct { signed char resource_bank, glyph_mode, transform, glyph; float advance; } GlyphCommand;
typedef char GlyphCommand_size8[(sizeof(GlyphCommand)==8)?1:-1];
extern GlyphCommand data_u32_0043EB50[];
extern GlyphCommand data_glyph_commands_0043EBA0[];
extern GlyphCommand data_glyph_commands_0043EC00[];
extern GlyphCommand data_glyph_commands_0043EC50[];
extern GlyphCommand data_glyph_commands_0043EC90[];
extern GlyphCommand data_glyph_commands_0043ECD0[];
extern GlyphCommand data_glyph_commands_0043ED10[];
extern GlyphCommand data_glyph_commands_0043ED40[];
const GlyphCommand * const jtbl_0043ED70[16] = {
    data_u32_0043EB50,
    data_glyph_commands_0043EBA0,
    data_glyph_commands_0043EC00,
    data_glyph_commands_0043EC50,
    data_glyph_commands_0043EC90,
    data_glyph_commands_0043ECD0,
    data_glyph_commands_0043ED10,
    data_glyph_commands_0043ED40,
    data_u32_0043EB50,
    data_u32_0043EB50,
    data_u32_0043EB50,
    data_u32_0043EB50,
    data_u32_0043EB50,
    data_u32_0043EB50,
    data_u32_0043EB50,
    data_u32_0043EB50,
};
