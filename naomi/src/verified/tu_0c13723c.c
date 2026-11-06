#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern struct ActorSub2a4 *dat_0c2fb310;
extern unsigned int *dat_0c2fb30c;
extern void (*table_0c24e778[])(struct LinkedActor *),(*table_0c24e788[])(struct LinkedActor *);
void func_0c13727c(struct LinkedActor *);
struct LinkedActor *func_0c13723c(struct LinkedActor *record,unsigned char choice)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))){a->p16=func_0c13727c;a->p24=record->p24;a->p20=record;a->b32=choice;a->w38=0x501;}
 return a;
}
void func_0c13727c(struct LinkedActor *a)
{
 dat_0c2fb310=&((struct Actor *)a->p24)->sub2a4;dat_0c2fb30c=&a->wcc.dword_value;table_0c24e778[a->b4](a);
}
void func_0c1372a2(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;
 a->sdc.w130=a->p24->sdc.w130;table_0c24e788[a->b32](a);
}
void func_0c13732a(struct LinkedActor *a)
{
 struct LinkedActor *source=a->p20;a->b36=0;a->f52=source->f52;a->f56=source->f56;func_0c13723c(a,1);func_0c02a0c4(a,23,7);
}
