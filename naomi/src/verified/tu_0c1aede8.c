/* Paired actor allocation, attachment offsets, and lifetime callbacks. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
void func_0c1aee3e(struct LinkedActor *);
struct LinkedActor *func_0c1aede8(struct LinkedActor *owner)
{
    struct LinkedActor *a;
    if((a=func_0c0374da(0,3,0))) {
        a->p16=func_0c1aee3e; a->p24=owner;
        a->w38=0x1e01; a->b33=0;
    }
    if((a=func_0c0374da(0,3,0))) {
        a->p16=func_0c1aee3e; a->p24=owner;
        a->w38=0x1e01; a->b33=1;
    }
    return a;
}

extern float *dat_0c2fb41c;
extern void (*table_0c259f78[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c037688(struct LinkedActor *);
void func_0c1aee3e(struct LinkedActor *a)
{
    dat_0c2fb41c=(float *)&a->wcc;
    table_0c259f78[a->b4](a);
}
void func_0c1aee5a(struct LinkedActor *a)
{
    a->f52=a->p24->f52; a->f56=a->p24->f56;
    if(a->sdc.w130) a->f52+=dat_0c2fb41c[0];
    else a->f52-=dat_0c2fb41c[0];
    a->f56+=dat_0c2fb41c[1];
}
void func_0c1aee9c(struct LinkedActor *a)
{
    float zero;
    a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
    a->b2=a->p24->b2;a->b1=a->p24->b1;
    a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
    a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
    a->b48=a->p24->b48;a->v80=a->p24->v80;
    a->b36=a->p24->b36;a->sdc.b12c=1;
    a->b36=a->b33?0:11;
    a->f52=a->p24->f52;a->f56=a->p24->f56;a->s28=0;
    zero=0.0f;dat_0c2fb41c[0]=zero;dat_0c2fb41c[1]=zero;
    func_0c1aee5a(a);
    func_0c02a0c4(a,23,(unsigned char)a->b33*2);
}
void func_0c1aefa4(struct LinkedActor *);
void func_0c1aef7e(struct LinkedActor *a)
{
    func_0c1aee5a(a);
    if(((signed char *)&((struct Actor *)a->p24)->w150)[1]!=3) { func_0c1aefa4(a); return; }
    func_0c02a026((struct Actor *)a);
}
void func_0c1aefa4(struct LinkedActor *a)
{
    a->b4++;a->sdc.b12c=0;func_0c037688(a);
}
