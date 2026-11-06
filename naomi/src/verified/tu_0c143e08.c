#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,char);
extern char func_0c02a026(struct LinkedActor *);
extern short dat_0c24f9ac[];
extern void (*table_0c24f9c0[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f9c8[])(struct LinkedActor *);
extern void (*table_0c24f9d8[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c24f9dc[])(struct LinkedActor *);
void func_0c143e5c(struct LinkedActor *);
void func_0c143f9c(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c143e08(struct Actor *p,unsigned char x,unsigned char y)
{
 struct LinkedActor *q;short *slot;
 if((q=func_0c0374da(0,1,0))!=0){q->p16=func_0c143e5c;q->w38=0xf00;q->p24=(struct LinkedActor *)p;q->b1=p->b1;q->b32=x;q->b33=y;slot=&q->wcc.short_value;*slot=*(short *)&p->b158;}return q;
}
void func_0c143e5c(struct LinkedActor *a){table_0c24f9c0[a->b32](a,a->p24);}
void func_0c143e72(struct LinkedActor *a){table_0c24f9c8[a->b4](a);}
void func_0c143e84(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;a->sdc.b12c=1;a->b49=-1;a->f60=owner->f60;
 A(a)->f92=dat_0c24f9ac[2*(unsigned char)a->b33]*1.66666663f;
 A(a)->f96=(dat_0c24f9ac+2*(unsigned char)a->b33)[1]*2.1428571f;
 if(owner->sdc.w130)A(a)->f92=-A(a)->f92;
 if(!a->b33)A(a)->b158=24;else A(a)->b158=16;
 func_0c02a0c4(a,23,A(a)->b158);
 func_0c143f9c(a,owner);
}
void func_0c143f9c(struct LinkedActor *a,struct LinkedActor *owner)
{
 short *slot=&a->wcc.short_value;
 if(*(short *)&A(owner)->b158!=*slot){a->b4++;return;}
 a->b36=owner->b36;
 a->f52=owner->f52+A(a)->f92;a->f56=owner->f56+A(a)->f96;
 table_0c24f9d8[(unsigned char)a->b5](a,owner);
}
void func_0c143fea(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0){a->sdc.b12c=0;a->b4++;}
}
void func_0c14400c(struct LinkedActor *a){table_0c24f9dc[a->b4](a);}
