#include "objects.h"

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern int func_0c1974d4(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c242b8c[])(struct Actor *, struct ActorSub2a4 *);

void func_0c08fe64(struct Actor *a, char *flag)
{
    a->b6++;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    *flag = 0;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1a1 = 65;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, a->b1a3 + 12);
}

void func_0c08fed8(struct Actor *a, char *flag)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        func_0c048bb0(a, 5);
        if (!func_0c1974d4(a))
            *flag = -1;
    }
}

void func_0c08ff1c(struct Actor *a, char *flag)
{
    func_0c02a026(a);
    if (*flag == -1) {
        a->b6++;
        func_0c02a0c4(a, 21, a->b1a3 + 14);
    }
}

void func_0c08ff56(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c08ff78(struct Actor *a)
{
    table_0c242b8c[a->b6](a, &a->sub2a4);
}
