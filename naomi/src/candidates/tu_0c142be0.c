/* Candidate (864/868): func_0c142be0 loads the stack-spilled owner argument into r0 (mov.l @r15,r0; mov.l r0,@(24,r4)) where retail uses r1; every other
 * function and pool matches. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct Dat_13bb5c dat_0c2f8338;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern void (*table_0c24f898[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f8a4[])(struct LinkedActor *,struct LinkedActor *,struct ActorSubControlBytes *);
void func_0c142c24(struct LinkedActor *);
void func_0c142f0c(struct LinkedActor *,struct LinkedActor *);

struct LinkedActor *func_0c142be0(struct LinkedActor *p, int x, struct LinkedActor *owner)
{
    struct LinkedActor *q;
    if ((q = func_0c0374da(0, 1, 1)) != 0) {
        q->w38 = 0x0e02;
        q->b32 = x;
        *(struct LinkedActorVec3 *)&q->f52 = *(struct LinkedActorVec3 *)&p->f52;
        q->p24 = owner;
        q->p16 = func_0c142c24;
    }
    return q;
}

void func_0c142c24(struct LinkedActor *a)
{
    table_0c24f898[a->b4](a, a->p24);
}

void func_0c142c38(struct LinkedActor *a, struct LinkedActor *p)
{
    struct ActorSubMoveBytes *sub = (struct ActorSubMoveBytes *)&A(p)->sub2a4;
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
    A(a)->b19c = 70;
    A(a)->b19d = 70;
    a->b36 = p->b36;
    a->b49 = -8;
    a->s28 = 0;
    x = -160.0f;
    if (a->sdc.w130) x = 160.0f;
    a->f52 += x;
    A(a)->b13e = 32;
    A(a)->b13f = 32;
    if (func_0c028642(a)) {
        if (a->b32 <= 6) {
            if (sub->b5 > 0) goto cont;
        }
    }
    a->b5 = 2;
    A(a)->b12c = 0;
    a->s30 = 20;
    return;
cont:
    A(a)->b1a1 = 62;
    A(a)->w1ac = 0;
    A(a)->b19e = 0;
    A(a)->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c037d0c(a);
    func_0c02a0c4(a, 23, 18);
}

void func_0c142d82(struct LinkedActor *a, struct Actor *p)
{
    struct ActorSub2a4 *sub = &p->sub2a4;
    if (p->b1d0 == 28 || p->b5 != 0 || p->b1e9 != 4) {
        a->b4 = 2;
        A(a)->b12c = 0;
        return;
    }
    a->b36 = p->b36;
    a->b49 = -8;
    table_0c24f8a4[(unsigned char)a->b5](a, (struct LinkedActor *)p, (struct ActorSubControlBytes *)sub);
}

void func_0c142dde(struct LinkedActor *a, struct LinkedActor *p, struct ActorSubControlBytes *q)
{
    if ((dat_0c2f8338.w3c & (1 << dat_0c2f8338.b3b)) == 0) {
        func_0c142f0c(a, p);
        func_0c02a026(a);
        if (A(a)->b14b) {
            A(a)->b1a1 = A(a)->b14b;
            A(a)->w1ac = 0;
            A(a)->b19e = 0;
            A(a)->p1c4 = 0;
            dat_0c2f83f8->arr[a->b2]++;
            A(a)->b14b = 0;
            a->s28 = 0;
        }
        if (A(a)->b141) {
            a->b5++;
            if (func_0c142be0(a, a->b32 + 1, p) == 0) q->b4 = -1;
        }
    }
    func_0c037d0c(a);
}

void func_0c142e9c(struct LinkedActor *a, struct LinkedActor *p)
{
    if ((dat_0c2f8338.w3c & (1 << dat_0c2f8338.b3b)) == 0) {
        func_0c142f0c(a, p);
        if (func_0c02a026(a) < 0) {
            a->b4 = 2;
            A(a)->b12c = 0;
            return;
        }
    }
    func_0c037d0c(a);
}

void func_0c142ee8(struct LinkedActor *a, struct LinkedActor *p, struct ActorSubControlBytes *q)
{
    if (--a->s30 == 0) {
        a->b4 = 2;
        A(a)->b12c = 0;
        q->b4 = 1;
    }
}

void func_0c142f06(struct LinkedActor *a)
{
    func_0c037688(a);
}

void func_0c142f0c(struct LinkedActor *a, struct LinkedActor *p)
{
    struct ActorSubMoveBytes *sub = (struct ActorSubMoveBytes *)&A(p)->sub2a4;
    if (A(a)->b19e) {
        if (a->s28) {
            sub->b5--;
            a->s28 = 1;
        }
    }
}
