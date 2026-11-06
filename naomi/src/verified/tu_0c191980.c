/* Linked-actor attachments that follow the owner's position while its 0x159 action matches. */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c029e70(struct LinkedActor *, int, int);
extern char func_0c029fc4(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern void (*table_0c2577b4[])(struct LinkedActor *);
extern void (*table_0c2577c0[])(struct LinkedActor *);
extern char dat_0c2577ac[];
void func_0c1919b4(struct LinkedActor *a);
int func_0c191cc2(struct LinkedActor *a, int action);
void func_0c191cde(struct LinkedActor *a);

struct LinkedActor *func_0c191980(struct LinkedActor *owner, int kind)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 1, 1)) != 0) {
        a->w38 = 0x700;
        a->b32 = kind;
        a->p16 = func_0c1919b4;
        a->p24 = owner;
    }
    return a;
}

void func_0c1919b4(struct LinkedActor *a)
{
    table_0c2577b4[a->b4](a);
}

void func_0c1919c6(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    a->b4++;
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
    a->b36 = 0;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    func_0c029e70(a, 27, dat_0c2577ac[a->b32]);
}

void func_0c191a48(struct LinkedActor *p)
{
    register struct LinkedActor *a = p;
    table_0c2577c0[a->b32](a);
}

void func_0c191a5c(struct LinkedActor *a)
{
    if (func_0c029fc4(a) < 0)
        func_0c191cde(a);
}

void func_0c191a7c(struct LinkedActor *a)
{
    if (!a->b5 && !func_0c191cc2(a, 7) && !func_0c191cc2(a, 20) && !func_0c191cc2(a, 21))
        goto kill;
    if (func_0c029fc4(a) < 0)
kill:
        func_0c191cde(a);
}

void func_0c191aee(struct LinkedActor *a)
{
    if (!a->b5 && !func_0c191cc2(a, 9) && !func_0c191cc2(a, 21))
        goto kill;
    if (func_0c029fc4(a) < 0)
kill:
        func_0c191cde(a);
}

void func_0c191b28(struct LinkedActor *a)
{
    if (!a->b5 && !func_0c191cc2(a, 11))
        goto kill;
    if (func_0c029fc4(a) < 0) {
kill:
        func_0c191cde(a);
        return;
    }
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&a->p24->f52;
}

void func_0c191b66(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    if ((unsigned char)o->b5 == 3 || (((char *)o)[0x1fd] & 1) == A(o)->b1d2)
        goto kill;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    if (!a->b5) {
        func_0c029fc4(a);
        if ((unsigned char)A(o)->b159 != 22)
            goto kill;
        if ((unsigned char)A(o)->b158 == 10 || A(o)->f92 == 0.0f) {
            a->b5++;
            func_0c029e70(a, 27, 6);
        }
        return;
    } else if (func_0c029fc4(a) >= 0)
        return;
kill:
    func_0c191cde(a);
}

void func_0c191c0a(struct LinkedActor *a)
{
    if (!a->b5) {
        int r = func_0c191cc2(a, 23);
        r |= func_0c191cc2(a, 19);
        r |= func_0c191cc2(a, 20);
        if (!r)
            goto kill;
    }
    if (func_0c029fc4(a) < 0) {
kill:
        func_0c191cde(a);
        return;
    }
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&a->p24->f52;
}

void func_0c191c60(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    if (o->b5)
        goto kill;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    if (!a->b5) {
        if (func_0c029fc4(a) >= 0)
            return;
        a->b5++;
        func_0c029e70(a, 27, 6);
        return;
    } else if (func_0c029fc4(a) >= 0)
        return;
kill:
    func_0c191cde(a);
}

void func_0c191cbc(struct LinkedActor *a)
{
    func_0c037688(a);
}

int func_0c191cc2(struct LinkedActor *a, int action)
{
    struct LinkedActor *o = a->p24;
    if (a->sdc.b141)
        a->b5++;
    return (unsigned char)A(o)->b159 == action;
}

void func_0c191cde(struct LinkedActor *a)
{
    a->b4 = 2;
    a->sdc.b12c = 0;
}
