typedef unsigned char u8;
typedef float f32;

f32 func_001519E0(u8 *a0)
{
    f32 m = *(f32 *)(a0 + 0);
    if (*(f32 *)(a0 + 4) > m)
        m = *(f32 *)(a0 + 4);
    if (*(f32 *)(a0 + 8) > m)
        m = *(f32 *)(a0 + 8);
    return m;
}
