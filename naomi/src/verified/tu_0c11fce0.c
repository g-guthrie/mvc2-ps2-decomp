#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Actor *func_0c1bc460(struct Actor *,int);
extern void func_0c0432ca(struct Actor *),func_0c0442fa(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c11fce0(struct Actor *a)
{
 int zero;struct Actor *other;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 zero=0;a->b6++;a->b1f9=zero;func_0c0432ca(a);func_0c0442fa(a);
 a->b1a1=61;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,9);
 if((other=func_0c1bc460(a,4)))other->b34=zero;
 if((other=func_0c1bc460(a,4)))other->b34=16;
}
void func_0c11fd72(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141){int zero=0;a->b3f0=zero;a->b3f1=zero;a->b6++;a->b141=zero;a->s28=180;func_0c0344a0(a,21);
  position.x=40.0f;position.y=342.85712f;func_0c0429a4(a,&position,1);}
}
