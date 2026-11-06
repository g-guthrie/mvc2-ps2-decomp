#include "objects.h"
extern void func_0c037688(struct Actor *);

void func_0c153fe4(struct Actor *a, int unused, struct Actor *b)
{
    a->f264 -= 0.1000000015f;
    if (a->f264 <= 0.0f) {
        a->b4++;
        b->b4 = 0;
    }
}

void func_0c154008(struct Actor *a)
{
    a->b4++;
    a->b12c = 0;
}

void func_0c154016(struct Actor *a)
{
    func_0c037688(a);
}
