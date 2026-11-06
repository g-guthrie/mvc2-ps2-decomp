#include "objects.h"
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0953ba(struct Actor *);
extern void func_0c143e08(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c242e58[])(struct Actor *);
void func_0c0938ac(struct Actor *, void *);
void func_0c093820(register struct Actor *a, void *context)
{
    register void *zero;
    a->b7++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    zero = 0;
    a->b1f9 = (int)zero;
    a->f56 = a->f41c;
    a->b1a1 = a->b1a3 + 50;
    a->w1ac = (int)zero;
    a->b19e = (int)zero;
    *(unsigned int *)&a->p1c4 = (unsigned int)zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, (int)zero);
    func_0c0938ac(a, context);
}
void func_0c0938ac(struct Actor *a, void *context)
{
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    func_0c0953ba(a);
    if (a->b141) {
        a->b141 = 0;
        func_0c143e08(a, 0, 0);
        func_0c143e08(a, 1, 0);
        a->b27a = 16;
        a->b27b = 0;
    }
}
void func_0c0938fe(struct Actor *a) { table_0c242e58[a->b7](a); }
