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
typedef struct { u8 pad[0x34]; f32 f34; } P34;

#define PAR (*(u8 **)(o + 0x18))

void residual_00346E90(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003470A0(u8 *);
    u8 *q;
    u32 t;
    P34 *sa;
    u8 *r;
    q = PAR + 0x2B8;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(PAR + 0xEC);
    r = o + 2;
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
    *(f32 *)(o + 0x38) += 137.14285278320312f;
    *(f32 *)(o + 0x3C) = *(f32 *)(PAR + 0x3C);
    sa = (P34 *)o;
    if (*(s16 *)(o + 0x140) != 0) {
        sa->f34 += 106.66666412353516f;
    } else {
        sa->f34 -= 106.66666412353516f;
    }
    if (o[0x1B7] == 0) {
        *(u32 *)(o + 0x5C) = 0xC0A00000;
    } else {
        *(u32 *)(o + 0x5C) = 0xC1055555;
    }
    if (*(s16 *)(o + 0x140) != 0) {
        *(f32 *)(o + 0x5C) = -*(f32 *)(o + 0x5C);
    }
    o[0x24] = 0;
    o[0x1B5] = *(s8 *)(o + 0x1B7) + 0x30;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    D_004C2794->f7c[*r]++;
    q[2] = 1;
    func_001757E0(o, 0x17, o[0x1B7]);
    func_003470A0(o);
}
