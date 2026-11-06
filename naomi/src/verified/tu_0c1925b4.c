/* Linked-actor follower: spawned by func_0c1925b4, copies the owner's block and tracks its offset table entry. */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern void func_0c037688(struct LinkedActor *);
extern void (*table_0c257af4[])(struct LinkedActor *);
extern short dat_0c257860[];
void func_0c1925e0(struct LinkedActor *a);
void func_0c192678(struct LinkedActor *a);
void func_0c19275a(struct LinkedActor *a);

struct LinkedActor *func_0c1925b4(struct LinkedActor *owner)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c1925e0;
        a->p24 = owner;
        a->w38 = 0x902;
    }
    return a;
}

void func_0c1925e0(struct LinkedActor *a)
{
    table_0c257af4[a->b4](a);
}

void func_0c1925f2(struct LinkedActor *a)
{
    a->b4++;
    a->sdc = a->p24->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    A(a)->f80 = A(a->p24)->f80;
    A(a)->f84 = A(a->p24)->f84;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    a->b36 = a->p24->b36;
    a->sdc.b12c = 0;
    a->b36 = 0;
    func_0c02a0c4(a, 20, 3);
    func_0c192678(a);
}

void func_0c192678(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    struct ActorSub2a4 *p = &A(o)->sub2a4;
    a->b36 = o->b36;
    a->b49 = -1;
    if (!p->b0) {
        a->b4++;
        func_0c19275a(a);
        return;
    }
    a->sdc.b12c = 0;
    a->f52 = a->p24->f52;
    a->f56 = a->p24->f56;
    if (A(a->p24)->b14b) {
        float dx;
        a->sdc.b12c = 1;
        dx = dat_0c257860[A(a->p24)->b14b * 2] * 1.66666663f;
        if (A(a->p24)->w130)
            dx = -dx;
        a->f52 += dx;
        a->f56 -= (dat_0c257860 + A(a->p24)->b14b * 2)[1] * 2.1428571f;
    }
    if ((unsigned char)A(a->p24)->b159 >= 7)
        a->sdc.b12c = 0;
    if (!A(a->p24)->b12c)
        a->sdc.b12c = 0;
}

void func_0c19275a(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c = 0;
    func_0c037688(a);
}
