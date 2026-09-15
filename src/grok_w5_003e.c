typedef signed int s32;
typedef float f32;

extern s32 D_0062BF8C;
extern s32 D_0062BC00;
extern s32 D_0062BF90;
extern f32 D_0062BC30;

f32 func_003E0C20(f32 x)
{
    x -= (f32)D_0062BF8C;
    return x;
}

f32 func_003E0C40(f32 x)
{
    x -= (f32)D_0062BF90;
    if (!D_0062BC00)
        x = 0.5f * x;
    return x;
}

f32 func_003E0C80(f32 x)
{
    x = x - 1.0f;
    x = -0.5f * x;
    x = x * D_0062BC30;
    return x;
}
