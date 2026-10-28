typedef unsigned int u32;
typedef signed int s32;

typedef union EffectScale
{
    float value;
    u32 bits;
} EffectScale;

/* func_0041CA40 (src/w1912_e.c) writes the same fields at the same offsets as
 * func_00420400 does for effect_parameters_004A6ED0, then passes the
 * 0x40-byte parameter block passed whole to func_00153AB0(block, 1). */
typedef struct EffectParameters
{
    s32 id;
    float offsetX;
    float offsetY;
    EffectScale scale;
    float scale10[2];
    u32 word18[2];
    float scale20[2];
    u32 word28;
    EffectScale word2C;
    u32 word30;
    s32 mode34;
    s32 word38;
    u32 word3C;
} EffectParameters;
typedef char EffectParameters_size_check[(sizeof(EffectParameters) == 0x40) ? 1 : -1];

EffectParameters effect_parameters_004A6DA0 = {
    0,
    0.0f,
    0.0f,
    { 0.9f },
    { 1.0f, 1.0f },
    { 0x0u, 0x0u },
    { 1.0f, 1.0f },
    0x0u,
    { 1.0f },
    0x2u,
    0x405,
    -1,
    0x0u,
};
