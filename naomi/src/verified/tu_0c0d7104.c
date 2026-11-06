#include "objects.h"
extern void (*dat_0c24891c[])(struct Actor *);
extern unsigned char dat_0c24887c[];
extern unsigned char dat_0c24888c[];
extern unsigned char dat_0c24889c[];
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
int func_0c0d7104(struct Actor *a);
int func_0c0d7130(struct Actor *a);
int func_0c0d7166(struct Actor *a);
int func_0c0d719c(struct Actor *a);
void func_0c0d71d2(struct Actor *a);
void func_0c0d71d6(struct Actor *a);

int func_0c0d7104(struct Actor *a)
{
    if (func_0c0d7130(a) || func_0c0d7166(a) || func_0c0d719c(a))
        return 1;
    return 0;
}

int func_0c0d7130(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24889c, (unsigned char *)a + 0x394))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 3;
    return 1;
}

int func_0c0d7166(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24888c, (unsigned char *)a + 0x38c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 4;
    return 1;
}

int func_0c0d719c(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24887c, (unsigned char *)a + 0x384))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 2;
    return 1;
}

void func_0c0d71d2(struct Actor *a) {}

void func_0c0d71d6(struct Actor *a)
{
    dat_0c24891c[a->b1ff](a);
}
