#include "objects.h"
extern short dat_0c2f6830;
extern struct LinkedActor *func_0c0374da(struct LinkedActor *,int,int);
extern void (*table_0c257f88[])(struct LinkedActor *,struct LinkedActor *);
extern short *table_0c257f80[];
extern int func_0c1952ae(struct Actor *);
extern int func_0c195208(struct Actor *,struct Actor *);
extern struct Dat_13bb5c dat_0c2f8338;
extern void func_0c037688(struct Actor *);
extern void func_0c044788(struct Actor *,struct Actor *);
extern void func_0c03edcc(struct Actor *,struct Actor *);
extern void func_0c02a18c(struct Actor *,int,int,int);
extern unsigned char table_0c257e50[];
extern short table_0c257d30[][4];
extern short table_0c257e30[][2];
void func_0c196142(struct LinkedActor *a);
void func_0c1962a8(struct Actor *a,struct Actor *owner);
void func_0c196360(struct Actor *a,struct Actor *owner);
void func_0c1963e4(struct Actor *a,struct Actor *owner);
int func_0c1960d0(struct LinkedActor *owner,int count,int kind)
{
 struct LinkedActor *a;int i;
 if(dat_0c2f6830<=count)return 0;if(count>12)count=12;
 for(i=0;i<count;i++)if((a=func_0c0374da(0,3,1))!=0){a->w38=0xc05;a->b35=i;a->b32=kind;a->s30=count;a->p16=func_0c196142;a->p24=owner;}
 return i;
}
void func_0c196142(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 struct ActorActionResult56 *context=(struct ActorActionResult56 *)&((struct Actor *)owner)->sub2a4;
 if(a->b35)return;
 if(((struct Actor *)owner)->b1e9!=6||owner->b5||((struct Actor *)owner)->b1d0!=29||context->result==-1)a->b4=2;
 table_0c257f88[a->b4](a,owner);
}
void func_0c19618e(struct Actor *a,struct Actor *owner)
{
 struct MotionContext8a3 *context=(struct MotionContext8a3 *)&owner->sub2a4;
 func_0c1962a8(a,owner);a->b4++;
 a->f52=owner->f52+context->vx;a->f56=owner->f56+context->vy;
 a->p1b0=(struct Actor *)table_0c257f80[((struct LinkedActor *)a)->b32];
 func_0c1952ae(a);func_0c1963e4(a,owner);func_0c196360(a,owner);
}
void func_0c19620c(struct Actor *a,struct Actor *owner)
{
 struct ActorActionResult56 *context=(struct ActorActionResult56 *)&owner->sub2a4;int r;
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 func_0c195208(a,owner);func_0c1963e4(a,owner);func_0c196360(a,owner);
 r=context->result;if(r==2||r==-1)a->b4=2;
}
void func_0c19626c(struct Actor *a,struct Actor *owner)
{int i,count=a->s30;struct Actor *child;for(i=1;i<count;i++){child=a->p12;child->b12c=0;func_0c037688(child);}func_0c037688(a);}
void func_0c1962a8(struct Actor *a,struct Actor *owner)
{
 int i,count=a->s30;struct Actor *last;
 for(i=0;i<count;i++){
 last=a;
 ((struct LinkedActor *)a)->sdc=((struct LinkedActor *)owner)->sdc;a->b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->f80=owner->f80;a->f84=owner->f84;a->b1a3=owner->b1a3;a->pad7cc[0]=owner->pad7cc[0];
 ((struct LinkedActor *)a)->b48=((struct LinkedActor *)owner)->b48;((struct LinkedActor *)a)->v80=((struct LinkedActor *)owner)->v80;
 a->b36=owner->b36;a->b36=7;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;a=a->p12;
 }
 func_0c044788(owner,last);last->b15a=-1;
}
void func_0c196360(struct Actor *a,struct Actor *owner)
{
 int i,count=a->s30;unsigned int bank;
 for(i=0;i<count-1;i++){
  bank=(unsigned int)table_0c257e50[((struct LinkedActor *)a)->b35]+16;
  func_0c02a18c(a,23,bank,a->b34);a=a->p12;
 }
 func_0c02a18c(a,15,10,((a->b34+2)&31)>>2);
 func_0c03edcc(a,a->p1c8);
}
void func_0c1963e4(struct Actor *a,struct Actor *owner)
{
 struct MotionContext8a3 *context;
 struct Actor *child;short *row;int i,count;float nx,ny,dx,dy;
 row=(short *)table_0c257d30+(unsigned int)(a->b34*4+2);nx=*row++*1.66666663f;context=(struct MotionContext8a3 *)&owner->sub2a4;ny=*row*2.1428571f;
 if((short)a->w130)nx=-nx;
 a->f52=owner->f52+context->vx-nx;a->f56=owner->f56+context->vy-ny;
 count=a->s30;
 for(i=1;i<count-1;i++){
 child=a->p12;
 row=table_0c257d30[a->b34];dx=*row++*1.66666663f;dy=*row*2.1428571f;
 row=(short *)table_0c257d30+(unsigned int)(child->b34*4+2);nx=*row++*1.66666663f;ny=*row*2.1428571f;
 if((short)a->w130){dx=-dx;nx=-nx;}
 child->f52=a->f52+dx-nx;child->f56=a->f56+dy-ny;a=child;
 }
 child=a->p12;
 row=table_0c257d30[a->b34];dx=*row++*1.66666663f;dy=*row*2.1428571f;
 row=(unsigned int)((((child->b34+2)&31)>>2)*2)+(short *)table_0c257e30;nx=*row++*1.66666663f;ny=*row*2.1428571f;
 if((short)a->w130){dx=-dx;nx=-nx;}
 child->f52=a->f52+dx-nx;child->f56=a->f56+dy-ny;
}
