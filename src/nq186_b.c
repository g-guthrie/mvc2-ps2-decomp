typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x34]; f32 f34; } O34;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;
extern s16 D_004644D0[];
extern s16 D_004644D2[];

#define PAR par

void residual_00381070(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003812D0(u8 *);
    u32 t;
    u32 z;
    u8 *par;
    u8 *q;
    par = *(u8 **)(o + 0x18);
    t = o[4];
    o[4] = t + 1;
    *(s16 *)(o + 0x26) = 0x1902;
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
    o[0x24] = 8;
    o[0x13C] = 1;
    *(s16 *)(o + 0x140) = 0;
    o[0x14C] = 0x10;
    o[0x14D] = 0x10;
    o[0x14E] = 0x10;
    o[0x14F] = 0x10;
    *(s16 *)(o + 0x1C) = 0x14;
    *(V3 *)(o + 0x34) = *(V3 *)(PAR + 0x34);
    q = o + 2;
    if (*(s16 *)(PAR + 0x140) == 0) {
        ((O34 *)o)->f34 += 1.6666666269302368f * (f32)D_004644D0[o[0x23] * 2];
    } else {
        ((O34 *)o)->f34 -= 1.6666666269302368f * (f32)D_004644D0[o[0x23] * 2];
    }
    *(f32 *)(o + 0x38) += 2.142857074737549f * (f32)D_004644D2[o[0x23] * 2];
    if (*(s16 *)(PAR + 0x140) != 0) {
        o[0x23] = (0x20 - *(s8 *)(o + 0x23)) & 0x1F;
    }
    o[0x22] = o[0x23];
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    o[0x1B5] = 0x31;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    D_004C2794->f7c[*q]++;
    func_001757E0(o, 0x17, 2);
    func_003812D0(o);
}
