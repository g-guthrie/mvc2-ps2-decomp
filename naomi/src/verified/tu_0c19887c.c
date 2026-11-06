#include "objects.h"
extern struct ActorFlags*dat_0c2d6f84;
extern short dat_0c2f6830;
extern int func_0c02887e(float*,float*);
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c02a18c(struct Actor*,int,int,int);
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct Dat_13bb5c dat_0c2f8338;
extern short *table_0c258420[];
extern void func_0c037688(struct Actor*);
extern short table_0c258120[][4];
extern unsigned char table_0c258240[];
extern void (*table_0c25843c[])();
int func_0c19887c(struct LinkedActor *owner,int count,int kind);
void func_0c1988fa(struct LinkedActor *a);
void func_0c19891c(struct Actor *a,struct Actor *owner);
void func_0c19896c(struct Actor *a,struct Actor *owner);
void func_0c198a3e(struct Actor *a,struct Actor *owner);
void func_0c198a8c(struct Actor *a,struct Actor *owner);
void func_0c198b12(struct Actor *a,struct Actor *owner);
void func_0c198b36(struct Actor *a,struct Actor *owner);
void func_0c198bb4(struct Actor *a,struct Actor *owner);
void func_0c198c94(struct Actor *a,struct Actor *owner);
void func_0c198dac(struct Actor *a,struct Actor *owner);
int func_0c198f48(struct Actor *a,struct Actor *owner);
int func_0c198fea(struct Actor *a);

int func_0c19887c(struct LinkedActor *owner,int count,int kind)
{
 struct LinkedActor *a,*first;int i;
 if(dat_0c2f6830<=count)return 0;if(count>12)count=12;
 for(i=0;i<count;i++)if((a=func_0c0374da(0,3,1))!=0){a->w38=0xe05;a->b35=i;a->b32=kind;a->s30=count;a->p16=func_0c1988fa;a->p24=owner;if(!i)first=a;}
 first->p20=a;return i;
}

void func_0c1988fa(struct LinkedActor *a)
{struct LinkedActor *owner=a->p24;if(!a->b35)table_0c25843c[a->b4](a,owner);}

void func_0c19891c(struct Actor *a,struct Actor *owner)
{
 func_0c198a8c(a,owner);
 a->b4++;a->b5=0;
 a->p1b0=(struct Actor *)table_0c258420;
 func_0c198fea(a);
 func_0c198f48(a,owner);
 func_0c198bb4(a,owner);
 func_0c198b36(a,owner);
}

void func_0c19896c(struct Actor *a,struct Actor *owner)
{
 struct MotionContext19887c *context=(struct MotionContext19887c *)&owner->sub2a4;
 if(owner->b5||owner->b1d0!=26||(unsigned char)owner->b159!=20||(unsigned char)owner->b158!=3){a->b4=2;goto release;}
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 if(!a->b5){
  func_0c198dac(a,owner);func_0c198b36(a,owner);
  if(context->flag32==-1){a->b5++;a->b33=10;}
  return;
 }
 if(!--a->b33){a->b4=2;a->b12c=0;
release:
  func_0c198a3e(a,owner);return;}
 func_0c198b12(a,owner);func_0c198f48(a,owner);func_0c198c94(a,owner);func_0c198b36(a,owner);
}

void func_0c198a3e(struct Actor *a,struct Actor *owner)
{int i,count=a->s30;struct Actor *child;for(i=1;i<count;i++){child=a->p12;child->b12c=0;func_0c037688(child);}func_0c037688(a);}

void func_0c198a8c(struct Actor *a,struct Actor *owner)
{
 int i,count=a->s30;
 for(i=0;i<count;i++){
 ((struct LinkedActor *)a)->sdc=((struct LinkedActor *)owner)->sdc;a->b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->f80=owner->f80;a->f84=owner->f84;a->b1a3=owner->b1a3;a->pad7cc[0]=owner->pad7cc[0];
 ((struct LinkedActor *)a)->b48=((struct LinkedActor *)owner)->b48;((struct LinkedActor *)a)->v80=((struct LinkedActor *)owner)->v80;
 a->b36=owner->b36;a->b36=owner->b36;((struct LinkedActor *)a)->b49=8;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;a=a->p12;
 }
}

void func_0c198b12(struct Actor *a,struct Actor *owner)
{int i,count=a->s30;for(i=0;i<count;i++){a->b12c=dat_0c2d6f84->flags&1;a=a->p12;}}

void func_0c198b36(struct Actor *a,struct Actor *owner)
{
 int i,count=a->s30;unsigned int bank;
 for(i=0;i<count-1;i++){
 bank=(unsigned int)table_0c258240[a->b35]+85;func_0c02a18c(a,23,bank,a->b34);a=a->p12;
 }
 func_0c02a0c4(a,23,43);
}

