#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
typedef struct { u8 pad[0x34]; f32 f34; } F34;
extern G3c *D_004C2794;
extern u16 *D_004C29E8;

void residual_00398DC0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00398FE0(u8 *);
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    f32 k;
    F34 *sa = (F34 *)p;
    u32 t = p[4];
    p[4] = t + 1;
    n = 0x31;
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    d = (s32 *)(p + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
    q = p + 2;
    p[0x13C] = 1;
    k = 180.0f;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *D_004C29E8 = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    p[0x13C] = 1;
    *(f32 *)((s32)p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x38) += k;
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if (*(s16 *)(p + 0x140) != 0) {
        sa->f34 += 63.33333206176758f;
    } else {
        sa->f34 -= 63.33333206176758f;
    }
    if (p[0x1B7] != 0) {
        *(s16 *)(p + 0x1C) = 0x3C;
        p[0x1B5] = 0x50;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*q]++;
    } else {
        *(s16 *)(p + 0x1C) = 0x14;
        p[0x1B5] = 0x46;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*q]++;
    }
    func_001757E0(p, 0x14, 4);
    func_00398FE0(p);
}
