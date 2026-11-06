#include "objects.h"

extern struct LinkedActor *func_0c0374da(int, int, int);
extern void (*const table_0c25b0cc[])(struct LinkedActor *, struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *, int, int);
void func_0c1b50c0(struct LinkedActor *);

struct LinkedActor *func_0c1b5070(struct LinkedActor *parent, int side, int kind)
{
    struct LinkedActor *a;
    if ((a = func_0c0374da(0, 3, 1)) != 0) {
        a->w38 = 0x2b00;
        a->b32 = side;
        a->b33 = kind;
        a->b34 = parent->b1d0;
        a->s28 = ((unsigned char *)parent)[0x1e9];
        a->p16 = func_0c1b50c0;
        a->p24 = parent;
    }
    return a;
}

void func_0c1b50c0(struct LinkedActor *a)
{
    table_0c25b0cc[a->b4](a, a->p24);
}

void func_0c1b50d4(struct LinkedActor *a, struct LinkedActor *b)
{
    int n;
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
    a->b36 = 7;
    n = (unsigned char)a->b32 * 3 + (unsigned char)a->b33;
    func_0c02a0c4(a, 23, n + 12);
}
