#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c02a18c(struct Actor *,int,int,int);

void func_0c0fecb0(struct Actor *a)
{
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b7++;a->b1f9=0;a->f56=a->f41c;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1a1=59;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,22,11);
}

void func_0c0fed30(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;
 func_0c02a026(a);
 if(a->b141){
  a->b3f0=0;a->b3f1=0;
  a->b7++;a->b141=0;
  position.x=0.0f;position.y=205.71428f;
  func_0c0429a4(a,&position,1);
 }
}

void func_0c0fed98(struct Actor *a)
{
 a->b3f8=2;a->b328=5;a->b7++;
 func_0c02a18c(a,22,11,7);
}

void func_0c0fedb4(struct Actor *a)
{
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)<0){a->b6++;a->b7=0;func_0c02a0c4(a,22,12);}
}
