/* Exact effects chain, 0x0c19592c..0x0c1960ce.
 * The mapped two-byte alignment pad at 0x0c1960ce is outside this section. */
#include "objects.h"
extern short dat_0c2f6830;
extern struct LinkedActor *func_0c0374da(struct LinkedActor *,int,int);
extern void (*table_0c257f58[])(struct LinkedActor *,struct LinkedActor *);
extern short *table_0c257f3c[];
extern int func_0c1952ae(struct Actor *);
extern int func_0c195208(struct Actor *,struct Actor *);
extern void func_0c195b80(struct Actor *,struct Actor *);
extern void func_0c195c12(struct Actor *,struct Actor *,int);
extern void func_0c195d28(struct Actor *,struct Actor *),func_0c195c98(struct Actor *,struct Actor *);
void func_0c1959aa(struct LinkedActor *);
int func_0c19592c(struct LinkedActor *owner,int count,int kind)
{
 struct LinkedActor *a,*first;int i;
 if(dat_0c2f6830<=count)return 0;if(count>12)count=12;
 for(i=0;i<count;i++)if((a=func_0c0374da(0,3,1))!=0){a->w38=0xc04;a->b35=i;a->b32=kind;a->s30=count;a->p16=func_0c1959aa;a->p24=owner;if(!i)first=a;}
 first->p20=a;return i;
}
void func_0c1959aa(struct LinkedActor *a)
{struct LinkedActor *owner=a->p24;if(!a->b35)table_0c257f58[a->b4](a,owner);}
void func_0c1959cc(struct Actor *a,struct Actor *owner)
{
 func_0c195b80(a,owner);a->b4++;a->p1b0=(struct Actor *)table_0c257f3c;
 func_0c1952ae(a);func_0c195208(a,owner);func_0c195c12(a,owner,0);func_0c195d28(a,owner);func_0c195c98(a,owner);
}

extern struct Dat_13bb5c dat_0c2f8338;
extern void func_0c037688(struct Actor *),func_0c195f30(struct Actor *,struct Actor *),func_0c195e18(struct Actor *,struct Actor *);
void func_0c195b44(struct Actor *,struct Actor *);
void func_0c195a2c(struct Actor *a,struct Actor *owner)
{
 struct ActorSubByteState *context=(struct ActorSubByteState *)&owner->sub2a4;
 if(owner->b5 || owner->b1d0!=21 || (unsigned char)owner->b159!=21){a->b4=2;func_0c195b44(a,owner);return;}
 if(dat_0c2f8338.w3c&(1<<dat_0c2f8338.b3b))return;
 switch(a->b5){
 case 0:func_0c195c12(a,owner,0);func_0c195d28(a,owner);func_0c195c98(a,owner);
 if(((struct ActorSubByteState *)context)->b5)a->b5++;break;
 case 1:func_0c195f30(a,owner);func_0c195c98(a,owner);
 if(((struct ActorSubByteState *)context)->b5!=1){a->b5++;a->b33=16;}break;
 case 2:if(--a->b33==0){a->b4=2;a->b12c=0;func_0c195c12(a,owner,2);return;}
 func_0c195c12(a,owner,1);func_0c195208(a,owner);func_0c195e18(a,owner);func_0c195c98(a,owner);break;
 default:break;
 }
}
void func_0c195b44(struct Actor *a,struct Actor *owner)
{int i,count=a->s30;struct Actor *child;for(i=1;i<count;i++){child=a->p12;child->b12c=0;func_0c037688(child);}func_0c037688(a);}
void func_0c195b80(struct Actor *a,struct Actor *owner)
{
 int i,count=a->s30;
 for(i=0;i<count;i++){
 ((struct LinkedActor *)a)->sdc=((struct LinkedActor *)owner)->sdc;a->b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->f80=owner->f80;a->f84=owner->f84;a->b1a3=owner->b1a3;a->pad7cc[0]=owner->pad7cc[0];
 ((struct LinkedActor *)a)->b48=((struct LinkedActor *)owner)->b48;((struct LinkedActor *)a)->v80=((struct LinkedActor *)owner)->v80;
 a->b36=owner->b36;a->b12c=0;a->b36=owner->b36;((struct LinkedActor *)a)->b49=8;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;a=a->p12;
 }
}

