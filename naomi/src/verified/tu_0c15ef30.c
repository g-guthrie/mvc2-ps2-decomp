/* Spawner and state handlers; matches retail exactly. func_0c15f00a is an
 * old-style definition whose second parameter only carries the owner in r5,
 * which is what retail's register choice requires. */
#include "objects.h"
#define LA struct LinkedActor
extern LA *func_0c0374da(LA *, int, int);
extern void (*table_0c25120c[])(LA *);
extern void (*table_0c25121c[])(LA *);
extern void (*table_0c25125c[])(LA *);
void func_0c15ef92(LA *);
void func_0c15f00a();

LA *func_0c15ef30(LA *a, char b)
{
    LA *q;
    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c15ef92;
        q->p24 = a;
        q->b32 = b;
    }
    return q;
}

LA *func_0c15ef5e(LA *a, char b)
{
    LA *q;
    if ((q = func_0c0374da(a, 1, 2)) != 0) {
        q->p16 = func_0c15ef92;
        q->p24 = a;
        q->b32 = b;
    }
    return q;
}

void func_0c15ef92(LA *a)
{
    table_0c25120c[a->b4](a);
}

void func_0c15efa4(LA *a)
{
    LA *o = a->p24;
    a->b4++;
    a->w38 = 0x1c06;
    a->sdc = o->sdc;
    a->sdc.b12c = 1;
    a->b2 = o->b2;
    a->b1 = o->b1;
    a->v80.x = o->v80.x;
    a->v80.y = o->v80.y;
    a->b1a3 = o->b1a3;
    a->b1a4 = o->b1a4;
    a->b48 = o->b48;
    a->v80 = o->v80;
    a->b36 = o->b36;
    a->b36 = 8;
    a->sdc.b12c = 1;
    func_0c15f00a(a);
}

void func_0c15f00a(a, o)
LA *a, *o;
{
    o = a->p24;
    if (o->b4 >= 2) {
        a->b4++;
        a->sdc.b12c = 0;
        return;
    }
    table_0c25121c[a->b32](a);
}

void func_0c15f040(LA *a)
{
    table_0c25125c[(unsigned char)a->b5](a);
}
