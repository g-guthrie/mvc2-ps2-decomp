/* func_001825F0: MW 3.0 (MWCCPS2_30) "-O3 -Op -fp off -sdatathreshold 0", compiled after src/e080_b.c (func_00174F60) in the same mwccps2 invocation (soft-float warm rule). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct PC {
    u8 _p0[5];
    u8 b5;
    u8 _p1[0x34 - 6];
    f32 f34;
    f32 f38;
    u8 _p2[0x211 - 0x3C];
    u8 b211;
    u8 _p3[0x215 - 0x212];
    u8 b215;
    u8 _p4[0x220 - 0x216];
    struct PC *q220;
    u8 _p5[0x338 - 0x224];
    s8 b338;
    u8 _p6[0x430 - 0x339];
    f32 f430;
} PC;

extern f32 D_004F1F40[];
extern f32 D_004F1FE0[];

void func_001825F0(PC *p)
{
    f32 *table = D_004F1F40;
    f32 d, lim, a, b;
    s32 cur;

    if (p->b338 == 0) {
        return;
    }
    if (p->b215 != 0 && p->b5 != 2) {
        d = (274.28570556640625f + p->q220->f38) - p->f38;
        if (d < 0.0f) {
            p->f38 += d / 8.0f;
        } else {
            d = (p->f38 - 34.28571319580078f) - p->f430;
            if (d < 0.0f) {
                p->f38 -= d / 2.0f;
            }
        }
        d = p->f38;
        lim = D_004F1FE0[0] - 205.7142791748047f;
        if (!(d <= lim)) {
            p->f38 = lim;
        }
    }
    p->b211 = 0;
    a = table[3];
    d = a - 320.0f;
    b = 26.66666603088379f + d;
    cur = (s32)p->f34;
    if (cur <= (s32)b) {
        p->f34 = b;
        p->b211 = 2;
    } else {
        a = (320.0f + a) - 26.66666603088379f;
        if (!(cur < (s32)a)) {
            p->f34 = a;
            p->b211 = 1;
        }
    }
}
