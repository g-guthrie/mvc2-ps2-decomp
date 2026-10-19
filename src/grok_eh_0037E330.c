typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001E7F60(u8 *);

void residual_0037E330(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        if (*(s16 *)(p + 0x140) == 0)
            *(f32 *)(p + 0x34) -= 106.666664f;
        else
            *(f32 *)(p + 0x34) -= 106.666664f;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        *(u32 *)(p + 0x48) = 0;
        func_001757E0(p, 0x17, 2);
        *(f32 *)(p + 0x50) *= 0.25f;
        *(f32 *)(p + 0x54) *= 0.375f;
    } else
        func_001E7F60(p);
}
