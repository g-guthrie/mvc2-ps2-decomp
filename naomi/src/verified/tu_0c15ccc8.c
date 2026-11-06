#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct LaunchRow16 table_0c250d74[];
extern void (*table_0c250dc4[])(struct LinkedActor *);
extern void (*table_0c250dd4[])(struct LinkedActor *,struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c0344a0(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
void func_0c15ccf6(struct LinkedActor *),func_0c15cec4(struct LinkedActor *);
struct LinkedActor *func_0c15ccc8(struct LinkedActor *owner,unsigned char mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c15ccf6;a->p24=owner;a->b32=mode;}return a;}
void func_0c15ccf6(struct LinkedActor *a){table_0c250dc4[a->b4](a);}
void func_0c15cd08(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 struct LaunchRow16 *row;
 float scale,unit;
 a->b4++;a->w38=0x1c00;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->b36=8;
 A(a)->b13c=16;((unsigned char *)a)[0x13d]=16;A(a)->b13e=16;A(a)->b13f=16;
 if(owner->b1==29){((struct LinkedActorPrefix12c *)&a->sdc.b12c)->b12d=1;((struct LinkedActorPrefix12c *)&a->sdc.b12c)->w12e+=-2;}
 row=&table_0c250d74[a->b32];
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 scale=1.66666663f;unit=65536.0f;
 if(!A(a)->w130){a->f52+=row->dx*scale;a->f92=row->vx*scale/unit;}
 else{a->f52+=-(row->dx*scale);a->f92=-(row->vx*scale/unit);}
 scale=2.1428571f;
 a->f56+=row->dy*scale;a->f96=row->vy*scale/unit;
 a->f104=0.0f;a->f108=0.0f;
 A(a)->b19c=66;A(a)->b19d=66;A(a)->b1a1=row->flag;
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,23,row->anim);
 func_0c0344a0(owner,37);
 func_0c15cec4(a);
}
void func_0c15cec4(struct LinkedActor *a){table_0c250dd4[(unsigned char)a->b5](a,a->p24);}
void func_0c15ced8(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(!func_0c028642(a)){a->b4=3;a->sdc.b12c=0;return;}
 if(A(a)->b19e||A(a)->b19f){a->b5++;func_0c02a0c4(a,23,owner->b1==28?1:3);return;}
 a->f52+=a->f92;a->f92+=a->f104;
 a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 func_0c037d0c(a);
}
