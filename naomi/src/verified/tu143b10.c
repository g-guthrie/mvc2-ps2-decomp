/* Exact attachment initializer, local follow handler and shared literal pools. */
#include "objects.h"
#define A(a) ((struct Actor *)(a))
#define M(a) ((struct MeActor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern int func_0c028642(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c24f944[];
extern char dat_0c24f980[],dat_0c24f934[];
extern void (*dat_0c24f990[])(struct LinkedActor *,struct LinkedActor *);
extern void (*dat_0c24f998[])(struct LinkedActor *);
extern void (*dat_0c24f9a8[])(struct LinkedActor *,struct LinkedActor *);
void func_0c143b64(struct LinkedActor *);
void func_0c143d26(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c143b10(struct Actor *p,unsigned char x,unsigned char y)
{
 struct LinkedActor *q;short *slot;
 if((q=func_0c0374da(0,1,0))!=0){q->p16=func_0c143b64;q->w38=0xf01;q->p24=(struct LinkedActor *)p;q->b1=p->b1;q->b32=x;q->b33=y;slot=&q->wcc.short_value;*slot=*(short *)&p->b158;}return q;
}
void func_0c143b64(struct LinkedActor *q){dat_0c24f990[q->b32](q,q->p24);}
void func_0c143b7a(struct LinkedActor *a){dat_0c24f998[a->b4](a);}
void func_0c143b8c(struct LinkedActor *a,struct LinkedActor *owner)
{
 int one,zero;short horizontal;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=-1;M(a)->blk_dc.b13c=M(a)->blk_dc.b13d=M(a)->blk_dc.b13e=M(a)->blk_dc.b13f=16;
 zero=0;if(!a->b32)A(a)->b1a1=48;else A(a)->b1a1=56;
 A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 a->pad11[0]=66;a->pad11[1]=66;a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 a->f56+=(dat_0c24f944+(unsigned char)a->b33*2)[1]*2.1428571f;
 horizontal=(short)(int)(dat_0c24f944[(unsigned char)a->b33*2]*1.66666663f);
 if(A(owner)->w130)horizontal=-horizontal;
 a->f52+=horizontal;a->b34=dat_0c24f980[(unsigned char)a->b33];
 if(A(a)->w130){a->b34=32-a->b34;a->b34&=31;}
 func_0c02a0c4(a,23,dat_0c24f934[(unsigned char)a->b33]);func_0c143d26(a,owner);
}
void func_0c143d26(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b36=owner->b36;
 if(!func_0c028642(a)||A(owner)->f41c>a->f56){a->b4++;return;}
 dat_0c24f9a8[(unsigned char)a->b5](a,owner);
}
