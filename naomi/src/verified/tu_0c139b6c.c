#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern struct ActorSub2a4 *dat_0c2fb330;
extern unsigned int *dat_0c2fb32c;
extern void (*table_0c24eb30[])(struct LinkedActor *),(*table_0c24eb40[])(struct LinkedActor *);
void func_0c139c18(struct LinkedActor *);
struct LinkedActor *func_0c139b6c(struct LinkedActor *owner,unsigned char choice)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c139c18;a->p24=owner;a->b32=choice;a->b33=0;a->w38=0x505;a->f52=owner->f52;a->f56=owner->f56;}
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c139c18;a->p24=owner;a->b32=choice;a->b33=1;a->w38=0x505;a->f52=owner->f52;a->f56=owner->f56;}
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c139c18;a->p24=owner;a->b32=choice;a->b33=3;a->w38=0x505;a->f52=owner->f52;a->f56=owner->f56;}
 return a;
}
void func_0c139c18(struct LinkedActor *a)
{
 dat_0c2fb330=&((struct Actor *)a->p24)->sub2a4;dat_0c2fb32c=&a->wcc.dword_value;table_0c24eb30[a->b4](a);
}
void func_0c139c3e(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 ((struct Actor *)a)->f104=0.0f;((struct Actor *)a)->f108=0.0f;table_0c24eb40[a->b32](a);
}
