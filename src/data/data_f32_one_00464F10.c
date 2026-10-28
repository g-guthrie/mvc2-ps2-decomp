typedef float f32;
/* Part of the 0x3C4-byte memory-card icon.sys image D_00464E90 ("PS2D" magic; func_0038B2E0
 * writes 0x3C4 bytes from it, func_0038D010 fills the title at +0xC0 and the icon file names at
 * +0x104/+0x144/+0x184 and sets the title line-break halfword at +6). +0x80 is the first
 * light color, an f32 RGBA vector; these are its r, g, b (alpha is data_u32_00464F1C). */
f32 data_f32_one_00464F10[3] = { 1.0f, 1.0f, 1.0f };
