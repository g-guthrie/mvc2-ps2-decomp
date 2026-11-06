/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c247ab0[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0432ca(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c15d3f8(struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c0c3b80(struct Actor *a);
extern ActorHandler table_0c246b4c[];

void func_0c0c3af4(struct Actor *a)
{
    unsigned char *sub = (unsigned char *)&a->sub2a4;
    a->b7++;
    sub[4] = 255;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->f56 = a->f41c;
    a->b1fc = 0;
    a->b1f9 = 0;
    func_0c048bb0(a, 5);
    a->b1a1 = 57;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 9);
    func_0c0432ca(a);
    func_0c0c3b80(a);
}

void func_0c0c3b80(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b7++;
        a->b141 = 0;
        func_0c15d3f8(a);
    }
}

void func_0c0c3bae(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0c3bd0(struct Actor *a)
{
    table_0c246b4c[a->b7](a);
}
