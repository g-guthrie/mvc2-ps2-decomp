#include "objects.h"
struct Sub_efd74 { unsigned char pad0[4]; unsigned char b4, b5, b6, b7, b8, b9; };
extern void (*table_0c249fa0[])(struct Actor *, struct Sub_efd74 *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct LinkedActorVec3 *, int);
extern void func_0c1b2e9c(struct Actor *, int);
extern void func_0c1b2e10(struct Actor *, int);
extern void func_0c16a708(struct Actor *, int);
extern int func_0c047bbe(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern signed char dat_0c2f836e[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;

void func_0c0efd74(struct Actor *a)
{
    table_0c249fa0[a->b7](a, (struct Sub_efd74 *)&a->sub2a4);
}

void func_0c0efd8a(struct Actor *a, struct Sub_efd74 *s)
{
    if (a->b255 == 6) {
        a->b3f0 = 0xff;
        a->b3f1 = 16;
    }
    a->b7++;
    s->b8 = 0;
    s->b6 = 0;
    s->b7 = 0;
    s->b9 = 0;
    func_0c0442fa(a);
    func_0c02a0c4(a, 21, 24);
}

void func_0c0efdca(struct Actor *a)
{
    struct LinkedActorVec3 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 13.33333302f;
        v.y = 222.857132f;
        v.z = 0.0f;
        func_0c0429a4(a, &v, 1);
        func_0c02a0c4(a, 21, 41);
        func_0c1b2e9c(a, 10);
    }
}

void func_0c0efe46(struct Actor *a, struct Sub_efd74 *s)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f92 = a->b1d2 ? 15.0f : -15.0f;
        a->b1a1 = 65;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        s->b5 = 2;
        goto ly; ly:a->s28 = 96;
        a->s30 = 7;
        a->p20 = 0;
        goto c; c: func_0c1b2e10(a, 11);
        func_0c16a708(a, 0);
        func_0c02a0c4(a, 21, 25);
    }
}

void func_0c0eff2a(register struct Actor *a, struct Sub_efd74 *s0)
{
    void *zero = 0;
    unsigned char one = 1;
    unsigned char two = 2;
    register struct Sub_efd74 *s = s0;
    struct Actor *p;
    unsigned char lim;
    unsigned char d;
    a->b3f8 = two;
    a->b328 = 5;
    p = a->p20;
    if (p && p->b19f) {
        a->f92 -= a->b1d2 ? -1.25 : 1.25;
        s->b7 = 6;
    }
    if (a->b141)
        s->b4 = one;
    a->b1f5 = one;
    p = a->p20c;
    if ((short)p->w420 <= 0 && dat_0c2f836e[p->b2] <= 2)
        goto out;
    if ((a->b1d2 || ((signed char)a->b1fd & 2)) && (!a->b1d2 || ((signed char)a->b1fd & 1)))
        goto out;
    if (s->b7) {
        if (--s->b7)
            goto skip;
        a->f104 += a->b1d2 ? 0.1041666642 : -0.1041666642;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
skip:
    if (func_0c047bbe(a)) {
        *(unsigned char *)&a->b142 = one;
        s->b9++;
        if (a->b525) lim = 6; else lim = two;
        if (s->b9 >= lim) {
            s->b9 = (int)zero;
            if (a->s30 >= 10)
                s->b6 = one;
            if (!s->b6)
                a->s30++;
        }
    }
    func_0c02a026(a);
    if (--a->s28 >= 0) {
        if (a->b19e && --s->b5 == 0 && ++s->b8 < 10 && --a->s30 != 0) {
            goto l2; l2: a->b1a1 = 65;
            a->w1ac = (int)zero;
            a->b19e = (int)zero;
            a->p1c4 = (int)zero;
            dat_0c2f83f8->arr[a->b2]++;
            s->b5 = two;
        }
        return;
    }
out:
    a->b7++;
    a->b3f9 = (int)zero;
    a->b3f8 = (int)zero;
    a->b327 = (int)zero;
    a->b328 = (int)zero;
    func_0c02a39a(a, 0);
    a->f108 = -0.80357140303f;
    func_0c02a0c4(a, 21, 48);
}
