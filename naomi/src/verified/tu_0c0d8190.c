#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
struct Vec3_0c2489d4 { float x, y, z; };
extern const struct Vec3_0c2489d4 dat_0c2489d4[];
extern void func_0c048bb0(struct Actor *, int), func_0c0442fa(struct Actor *), func_0c0344a0(struct Actor *, int);
extern void func_0c165b30(struct Actor *, int, int), func_0c0432ca(struct Actor *), func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *), func_0c0451f2(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c2489c0[])(struct Actor *);

#define W151(a) (((char *)&(a)->w150)[1])

void func_0c0d8190(struct Actor *a)
{
    a->b6++;
    a->b1a1 = 48;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c0344a0(a, 21);
    func_0c165b30(a, 1, 0);
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 0);
}

void func_0c0d8218(struct Actor *a)
{
    if (func_0c02a026(a) >= 0) {
        if (!(W151(a) & 1)) return;
        W151(a) &= ~1;
        func_0c0344a0(a, 30);
        func_0c165b30(a, 0, 0);
        return;
    }
    a->b6++;
    func_0c02a0c4(a, 21, 1);
}

void func_0c0d826c(struct Actor *a)
{
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}

void func_0c0d828e(struct Actor *a)
{
    struct Actor *p = a;
    table_0c2489c0[p->b6](a);
}

void func_0c0d82a0(struct Actor *a)
{
    a->b6++;
    if (a->b255 == 3) {
        a->b1a1 = 81;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    } else {
        a->b1a1 = a->b1a3 ? 53 : 51;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c048bb0(a, 10);
    }
    func_0c0442fa(a);
    a->f56 = a->f41c;
    a->b1f9 = 0;
    a->f92 = a->b1d2 ? dat_0c2489d4[(unsigned char)a->b1a3].x : -dat_0c2489d4[(unsigned char)a->b1a3].x;
    a->f96 = dat_0c2489d4[(unsigned char)a->b1a3].y;
    a->f108 = dat_0c2489d4[(unsigned char)a->b1a3].z;
    a->f104 = 0.0f;
    func_0c165b30(a, 2, 0);
    func_0c0432ca(a);
    a->b158 = a->b1a3 ? 4 : 2;
    func_0c02a0c4(a, 21, a->b158);
}

void func_0c0d83fc(struct Actor *a)
{
    func_0c02a026(a);
    if (!(W151(a) & 1)) return;
    a->b6++;
    func_0c0451f2(a);
    func_0c165b30(a, 7, 0);
}
