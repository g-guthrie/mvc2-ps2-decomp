#include "objects.h"
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *,int,int),func_0c048ce6(struct Actor *),func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c24ae0c[])(struct Actor *);
struct Actor *func_0c0ff95c(struct Actor *a)
{
 struct Actor *result=0;
 if(!a->b1a3 || a->b1fe || !(a->w1fa&0x0c00))return 0;
 if(a->b1f9==2){
  if(a->f41c+106.666664124f>a->f56)return 0;
  if((result=func_0c037d54(a))!=0)a->b1f7=1;
 }else if(a->b1f9==0){if((result=func_0c037d54(a))!=0)a->b1f7=0;}
 return result;
}
void func_0c0ff9dc(struct Actor *a)
{
 func_0c025900(a,5,5);func_0c048ce6(a);table_0c24ae0c[a->b1f7&63](a);
}
void func_0c0ffa06(struct Actor *a)
{
 struct LinkedActorVec3 position;
 if(a->w1fa&0x0800){a->w130^=1;a->b1d2^=1;}
 position.x=-106.666664124f;position.y=235.71428f;func_0c1d4610(a,&position);
 a->b1a0=10;a->b6=0;a->b7=0;func_0c02a0c4(a,15,0);
}
