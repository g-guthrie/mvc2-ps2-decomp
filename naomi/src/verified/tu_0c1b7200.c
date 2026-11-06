/* 0x0c1b7200 group: owner follower, dispatcher and update; matches retail
 * exactly. The b141 test is read as a raw byte, which keeps it in r2. */
#include "objects.h"
#define A(x) ((struct Actor *)(x))
extern void (*table_0c25b530[])(struct LinkedActor *);
extern short dat_0c25b46c[];
extern char dat_0c25b48c[];
extern float dat_0c25b49c[];
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c1b7200(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(owner->b5||owner->b1d0!=29){a->b4=2;a->sdc.b12c=0;return;}
 if(func_0c02a026(a)<0){a->b4=2;a->sdc.b12c=0;return;}
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 if(((char *)a)[0x141]){
  float f=-13.33333302f;
  if(a->sdc.w130)f=13.33333302f;
  a->f52+=f;
 }
}


void func_0c1b7268(struct LinkedActor *a){table_0c25b530[a->b4](a);}
void func_0c1b727a(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;
 a->f52=owner->f52;
 a->f56=owner->f56+dat_0c25b46c[(unsigned char)a->b33]*2.1428571f;
 func_0c02a0c4(a,23,dat_0c25b48c[(unsigned char)a->b33]+10);
 a->b36=dat_0c25b49c[A(a)->b141>>1];
}
