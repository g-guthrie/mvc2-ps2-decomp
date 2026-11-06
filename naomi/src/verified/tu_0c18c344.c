#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern float *dat_0c2fb3e0;
extern void (*table_0c256254[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c18c3b2(struct LinkedActor *),func_0c18c53c(struct LinkedActor *);
struct LinkedActor *func_0c18c344(struct LinkedActor *owner,unsigned char index)
{
 struct LinkedActor *a;int one=1;
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c18c3b2;a->p24=owner;a->w38=one;a->b32=index;a->b33=0;}
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c18c3b2;a->p24=owner;a->w38=one;a->b32=index;a->b33=one;}
 return a;
}
void func_0c18c3b2(struct LinkedActor *a)
{
 dat_0c2fb3e0=(float *)&a->wcc;table_0c256254[a->b4](a);
}
void func_0c18c3ce(struct LinkedActor *a)
{
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 if(a->sdc.w130)a->f52+=dat_0c2fb3e0[0];else a->f52-=dat_0c2fb3e0[0];
 a->f56+=dat_0c2fb3e0[1];
}
void func_0c18c410(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=1;a->b36=a->b33?0:11;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->s28=0;
 dat_0c2fb3e0[0]=a->b32?-30.0f:0.0f;dat_0c2fb3e0[1]=a->b32?34.2857132f:0.0f;
 func_0c18c3ce(a);func_0c02a0c4(a,23,(unsigned char)a->b33*2);
}
void func_0c18c50c(struct LinkedActor *a)
{
 func_0c18c3ce(a);
 if(*((char *)&A(a->p24)->w150+1)!=5 && *((char *)&A(a->p24)->w150+1)!=8){func_0c18c53c(a);return;}
 func_0c02a026(a);
}
void func_0c18c53c(struct LinkedActor *a)
{
 a->b4++;a->sdc.b12c=0;func_0c037688(a);
}