void func_0c198bb4(struct Actor *a,struct Actor *owner)
{
 struct MotionContext19887c *context=(struct MotionContext19887c *)&owner->sub2a4;
 struct Actor *child;short *row;int i,count;float nx,ny,dx,dy;
 row=(short *)table_0c258120+(unsigned int)(a->b34*4+2);nx=*row++*1.66666663f;ny=*row*2.1428571f;
 if((short)a->w130)nx=-nx;
 a->f52=owner->f52+context->vx-nx;a->f56=owner->f56+context->vy-ny;
 count=a->s30;
 for(i=1;i<count;i++){
 child=a->p12;
 row=table_0c258120[a->b34];dx=*row++*1.66666663f;dy=*row*2.1428571f;
 row=(short *)table_0c258120+(unsigned int)(child->b34*4+2);nx=*row++*1.66666663f;ny=*row*2.1428571f;
 if((short)a->w130){dx=-dx;nx=-nx;}
 child->f52=a->f52+dx-nx;child->f56=a->f56+dy-ny;a=child;
 }
}

void func_0c198c94(struct Actor *a,struct Actor *owner)
{
 struct MotionContext19887c *context=(struct MotionContext19887c *)&owner->sub2a4;
 struct Actor *child;short *row;int i,count;float dx,dy,nx,ny,bias=0,height;
 a=a->p20;height=-4.28571415f;child=a->p8;row=table_0c258120[child->b34];dx=*row++*1.66666663f;dy=*row*2.1428571f;
 if((short)a->w130){dx=-dx;bias=-0.0f;}
 child->f52=a->f52+bias-dx;child->f56=a->f56+height-dy;count=a->s30;
 for(i=1;i<count-1;i++){
 a=child;child=a->p8;
 row=(short *)table_0c258120+(unsigned int)(a->b34*4+2);nx=*row++*1.66666663f;ny=*row*2.1428571f;
 row=table_0c258120[child->b34];dx=*row++*1.66666663f;dy=*row*2.1428571f;
 if((short)a->w130){nx=-nx;dx=-dx;}
 child->f52=a->f52+nx-dx;child->f56=a->f56+ny-dy;
 }
 if(!context->flag32){owner->f52=child->f52-context->vx;owner->f56=child->f56-context->vy;}
}

void func_0c198dac(struct Actor *a,struct Actor *owner)
{
 struct LinkedActorVec3 point;struct MotionContext19887c *context=(struct MotionContext19887c *)&owner->sub2a4;
 struct Actor *child;short *row;int angle,i,count;float dx,dy,nx,ny;
 a=a->p20;point.x=owner->f52+context->vx;point.y=owner->f56+context->vy;
 angle=func_0c02887e(&point,(struct LinkedActorVec3 *)&a->f52);if(owner->b1d2)angle=-angle;
 a->b34=(unsigned char)(angle+4)>>3;count=a->s30;
 for(i=1;i<count;i++){
 child=a->p8;angle=func_0c02887e(&point,(struct LinkedActorVec3 *)&a->f52);if(owner->b1d2)angle=-angle;
 child->b34=(unsigned char)(angle+4)>>3;
 if(i==1){dx=0;dy=-4.28571415f;}else{row=(short *)table_0c258120+(unsigned int)(a->b34*4+2);dx=*row++*1.66666663f;dy=*row*2.1428571f;}
 row=table_0c258120[child->b34];nx=*row++*1.66666663f;ny=*row*2.1428571f;
 if((short)child->w130){dx=-dx;nx=-nx;}
 child->f52=a->f52+dx-nx;child->f56=a->f56+dy-ny;a=child;
 }
 row=(short *)table_0c258120+(unsigned int)(a->b34*4+2);dx=*row++*1.66666663f;dy=*row*2.1428571f;
 if((short)a->w130)dx=-dx;
 owner->f52=a->f52+dx-context->vx;owner->f56=a->f56+dy-context->vy;owner->b34=a->b34;
}

int func_0c198f48(struct Actor *a,struct Actor *owner)
{
 int result=1,i,count;struct Actor *child;
 a->b34=owner->b34;
 if(a->s28){
  a->s28--;
  count=a->s30;
  for(i=1;i<count;i++){
   child=a->p12;
   child->f96+=child->f100;
   child->f108=a->f108+child->f96;
   if(child->f108<0.0f)child->f108+=256.0f;
   if(!(256.0f>child->f108))child->f108-=256.0f;
   child->b34=(((unsigned char)(int)child->f108+4)>>3)+owner->b34&31;
   a=child;
  }
 }
 else result=func_0c198fea(a);
 return result;
}

int func_0c198fea(struct Actor *a)
{
 short **list=(short **)a->p1b0,*frame;int more=1,i,count;struct Actor *child;
 frame=*list++;
 if(!frame){list-=2;frame=*list++;more=0;}
 a->p1b0=(struct Actor *)list;
 a->f108=a->f104;
 a->f104=*frame++;
 a->f112=(a->f104-a->f108)*frame[0];
 if(a->f112<0.0f)a->f112+=256.0f;
 a->f112*=*frame++;
 a->f112/=12;
 a->s28=*frame;
 a->f108=0.0f;
 count=a->s30;
 for(i=1;i<count;i++){
  child=a->p12;
  child->f108=a->f108+child->f96;
  child->f112=a->f112;
  child->s28=a->s28;
  child->f100=a->f112/a->s28;
  if(child->f108<0.0f)child->f108+=256.0f;
  if(!(256.0f>child->f108))child->f108-=256.0f;
  a=child;
 }
 return more;
}
