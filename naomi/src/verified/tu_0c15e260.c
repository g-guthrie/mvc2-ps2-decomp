/* Exact 0x0c15e260..0x0c15e32c: follow-offset handlers with one shared completion branch. */
#include "objects.h"
extern struct FollowOffset15e2 dat_0c250e80[];
extern void (*table_0c250f10[])(struct Actor *,struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c037688(struct Actor *);
void func_0c15e2a0(struct Actor *,struct Actor *);
void func_0c15e260(struct Actor *a,struct Actor *owner){table_0c250f10[a->b5](a,owner);}
void func_0c15e272(struct Actor *a,struct Actor *owner)
{
 struct FollowOffset15e2 *row;
 a->b5++;row=&dat_0c250e80[a->b32];a->f52=owner->f52;a->f56=owner->f56+row->y;
 func_0c15e2a0(a,owner);
}
void func_0c15e2a0(struct Actor *a,struct Actor *owner)
{
 if(owner->b4>=2){a->b5++;func_0c02a0c4(a,23,7);}
 func_0c02a026(a);
}
void func_0c15e2ca(struct Actor *a,struct Actor *owner)
{if(owner->b4>=2)goto finish;if(func_0c02a026(owner)>=0)return;finish:a->b4++;a->b12c=0;}
void func_0c15e302(struct Actor *a){a->b4++;a->b12c=0;}
void func_0c15e310(struct Actor *a){func_0c037688(a);}
