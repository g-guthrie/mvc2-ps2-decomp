#include "objects.h"

extern void func_0c02a18c(struct LinkedActor *, int, int, int);
extern void func_0c037688(struct LinkedActor *);

void func_0c1b3fd0(struct LinkedActor *a, struct LinkedActor *b)
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
        a->sdc.b12c = 0;
        a->b49 = -1;
    }
    if ((unsigned short)b->sdc.w158.short_value == a->wcc.dword_value) {
        if (b->sdc.b141) {
            func_0c02a18c(a, 23, 2, b->sdc.b141 - 1);
            a->f52 = b->f52;
            a->f56 = b->f56;
            a->b36 = b->b36;
            a->sdc.b12c = 1;
        } else {
            a->sdc.b12c = 0;
        }
    } else {
        func_0c037688(a);
    }
}
