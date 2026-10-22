#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 x[49]; } B_b;
typedef struct { f32 x, y, z; } V3_b;
typedef struct { u8 pad[0x50]; u32 w50, w54; } W_b;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_b;
extern H_b *D_004C2794;

void func_00373B70(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    u8 *q;
    u32 t;
    u32 k;
    f32 a, b, c;
    u8 *r;

    t = p[4];
    p[4] = t + 1;
    *(s16 *)(p + 0x1C) = 10;
    q = *(u8 **)(p + 0x18);
    *(B_b *)(p + 0xEC) = *(B_b *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)((s32)p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)((s32)p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3_b *)(p + 0x50) = *(V3_b *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x14D] = 0x50;
    p[0x14C] = 0x50;
    p[0x14F] = 0x50;
    p[0x14E] = 0x50;
    p[0x24] = 7;
    r = p + 2;
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    k = p[0x20];
    if ((s32)k >= 0xF) {
        ((W_b *)p)->w50 = 0x3D23D70A;
        ((W_b *)p)->w54 = 0x3D23D70A;
        *(s16 *)(p + 0x140) = 0;
        a = -20.0f;
        b = 0.0f;
        c = -5.0f;
        if (*(s16 *)(q + 0x140) != 0) {
            a = -a;
            b = -b;
            c = -c;
        }
        *(f32 *)(p + 0x34) += a;
        *(f32 *)(p + 0x38) += 137.14285278320312f;
        *(f32 *)(p + 0x5C) = c;
        *(f32 *)(p + 0x68) = b;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        p[0x1B5] = 0x3F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*r]++;
        func_001757E0(p, 0x16, 0xE);
        func_001E3210(p, 0x19);
        return;
    }
    p[5] = k;
}
