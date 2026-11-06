/* Linked-actor shard: spawned with an offset-table index, placed around the parent by angle and launched. */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
struct ShardOffset6 { short x, y; char b36, anim; };
extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c029e70(struct LinkedActor *, int, int);
extern void func_0c037688(struct LinkedActor *);
extern float func_0c1ebd40(int), func_0c1ec2c0(int);
extern void (*table_0c2589ac[])(struct LinkedActor *);
extern struct ShardOffset6 dat_0c258988[];
void func_0c19d068(struct LinkedActor *a);
void func_0c19d222(struct LinkedActor *a);

struct LinkedActor *func_0c19d034(struct LinkedActor *owner, struct LinkedActor *parent, unsigned char index)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c19d068;
        a->p24 = owner;
        a->p20 = parent;
        a->b32 = index;
    }
    return a;
}

void func_0c19d068(struct LinkedActor *a)
{
    table_0c2589ac[a->b4](a);
}

void func_0c19d07a(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    struct LinkedActor *p = a->p20;
    struct ShardOffset6 *e;
    struct { float x, y; } v;
    a->b4++;
    a->w38 = 0x1007;
    a->sdc = o->sdc;
    a->sdc.b12c = 1;
    a->b2 = o->b2;
    a->b1 = o->b1;
    A(a)->f80 = A(o)->f80;
    A(a)->f84 = A(o)->f84;
    a->b1a3 = o->b1a3;
    a->b1a4 = o->b1a4;
    a->b48 = o->b48;
    a->v80 = o->v80;
    a->b36 = o->b36;
    a->s28 = 30;
    e = &dat_0c258988[a->b32];
    a->b36 = e->b36;
    v.x = e->x * 1.66666663f;
    v.y = e->y * 2.1428571f;
    a->l72 = p->l72;
    if ((a->sdc.w130 = p->sdc.w130) == 0)
        a->f52 = p->f52 + v.x * func_0c1ebd40(a->l72) - v.y * func_0c1ec2c0(a->l72);
    else
        a->f52 = p->f52 - v.x * func_0c1ebd40(a->l72) + v.y * func_0c1ec2c0(a->l72);
    a->f56 = p->f56 + v.x * func_0c1ec2c0(a->l72) + v.y * func_0c1ebd40(a->l72);
    a->f92 = (a->f52 - p->f52) / 32.0f;
    A(a)->f104 = 0.0f;
    a->f96 = 8.5714283f;
    A(a)->f108 = -0.80357140303f;
    func_0c029e70(a, 27, e->anim);
    func_0c19d222(a);
}

void func_0c19d222(struct LinkedActor *a)
{
    a->f52 += a->f92;
    a->f92 += A(a)->f104;
    a->f56 += a->f96;
    a->f96 += A(a)->f108;
    if (--a->s28 == 0)
        a->b4++;
    if (a->s28 <= 10)
        a->sdc.b12c = a->s28 & 1;
}

void func_0c19d282(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c19d290(struct LinkedActor *a)
{
    func_0c037688(a);
}
