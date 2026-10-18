typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s16 *D_004C2794;

void func_0037CB60(u8 *p, u8 *q) {
    p[0x1B5] = (*(u32 *)(q + 0x2EC) != 0) ? 0x39 : 0x3A;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794[p[2] + 0x3E] += 1;
}

void func_001CE2B0(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    v = *(s16 *)(p + 0x1C);
    if (v < 0x1E) {
        if (v < 0) {
            *(s8 *)(p + 4) = 2;
        } else if (v & 1) {
            p[0x13C] = 0;
        } else {
            p[0x13C] = 1;
        }
    } else {
        p[0x13C] = 1;
    }
}

extern u8 *func_003DA750();
extern void func_0033D270();
void func_0033D2C0(void) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0033D270;
        *(u32 *)(o + 0xD0) = 0x800C20;
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0x3F800000;
        *(u32 *)(o + 0x80) = 0x3F800000;
        *(u32 *)(o + 0x74) = 0x3F000000;
    }
}
