typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3b;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3b;
extern G3b *D_004C2794;
extern s8 D_004C2000[8];
extern f32 D_004F1FCC[];
extern f32 D_004F1FC8[];
extern s16 D_00474100[][3];
extern s16 D_00474118[][2];
extern s16 D_0047411A[][2];

void func_003B5B60(u8 *o, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    u8 *pp;
    u8 *r;
    *(u32 *)(o + 0x14C) = 0x20204060;
    r = o + 0x88;
    t = o[4];
    o[4] = t + 1;
    *(B3b *)(o + 0xEC) = *(B3b *)(q + 0xEC);
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
    o[0x24] = 0;
    o[0x31] = o[0x21];
    t = q[0x2BD];
    q[0x2BD] = t + 1;
    pp = o + 2;
    if (*(s16 *)(q + 0x140) == 0) {
        *(f32 *)(o + 0x34) = D_004F1FCC[0] + 1.6666666269302368f * (f32)D_00474100[o[0x20]][o[0x21]] / 256.0f;
        *(f32 *)(o + 0x5C) = -(1.6666666269302368f * (f32)D_00474118[o[0x20]][0] / 256.0f);
    } else {
        *(f32 *)(o + 0x34) = D_004F1FC8[0] - 1.6666666269302368f * (f32)D_00474100[o[0x20]][o[0x21]] / 256.0f;
        *(f32 *)(o + 0x5C) = 1.6666666269302368f * (f32)D_00474118[o[0x20]][0] / 256.0f;
    }
    if (o[0x20] != 2) {
        *(f32 *)(o + 0x38) = 308.5714111328125f + *(f32 *)(q + 0x430);
        if (q[0x269] == 3) {
            o[0x1B5] = 0x21;
            o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
            *(s32 *)(o + 0x1D8) = 0;
            { s32 x = *pp; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        } else {
            o[0x1B5] = 0x21;
            o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
            *(s32 *)(o + 0x1D8) = 0;
            { s32 x = *pp; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        }
    } else {
        *(f32 *)(o + 0x38) = *(f32 *)(q + 0x430) + 2.142857074737549f * (f32)(o[0x21] * 0x3000 + 0x2000) / 256.0f;
        o[0x1B5] = 0x39;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *pp; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    }
    *(f32 *)(o + 0x60) = 2.142857074737549f * (f32)D_0047411A[o[0x20]][0] / 256.0f;
    *(s32 *)(o + 0x6C) = 0;
    *(s32 *)(o + 0x68) = 0;
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    func_001757E0(o, 0x15, 0x17);
    r[0x22] = 0;
    r[0x23] = 0;
    r[0x20] = 0;
    r[0x21] = D_004C2000[o[0x21]];
}
