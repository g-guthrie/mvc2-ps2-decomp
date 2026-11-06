#include "objects.h"
extern signed char dat_0c25e810[][3];
extern struct ActorVec2 dat_0c25e7a8[];
extern struct ActorFlags *dat_0c2d6f84;
extern void func_0c02fc02(struct Actor *,int,float,float);
void func_0c1c76bc(struct Actor *a)
{
 signed char index=dat_0c25e810[a->b1][a->b33];
 float x=dat_0c25e7a8[index].x-dat_0c25e7a8[0].x;
 float y=dat_0c25e7a8[0].y-dat_0c25e7a8[index].y;
 if(dat_0c2d6f84->b41)func_0c02fc02(a,109,x,y);
 else func_0c02fc02(a,103,x,y);
}
