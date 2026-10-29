/*
 * VU0 macro-mode math on the host (Port J).
 *
 * The credited C for these functions (src/vu0_a.c, vu0_b.c, vu0_d.c,
 * vu0_f.c, w183_z.c) keeps the COP2 instructions as inline asm, and the
 * placeholder functions (src/k1a.c, k6a.c, p0a.c, s0h.c, s1k.c) are whole
 * assembly; on the host all of those are no-ops, which left every camera,
 * world and light matrix uninitialised.  These are the same operations in
 * plain C, read off the asm (each comment names the Sony libvu0 routine).
 *
 * Conventions (as on VU0): a matrix is four 16-byte rows m[0..3]; applying
 * m to v gives m[0]*v.x + m[1]*v.y + m[2]*v.z + m[3]*v.w.
 */
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "host.h"

typedef float V4f[4];
#define P(x) ((float *)(uintptr_t)(x))
#define PI32(x) ((int32_t *)(uintptr_t)(x))

static void apply(float out[4], const float m[16], const float v[4])
{
    float r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = m[i] * v[0] + m[4 + i] * v[1] + m[8 + i] * v[2] + m[12 + i] * v[3];
    memcpy(out, r, sizeof r);
}

/* VU0 float -> fixed conversion: truncation toward zero, saturating */
static int32_t ftoi(float f, float scale)
{
    double d = (double)f * scale;
    if (d != d)
        return 0;
    if (d >= 2147483647.0)
        return 0x7FFFFFFF;
    if (d <= -2147483648.0)
        return (int32_t)0x80000000u;
    return (int32_t)d;
}

/* ---- Metrowerks helpers (vu0_b.c, w183_z.c, vu0_d.c) ---- */

/* out = a * b: each row of a applied to b's rows (4x4) */
void func_003DE160(void *out, void *a, void *b)
{
    float ta[16], tb[16], r[16];
    int i;
    memcpy(ta, a, sizeof ta);
    memcpy(tb, b, sizeof tb);
    for (i = 0; i < 4; i++)
        apply(r + 4 * i, tb, ta + 4 * i);
    memcpy(out, r, sizeof r);
}

/* out (V4) = mat applied to in */
void func_003DE3D0(void *out, void *in, void *mat)
{
    float v[4], m[16];
    memcpy(v, in, sizeof v);
    memcpy(m, mat, sizeof m);
    apply(v, m, v);
    memcpy(out, v, sizeof v);
}

/* normalise a V3 in place (vrsqrt) */
void func_003DE530(void *pv)
{
    float *v = (float *)pv;
    float l = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    float q = 1.0f / sqrtf(l);
    v[0] *= q;
    v[1] *= q;
    v[2] *= q;
}

/* out (V3) = a x b */
void func_003DE5C0(void *out, void *pa, void *pb)
{
    float a[3], b[3], r[3];
    memcpy(a, pa, sizeof a);
    memcpy(b, pb, sizeof b);
    r[0] = a[1] * b[2] - a[2] * b[1];
    r[1] = a[2] * b[0] - a[0] * b[2];
    r[2] = a[0] * b[1] - a[1] * b[0];
    memcpy(out, r, sizeof r);
}

/* vsqrt */
float func_003DE7A0(float f)
{
    return sqrtf(f);
}

/* v0 = m0 * v1, x and y to 12.4 fixed point, z and w stay float bits */
void func_004135D0(int v0, int v1, int m0)
{
    float r[4];
    int32_t *o = PI32(v0);
    apply(r, P(m0), P(v1));
    o[0] = ftoi(r[0], 16.0f);
    o[1] = ftoi(r[1], 16.0f);
    memcpy(&o[2], &r[2], 8);
}

/* ---- Sony libvu0 (vu0_a.c, vu0_f.c and the assembly placeholders) ---- */

/* sceVu0ApplyMatrix(v0, m0, v1) */
void func_00102C70(int v0, int m0, int v1) { apply(P(v0), P(m0), P(v1)); }

/* sceVu0OuterProduct(v0, v1, v2): v0 = v1 x v2, w = 0 */
void func_00102CE8(int v0, int v1, int v2)
{
    float *a = P(v1), *b = P(v2), r[4];
    r[0] = a[1] * b[2] - a[2] * b[1];
    r[1] = a[2] * b[0] - a[0] * b[2];
    r[2] = a[0] * b[1] - a[1] * b[0];
    r[3] = 0.0f;
    memcpy(P(v0), r, sizeof r);
}

