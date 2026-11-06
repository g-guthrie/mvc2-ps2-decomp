#include "objects.h"

extern void func_0c029e70(struct LinkedActor *, int, int);
extern char func_0c029fc4(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);

void func_0c1b605c(struct LinkedActor *a, struct LinkedActor *b)
{
    if (!a->b4) {
        if (((unsigned char *)b)[0x1f9] == 2)
            goto cleanup;
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
        a->f52 = b->f52;
        a->f56 = b->f56;
        func_0c029e70(a, 27, (char)a->b32 + 2);
    }
    if (func_0c029fc4(a) < 0) {
cleanup:
        func_0c037688(a);
    }
}

void func_0c1b60fc(struct LinkedActor *a, struct LinkedActor *b)
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
        func_0c029e70(a, 27, 4);
    }
    a->f52 = b->f52;
    a->f56 = *(float *)((char *)b + 0x41c);
    if (func_0c029fc4(a) < 0)
        func_0c037688(a);
}
