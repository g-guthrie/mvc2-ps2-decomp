#include "objects.h"

struct InitGlobal_0c1da330 {
    unsigned char pad[12];
    void *p0c;
};

extern struct LinkedActor *func_0c0374da(int, int, int);
extern void func_0c1da1d0(struct LinkedActor *);
extern struct InitGlobal_0c1da330 **dat_0c2d964c;
extern struct LinkedActorVec3 dat_0c261d88;

void func_0c1da330(void)
{
    struct LinkedActor *r;

    if ((r = func_0c0374da(0, 5, 1)) != 0) {
        r->sdc.b12c = 1;
        r->p16 = func_0c1da1d0;
        r->p84 = (**dat_0c2d964c).p0c;
        r->wcc.dword_value = 0x0805;
        *(struct LinkedActorVec3 *)&r->f52 = dat_0c261d88;
    }
}
