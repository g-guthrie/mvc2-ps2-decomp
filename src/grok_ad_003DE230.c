typedef float f32;
typedef signed int s32;
typedef struct { f32 x, y, z, w; } V4;

void func_003DE230(f32 *out, V4 *in, V4 *mat)
{
    V4 a[4];
    V4 m[4];
    V4 r[4];
    V4 *pa;
    V4 *pm;
    V4 *pr;
    s32 i;
    a[0] = in[0]; a[1] = in[1]; a[2] = in[2]; a[3] = in[3];
    m[0] = mat[0]; m[1] = mat[1]; m[2] = mat[2]; m[3] = mat[3];
    pa = a;
    pm = m;
    pr = r;
    i = 3;
    asm {
        lqc2 vf4, 0(pm)
        lqc2 vf5, 0x10(pm)
        lqc2 vf6, 0x20(pm)
    }
    do {
        asm {
            lqc2 vf8, 0(pa)
            vmulax.xyz ACC, vf4, vf8x
            vmadday.xyz ACC, vf5, vf8y
            vmaddz.xyz vf9, vf6, vf8z
            sqc2 vf9, 0(pr)
        }
        pa++;
        pr++;
        i--;
    } while (i);
    out[0] = r[0].x; out[1] = r[0].y; out[2] = r[0].z;
    out[4] = r[1].x; out[5] = r[1].y; out[6] = r[1].z;
    out[8] = r[2].x; out[9] = r[2].y; out[10] = r[2].z;
}
