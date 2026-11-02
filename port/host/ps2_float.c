/*
 * EE FPU single-precision arithmetic on the host (PS2_FLOAT_NO_REWRITE).
 *
 * The EE's COP1 rounds every single-precision result toward zero and has no
 * denormals; the host (x86 SSE, wasm) rounds to nearest.  A 1-ulp difference
 * per operation changes positions (369.99997 vs 370.0), then what truncates
 * them, then hits.  port/tools/ps2_fp_rewrite.pl turns every float
 * fadd/fsub/fmul/fdiv/sqrt and int->float conversion of the game's code
 * (LLVM IR, before optimisation) into calls of these helpers, which give the
 * result the EE gives, as the Play! core (SSE in round-toward-zero with
 * flush-to-zero and denormals-are-zero) models it: the exact result rounded
 * toward zero, denormal inputs and outputs as signed zero, overflow as the
 * largest finite float.  Doubles are left alone: the EE has no double unit
 * and the game's doubles are libgcc soft-float, which rounds to nearest.
 *
 * Each helper computes in double and corrects the nearest float toward
 * zero: products of two floats are exact in double; sums are corrected with
 * the TwoSum error term, quotients and square roots with an exact back
 * multiplication.  This file itself must not be rewritten.
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* MVC2_PS2FP_OFF=1 (testing, A/B): the helpers round to nearest like the
 * host, i.e. the game runs as it did before this file */
static int fp_off = -1;
/* arcade.float_round (port/host/fe/fe_arcade.c): the NAOMI's SH-4 runs the
 * game with round-to-nearest (fpscr RM = 0), so the arcade setting gives the
 * helpers the host's own rounding */
void ps2_float_set_nearest(int on)
{
    const char *e = getenv("MVC2_PS2FP_OFF");
    fp_off = on || (e && *e && *e != '0');
}
static inline int off(void)
{
    if (__builtin_expect(fp_off < 0, 0)) {
        const char *e = getenv("MVC2_PS2FP_OFF");
        fp_off = e && *e && *e != '0';
    }
    return fp_off;
}

typedef float f32;

static inline uint32_t fbits(f32 f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static inline f32 bitsf(uint32_t u) { f32 f; memcpy(&f, &u, 4); return f; }

/* denormal -> signed zero (EE inputs and outputs) */
static inline f32 daz(f32 f)
{
    uint32_t u = fbits(f);
    if ((u & 0x7F800000u) == 0)
        return bitsf(u & 0x80000000u);
    return f;
}

/* the float toward zero of exact = d + tail, where d is the double nearest
 * to exact and only the sign of tail is known (0: d is exact) */
static f32 rz(double d, int tail)
{
    f32 f;
    double df, ad;
    uint32_t u;
    if (d != d)
        return (f32)d;
    ad = d < 0 ? -d : d;
    if (ad > 3.4028234663852886e38) { /* beyond FLT_MAX (and inf from finite ops) */
        if (ad == __builtin_inf())
            return (f32)d;
        return d < 0 ? -3.4028234663852886e38f : 3.4028234663852886e38f;
    }
    f = (f32)d;
    df = f;
    if ((df < 0 ? -df : df) > ad || (df == d && tail != 0 && ((d > 0) != (tail > 0)) && d != 0)) {
        u = fbits(f);
        if (u & 0x7FFFFFFFu)
            f = bitsf(u - 1); /* one ulp toward zero (sign-magnitude) */
    }
    return daz(f);
}

static inline int sgn(double x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }

f32 ps2_fadd(f32 a, f32 b)
{
    if (off())
        return a + b;
    double s, bb, e;
    a = daz(a);
    b = daz(b);
    s = (double)a + (double)b;
    if (s - s != 0) /* inf or nan */
        return (f32)s;
    bb = s - (double)a;
    e = ((double)a - (s - bb)) + ((double)b - bb);
    return rz(s, sgn(e));
}

f32 ps2_fsub(f32 a, f32 b)
{
    return ps2_fadd(a, -b);
}

f32 ps2_fmul(f32 a, f32 b)
{
    if (off())
        return a * b;
    double p;
    a = daz(a);
    b = daz(b);
    p = (double)a * (double)b; /* exact: 24 x 24 bits */
    if (p - p != 0)
        return (f32)p;
    return rz(p, 0);
}

f32 ps2_fdiv(f32 a, f32 b)
{
    if (off())
        return a / b;
    double q, t;
    f32 f;
    a = daz(a);
    b = daz(b);
    if (b == 0) {
        /* the EE gives the largest float with the quotient's sign (the
         * oracle: 7F7FFFFF where the host had +inf, Thanos run) */
        uint32_t s = (fbits(a) ^ fbits(b)) & 0x80000000u;
        return bitsf(s | 0x7F7FFFFFu);
    }
    q = (double)a / (double)b;
    if (q - q != 0)
        return (f32)q;
    f = (f32)q;
    if ((double)f == q) {
        /* q is a float: b * q is exact (48 bits), so is a - b * q */
        t = (double)a - (double)b * q;
        return rz(q, sgn(t) * sgn((double)b));
    }
    return rz(q, 0);
}

f32 ps2_fsqrt(f32 a)
{
    if (off())
        return __builtin_sqrtf(a);
    double s;
    f32 f;
    a = daz(a);
    if (a <= 0 || a != a || a == __builtin_inff())
        return __builtin_sqrtf(a);
    s = __builtin_sqrt((double)a);
    f = (f32)s;
    if ((double)f == s) {
        double sq = (double)f * (double)f; /* exact */
        return rz(s, sq > (double)a ? -1 : sq < (double)a ? 1 : 0);
    }
    return rz(s, 0);
}

f32 ps2_i2f(int32_t i)
{
    if (off())
        return (f32)i;
    return rz((double)i, 0); /* exact in double */
}

f32 ps2_u2f(uint32_t i)
{
    if (off())
        return (f32)i;
    return rz((double)i, 0);
}

f32 ps2_l2f(int64_t i)
{
    double d = (double)i; /* rare: nearest double, then toward zero */
    return rz(d, sgn((double)(i - (int64_t)d)));
}

f32 ps2_ul2f(uint64_t i)
{
    double d = (double)i;
    return rz(d, i > (uint64_t)d ? 1 : i < (uint64_t)d ? -1 : 0);
}

/* double -> float: the game's conversion is the soft-float dptofp (the EE
 * toolchain's fp-bit __truncdfsf2), which the oracle shows truncating too
 * (func_00161240: -(f32)(1.0 - 0.0125 * x) is 0xBF7CCCCC on the PS2,
 * 0xBF7CCCCD rounded to nearest). */
f32 ps2_d2f(double d)
{
    if (off())
        return (f32)d;
    return rz(d, 0);
}
