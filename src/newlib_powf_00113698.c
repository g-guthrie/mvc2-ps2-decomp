/* Newlib1.10 upstreamffbf3c2fe5af89ba84aad3359964ead31121b7ad, math/ef_pow.c. */
/* ef_pow.c -- float version of e_pow.c.
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
#define __ieee754_powf func_00113698
#define __ieee754_sqrtf func_00114228
#define scalbnf func_00117178
#define fabsf func_00117078
extern float func_00114228(float);
extern float func_00117178(float,int);
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




#ifdef __v810__
#define const
#endif

#ifdef __STDC__
static const float
#else
static float
#endif
bp[] = {1.0, 1.5,},
dp_h[] = { 0.0, 5.84960938e-01,}, /* 0x3f15c000 */
dp_l[] = { 0.0, 1.56322085e-06,}, /* 0x35d1cfdc */
zero    =  0.0,
one	=  1.0,
two	=  2.0,
two24	=  16777216.0,	/* 0x4b800000 */
huge	=  1.0e30,
tiny    =  1.0e-30,
        /* poly coefs for (3/2)*(log(x)-2s-2/3*s**3 */
L1  =  6.0000002384e-01, /* 0x3f19999a */
L2  =  4.2857143283e-01, /* 0x3edb6db7 */
L3  =  3.3333334327e-01, /* 0x3eaaaaab */
L4  =  2.7272811532e-01, /* 0x3e8ba305 */
L5  =  2.3066075146e-01, /* 0x3e6c3255 */
L6  =  2.0697501302e-01, /* 0x3e53f142 */
P1   =  1.6666667163e-01, /* 0x3e2aaaab */
P2   = -2.7777778450e-03, /* 0xbb360b61 */
P3   =  6.6137559770e-05, /* 0x388ab355 */
P4   = -1.6533901999e-06, /* 0xb5ddea0e */
P5   =  4.1381369442e-08, /* 0x3331bb4c */
lg2  =  6.9314718246e-01, /* 0x3f317218 */
lg2_h  =  6.93145752e-01, /* 0x3f317200 */
lg2_l  =  1.42860654e-06, /* 0x35bfbe8c */
ovt =  4.2995665694e-08, /* -(128-log2(ovfl+.5ulp)) */
cp    =  9.6179670095e-01, /* 0x3f76384f =2/(3ln2) */
cp_h  =  9.6179199219e-01, /* 0x3f763800 =head of cp */
cp_l  =  4.7017383622e-06, /* 0x369dc3a0 =tail of cp_h */
ivln2    =  1.4426950216e+00, /* 0x3fb8aa3b =1/ln2 */
ivln2_h  =  1.4426879883e+00, /* 0x3fb8aa00 =16b 1/ln2*/
ivln2_l  =  7.0526075433e-06; /* 0x36eca570 =1/ln2 tail*/

#ifdef __STDC__
        float __ieee754_powf(float x, float y)
#else
        float __ieee754_powf(x,y)
        float x, y;
