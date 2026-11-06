#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a18c(struct LinkedActor *,int,int,unsigned char);
extern void func_0c037688(struct LinkedActor *);
extern void (*table_0c257b14[])(struct LinkedActor *);
void func_0c1929e4(struct LinkedActor *a);
void func_0c1929f6(struct LinkedActor *a);
void func_0c192aca(struct LinkedActor *a);
struct LinkedActor *func_0c1929b0(struct LinkedActor *owner)
{struct LinkedActor *a;if((a=func_0c0374da(0,3,0))){a->p16=func_0c1929e4;a->p24=owner;a->w38=0x904;a->s28=owner->sdc.w158.short_value;}return a;}
void func_0c1929e4(struct LinkedActor *a){table_0c257b14[a->b4](a);}
void func_0c1929f6(struct LinkedActor *a)
{
 int v;
 if(!((v=a->p24->sdc.b141)&15))return;
 if(v==A(a)->b33)return;
 a->b33=a->p24->sdc.b141;
 func_0c02a18c(a,23,8,a->b33+0xff&15);
}
void func_0c192a34(struct LinkedActor *a)
{
 a->b4++;
 a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=1;a->b36=15;A(a)->b33=0xff;
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 func_0c1929f6(a);
 func_0c192aca(a);
}
void func_0c192aca(struct LinkedActor *a)
{
 func_0c1929f6(a);
 if(!a->p24->sdc.b141||(unsigned short)a->p24->sdc.w158.short_value!=a->s28){a->b4++;a->sdc.b12c=0;}
}
void func_0c192afa(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;func_0c037688(a);}
