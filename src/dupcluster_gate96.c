typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);

s32 func_002B5D90(u8 *a0)
{
    f32 prod;
    *(f32 *)(a0 + 56) += *(f32 *)(a0 + 96);
    *(f32 *)(a0 + 96) += *(f32 *)(a0 + 108);
    prod = *(f32 *)(a0 + 96) * *(f32 *)(a0 + 108);
    if (prod > 0.0f) {
        a0[6]++;
        *(s32 *)(a0 + 108) = 0xC0092492;
    }
    return func_00175700(a0);
}
