/* Exact 0x0c172d48..0x0c17323c: attachment constructors, owner guard, timed child spawning, child motion and cleanup. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct InputMask173 {unsigned char pad0[59],selected;unsigned short mask;};
extern struct LinkedActor *func_0c0374da(int,int,int);
extern unsigned char dat_0c2f8338[];
extern void (*table_0c252a28[])(struct LinkedActor *,struct LinkedActor *),(*table_0c252a30[])(struct LinkedActor *,struct LinkedActor *),(*table_0c252a40[])(struct LinkedActor *,struct LinkedActor *),(*table_0c252a48[])(struct LinkedActor *,struct LinkedActor *);
extern void func_0c1731f8(struct LinkedActor *,struct LinkedActor *);
void func_0c172de4(struct LinkedActor *),func_0c172e74(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c172d48(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c172de4;a->w38=0x2e06;a->p24=owner;a->b1=owner->b1;*(&a->b32)=mode;*(&a->b33)=value;}
 return a;
}
struct LinkedActor *func_0c172d96(struct LinkedActor *owner,unsigned char mode,unsigned char value)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,1))){a->p16=func_0c172de4;a->w38=0x2e06;a->p24=owner->p24;a->b1=owner->b1;a->p20=owner;*(&a->b32)=mode;a->b33=value;}
 return a;
}
void func_0c172de4(struct LinkedActor *a){table_0c252a28[a->b32](a,a->p24);}
void func_0c172dfa(struct LinkedActor *a,struct LinkedActor *owner){table_0c252a30[a->b4](a,owner);}
void func_0c172e0c(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=0;a->b49=-2;a->s28=4;func_0c172e74(a,owner);
}
void func_0c172e74(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct InputMask173 *controls;
 if((unsigned char)A(owner)->b159!=22 || owner->b5){a->b4++;func_0c1731f8(a,owner);return;}
 a->b36=owner->b36;a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 if(!A(a)->w130)a->f52+=-178.33333f;else a->f52+=178.33333f;
 a->f56+=203.57143f;controls=(struct InputMask173 *)dat_0c2f8338;
 if(!(controls->mask&(1<<controls->selected)))table_0c252a40[(unsigned char)a->b5](a,owner);
}
void func_0c172f28(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(--a->s28==0){int zero=0;a->b5++;a->b33=zero;a->s28=zero;}
}
void func_0c172f4a(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *context=&A(owner)->sub2a4;
 if(a->s28--==0){a->s28=2;func_0c172d96(a,1,a->b33);a->b33++;a->b33&=1;}
 if(context->b6){a->b4++;func_0c1731f8(a,owner);}
}
void func_0c172faa(struct LinkedActor *a,struct LinkedActor *owner){table_0c252a48[a->b4](a,owner);}

extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c252a08[];
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c02849a(void),func_0c028642(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *),func_0c0346da(struct LinkedActor *,int),func_0c1d330c(struct LinkedActor *,struct LinkedActorVec3 *,int,int);
extern void (*table_0c252a58[])(struct LinkedActor *,struct LinkedActor *);
void func_0c173102(struct LinkedActor *,struct LinkedActor *),func_0c173206(struct LinkedActor *,struct LinkedActor *);
void func_0c172fd8(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActor *p=a->p20;int one,zero;
 a->b4++;a->sdc=p->sdc;one=1;a->sdc.b12c=one;a->b2=p->b2;a->b1=p->b1;
 a->v80.x=p->v80.x;a->v80.y=p->v80.y;a->b1a3=p->b1a3;a->b1a4=p->b1a4;a->b48=p->b48;a->v80=p->v80;a->b36=p->b36;
 a->sdc.b12c=one;a->b49=-2;a->pad11[0]=68;a->pad11[1]=68;zero=0;
 if(!a->b33)A(a)->b1a1=66;else{goto variant;variant:A(a)->b1a1=67;}
 A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 goto colors;colors:((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=26;
 a->f52=p->f52;a->f56=p->f56;a->f60=p->f60;
 {short index=func_0c02849a()&15;a->f56+=dat_0c252a08[index]*2.1428571f;}
 A(a)->f92=-23.3333321f;A(a)->f104=-0.20833333f;
 if(A(a)->w130){A(a)->f92=-A(a)->f92;A(a)->f104=-A(a)->f104;}
 func_0c02a0c4(a,23,41);func_0c173102(a,owner);
}
void func_0c173102(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b36=owner->b36;table_0c252a58[(unsigned char)a->b5](a,owner);
}
void func_0c173158(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;func_0c02a026(a);
 if(!A(a)->b19f){goto draw;draw:func_0c037d0c(a);if(!A(a)->b19e)goto check_lifetime;}
 a->b5++;return;
 check_lifetime:if(!func_0c028642(a)){a->b4++;func_0c173206(a,owner);}
}
void func_0c1731cc(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c1d330c(a,(struct LinkedActorVec3 *)&a->f52,1,8);func_0c0346da(a,73);a->b4++;a->sdc.b12c=0;
}
void func_0c1731f8(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c173206(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c173214(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
