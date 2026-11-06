#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);
extern void (*table_0c242518[])(struct Actor *);
extern void (*table_0c242524[])(struct Actor *, struct ActorSub2a4 *);
void func_0c089c38(struct Actor *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (func_0c02a026(a) >= 0) {
        if (a->b14b) {
            a->b1a1 = a->b14b;
            a->w1ac = 0;
            a->b19e = 0;
            *(unsigned int *)&a->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
            a->w1ac = 64;
            a->b14b = 0;
        }
    } else {
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        a->b6++;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 22, 31);
    }
}
void func_0c089cfa(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c089d1c(struct Actor *a)
{
    table_0c242518[a->b6](a);
}
void func_0c089d2e(struct Actor *a)
{
    table_0c242524[a->b7](a, &a->sub2a4);
}
