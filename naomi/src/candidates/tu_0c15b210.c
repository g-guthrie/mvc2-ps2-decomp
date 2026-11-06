/* Candidate (1007/1024): pools, extent and control flow match. Differences: at
 * 0c15b2ae retail stores the 0x13c long before setting up the 0x34 vector copy
 * (ours hoists mov r14,r1 first); 0c15b31c loads dat_0c2d6f84 into r2 (ours r3). */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
#define SRC(a) ((struct LinkedActor *)A(a)->p8)
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct ActorFlags *dat_0c2d6f84;
extern void (*table_0c250ba8[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c02a18c(struct LinkedActor *,int,int,int);
extern void func_0c037d0c(struct LinkedActor *),func_0c0344a0(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *);
extern unsigned char func_0c028642(struct LinkedActor *);
void func_0c15b3cc(struct LinkedActor *);
void func_0c15b210(struct LinkedActor *a)
{
 struct LinkedActor *target;
 float dx;
 a->b4++;target=a->p24;a->sdc=SRC(a)->sdc;a->sdc.b12c=1;
 a->b2=SRC(a)->b2;a->b1=SRC(a)->b1;
 a->v80.x=SRC(a)->v80.x;a->v80.y=SRC(a)->v80.y;
 a->b1a3=SRC(a)->b1a3;a->b1a4=SRC(a)->b1a4;a->b48=SRC(a)->b48;a->v80=SRC(a)->v80;
 a->b36=SRC(a)->b36;
 A(a)->b19c=66;A(a)->b19d=66;A(a)->b1a1=54;
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 *(int *)&A(a)->b13c=0x302828f0;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&SRC(a)->f52;
 dx=a->v80.x*373.333313f;
 if(!A(a)->w130)dx=-dx;
 a->f52+=dx;
 a->b36=0;a->f96=0.0f;a->f108=0.0f;
 a->f92=-20.0f;a->f104=-0.41666666f;
 if(A(a)->w130){a->f92=-a->f92;a->f104=-a->f104;}
 if(!A(target)->b1e9){
  switch(dat_0c2d6f84->flags&3){
  case 0:a->f96=2.1428571f;break;
  case 1:a->f96=-2.1428571f;break;
  }
 }
 A(a)->f100=(target->v80.x*1.20000005f-a->v80.x)/30.0f;
 A(a)->f112=(target->v80.y*1.20000005f-a->v80.y)/30.0f;
 a->s28=5;a->s30=120;
 a->wcc.float_value=a->f52;
 a->b34=1;a->sdc.b12c=1;
 func_0c02a18c(a,23,11,0);
 func_0c15b3cc(a);
 func_0c0344a0(a,27);
}
void func_0c15b3cc(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 float scale;
 a->f52+=a->f92;a->f92+=a->f104;
 a->f56+=a->f96;a->f96+=a->f108;
 if(!a->b34){
  short n=(a->wcc.float_value-a->f52)/a->v80.x/1.66666663f;
  if(n<0)n=-n;
  if(n>=0xe0){a->b34=1;func_0c02a0c4(a,23,11);}
  else{short frame=(n&0xe0)>>5;func_0c02a18c(a,23,13,frame);}
 }
 a->sdc.b12c=func_0c028642(a);
 scale=1.20000005f;
 switch(a->b7){
 case 0:
  func_0c02a026(a);
  if(owner->v80.x*scale>a->v80.x)a->v80.x+=A(a)->f100;
  if(owner->v80.y*scale>a->v80.y)a->v80.y+=A(a)->f112;
  if(--a->s30>0){
   goto s3; s3: if(!A(a)->b19e)goto tail;
   if(--a->s28>0)goto next;
  }
  a->b7=2;func_0c02a0c4(a,23,12);return;
 next:
  a->b7++;goto tail;
 case 1:
  func_0c02a026(a);
  if(owner->v80.x*scale>a->v80.x)a->v80.x+=A(a)->f100;
  if(owner->v80.y*scale>a->v80.y)a->v80.y+=A(a)->f112;
  if(--*(signed char *)&A(a)->b1a0>0)return;
  a->b7--;
  A(a)->b1a1=54;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;
 tail:
  func_0c037d0c(a);
  return;
 case 2:
  if(func_0c02a026(a)<0){a->b4++;a->sdc.b12c=0;}
  return;
 }
}
void func_0c15b5e4(struct LinkedActor *a){table_0c250ba8[a->b4](a);}
