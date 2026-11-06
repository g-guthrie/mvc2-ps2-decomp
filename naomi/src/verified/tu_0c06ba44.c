#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0429a4(struct Actor *, void *, int);
extern int func_0c0447bc(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c044548(struct Actor *, struct Actor *);
extern void func_0c1d4610(struct Actor *, void *);
extern void func_0c0344a0(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;

struct Vec3_06ba {
    float x, y, z;
};

void func_0c06ba44(struct Actor *a)
{
    short z;

    if (a->b255 == 6) {
        a->b3f0 = 255;
        a->b3f1 = 16;
    }
    a->b6++;
    z = 0;
    a->b1a1 = 71;
    a->w1ac = z;
    a->b19e = z;
    a->p1c4 = z;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0442fa(a);
    a->b1f9 = z;
    a->f56 = a->f41c;
    a->f96 = 0;
    a->f108 = 0;
    func_0c0432ca(a);
    func_0c02a0c4(a, 22, 4);
}

void func_0c06bac0(struct Actor *a)
{
    struct Vec3_06ba v;

    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = a->b255 == 6 ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = -30.0f;
        v.y = 175.71428f;
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c06bb26(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        if (a->b1d2)
            a->f92 = 13.33333302f;
        else
            a->f92 = -13.33333302f;
        a->f104 = 0;
        a->s28 = 24;
        func_0c02a0c4(a, 22, 30);
    }
}

void func_0c06bbbe(struct Actor *a)
{
    struct Vec3_06ba v;
    int c;
    int d;

    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->b19e) {
        a->s28 = 1;
        if (func_0c0447bc(a) != 0) {
            func_0c025900(a, 8, 8);
            a->b6 = a->b6 + 2;
            a->b1f7 = 194;
            func_0c044548(a, a->p1b0);
            a->b1a0 = 10;
            v.x = -96.666664124f;
            v.y = 128.57143f;
            v.z = 0;
            func_0c1d4610(a, &v);
            func_0c0344a0(a, 5);
            d = 5;
            c = 15;
            goto call;
        }
    }
    if (--a->s28 != 0)
        return;
    a->b6++;
    a->b3f9 = 0;
    a->b3f8 = 0;
    a->b327 = 0;
    a->b328 = 0;
    if (a->b1d2)
        a->f92 = 11.666666031f;
    else
        a->f92 = -11.666666031f;
    if (a->b1d2)
        a->f104 = -0.20833333f;
    else
        a->f104 = 0.20833333f;
    d = 31;
    c = 22;
call:
    func_0c02a0c4(a, c, d);
}
