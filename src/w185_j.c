typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_0023DCE0(u8 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_001E3210();
    extern void func_0035C7B0();
    s32 i;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x209] = 1;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(137.14285278320312f + *(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        u32 t = p[6];
        p[6] = t + 1;
        q[1] = 1;
        D_004F1F45[0] = 3;
        D_004F1F46[0] = 1;
        func_001E3210(p, 0x1F);
        for (i = 0; i < 20; i++) {
            func_0035C7B0(p, 1, 0);
        }
        *(f32 *)(p + 0x5C) /= 4.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 8.0f;
        *(s16 *)(p + 0x1C) = 16;
    }
}
