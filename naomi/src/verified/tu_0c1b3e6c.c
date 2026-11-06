#include "objects.h"

extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
extern char func_0c02a026(struct LinkedActor *);
extern void (*const table_0c25afd8[])(struct LinkedActor *, struct LinkedActor *);

void func_0c1b3ec4(struct LinkedActor *);

struct LinkedActor *func_0c1b3e6c(struct LinkedActor *parent, unsigned char side)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 1)) != 0) {
        a->p16 = func_0c1b3ec4;
        a->b32 = side;
        a->b33 = 0;
        a->p24 = parent;
        a->b1 = parent->b1;
        a->f52 = parent->f52;
        a->f56 = parent->f56;
        a->w38 = 0x2900;
        a->wcc.dword_value = (unsigned short)parent->sdc.w158.short_value;
    }
    return a;
}

void func_0c1b3ec4(struct LinkedActor *a)
{
    struct LinkedActor *b = a->p24;
    if (a->b4 >= 2)
        func_0c037688(a);
    else
        table_0c25afd8[a->b32](a, b);
}

void func_0c1b3eee(struct LinkedActor *a, struct LinkedActor *b)
{
    if (!a->b4) {
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
        func_0c02a0c4(a, 23, 1);
    }
    a->b36 = b->b36;
    a->b49 = -1;
    if (((unsigned char *)b)[0x159] == 22 &&
        ((char *)b)[0x158] == 0) {
        a->f52 = b->f52;
        a->f56 = b->f56;
        func_0c02a026(a);
    } else {
        func_0c037688(a);
    }
}
