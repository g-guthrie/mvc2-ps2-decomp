#include "objects.h"
typedef void (*handler_0c0912bc)(struct Actor *,struct ActorSub2a4 *);
extern handler_0c0912bc table_0c242c14[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a39a(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c1990c0(struct Actor *,int);
void func_0c0912bc(struct Actor *a)
{
    a->b6 = a->b6 + 1;
    a->b1f9 = 2;
    func_0c02a39a(a, 0);
    a->f92 = -30.0f;
    a->f96 = 0.20833333f;
    a->f104 = 0.0f;
    a->f108 = -0.80357140303f;
    if (a->b1d2)
        a->f92 = -a->f92;
    a->b1a1 = 37;
    a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}
void func_0c091338(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 < a->f41c) {
        a->b6 = a->b6 + 1;
        a->b1f9 = 0;
        a->f56 = a->f41c;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c1990c0(a, 2);
        func_0c02a0c4(a, 20, 1);
    }
}
void func_0c0913c8(struct Actor *a,struct ActorSub2a4 *state){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0913ea(struct Actor *a)
{
    struct ActorSub2a4 *s = &a->sub2a4;
    a->b1f5 = 1;
    table_0c242c14[a->b6](a, s);
}
