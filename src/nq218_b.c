typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;
extern f32 D_00461ED0[];
extern f32 D_00461ED4[];

typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } O34;
/* MWCC 3.0: ./try30.sh src/nq218_b.c "-O3 -Op -sdatathreshold 8" */
#define PAR (*(u8 **)(o + 0x18))

void residual_00348010(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00348360(u8 *);
    u8 *par;
    u32 t;
    u32 z;
    u8 *p2;
    par = PAR;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(PAR + 0xEC);
    o[0x13C] = 1;
    o[2] = PAR[2];
    o[1] = PAR[1];
    *(f32 *)(o + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(PAR + 0x54);
    o[0x1B7] = PAR[0x1B7];
    o[0x1B8] = PAR[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(PAR + 0x24);
    *(s16 *)(o + 0x140) = *(s16 *)(PAR + 0x140);
    p2 = o + 2;
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    *(f32 *)(o + 0x34) = *(f32 *)(PAR + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x38);
    if (PAR[0x1E6] != 0) {
        ((O34 *)o)->f34 += 160.0f;
    } else {
        ((O34 *)o)->f34 -= 160.0f;
    }
    *(f32 *)(o + 0x38) += 137.14285278320312f;
    o[0x14E] = 0x40;
    o[0x14F] = 0x40;
    *(s8 *)(o + 0x24) = 0;
    if (par[0x269] == 3) {
        o[0x1B5] = 0x3F;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        func_001757E0(o, 0x14, 2);
    } else if (o[0x20] == 1) {
        o[0x1B5] = 0x3A;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        func_001757E0(o, 0x14, 3);
    } else if (o[0x20] == 2) {
        o[0x1B5] = 0x4E;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        func_001757E0(o, 0x14, 2);
    } else {
        o[0x1B5] = o[0x1B7] ? 0x39 : 0x38;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        func_001757E0(o, 0x14, 2);
    }
    if (*(s16 *)(o + 0x140) != 0) {
        *(f32 *)(o + 0x5C) = D_00461ED0[o[0x1B7] * 2];
    } else {
        *(f32 *)(o + 0x5C) = -D_00461ED0[o[0x1B7] * 2];
    }
    *(f32 *)(o + 0x60) = D_00461ED4[o[0x1B7] * 2];
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    func_00348360(o);
}
