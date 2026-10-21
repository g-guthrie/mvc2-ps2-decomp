typedef struct { signed char resource_bank, glyph_mode, transform, glyph; float advance; } GlyphCommand;
typedef char GlyphCommand_size8[(sizeof(GlyphCommand)==8)?1:-1];
extern GlyphCommand data_u32_0043EE20[];
extern GlyphCommand data_dynamic_commands_0043EEA0[];
extern GlyphCommand data_dynamic_commands_0043EF10[];
extern GlyphCommand data_dynamic_commands_0043EFA0[];
extern GlyphCommand data_dynamic_commands_0043F020[];
extern GlyphCommand data_dynamic_commands_0043F060[];
extern GlyphCommand data_dynamic_commands_0043F0C0[];
const GlyphCommand * const D_0043F140[7] = {
    data_u32_0043EE20,
    data_dynamic_commands_0043EEA0,
    data_dynamic_commands_0043EF10,
    data_dynamic_commands_0043EFA0,
    data_dynamic_commands_0043F020,
    data_dynamic_commands_0043F060,
    data_dynamic_commands_0043F0C0,
};
