/* Linked effect follow/collide handlers 0x0c145df4-0x0c145f34. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct BytePair_145df4 { unsigned char b0, b1; };
struct OwnerTarget_145df4 { struct Actor *target; char b4; };
extern struct BytePair_145df4 dat_0c24fb54[];
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);

void func_0c145df4(struct LinkedActor *a,struct LinkedActor *o)
{
 struct OwnerTarget_145df4 *sub=(struct OwnerTarget_145df4 *)&A(o)->sub2a4;
 struct Actor *t=sub->target;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;
 if(sub->b4&&t->b3==4&&t->w38==0x1003){
  if(a->sdc.w130==0&&a->f52<=t->f52||a->sdc.w130!=0&&a->f52>=t->f52){
   a->b5++;
   t->s30++;
   goto call;
  }
 }else if(func_0c028642(a)){
  a->b5++;
  call:
  func_0c02a0c4(a,23,dat_0c24fb54[a->b32].b1);
 }
 func_0c037d0c(a);
}

void func_0c145ea2(struct LinkedActor *a)
{
 if(a->s28<=210&&!func_0c028642(a)){a->b4++;a->sdc.b12c=0;return;}
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;
 func_0c037d0c(a);
}

void func_0c145efe(struct LinkedActor *a)
{
 a->b4++;
 a->sdc.b12c=0;
}

void func_0c145f0c(struct LinkedActor *a)
{
 func_0c037688(a);
}
