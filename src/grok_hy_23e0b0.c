typedef unsigned char u8;
typedef float f32;

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void func_0023E0B0(u8 *p)
{
    f32 x;
    f32 lim;
    lim = D_004F1FC8 + 53.333332061767578f;
    x = *(f32 *)(p + 0x34);
    if (!(lim <= x))
        *(f32 *)(p + 0x34) = lim;
    lim = D_004F1FCC - 53.333332061767578f;
    x = *(f32 *)(p + 0x34);
    if (lim < x)
        *(f32 *)(p + 0x34) = lim;
}
