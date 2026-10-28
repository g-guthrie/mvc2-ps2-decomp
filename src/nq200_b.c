typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } W31;
typedef struct { u8 pad[0x7c]; s16 count[2]; } GameStateC;
extern GameStateC *D_004C2794;
extern u8 D_00464310[];
extern f32 D_00464340[];

#pragma padloop on

void residual_0037FCC0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern f32 func_00417440(u32);
    extern f32 func_00417500(u32);
    extern void func_00380090(u8 *);
    extern void func_0037FF60(u8 *);
    u8 *c;
    u32 t;
    u8 *q;
    t = p[4];
    p[4] = t + 1;
    *(s16 *)(p + 0x26) = 0x1804;
    q = *(u8 **)(p + 0x18);
    *(W31 *)(p + 0xEC) = *(W31 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    p[0x30] = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    p[0x24] = *(s8 *)(q + 0x24);
    c = p + 2;
    p[0x13C] = 1;
    p[0x14C] = 0x10;
    p[0x14D] = 0x10;
    p[0x14E] = 0x10;
    p[0x14F] = 0x10;
    p[0x23] = (D_00464310 + p[0x20] * 6)[p[0x21]];
    *(f32 *)(p + 0x5C) = D_00464340[p[0x20]] * func_00417440((u32)(s32)(0.5 + 65536.0 * (double)(p[0x21] * 15 + 0x3C) / 360.0) & 0xFFFF);
    *(f32 *)(p + 0x60) = D_00464340[p[0x20]] * func_00417500((u32)(s32)(0.5 + 65536.0 * (double)(p[0x21] * 15 + 0x3C) / 360.0) & 0xFFFF);
    if (*(s16 *)(p + 0x140) == 0)
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = *(s8 *)(p + 0x23) + 0x37;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 k = *c; s16 cc = D_004C2794->count[k]; cc++; D_004C2794->count[k] = cc; }
    func_001757E0(p, 0x17, (u8)(p[0x23] + 4));
    func_00380090(p);
    func_0037FF60(p);
}
