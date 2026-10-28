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
typedef struct { u8 pad[0x5C]; f32 f5c; } N5c;

void residual_00382BE0(u8 *o) {
    extern u32 func_00174170();
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00382E20(u8 *);
    u8 *s;
    u32 t;
    f32 k;
    u8 *q;
    N5c *na;

    t = o[4];
    o[4] = t + 1;
    s = *(u8 **)(o + 0x18);
    *(B3c *)(o + 0xEC) = *(B3c *)(s + 0xEC);
    q = o + 2;
    o[0x13C] = 1;
    o[2] = s[2];
    o[1] = s[1];
    *(f32 *)(o + 0x50) = *(f32 *)(s + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(s + 0x54);
    o[0x1B7] = s[0x1B7];
    o[0x1B8] = s[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(s + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(s + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(s + 0x24);
    o[0x24] = 0;
    k = 0.5f;
    *(f32 *)(o + 0x50) *= k;
    *(f32 *)(o + 0x54) *= k;
    *(V3 *)(o + 0x34) = *(V3 *)(s + 0x34);
    *(f32 *)(o + 0x5C) = *(f32 *)(s + 0x50) * (1.6666666269302368f * (f32)(s32)-(func_00174170() % 7 * 8));
    na = (N5c *)o;
    if (*(s16 *)(o + 0x140) != 0) {
        na->f5c = -na->f5c;
    }
    *(f32 *)(o + 0x60) = *(f32 *)(s + 0x54) * (2.142857074737549f * (f32)(o[0x21] % 3 * 32 + 0x38));
    if (*(s16 *)(o + 0x140) != 0) {
        o[0x22] = 4;
    } else {
        o[0x22] = 0xC;
    }
    if (*(s8 *)(o + 0x21) >= 0) {
        func_001757E0(o, 0x17, 0xE);
        o[0x1B0] = 0x42;
        o[0x1B1] = 0x42;
        o[0x1B5] = 0x36;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        D_004C2794->f7c[*q]++;
    } else {
        func_001754A0(o, 0x1B, 3);
    }
    func_00382E20(o);
}