extern struct ActorFlags *dat_0c2d6f84;
extern unsigned char table_0c257e50[];
extern void func_0c02a18c(struct Actor *,int,int,int),func_0c02a0c4(struct Actor *,int,int);
void func_0c195c12(struct Actor *a,struct Actor *owner,int mode)
{
 struct ActorSubByteState *context=(struct ActorSubByteState *)&owner->sub2a4;int i,count=a->s30;
 for(i=0;i<count;i++){
  if(!mode){if(!a->b12c)break;}
  else if(mode==1)a->b12c=dat_0c2d6f84->flags&1;
  else a->b12c=0;
  a=a->p12;
 }
 if(!mode){if(i<count)a->b12c=1;else ((struct ActorSubByteState *)context)->b5=1;}
}
void func_0c195c98(struct Actor *a,struct Actor *owner)
{
 struct ActorSubByteState *context=(struct ActorSubByteState *)&owner->sub2a4;int i,count=a->s30;unsigned int bank;struct Actor *child;
 for(i=1;i<count;i++){
  child=a->p12;if(!child->b12c)break;
  bank=(unsigned int)table_0c257e50[((struct LinkedActor *)a)->b35]+16;
  func_0c02a18c(a,23,bank,a->b34);a=child;
 }
 bank=19;if(context->b5>=1)bank++;
 func_0c02a0c4(a,23,bank);
}

extern short table_0c257d30[][4];
void func_0c195d28(struct Actor *a,struct Actor *owner)
{
 struct MotionContext8a3 *context=(struct MotionContext8a3 *)&owner->sub2a4;
 struct Actor *child;short *row;int i,count;float nx,ny,dx,dy;
 row=(short *)table_0c257d30+(unsigned int)(a->b34*4+2);nx=*row++*1.66666663f;ny=*row*2.1428571f;
 if((short)a->w130)nx=-nx;
 a->f52=owner->f52+context->vx-nx;a->f56=owner->f56+context->vy-ny;
 count=a->s30;
 for(i=1;i<count;i++){
 child=a->p12;if(!child->b12c)break;
 row=table_0c257d30[a->b34];dx=*row++*1.66666663f;dy=*row*2.1428571f;
 row=(short *)table_0c257d30+(unsigned int)(child->b34*4+2);nx=*row++*1.66666663f;ny=*row*2.1428571f;
 if((short)a->w130){dx=-dx;nx=-nx;}
 child->f52=a->f52+dx-nx;child->f56=a->f56+dy-ny;a=child;
 }
}
void func_0c195e18(struct Actor *a,struct Actor *owner)
{
 struct MotionContext8a3 *context=(struct MotionContext8a3 *)&owner->sub2a4;
 struct Actor *child;short *row;int i,count;float dx,dy,nx,ny,bias=0,height;
 a=a->p20;height=8.5714283f;child=a->p8;row=table_0c257d30[child->b34];dx=*row++*1.66666663f;dy=*row*2.1428571f;
 if((short)a->w130){dx=-dx;bias=-0.0f;}
 child->f52=a->f52+bias-dx;child->f56=a->f56+height-dy;count=a->s30;
 for(i=1;i<count-1;i++){
 a=child;child=a->p8;
 row=(short *)table_0c257d30+(unsigned int)(a->b34*4+2);nx=*row++*1.66666663f;ny=*row*2.1428571f;
 row=table_0c257d30[child->b34];dx=*row++*1.66666663f;dy=*row*2.1428571f;
 if((short)a->w130){nx=-nx;dx=-dx;}
 child->f52=a->f52+nx-dx;child->f56=a->f56+ny-dy;
 }
 if(((struct ActorSubByteState *)context)->b5==1){owner->f52=child->f52-context->vx;owner->f56=child->f56-context->vy;}
}

extern int func_0c02887e(struct LinkedActorVec3 *,struct LinkedActorVec3 *);
void func_0c195f30(struct Actor *a,struct Actor *owner)
{
 struct LinkedActorVec3 point;struct MotionContext8a3 *context=(struct MotionContext8a3 *)&owner->sub2a4;
 struct Actor *child;short *row;int angle,i,count;float dx,dy,nx,ny;
 a=a->p20;point.x=owner->f52+context->vx;point.y=owner->f56+context->vy;
 angle=func_0c02887e(&point,(struct LinkedActorVec3 *)&a->f52);if(owner->b1d2)angle=-angle;
 a->b34=(unsigned char)(angle+4)>>3;count=a->s30;
 for(i=1;i<count;i++){
 child=a->p8;angle=func_0c02887e(&point,(struct LinkedActorVec3 *)&a->f52);if(owner->b1d2)angle=-angle;
 child->b34=(unsigned char)(angle+4)>>3;
 if(i==1){dx=0;dy=8.5714283f;}else{row=(short *)table_0c257d30+(unsigned int)(a->b34*4+2);dx=*row++*1.66666663f;dy=*row*2.1428571f;}
 row=table_0c257d30[child->b34];nx=*row++*1.66666663f;ny=*row*2.1428571f;
 if((short)child->w130){dx=-dx;nx=-nx;}
 child->f52=a->f52+dx-nx;child->f56=a->f56+dy-ny;a=child;
 }
 row=(short *)table_0c257d30+(unsigned int)(a->b34*4+2);dx=*row++*1.66666663f;dy=*row*2.1428571f;
 if((short)a->w130)dx=-dx;
 owner->f52=a->f52+dx-context->vx;owner->f56=a->f56+dy-context->vy;owner->b34=a->b34;
}
