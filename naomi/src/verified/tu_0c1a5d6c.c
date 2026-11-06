#include "objects.h"

extern void func_0c029fc4(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c1a5db6(struct LinkedActor *);

void func_0c1a5d6c(struct LinkedActor *a)
{
    *(struct LinkedActorVec3 *)&a->f52 =
        *(struct LinkedActorVec3 *)&a->p20->f52;
    if (a->b1 != a->p24->b1) {
        func_0c1a5db6(a);
        return;
    }
    if (a->p20->b4 > 3) {
        a->b4 = 2;
        a->sdc.b12c = 0;
    }
    func_0c029fc4(a);
}

void func_0c1a5da8(struct LinkedActor *a)
{
    a->b4++;
    a->sdc.b12c = 0;
}

void func_0c1a5db6(struct LinkedActor *a)
{
    func_0c037688(a);
}
