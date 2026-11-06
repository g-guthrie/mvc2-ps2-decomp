#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c257c9c[])(struct LinkedActor *,struct LinkedActor *);
void func_0c194570(struct LinkedActor *);
struct LinkedActor *func_0c1944c8(struct LinkedActor *parent,unsigned char b32,unsigned char b33)
{
    struct LinkedActor *a;
    if((a=func_0c0374da(0,3,1))){
        a->p16=func_0c194570;a->p24=parent;a->b1=parent->b1;
        a->b32=b32;a->b33=b33;a->w38=0x0b01;a->sdc.b12c=0;
    }
    return a;
}
struct LinkedActor *func_0c19451c(struct LinkedActor *parent,unsigned char b32,unsigned char b33)
{
    struct LinkedActor *a;
    if((a=func_0c0374da((int)parent,3,2))){
        a->p16=func_0c194570;a->p24=parent->p24;a->p20=parent;a->b1=parent->b1;
        a->b32=b32;a->b33=b33;a->w38=0x0b01;a->sdc.b12c=0;
    }
    return a;
}
void func_0c194570(struct LinkedActor *a)
{table_0c257c9c[(unsigned char)a->b4](a,a->p24);}

extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c194594(struct LinkedActor *a,struct LinkedActor *parent)
{
    float *smooth=(float *)&a->pad9b[0];
    int speed;
    func_0c19451c(a,1,0);func_0c19451c(a,1,1);func_0c19451c(a,1,2);
    func_0c19451c(a,1,3);func_0c19451c(a,1,4);func_0c19451c(a,1,5);
    func_0c19451c(a,1,6);func_0c19451c(a,1,7);func_0c19451c(a,1,8);
    a->sdc.b12c=0;
    a->f52=parent->f52;a->f56=parent->f56+222.857132f;
    speed=1048576;
    if(!a->sdc.w130)speed=-1048576;
    a->f92=speed*1.66666663f/65536.0f;a->f96=-3.75f;
    a->f104=a->f92/64.0f;a->f108=a->f96/64.0f;
    *smooth=0;func_0c02a0c4(a,23,1);
}
