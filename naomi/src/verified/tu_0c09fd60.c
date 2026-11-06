#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern void func_0c14a9d0(struct Actor *, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2438fc[])(struct Actor *);

void func_0c09fd60(struct Actor *a)
{
    if (a->b141 > 1) {
        a->f52 += a->b1d2 ? (float)a->b141 * 1.66666663f : -((float)a->b141 * 1.66666663f);
    }
    if (a->b141 == 1) {
        a->b7++;
        a->s28 = 1;
        func_0c0451f2(a);
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
    func_0c02a026(a);
}

void func_0c09fdd8(struct Actor *a)
{
    if (a->f96 < 0.0f) {
        a->b7++;
    } else {
        if (--a->s28 == 0) {
            func_0c14a9d0(a, 1);
            func_0c14a9d0(a, 2);
            a->s28 = 6;
        }
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (a->b141)
            return;
    }
    func_0c02a026(a);
}

void func_0c09fe44(struct Actor *a)
{
    if (a->f56 < a->f41c) {
        a->b7++;
        a->b1f9 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f56 = a->f41c;
        func_0c043324(a);
    } else {
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (a->b141)
            return;
    }
    func_0c02a026(a);
}

void func_0c09fed6(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c09fef8(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6++;
        if (!a->b1fe) {
            func_0c048bb0(a, 5);
            a->b1a1 = 18;
            a->w1ac = 0;
            a->b19e = 0;
            a->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
            a->b1f9 = 1;
            func_0c02a0c4(a, 20, 19);
        }
    }
    if (a->b1ff == 3)
        func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c09ffc0(struct Actor *a){table_0c2438fc[a->b6](a);}
