#include "objects.h"
extern int func_0c02850e(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *);
extern void (*table_0c25155c[])(struct Actor *,struct Actor *);
void func_0c161112(struct Actor *,struct Actor *);
void func_0c161094(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;if(!func_0c02850e(a)){a->b4++;a->b12c=0;}func_0c02a026(a);func_0c037d0c(a);
}
void func_0c1610de(struct Actor *a,struct Actor *owner){table_0c25155c[a->b5](a,owner);}
void func_0c1610f0(struct Actor *a,struct Actor *owner)
{
 a->b5++;((struct MeActor *)a)->blk_dc.b13c=24;((struct MeActor *)a)->blk_dc.b13d=24;((struct MeActor *)a)->blk_dc.b13e=16;((struct MeActor *)a)->blk_dc.b13f=16;a->f108=-1.07142854f;func_0c161112(a,owner);
}
void func_0c161112(struct Actor *a,struct Actor *owner)
{
 func_0c02a026(a);if(!a->b141){a->b5++;a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;}func_0c037d0c(a);
}
void func_0c16116c(struct Actor *a,struct Actor *owner)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>owner->f41c)){a->b5++;a->f56=owner->f41c;}func_0c02a026(a);func_0c037d0c(a);
}
