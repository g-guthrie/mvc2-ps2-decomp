/* Three positioning callbacks and one dispatcher. */
#include "objects.h"
extern void func_0c048ce6(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void (*dat_0c24c0a8[])(struct Actor *);
void func_0c112b44(struct Actor *a)
{
 struct LinkedActorVec3 position;
 float zero;
 if(a->b34&1){a->b1d2^=1;a->w130=(unsigned char)a->b1d2;}
 a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,0);
 position.x=-85.0f;position.y=53.57143f;zero=0.0f;position.z=zero;
 func_0c1d4610(a,&position);
 a->f92=zero;a->f96=zero;a->f104=zero;a->f108=zero;
}
void func_0c112bb6(struct Actor *a)
{
 struct LinkedActorVec3 position;
 float zero;
 if(a->b34&1){a->b1d2^=1;a->w130=(unsigned char)a->b1d2;}
 a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,5);
 position.x=-85.0f;position.y=53.57143f;zero=0.0f;position.z=zero;
 func_0c1d4610(a,&position);
 a->f92=zero;a->f96=zero;a->f104=zero;a->f108=zero;
}
void func_0c112c28(struct Actor *a)
{
 struct LinkedActorVec3 position;
 float zero;
 a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,6);
 position.x=-85.0f;position.y=53.57143f;zero=0.0f;position.z=zero;
 func_0c1d4610(a,&position);
 a->f92=zero;a->f96=zero;a->f104=zero;a->f108=zero;
}
void func_0c112c7e(struct Actor *a){dat_0c24c0a8[a->b1f7&63](a);}
