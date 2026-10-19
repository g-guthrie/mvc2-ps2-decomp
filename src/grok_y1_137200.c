typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern f32 D_0043F1C0[];
extern f32 D_0043F1C4[];
extern f32 D_0043F1C8[];
extern void func_0032D390(u8 *, s16, int, int, f32, f32);

void residual_00137200(u8 *p)
{
    int k;

    p[4]++;
    k = p[7] * 3;
    func_0032D390(p, *(s16 *)(p + 0x1C), 2, 2, D_0043F1C0[k], D_0043F1C4[k]);
    k = p[7] * 3;
    *(f32 *)(p + 0x64) = (D_0043F1C8[k] - *(f32 *)(p + 0x3C)) / (f32) *(s16 *)(p + 0x1C);
    *(int *)(p + 0x70) = 0;
}
