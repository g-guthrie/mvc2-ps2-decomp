#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c24174c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

void func_0c07c4e0(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 <= a->f41c) {
        a->f56 = a->f41c;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
    }
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}
void func_0c07c55a(struct Actor *a)
{
    if (a->b6 == 0) {
        a->b6++;
        func_0c02a0c4(a, 20, 7);
    } else if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
    }
}
void func_0c07c596(struct Actor *a) { table_0c24174c[a->b6](a); }
void func_0c07c5a8(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 60;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 8);
}
