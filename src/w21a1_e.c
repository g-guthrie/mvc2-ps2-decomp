typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003767A0(u8 *p) {
    extern void func_00190690(u8 *, s32, s32);
    extern void func_0015F4B0(u8 *, s32);
    extern void func_00131AB0(u8 *, u8 *, s32);
    extern void func_0018FAA0(u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001E7F60(u8 *);
    s8 *s0;
    u8 *q, *s1;
    u32 t;
    f32 v, w;
    q = *(u8 **)(p + 0x18);
    s1 = *(u8 **)(p + 0x1C4);
    s0 = (s8 *)(q + 0x2B8);
    if (p[6] == 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x13C] = 1;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        v = *(f32 *)(s1 + 0x34);
        *(f32 *)(p + 0x64) = v;
        *(f32 *)(p + 0x5C) = (v - *(f32 *)(p + 0x34)) / 32.0f;
        *(f32 *)(p + 0x60) = 25.714284896850586f;
        *(f32 *)(p + 0x6C) = -(*(f32 *)(p + 0x60) / 16.0f);
        *(s16 *)(p + 0x1C) = 0x14;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        *(s16 *)(p + 0x1C) -= 1;
        if (*(s8 *)(p + 0x1B2) != 0) {
            p[5]++;
            p[6] = 0;
            if (s1[0x425] != 0) {
                p[5] = 4;
                p[0x13C] = 0;
                p[4] = 2;
                return;
            }
            if (*(s8 *)(*(u8 **)(p + 0x18) + 0x4DD) != 0) {
                func_00190690(s1, 0x168, 0x10);
                func_0015F4B0(s1, 1);
                p[0x21] = 1;
                s0[4]++;
                s0[4] = s0[4] & 1;
                func_00131AB0(s1, s1 + 0x3FC, 1);
            } else {
                func_0018FAA0(s1, 0x14);
                func_0015F4B0(s1, 4);
                p[0x21] = 0;
            }
            func_001E3710(p, 0x2A);
            return;
        }
        if (*(f32 *)(s1 + 0x430) > *(f32 *)(p + 0x38)) {
            p[5]++;
            p[6] = 0;
        } else {
            if (*(f32 *)(p + 0x60) <= 0.0f) func_001E7F60(p);
        }
    }
}
