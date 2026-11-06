#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c096904(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){a->b6++;a->s28=20;a->f92=a->b1d2==0?13.33333302f:-13.33333302f;a->f96=4.28571415f;a->f108=-0.5357143f;}
}
void func_0c09694c(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;
 a->f96+=a->f108;if(a->f96&&!(a->f56>=a->f41c)){a->f56=a->f41c;a->f96=0;a->f108=0;}
 if(--a->s28<=0){a->b6++;a->f104=a->b1d2==0?-0.26041666f:0.26041666f;func_0c02a0c4(a,2,3);}
}
