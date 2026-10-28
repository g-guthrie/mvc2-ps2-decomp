typedef unsigned int u32;
typedef signed int s32;

typedef union EffectScale
{
    float value;
    u32 bits;
} EffectScale;

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

extern EffectParameters effect_parameters_004A6ED0;
extern float D_004F7FD0;
extern float D_004F7FD4;

extern s32 func_00153AB0(void *parameters, s32 mode);

s32 func_00420400(void)
{
    effect_parameters_004A6ED0.word18[0] = 0;
    effect_parameters_004A6ED0.word18[1] = 0;
    effect_parameters_004A6ED0.id = 2320;
    effect_parameters_004A6ED0.word28 = 0;
    effect_parameters_004A6ED0.scale.bits = 0x3f75c28f;
    effect_parameters_004A6ED0.scale20[0] = 1.0f;
    effect_parameters_004A6ED0.mode34 = 5;
    effect_parameters_004A6ED0.word38 = 0xffffffff;
    effect_parameters_004A6ED0.scale20[1] = 1.0f;
    effect_parameters_004A6ED0.scale10[0] = 1.0f;
    effect_parameters_004A6ED0.scale10[1] = 1.0f;
    effect_parameters_004A6ED0.word2C.bits = 0x3f800000;
    effect_parameters_004A6ED0.word30 = 0;
    effect_parameters_004A6ED0.word3C = 0;
    effect_parameters_004A6ED0.offsetX = D_004F7FD0;
    effect_parameters_004A6ED0.offsetY = D_004F7FD4;
    return func_00153AB0(&effect_parameters_004A6ED0, 1);
}
