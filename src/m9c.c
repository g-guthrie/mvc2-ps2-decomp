typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;


void func_00346DC0(u8 *a, u8 *b) {
    if (*(s16 *)(b + 0x140) != 0) {
        *(f32 *)(a + 0x34) = 140.0f + *(f32 *)(b + 0x34);
    } else {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) - 140.0f;
    }
    *(f32 *)(a + 0x38) = 177.857131958f + *(f32 *)(b + 0x38);
}


void func_0014AFB0(u8 *p) {
    f32 k;
    *(s16 *)(p + 0x1C) += 1;
    if (*(s16 *)(p + 0x1C) >= 0x32) *(s16 *)(p + 0x1C) = 0;
    *(u32 *)(p + 0xD0) |= 0x20000;
    k = 0.0199999996f;
    *(f32 *)(p + 0xE0) = k * (f32)*(s16 *)(p + 0x1C);
    *(f32 *)(p + 0xE4) = k * (f32)*(s16 *)(p + 0x1C);
}

typedef struct { f32 x, y, z; } V3;
void func_001A1060(u8 *p, u8 *q) {
    if (q[5] != 0 || q[0x1E4] != 0x15) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
        if (p[0x21] != 0) *(f32 *)(p + 0x34) += 266.666656494f;
        if ((*(s8 *)(q + 0x151) & 2) != 0) {
            p[4] = 2;
            p[0x13C] = 0;
        }
    }
}

extern void func_003DAA40();
void func_00157600(u8 *p) {
    f32 a = 0.0199999996f;
    f32 b = 0.0500000007f;
    s16 i;
    *(f32 *)(p + 0x50) += a;
    *(f32 *)(p + 0x54) += a;
    *(f32 *)(p + 0x58) += a;
    *(f32 *)(p + 0x78) -= b;
    *(f32 *)(p + 0x7C) -= b;
    *(f32 *)(p + 0x80) -= b;
    i = *(s16 *)(p + 0x1C);
    if (i >= 0xF) func_003DAA40();
    else *(s16 *)(p + 0x1C) = i + 1;
}
