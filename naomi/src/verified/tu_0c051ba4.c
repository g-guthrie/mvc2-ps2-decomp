#include "objects.h"

extern struct ActorFlags *dat_0c2d6f84;

int func_0c051ba4(struct Actor *a)
{
    if (a->b6 == 5 && (dat_0c2d6f84->flags & 1) != 0)
        a->w4dc = 0x1100;
    return 0;
}

int func_0c051bc0(struct Actor *a)
{
    if (a->b6 == 5 && (dat_0c2d6f84->flags & 1) != 0)
        a->w4dc = 0x2100;
    return 0;
}

int func_0c051bdc(struct Actor *a)
{
    if (a->b6 == 5 && (dat_0c2d6f84->flags & 1) != 0)
        a->w4dc = (a->b1d2 * 3 << 10) ^ 0x2500;
    return 0;
}
