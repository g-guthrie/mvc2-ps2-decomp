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
extern f32 D_004766B0[];

#define PAR (*(u8 **)(o + 0x14))

void residual_003CDF00(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00174170(void);
    u32 t;
    u32 z;
    u8 *q;
    f32 f;
    s32 r;
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
    o[0x24] = 8;
    o[0x23] = 0;
    *(V3 *)(o + 0x34) = *(V3 *)(PAR + 0x34);
    *(s16 *)(o + 0x1C) = (func_00174170() & 0x1F) + 0xB4;
    f = D_004766B0[o[0x21]];
    if (*(s16 *)(o + 0x140) != 0) f = -f;
    *(f32 *)(o + 0x5C) = f;
    *(u32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x60) = 0x40892492;
    *(u32 *)(o + 0x6C) = 0xBE892492;
    *(f32 *)(o + 0x5C) += 1.6666666269302368f * (f32)(s16)((r = func_00174170(), (r &= 0xFF) + (t = -0x80))) / 256.0f;
    *(f32 *)(o + 0x60) += 2.142857074737549f * (f32)(s16)((u8)func_00174170() - 0x80) / 256.0f;
    o[0x1B0] = 0x66;
    o[0x1B1] = 6;
    o[0x1B5] = 0x30;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    D_004C2794->f7c[*q]++;
    func_001757E0(o, 0x17, (u8)((func_00174170() & 3) + 0x34));
}
