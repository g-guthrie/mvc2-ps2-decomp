/* Metrowerks (mwccps2 3.0.3, -O3 -sdatathreshold 0) vector helpers that run
 * their arithmetic on VU0 in macro mode.  The 16-byte stack temporaries, the
 * struct copies in and out, prologue and epilogue are compiler output; only
 * the COP2 instructions are inline asm, with C locals as operands. */

typedef float f32;
typedef signed int s32;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;
typedef struct { s32 m[16]; } M4;

void func_003DE3D0(V4 *out, V4 *in, M4 *mat)
{
    V4 a;
    V4 r;
    M4 m;
    M4 *pm;
    V4 *pa;
    V4 *pr;
    a = *in;
    m = *mat;
    pm = &m;
    pa = &a;
    pr = &r;
    asm {
        lqc2 vf4, 0(pa)
        lqc2 vf5, 0(pm)
        lqc2 vf6, 0x10(pm)
        lqc2 vf7, 0x20(pm)
        lqc2 vf8, 0x30(pm)
        vmulax.xyzw ACC, vf5, vf4x
        vmadday.xyzw ACC, vf6, vf4y
        vmaddaz.xyzw ACC, vf7, vf4z
        vmaddw.xyzw vf4, vf8, vf4w
        sqc2 vf4, 0(pr)
    }
    *out = r;
}

void func_003DE530(V3 *v) {
    V3 t;
    V3 *pt;
    pt = &t;
    *pt = *v;
    asm {
        lqc2 vf4, 0(pt)
        vmul.xyz vf5, vf4, vf4
        vaddy.x vf5, vf5, vf5y
        vaddz.x vf5, vf5, vf5z
        vrsqrt Q, vf0w, vf5x
        vwaitq
        vmulq.xyz vf4, vf4, Q
        sqc2 vf4, 0(pt)
    }
    *v = *pt;
}

void func_003DE5C0(V3 *out, V3 *a, V3 *b) {
    V3 r;
    V3 ta;
    V3 tb;
    V3 *pb;
    V3 *pa;
    V3 *pr;
    pa = &ta;
    pb = &tb;
    pr = &r;
    *pa = *a;
    *pb = *b;
    asm {
        lqc2 vf4, 0(pa)
        lqc2 vf5, 0(pb)
        vopmula.xyz ACC, vf4, vf5
        vopmsub.xyz vf6, vf5, vf4
        sqc2 vf6, 0(pr)
    }
    *out = *pr;
}
