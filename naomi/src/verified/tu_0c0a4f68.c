#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2441dc[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c14b8d8(struct Actor *, int, int, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);

void func_0c0a4f68(struct Actor *a)
{
    if (a->b141==14) {
        a->b141=0;
        func_0c14b8d8(a,8,19,8);
    }
    if (a->b143<0) {
        a->b6=a->b6+1;
        func_0c02a0c4(a,21,28);
    }
    func_0c02a026(a);
}
void func_0c0a4faa(struct Actor *a)
{
    if (func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0a4fcc(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b1a1 = 49;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c048bb0(a, 5);
    a->s28 = 24;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    func_0c02a0c4(a, 21, 12);
}

void func_0c0a504e(struct Actor *a)
{
    table_0c2441dc[a->b6](a);
}
