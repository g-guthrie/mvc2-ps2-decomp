typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x5C]; f32 f5c; } SC;
typedef struct { u8 pad[0x7c]; s16 count[2]; } GameStateC;
extern GameStateC *D_004C2794;
extern u8 *D_004C29A4;

#pragma padloop on

void func_00381AC0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00381C50(u8 *);
    s32 n;
    u8 *c;
    u32 *d;
    u32 *r;
    u32 t;
    t = p[4];
    p[4] = t + 1;
    d = (u32 *)(p + 0xEC);
    r = (u32 *)(*(u8 **)(p + 0x18) + 0xEC);
    n = 49;
    for (; n > 0; --n) {
        *d++ = *r++;
    }
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    c = p + 2;
    p[0x14C] = 0x10;
    p[0x14D] = 0x10;
    p[0x14E] = 0x10;
    p[0x14F] = 0x10;
    if (p[0x23] == 0)
        *D_004C29A4 = 0;
    else
        *D_004C29A4 = 2;
    D_004C29A4[2] = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x33;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 k = *c; s16 cc = D_004C2794->count[k]; cc++; D_004C2794->count[k] = cc; }
    func_001757E0(p, 0x19, p[0x1B7] + (D_004C29A4[0] << 1));
    func_00381C50(p);
}
