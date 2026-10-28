typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7c]; s16 count[2]; } GameStateC;
extern GameStateC *D_004C2794;

typedef struct { u8 pad[0x34]; f32 f34; } S34;

#pragma padloop on

void residual_003A54E0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003A5700(u8 *, u8 *);
    s32 n;
    u32 *d;
    u32 *r;
    u8 *par;
    u32 t;
    par = *(u8 **)(p + 0x14);
    t = p[4];
    p[4] = t + 1;
    d = (u32 *)(p + 0xEC);
    r = (u32 *)(par + 0xEC);
    n = 49;
    for (; n > 0; --n) {
        *d++ = *r++;
    }
    p[0x13C] = 1;
    p[2] = par[2];
    p[1] = par[1];
    *(f32 *)(p + 0x50) = *(f32 *)(par + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(par + 0x54);
    p[0x1B7] = par[0x1B7];
    p[0x1B8] = par[0x1B8];
    p[0x30] = *(s8 *)(par + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(par + 0x50);
    p[0x24] = *(s8 *)(par + 0x24);
    p[0x13C] = 1;
    *(s8 *)(p + 0x31) = -2;
    p[0x1B5] = 0x30;
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 k = p[2]; s16 cc = D_004C2794->count[k]; cc++; D_004C2794->count[k] = cc; }
    if (p[0x23] == 0)
        p[0x1B0] = 0x42;
    else
        p[0x1B0] = 0x60;
    p[0x1B1] = 0x42;
    p[0x14F] = 0x1A;
    p[0x14E] = 0x1A;
    *(f32 *)(p + 0x34) = *(f32 *)(par + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(par + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(par + 0x3C);
    if (*(s16 *)(p + 0x140) == 0)
        ((S34 *)p)->f34 += -53.33333206176758f;
    else
        ((S34 *)p)->f34 += 53.33333206176758f;
    if (*(s16 *)(p + 0x140) == 0)
        *(u32 *)(p + 0x68) = 0xC2480000;
    else
        *(u32 *)(p + 0x68) = 0x42480000;
    *(u32 *)(p + 0x5C) = 0;
    if (p[0x20] == 2) {
        func_001757E0(p, 0x17, 0);
    } else if (p[0x21] == 0) {
        func_001757E0(p, 0x17, 2);
    } else {
        func_001757E0(p, 0x17, 3);
    }
    func_003A5700(p, q);
}
