#include "objects.h"

extern struct LinkedActor *func_0c0374da(int a, int b, int c);
extern void func_0c1e4c8c(struct LinkedActor *a);

void func_0c1e4fc4(void)
{
    struct LinkedActor *p;

    if ((p = func_0c0374da(0, 5, 1)) != 0)
        p->p16 = func_0c1e4c8c;
}
