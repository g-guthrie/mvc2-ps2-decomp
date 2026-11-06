#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, char, char);
extern void func_0c13d8e0(struct Actor *, char);
void func_0c07c40a(struct Actor *a);
void func_0c07c380(struct Actor *a)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c0451f2(a);
    a->b1a1 = a->b1a3 + 54;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c02a0c4(a, 21, (a->b1a3 ^ 1) + 8);
    a->f92 /= 8.0f;
    a->f96 /= 8.0f;
    a->f104 /= 8.0f;
    a->f108 /= 8.0f;
    a->s28 = 40;
    func_0c07c40a(a);
}
void func_0c07c40a(struct Actor *a)
{
    if (--a->s28 <= 0) {
        a->b6++;
        func_0c02a0c4(a, 21, (a->b1a3 ^ 1) + 12);
        return;
    }
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!(a->f56 > a->f41c)) {
        a->f56 = a->f41c;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
    }
    if (a->b141) {
        a->b141 = 0;
        func_0c13d8e0(a, (a->b1a3 ^ 1) + 2);
    }
}
