#include "objects.h"
extern signed char func_0c02a026(struct Actor *);
extern void func_0c037688(struct Actor *);

void func_0c140ed4(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4 = 2;
        a->b12c = 0;
    }
}

void func_0c140ef4(struct Actor *a)
{
    func_0c037688(a);
}
