#include "objects.h"
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern unsigned char dat_0c24b42c[], dat_0c24b43c[];
extern void func_0c107f92(struct Actor *);
extern void (*dat_0c24b4bc[])(struct Actor *);
int func_0c105d42(struct Actor *);
int func_0c105d7a(struct Actor *);

int func_0c105d1c(struct Actor *a)
{
    if (func_0c105d42(a)) return 1;
    if (func_0c105d7a(a)) return 1;
    return 0;
}

int func_0c105d42(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24b42c, (unsigned char *)a + 0x38c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 1;
    return 1;
}

int func_0c105d7a(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24b43c, (unsigned char *)a + 0x394))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 6;
    return 1;
}

void func_0c105db0(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    if (a->b201 && !a->b5) {
        if (--*(unsigned short *)&sub->w4 == 0) {
            if (a->b1d0 == 21)
                *(unsigned short *)&sub->w4 = 1;
            else
                func_0c107f92(a);
        }
    }
}

void func_0c105de8(struct Actor *a)
{
    dat_0c24b4bc[(unsigned char)a->b1ff](a);
}
