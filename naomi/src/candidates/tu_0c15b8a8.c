/* Candidate (311/356): retail func_0c15b924 keeps the owner+0x2a4 pointer in a
 * 4-byte stack slot (mov.l r4,@r15) but tests through r4; the `if(!&sub)` line is a
 * placeholder that forces the slot and is not the original spelling. Also differs in
 * load order at 0c15b8b8 and temp registers (r1/r4 vs r3). */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern void func_0c0498e6(struct LinkedActor *),func_0c03462c(struct LinkedActor *,int);
void func_0c15b924(struct LinkedActor *);
void func_0c15b8a8(struct LinkedActor *owner)
{
 struct LinkedActor *a=owner;owner=a->p24;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;
 a->sdc.b12c=0;A(a)->b19c=0;A(a)->b19d=69;
 func_0c02a0c4(a,23,15);
 func_0c15b924(a);
}
void func_0c15b924(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 struct ActorSub2a4 *sub;
 float dx;
 if(!A(owner)->b0)return;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 dx=owner->v80.x*32.0f;
 if(!A(owner)->w130)dx=-dx;
 a->f52+=dx;
 a->f56+=owner->v80.y*205.71428f;
 if(!A(owner)->b19d)return;
 if(A(a)->b19f){func_0c0498e6(a);func_0c03462c(a,15);}
 sub=&A(owner)->sub2a4;
 if(!sub->b0&&!sub->b1)return;
 if(!&sub)return;
 if(*(float *)((char *)owner+0x2a8)!=1.0f)return;
 func_0c037d0c(a);
}
void func_0c15b9c6(struct LinkedActor *a){a->b4++;}
void func_0c15b9ce(struct LinkedActor *a){func_0c037688(a);}
