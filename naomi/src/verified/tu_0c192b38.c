/* Linked-actor emitter pair: copies the owner's partner block and spawns scattering children. */
#include "objects.h"
#define A(p) ((struct Actor *)(p))
#define L(p) ((struct LinkedActor *)(p))
extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c02a39a(struct LinkedActor *, int);
extern int func_0c02849a(void);
extern void func_0c029e70(struct LinkedActor *, int, unsigned char);
extern char func_0c029fc4(struct LinkedActor *);
extern struct ActorFlags *dat_0c2d6f84;
void func_0c192b78(struct LinkedActor *a);
void func_0c192ba0(struct LinkedActor *a, struct LinkedActor *o);
void func_0c192d44(struct LinkedActor *a, struct LinkedActor *o);

struct LinkedActor *func_0c192b38(struct Actor *owner)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c192b78;
        a->b32 = 0;
        a->b33 = 0;
        a->p24 = L(owner->p1c8);
        a->b1 = owner->b1;
        a->w38 = 0x905;
    }
    return a;
}

void func_0c192b78(struct LinkedActor *a)
{
    struct LinkedActor *o = a->p24;
    if (a->b4 >= 2)
        func_0c037688(a);
    else if (!a->b32)
        func_0c192ba0(a, o);
    else
        func_0c192d44(a, o);
}

void func_0c192ba0(struct LinkedActor *a, struct LinkedActor *o)
{
    struct LinkedActor *n;
    int k;
    a->sdc.b12c = 0;
    a->b36 = o->b36;
    if (!a->b4) {
        a->b4++;
        a->sdc = L(A(o)->p1c8)->sdc;
        a->sdc.b12c = 1;
        a->b2 = A(o)->p1c8->b2;
        a->b1 = A(o)->p1c8->b1;
        A(a)->f80 = A(o)->p1c8->f80;
        A(a)->f84 = A(o)->p1c8->f84;
        a->b1a3 = L(A(o)->p1c8)->b1a3;
        a->b1a4 = L(A(o)->p1c8)->b1a4;
        a->b48 = L(A(o)->p1c8)->b48;
        a->v80 = L(A(o)->p1c8)->v80;
        a->b36 = A(o)->p1c8->b36;
        a->b49 = -1;
        a->f52 = A(o)->p1c8->f52;
        a->f56 = A(o)->p1c8->f56;
        a->s30 = 10;
    } else {
    if (!A(o)->b22a) {
    k = (unsigned char)o->b5;
    if (k == 3 || k == 2) {
        func_0c02a39a(a->p24, 7);
        if (a->s30) {
        if ((n = func_0c0374da(0, 3, 0)) != 0) {
            n->p16 = func_0c192b78;
            n->b32 = (dat_0c2d6f84->flags & 3) + 1;
            n->b33 = 0;
            n->p24 = a->p24;
            n->b1 = A(o)->p1c8->b1;
            n->w38 = 0x905;
            n->wcc.arrcc[0] = (func_0c02849a() & 63) - 32;
            n->wcc.arrcc[1] = 64 - (func_0c02849a() & 63);
        }
        a->s30--;
        }
        return;
    }
    goto D; D: func_0c02a39a(a->p24, 1);
    }
    func_0c037688(a);
    }
}

void func_0c192d44(struct LinkedActor *a, struct LinkedActor *o)
{
    int k;
    a->b36 = o->b36;
    if (!a->b4) {
        a->b4++;
        a->sdc = L(A(o)->p1c8)->sdc;
        a->sdc.b12c = 1;
        a->b2 = A(o)->p1c8->b2;
        a->b1 = A(o)->p1c8->b1;
        A(a)->f80 = A(o)->p1c8->f80;
        A(a)->f84 = A(o)->p1c8->f84;
        a->b1a3 = L(A(o)->p1c8)->b1a3;
        a->b1a4 = L(A(o)->p1c8)->b1a4;
        a->b48 = L(A(o)->p1c8)->b48;
        a->v80 = L(A(o)->p1c8)->v80;
        a->b36 = A(o)->p1c8->b36;
        a->b49 = -1;
        func_0c029e70(a, 27, a->b32 + 255);
        a->s28 = 300;
        a->sdc.b12c = 0;
        if ((a->sdc.w130 = o->sdc.w130) != 0)
            a->wcc.arrcc[0] = -a->wcc.arrcc[0];
        return;
    }
    if (!a->b5) {
        if (!A(o)->b22a) {
            k = (unsigned char)o->b5;
            if (k == 3 || k == 2) {
        a->sdc.b12c = 1;
        a->f52 = o->f52 + (float)a->wcc.arrcc[0] * 1.66666663f;
        a->f56 = o->f56 + (float)a->wcc.arrcc[1] * 2.1428571f;
        func_0c029fc4(a);
        return;
            }
            a->b5++;
            func_0c029e70(a, 27, 4);
            return;
        }
    } else if (func_0c029fc4(a) >= 0)
        return;
    func_0c037688(a);
}
