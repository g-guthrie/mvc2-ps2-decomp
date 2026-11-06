#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int);
void func_0c106fd8(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;
 if(--a->s28==0){a->b6++;a->f104=a->b1d2?0.41666666f:-0.41666666f;func_0c02a0c4(a,2,3);}
}
void func_0c10703a(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c10705c(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 a->b6++;a->b12c=1;sub->b1=0;a->f56+=480.0f;a->f96=-8.5714283f;
 func_0c02a0c4(a,18,0);func_0c0344a0(a,34);
}
void func_0c1070a2(struct Actor *a)
{
 func_0c02a026(a);a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f41c<a->f56)){a->b6++;a->f56=a->f41c;a->f96=-4.28571415f;a->s28=8;}
}
