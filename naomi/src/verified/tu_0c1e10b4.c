#include "objects.h"

struct Global_1e10b4 { int pad[5]; int arr[32]; };
extern struct Global_1e10b4 **dat_0c2d964c;
extern char dat_0c2627ec[];
extern struct LinkedActorSequence *func_0c0374da(int,int,int);
void func_0c1e10b4(struct LinkedActorSequence *a)
{
    a->l84 = ((int *)(*dat_0c2d964c))[5 + dat_0c2627ec[a->s28]];
    if ((unsigned)(short)(++a->s28) >= 15)
        a->s28 = 0;
}
void func_0c1e10e2(void)
{
    struct LinkedActorSequence *a;
    if ((a = func_0c0374da(0,5,1)) != 0) {
        a->b12c = 1;
        a->p16 = func_0c1e10b4;
        a->lcc = 0x800;
    }
}
