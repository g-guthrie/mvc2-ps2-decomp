#include "objects.h"
#define OWNER(a) ((struct Actor *)(a)->p24)
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c252034[])(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c1682de(struct LinkedActor *),func_0c168450(struct LinkedActor *),func_0c1684c8(struct LinkedActor *);
struct LinkedActor *func_0c1682b8(struct LinkedActor *owner){struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c1682de;a->p24=owner;}return a;}
void func_0c1682de(struct LinkedActor *a){table_0c252034[a->b4](a);}
void func_0c1682f0(struct LinkedActor *record)
{
 struct LinkedActor *a=record;
 struct ActorSub2a4 *sub;
 int one,effect;unsigned int zero;
 record=a->p24;sub=&((struct Actor *)record)->sub2a4;
 a->b4++;a->sdc=a->p24->sdc;one=1;a->sdc.b12c=one;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 effect=66;((struct MeActor *)a)->blk_dc.b13e=64;((struct MeActor *)a)->blk_dc.b13f=64;a->pad11[0]=effect;a->pad11[1]=effect;a->b36=11;a->sdc.b12c=one;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f56+=115.71428f;a->f60=a->p24->f60;
 if(((struct Actor *)a)->w130)a->f52+=120.0f;else a->f52-=120.0f;
 if(!a->b1a3)((struct Actor *)a)->f92=-4.16666651f;else ((struct Actor *)a)->f92=-7.5f;
 if(((struct Actor *)a)->w130)((struct Actor *)a)->f92=-((struct Actor *)a)->f92;
 sub->b6=one;func_0c02a0c4(a,20,0);
 zero=0;((struct Actor *)a)->b1a1=effect;((struct Actor *)a)->w1ac=zero;*(unsigned char *)&((struct Actor *)a)->b19e=zero;*(void **)&((struct Actor *)a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c168450(a);
}
void func_0c168450(struct LinkedActor *a)
{
 if(!func_0c028642(a)){func_0c1684c8(a);return;}
 if(((struct Actor *)a)->b19e||((struct Actor *)a)->b19f){a->b4++;func_0c02a0c4(a,20,1);return;}
 a->f52+=((struct Actor *)a)->f92;func_0c037d0c(a);func_0c02a026(a);
}
void func_0c1684a8(struct LinkedActor *a){if(func_0c02a026(a)<0)func_0c1684c8(a);}
void func_0c1684c8(struct LinkedActor *a){struct Actor *owner=OWNER(a);struct ActorSub2a4 *sub=&owner->sub2a4;int zero=0;sub->b6=zero;a->b4++;a->sdc.b12c=zero;}
void func_0c1684e2(struct LinkedActor *a){func_0c037688(a);}
