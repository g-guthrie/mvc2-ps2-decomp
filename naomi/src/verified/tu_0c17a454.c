/* Exact actor-frame group, including constructors, local follow routines and literal pools. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c2f8338[];
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c0346da(struct LinkedActor *,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
void func_0c17a50a(struct LinkedActor *);
extern void (*table_0c2538d0[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2538d8[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c2538e8[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2538f4[])(struct LinkedActor *,struct LinkedActor *),(*table_0c253904[])(struct LinkedActor *,struct LinkedActor *);
void func_0c17a544(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17a5fc(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17a6c0(register struct LinkedActor *a);
void func_0c17a748(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17a7e8(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17a838(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17a84a(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17a91e(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17a99c(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17aa02(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17aa32(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17aa40(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17aa4e(struct LinkedActor *a,struct LinkedActor *owner);
void func_0c17aa58(struct LinkedActor *a,struct LinkedActor *owner);

struct LinkedActor *func_0c17a454(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c17a50a;a->w38=0x3304;a->p24=owner;a->b1=owner->b1;*(&a->b32)=mode;*(&a->b33)=value;}
 return a;
}
struct LinkedActor *func_0c17a4a2(struct LinkedActor *owner,unsigned char mode,unsigned char value,short speed,unsigned char duration)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,1))){a->p16=func_0c17a50a;a->w38=0x3304;a->p24=owner->p24;a->b1=owner->b1;a->p20=owner;*(&a->b32)=mode;a->b33=value;((struct Actor *)a)->f92=speed;a->s30=duration;}
 return a;
}
void func_0c17a50a(struct LinkedActor *a){table_0c2538d0[a->b32](a,a->p24);}
void func_0c17a520(struct LinkedActor *a,struct LinkedActor *owner){table_0c2538d8[a->b4](a,owner);}
void func_0c17a544(struct LinkedActor *a,struct LinkedActor *owner)
{
 int one,zero;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=-2;zero=0;A(a)->b1a1=52;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=66;a->pad11[1]=66;
 func_0c02a0c4(a,23,13);a->b35=zero;a->s28=4;func_0c17a5fc(a,owner);
}
void func_0c17a5fc(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct Dat_13bb5c *controls;
 if((unsigned char)A(owner)->b159!=22 || owner->b5){a->b4++;func_0c17aa32(a,owner);return;}
 a->b36=owner->b36;a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 if(!A(a)->w130)a->f52+=-178.33333f;else a->f52+=178.33333f;
 a->f56+=203.57143f;controls=(struct Dat_13bb5c *)dat_0c2f8338;
 if(!(controls->w3c&(1<<controls->b3b)))table_0c2538e8[(unsigned char)a->b5](a,owner);
}
void func_0c17a6c0(register struct LinkedActor *a)
{
 func_0c02a026(a);
 if(--a->s28==0){
  register int remaining;int speed;register float step;
  a->b5++;remaining=6;speed=-170;a->b33=7;a->s30=0;step=50.0f;
  do{
   func_0c17a4a2(a,1,a->b33,speed,a->s30);
   speed=(short)speed;a->s30++;speed=(int)(speed-step);a->s30&=3;
  }while(--remaining);
  a->b33=0;func_0c0346da(a,72);
 }
}
void func_0c17a748(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *context=&A(owner)->sub2a4;
 func_0c02a026(a);func_0c037d0c(a);
 if(A(a)->b141){int zero=0;A(a)->b141=zero;A(a)->b1a1=52;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;}
 func_0c17a4a2(a,1,a->b33,-170,a->s30);
 a->b33++;a->b33&=7;a->s30++;a->s30&=3;
 if(context->b6){a->b5++;func_0c02a0c4(a,23,14);}
}
void func_0c17a7e8(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(func_0c02a026(a)<0){a->b4++;func_0c17aa32(a,owner);}
}
void func_0c17a838(struct LinkedActor *a,struct LinkedActor *owner){table_0c2538f4[a->b4](a,owner);}
void func_0c17a84a(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActor *p=a->p20;int one,zero;
 a->b4++;a->sdc=p->sdc;one=1;a->sdc.b12c=one;a->b2=p->b2;a->b1=p->b1;
 a->v80.x=p->v80.x;a->v80.y=p->v80.y;a->b1a3=p->b1a3;a->b1a4=p->b1a4;a->b48=p->b48;a->v80=p->v80;a->b36=p->b36;
 a->sdc.b12c=one;a->b49=-2;
 if(!a->s30){
  a->pad11[0]=66;p->b35++;p->b35&=3;zero=0;
  A(a)->b1a1=p->b35+55;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;a->pad11[1]=66;
 }
 ((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=26;
 func_0c02a0c4(a,23,a->b33+15);func_0c17a91e(a,owner);
}
void func_0c17a91e(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct Dat_13bb5c *controls;
 if((unsigned char)A(owner)->b159!=22 || owner->b5){a->b4++;func_0c17aa40(a,owner);return;}
 a->b36=owner->b36;controls=(struct Dat_13bb5c *)dat_0c2f8338;
 if(!(controls->w3c&(1<<controls->b3b)))table_0c253904[(unsigned char)a->b5](a,owner);
}
void func_0c17a99c(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *context=&A(owner)->sub2a4;
 func_0c17aa58(a,a->p20);func_0c02a026(a);if(!a->s30)func_0c037d0c(a);
 if(context->b6){a->b5++;func_0c02a0c4(a,23,23);}
 if(!func_0c028642(a)){a->b4++;func_0c17aa40(a,owner);}
}
void func_0c17aa02(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(func_0c02a026(a)<0){a->b4++;func_0c17aa40(a,owner);}
}
void func_0c17aa32(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c17aa40(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c17aa4e(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
void func_0c17aa58(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 if(!A(a)->w130)a->f52+=A(a)->f92;else a->f52-=A(a)->f92;
 A(a)->f92-=50.0f;
}
