#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c1b2e44(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern float dat_0c249ef4[][2],dat_0c2d926c;
void func_0c0ee498(struct Actor *a,struct ActorSub2a4 *context)
{
 int one=1;
 if(((unsigned char *)&a->w150)[1])((struct ActorSubByteState *)context)->b4=one;
 if(a->b141){a->b141=0;((struct ActorSubByteState *)context)->b4=one;}
 if(func_0c02a026(a)<0){a->b6++;a->s28=20;((struct ActorSubByteState *)context)->b4=one;a->b12c=0;a->b1f5=one;func_0c0344a0(a,27);func_0c1b2e44(a);}
}
void func_0c0ee510(struct Actor *a)
{
 int zero=0;
 a->b12c=zero;a->b1f5=1;
 if(--a->s28<0){
  a->b6++;a->b12c=1;
  a->f52=dat_0c2d926c+dat_0c249ef4[a->b7][0]+-320.0f;
  a->f56=a->p20c->f56+dat_0c249ef4[a->b7][1];
  if(a->f56>a->f41c){a->b1f9=2;a->b1d4=zero;a->pad7f2=zero;a->b1d6=17;a->pad1d7[2]=zero;}else a->b1f9=zero;
  func_0c0344a0(a,28);
  a->b1d2=a->w130=(a->b7&1)?0:1;func_0c02a0c4(a,21,6);
 }
}
