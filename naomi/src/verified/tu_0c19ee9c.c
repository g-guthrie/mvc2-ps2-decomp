#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c029e70(struct LinkedActor *,int,int),func_0c0344a0(struct LinkedActor *,int);
extern void (*table_0c258c84[])(struct LinkedActor *),(*table_0c258c94[])(struct LinkedActor *);
void func_0c19eeca(struct LinkedActor *);
struct LinkedActor *func_0c19ee9c(struct LinkedActor *owner,char mode){struct LinkedActor *a;if((a=func_0c0374da(0,3,0))){a->p16=func_0c19eeca;a->p24=owner;a->b32=mode;}return a;}
void func_0c19eeca(struct LinkedActor *a){table_0c258c84[a->b4](a);}
void func_0c19eedc(struct LinkedActor *a){table_0c258c94[a->b32](a);}
void func_0c19eef0(struct LinkedActor *a)
{
struct LinkedActor *parent;int one;
a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;a->b36=parent->b36;
a->sdc.b12c=one;a->b36=14;
a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
func_0c029e70(a,27,16);
}
void func_0c19ef74(struct LinkedActor *a)
{
struct LinkedActor *parent;int one;
a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;a->b36=parent->b36;
a->sdc.b12c=one;a->b36=14;
a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
a->f52+=a->p24->sdc.w130?-48:48;func_0c029e70(a,27,a->p24->s28);
}
void func_0c19f04a(struct LinkedActor *a)
{
struct LinkedActor *parent;int one;
a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;a->b36=parent->b36;
a->sdc.b12c=one;a->b36=14;
a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
a->f96=a->p24->f56;a->s28=120;func_0c0344a0(a->p24,38);func_0c029e70(a,27,9);
}
void func_0c19f0ec(struct LinkedActor *a)
{
struct LinkedActor *parent;int one;
a->b4++;parent=a->p24;a->sdc=parent->sdc;one=1;a->sdc.b12c=one;
a->b2=parent->b2;a->b1=parent->b1;a->v80.x=parent->v80.x;a->v80.y=parent->v80.y;
a->b1a3=parent->b1a3;a->b1a4=parent->b1a4;a->b48=parent->b48;a->v80=parent->v80;a->b36=parent->b36;
a->sdc.b12c=one;a->b36=15;
a->f52=a->p24->f52;a->f56=a->p24->f56;a->f60=a->p24->f60;
a->f52+=a->p24->sdc.w130?110.0f:-110.0f;a->f56-=17.142857f;a->s28=120;func_0c029e70(a,27,10);
}
