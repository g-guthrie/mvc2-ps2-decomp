typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } GB;
typedef struct { s16 a, b, c, d; u8 e; u8 pad; } TB;
extern u8 D_004B83D0[], D_004B83D2[], D_004B83D4[], D_004B83D6[], D_004B83D8[];
typedef struct { s32 w[0x31]; } CB;
typedef struct { f32 x, y, z; } V3b;
typedef struct { u8 pad[0x38]; f32 f38; } PB;
extern GB *D_004C2794;


void func_00372360(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q, *i2;
    u32 t4;
    u32 idx, off;
    f32 f1, f2, f3;

    t4 = p[4];
    p[4] = t4 + 1;
    q = *(u8 **)(p + 0x18);
    *(CB *)(p + 0xEC) = *(CB *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3b *)(p + 0x50) = *(V3b *)(*(u8 **)(p + 0x18) + 0x50);
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x14D] = 0x20;
    p[0x14C] = 0x20;
    p[0x14F] = 0x24;
    p[0x14E] = 0x24;
    p[0x24] = 0;
    i2 = p + 2;
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
    } else {
        q[0x21] = 1;
        *(s32 *)(p + 0x48) = 0;
        f3 = -120.0f;
        idx = (u8)(*(s8 *)(p + 0x1B7) + *(s8 *)(p + 0x20) * 2);
        off = idx * 10;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        f1 = *(s16 *)(D_004B83D0 + off);
        f2 = *(s16 *)(D_004B83D4 + off);
        if (*(s16 *)(p + 0x140) != 0) {
            f3 = -f3;
            f1 = -f1;
            f2 = -f2;
        }
        *(f32 *)(p + 0x34) += f3;
        *(f32 *)(p + 0x5C) = f1;
        *(f32 *)(p + 0x68) = f2;
        *(f32 *)(p + 0x60) = *(s16 *)(D_004B83D2 + off);
        *(f32 *)(p + 0x6C) = *(s16 *)(D_004B83D6 + off);
        p[0x1B0] = 0x44;
        p[0x1B1] = 0x44;
        p[0x1B5] = 0x30;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*i2]++;
        q[0x1B5] = 0x30;
        q[0x1B2] = *(u16 *)(q + 0x1C0) = 0;
        *(s32 *)(q + 0x1D8) = 0;
        D_004C2794->f7c[q[2]]++;
        p[0x13C] = 0;
        func_001757E0(p, 0x15, D_004B83D8[off]);
        p[5] = 2;
        p[6] = 0;
    }
}
