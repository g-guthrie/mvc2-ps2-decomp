#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern struct ActorSub2a4 *dat_0c2fb318;
extern unsigned int *dat_0c2fb314;
extern void (*table_0c24e798[])(struct LinkedActor *),(*table_0c24e7a8[])(struct LinkedActor *);
void func_0c1375b2(struct LinkedActor *);
struct LinkedActor *func_0c137500(struct LinkedActor *owner,unsigned char choice)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c1375b2;a->p24=owner;a->b32=choice;a->w38=0x502;}
 return a;
}
struct LinkedActor *func_0c137534(struct LinkedActor *owner)
{
 struct LinkedActor *a;int i;unsigned char mode;
 mode=2;
 for(i=0;i<8;i++){if(!(a=func_0c0374da(0,1,0)))break;a->p16=func_0c1375b2;a->p24=owner;a->b32=mode;a->b33=i;a->w38=0x502;}
 i=0;mode=1;
 for(;i<8;i++){if(!(a=func_0c0374da(0,1,0)))break;a->p16=func_0c1375b2;a->p24=owner;a->b32=mode;a->b33=i;a->w38=0x502;}
 return a;
}
void func_0c1375b2(struct LinkedActor *a)
{
 dat_0c2fb318=&((struct Actor *)a->p24)->sub2a4;dat_0c2fb314=&a->wcc.dword_value;table_0c24e798[a->b4](a);
}
void func_0c1375d8(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.w130=a->p24->sdc.w130;table_0c24e7a8[a->b32](a);
}
