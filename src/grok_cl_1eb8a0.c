typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_0018C4B0(u8 *, s32);
extern double func_00119058(f32);
extern s32 func_00100240(void);
extern s32 func_00100290(void);
extern void func_001757E0(u8 *, s32, s32);
extern u8 *D_004C2794;

void residual_001EB8A0(u8 *p)
{
    f32 d;
    p[6]++;
    func_0018C4B0(p, 5);
    p[0x1B5] = (s8)p[0x1B7] + 0x3C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    if (p[0x1B7])
        d = 4.1666665f;
    else
        d = 2.5f;
    if (p[0x1E6]) {
        func_00119058(*(f32 *)(p + 0x5C));
        if (func_00100240())
            d = -d;
    } else {
        d = -d;
        func_00119058(*(f32 *)(p + 0x5C));
        if (func_00100290())
            d = -d;
    }
    *(f32 *)(p + 0x5C) += d;
    *(u32 *)(p + 0x68) = 0;
    *(s16 *)(p + 0x1C) = (s16)(p[0x1B7] << 1);
    func_001757E0(p, 0x15, 8);
}
