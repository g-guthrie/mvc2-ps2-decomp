/* Newlib1.10 upstreamffbf3c2fe5af89ba84aad3359964ead31121b7ad, math/ef_rem_pio2.c. */
/* ef_rem_pio2.c -- float version of e_rem_pio2.c
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

/* __ieee754_rem_pio2f(x,y)
 *
 * return the remainder of x rem pi/2 in y[0]+y[1]
 * use __kernel_rem_pio2f()
 */

/* Original fdlibm word access and actual PS2 single-precision format. */
#define _FLT_NO_DENORMALS
#define _FLT_LARGEST_EXPONENT_IS_NORMAL
#define __ieee754_rem_pio2f func_00113E78
#define __kernel_rem_pio2f func_001154A8
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



extern int func_001154A8(float *,float *,int,int,int,const __int32_t *);


/*
 * Table of constants for 2/pi, 396 Hex digits (476 decimal) of 2/pi
 */
#ifdef __STDC__
static const __int32_t two_over_pi[] = {
#else
static __int32_t two_over_pi[] = {
#endif
0xA2, 0xF9, 0x83, 0x6E, 0x4E, 0x44, 0x15, 0x29, 0xFC,
0x27, 0x57, 0xD1, 0xF5, 0x34, 0xDD, 0xC0, 0xDB, 0x62,
0x95, 0x99, 0x3C, 0x43, 0x90, 0x41, 0xFE, 0x51, 0x63,
0xAB, 0xDE, 0xBB, 0xC5, 0x61, 0xB7, 0x24, 0x6E, 0x3A,
0x42, 0x4D, 0xD2, 0xE0, 0x06, 0x49, 0x2E, 0xEA, 0x09,
0xD1, 0x92, 0x1C, 0xFE, 0x1D, 0xEB, 0x1C, 0xB1, 0x29,
0xA7, 0x3E, 0xE8, 0x82, 0x35, 0xF5, 0x2E, 0xBB, 0x44,
0x84, 0xE9, 0x9C, 0x70, 0x26, 0xB4, 0x5F, 0x7E, 0x41,
0x39, 0x91, 0xD6, 0x39, 0x83, 0x53, 0x39, 0xF4, 0x9C,
0x84, 0x5F, 0x8B, 0xBD, 0xF9, 0x28, 0x3B, 0x1F, 0xF8,
0x97, 0xFF, 0xDE, 0x05, 0x98, 0x0F, 0xEF, 0x2F, 0x11,
0x8B, 0x5A, 0x0A, 0x6D, 0x1F, 0x6D, 0x36, 0x7E, 0xCF,
0x27, 0xCB, 0x09, 0xB7, 0x4F, 0x46, 0x3F, 0x66, 0x9E,
0x5F, 0xEA, 0x2D, 0x75, 0x27, 0xBA, 0xC7, 0xEB, 0xE5,
0xF1, 0x7B, 0x3D, 0x07, 0x39, 0xF7, 0x8A, 0x52, 0x92,
0xEA, 0x6B, 0xFB, 0x5F, 0xB1, 0x1F, 0x8D, 0x5D, 0x08,
0x56, 0x03, 0x30, 0x46, 0xFC, 0x7B, 0x6B, 0xAB, 0xF0,
0xCF, 0xBC, 0x20, 0x9A, 0xF4, 0x36, 0x1D, 0xA9, 0xE3,
0x91, 0x61, 0x5E, 0xE6, 0x1B, 0x08, 0x65, 0x99, 0x85,
0x5F, 0x14, 0xA0, 0x68, 0x40, 0x8D, 0xFF, 0xD8, 0x80,
0x4D, 0x73, 0x27, 0x31, 0x06, 0x06, 0x15, 0x56, 0xCA,
0x73, 0xA8, 0xC9, 0x60, 0xE2, 0x7B, 0xC0, 0x8C, 0x6B,
};

/* This array is like the one in e_rem_pio2.c, but the numbers are
   single precision and the last 8 bits are forced to 0.  */
#ifdef __STDC__
static const __int32_t npio2_hw[] = {
#else
static __int32_t npio2_hw[] = {
#endif
0x3fc90f00, 0x40490f00, 0x4096cb00, 0x40c90f00, 0x40fb5300, 0x4116cb00,
0x412fed00, 0x41490f00, 0x41623100, 0x417b5300, 0x418a3a00, 0x4196cb00,
0x41a35c00, 0x41afed00, 0x41bc7e00, 0x41c90f00, 0x41d5a000, 0x41e23100,
0x41eec200, 0x41fb5300, 0x4203f200, 0x420a3a00, 0x42108300, 0x4216cb00,
0x421d1400, 0x42235c00, 0x4229a500, 0x422fed00, 0x42363600, 0x423c7e00,
0x4242c700, 0x42490f00
};

/*
 * invpio2:  24 bits of 2/pi
 * pio2_1:   first  17 bit of pi/2
 * pio2_1t:  pi/2 - pio2_1
 * pio2_2:   second 17 bit of pi/2
 * pio2_2t:  pi/2 - (pio2_1+pio2_2)
 * pio2_3:   third  17 bit of pi/2
 * pio2_3t:  pi/2 - (pio2_1+pio2_2+pio2_3)
 */

#ifdef __STDC__
static const float
#else
static float
#endif
zero =  0.0000000000e+00, /* 0x00000000 */
half =  5.0000000000e-01, /* 0x3f000000 */
two8 =  2.5600000000e+02, /* 0x43800000 */
invpio2 =  6.3661980629e-01, /* 0x3f22f984 */
pio2_1  =  1.5707855225e+00, /* 0x3fc90f80 */
pio2_1t =  1.0804334124e-05, /* 0x37354443 */
pio2_2  =  1.0804273188e-05, /* 0x37354400 */
pio2_2t =  6.0770999344e-11, /* 0x2e85a308 */
pio2_3  =  6.0770943833e-11, /* 0x2e85a300 */
pio2_3t =  6.1232342629e-17; /* 0x248d3132 */

#ifdef __STDC__
        __int32_t __ieee754_rem_pio2f(float x, float *y)
#else
        __int32_t __ieee754_rem_pio2f(x,y)
        float x,y[];
#endif
{
        float z,w,t,r,fn;
        float tx[3];
        __int32_t i,j,n,ix,hx;
        int e0,nx;

        GET_FLOAT_WORD(hx,x);
        ix = hx&0x7fffffff;
        if(ix<=0x3f490fd8)   /* |x| ~<= pi/4 , no need for reduction */
            {y[0] = x; y[1] = 0; return 0;}
        if(ix<0x4016cbe4) {  /* |x| < 3pi/4, special case with n=+-1 */
            if(hx>0) {
                z = x - pio2_1;
                if((ix&0xfffffff0)!=0x3fc90fd0) { /* 24+24 bit pi OK */
                    y[0] = z - pio2_1t;
                    y[1] = (z-y[0])-pio2_1t;
                } else {		/* near pi/2, use 24+24+24 bit pi */
                    z -= pio2_2;
                    y[0] = z - pio2_2t;
                    y[1] = (z-y[0])-pio2_2t;
                }
                return 1;
            } else {	/* negative x */
                z = x + pio2_1;
                if((ix&0xfffffff0)!=0x3fc90fd0) { /* 24+24 bit pi OK */
                    y[0] = z + pio2_1t;
                    y[1] = (z-y[0])+pio2_1t;
                } else {		/* near pi/2, use 24+24+24 bit pi */
                    z += pio2_2;
                    y[0] = z + pio2_2t;
                    y[1] = (z-y[0])+pio2_2t;
                }
                return -1;
            }
        }
        if(ix<=0x43490f80) { /* |x| ~<= 2^7*(pi/2), medium size */
            t  = fabsf(x);
            n  = (__int32_t) (t*invpio2+half);
            fn = (float)n;
            r  = t-fn*pio2_1;
            w  = fn*pio2_1t;	/* 1st round good to 40 bit */
            if(n<32&&(ix&0xffffff00)!=npio2_hw[n-1]) {
                y[0] = r-w;	/* quick check no cancellation */
            } else {
                __uint32_t high;
                j  = ix>>23;
                y[0] = r-w;
                GET_FLOAT_WORD(high,y[0]);
                i = j-((high>>23)&0xff);
                if(i>8) {  /* 2nd iteration needed, good to 57 */
                    t  = r;
                    w  = fn*pio2_2;
                    r  = t-w;
                    w  = fn*pio2_2t-((t-r)-w);
                    y[0] = r-w;
                    GET_FLOAT_WORD(high,y[0]);
                    i = j-((high>>23)&0xff);
                    if(i>25)  {	/* 3rd iteration need, 74 bits acc */
                        t  = r;	/* will cover all possible cases */
                        w  = fn*pio2_3;
                        r  = t-w;
                        w  = fn*pio2_3t-((t-r)-w);
                        y[0] = r-w;
                    }
                }
            }
            y[1] = (r-y[0])-w;
            if(hx<0) 	{y[0] = -y[0]; y[1] = -y[1]; return -n;}
            else	 return n;
        }
    /*
     * all other (large) arguments
     */
        if(!FLT_UWORD_IS_FINITE(ix)) {
            y[0]=y[1]=x-x; return 0;
        }
    /* set z = scalbn(|x|,ilogb(x)-7) */
        e0 	= (int)((ix>>23)-134);	/* e0 = ilogb(z)-7; */
        SET_FLOAT_WORD(z, ix - ((__int32_t)e0<<23));
        for(i=0;i<2;i++) {
                tx[i] = (float)((__int32_t)(z));
                z     = (z-tx[i])*two8;
        }
        tx[2] = z;
        nx = 3;
        while(tx[nx-1]==zero) nx--;	/* skip zero term */
        n  =  __kernel_rem_pio2f(tx,y,e0,nx,2,two_over_pi);
        if(hx<0) {y[0] = -y[0]; y[1] = -y[1]; return -n;}
        return n;
}
