#include "objects.h"

typedef void (*ActorHandler_1a9770)(struct Actor *);

extern char func_0c029fc4(struct Actor *);
extern void func_0c029e70(struct Actor *, int, int);
extern ActorHandler_1a9770 table_0c259654[];

void func_0c1a9770(struct Actor *a)
{
    float scale;

    a->b12c = 1;
    a->b4++;
    if (a->b33 == 0) {
        /* Keep this state's two multiplies separate from the scaled branch. */
        ((volatile struct Actor *)a)->f80 *= 0.800000012f;
        ((volatile struct Actor *)a)->f84 *= 0.800000012f;
        goto done;
    }
    if (a->b33 == 1)
        scale = 1.0f;
    else
        scale = 1.20000005f;
    a->f80 *= scale;
    a->f84 *= scale;
done:
    a->b36 = 8;
    func_0c029e70(a, 27, 2);
}

void func_0c1a97c8(struct Actor *a)
{
    if (func_0c029fc4(a) < 0) {
        a->b4 = a->b4 + 1;
        a->b12c = 0;
    }
}

void func_0c1a97ea(struct Actor *a)
{
    table_0c259654[a->b4](a);
}
