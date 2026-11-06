#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *),func_0c02a0c4(struct Actor *,int,char);
void func_0c1452b8(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f96>-3.21428561211f)){a->b6++;a->f92=0.0f;a->f108=0.0f;}
 func_0c037d0c(a);
}
void func_0c145320(struct Actor *a,struct Actor *owner)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>owner->f41c+171.42856f)){a->b6++;a->f108=-0.80357140303f;func_0c02a0c4(a,23,30);return;}
 func_0c037d0c(a);
}
void func_0c1453a6(struct Actor *a,struct Actor *owner)
{
 struct ActorSubByteState *sub;
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>owner->f41c)){a->b6++;a->f56=owner->f41c;func_0c02a0c4(a,23,31);sub=(struct ActorSubByteState *)&owner->sub2a4;if(sub->b5)sub->b5--;}
}
