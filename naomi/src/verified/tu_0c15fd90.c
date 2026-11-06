#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern struct LinkedActor *func_0c160158(struct LinkedActor *,unsigned char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern signed char dat_0c251390[][2];
extern void (*table_0c25139c[])(struct LinkedActor *),(*table_0c2513ac[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2513b4[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2513c8[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2513d4[])(struct LinkedActor *,struct LinkedActor *);
void func_0c15fdbe(struct LinkedActor *),func_0c15feac(struct LinkedActor *),func_0c1600f4(struct LinkedActor *,struct LinkedActor *),func_0c160120(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c15fd90(struct LinkedActor *owner,unsigned char mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c15fdbe;a->p24=owner;a->b32=mode;}return a;}
void func_0c15fdbe(struct LinkedActor *a){table_0c25139c[a->b4](a);}
void func_0c15fdd0(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 signed char *row;
 a->b4++;a->w38=0x1c08;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->s28=0;

 row=dat_0c251390[(unsigned char)a->b32];a->b49=row[0];
 if(!a->b32){A(a)->b19c=66;A(a)->b19d=66;A(a)->b1a1=78;}
 else if(a->b32==4){A(a)->b19c=66;A(a)->b19d=66;A(a)->b1a1=63;}
 else goto animation;
 A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
animation:
 func_0c02a0c4(a,22,row[1]);func_0c15feac(a);
}
void func_0c15feac(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if(owner->b1d0!=29){a->b4++;a->sdc.b12c=0;return;}
 a->b36=owner->b36;func_0c160120(a,owner);table_0c2513ac[(unsigned char)a->b5](a,owner);
}
void func_0c15ff2a(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSubMotionFlags *sub=(struct ActorSubMotionFlags *)&A(owner)->sub2a4;
 if(!sub->timer30){a->b5++;a->b6=0;a->sdc.b12c=1;func_0c1600f4(a,owner);return;}
 a->sdc.b12c=1;if(sub->flag25)a->sdc.b12c=0;
 table_0c2513b4[a->b32](a,owner);
}
void func_0c15ff74(struct LinkedActor *a,struct LinkedActor *owner){table_0c2513c8[a->b6](a,owner);func_0c037d0c(a);}
void func_0c15ff92(struct LinkedActor *a,struct LinkedActor *owner)
{struct ActorSubMotionFlags *sub=(struct ActorSubMotionFlags *)&A(owner)->sub2a4;if(((unsigned char *)sub)[12]&1){a->b6++;sub->flag28|=1;}}
void func_0c15ffb2(struct LinkedActor *a,struct LinkedActor *owner)
{func_0c02a026(a);if(a->sdc.b141){a->b6++;if((++a->s28&3)==0)func_0c160158(a,0);else func_0c160158(a,2);}}
void func_0c15ffec(struct LinkedActor *a,struct LinkedActor *owner)
{register struct ActorSubMotionFlags *sub;if(func_0c02a026(a)<0){a->b6=0;sub=(struct ActorSubMotionFlags *)&A(owner)->sub2a4;sub->flag28&=254;}}
void func_0c16001e(struct LinkedActor *a,struct LinkedActor *owner){func_0c02a026(a);}
void func_0c160024(struct LinkedActor *a,struct LinkedActor *owner){table_0c2513d4[a->b6](a,owner);func_0c037d0c(a);}
void func_0c160068(struct LinkedActor *a,struct LinkedActor *owner)
{struct ActorSubMotionFlags *sub=(struct ActorSubMotionFlags *)&A(owner)->sub2a4;if(((unsigned char *)sub)[12]&2){a->b6++;sub->flag28|=2;}}
void func_0c160088(struct LinkedActor *a,struct LinkedActor *owner)
{func_0c02a026(a);if(a->sdc.b141){a->b6++;if((++a->s28&3)==0)func_0c160158(a,1);else func_0c160158(a,3);}}
void func_0c1600c2(struct LinkedActor *a,struct LinkedActor *owner)
{register struct ActorSubMotionFlags *sub;if(func_0c02a026(a)<0){a->b6=0;sub=(struct ActorSubMotionFlags *)&A(owner)->sub2a4;sub->flag28&=253;}}
void func_0c1600f4(struct LinkedActor *a,struct LinkedActor *owner){if(!A(owner)->b141){a->b4++;a->sdc.b12c=0;}}
void func_0c16010c(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c16011a(struct LinkedActor *a){func_0c037688(a);}
void func_0c160120(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.w130=owner->sdc.w130;*(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;}
