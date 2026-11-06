#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern void (*table_0c24e324[])(struct LinkedActor *);
void func_0c132e02(struct LinkedActor *);
void func_0c132ed2(struct LinkedActor *);
void func_0c132ef2(struct LinkedActor *);
struct LinkedActor *func_0c132ddc(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c132e02;a->p24=owner;}
 return a;
}
void func_0c132e02(struct LinkedActor *a){table_0c24e324[a->b4](a);}
void func_0c132e14(struct LinkedActor *a)
{
 float offset;
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->pad11[0]=66;a->pad11[1]=66;a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
 offset=0.0f;if(a->sdc.w130)a->f52+=offset;else a->f52-=offset;
 a->b36=11;func_0c02a0c4(a,23,6);func_0c132ed2(a);
}
void func_0c132ed2(struct LinkedActor *a){if(func_0c02a026(a)<0)func_0c132ef2(a);}
void func_0c132ef2(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c132f00(struct LinkedActor *a){func_0c037688(a);}
