#include "objects.h"
typedef void (*Handler_1a9ad8)(struct Actor *);
extern Handler_1a9ad8 table_0c25967c[];

void func_0c1a9ad8(struct Actor *a)
{
    a->f80 *= 1.5f;
    a->f84 *= 0.9f;
    a->f264 -= 0.032000002f;
    if (--a->s30 <= 0)
        a->b4++;
}

void func_0c1a9b18(struct Actor *a)
{
    table_0c25967c[a->b4](a);
}
