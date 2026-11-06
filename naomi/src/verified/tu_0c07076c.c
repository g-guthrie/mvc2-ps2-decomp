/* Four actor position/state handlers sharing one literal pool. */
#include "objects.h"
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c240ea4[])(struct Actor *);
extern void (*table_0c240ebc[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern short dat_0c240ecc[];
extern void func_0c03489c(struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c07098a(struct Actor *);

void func_0c07076c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=53.3333321f;position.y=171.42856f;
 func_0c1d4610(a,&position);a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,0);
}

void func_0c0707a8(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=-53.3333321f;position.y=171.42856f;
 func_0c1d4610(a,&position);a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,1);
}

void func_0c0707e4(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=-53.3333321f;position.y=171.42856f;
 func_0c1d4610(a,&position);a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,2);
}

void func_0c070820(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=-53.3333321f;position.y=171.42856f;
 func_0c1d4610(a,&position);a->b1a0=10;func_0c048ce6(a);func_0c02a0c4(a,15,3);
}

void func_0c07085c(struct Actor *a)
{
 struct LinkedActorVec3 position;
 position.x=-26.666666031f;position.y=102.85714f;
 func_0c1d4610(a,&position);a->b1a0=10;
 a->f92=0.0f;a->f104=0.0f;
 a->f96/=2.0f;
 a->f108=-0.80357140303f;
 func_0c048ce6(a);func_0c02a0c4(a,15,6);
}
