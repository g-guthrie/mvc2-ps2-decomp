/* Linked-actor pair spawned by func_0c19715c: mirrors the owner's 0x140 animation into velocity steps. */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern void func_0c02a026(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern struct Dat_13bb5c dat_0c2f8338;
extern void (*table_0c2580b0[])(struct LinkedActor *);
extern void (*table_0c2580b8[])(struct LinkedActor *, struct LinkedActor *);
extern void (*table_0c2580c4[])(struct LinkedActor *);
extern char dat_0c258048[];
extern short dat_0c258060[];
void func_0c1971a2(struct LinkedActor *a);
void func_0c197266(struct LinkedActor *a, struct LinkedActor *o);

struct LinkedActor *func_0c19715c(struct LinkedActor *owner, int side, int part)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 1)) != 0) {
        a->w38 = 0xe00;
        a->b32 = side;
        a->b33 = part;
        a->p16 = func_0c1971a2;
        a->p24 = owner;
        a->s28 = (unsigned char)A(owner)->b159;
    }
    return a;
}

void func_0c1971a2(struct LinkedActor *a)
{
    table_0c2580b0[a->b32](a);
}

void func_0c1971b6(struct LinkedActor *a)
{
    table_0c2580b8[a->b4](a, a->p24);
}

void func_0c1971ca(struct LinkedActor *a, struct LinkedActor *o)
{
    a->b4++;
    a->b34 = 0xff;
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
    { float z = 0.0f; A(a)->f104 = z; A(a)->f108 = z; }
    a->b36 = o->b36;
    a->b49 = -8;
    if (!a->b33) {
        func_0c19715c(o, 0, 1);
        func_0c19715c(o, 0, 2);
    }
    func_0c197266(a, o);
}

void func_0c197266(struct LinkedActor *a, struct LinkedActor *o)
{
    int i;
    int c;
    short *p;
    if (o->b5 || A(o)->b1d0 != 21 || A(o)->b1e9 != 0 || (unsigned char)A(o)->b159 != a->s28) {
        a->b4 = 2;
        goto off;
    }
    if (dat_0c2f8338.w3c & (1 << dat_0c2f8338.b3b))
        return;
    a->b36 = o->b36;
    a->b49 = -8;
    if (!(c = o->sdc.b140))
        goto off;
    a->sdc.b12c = 1;
    if (c != a->b34) {
        a->b34 = c;
        i = (c & 15) * 4 + (unsigned char)a->b33;
        func_0c02a0c4(a, 23, dat_0c258048[i]);
        p = dat_0c258060;
        p += ((a->b34 & 15) - 1) * 8 + (unsigned char)a->b33 * 2;
        a->f92 = *p++ * 1.66666663f;
        a->f96 = *p * 2.1428571f;
        if (A(o)->b1d2)
            a->f92 = -a->f92;
    }
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    a->f52 += a->f92;
    a->f92 += A(a)->f104;
    a->f56 += a->f96;
    a->f96 += A(a)->f108;
    func_0c02a026(a);
    return;
off:
    goto LB0_100; LB0_100:
    a->sdc.b12c = 0;
}

void func_0c1973d6(struct LinkedActor *a)
{
    func_0c037688(a);
}

void func_0c1973dc(struct LinkedActor *a)
{
    table_0c2580c4[a->b4](a);
}
