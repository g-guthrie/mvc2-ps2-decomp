typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { f32 x, y; } XY;
extern XY D_004726B0[];
extern f32 D_004726B4[];

#define PAR (*(u8 **)(o + 0x18))

void residual_0039ADB0(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    f32 v;
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
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    *(f32 *)(o + 0x34) = *(f32 *)(PAR + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x38);
    *(s16 *)(o + 0x140) = *(s16 *)(PAR + 0x140);
    o[0x24] = 0;
    if (*(s16 *)(o + 0x140) != 0) {
        v = D_004726B0[o[0x20]].x;
    } else {
        v = -D_004726B0[o[0x20]].x;
    }
    *(f32 *)(o + 0x34) += v;
    *(f32 *)(o + 0x38) += D_004726B4[o[0x20] * 2];
    *(s16 *)(o + 0x1C) = (o[0x20] != 0) ? 4 : 1;
    o[0x1B4] = 0;
    o[0x1B2] = 0;
    func_001757E0(o, 0x15, 0x11);
}
