#include "objects.h"
extern void func_0c048ce6(struct Actor *),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c02a0c4(struct Actor *,int,int);
void func_0c0e763c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c048ce6(a);
 position.x=-80.0f;position.y=184.28571f;position.z=0.0f;
 func_0c1d4610(a,&position);a->b1a0=10;
 a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;
 if(!(a->b34&1)){
  a->b1d2=a->w130=a->b1d2^1;
  a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;
 }
 func_0c02a0c4(a,15,0);
}
void func_0c0e76ca(struct Actor *a)
{
 struct LinkedActorVec3 position;
 float stopped;
 func_0c048ce6(a);
 a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;
 if(!(a->b34&1)){
  a->b1d2=a->w130=a->b1d2^1;
  a->p1c8->b1d2=a->p1c8->w130=a->b1d2^1;
 }
 a->f92=a->b1d2?-3.3333333f:3.3333333f;
 stopped=0.0f;a->f104=stopped;a->f96=-4.28571415f;a->f108=-0.80357140303f;
 position.x=-50.0f;position.y=158.57143f;position.z=stopped;
 func_0c1d4610(a,&position);a->b1a0=10;func_0c02a0c4(a,15,1);
}
