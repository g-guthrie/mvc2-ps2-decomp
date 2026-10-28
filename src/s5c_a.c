/* MW 3.0, compiled in the same mwccps2 invocation after src/chA_a.c (soft-float warm): -O3 -Op -fp off -sdatathreshold 0 */
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;
s32 func_001745B0(u8 *p) {
    extern void func_001741D0(u8 *, f32 *);
    f32 t[2];
    s32 a, b;
    func_001741D0(p + 0x34, &t[0]);
    a = (u16)(s32)(480.0f + (68.57142639160156f + (2.142857074737549f * (f32)(u32)p[0x14C] * *(f32 *)(p + 0x54) + 2.142857074737549f * (f32)(u32)p[0x14D] * *(f32 *)(p + 0x54))));
    b = (u16)(s32)(t[1] + (34.28571319580078f + 2.142857074737549f * (f32)(u32)p[0x14D] * *(f32 *)(p + 0x54)));
    return !(u32)(a < b);
}
