#include "objects.h"
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern void func_0c044450(struct Actor *, struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c242904[])(struct Actor *);
void func_0c08d804(struct Actor *, void *);
void func_0c08d77c(struct Actor *a, void *context)
{
    a->b6++;
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
    a->b1a1 = 66;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, a->b1a3 + 24);
    func_0c08d804(a, context);
}
void func_0c08d804(struct Actor *a, void *context)
{
    struct Actor *child;
    if (func_0c02a026(a) < 0) {
        a->b6++;
        func_0c02a0c4(a, 21, a->b1a3 + 26);
        return;
    }
    if (func_0c0447bc(a)) {
        a->b1f7 = 2;
        a->b1f7 |= 0x40;
        a->b1f7 |= 0x80;
        a->b7 = 0;
        a->b6 = 0;
        child = a->p1b0;
        child->f92 = child->f96 = child->f104 = child->f108 = 0;
        func_0c044450(a, child);
    }
}
void func_0c08d878(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0437b8(a); }
void func_0c08d89a(struct Actor *a) { table_0c242904[a->b6](a); }
