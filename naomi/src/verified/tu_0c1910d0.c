/* Linked-actor effect family: spawners, a b4/b32/b5-dispatched state machine and its launch arcs.
 * The child spawners copy the position through the Obj_tu5_03 pos view (offset 52). */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
extern struct LinkedActor *func_0c0374da(struct LinkedActor *, int, int);
extern void func_0c029e70(struct LinkedActor *, int, int);
extern char func_0c029fc4(struct LinkedActor *);
extern void (*table_0c257720[])(struct LinkedActor *);
extern void (*table_0c257730[])(struct LinkedActor *);
extern void (*table_0c257770[])(struct LinkedActor *, struct LinkedActor *);
extern void (*table_0c257794[])(struct LinkedActor *);
extern unsigned char table_0c257754[];
extern unsigned short table_0c257764[];
void func_0c1911a8(struct LinkedActor *a);
void func_0c191436(struct LinkedActor *a);

struct LinkedActor *func_0c1910d0(struct LinkedActor *owner, unsigned char kind)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c1911a8;
        a->p24 = owner;
        a->b32 = kind;
        a->w38 = 0x601;
        a->wcc.short_value = owner->sdc.w158.short_value;
    }
    return a;
}

struct LinkedActor *func_0c191114(struct LinkedActor *o, char kind)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(o, 3, 2)) != 0) {
        a->p16 = func_0c1911a8;
        a->p24 = o->p24;
        a->p20 = o;
        ((struct Obj_tu5_03 *)a)->pos = ((struct Obj_tu5_03 *)o)->pos;
        a->b32 = kind;
        a->w38 = 0x601;
    }
    return a;
}

struct LinkedActor *func_0c19115e(struct LinkedActor *o, char kind)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 1)) != 0) {
        a->p16 = func_0c1911a8;
        a->p24 = o->p24;
        a->p20 = o;
        ((struct Obj_tu5_03 *)a)->pos = ((struct Obj_tu5_03 *)o)->pos;
        a->b32 = kind;
        a->w38 = 0x601;
    }
    return a;
}

void func_0c1911a8(struct LinkedActor *a)
{
    table_0c257720[a->b4](a);
}

void func_0c1911ba(struct LinkedActor *a, struct LinkedActor *o)
{
    a->b4++;
    o = a->p24;
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
    table_0c257730[a->b32](a);
    func_0c191436(a);
}

void func_0c191254(struct LinkedActor *a, struct LinkedActor *o)
{
    float dx;
    a->sdc.b12c = 1;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    dx = 65.0f;
    if (o->sdc.w130)
        a->f52 += dx;
    else
        a->f52 -= dx;
    if (!a->b32)
        a->f56 += 190.71428f;
    else
        a->f56 += 135.0f;
    a->b49 = -1;
    func_0c029e70(a, 27, 2);
}

void func_0c1912b6(struct LinkedActor *a)
{
    a->b49 = -1;
    func_0c029e70(a, 27, 3);
}

void func_0c1912c4(struct LinkedActor *a, struct LinkedActor *o)
{
    float dx;
    a->b49 = -1;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    dx = 30.0f;
    if (a->sdc.w130)
        a->f52 += dx;
    else
        a->f52 -= dx;
    a->f56 += 212.142853f;
    func_0c029e70(a, 27, 4);
}

void func_0c19130e(struct LinkedActor *a, struct LinkedActor *o)
{
    float dx;
    a->b49 = -1;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    a->f96 = 12.85714245f;
    a->f108 = -0.5357143f;
    a->f92 = 3.3333333f;
    a->f104 = 0.0f;
    a->f56 += 188.57143f;
    dx = 80.0f;
    if (a->sdc.w130) {
        a->f92 = -a->f92;
        dx = -80.0f;
    }
    a->f52 += dx;
    func_0c029e70(a, 27, 5);
}

void func_0c19137a(struct LinkedActor *a)
{
    a->b49 = -16;
    func_0c029e70(a, 27, 6);
}

void func_0c1913c0(struct LinkedActor *a)
{
    a->b49 = -120;
    a->sdc.w130 ^= 1;
    a->l72 = table_0c257764[table_0c257754[a->p20->b34]];
    func_0c029e70(a, 27, 7);
}

void func_0c1913f2(struct LinkedActor *a, struct LinkedActor *o)
{
    a->b49 = -1;
    *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
    a->f96 = 207.857132f;
    a->f56 += a->f96;
    func_0c029e70(a, 27, 4);
}

void func_0c191428(struct LinkedActor *a)
{
    a->b49 = -16;
    func_0c029e70(a, 27, 8);
}

void func_0c191436(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    a->b36 = o->b36;
    table_0c257770[a->b32](a, o);
}

void func_0c191454(struct LinkedActor *a)
{
    if (func_0c029fc4(a) < 0) {
        a->b4++;
        a->sdc.b12c = 0;
    }
}

void func_0c191476(struct LinkedActor *a)
{
    table_0c257794[(unsigned char)a->b5](a);
}

void func_0c191488(struct LinkedActor *a, struct LinkedActor *o)
{
    float dx;
    a->sdc.b12c = 1;
    dx = 0.0f;
    switch (o->sdc.b141) {
    case 0:
        a->sdc.b12c = 0;
        break;
    case 3:
        a->b5++;
        a->f104 = dx;
        a->f92 = 1.66666663f;
        if (!a->sdc.w130)
            a->f92 = -a->f92;
        a->f96 = 12.85714245f;
        a->f108 = -0.5357143f;
        break;
    default:
        *(struct LinkedActorVec3 *)&a->f52 = *(struct LinkedActorVec3 *)&o->f52;
        if (o->sdc.b141 == 1)
            a->f56 += 240.0f;
        else {
            dx = -13.33333302f;
            a->f56 += 274.28571f;
        }
        if (!a->sdc.w130)
            dx = -dx;
        a->f52 += dx;
    }
}

void func_0c191556(struct LinkedActor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f96 > 0.0f)
        return;
    a->b5++;
    a->f92 = 0.0f;
    a->f104 = 0.0f;
    a->f96 = -2.1428571f;
    a->f108 = -0.2678571343422f;
    func_0c029fc4(a);
    a->s28 = 0;
}

void func_0c1915ca(struct LinkedActor *a, struct Actor *o)
{
    func_0c029fc4(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (!a->s28 && o->f41c + 205.71428f > a->f56) {
        a->s28 = 1;
        func_0c191114(a, 3);
    }
    if (a->f56 > o->f41c)
        return;
    a->b4++;
    a->sdc.b12c = 0;
}
