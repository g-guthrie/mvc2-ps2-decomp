#include "objects.h"
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern unsigned char dat_0c243394[],dat_0c2433a4[],dat_0c2433c4[];
int func_0c099330(struct Actor*),func_0c099370(struct Actor*),func_0c0993a6(struct Actor*);
int func_0c099304(struct Actor *a)
{
    if (func_0c099330(a) || func_0c099370(a) || func_0c0993a6(a))
        return 1;
    return 0;
}

int func_0c099330(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c243394, a->x39c) || !*a->p40c || a->b1f9 == 2)
        return 0;
    a->b258 = 6;
    return 1;
}

int func_0c099370(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2433a4, a->x3a4))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 7;
    return 1;
}

int func_0c0993a6(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2433c4, a->x3ac))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 8;
    return 1;
}
