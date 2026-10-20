/* Newlib 1.10 source ffbf3c2fe5af89ba84aad3359964ead31121b7ad, math/sf_tan.c. */
/* sf_tan.c -- float version of s_tan.c.
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
 */

/* Original fdlibm word access and actual PS2 single-precision format. */
#define _FLT_NO_DENORMALS
#define _FLT_LARGEST_EXPONENT_IS_NORMAL
#define tanf func_00117328
#define __kernel_tanf func_00115E18
#define __ieee754_rem_pio2f func_00113E78
extern float func_00115E18(float,float,int);
extern int func_00113E78(float,float*);
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




#ifdef __STDC__
        float tanf(float x)
#else
        float tanf(x)
        float x;
#endif
{
        float y[2],z=0.0;
        __int32_t n,ix;

        GET_FLOAT_WORD(ix,x);

    /* |x| ~< pi/4 */
        ix &= 0x7fffffff;
        if(ix <= 0x3f490fda) return __kernel_tanf(x,z,1);

    /* tan(Inf or NaN) is NaN */
        else if (!FLT_UWORD_IS_FINITE(ix)) return x-x;		/* NaN */

    /* argument reduction needed */
        else {
            n = __ieee754_rem_pio2f(x,y);
            return __kernel_tanf(y[0],y[1],1-((n&1)<<1)); /*   1 -- n even
                                                              -1 -- n odd */
        }
}

#ifdef _DOUBLE_IS_32BITS

#ifdef __STDC__
        double tan(double x)
#else
        double tan(x)
        double x;
#endif
{
        return (double) tanf((float) x);
}

#endif /* defined(_DOUBLE_IS_32BITS) */
