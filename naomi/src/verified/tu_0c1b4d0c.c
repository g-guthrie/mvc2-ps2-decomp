#include "objects.h"
#define A(a) ((struct Actor *)(a))
#define V(p) (*(struct LinkedActorVec3 *)&(p)->f52)
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25b0c0[])(struct LinkedActor *);
extern short table_0c25b0a4[];
extern int table_0c25b0b0[];
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c1b4d46(struct LinkedActor *);
struct LinkedActor *func_0c1b4d0c(struct LinkedActor *source,struct LinkedActor *owner,int mode)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,1))!=0){a->w38=0x2b00;a->b32=mode;a->p16=func_0c1b4d46;a->p20=source;a->p24=owner;}
 return a;
}
void func_0c1b4d46(struct LinkedActor *a){table_0c25b0c0[a->b4](a);}
void func_0c1b4d58(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p20;
 int *speed;
 int dx,dy,i;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->b36=0;
 a->sdc.w130=owner->sdc.w130;A(a)->b13c=16;A(a)->b13d=16;A(a)->b13e=16;A(a)->b13f=16;
 V(a)=V(owner);
 i=a->b32*2;dx=*(table_0c25b0a4+i);dy=*(table_0c25b0a4+i+1);
 speed=table_0c25b0b0;
 a->f92=(float)*speed++*1.66666663f/65536.0f;
 a->f104=(float)*speed++*1.66666663f/65536.0f;
 a->f96=(float)*speed++*2.1428571f/65536.0f;
 a->f108=(float)*speed*2.1428571f/65536.0f;
 if(a->sdc.w130){dx=-dx;a->f92=-a->f92;a->f104=-a->f104;}
 a->f52+=dx*1.66666663f;
 a->f56+=dy*2.1428571f;
 func_0c02a0c4(a,23,10);
}
