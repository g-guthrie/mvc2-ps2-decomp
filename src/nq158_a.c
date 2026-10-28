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
typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad3c[0x20]; f32 f5c; u8 pad60[0xE0]; s16 f140; } SA;

void residual_0035FAA0(u8 *o, u8 *a) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0035FCA0(u8 *, u8 *);
    u32 t;
    u32 z;
    SA *sa = (SA *)o;
    u8 *q;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(a + 0xEC);
    o[0x13C] = 1;
    o[2] = a[2];
    o[1] = a[1];
    *(f32 *)(o + 0x50) = *(f32 *)(a + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(a + 0x54);
    o[0x1B7] = a[0x1B7];
    o[0x1B8] = a[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(a + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(a + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
    o[0x13C] = 1;
    o[0x31] = 1;
    o[0x24] = 0;
    *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(a + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(a + 0x3C);
    q = o + 2;
    if (*(s16 *)(o + 0x140) == 0) {
        sa->f34 += -186.66665649414062f;
    } else {
        sa->f34 -= -186.66665649414062f;
    }
    *(f32 *)(o + 0x38) += 171.42855834960938f;
    o[0x14F] = 0x5D;
    o[0x14E] = 0x5D;
    *(s32 *)(o + 0x5C) = 0;
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    *(f32 *)(o + 0x5C) = -13.333333015441895f;
    if (*(s16 *)(o + 0x140) != 0) {
        sa->f5c = -sa->f5c;
    }
    o[0x1B5] = 0x3A;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *q; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B5] |= 0x10;
    o[0x1B0] = 0x43;
    o[0x1B1] = 0x42;
    func_001757E0(o, 0x17, 0);
    func_0035FCA0(o, a);
}
