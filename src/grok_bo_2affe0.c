typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern u16 D_004C0C78[];
extern f32 D_004C0C70[];
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_002AFFE0(u8 *p)
{
    f32 d;

    p[6]++;
    p[0x1B5] = (s8)p[0x1B7] * 2 + 90;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 4);
    func_00185490(p);
    *(s16 *)(p + 0x1C) = D_004C0C78[p[0x1B7]];
    d = D_004C0C70[p[0x1B7]];
    if (p[0x1E6]) {
        if (*(f32 *)(p + 0x5C) < 0.0f)
            d = -d;
        d = -d;
    } else {
        if (*(f32 *)(p + 0x5C) > 0.0f)
            d = -d;
    }
    *(f32 *)(p + 0x5C) += d;
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 21, (u8)(p[0x1B7] + 25));
}
