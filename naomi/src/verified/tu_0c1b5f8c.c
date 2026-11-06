#include "objects.h"

extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c037688(struct LinkedActor *);
extern void (*const table_0c25b350[])(struct LinkedActor *, struct LinkedActor *);

void func_0c1b6020(struct LinkedActor *a);

struct LinkedActor *func_0c1b5f8c(struct LinkedActor *parent, unsigned char side)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c1b6020;
        a->b32 = side;
        a->b33 = 0;
        a->p24 = parent;
        a->b1 = parent->b1;
        a->w38 = 0x2c01;
    }
    return a;
}

struct LinkedActor *func_0c1b5fd2(struct LinkedActor *parent, unsigned char side, unsigned char kind)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 0)) != 0) {
        a->p16 = func_0c1b6020;
        a->b32 = side;
        a->b33 = kind;
        a->p24 = parent;
        a->b1 = parent->b1;
        a->w38 = 0x2c01;
    }
    return a;
}

void func_0c1b6020(struct LinkedActor *a)
{
    struct LinkedActor *b = a->p24;
    if (a->b4 >= 2)
        func_0c037688(a);
    else
        table_0c25b350[a->b32](a, b);
}
