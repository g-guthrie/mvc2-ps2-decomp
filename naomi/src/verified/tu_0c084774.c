#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0432ca(struct Actor *),func_0c08362c(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c044548(struct Actor *,struct Actor *);
extern int func_0c0447bc(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c0429a4(struct Actor *,struct LinkedActorVec3 *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2420e4[])(struct Actor *),(*table_0c2420ec[])(struct Actor *),(*table_0c242100[])(struct Actor *);
void func_0c0847d8(struct Actor *,struct ActorSubThrowContext *),func_0c084940(struct Actor *,struct ActorSubThrowContext *),func_0c0849d0(struct Actor *,struct ActorSubThrowContext *);
void func_0c084774(struct Actor *a){a->b3f8=2;a->b328=5;if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0847a2(struct Actor *a){table_0c2420e4[a->b7](a);}
void func_0c0847b4(struct Actor *a){table_0c2420ec[a->b7](a);}
void func_0c0847c6(struct Actor *a){table_0c242100[a->b6](a);}
void func_0c0847d8(struct Actor *a,struct ActorSubThrowContext *sub)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;a->b3f1=a->b255==6?2:0;
 if(func_0c02a026(a)<0){a->b6++;a->b7=0;a->b3f0=0;a->b3f1=0;
 position.x=40.0f;position.y=199.28571f;func_0c0429a4(a,&position,1);}
}
void func_0c08486c(struct Actor *a,struct ActorSubThrowContext *sub)
{
 int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b7++;zero=0;sub->b19=zero;func_0c08362c(a);
 a->b159=22;a->b158=2;func_0c02a0c4(a,a->b159,a->b158);func_0c0432ca(a);
 a->b1a1=76;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c0847d8(a,sub);
}
void func_0c0848f2(struct Actor *a)
{
 float speed;
 a->b7++;speed=16.666666031f;if(!a->w130)speed=-16.666666031f;
 a->f92=speed;a->f104=0;a->f96=3.21428561211f;a->f108=-0.33482140303f;
 a->b159=22;a->b158=3;func_0c02a0c4(a,a->b159,a->b158);
}
void func_0c084940(struct Actor *a,struct ActorSubThrowContext *sub)
{
 float speed;
 a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;a->b7++;
 speed=4.16666651f;if(!a->w130)speed=-4.16666651f;
 a->f92=speed;a->f104=0;a->f96=0;a->f108=0;a->b159=22;a->b158=4;func_0c02a0c4(a,a->b159,a->b158);
}
void func_0c0849d0(struct Actor *a,struct ActorSubThrowContext *sub)
{
 struct Actor *child;
 a->f56=a->f41c;child=a->p1b0;
 if(!func_0c0447bc(a)||child->b233!=2){func_0c084940(a,sub);return;}
 sub->base.child=child;a->b6++;a->b7=0;a->b1f7=197;func_0c044548(a,child);
 a->b1ed=2;a->b1f5=2;child->p1b4=a;child->w130=a->w130;child->b1f6=17;child->b1f9=2;child->b1a1=76;
}
void func_0c084a54(struct Actor *a,struct ActorSubThrowContext *sub)
{
 char flags=a->b19e;
 if(flags<0){flags&=127;if(!flags){func_0c0849d0(a,sub);return;}a->f56=a->f41c;goto finish;}
 func_0c02a026(a);
 if(a->b141)return;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c044e52(a)){finish:func_0c084940(a,sub);}
}
