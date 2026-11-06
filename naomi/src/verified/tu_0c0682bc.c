#include "objects.h"
extern void (*dat_0c24067c[])(struct Actor *);
extern unsigned char dat_0c2405dc[];
extern unsigned char dat_0c2405ec[];
extern unsigned char dat_0c2405fc[];
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
int func_0c0682bc(struct Actor *a);
int func_0c0682e8(struct Actor *a);
int func_0c06831e(struct Actor *a);
int func_0c068354(struct Actor *a);
void func_0c0683a0(struct Actor *a);
void func_0c0683a4(struct Actor *a);

int func_0c0682bc(struct Actor *a)
{
    if (func_0c0682e8(a) || func_0c06831e(a) || func_0c068354(a))
        return 1;
    return 0;
}

int func_0c0682e8(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2405dc, (unsigned char *)a + 0x36c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 12;
    return 1;
}

int func_0c06831e(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2405ec, (unsigned char *)a + 0x374))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 10;
    return 1;
}

int func_0c068354(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c2405fc,a->x37c))return 0;
 if(!*a->p40c)return 0;
 if(sub->b0)return 0;
 a->b258=4;return 1;
}

void func_0c0683a0(struct Actor *a) {}

void func_0c0683a4(struct Actor *a)
{
    dat_0c24067c[a->b1ff](a);
}
