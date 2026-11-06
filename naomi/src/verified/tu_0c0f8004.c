#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c1ce916(struct LinkedActorVec3 *,int,int,int),func_0c034946(struct Actor *,int),func_0c042018(struct Actor *),func_0c044f1c(struct Actor *),func_0c0438de(struct Actor *),func_0c03edcc(struct Actor *,struct Actor *);
extern void (*table_0c24a610[])(struct Actor *);
void func_0c0f8004(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);
 if(a->b141){
  a->b141=0;a->b6++;position.y=a->f56+171.42856f;
  position.x=a->b1d2?53.3333321f:-53.3333321f;position.x+=a->f52;
  func_0c1ce916(&position,(short)a->w130,1,0);func_0c034946(a->p1c8,0);
  a->p1c8->p1b4=a;a->p1c8->b1f6=1;a->p1c8->b1a1=34;
  a->f96=23.57143f;a->f108=-0.9375f;a->f92=a->b1d2?-4.16666651f:4.16666651f;
 }
}
void func_0c0f80ae(struct Actor *a)
{
 func_0c042018(a);
 if(func_0c044e52(a))func_0c044f1c(a);
 else if(func_0c02a026(a)<0){a->b1d3=1;func_0c0438de(a);}
}
void func_0c0f80f0(struct Actor *a){table_0c24a610[a->b1f7&63](a);}
void func_0c0f8108(struct Actor *a){func_0c03edcc(a->p1c8,a);}
