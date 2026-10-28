typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern f32 D_00474590[];
extern f32 D_004745D0[];
extern f32 D_004745D4[];
extern f32 D_004745D8[];
extern f32 D_004745DC[];
extern f32 D_00474650[];

void residual_003BBF40(u8 *p)
{
    extern void func_003BD840(u8 *);
    extern void func_003BD290(u8 *);
    extern s32 func_00119098(f32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    f32 v;
    f32 b;
    f32 a;
    u32 t;

    t = p[4];
    p[4] = t + 1;
    p[5] = 0;
    p[6] = 0;
    q = *(u8 **)(p + 0x18);
    func_003BD840(p);
    v = D_00474590[p[0x21] * 2];
    if (q[0x1E6] == 0) v = -v;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + v;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + D_00474590[p[0x21] * 2];
    *(f32 *)(p + 0x60) = D_004745D8[p[0x21] * 4];
    *(f32 *)(p + 0x6C) = D_004745DC[p[0x21] * 4];
    a = D_004745D0[p[0x21] * 4];
    b = D_004745D4[p[0x21] * 4];
    if (q[0x1E6] == 0) {
        a = -a;
        b = -b;
    }
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = b;
    func_003BD290(p);
    p[0x1B5] = 0x17;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) += 1;
    func_001757E0(p, 0x19, func_00119098(D_00474650[p[0x21]]));
}
