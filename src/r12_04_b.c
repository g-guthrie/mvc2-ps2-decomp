/* func_00193E10: MW 3.0.3 (try.sh) -O3 -Op -sdatathreshold 0, with
 * opt_dead_assignments off so the named locals keep retail's evaluation order. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern u8 D_004D18A6;

#pragma push
#pragma opt_dead_assignments off

void func_00193E10(u8 *p, u8 *q) {
    u8 *s0;
    u8 *s1;
    extern s32 func_00348D60(u8 *);
    extern void func_00175670(u8 *);
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    extern f32 func_00417D50(f32, f32);
    f32 c, x;
    u32 ta, tb;
    s0 = p + 0x88;
    s1 = q + 0x2B8;
    tb = *(u16 *)(p + 0x98);
    ta = *(u16 *)(q + 0x168);
    if (tb != ta) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 8;
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_00348D60(p);
    }
    if ((D_004D18DC & (1 << D_004D18DB)) != 0) return;
    if (D_004D18A6 == 0) {
        s32 v;
        func_00175670(p);
        v = *(s16 *)(p + 0x1E);
        if (v != 0) {
            *(s16 *)(p + 0x1E) = v - 1;
            return;
        }
        if (*(s8 *)(p + 0x150) == 0) {
            *(s16 *)(p + 0x1E) = 1;
            *(s32 *)(s0 + 0x14) = *(s32 *)(s0 + 0x14) + *(s32 *)(s0 + 0x18);
            if (*(s8 *)(s1 + 0x13) != 0) {
                *(s32 *)(s0 + 0x14) = *(s32 *)(s0 + 0x14) + *(s32 *)(s0 + 0x18);
            }
        }
    }
    c = func_00417500(*(s32 *)(s0 + 0x14));
    *(f32 *)(p + 0x5C) = c * func_00417D50(2.0f, (f32)*(s8 *)(s0 + 0x1C)) / 2.0f;
    { f32 two; c = func_00417440(*(s32 *)(s0 + 0x14)); two = 2.0f; x = (f32)*(s8 *)(s0 + 0x1C); *(f32 *)(p + 0x60) = c * func_00417D50(two, x) / 2.0f; }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) = 137.14285278f + (*(f32 *)(q + 0x38) + *(f32 *)(p + 0x60));
}

#pragma pop
