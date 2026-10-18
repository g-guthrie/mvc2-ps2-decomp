typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003648A0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *a = *(u8 **)(p + 0x14);
    f32 v;
    s16 c;
    u32 t;
    if (a[4] >= 2) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        p[0] = 0;
    } else {
        if (p[0x23] == 0) {
            v = 26.66666603f + *(f32 *)(a + 0x34) - *(f32 *)(p + 0x34);
        } else {
            v = *(f32 *)(a + 0x34) - 26.66666603f - *(f32 *)(p + 0x34);
        }
        v /= (f32)*(s16 *)(p + 0x1C);
        *(f32 *)(p + 0x5C) = v;
        *(f32 *)(p + 0x34) += v;
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        c = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = c;
        if (c == 0) {
            t = p[5];
            p[5] = t + 1;
            *(s16 *)(p + 0x1C) = 0;
            *(s32 *)(p + 0xD0) = 0;
            func_001E3710(p, 0x23);
            func_001757E0(p, 0x17, (u8)(p[0x23] + 0x49));
        }
    }
}
