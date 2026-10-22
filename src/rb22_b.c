typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0039D900(u8 *p) {
    extern s32 func_00175700();
    extern void func_0039DAC0(u8 *);
    extern void func_0039DA50(u8 *);
    extern int func_00174470(const void *);
    extern void func_0039E450(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    u8 *s1, *s2;
    u32 t;
    f32 v;
    s2 = *(u8 **)(p + 0x18);
    s1 = *(u8 **)(s2 + 0x18);
    if (p[5] != 0) {
        if ((s8)func_00175700(p) >= 0) return;
        func_0039DAC0(p);
        return;
    }
    if (*(s8 *)(s2 + 0x1B2) != 0) {
        func_0039DA50(p);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) == 0) {
        func_0039DA50(p);
        return;
    }
    v = *(f32 *)(s1 + 0x430);
    if (v > *(f32 *)(p + 0x38)) {
        *(f32 *)(p + 0x38) = v;
        *(s16 *)(s2 + 0x1E) -= 1;
        if (*(s16 *)(s2 + 0x1E) != 0) {
            func_0039E450(p);
        } else {
            t = p[5];
            p[5] = t + 1;
            func_001757E0(p, 0x14, 1);
        }
    } else {
        func_001E7F60(p);
    }
}