/* sceVu0InnerProduct (xyz) */
float func_00102D08(int v0, int v1)
{
    float *a = P(v0), *b = P(v1);
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

/* sceVu0Normalize(v0, v1): xyz / |xyz|, w = 0 */
void func_00102D30(int v0, int v1)
{
    float *a = P(v1), r[4];
    float q = 1.0f / sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    r[0] = a[0] * q;
    r[1] = a[1] * q;
    r[2] = a[2] * q;
    r[3] = 0.0f;
    memcpy(P(v0), r, sizeof r);
}

/* sceVu0TransposeMatrix(m0, m1) */
void func_00102D70(int m0, int m1)
{
    float *s = P(m1), r[16];
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            r[4 * i + j] = s[4 * j + i];
    memcpy(P(m0), r, sizeof r);
}

/* sceVu0InversMatrix(m0, m1) for a rotation + translation: transpose the
 * 3x3, translation = -(R^T t), m0[3].w = m1[3].w, rows 0..2 have w = 0 */
void func_00102DB8(int m0, int m1)
{
    float *s = P(m1), r[16];
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            r[4 * i + j] = s[4 * j + i];
        r[4 * i + 3] = 0.0f;
    }
    for (j = 0; j < 3; j++)
        r[12 + j] = -(r[j] * s[12] + r[4 + j] * s[13] + r[8 + j] * s[14]);
    r[15] = s[15];
    memcpy(P(m0), r, sizeof r);
}

/* sceVu0DivVector / DivVectorXYZ */
void func_00102E28(int v0, int v1, float q)
{
    float *a = P(v1), *o = P(v0), k = 1.0f / q;
    int i;
    for (i = 0; i < 4; i++)
        o[i] = a[i] * k;
}

void func_00102E48(int v0, int v1, float q)
{
    float *a = P(v1), *o = P(v0), k = 1.0f / q, w = a[3];
    int i;
    for (i = 0; i < 3; i++)
        o[i] = a[i] * k;
    o[3] = w;
}

/* sceVu0InterVector: v0 = v1*t + v2*(1-t) */
void func_00102E68(int v0, int v1, int v2, float t)
{
    float *a = P(v1), *b = P(v2), r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = a[i] * t + b[i] * (1.0f - t);
    memcpy(P(v0), r, sizeof r);
}

/* sceVu0AddVector / SubVector / MulVector */
void func_00102E90(int v0, int v1, int v2)
{
    float *a = P(v1), *b = P(v2), r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = a[i] + b[i];
    memcpy(P(v0), r, sizeof r);
}

void func_00102EA8(int v0, int v1, int v2)
{
    float *a = P(v1), *b = P(v2), r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = a[i] - b[i];
    memcpy(P(v0), r, sizeof r);
}

void func_00102EC0(int v0, int v1, int v2)
{
    float *a = P(v1), *b = P(v2), r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = a[i] * b[i];
    memcpy(P(v0), r, sizeof r);
}

/* sceVu0ScaleVector */
void func_00102ED8(int v0, int v1, float t)
{
    float *a = P(v1), *o = P(v0);
    int i;
    for (i = 0; i < 4; i++)
        o[i] = a[i] * t;
}

/* sceVu0TransMatrix(m0, m1, tv): copy, translation.xyz += tv.xyz */
void func_00102EF0(int m0, int m1, int tv)
{
    float r[16], *t = P(tv);
    memcpy(r, P(m1), sizeof r);
    r[12] += t[0];
    r[13] += t[1];
    r[14] += t[2];
    memcpy(P(m0), r, sizeof r);
}

/* sceVu0CopyVector */
void func_00102F20(int v0, int v1) { memmove(P(v0), P(v1), 16); }

/* sceVu0FTOI4Vector / FTOI0Vector / ITOF4Vector / ITOF0Vector */
void func_00102F58(int v0, int v1)
{
    float *a = P(v1);
    int32_t r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = ftoi(a[i], 16.0f);
    memcpy(PI32(v0), r, sizeof r);
}

void func_00102F68(int v0, int v1)
{
    float *a = P(v1);
    int32_t r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = ftoi(a[i], 1.0f);
    memcpy(PI32(v0), r, sizeof r);
}

