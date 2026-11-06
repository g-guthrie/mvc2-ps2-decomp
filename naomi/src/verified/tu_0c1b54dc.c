/* Actor constructor, dispatcher, and initialization callback. */
#include "objects.h"

extern struct LinkedActor *func_0c0374da(int, int, int);
extern void (*const table_0c25b0e4[])(struct LinkedActor *, struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *, int, int);

void func_0c1b5518(struct LinkedActor *a);

struct LinkedActor *func_0c1b54dc(struct LinkedActor *parent, int x, int y)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 1)) != 0) {
        a->w38 = 0x2b00;
        a->b32 = x;
        a->b33 = y;
        a->p16 = func_0c1b5518;
        a->p24 = parent;
    }
    return a;
}

void func_0c1b5518(struct LinkedActor *a)
{
    table_0c25b0e4[a->b4](a, a->p24);
}

void func_0c1b552c(struct LinkedActor *a, struct LinkedActor *b)
{
    a->b4++;
    a->sdc = b->sdc;
    a->sdc.b12c = 1;
    a->b2 = b->b2;
    a->b1 = b->b1;
    a->v80.x = b->v80.x;
    a->v80.y = b->v80.y;
    a->b1a3 = b->b1a3;
    a->b1a4 = b->b1a4;
    a->b48 = b->b48;
    a->v80 = b->v80;
    a->b36 = b->b36;
    a->sdc.b12c = 0;
    a->sdc.w130 = a->b32;
    a->b36 = a->b33 ? 12 : 11;
    func_0c02a0c4(a, 23, a->b33 + 21);
}
