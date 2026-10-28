typedef float f32;
typedef struct { f32 a, b, c, d; } V4;
/* func_001325A0 (src/w183_x.c) copies D_0043E150[idx] (16-byte stride) into actor +0x74..+0x80
 * with four lwc1 reads (+0, +4, +8, +0xC); the span holds 15 records. */
V4 data_rec_0043E150[15] = {
    { 1.0f, 1.0f, 0.25f, 0.25f },
    { 1.0f, 1.0f, 1.0f, 0.133f },
    { 1.0f, 0.375f, 0.375f, 1.0f },
    { 1.0f, 1.0f, 0.6f, 0.266f },
    { 1.0f, 0.125f, 1.0f, 0.125f },
    { 1.0f, 0.75f, 0.25f, 1.0f },
    { 1.0f, 0.375f, 1.0f, 0.25f },
    { 1.0f, 0.75f, 0.75f, 0.75f },
    { 1.0f, 0.5f, 0.5f, 0.5f },
    { 1.0f, 1.0f, 1.0f, 0.625f },
    { 1.0f, 0.125f, 1.0f, 1.0f },
    { 1.0f, 0.125f, 0.8f, 1.0f },
    { 1.0f, 0.125f, 0.6f, 1.0f },
    { 1.0f, 1.0f, 0.0f, 0.875f },
    { 1.0f, 1.0f, 0.0f, 0.875f },
};
