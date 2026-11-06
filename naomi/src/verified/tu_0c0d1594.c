#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24832c[];
extern ActorHandler table_0c24834c[];
extern ActorHandler table_0c248370[];
extern float dat_0c248360[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c163390(struct Actor *, int);
extern void func_0c0cfebe(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c0ce574(struct Actor *);
extern void func_0c042018(struct Actor *);

void func_0c0d1628(struct Actor *a);

void func_0c0d1594(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0d15b6(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        if (--a->s28 < 0) {
            a->b6 = 6;
            func_0c02a0c4(a, 22, 18);
            return;
        }
    }
    if (a->b141 & 1) {
        a->b141 = 0;
        func_0c163390(a, 1);
    }
}

void func_0c0d1604(struct Actor *a)
{
    table_0c24832c[a->b6](a);
}

void func_0c0d1616(struct Actor *a)
{
    table_0c24834c[a->b6](a);
}

void func_0c0d1628(struct Actor *a)
{
    func_0c02a0c4(a, 21, 10);
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    a->f92 = dat_0c248360[(unsigned char)a->b1a3 * 2];
    a->f104 = (dat_0c248360 + (unsigned char)a->b1a3 * 2)[1];
    if (a->w130 != 0) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
    }
}

void func_0c0d1684(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    func_0c0cfebe(a);
    func_0c048bb0(a, 5);
    a->b1a1 = 52;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 5);
    func_0c0346da(a, 23);
}

void func_0c0d1710(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b6 = a->b6 + 1;
        func_0c0d1628(a);
    }
}

void func_0c0d1734(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0ce574(a);
    else {
        if (a->b141 != 0)
            a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
}

void func_0c0d1794(struct Actor *a)
{
    func_0c0437b8(a);
}

void func_0c0d179a(struct Actor *a)
{
    func_0c0437b8(a);
}

void func_0c0d17a0(struct Actor *a)
{
    if (a->b1f9 == 2) {
        func_0c042018(a);
        if (a->f56 < a->f41c)
            a->f56 = a->f41c;
    }
    table_0c248370[a->b6](a);
}
