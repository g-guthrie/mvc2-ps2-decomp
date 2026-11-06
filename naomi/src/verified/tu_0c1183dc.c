#include "objects.h"

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
typedef void (*Handler_0c1183dc)(struct Actor *);
extern Handler_0c1183dc table_0c24cb50[];
extern Handler_0c1183dc table_0c24cb64[];
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c179a48(struct Actor *, int, int);

void func_0c1183dc(struct Actor *a)
{
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b6++;
        func_0c02a0c4(a, 21, 9);
    }
}

void func_0c11840c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c11842e(struct Actor *a)
{
    table_0c24cb50[a->b6](a);
}

void func_0c1184c4(struct Actor *a, int b);

void func_0c118440(struct Actor *a, int b)
{
    a->b7++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->b1a1 = 50;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 10);
    func_0c1184c4(a, b);
}

void func_0c1184c4(struct Actor *a, int b)
{
    (void)b;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        func_0c179a48(a, 0, 0);
        func_0c179a48(a, 0, 1);
    }
}

void func_0c118508(struct Actor *a)
{
    table_0c24cb64[a->b7](a);
}
