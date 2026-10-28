typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u16 b; u8 pad[18]; } E20b;
extern s8 *D_004C2840;
extern E20b D_004F4480[];
extern u8 D_004B5630[];
extern u8 D_004B5640[];

void residual_00172B70(u8 *p)
{
    extern void func_003D7350(u8, u8, s32, u8 *);
    extern void func_00173F90(u8 *);
    extern void func_00174030(u8 *);
    extern void func_00131340(s32);
    s8 *g = D_004C2840;
    u8 k;
    s8 c;
    s32 k2;
    if (g[0x8C] != 0) return;
    if (g[0x19] != 0) return;
    if (g[0x91] != 0 || g[2] == 5) return;
    if ((c = g[0x4A]) != 0) {
        if (c > 0) {
            k = (*(s8 *)(p + 0x538) == 1) ? 0x68 : 8;
            func_003D7350(k, g[0xB6], 0xB, D_004B5630);
        }
        return;
    }
    if (*(s16 *)(p + 0x4D4) == 0) {
        *(s16 *)(p + 0x4D4) = 0x28;
        *(s16 *)(p + 0x4D6) += 1;
        *(s16 *)(p + 0x4D6) &= 3;
    }
    *(s16 *)(p + 0x4D4) -= 1;
    k2 = (*(s8 *)(p + 0x538) == 1) ? 0x64 : 4;
    {
        s8 *b = D_004C2840 + 0xB6;
        if (*b == 0) *b = -0x10; else *b = 7;
    }
    func_003D7350(k2, D_004C2840[0xB6], 0xB, D_004B5640);
    if (D_004F4480[*(s8 *)(p + 0x538) & 1].b & 0x8000) {
        func_00173F90(p);
        func_00174030(p);
        func_00131340(0x64);
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3d;
extern G3d *D_004C2794;
extern s16 D_004C1C28[4];
extern s16 D_004C1C2A[4];
extern f32 D_00463730[];
extern f32 D_00463734[];

void residual_00363DD0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00363F70(u8 *, u8 *);
    s16 v;
    f32 f;
    p[5]++;
    p[0x13C] = 0;
    p[0x24] = 8;
    p[0x31] = 0;
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = 0x3F;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    *(u16 *)(p + 0x1C0) |= 0x200;
    p[0x14F] = 0x20;
    p[0x14E] = 0x20;
    v = D_004C1C28[p[0x1B7] * 2];
    if (*(s16 *)(p + 0x140) != 0) v = -v;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.666666627f * (f32)v;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.142857075f * (f32)D_004C1C2A[p[0x1B7] * 2];
    f = D_00463730[p[0x1B7] * 2];
    if (*(s16 *)(p + 0x140) != 0) f = -f;
    *(f32 *)(p + 0x5C) = f;
    *(f32 *)(p + 0x60) = D_00463734[p[0x1B7] * 2];
    *(s32 *)(p + 0x6C) = 0;
    *(s32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x17, 0x51);
    func_00363F70(p, q);
}
