/* Projectile launch/flight states: 0x0c248e58/0x0c248e68 dispatch, per-strength speed tables. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c166704(struct Actor *,int),func_0c0344a0(struct Actor *,int);
extern void func_0c0438de(struct Actor *),func_0c0451f2(struct Actor *),func_0c0432ca(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c248e58[])(struct Actor *);
extern void (*table_0c248e68[])(struct Actor *);
extern const short dat_0c248c6c[][2];
extern const unsigned char dat_0c248e64[][2];
extern const float dat_0c248c74[][2];

void func_0c0dcd40(struct Actor *a){table_0c248e58[a->b6](a);}

void func_0c0dcd52(register struct Actor *a)
{
    register void *zero;
    zero = 0;
    a->b6++;
    a->b1a1 = a->b1a3 + 68;
    a->w1ac = (int)zero; a->b19e = (int)zero; a->p1c4 = (int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 4);
    func_0c0442fa(a);
    func_0c02a39a(a, (int)zero);
    a->f92 /= 8.0f;
    a->f104 = 0.0f;
    a->f96 /= 8.0f;
    a->f108 /= 64.0f;
    a->s28 = dat_0c248c6c[a->i204][(unsigned char)a->b1a3];
    a->b1a1 = dat_0c248e64[a->i204][(unsigned char)a->b1a3];
    a->w1ac = (int)zero; a->b19e = (int)zero; a->p1c4 = (int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, a->b1a3 + 21);
}

void func_0c0dce2e(struct Actor *a)
{
    a->f52 += a->f92; a->f92 += a->f104;
    a->f56 += a->f96; a->f96 += a->f108;
    if (a->f41c > a->f56) a->f56 = a->f41c;
    func_0c02a026(a);
    if (a->b141) {
        a->b141 = 0;
        if (!a->i204) func_0c166704(a, 1); else func_0c166704(a, 7);
        func_0c0344a0(a, 30);
    }
    if (--a->s28 <= 0) {
        a->b6++;
        func_0c02a0c4(a, 21, a->b1a3 + 23);
    }
}

void func_0c0dcf12(struct Actor *a)
{
    a->f52 += a->f92; a->f92 += a->f104;
    a->f56 += a->f96; a->f96 += a->f108;
    if (a->f41c > a->f56) a->f56 = a->f41c;
    if (func_0c02a026(a) < 0) func_0c0438de(a);
}

void func_0c0dcf80(struct Actor *a){table_0c248e68[a->b6](a);}

void func_0c0dcf92(register struct Actor *a)
{
    register void *zero;
    const float *px;
    zero = 0;
    a->b6++;
    a->b1f9 = (int)zero;
    func_0c0442fa(a);
    px = (const float *)dat_0c248c74;
    if (a->b255 == 8) {
        a->f92 = px[4]; a->f96 = ((const float *)dat_0c248c74)[5]; a->b1a1 = 76;
    } else {
        a->f92 = px[(unsigned char)a->b1a3 * 2]; a->f96 = ((const float *)dat_0c248c74)[(unsigned char)a->b1a3 * 2 + 1]; a->b1a1 = ((unsigned char)a->b1a3 << 1) + 75;
    }
    a->w1ac = (int)zero; a->b19e = (int)zero; a->p1c4 = (int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    a->f108 = -0.80357140303f;
    goto s; s: a->f92 = a->b1d2 ? a->f92 : -a->f92;
    a->f104 = 0.0f;
    func_0c048bb0(a, 8);
    func_0c02a0c4(a, 21, a->b1a3 + 12);
}

void func_0c0dd08e(struct Actor *a)
{
    func_0c02a026(a);
    if (!a->b141) {
        a->b6++;
        func_0c0451f2(a);
        func_0c0432ca(a);
    }
}
