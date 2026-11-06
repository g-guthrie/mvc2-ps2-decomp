/* Child projectile setup: copies the parent display block and position,
 * offsets the spawn point and velocity from two signed placement tables
 * indexed by b32, and starts animation 23. Plus its b5 dispatcher. */
#define A(a) ((struct Actor *)(a))
#include "objects.h"
extern short table_0c24f624[], table_0c24f62c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24f684[])(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *), func_0c02a0c4(struct LinkedActor *, int, int);
void func_0c1403dc(struct LinkedActor *a, struct LinkedActor *p)
{
    struct ActorSub2a4 *link = &A(p)->sub2a4;
    int kind, base;
    short *t;
    float x;
    a->sdc = p->sdc;
    a->sdc.b12c = 1;
    a->b2 = p->b2;
    a->b1 = p->b1;
    a->v80.x = p->v80.x;
    a->v80.y = p->v80.y;
    a->b1a3 = p->b1a3;
    a->b1a4 = p->b1a4;
    a->b48 = p->b48;
    a->v80 = p->v80;
    a->b36 = p->b36;
    a->b4++;
    a->pad11[0] = 66;
    a->pad11[1] = 66;
    a->sdc.b13e = 32;
    a->sdc.b13f = 32;
    link->b0 = 1;
    kind = a->b32 * 2;
    t = &table_0c24f624[kind];
    x = *t++ * 1.66666663f;
    if (A(a)->w130)
        x = -x;
    a->f52 = p->f52 + x;
    a->f56 = p->f56 + *t * 2.1428571f;
    t = &table_0c24f62c[kind];
    a->f92 = *t++ * 1.66666663f / 256.0f;
    a->f96 = *t * 2.1428571f / 256.0f;
    if (A(a)->w130)
        a->f92 *= -1.0f;
    base = 54;
    if (a->b32)
        base = 57;
    A(a)->b1a1 = base + a->b1a3;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    A(a)->w1ac |= 0x200;
    func_0c037d0c(a);
    func_0c02a0c4(a, 23, kind + 1);
}
void func_0c14052a(struct LinkedActor *a){table_0c24f684[(unsigned char)a->b5](a);}
