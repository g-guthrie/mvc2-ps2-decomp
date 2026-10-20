/* Newlib1.10 upstreamffbf3c2fe5af89ba84aad3359964ead31121b7ad, math/ef_atan2.c. */
/* ef_atan2.c -- float version of e_atan2.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 *
 */

/* Original fdlibm word access and actual PS2 single-precision format. */
#define _FLT_NO_DENORMALS
#define _FLT_LARGEST_EXPONENT_IS_NORMAL
#define __ieee754_atan2f func_001130F0
#define atanf func_00116CD0
#define fabsf func_00117078
extern float func_00116CD0(float);
extern float func_00117078(float);
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef union { float value; __uint32_t word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value=(d); (i)=gf_u.word; } while(0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word=(i); (d)=sf_u.value; } while(0)
/* Most routines need to check whether a float is finite, infinite, or not a
   number, and many need to know whether the result of an operation will
   overflow.  These conditions depend on whether the largest exponent is
   used for NaNs & infinities, or whether it's used for finite numbers.  The
   macros below wrap up that kind of information:

   FLT_UWORD_IS_FINITE(X)
        True if a positive float with bitmask X is finite.

   FLT_UWORD_IS_NAN(X)
        True if a positive float with bitmask X is not a number.

   FLT_UWORD_IS_INFINITE(X)
        True if a positive float with bitmask X is +infinity.

   FLT_UWORD_MAX
        The bitmask of FLT_MAX.

   FLT_UWORD_HALF_MAX
        The bitmask of FLT_MAX/2.

   FLT_UWORD_EXP_MAX
        The bitmask of the largest finite exponent (129 if the largest
        exponent is used for finite numbers, 128 otherwise).

   FLT_UWORD_LOG_MAX
        The bitmask of log(FLT_MAX), rounded down.  This value is the largest
        input that can be passed to exp() without producing overflow.

   FLT_UWORD_LOG_2MAX
        The bitmask of log(2*FLT_MAX), rounded down.  This value is the
        largest input than can be passed to cosh() without producing
        overflow.

   FLT_LARGEST_EXP
        The largest biased exponent that can be used for finite numbers
        (255 if the largest exponent is used for finite numbers, 254
        otherwise) */

#ifdef _FLT_LARGEST_EXPONENT_IS_NORMAL
#define FLT_UWORD_IS_FINITE(x) 1
#define FLT_UWORD_IS_NAN(x) 0
#define FLT_UWORD_IS_INFINITE(x) 0
#define FLT_UWORD_MAX 0x7fffffff
#define FLT_UWORD_EXP_MAX 0x43010000
#define FLT_UWORD_LOG_MAX 0x42b2d4fc
#define FLT_UWORD_LOG_2MAX 0x42b437e0
#define HUGE ((float)0X1.FFFFFEP128)
#else
#define FLT_UWORD_IS_FINITE(x) ((x)<0x7f800000L)
#define FLT_UWORD_IS_NAN(x) ((x)>0x7f800000L)
#define FLT_UWORD_IS_INFINITE(x) ((x)==0x7f800000L)
#define FLT_UWORD_MAX 0x7f7fffff
#define FLT_UWORD_EXP_MAX 0x43000000
#define FLT_UWORD_LOG_MAX 0x42b17217
#define FLT_UWORD_LOG_2MAX 0x42b2d4fc
#define HUGE ((float)3.40282346638528860e+38)
#endif
#define FLT_UWORD_HALF_MAX (FLT_UWORD_MAX-(1<<23))
#define FLT_LARGEST_EXP (FLT_UWORD_MAX>>23)

/* Many routines check for zero and subnormal numbers.  Such things depend
   on whether the target supports denormals or not:

   FLT_UWORD_IS_ZERO(X)
        True if a positive float with bitmask X is +0.	Without denormals,
        any float with a zero exponent is a +0 representation.	With
        denormals, the only +0 representation is a 0 bitmask.

   FLT_UWORD_IS_SUBNORMAL(X)
        True if a non-zero positive float with bitmask X is subnormal.
        (Routines should check for zeros first.)

   FLT_UWORD_MIN
        The bitmask of the smallest float above +0.  Call this number
        REAL_FLT_MIN...

   FLT_UWORD_EXP_MIN
        The bitmask of the float representation of REAL_FLT_MIN's exponent.

   FLT_UWORD_LOG_MIN
        The bitmask of |log(REAL_FLT_MIN)|, rounding down.

   FLT_SMALLEST_EXP
        REAL_FLT_MIN's exponent - EXP_BIAS (1 if denormals are not supported,
        -22 if they are).
*/

