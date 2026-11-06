/* Attached effect allocation, state dispatch, and ballistic initialization. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern short *dat_0c2fb3fc;
extern void (*table_0c2590c4[])(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,int,int);
void func_0c1a5074(struct LinkedActor *);
struct LinkedActor *func_0c1a5048(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,3,0))){a->p16=func_0c1a5074;a->p24=owner;a->w38=0x1607;}return a;
}
void func_0c1a5074(struct LinkedActor *a){dat_0c2fb3fc=(short *)&a->wcc;table_0c2590c4[a->b4](a);}
void func_0c1a5090(struct LinkedActor *a)
{
 float zero;
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->b36=7;a->f52=a->p24->f52;a->f56=a->p24->f56;
 a->f52+=a->sdc.w130?65.0:-65.0;
 a->f56+=231.42856;
 zero=0.0f;a->f92=zero;a->f104=zero;
 a->f96=2.1428571f;a->f108=-0.5357143f;
 func_0c029e70(a,27,18);
 *dat_0c2fb3fc=a->p24->sdc.w158.short_value;
}
