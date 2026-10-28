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
extern u8 D_004C1AC8[8];

#define PAR (*(u8 **)(o + 0x18))

void residual_00358A90(u8 *o) {
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    u8 *e;
    u8 *q;
    u16 s;
    u8 v;
    u32 t;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(PAR + 0xEC);
    q = o + 2;
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
    v = 0;
    if (*(s16 *)(o + 0x140) == 0) v = 0x18;
    o[0x20] = v;
    o[0x23] = 4;
    e = &D_004C1AC8[o[0x21] * 2];
    s = 100;
    if (e[0] != 0) {
        s = 200;
        o[0x20] = func_00174170() & 0x1F;
    }
    *(s16 *)(o + 0x1E) = s;
    *(u32 *)(o + 0x88) = 0x42000000;
    *(u32 *)(o + 0x8C) = 0x40000000;
    o[0x21] = e[1];
    if (o[0x21] == 0) {
        o[0x1B0] = 0x42;
        o[0x1B1] = 0x42;
        o[0x1B5] = 0x6B;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        D_004C2794->f7c[*q]++;
    }
    func_001757E0(o, 0x17, 0);
}
