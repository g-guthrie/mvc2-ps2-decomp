#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c2527b8[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c2527c4[])(struct LinkedActor *);
extern int func_0c02849a(void);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c1703a4(struct LinkedActor *);
struct LinkedActor *func_0c170378(struct LinkedActor *owner)
{
    struct LinkedActor *a;
    if ((a=func_0c0374da(0,1,1)) != 0) {
        a->w38=0x2d01;
        a->p16=func_0c1703a4;
        a->p24=owner;
    }
    return a;
}
void func_0c1703a4(struct LinkedActor *a)
{
    struct LinkedActor *q=a;
    table_0c2527b8[q->b4](q,q->p24);
}
void func_0c1703b8(struct LinkedActor *a,struct LinkedActor *owner)
{
    float offset;
    a->sdc=owner->sdc;
    a->sdc.b12c=1;
    a->b2=owner->b2;
    a->b1=owner->b1;
    a->v80.x=owner->v80.x;
    a->v80.y=owner->v80.y;
    a->b1a3=owner->b1a3;
    a->b1a4=owner->b1a4;
    a->b48=owner->b48;
    a->v80=owner->v80;
    a->b36=owner->b36;
    a->b4++;
    a->pad11[0]=68;
    a->pad11[1]=68;
    a->b32=func_0c02849a() & 3;
    a->b33=0;
    offset=-80.0f;
    if (a->sdc.w130) offset=80.0f;
    a->f52=owner->f52+offset;
    a->f56=((struct Actor *)owner)->f41c;
    func_0c02a0c4(a,23,26);
}
void func_0c170462(struct LinkedActor *a)
{
    table_0c2527c4[(unsigned char)a->b5](a);
}
