#include "objects.h"
extern void func_0c048ce6(struct Actor *);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c1a48d4(struct Actor *,int);
extern void func_0c025900(struct Actor *,char,char);
void func_0c0b2b28(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if (a->b34 & 1) {
  struct Actor *child;
  a->b1d2 = a->w130 = a->b1d2 ^ 1;
  child = a->p1c8;
  child->b1d2 = child->w130 = a->b1d2 ^ 1;
 }
 func_0c048ce6(a);
 a->b1a0=10;
 position.x=-61.666664124f; position.y=137.142853f; position.z=0;
 func_0c1d4610(a,&position);
 func_0c02a0c4(a,15,0);
 func_0c1a48d4(a,0);
}
void func_0c0b2ba8(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if (a->b34 & 1) {
  struct Actor *child;
  a->b1d2 = a->w130 = a->b1d2 ^ 1;
  child = a->p1c8;
  child->b1d2 = child->w130 = a->b1d2 ^ 1;
 }
 func_0c048ce6(a);
 a->b1a0=10;
 position.x=-60.0f; position.y=188.57143f; position.z=0;
 func_0c1d4610(a,&position);
 func_0c02a0c4(a,15,1);
 func_0c1a48d4(a,1);
}
void func_0c0b2c28(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c025900(a,6,6);
 func_0c048ce6(a);
 a->b1a0=10;
 position.x=0;position.y=0;position.z=0;
 func_0c1d4610(a,&position);
 func_0c02a0c4(a,15,2);
}
