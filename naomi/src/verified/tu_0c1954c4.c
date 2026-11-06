/* Linked-actor followers that copy the owner's block and react to its 0x2a4 record. */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern void func_0c02a026(struct LinkedActor *);
extern void (*table_0c257f08[])(struct LinkedActor *, struct LinkedActor *);
extern void (*table_0c257f14[])(struct LinkedActor *);

void func_0c1954c4(struct LinkedActor *a, struct LinkedActor *o)
{
    struct ActorActionResult56 *p = (struct ActorActionResult56 *)&A(o)->sub2a4;
    if (p->pad28[29] || (unsigned char)A(o)->b159 != 19 || (unsigned char)A(o)->b158 != 1) {
        a->b4 = 2;
        a->sdc.b12c = 0;
    }
    table_0c257f08[a->b4](a, o);
}

void func_0c195502(struct LinkedActor *a, struct LinkedActor *o)
{
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
    a->b4++;
    a->b36 = 7;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    a->f92 = 0.20833333f;
    a->f104 = -0.013020833023f;
    func_0c02a0c4(a, 23, 22);
}

void func_0c195586(struct LinkedActor *a, struct LinkedActor *o)
{
    float x, d;
    if (!a->b5) {
        if (A(o)->b14b) {
            a->b5++;
            func_0c02a026(a);
        }
        return;
    } else {
        func_0c02a026(a);
        x = a->f52;
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
        d = x - a->f52;
        if (d < 0.0f)
            d = -d;
        if (!(d < 0.44921875f)) {
            a->f104 = -a->f104; a->f92 = a->f104 * 2.0f;
        }
    }
}

void func_0c195648(struct LinkedActor *a)
{
    table_0c257f14[a->b4](a);
}

void func_0c19565a(struct LinkedActor *a, struct LinkedActor *o)
{
    int n;
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
    a->b4++;
    a->b36 = 0;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    a->b33 = ((char *)a)[0x130];
    n = o->b32;
    if (a->sdc.w130) {
        a->f52 += 266.66666f;
        a->sdc.w130 = 0;
        n += 3;
    }
    func_0c02a0c4(a, 23, n + 26);
}
