/* Actor callback pair and its shared literal pool. */
#include "objects.h"

extern char func_0c02a026(struct Actor *);
extern void func_0c037688(struct Actor *);

void func_0c194bb4(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->b4 = a->b4 + 1;
        a->b12c = 0;
    }
}

void func_0c194bd6(struct Actor *a)
{
    func_0c037688(a);
}
