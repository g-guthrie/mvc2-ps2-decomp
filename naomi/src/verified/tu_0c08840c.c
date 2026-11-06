#include "objects.h"
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c0451f2(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2424b8[])(struct Actor *);
void func_0c08840c(struct Actor *a, struct ActorSub2a4 *sub)
{
    a->b6++;
    a->b7 = 0;
    a->b32 = 1;
    a->b34 = 28;
    a->b1f5 = 2;
    ((char *)sub)[5] = 0;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->f92 = 2.91666651f;
    a->f104 = 0;
    a->f96 = 17.142857f;
    a->f108 = -1.07142854f;
    if (a->b1d2) { a->f92 = -a->f92; a->f104 = -a->f104; }
    if (a->b1f9 != 2) {
        a->b32 = 0;
        a->b1fc = 0;
        a->f56 = a->f41c;
        func_0c0442fa(a);
        func_0c0432ca(a);
        func_0c0451f2(a);
    }
    a->b1a1 = a->b32 * 3 + 60;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, (char)a->b32 * 3 + a->b1a3 + 11);
}
void func_0c0884fa(struct Actor *a)
{
    a->b1f5 = 2;
    table_0c2424b8[a->b7](a);
}
