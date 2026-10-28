/* residual_0034D600: MW 3.0 (try30.sh) -O3 -Op -sdatathreshold 8, exact.
   if-form conditional call; h1c store through a struct field so 3.0 does not CSE o+0x1C into a1. */
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
extern u8 *D_004C2940;

typedef struct { u8 pad[0x18]; u8 *par; } PS;
typedef struct { u8 pad[0x1C]; s16 h1c; } H1C;
#define PAR (*(u8 **)(o + 0x18))

void residual_0034D600(u8 *o) {
    extern void func_00131AB0(u8 *, u8 *, s32);
    extern void func_0034DC30(u8 *);
    u32 t;
    f32 k;
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
    *(s16 *)(o + 0x140) = 0;
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    o[0x1B5] = o[0x20] ? 0x57 : 0x35;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    D_004C2940[8] = PAR[0x1E6];
    *(f32 *)(o + 0x34) = *(f32 *)(PAR + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x38);
    ((H1C *)o)->h1c = 0xF0;
    if (o[0x20]) func_00131AB0(((PS *)o)->par, o + 0x1C, 6);
    D_004C2940[9] = 0;
    o[0x14C] = 0x40;
    o[0x14D] = 0x20;
    o[0x14E] = 0x24;
    o[0x14F] = 0x24;
    k = o[0x20] ? 106.66666412353516f : -106.66666412353516f;
    *(f32 *)D_004C2940 = k;
    *(u32 *)(D_004C2940 + 4) = 0x42CDB6DB;
    o[0x22] = o[0x20] ? 0x10 : 0;
    *(s16 *)(o + 0x1E) = 2;
    *(s32 *)(o + 0x5C) = 0;
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    D_004C2940[0xA] = 0x10;
    func_0034DC30(o);
}
