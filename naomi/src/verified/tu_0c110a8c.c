#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *);
void func_0c110a8c(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){a->b6++;a->f92=a->b1d2?-20.0f:20.0f;a->f104=a->b1d2?0.625f:-0.625f;a->f96=6.428571224213f;a->f108=-0.5357143f;}
}
void func_0c110ae6(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);
 if(!(a->f41c<a->f56)){a->b6++;a->b1f9=0;a->f56=a->f41c;a->f104=-(a->f92/8.0f);func_0c02a0c4(a,2,3);}
}
void func_0c110b6e(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
