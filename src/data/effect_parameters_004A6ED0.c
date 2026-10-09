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

EffectParameters effect_parameters_004A6ED0 = {
    0,
    0.0f,
    0.0f,
    { 0.9f },
};
