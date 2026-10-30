/*
 * Game functions whose retail code has no credited C, written for the host
 * from the retail asm (Port J).  Each is a direct transcription; the asm is
 * in asm/main.s at the function's address.  Only two are left:
 *   func_003DE230  VU0 macro-mode code (src/vu0_macro_math.S in the decomp)
 *   func_001E7CB0  not matched (REMAINING.md: a 10-word scheduling near miss)
 * Every other stand-in that used to live here is credited C now and the
 * game's own code runs (BOOT_NOTES.md, 2026-10-30).
 */
#include <string.h>
#include "host.h"

/* func_003DE230(out, a, b): VU0 3x3 product of the rotation parts,
 * out.row[i].xyz = a.row[i].x * b.row[0] + a.row[i].y * b.row[1] + a.row[i].z * b.row[2]
 * (rows of 4 floats; w and row 3 of out untouched).  Inputs are copied
 * first, as the asm does, so out may alias them. */
void func_003DE230(int outp, int ap, int bp)
{
    float a[16], b[16], *o = (float *)(uintptr_t)outp;
    int i, k;
    memcpy(a, (void *)(uintptr_t)ap, 64);
    memcpy(b, (void *)(uintptr_t)bp, 64);
    for (i = 0; i < 3; i++)
        for (k = 0; k < 3; k++)
            o[4 * i + k] = a[4 * i] * b[k] + a[4 * i + 1] * b[4 + k] + a[4 * i + 2] * b[8 + k];
}

/* func_001E7CB0(A, B, boxA, boxB, out): overlap of two characters' boxes.
 * Boxes are s16 {x, w, y, h} at *(A + 0x180) + index * 8, in units scaled by
 * 5/3 horizontally and 15/7 vertically and by each character's scale
 * (+0x50, +0x54); x mirrors with the facing flag s16 +0x140, positions are
 * +0x34 / +0x38.  When |dx| < wA + wB and |dy| < hA + hB (zero widths or
 * heights of B never overlap) it stores the vertical overlap in *out and
 * sets B[0x1B3] = 1.  C from the asm. */
void func_001E7CB0(int a0, int a1, int a2, int a3, int t0)
{
    u8 *A = (u8 *)(uintptr_t)a0, *B = (u8 *)(uintptr_t)a1;
    const s16 *ba = (const s16 *)(uintptr_t)(*(u32 *)(A + 0x180) + (u32)(a2 & 0xFFFF) * 8);
    const s16 *bb = (const s16 *)(uintptr_t)(*(u32 *)(B + 0x180) + (u32)(a3 & 0xFFFF) * 8);
    const float kx = 1.6666666269302368f, ky = 2.142857074737549f;
    float sa = *(float *)(A + 0x50), sb = *(float *)(B + 0x50), xa, xb, d, wa, wb, ya, yb, ha, hb;
    xa = kx * (float)ba[0] * sa;
    xb = kx * (float)bb[0] * sb;
    if (*(s16 *)(A + 0x140))
        xa = -xa;
    xa += *(float *)(A + 0x34);
    if (*(s16 *)(B + 0x140))
        xb = -xb;
    xb += *(float *)(B + 0x34);
    d = xa - xb;
    if (d < 0)
        d = -d;
    wb = kx * (float)bb[1] * sb;
    if (wb == 0.0f)
        return;
    wa = kx * (float)ba[1] * sa;
    if (!(d < wb + wa))
        return;
    sa = *(float *)(A + 0x54);
    sb = *(float *)(B + 0x54);
    ya = -(ky * (float)ba[2] * sa) + *(float *)(A + 0x38);
    yb = -(ky * (float)bb[2] * sb) + *(float *)(B + 0x38);
    d = ya - yb;
    if (d < 0)
        d = -d;
    hb = ky * (float)bb[3] * sb;
    if (hb == 0.0f)
        return;
    ha = ky * (float)ba[3] * sa;
    if (!(d < hb + ha))
        return;
    *(float *)(uintptr_t)t0 = hb + ha - d;
    B[0x1B3] = 1;
}
