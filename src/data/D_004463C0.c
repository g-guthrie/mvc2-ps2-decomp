typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* Effect parameter block passed as func_00153AB0(&D_004463C0, 0) by
 * func_0016DCB0 (src/fb10_e.c) and src/w1710_c.c. func_00153AB0 reads
 * id (lw +0) and f32 fields +0x4..+0x24 (lwc1); fb10_e.c writes the same
 * fields as D_004463C4..D_004463E4. The tail (+0x28..+0x3F) is not read by
 * func_00153AB0; it keeps the typing of the former data_u32_004463E8 and
 * mirrors the block at effect_parameters_004A6ED0. */
typedef struct {
    s32 id;
    f32 x, y, scale;
    f32 size[2];
    f32 uv0[2];
    f32 uv1[2];
    u32 w28;
    f32 f2C;
    u32 w30;
    u32 w34;
    s32 i38;
    u32 w3C;
} EffectParams;
typedef char EffectParams_size_check[(sizeof(EffectParams) == 0x40) ? 1 : -1];
EffectParams D_004463C0 = {
    0,
    0.0f, 0.0f, 0.899999976f,
    { 1.0f, 1.0f },
    { 0.0f, 0.0f },
    { 1.0f, 1.0f },
    0x00000000u,
    1.0f,
    0x00000002u,
    0x00000405u,
    -1,
    0x00000000u
};
