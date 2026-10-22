typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1F4C[];
extern f32 D_004F1FE8[];

void func_002BC7B0(u8 *p)
{
    extern double func_00119058(f32);
    extern void func_00175700(u8 *);
    extern f32 dptofp(double);
    u32 t;
    double x, k;
    f32 g;

    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) return;
    t = p[6];
    p[6] = t + 1;
    p[0x152] = p[0x152] + 1;
    if (p[0x1E6] != 0) {
        x = func_00119058(D_004F1F4C[0]) - 320.0;
    } else {
        k = 320.0;
        x = (k += func_00119058(D_004F1F4C[0]));
    }
    *(f32 *)(p + 0x5C) = (f32)(func_00119058(dptofp(x) - *(f32 *)(p + 0x34)) / 32.0);
    k = 240.0;
    x = (k += func_00119058(D_004F1FE8[0])) - 102.85713958740234;
    *(f32 *)(p + 0x60) = (f32)(func_00119058(dptofp(x) - *(f32 *)(p + 0x38)) / 32.0);
}
