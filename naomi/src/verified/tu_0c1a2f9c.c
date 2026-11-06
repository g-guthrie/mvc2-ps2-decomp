#include "objects.h"

typedef void (*LinkedActorHandler)(struct LinkedActor *);
extern struct LinkedActor *func_0c0374da(int, int, int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a18c(struct LinkedActor *, int, int, int);
extern LinkedActorHandler table_0c258f64[];
extern LinkedActorHandler table_0c258f74[];
extern LinkedActorHandler table_0c258f84[];
void func_0c1a2fd0(struct LinkedActor *);

struct LinkedActor *func_0c1a2f9c(struct LinkedActor *p, unsigned char b)
{
    struct LinkedActor *q;
    if ((q = func_0c0374da(0, 3, 0)) != 0) {
        q->p16 = func_0c1a2fd0;
        q->p24 = p;
        q->b32 = b;
        q->w38 = 0x1500;
    }
    return q;
}

void func_0c1a2fd0(struct LinkedActor *a)
{
    table_0c258f64[a->b32](a);
}

void func_0c1a2fe4(struct LinkedActor *a)
{
    table_0c258f74[a->b4](a);
}

void func_0c1a2ff6(struct LinkedActor *a)
{
    a->b4++;
    a->sdc = a->p24->sdc;
    a->sdc.b12c = 1;
    a->b2 = a->p24->b2;
    a->b1 = a->p24->b1;
    a->v80.x = a->p24->v80.x;
    a->v80.y = a->p24->v80.y;
    a->b1a3 = a->p24->b1a3;
    a->b1a4 = a->p24->b1a4;
    a->b48 = a->p24->b48;
    a->v80 = a->p24->v80;
    /* The parent state is copied before this transition resets the byte. */
    a->b36 = a->p24->b36;
    a->b36 = 0;
    if (a->b33)
        func_0c02a18c(a, 21, 16, 6);
    else
        func_0c02a18c(a, 21, 10, 6);
}

void func_0c1a3078(struct LinkedActor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4++;
        a->sdc.b12c = 0;
    }
}

void func_0c1a309a(struct LinkedActor *a)
{
    table_0c258f84[a->b4](a);
}
