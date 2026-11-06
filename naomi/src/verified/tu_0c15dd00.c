#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern struct FollowOffset15e2 dat_0c250e80[];
extern void (*table_0c250eac[])(struct LinkedActor *);
extern void (*table_0c250ebc[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c250ed8[])(struct Actor *);
extern struct { float f0,f4,f8,f12; } dat_0c250ee8[];
extern short dat_0c250f08[];
extern short dat_0c250f0a[];
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c0346da(struct Actor *,int),func_0c037d0c(struct Actor *);
extern char func_0c02a026(struct Actor *);
void func_0c15de18(struct LinkedActor *);
void func_0c15dd6a(struct LinkedActor *),func_0c15dffc(struct Actor *,struct Actor *);
struct LinkedActor *func_0c15dd00(struct LinkedActor *owner)
{struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c15dd6a;a->p24=owner;a->b32=0;{struct ActorSub2a4 *s=&A(owner)->sub2a4;s->b6=255;}}return a;}
struct LinkedActor *func_0c15dd36(struct LinkedActor *owner,unsigned char mode)
{struct LinkedActor *a;if((a=func_0c0374da((int)owner,1,2))){a->p16=func_0c15dd6a;a->p24=owner;a->b32=mode;}return a;}
void func_0c15dd6a(struct LinkedActor *a){table_0c250eac[a->b4](a);}
void func_0c15dd7c(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 struct FollowOffset15e2 *row;
 a->b4++;a->w38=0x1c03;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=1;
 row=&dat_0c250e80[a->b32];
 func_0c02a0c4(a,((char *)row)[4],((char *)row)[5]);
 a->b36=11;a->b49=*(char *)row;
 func_0c15de18(a);
}
void func_0c15de18(struct LinkedActor *a){table_0c250ebc[a->b32](a,a->p24);}
void func_0c15de2e(struct Actor *a,struct Actor *owner)
{
 int lim=2;int zero=0;
 if(owner->b4>=lim||a->b1!=owner->b1){a->b4++;a->b12c=zero;return;}
 if(owner->b5>=lim){struct ActorSub2a4 *s;a->b4++;a->b12c=zero;s=&owner->sub2a4;s->b6=zero;return;}
 table_0c250ed8[a->b5](a);
}
void func_0c15deb8(struct Actor *a,struct Actor *owner)
{
 struct { float x,y; } v;
 a->b5++;
 *(int *)&a->pad5ba[4]=0;
 if(owner->b1==28){v.x=-53.3333321f;v.y=94.2857132f;}else{v.x=-53.3333321f;v.y=81.42857f;}
 if(!owner->b1d2){
  a->f52=owner->f52+v.x;
  a->f92=dat_0c250ee8[(unsigned char)owner->b1a3].f0;
  a->f104=dat_0c250ee8[(unsigned char)owner->b1a3].f4;
 }else{
  a->f52=owner->f52-v.x;
  a->f92=-dat_0c250ee8[(unsigned char)owner->b1a3].f0;
  a->f104=-dat_0c250ee8[(unsigned char)owner->b1a3].f4;
 }
 a->f56=owner->f56+v.y;
 a->f96=dat_0c250ee8[(unsigned char)owner->b1a3].f8;
 a->f108=dat_0c250ee8[(unsigned char)owner->b1a3].f12;
 a->i204=dat_0c250f08[0];
 *(int *)&a->pad5ba[0]=1;
 a->b19c=66;a->b19d=66;a->b1a1=58;
 a->w1ac=0;a->b19e=0;a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c15dffc(a,owner);
}
void func_0c15dffc(struct Actor *a,struct Actor *owner)
{
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 if(!*(int *)&a->pad5ba[4]){
  if(a->f92<0.0f){if(a->f52<=dat_0c2d9260.f88+53.3333321f)goto bounce;}
  else if(a->f52>=dat_0c2d9260.f8c-53.3333321f)goto bounce;
  goto ground;
 bounce:
  *(int *)&a->pad5ba[4]=255;a->f92=0.0f;a->f104=0.0f;
 }
 ground:
 if(a->f56<=owner->f41c){a->b5=a->b5+1;a->f56=owner->f41c;a->s28=dat_0c250f0a[0];a->b36=15;func_0c02a0c4(a,23,5);func_0c0346da(a,75);}
 func_0c02a026(a);func_0c037d0c(a);
}
