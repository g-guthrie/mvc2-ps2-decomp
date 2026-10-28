/* func_0019FAB0: MW 3.0 (MWCCPS2_30) "-O3 -Op -fp off -sdatathreshold 0", compiled after src/e080_b.c (func_00174F60) in the same mwccps2 invocation (soft-float warm rule). */
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

void func_0019FAB0(u8 *p)
{
    extern void func_00175910(u8 *, s32, s32, s32);
    u8 *o;
    f32 *a, *b;
    f32 d, z;

    o = *(u8 **)(p + 0x14);
    p[0x13C] = 0;
    a = (f32 *)(o + 0x88);
    b = (f32 *)(p + 0x88);
    if (o[4] >= 2) {
        p[4]++;
        return;
    }
    d = *a - *b;
    z = 0.0f;
    if (!(d <= z)) {
        d /= 16.0f;
        if (d < z) d = z;
        if (d > 3.0f) {
            p[4]++;
            return;
        }
        func_00175910(p, 0x17, 0, (s32)d);
    }
    p[0x13C] = 1;
}
