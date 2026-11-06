#include "objects.h"
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c095380(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0953ba(struct Actor *);
extern void func_0c143e08(struct Actor *, int, int);
extern void func_0c0438de(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c242e60[])(struct Actor *);
void func_0c0939e6(struct Actor *, void *);
void func_0c093948(struct Actor *a, void *context)
{
    a->b7++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    a->b1f9 = 2;
    func_0c02a39a(a, 0);
    a->f92 /= 16.0f;
    a->f96 /= 8.0f;
    a->f108 /= 64.0f;
    a->f104 = 0;
    a->b1a1 = a->b1a3 + 52;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 1);
    a->s28 = 48;
    func_0c0939e6(a, context);
}
void func_0c0939e6(struct Actor *a, void *context)
{
    func_0c095380(a);
    func_0c02a026(a);
    func_0c0953ba(a);
    if (a->b141) {
        a->b141 = 0;
        func_0c143e08(a, 0, 1);
        func_0c143e08(a, 1, 1);
        a->b27a = 16;
        a->b27b = 0;
    }
    if (--a->s28 == 0) { a->b7++; func_0c02a0c4(a, 21, 2); }
}
void func_0c093a4e(struct Actor *a)
{
    func_0c095380(a);
    if (func_0c02a026(a) < 0) func_0c0438de(a);
}
void func_0c093a74(struct Actor *a) { table_0c242e60[a->b7](a); }
