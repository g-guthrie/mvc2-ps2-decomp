/* Candidate: func_0c19933e register allocation of the flag/one value (r12 copy) and b36 load regs differ (260/324) */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
extern unsigned int func_0c02849a(void);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
void func_0c19933e(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c1992d0(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;a->sdc.b12c=0;a->b36=owner->b36;a->b49=-8;a->sdc.w130=0;
 func_0c19933e(a,owner);
}
void func_0c19933e(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(owner->b5==0&&owner->sdc.w158.bytes[1]==20&&(owner->sdc.w158.bytes[0]==2||owner->sdc.w158.bytes[0]==1)){
  int one;
  a->b36=owner->b36;a->b49=-8;
  *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
  one=1;
  if(A(owner)->b141&one){
   A(owner)->b141^=1;a->sdc.b12c=one;
   one=((func_0c02849a()&one)<<1)+A(owner)->b1d2;
   if(a->b32==2)one+=21;else one+=25;
   func_0c02a0c4(a,23,one);
  }
  if(!(A(owner)->b141&2))return;
 }
 a->b4=2;a->sdc.b12c=0;
}

void func_0c1993e8(struct LinkedActor *a){func_0c037688(a);}
