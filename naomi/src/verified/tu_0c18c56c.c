#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern float *dat_0c2fb3e0;
extern void (*table_0c256264[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c18c5f0(struct LinkedActor *),func_0c18c73c(struct LinkedActor *);
struct LinkedActor *func_0c18c56c(struct LinkedActor *owner)
{
 struct LinkedActor *a;register int two=2,one;
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c18c5f0;a->p24=owner;a->w38=two;a->b32=0;a->b33=0;}
 one=1;
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c18c5f0;a->p24=owner;a->w38=two;a->b32=one;a->b33=one;}
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c18c5f0;a->p24=owner;a->w38=two;a->b32=two;a->b33=one;}
 return a;
}
void func_0c18c5f0(struct LinkedActor *a)
{
 table_0c256264[a->b4](a);
}
void func_0c18c602(struct LinkedActor *a)
{
 struct Actor *owner=(struct Actor *)a->p24;
 float displacement,distance;
 a->f52=owner->f52;a->f56=owner->f41c;distance=80.0f;
 switch(a->b32){case 0:displacement=0.0f;break;case 1:displacement=distance;break;
 case 2:displacement=distance;A(a)->w130^=1;break;}
 if(A(a)->w130)displacement=-displacement;
 a->f52+=displacement;
}
void func_0c18c668(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.b12c=1;a->b36=0;
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 func_0c18c602(a);func_0c02a0c4(a,23,a->b33?12:13);
}
void func_0c18c70c(struct LinkedActor *a)
{
 func_0c18c602(a);
 if(*((unsigned char *)a->p24+0x159)!=22 || *((unsigned char *)a->p24+0x158)!=1){func_0c18c73c(a);return;}
 func_0c02a026(a);
}
void func_0c18c73c(struct LinkedActor *a)
{
 a->b4++;a->sdc.b12c=0;func_0c037688(a);
}
