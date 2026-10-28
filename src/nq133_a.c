typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3a;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3a;
extern G3a *D_004C2794;
typedef struct { u8 pad[0x1C0]; u16 h1c0; } P3a;

void residual_00354510(u8 *o) {
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    u32 t;
    s32 v;
    u8 *r;
    t = o[4];
    q = *(u8 **)(o + 0x18);
    o[4] = t + 1;
    *(B3a *)(o + 0xEC) = *(B3a *)(q + 0xEC);
    r = o + 2;
    o[0x13C] = 1;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    o[0x1B0] = 0x40;
    o[0x1B1] = 0x40;
    o[0x24] = (o[0x21] != 0) ? 0xC : 0xB;
    *(V3 *)(o + 0x34) = *(V3 *)(q + 0x34);
    if (o[0x21] == 0) {
        v = o[0x20] + (o[0x1B7] * 2 + 0x3B);
        if (*(s8 *)(q + 0x20) > 0) v = 0x61;
        if (q[0x1FD] == 5) v = o[0x20] + 0x41;
        o[0x1B5] = v;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        D_004C2794->f7c[*r]++;
        if (q[0x1FD] == 5) ((P3a *)o)->h1c0 = 0x40;
        func_001E7F60(o);
    }
    func_001757E0(o, 0x17, (u8)(o[0x21] + (o[0x1B7] * 4 + o[0x20] * 2) + 2));
}


