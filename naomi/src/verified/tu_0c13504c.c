#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c18f9ba(struct Actor *,int);
void func_0c13504c(struct Actor *a,struct Actor *owner)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56>owner->f41c+548.571411133f){a->f56=owner->f41c+548.571411133f;a->b5++;}
 func_0c02a026(a);
}
void func_0c1350ac(struct Actor *a,struct Actor *owner)
{
 struct ActorSub2a4 *sub=&owner->sub2a4;
 if(*(char *)&sub->s14){a->b5++;func_0c02a0c4(a,22,17);return;}func_0c02a026(a);
}
void func_0c1350ca(struct Actor *a)
{
 func_0c02a026(a);if(a->b141){if(a->b141==63){a->b5++;func_0c18f9ba(a,3);func_0c02a0c4(a,22,18);}else a->b141=0;}
}
void func_0c13510a(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->s28=30;a->b5++;a->f92=3.3333333f;a->f108=0.0f;a->f96=-4.28571415f;a->f108=-1.07142854f;
  if(a->w130)a->f92=-a->f92;func_0c02a0c4(a,22,19);}
}
void func_0c135166(struct Actor *a){if(--a->s28==0){a->b4++;a->b12c=0;}}