void func_00102F78(int v0, int v1)
{
    int32_t *a = PI32(v1);
    float r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = (float)a[i] / 16.0f;
    memcpy(P(v0), r, sizeof r);
}

void func_00102F88(int v0, int v1)
{
    int32_t *a = PI32(v1);
    float r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = (float)a[i];
    memcpy(P(v0), r, sizeof r);
}

/* sceVu0UnitMatrix */
void func_00102F98(int m0)
{
    float *m = P(m0);
    memset(m, 0, 64);
    m[0] = m[5] = m[10] = m[15] = 1.0f;
}

/* sceVu0RotMatrixZ / X / Y (m0 = R applied to each row of m1).  The asm's
 * sin/cos (func_00102FC0, a polynomial on VU0) is sinf/cosf here. */
static void rot_apply(int m0, int m1, const float R[16])
{
    float s[16], r[16];
    int i;
    memcpy(s, P(m1), sizeof s);
    for (i = 0; i < 4; i++)
        apply(r + 4 * i, R, s + 4 * i);
    memcpy(P(m0), r, sizeof r);
}

void func_00103038(int m0, int m1, float rz)
{
    float c = cosf(rz), s = sinf(rz);
    float R[16] = { c, s, 0, 0,  -s, c, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1 };
    rot_apply(m0, m1, R);
}

void func_001030E0(int m0, int m1, float rx)
{
    float c = cosf(rx), s = sinf(rx);
    float R[16] = { 1, 0, 0, 0,  0, c, s, 0,  0, -s, c, 0,  0, 0, 0, 1 };
    rot_apply(m0, m1, R);
}

void func_00103188(int m0, int m1, float ry)
{
    float c = cosf(ry), s = sinf(ry);
    float R[16] = { c, 0, -s, 0,  0, 1, 0, 0,  s, 0, c, 0,  0, 0, 0, 1 };
    rot_apply(m0, m1, R);
}

/* sceVu0ClampVector */
void func_00103280(int v0, int v1, float mn, float mx)
{
    float *a = P(v1), r[4];
    int i;
    for (i = 0; i < 4; i++)
        r[i] = a[i] < mn ? mn : a[i] > mx ? mx : a[i];
    memcpy(P(v0), r, sizeof r);
}

/* sceVu0RotTransPers(v0, m0, v1, mode) */
void func_00103770(int v0, int m0, int v1, int mode)
{
    float r[4], q;
    int32_t o[4];
    int i;
    apply(r, P(m0), P(v1));
    q = 1.0f / r[3];
    for (i = 0; i < 3; i++)
        r[i] *= q;
    for (i = 0; i < 4; i++)
        o[i] = ftoi(r[i], 16.0f);
    if (mode) {
        o[2] = ftoi(r[2], 1.0f);
        o[3] = ftoi(r[3], 1.0f);
    }
    memcpy(PI32(v0), o, sizeof o);
}

/* sceVu0InterVectorXYZ: xyz interpolated, w = v1.w */
void func_001037D8(int v0, int v1, int v2, float t)
{
    float *a = P(v1), *b = P(v2), r[4];
    int i;
    for (i = 0; i < 3; i++)
        r[i] = a[i] * t + b[i] * (1.0f - t);
    r[3] = a[3];
    memcpy(P(v0), r, sizeof r);
}

/* sceVu0ScaleVectorXYZ: xyz *= t, w unchanged */
void func_00103808(int v0, int v1, float t)
{
    float *a = P(v1), *o = P(v0), w = a[3];
    int i;
    for (i = 0; i < 3; i++)
        o[i] = a[i] * t;
    o[3] = w;
}

/* MAC sticky flags of the guard-band subtractions: 0x40 any zero, 0x80 any negative */
static int clip_flags(const float *v)
{
    float t[5];
    int i, f = 0;
    t[0] = v[0];
    t[1] = v[1];
    t[2] = v[3];
    t[3] = 4096.0f - v[0];
    t[4] = 4096.0f - v[1];
    for (i = 0; i < 5; i++) {
        if (t[i] == 0.0f)
            f |= 0x40;
        if (signbit(t[i]))
            f |= 0x80;
    }
    return f;
}

/* sceVu0ClipScreen / ClipScreen3 */
int func_00103820(int v0) { return clip_flags(P(v0)); }

int func_00103868(int v0, int v1, int v2)
{
    return clip_flags(P(v0)) | clip_flags(P(v1)) | clip_flags(P(v2));
}
