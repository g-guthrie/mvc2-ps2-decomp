#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c25290c[])(struct LinkedActor *,struct LinkedActor *),(*table_0c252914[])(struct LinkedActor *,struct LinkedActor *);
void func_0c171ec2(struct LinkedActor *);
struct LinkedActor *func_0c171e0c(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c171ec2;a->w38=0x2e04;a->p24=owner;a->b1=owner->b1;*(&a->b32)=mode;*(&a->b33)=value;}
 return a;
}
struct LinkedActor *func_0c171e5a(struct LinkedActor *owner,unsigned char mode,unsigned char value,short speed,unsigned char duration)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,1))){a->p16=func_0c171ec2;a->w38=0x2e04;a->p24=owner->p24;a->b1=owner->b1;a->p20=owner;*(&a->b32)=mode;a->b33=value;((struct Actor *)a)->f92=speed;a->s30=duration;}
 return a;
}
void func_0c171ec2(struct LinkedActor *a){table_0c25290c[a->b32](a,a->p24);}
void func_0c171ed8(struct LinkedActor *a,struct LinkedActor *owner){table_0c252914[a->b4](a,owner);}

#define A(a) ((struct Actor *)(a))
struct InputMask172 {unsigned char pad0[59],selected;unsigned short mask;};
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c2f8338[];
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c1723ea(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c252924[])(struct LinkedActor *,struct LinkedActor *);
void func_0c171fb4(struct LinkedActor *,struct LinkedActor *);
void func_0c171efc(struct LinkedActor *a,struct LinkedActor *owner)
{
 int one,zero;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=-2;zero=0;A(a)->b1a1=52;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=66;a->pad11[1]=66;
 func_0c02a0c4(a,23,19);a->b35=zero;a->s28=4;func_0c171fb4(a,owner);
}
void func_0c171fb4(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct InputMask172 *controls;
 if((unsigned char)A(owner)->b159!=22 || owner->b5){a->b4++;func_0c1723ea(a,owner);return;}
 a->b36=owner->b36;a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 if(!A(a)->w130)a->f52+=-178.33333f;else a->f52+=178.33333f;
 a->f56+=203.57143f;controls=(struct InputMask172 *)dat_0c2f8338;
 if(!(controls->mask&(1<<controls->selected)))table_0c252924[(unsigned char)a->b5](a,owner);
}

extern char func_0c02a026(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c0346da(struct LinkedActor *,int),func_0c037d0c(struct LinkedActor *),func_0c1723ea(struct LinkedActor *,struct LinkedActor *);
extern struct LinkedActor *func_0c171e5a(struct LinkedActor *,unsigned char,unsigned char,short,unsigned char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c252930[])(struct LinkedActor *,struct LinkedActor *);
void func_0c172078(register struct LinkedActor *a)
{
 func_0c02a026(a);
 if(--a->s28==0){
  register int remaining;int speed;register float step;
  a->b5++;remaining=6;speed=-170;a->b33=7;a->s30=0;step=50.0f;
  do{
   func_0c171e5a(a,1,a->b33,speed,a->s30);
   speed=(short)speed;a->s30++;speed=(int)(speed-step);a->s30&=3;
  }while(--remaining);
  a->b33=0;func_0c0346da(a,72);
 }
}
void func_0c172100(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *context=&A(owner)->sub2a4;
 func_0c02a026(a);func_0c037d0c(a);
 if(A(a)->b141){int zero=0;A(a)->b141=zero;A(a)->b1a1=52;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;}
 func_0c171e5a(a,1,a->b33,-170,a->s30);
 a->b33++;a->b33&=7;a->s30++;a->s30&=3;
 if(context->b6){a->b5++;func_0c02a0c4(a,23,20);}
}
void func_0c1721a0(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(func_0c02a026(a)<0){a->b4++;func_0c1723ea(a,owner);}
}
void func_0c1721f0(struct LinkedActor *a,struct LinkedActor *owner){table_0c252930[a->b4](a,owner);}


extern int func_0c028642(struct LinkedActor *);
extern void (*table_0c252940[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1722d6(struct LinkedActor *,struct LinkedActor *),func_0c1723f8(struct LinkedActor *,struct LinkedActor *),func_0c172410(struct LinkedActor *,struct LinkedActor *);
void func_0c172202(struct LinkedActor *a,struct LinkedActor *owner)
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
 func_0c02a0c4(a,23,a->b33+21);func_0c1722d6(a,owner);
}
void func_0c1722d6(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct InputMask172 *controls;
 if((unsigned char)A(owner)->b159!=22 || owner->b5){a->b4++;func_0c1723f8(a,owner);return;}
 a->b36=owner->b36;controls=(struct InputMask172 *)dat_0c2f8338;
 if(!(controls->mask&(1<<controls->selected)))table_0c252940[(unsigned char)a->b5](a,owner);
}
void func_0c172354(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *context=&A(owner)->sub2a4;
 func_0c172410(a,a->p20);func_0c02a026(a);if(!a->s30)func_0c037d0c(a);
 if(context->b6){a->b5++;func_0c02a0c4(a,23,29);}
 if(!func_0c028642(a)){a->b4++;func_0c1723f8(a,owner);}
}
void func_0c1723ba(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(func_0c02a026(a)<0){a->b4++;func_0c1723f8(a,owner);}
}
void func_0c1723ea(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c1723f8(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c172406(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
void func_0c172410(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 if(!A(a)->w130)a->f52+=A(a)->f92;else a->f52-=A(a)->f92;
 A(a)->f92-=50.0f;
}
