#include "objects.h"

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char dat_0c2453a8[];
extern char dat_0c2453a9[];
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0432ca(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c159ae0(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2453ac[];

void func_0c0b9562(struct Actor *a);

void func_0c0b94d0(struct Actor *a)
{
    int z = 0;

    a->b6 = a->b6 + 1;
    func_0c0442fa(a);
    func_0c02a39a(a, 1);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->f56 = a->f41c;
    a->b1fc = z;
    a->b1f9 = z;
    func_0c048bb0(a, 5);
    a->b1a1 = a->b1a3 + 55;
    a->w1ac = z;
    a->b19e = z;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, dat_0c2453a8[(unsigned char)a->b1a3 * 2]);
    func_0c0432ca(a);
    func_0c0b9562(a);
}

void func_0c0b9562(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6 = a->b6 + 1;
        if (!a->b1a3)
            a->s28 = 18;
        else
            a->s28 = 30;
        func_0c159ae0(a, a->b1a3);
    }
}

void func_0c0b959e(struct Actor *a)
{
    func_0c02a026(a);
    if (--a->s28 == 0) {
        a->b6 = a->b6 + 1;
        func_0c02a0c4(a, 21, dat_0c2453a9[(unsigned char)a->b1a3 * 2]);
    }
}

void func_0c0b95d8(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0b95fa(struct Actor *a)
{
    a->b1f5 = 1;
    table_0c2453ac[a->b6](a);
}
