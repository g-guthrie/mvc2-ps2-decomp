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
typedef struct { f32 a, b; } T2;
extern G3c *D_004C2794;
extern T2 D_004B8350[];
extern T2 D_004B8354[];

#define PAR (*(u8 **)(o + 0x18))

void residual_003550F0(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00417A40(void);
    extern void func_003553E0(u8 *);
    u32 t;
    u32 z;
    f32 a, b;
    u8 *q;
    u8 *ix;
    t = o[4];
    o[4] = t + 1;
    q = PAR;
    o[0x14D] = 0xC0;
    o[0x14C] = 0xC0;
    o[0x14E] = 0x40;
    o[0x14F] = 0x40;
    *(s16 *)(o + 0x1C) = 0;
    q[0x2C2] = 1;
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
    ix = o + 2;
    if (PAR[0x20D] == 2) {
        if (o[0x20] == 4) {
            o[0x1B5] = 0x3D;
            z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
            *(s32 *)(o + 0x1D8) = 0;
            D_004C2794->f7c[*ix]++;
        } else {
            o[0x1B5] = 0x3F;
            z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
            *(s32 *)(o + 0x1D8) = 0;
            D_004C2794->f7c[*ix]++;
        }
    } else {
        o[0x1B5] = *(s8 *)(PAR + 0x1B7) + 0x3B;
    }
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    D_004C2794->f7c[*ix]++;
    o[0x24] = 0;
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    o[0x13C] = 1;
    *(f32 *)(o + 0x34) = *(f32 *)(PAR + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(PAR + 0x3C) - 1.0f;
    *(f32 *)(o + 0x68) = 0.0f;
    *(f32 *)(o + 0x6C) = 0.0f;
    a = D_004B8350[o[0x20]].a;
    b = -43.33333206176758f;
    if (*(s16 *)(o + 0x140)) {
        a = -a;
        b = -b;
    }
    *(f32 *)(o + 0x5C) = a;
    *(f32 *)(o + 0x34) += b;
    *(f32 *)(o + 0x38) += 171.42855834960938f;
    *(f32 *)(o + 0x60) = D_004B8354[o[0x20]].a;
    o[0x169] = 0x15;
    o[0x168] = *(s8 *)(o + 0x20) + 2;
    func_001757E0(o, o[0x169], o[0x168]);
    *(s16 *)(o + 0x1C) = func_00417A40();
    *(s16 *)(o + 0x1C) &= 7;
    *(s16 *)(o + 0x1C) += 1;
    func_003553E0(o);
}
