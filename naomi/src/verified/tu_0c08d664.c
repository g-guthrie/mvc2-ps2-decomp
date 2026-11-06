#include "objects.h"
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c1418f8(struct Actor *, int, int);
extern void (*table_0c2428fc[])(struct Actor *);
void func_0c08d6fa(struct Actor *, void *);
void func_0c08d664(struct Actor *a, void *target)
{
    a->b6++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    (void)func_0c02a39a(a, 0);
    func_0c0432ca(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    a->b1a1 = 81;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    a->b159 = 21;
    a->b158 = a->b1a3 + 22;
    func_0c02a0c4(a, a->b159, a->b158);
    func_0c08d6fa(a, target);
}
void func_0c08d6fa(struct Actor *a, void *target)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141 & 2) {
        a->b141 = 0;
        func_0c1418f8(a, 0, 0);
    }
}
void func_0c08d736(struct Actor *a)
{
    table_0c2428fc[a->b6](a);
}
