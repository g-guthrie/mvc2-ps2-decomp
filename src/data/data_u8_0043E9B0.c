typedef float f32;
/* Components 1.a (entry.component) of the 16-byte f32 RGBA color table that starts at
 * 0x0043E994 after the lwc1-read vec3 data_f32_one_0043E988. func_00134EA0 loads the r, g, b
 * of entries 1 and 2 (D_0043E9A4..AC, D_0043E9B4..BC) with lwc1 into the effect color at
 * +0x78..+0x80; the table is split across units at word boundaries. */
f32 data_u8_0043E9B0[1] = { 1.0f };