#ifdef _FLT_NO_DENORMALS
#define FLT_UWORD_IS_ZERO(x) ((x)<0x00800000L)
#define FLT_UWORD_IS_SUBNORMAL(x) 0
#define FLT_UWORD_MIN 0x00800000
#define FLT_UWORD_EXP_MIN 0x42fc0000
#define FLT_UWORD_LOG_MIN 0x42aeac50
#define FLT_SMALLEST_EXP 1
#else
#define FLT_UWORD_IS_ZERO(x) ((x)==0)
#define FLT_UWORD_IS_SUBNORMAL(x) ((x)<0x00800000L)
#define FLT_UWORD_MIN 0x00000001
#define FLT_UWORD_EXP_MIN 0x43160000
#define FLT_UWORD_LOG_MIN 0x42cff1b5
#define FLT_SMALLEST_EXP -22
#endif


/* Original scalar values; no constant object has an address use. */
#define tiny 1.0e-30F
#define zero 0.0F
#define pi_o_4 7.8539818525e-01F
#define pi_o_2 1.5707963705e+00F
#define pi 3.1415925026e+00F
#define pi_lo 1.5099578832e-07F

#ifdef __STDC__
        float __ieee754_atan2f(float y, float x)
#else
        float __ieee754_atan2f(y,x)
        float  y,x;
#endif
{
        float z;
        __int32_t k,m,hx,hy,ix,iy;

        GET_FLOAT_WORD(hx,x);
        ix = hx&0x7fffffff;
        GET_FLOAT_WORD(hy,y);
        iy = hy&0x7fffffff;
        if(FLT_UWORD_IS_NAN(ix)||
           FLT_UWORD_IS_NAN(iy))	/* x or y is NaN */
           return x+y;
        if(hx==0x3f800000) return atanf(y);   /* x=1.0 */
        m = ((hy>>31)&1)|((hx>>30)&2);	/* 2*sign(x)+sign(y) */

    /* when y = 0 */
        if(FLT_UWORD_IS_ZERO(iy)) {
            switch(m) {
                case 0:
                case 1: return y; 	/* atan(+-0,+anything)=+-0 */
                case 2: return  pi+tiny;/* atan(+0,-anything) = pi */
                case 3: return -pi-tiny;/* atan(-0,-anything) =-pi */
            }
        }
    /* when x = 0 */
        if(FLT_UWORD_IS_ZERO(ix)) return (hy<0)?  -pi_o_2-tiny: pi_o_2+tiny;

    /* when x is INF */
        if(FLT_UWORD_IS_INFINITE(ix)) {
            if(FLT_UWORD_IS_INFINITE(iy)) {
                switch(m) {
                    case 0: return  pi_o_4+tiny;/* atan(+INF,+INF) */
                    case 1: return -pi_o_4-tiny;/* atan(-INF,+INF) */
                    case 2: return  (float)3.0*pi_o_4+tiny;/*atan(+INF,-INF)*/
                    case 3: return (float)-3.0*pi_o_4-tiny;/*atan(-INF,-INF)*/
                }
            } else {
                switch(m) {
                    case 0: return  zero  ;	/* atan(+...,+INF) */
                    case 1: return -zero  ;	/* atan(-...,+INF) */
                    case 2: return  pi+tiny  ;	/* atan(+...,-INF) */
                    case 3: return -pi-tiny  ;	/* atan(-...,-INF) */
                }
            }
        }
    /* when y is INF */
        if(FLT_UWORD_IS_INFINITE(iy)) return (hy<0)? -pi_o_2-tiny: pi_o_2+tiny;

    /* compute y/x */
        k = (iy-ix)>>23;
        if(k > 60) z=pi_o_2+(float)0.5*pi_lo; 	/* |y/x| >  2**60 */
        else if(hx<0&&k<-60) z=0.0; 	/* |y|/x < -2**60 */
        else z=atanf(fabsf(y/x));	/* safe to do y/x */
        switch (m) {
            case 0: return       z  ;	/* atan(+,+) */
            case 1: {
                      __uint32_t zh;
                      GET_FLOAT_WORD(zh,z);
                      SET_FLOAT_WORD(z,zh ^ 0x80000000);
                    }
                    return       z  ;	/* atan(-,+) */
            case 2: return  pi-(z-pi_lo);/* atan(+,-) */
            default: /* case 3 */
                    return  (z-pi_lo)-pi;/* atan(-,-) */
        }
}
