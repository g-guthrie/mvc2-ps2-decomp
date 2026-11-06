#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c241524[];
extern ActorHandler table_0c24152c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043324(struct Actor *);
extern void func_0c0437b8(struct Actor *);

void func_0c079c88(struct Actor *a)
{
    func_0c02a026(a);
    if (a->f41c < a->f56)
        return;
    a->b6++;
    a->f56 = a->f41c;
    a->b1fc = 0;
    func_0c0346da(a, 52);
    a->b1f9 = 0;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    func_0c02a0c4(a, 21, 14);
    func_0c043324(a);
}
void func_0c079cec(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c079d0e(struct Actor *a) { table_0c241524[a->b6](a); }
void func_0c079d20(struct Actor *a)
{
    a->b6++;
    a->f56 = a->f41c;
    a->b1a1 = 49;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 5);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
}
void func_0c079d7c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}
void func_0c079d9e(struct Actor *a) { table_0c24152c[a->b6](a); }
