#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void func_0c02a18c(struct LinkedActor *,int,int,int);
extern void (*table_0c257eec[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c257efc[])(struct LinkedActor *);
void func_0c1953b8(struct LinkedActor *);
void func_0c1953ce(struct LinkedActor *);
void func_0c1953e0(struct LinkedActor *,struct LinkedActor *);
void func_0c195454(struct LinkedActor *,struct LinkedActor *);
struct LinkedActor *func_0c195384(struct LinkedActor *parent,int kind)
{
    struct LinkedActor *a;
    if((a=func_0c0374da(0,3,1))){a->w38=0x0c03;a->b32=kind;a->p16=func_0c1953b8;a->p24=parent;}
    return a;
}
void func_0c1953b8(struct LinkedActor *a)
{
    table_0c257eec[a->b32](a,a->p24);
}
void func_0c1953ce(struct LinkedActor *a)
{
    table_0c257efc[a->b4](a);
}
void func_0c1953e0(register struct LinkedActor *a,register struct LinkedActor *parent)
{
    a->sdc=parent->sdc;
    a->sdc.b12c=1;
    a->b2=parent->b2; a->b1=parent->b1;
    a->v80.x=parent->v80.x; a->v80.y=parent->v80.y;
    a->b1a3=parent->b1a3; a->b1a4=parent->b1a4;
    a->b48=parent->b48;
    a->v80=parent->v80;
    a->b36=parent->b36;
    a->b4++;
    a->f52=parent->f52;
    a->f56=A(parent)->f41c;
    a->b36=7;
    func_0c02a0c4(a,23,0);
}
void func_0c195454(struct LinkedActor *a,struct LinkedActor *parent)
{
    func_0c02a026(a);
    if(*((unsigned char *)parent+0x159)!=18 || *((unsigned char *)parent+0x158)>2 || (parent->sdc.b141&2)){
        a->b4=2;
        a->sdc.b12c=0;
    }
}
