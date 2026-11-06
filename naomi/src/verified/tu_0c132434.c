#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24e2d4[])(struct LinkedActor *);
void func_0c13245a(struct LinkedActor *);
void func_0c1325c2(struct LinkedActor *);
void func_0c132648(struct LinkedActor *);
struct LinkedActor *func_0c132434(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c13245a;a->p24=owner;}
 return a;
}
void func_0c13245a(struct LinkedActor *a){table_0c24e2d4[a->b4](a);}
void func_0c13246c(struct LinkedActor *record)
{
 struct LinkedActor *a=record;
 struct ActorSub2a4 *sub;int one,zero;float offset;
 record=a->p24;sub=&((struct Actor *)record)->sub2a4;a->b4++;a->sdc=a->p24->sdc;
 one=1;a->sdc.b12c=one;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;
 a->v80=a->p24->v80;a->b36=a->p24->b36;a->pad11[0]=66;a->pad11[1]=66;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f56+=137.142853f;a->f60=a->p24->f60;
 offset=106.666664124f;if(a->sdc.w130)a->f52+=offset;else a->f52-=offset;
 ((struct Actor *)a)->f92=!a->b1a3?-5.0f:-8.33333302f;if(a->sdc.w130)((struct Actor *)a)->f92=-((struct Actor *)a)->f92;
 zero=0;a->b36=zero;((struct Actor *)a)->b1a1=a->b1a3+48;((struct Actor *)a)->w1ac=zero;((struct Actor *)a)->b19e=zero;*(void **)&((struct Actor *)a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 sub->b2=one;func_0c02a0c4(a,23,a->b1a3);func_0c1325c2(a);
}
void func_0c1325c2(struct LinkedActor *a)
{
 if(!func_0c028642(a)){func_0c132648(a);return;}
 if(((struct Actor *)a)->b19e || ((struct Actor *)a)->b19f){a->b4++;((struct Actor *)a)->b159=23;((struct Actor *)a)->b158=2;func_0c02a0c4(a,((struct Actor *)a)->b159,((struct Actor *)a)->b158);return;}
 a->f52+=((struct Actor *)a)->f92;func_0c037d0c(a);func_0c02a026(a);
}
void func_0c132628(struct LinkedActor *a){if(func_0c02a026(a)<0)func_0c132648(a);}
void func_0c132648(struct LinkedActor *a)
{
 struct Actor *owner=(struct Actor *)a->p24;struct ActorSub2a4 *sub=&owner->sub2a4;unsigned char zero=0;
 sub->b2=zero;a->b4++;a->sdc.b12c=zero;
}
void func_0c132662(struct LinkedActor *a){func_0c037688(a);}
