/* Candidate (1023/1032): pools, extent and control flow match. The only difference left in
 * func_0c15d23c is the hoisted constants 0/3 (retail r12=0, r13=3; ours swapped). */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct LaunchRow16 table_0c250ddc[];
extern void (*table_0c250e0c[])(struct LinkedActor *);
extern void (*table_0c250e1c[])(struct LinkedActor *,struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *),func_0c0344a0(struct LinkedActor *,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
void func_0c15d038(struct LinkedActor *),func_0c15d210(struct LinkedActor *);
struct LinkedActor *func_0c15cff0(struct Actor *owner,unsigned char mode)
{
 struct LinkedActor *a;
 struct ActorSub2a4 *sub=&owner->sub2a4;
 if((a=func_0c0374da(0,1,0))!=0){
  a->p16=func_0c15d038;a->p24=(struct LinkedActor *)owner;a->b32=mode;
  a->wcc.dword_value=sub->b2;
 }
 return a;
}
void func_0c15d038(struct LinkedActor *a){table_0c250e0c[a->b4](a);}
void func_0c15d04a(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 struct LaunchRow16 *row;
 float scale,unit;
 a->b4++;a->w38=0x1c01;a->s28=-1;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->b36=8;a->sdc.b12c=1;
 A(a)->b13c=16;((unsigned char *)a)[0x13d]=16;A(a)->b13e=16;A(a)->b13f=16;
 if(owner->b1==29){((struct LinkedActorPrefix12c *)&a->sdc.b12c)->b12d=1;((struct LinkedActorPrefix12c *)&a->sdc.b12c)->w12e+=-2;}
 row=&table_0c250ddc[a->b32];
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
 func_0c0344a0(owner,38);
 func_0c15d210(a);
}
void func_0c15d210(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if(A(a)->b1a0){A(a)->b1a0--;return;}
 table_0c250e1c[(unsigned char)a->b5](a,owner);
}
void func_0c15d23c(struct LinkedActor *a)
{
 struct LaunchRow16 *rows;
 char n;
 if(!func_0c028642(a)){a->b4=3;a->sdc.b12c=0;return;}
 rows=table_0c250ddc;
 if(A(a)->b19e){
  if(--A(a)->i204==0)goto advance;
  goto set; set: n=rows[a->b32].flag;
  if(a->s28++&3)n++;
  goto flag;
 }
 if(A(a)->b19f){
  unsigned char *hit=A(a)->p1bc;
  if(!hit||!(hit[2]&32)){
   if(--A(a)->i204!=0)goto refresh;
  }
  else if((A(a)->i204=A(a)->i204-3)>0)goto refresh;
 advance:
  a->b5++;func_0c02a0c4(a,23,3);return;
 refresh:
  n=rows[a->b32].flag;
  if(a->s28++&3)n++;
 flag:
  A(a)->b1a1=n;A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;
  dat_0c2f83f8->arr[a->b2]++;
 }
 a->f52+=a->f92;a->f92+=a->f104;
 a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 func_0c037d0c(a);
}
void func_0c15d3a4(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0){a->b4++;a->sdc.b12c=0;}
}
void func_0c15d3c6(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c15d3d4(struct LinkedActor *a){func_0c037688(a);}
