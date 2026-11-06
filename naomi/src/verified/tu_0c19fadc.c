#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c258d08[])(struct LinkedActor *);
extern void (*table_0c258d18[])(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,int,int);
extern void func_0c029fc4(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,int,int);
void func_0c19fb44(struct LinkedActor *);
void func_0c19fb56(struct LinkedActor *);
void func_0c19fb6a(struct LinkedActor *);
struct LinkedActor *func_0c19fadc(struct LinkedActor *parent,char mode)
{
    struct LinkedActor *a;
    if((a=func_0c0374da(0,3,0))){a->p16=func_0c19fb44;a->p24=parent;a->b32=mode;}
    return a;
}
struct LinkedActor *func_0c19fb0a(struct LinkedActor *parent,char mode)
{
    struct LinkedActor *a;
    if((a=func_0c0374da(0,3,0))){a->p16=func_0c19fb44;a->p24=parent->p24;a->p20=parent;a->b32=mode;}
    return a;
}
void func_0c19fb44(struct LinkedActor *a){table_0c258d08[a->b4](a);}
void func_0c19fb56(struct LinkedActor *a){table_0c258d18[a->b32](a);}
void func_0c19fb6a(struct LinkedActor *a)
{
    struct LinkedActor *p;
    a->b4++;p=a->p24;
    a->sdc=p->sdc;
    a->sdc.b12c=1;
    a->b2=p->b2; a->b1=p->b1;
    a->v80.x=p->v80.x; a->v80.y=p->v80.y;
    a->b1a3=p->b1a3; a->b1a4=p->b1a4; a->b48=p->b48;
    a->v80=p->v80;
    a->b36=p->b36;
    A(a)->f264=0.5f;
    a->sdc.b12c=1;
    a->f52=a->p24->f52; a->f56=a->p24->f56; a->f60=a->p24->f60;
    func_0c029e70(a,27,0);
}
