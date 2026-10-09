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
} EffectParameters;

extern EffectParameters effect_parameters_004A6ED0;
extern float data_f32_one_004A6EE0[2];
extern u32 data_u32_004A6EE8[2];
extern float data_f32_one_004A6EF0[2];
extern u32 data_u32_004A6EF8[6];
extern float D_004F7FD0;
extern float D_004F7FD4;

extern s32 func_00153AB0(void *parameters, s32 mode);

s32 func_00420400(void)
{
    data_u32_004A6EE8[0] = 0;
    data_u32_004A6EE8[1] = 0;
    effect_parameters_004A6ED0.id = 2320;
    data_u32_004A6EF8[0] = 0;
    effect_parameters_004A6ED0.scale.bits = 0x3f75c28f;
    data_f32_one_004A6EF0[0] = 1.0f;
    data_u32_004A6EF8[3] = 5;
    data_u32_004A6EF8[4] = 0xffffffff;
    data_f32_one_004A6EF0[1] = 1.0f;
    data_f32_one_004A6EE0[0] = 1.0f;
    data_f32_one_004A6EE0[1] = 1.0f;
    data_u32_004A6EF8[1] = 0x3f800000;
    data_u32_004A6EF8[2] = 0;
    data_u32_004A6EF8[5] = 0;
    effect_parameters_004A6ED0.offsetX = D_004F7FD0;
    effect_parameters_004A6ED0.offsetY = D_004F7FD4;
    return func_00153AB0(&effect_parameters_004A6ED0, 1);
}
