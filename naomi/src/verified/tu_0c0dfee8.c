/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2406a8[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c044cbc(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern ActorHandler table_0c2490f8[];

void func_0c0dfee8(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6++;
        a->b1f9 = 1;
        func_0c02a0c4(a, 20, 2);
        a->b1a1 = 85;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c048bb0(a, 5);
        func_0c0346da(a, 22);
    }
    if ((*(unsigned char *)((char *)a + 0x1ff)) == 3) func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0dffb0(struct Actor *a) { table_0c2490f8[a->b6](a); }

void func_0c0dffc2(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141)
        return;
    a->b6++;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    a->s28 = 20;
    if (a->b1d2) {
        a->f92 = 10.83333302f;
        a->f104 = -0.20833333f;
    } else {
        a->f92 = -10.83333302f;
        a->f104 = 0.20833333f;
    }
}
