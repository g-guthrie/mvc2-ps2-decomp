#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c043324(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c248a58[])(struct Actor *);

void func_0c0d8fe8(struct Actor *a)
{
    float k; int m;
    a->b3f8 = 2; a->b328 = 5;
    a->f52 += a->f92; a->f92 += a->f104;
    a->f56 += a->f96; a->f96 += a->f108;
    func_0c02a026(a);
    k = 8.0f;
    if (a->b19e) {
        if (func_0c0447bc(a)) {
            struct Actor *o;
            a->b6++;
            o = a->p1b0;
            o->f52 = a->f52 + (a->b1d2 ? 100.0f : -100.0f);
            o->f56 = a->f56;
            o->b1f9 = 0;
            a->f92 /= k;
            m = 3;
            goto call;
        }
        a->s28 = 1;
    }
    if (--a->s28 == 0) {
        a->b6 = 4;
        a->f92 /= k;
        m = 1;
    call:
        func_0c02a0c4(a, 22, m);
    }
}

void func_0c0d90c0(register struct Actor *a, struct Actor *b)
{
    register void *zero;
    float z;
    struct Actor *o;
    a->b3f8 = 2; a->b328 = 5;
    z = 0.0f;
    o = a->p20c;
    if (o->b1 != b->b1) {
        a->f92 = z; a->f96 = z; a->f104 = z; a->f108 = z;
        func_0c0437b8(a);
        return;
    }
    zero = 0;
    if (!a->b7) {
        a->f52 += a->f92; a->f92 += a->f104;
        a->f56 += a->f96; a->f96 += a->f108;
        func_0c02a026(a);
        if (a->b141) {
            a->b7++;
            a->b141 = (int)zero;
            a->f92 /= 4.0f;
            a->f96 = 17.142857f;
            a->f108 = -2.1428571f;
        }
        if (!a->b14b) return;
        a->b1a1 = a->b14b;
        a->w1ac = (int)zero; a->b19e = (int)zero; a->p1c4 = (int)zero;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b = (int)zero;
        return;
    }
    a->f52 += a->f92; a->f92 += a->f104;
    a->f56 += a->f96; a->f96 += a->f108;
    if (!a->b141) func_0c02a026(a);
    if (a->b14b) {
        a->b1a1 = a->b14b;
        a->w1ac = (int)zero; a->b19e = (int)zero; a->p1c4 = (int)zero;
        dat_0c2f83f8->arr[a->b2]++;
        a->b14b = (int)zero;
    }
    if (a->f56 > a->f41c) return;
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = (int)zero; a->b3f9 = (int)zero; a->b3f8 = (int)zero; a->b327 = (int)zero; a->b328 = (int)zero;
    a->f92 = z; a->f96 = z; a->f104 = z; a->f108 = z;
    func_0c043324(a);
    func_0c02a0c4(a, 1, 3);
}

void func_0c0d92c6(struct Actor *a)
{
    a->f52 += a->f92; a->f92 += a->f104;
    a->f56 += a->f96; a->f96 += a->f108;
    if (func_0c02a026(a) < 0) {
        a->f92 = 0.0f; a->f96 = 0.0f; a->f104 = 0.0f; a->f108 = 0.0f;
        func_0c0437b8(a);
    }
}

void func_0c0d9332(struct Actor *a){table_0c248a58[a->b6](a);}
