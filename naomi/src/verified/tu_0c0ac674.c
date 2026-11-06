#include "objects.h"
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c048ce6(struct Actor *),func_0c025900(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int);
void func_0c0ac674(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=-53.3333321f;position.y=171.42856f;func_0c1d4610(a,&position);
 a->b1a0=10;func_0c048ce6(a);
 func_0c025900(a,13,6);
 a->b1f9=2;
 func_0c02a0c4(a,15,0);
}
void func_0c0ac6c0(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(a->b34&2){a->b1d2^=1;a->w130=a->b1d2;}
 position.x=-53.3333321f;position.y=171.42856f;func_0c1d4610(a,&position);
 a->b1a0=10;func_0c048ce6(a);
 func_0c025900(a,13,7);
 func_0c02a0c4(a,15,5);
 func_0c0344a0(a,4);
}
void func_0c0ac72a(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=-53.3333321f;position.y=171.42856f;func_0c1d4610(a,&position);
 a->b1a0=10;func_0c048ce6(a);
 func_0c025900(a,13,6);
 a->b1f9=2;
 func_0c02a0c4(a,15,3);
 func_0c0344a0(a,3);
}
void func_0c0ac77e(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=-53.3333321f;position.y=171.42856f;func_0c1d4610(a,&position);
 a->b1a0=10;func_0c048ce6(a);
 func_0c025900(a,5,5);
}
