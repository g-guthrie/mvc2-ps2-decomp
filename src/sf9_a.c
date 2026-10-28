/* residual_00368730: ./try30.sh src/sf9_a.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } Bq213b;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gq213b;
typedef struct { u8 pad[0x48]; s32 f48; } Aq213b;
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } Pq213b;
extern Gq213b *D_004C2794;
extern u8 *D_004C297C;
typedef struct { f32 a, b, c, d; } Tq213b;
extern Tq213b D_004638F0[];

#define PAR (*(u8 **)(o + 0x18))

void residual_00368730(u8 *o) {
    extern s32 func_00417690(f32, f32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    f32 v;
    s32 ang;
    double d;
    t = o[4];
    o[4] = t + 1;
    *(Bq213b *)(o + 0xEC) = *(Bq213b *)(PAR + 0xEC);
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
    o[0x24] = 0;
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    o[0x1B5] = (o[0x21] & 0x80) ? 0x49 : 0x40;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { u32 ca; u32 x; ca = (u32)D_004C2794; x = o[2] * 2; ca = x + ca; ++*(s16 *)(ca + 0x7C); }
    *(u32 *)(o + 0x5C) = 0;
    *(u32 *)(o + 0x60) = 0;
    *(u32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x6C) = 0;
    if (*(s16 *)(o + 0x140)) v = 15.0f; else v = -15.0f;
    *(f32 *)(o + 0x5C) = v;
    *(f32 *)(o + 0x60) = D_004638F0[o[0x21] & 3].d;
    if (*(s16 *)(o + 0x140)) v = D_004638F0[o[0x21] & 3].a;
    else v = -D_004638F0[o[0x21] & 3].a;
    *(f32 *)(o + 0x34) = *(f32 *)(PAR + 0x34) + v;
    v = D_004638F0[o[0x21] & 3].b;
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x38) + v;
    if (*(s16 *)(o + 0x140)) d = 320.0 - D_004638F0[o[0x21] & 3].c;
    else d = -320.0 + D_004638F0[o[0x21] & 3].c;
    *(f32 *)(D_004C297C + 4) = d;
    *(s32 *)(o + 0x48) = func_00417690(*(f32 *)(o + 0x60), *(f32 *)(o + 0x5C));
    if (*(s16 *)(o + 0x140)) ang = -((Aq213b *)o)->f48;
    else ang = (((Aq213b *)o)->f48 + 0x7FFF + 1) & 0xFFFF;
    *(s32 *)(o + 0x48) = ang;
    *(s16 *)(o + 0x1C) = 4;
    func_001757E0(o, 0x17, 0x16);
}
