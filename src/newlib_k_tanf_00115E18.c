/* Newlib1.10 upstreamffbf3c2fe5af89ba84aad3359964ead31121b7ad, math/kf_tan.c. */
/* kf_tan.c -- float version of k_tan.c
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
#define fabsf func_00117078
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



#define __kernel_tanf func_00115E18

#ifdef __STDC__
static const float
#else
static float
#endif
one   =  1.0000000000e+00, /* 0x3f800000 */
pio4  =  7.8539812565e-01, /* 0x3f490fda */
pio4lo=  3.7748947079e-08, /* 0x33222168 */
T[] =  {
  3.3333334327e-01, /* 0x3eaaaaab */
  1.3333334029e-01, /* 0x3e088889 */
  5.3968254477e-02, /* 0x3d5d0dd1 */
  2.1869488060e-02, /* 0x3cb327a4 */
  8.8632395491e-03, /* 0x3c11371f */
  3.5920790397e-03, /* 0x3b6b6916 */
  1.4562094584e-03, /* 0x3abede48 */
  5.8804126456e-04, /* 0x3a1a26c8 */
  2.4646313977e-04, /* 0x398137b9 */
  7.8179444245e-05, /* 0x38a3f445 */
  7.1407252108e-05, /* 0x3895c07a */
 -1.8558637748e-05, /* 0xb79bae5f */
  2.5907305826e-05, /* 0x37d95384 */
};

#ifdef __STDC__
        float __kernel_tanf(float x, float y, int iy)
#else
        float __kernel_tanf(x, y, iy)
        float x,y; int iy;
#endif
{
        float z,r,v,w,s;
        __int32_t ix,hx;
        GET_FLOAT_WORD(hx,x);
        ix = hx&0x7fffffff;	/* high word of |x| */
        if(ix<0x31800000)			/* x < 2**-28 */
            {if((int)x==0) {			/* generate inexact */
                if((ix|(iy+1))==0) return one/fabsf(x);
                else return (iy==1)? x: -one/x;
            }
            }
        if(ix>=0x3f2ca140) { 			/* |x|>=0.6744 */
            if(hx<0) {x = -x; y = -y;}
            z = pio4-x;
            w = pio4lo-y;
            x = z+w; y = 0.0;
        }
        z	=  x*x;
        w 	=  z*z;
    /* Break x^5*(T[1]+x^2*T[2]+...) into
     *	  x^5(T[1]+x^4*T[3]+...+x^20*T[11]) +
     *	  x^5(x^2*(T[2]+x^4*T[4]+...+x^22*[T12]))
     */
        r = T[1]+w*(T[3]+w*(T[5]+w*(T[7]+w*(T[9]+w*T[11]))));
        v = z*(T[2]+w*(T[4]+w*(T[6]+w*(T[8]+w*(T[10]+w*T[12])))));
        s = z*x;
        r = y + z*(s*(r+v)+y);
        r += T[0]*s;
        w = x+r;
        if(ix>=0x3f2ca140) {
            v = (float)iy;
            return (float)(1-((hx>>30)&2))*(v-(float)2.0*(x-(w*w/(w+v)-r)));
        }
        if(iy==1) return w;
        else {		/* if allow error up to 2 ulp,
                           simply return -1.0/(x+r) here */
     /*  compute -1.0/(x+r) accurately */
            float a,t;
            __int32_t i;
            z  = w;
            GET_FLOAT_WORD(i,z);
            SET_FLOAT_WORD(z,i&0xfffff000);
            v  = r-(z - x); 	/* z+v = r+x */
            t = a  = -(float)1.0/w;	/* a = -1.0/w */
            GET_FLOAT_WORD(i,t);
            SET_FLOAT_WORD(t,i&0xfffff000);
            s  = (float)1.0+t*z;
            return t+a*(s+t*v);
        }
}
