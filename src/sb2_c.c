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
extern u8 D_004C2164[8];

#pragma padloop on

void func_003C4AB0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_003C4C40(u8 *, u8 *);
    s32 n;
    SC *sa;
    u32 *d;
    u32 *r;
    u32 t;
    t = p[4];
    p[4] = t + 1;
    r = (u32 *)(q + 0xEC);
    d = (u32 *)(p + 0xEC);
    n = 49;
    for (; n > 0; --n) {
        *d++ = *r++;
    }
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
    p[0x1B0] = 2;
    p[0x1B0] = 2;
    p[0x1B5] = D_004C2164[(p[0x20] >> 1) + p[0x1B7]];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 k = p[2]; s16 c = D_004C2794->count[k]; c++; D_004C2794->count[k] = c; }
    if (p[0x20] != 0) {
        *(u32 *)(p + 0x5C) = 0xC1D55555;
        if (*(s16 *)(p + 0x140) != 0) { sa = (SC *)q; sa = (SC *)p; sa->f5c = -sa->f5c; }
        *(u32 *)(p + 0x60) = 0x42892492;
    } else {
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x5C) = 0;
    }
    func_001757E0(p, 0x15, p[0x1B7] * 2 + 3);
    func_003C4C40(p, q);
}
