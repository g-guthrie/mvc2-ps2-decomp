typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern float D_004F1FC8;
extern void func_001757E0(u8 *, int, int);
extern void func_001AA340(u8 *, u8 *);

void residual_001AA2A0(u8 *p, u8 *a1)
{
    p[7]++;
    *(s16 *)(p + 0x1C) = 20;
    *(f32 *)(p + 0x64) = 320.0f + D_004F1FC8;
    *(f32 *)(p + 0x70) = *(f32 *)(a1 + 0x430);
    if (!(*(f32 *)(p + 0x34) < *(f32 *)(p + 0x64)))
        *(s16 *)(p + 0x140) = 0;
    else
        *(s16 *)(p + 0x140) = 1;
    func_001757E0(p, 23, 13);
    func_001AA340(p, a1);
}
