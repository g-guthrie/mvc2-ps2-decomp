#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *,int),func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int),func_0c19d2ac(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c09b87c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;func_0c02a026(a);
 if(a->b141){int zero=0;a->b7++;a->b141=zero;a->b3f0=zero;a->b3f1=zero;func_0c0344a0(a,24);
  position.x=43.3333321f;position.y=162.857132f;position.z=0.0f;func_0c0429a4(a,&position,1);}
}
void func_0c09b8f4(struct Actor *a)
{
 a->b3f8=2;a->b328=5;func_0c02a026(a);
 if(a->b141){int zero=0;a->b7++;a->s28=30;a->s30=9;a->b1a1=62;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
  dat_0c2f83f8->arr[a->b2]++;a->b34=1;a->f92=a->b1d2?11.666666031f:-11.666666031f;func_0c19d2ac(a,5,1);}
}
