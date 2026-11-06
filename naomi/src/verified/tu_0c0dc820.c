#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
#define PHASE(a) (((struct ActorSubByteState *)&(a)->sub2a4.s14)->b0)
#define COUNTER(a) (((struct ActorSubByteState *)&(a)->sub2a4.s14)->b1)
void func_0c0dc820(struct Actor *a)
{
 register float low_jump;float gravity;
 func_0c02a026(a);gravity=-0.80357140303f;
 if(a->b19e&1){
  a->b6++;PHASE(a)=2;COUNTER(a)=0;
  if(a->b1d2)a->f92=-3.3333333f;else a->f92=3.3333333f;
  a->f104=0;a->f96=8.5714283f;if(a->b1a3)a->f96=17.142857f;
  a->f108=gravity;func_0c02a0c4(a,21,4);
 }else{
  low_jump=2.1428571f;
  if(a->b19e){a->b6=5;PHASE(a)=1;COUNTER(a)=0;a->f96=low_jump;func_0c02a0c4(a,21,a->b1a3+32);}
  else{
   a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
   if(a->s28--==0){a->b6=6;PHASE(a)=2;COUNTER(a)=0;if(a->b1d2)a->f104=-0.20833333f;else a->f104=0.20833333f;a->f96=low_jump;a->f108=gravity;func_0c02a0c4(a,21,31);}
  }
 }
}
