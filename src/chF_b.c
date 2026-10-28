/* func_00392000: MW 3.0 -O3 -Op -fp off -sdatathreshold 8, warmed by src/sf11_a.c (MWWARM_30) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G199;
extern G199 *D_004C2794;
typedef struct { f32 x, y, z; } V3;


typedef struct { s32 w[0x31]; } B228c;
extern f32 D_004F1FCC[];
extern f32 D_004F1FC8[];

void func_00392000(u8 *o, u8 *q) {
    extern u8 *func_003916B0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    s32 i;
    u8 *c;
    u8 *p2;
    f32 a, b, k, x, cc, e;
    u8 *w;
    t = o[4];
    o[4] = t + 1;
    *(B228c *)(o + 0xEC) = *(B228c *)(q + 0xEC);
    o[0x13C] = 1;
    p2 = o + 2;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    o[0x13C] = 0;
    o[0x24] = 8;
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    cc = 53.33333206176758f;
    a = D_004F1FC8[0] - cc;
    k = -106.66666412353516f;
    if (*(s16 *)(q + 0x140) == 0) {
        a = cc + D_004F1FCC[0];
        k = -k;
    }
    *(f32 *)(o + 0x34) = 0.9800000190734863f * a;
    *(f32 *)(o + 0x5C) = 0.9800000190734863f * k;
    *(f32 *)(o + 0x38) = *(f32 *)(q + 0x430) - 51.42856979370117f;
    *(s16 *)(o + 0x1C) = 0;
    i = 0;
    do {
        if ((c = func_003916B0(o, 5)) != 0) {
            *(f32 *)(c + 0x34) = *(f32 *)(o + 0x34);
            *(f32 *)(c + 0x38) = *(f32 *)(q + 0x430) - 51.42856979370117f;
            *(u8 **)(c + 0x14) = o;
            { s16 h = *(s16 *)(o + 0x1C); *(s16 *)(o + 0x1C) = h + 1; c[0x21] = h; }
            *(f32 *)(o + 0x34) += *(f32 *)(o + 0x5C);
        }
        i++;
    } while (i < 0x15);
    cc = 53.33333206176758f;
    e = 1173.333251953125f;
    b = D_004F1FC8[0] - cc;
    a = b - e;
    k = -106.66666412353516f;
    if (*(s16 *)(q + 0x140) == 0) {
        b = cc + D_004F1FCC[0];
        k = -k;
        a = e + b;
    }
    *(f32 *)(o + 0x34) = 0.9800000190734863f * a;
    *(f32 *)(o + 0x5C) = 0.9800000190734863f * k;
    *(f32 *)(o + 0x38) = *(f32 *)(q + 0x430) - 51.42856979370117f;
    *(s16 *)(o + 0x1C) = 0;
    i = 0;
    do {
        if ((c = func_003916B0(o, 7)) != 0) {
            *(f32 *)(c + 0x34) = *(f32 *)(o + 0x34);
            *(f32 *)(c + 0x38) = *(f32 *)(q + 0x430) - 51.42856979370117f;
            *(u8 **)(c + 0x14) = o;
            { s16 h = *(s16 *)(o + 0x1C); *(s16 *)(o + 0x1C) = h + 1; c[0x21] = h; }
            *(f32 *)(o + 0x34) += *(f32 *)(o + 0x5C);
        }
        i++;
    } while (i < 0x14);
    *(s16 *)(o + 0x1E) = 10;
    *(u8 **)(o + 0x14) = o;
    o[0x21] = 0x14;
    w = *(u8 **)(o + 0x14);
    w[0xD2] = 0;
    w[0xD3] = 0;
    w[0xD4] = 0;
    o[0x14E] = 0xFF;
    o[0x14F] = 0x20;
    *(s16 *)(o + 0x1C) = 0x80;
    x = 40.0f;
    if (*(s16 *)(o + 0x140) == 0) x = -x;
    *(f32 *)(o + 0x5C) = x;
    *(u32 *)(o + 0x68) = 0;
    o[0x1B5] = 0x53;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(u32 *)(o + 0x1D8) = 0;
    { s32 xx = *p2; s16 y = D_004C2794->f7c[xx]; D_004C2794->f7c[xx] = y + 1; }
    x = 20.0f;
    if (o[0x20] > 5) x = 41.0f;
    x += (f32)(u32)o[0x21];
    func_001757E0(o, 0x17, (u32)x);
}

typedef struct { s32 w[0x31]; } CP199;
typedef struct { f32 x, y, z; } V199;
typedef struct { u8 pad[0x6C]; f32 f6c; } P6C;
