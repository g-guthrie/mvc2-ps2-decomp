typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
extern u16 D_004D18DC;
extern u8 D_004D18DB;
void func_001A44C0(u8 *);
void func_001A47F0(u8 *p, s32 a1, u8 *r) {
    extern u8 *func_003DA750(u8 *, s32, s32);
    u8 *o, *q;
    f32 z, k, f;
    u32 t;
    s32 one = 1;
    if ((D_004D18DC & (one << D_004D18DB)) != 0 || ((s8)r[4]) == 0) {
        q = *(u8 **)(p + 0x14);
        z = 0.0f;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        f = *(f32 *)(p + 0x5C);
        if (f < z) f = -f;
        k = 160.0f;
        f -= k;
        if (f < 0.0f) return;
        t = p[5];
        p[5] = t + 1;
        if (*(s16 *)(p + 0x140) == 0) {
            f = -f;
            k = -k;
        }
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + k;
        *(f32 *)(p + 0x5C) = k;
        *(f32 *)(p + 0x68) = 0;
        if (*(s16 *)(p + 0x1C) < 7) {
            o = func_003DA750(p, 3, 2);
            if (o != 0) {
                *(s16 *)(o + 0x26) = 0xE02;
                o[0x20] = 1;
                o[0x22] = 0;
                *(f32 *)(o + 0x5C) = f;
                *(s16 *)(o + 0x1C) = *(s16 *)(p + 0x1C) + 1;
                *(u8 **)(o + 0x18) = *(u8 **)(p + 0x18);
                *(u8 **)(o + 0x14) = p;
                *(void **)(o + 0x10) = (void *)func_001A44C0;
                p[0x22] = 1;
            } else {
                p[5] = 2;
                *(f32 *)(p + 0x68) = 26.66666603f;
                if (*(s16 *)(p + 0x140) != 0) {
                    { f32 *pp = (f32 *)p; pp[0x1A] = -pp[0x1A]; }
                }
            }
        }
    } else {
        p[5] = 2;
        *(f32 *)(p + 0x68) = 26.66666603f;
        if (*(s16 *)(p + 0x140) != 0) {
            { f32 *pp = (f32 *)p; pp[0x1A] = -pp[0x1A]; }
        }
    }
}
