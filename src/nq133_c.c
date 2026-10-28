typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c2;
extern f32 D_004F1FCC[];
extern f32 D_004F1FC8[];

typedef struct { u8 pad[0x34]; f32 f34; u8 pad2[0x24]; f32 f5c; } P3c;
#define PAR (*(u8 **)(o + 0x18))

void func_003A0920(u8 *o, u8 *q) {
    extern void func_0015E630(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *r;
    P3c *sa;
    u32 t;
    r = q + 0x2B8;
    sa = (P3c *)o;
    o[0] = 1;
    t = o[4];
    o[4] = t + 1;
    *(B3c2 *)(o + 0xEC) = *(B3c2 *)(PAR + 0xEC);
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
    *(s16 *)(o + 0x140) = *(s16 *)(q + 0x140);
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    o[0x14C] = 0x70;
    o[0x14D] = 0;
    o[0x14E] = 0x40;
    o[0x14F] = 0x30;
    *(f32 *)(o + 0x34) = 106.66666412353516f + D_004F1FCC[0];
    *(u32 *)(o + 0x5C) = 0xC1200000;
    *(u32 *)(o + 0x68) = 0;
    if (q[0x1E6] != 0) {
        sa->f34 = -106.66666412353516f + D_004F1FC8[0];
        sa->f5c = -sa->f5c;
    }
    *(f32 *)(o + 0x38) = *(f32 *)(q + 0x430);
    *(u32 *)(q + 0x60) = 0;
    *(u32 *)(q + 0x6C) = 0;
    *r = 1;
    func_0015E630(o);
    func_001E7F60(o);
    func_001757E0(o, 0x17, 0);
}