#endif
{
        float z,ax,z_h,z_l,p_h,p_l;
        float y1,t1,t2,r,s,t,u,v,w;
        __int32_t i,j,k,yisint,n;
        __int32_t hx,hy,ix,iy,is;

        GET_FLOAT_WORD(hx,x);
        GET_FLOAT_WORD(hy,y);
        ix = hx&0x7fffffff;  iy = hy&0x7fffffff;

    /* y==zero: x**0 = 1 */
        if(FLT_UWORD_IS_ZERO(iy)) return one;

    /* +-NaN return x+y */
        if(FLT_UWORD_IS_NAN(ix) ||
           FLT_UWORD_IS_NAN(iy))
                return x+y;

    /* determine if y is an odd int when x < 0
     * yisint = 0	... y is not an integer
     * yisint = 1	... y is an odd int
     * yisint = 2	... y is an even int
     */
        yisint  = 0;
        if(hx<0) {
            if(iy>=0x4b800000) yisint = 2; /* even integer y */
            else if(iy>=0x3f800000) {
                k = (iy>>23)-0x7f;	   /* exponent */
                j = iy>>(23-k);
                if((j<<(23-k))==iy) yisint = 2-(j&1);
            }
        }

    /* special value of y */
        if (FLT_UWORD_IS_INFINITE(iy)) {	/* y is +-inf */
            if (ix==0x3f800000)
                return  y - y;	/* inf**+-1 is NaN */
            else if (ix > 0x3f800000)/* (|x|>1)**+-inf = inf,0 */
                return (hy>=0)? y: zero;
            else			/* (|x|<1)**-,+inf = inf,0 */
                return (hy<0)?-y: zero;
        }
        if(iy==0x3f800000) {	/* y is  +-1 */
            if(hy<0) return one/x; else return x;
        }
        if(hy==0x40000000) return x*x; /* y is  2 */
        if(hy==0x3f000000) {	/* y is  0.5 */
            if(hx>=0)	/* x >= +0 */
            return __ieee754_sqrtf(x);
        }

        ax   = fabsf(x);
    /* special value of x */
        if(FLT_UWORD_IS_INFINITE(ix)||FLT_UWORD_IS_ZERO(ix)||ix==0x3f800000){
            z = ax;			/*x is +-0,+-inf,+-1*/
            if(hy<0) z = one/z;	/* z = (1/|x|) */
            if(hx<0) {
                if(((ix-0x3f800000)|yisint)==0) {
                    z = (z-z)/(z-z); /* (-1)**non-int is NaN */
                } else if(yisint==1)
                    z = -z;		/* (x<0)**odd = -(|x|**odd) */
            }
            return z;
        }

    /* (x<0)**(non-int) is NaN */
        if(((((__uint32_t)hx>>31)-1)|yisint)==0) return (x-x)/(x-x);

    /* |y| is huge */
        if(iy>0x4d000000) { /* if |y| > 2**27 */
        /* over/underflow if x is not close to one */
            if(ix<0x3f7ffff8) return (hy<0)? huge*huge:tiny*tiny;
            if(ix>0x3f800007) return (hy>0)? huge*huge:tiny*tiny;
        /* now |1-x| is tiny <= 2**-20, suffice to compute
           log(x) by x-x^2/2+x^3/3-x^4/4 */
            t = x-1;		/* t has 20 trailing zeros */
            w = (t*t)*((float)0.5-t*((float)0.333333333333-t*(float)0.25));
            u = ivln2_h*t;	/* ivln2_h has 16 sig. bits */
            v = t*ivln2_l-w*ivln2;
            t1 = u+v;
            GET_FLOAT_WORD(is,t1);
            SET_FLOAT_WORD(t1,is&0xfffff000);
            t2 = v-(t1-u);
        } else {
            float s2,s_h,s_l,t_h,t_l;
            n = 0;
        /* take care subnormal number */
            if(FLT_UWORD_IS_SUBNORMAL(ix))
                {ax *= two24; n -= 24; GET_FLOAT_WORD(ix,ax); }
            n  += ((ix)>>23)-0x7f;
            j  = ix&0x007fffff;
        /* determine interval */
            ix = j|0x3f800000;		/* normalize ix */
            if(j<=0x1cc471) k=0;	/* |x|<sqrt(3/2) */
            else if(j<0x5db3d7) k=1;	/* |x|<sqrt(3)   */
            else {k=0;n+=1;ix -= 0x00800000;}
            SET_FLOAT_WORD(ax,ix);

        /* compute s = s_h+s_l = (x-1)/(x+1) or (x-1.5)/(x+1.5) */
            u = ax-bp[k];		/* bp[0]=1.0, bp[1]=1.5 */
            v = one/(ax+bp[k]);
            s = u*v;
            s_h = s;
            GET_FLOAT_WORD(is,s_h);
            SET_FLOAT_WORD(s_h,is&0xfffff000);
        /* t_h=ax+bp[k] High */
            SET_FLOAT_WORD(t_h,((ix>>1)|0x20000000)+0x0040000+(k<<21));
            t_l = ax - (t_h-bp[k]);
            s_l = v*((u-s_h*t_h)-s_h*t_l);
        /* compute log(ax) */
            s2 = s*s;
            r = s2*s2*(L1+s2*(L2+s2*(L3+s2*(L4+s2*(L5+s2*L6)))));
            r += s_l*(s_h+s);
            s2  = s_h*s_h;
            t_h = (float)3.0+s2+r;
            GET_FLOAT_WORD(is,t_h);
            SET_FLOAT_WORD(t_h,is&0xfffff000);
            t_l = r-((t_h-(float)3.0)-s2);
        /* u+v = s*(1+...) */
            u = s_h*t_h;
            v = s_l*t_h+t_l*s;
        /* 2/(3log2)*(s+...) */
            p_h = u+v;
            GET_FLOAT_WORD(is,p_h);
            SET_FLOAT_WORD(p_h,is&0xfffff000);
            p_l = v-(p_h-u);
            z_h = cp_h*p_h;		/* cp_h+cp_l = 2/(3*log2) */
            z_l = cp_l*p_h+p_l*cp+dp_l[k];
        /* log2(ax) = (s+..)*2/(3*log2) = n + dp_h + z_h + z_l */
            t = (float)n;
            t1 = (((z_h+z_l)+dp_h[k])+t);
            GET_FLOAT_WORD(is,t1);
            SET_FLOAT_WORD(t1,is&0xfffff000);
            t2 = z_l-(((t1-t)-dp_h[k])-z_h);
        }

        s = one; /* s (sign of result -ve**odd) = -1 else = 1 */
        if(((((__uint32_t)hx>>31)-1)|(yisint-1))==0)
            s = -one;	/* (-ve)**(odd int) */

    /* split up y into y1+y2 and compute (y1+y2)*(t1+t2) */
        GET_FLOAT_WORD(is,y);
        SET_FLOAT_WORD(y1,is&0xfffff000);
        p_l = (y-y1)*t1+y*t2;
        p_h = y1*t1;
        z = p_l+p_h;
        GET_FLOAT_WORD(j,z);
        i = j&0x7fffffff;
        if (j>0) {
            if (i>FLT_UWORD_EXP_MAX)
                return s*huge*huge;			/* overflow */
            else if (i==FLT_UWORD_EXP_MAX)
                if(p_l+ovt>z-p_h) return s*huge*huge;	/* overflow */
        } else {
            if (i>FLT_UWORD_EXP_MIN)
                return s*tiny*tiny;			/* underflow */
            else if (i==FLT_UWORD_EXP_MIN)
                if(p_l<=z-p_h) return s*tiny*tiny;	/* underflow */
        }
    /*
     * compute 2**(p_h+p_l)
     */
        k = (i>>23)-0x7f;
        n = 0;
        if(i>0x3f000000) {		/* if |z| > 0.5, set n = [z+0.5] */
            n = j+(0x00800000>>(k+1));
            k = ((n&0x7fffffff)>>23)-0x7f;	/* new k for n */
            SET_FLOAT_WORD(t,n&~(0x007fffff>>k));
            n = ((n&0x007fffff)|0x00800000)>>(23-k);
            if(j<0) n = -n;
            p_h -= t;
        }
        t = p_l+p_h;
        GET_FLOAT_WORD(is,t);
        SET_FLOAT_WORD(t,is&0xfffff000);
        u = t*lg2_h;
        v = (p_l-(t-p_h))*lg2+t*lg2_l;
        z = u+v;
        w = v-(z-u);
        t  = z*z;
        t1  = z - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
        r  = (z*t1)/(t1-two)-(w+z*w);
        z  = one-(r-z);
        GET_FLOAT_WORD(j,z);
        j += (n<<23);
        if((j>>23)<=0) z = scalbnf(z,(int)n);	/* subnormal output */
        else SET_FLOAT_WORD(z,j);
        return s*z;
}
