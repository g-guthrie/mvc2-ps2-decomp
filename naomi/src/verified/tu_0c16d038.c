/* Two actor state handlers and their shared literal pool. */
#include "objects.h"

extern void func_0c037688(struct Actor *);

void func_0c16d038(struct Actor *a)
{
    a->b4++;
    a->b12c = 0;
}

void func_0c16d046(struct Actor *a)
{
    func_0c037688(a);
}
