/* func_001823C0: MW 3.0 (MWCCPS2_30) "-O3 -Op -fp off -sdatathreshold 0", compiled after src/e080_b.c (func_00174F60) in the same mwccps2 invocation (soft-float warm rule). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F20B0[], D_004F2668[], D_004F2C20[], D_004F31D8[], D_004F3790[], D_004F3D48[];
extern f32 D_004F1F40[];
extern f32 D_004F1FE0;
typedef struct PC {
    u8 _p0[0x38];
    f32 f38;
    u8 _p2[0x430 - 0x3C];
    f32 f430;
} PC;


void func_001823C0(u8 *p) {
    f32 *g = D_004F1F40;
    if (p == D_004F20B0 || p == D_004F2668 || p == D_004F2C20 || p == D_004F31D8 ||
        p == D_004F3790 || p == D_004F3D48) {
        f32 a, b;
        s32 n;
        if (*(s8 *)(p + 0x208) != 0) return;
        switch (*(s8 *)(p + 0x338)) { case 0: break; default: return; }
        if (p[0x215] != 0 && p[5] != 2) {
            PC *c = (PC *)p;
            f32 x = c->f38;
            f32 z = 0.0f;
            f32 d = (274.28570556640625f + *(f32 *)(*(u8 **)(p + 0x220) + 0x38)) - x;
            if (d < z) {
                c->f38 = x + d / 8.0f;
            } else {
                d = (x - 34.28571319580078f) - c->f430;
                if (d < z) c->f38 = x - d / 2.0f;
            }
            {
                f32 lim;
                d = c->f38;
                lim = D_004F1FE0 - 205.7142791748047f;
                if (!(d <= lim)) c->f38 = lim;
            }
        }
        p[0x211] = 0;
        a = g[3];
        b = a - 320.0f;
        b = 35.0f + b;
        n = (s32)*(f32 *)(p + 0x34);
        if (n <= (s32)b) {
            *(f32 *)(p + 0x34) = b;
            p[0x211] = 2;
            return;
        }
        a = (320.0f + a) - 35.0f;
        if (!(n < (s32)a)) {
            *(f32 *)(p + 0x34) = a;
            p[0x211] = 1;
        }
    }
}
