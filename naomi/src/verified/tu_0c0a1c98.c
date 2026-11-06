#include "objects.h"
extern void func_0c09e43a(struct Actor *),func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int),func_0c0346da(struct Actor *,int),func_0c04af58(struct Actor *,int),func_0c04c010(struct Actor *,struct Actor *,int),func_0c025900(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
void func_0c0a1c98(struct Actor *a)
{
 struct LinkedActorVec3 position;struct Actor *child;register float zero;float height;
 a->b1ea=1;a->b1ed=2;a->b1f5=2;func_0c09e43a(a);child=a->p1c8;height=171.42856f;zero=0.0f;
 if(a->s28==10){
  position.x=zero;position.y=height;func_0c1cea66(child,&position,10);func_0c0346da(a,6);func_0c04af58(child,-1);func_0c04c010(child,a,1);
 }
 if(a->s28==5){
  position.x=zero;position.y=height;func_0c1cea66(child,&position,16);func_0c0346da(a,6);func_0c04af58(child,-1);func_0c04c010(child,a,1);
 }
 if(a->s28--==0){
  a->b6++;func_0c025900(a,0,13);
  a->f92=a->b1d2?-20.0f:20.0f;a->f104=a->b1d2?0.8333333135f:-0.8333333135f;
  func_0c025900(a,0,0);a->b141=0;child->p1b4=a;child->b1f6=1;child->b1a1=36;
 }
 func_0c02a026(a);
}
