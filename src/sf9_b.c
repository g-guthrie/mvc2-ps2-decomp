/* residual_00355760: MWWARM_30@src/sa29_g.c "-O3 -Op -fp off -sdatathreshold 8" */
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

#define PAR (*(u8 **)(o + 0x18))

void residual_00355760(u8 *o) {
    extern void func_00355B60(u8 *);
    extern void func_00355AE0(u8 *);
    u32 t;
    u32 z;
    u8 *q2;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(PAR + 0xEC);
    q2 = o + 2;
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
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x40;
    if (o[0x20] & 1) {
        o[0x1B5] = 0x58;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { u32 ca; u32 x; ca = (u32)D_004C2794; x = *q2 * 2; ca = x + ca; ++*(s16 *)(ca + 0x7C); }
    } else {
        o[0x1B5] = 0x30;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { u32 ca; u32 x; ca = (u32)D_004C2794; x = *q2 * 2; ca = x + ca; ++*(s16 *)(ca + 0x7C); }
    }
    *(s32 *)(o + 0xD4) = *(f32 *)(PAR + 0x34);
    *(s32 *)(o + 0xD8) = *(f32 *)(PAR + 0x38);
    o[0x14E] = 0x20;
    o[0x14F] = 0x20;
    o[0x14D] = 0x20;
    o[0x14C] = 0x20;
    *(s32 *)(o + 0xDC) = *(s16 *)(o + 0x1E);
    func_00355B60(o);
    *(s16 *)(o + 0x1C) = 0;
    *(s32 *)(o + 0xD0) = 0x16;
    func_00355AE0(o);
}
