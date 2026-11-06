#include "objects.h"
extern unsigned int dat_0c244028[];
void func_0c0a2d9c(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit=112;
    register unsigned int *out = *((unsigned int **)((char *)a+0x428));
    register unsigned int *in=dat_0c244028;
    i=0;
loop:
    *(unsigned int *)((char *)out+i)=*(unsigned int *)((char *)in+i);
    i+=4;
    if (i<limit) goto loop;
}
char func_0c0a2db8(struct Actor *a)
{
    if (a->b1f9 != 2) return 1;
    goto L; L:
    if (a->b1fc) return 1;
    if (a->b1d4) return 0;
    a->b1d4=a->b1d4+1;
    return 1;
}
