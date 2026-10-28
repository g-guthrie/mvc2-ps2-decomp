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
extern u8 D_004B8750[];

#define PAR (*(u8 **)(o + 0x18))

void residual_0039DB30(u8 *o)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0039DD40(u8 *);
    u8 *q;
    o[4]++;
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
    o[0x13C] = 0;
    *(f32 *)(o + 0x34) = *(f32 *)(PAR + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x38);
    *(f32 *)(o + 0x38) += 102.85713958740234f;
    o[0x14F] = 0x20;
    o[0x14E] = 0x20;
    o[0x14D] = 0x20;
    o[0x14C] = 0x20;
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    *(s32 *)(o + 0x5C) = 0;
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    if (o[0x21] != 0) {
        o[0x1B5] = 0x40;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        D_004C2794->f7c[*q]++;
    } else {
        o[0x1B5] = 0x3F;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        D_004C2794->f7c[*q]++;
    }
    func_001757E0(o, 0x14, 0);
    o[0x22] = D_004B8750[o[0x22]];
    if (*(s16 *)(o + 0x140) != 0) {
        o[0x22] = -*(s8 *)(o + 0x22);
        o[0x22] &= 0x1F;
    }
    func_0039DD40(o);
}
