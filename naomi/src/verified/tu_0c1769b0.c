#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c176b2c(struct LinkedActor *);
struct LinkedActor *func_0c1769b0(struct LinkedActor *owner,char mode,char value)
{
 struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c176b2c;a->p24=owner;a->s28=owner->sdc.w158.short_value;a->b32=mode;a->b33=value;a->w38=0x3002;}return a;
}
void func_0c176a00(struct LinkedActor *source)
{
 struct LinkedActor *a;if((a=func_0c0374da(0,1,0))){a->p16=func_0c176b2c;a->p24=source->p24;a->s28=source->p24->sdc.w158.short_value;a->b32=3;a->b33=source->b33;a->b34=source->b34;a->b5=source->b5;a->w38=0x3002;}
}
struct LinkedActor *func_0c176a48(struct LinkedActor *owner,struct LinkedActor *source,int value)
{
 struct LinkedActor *a;if((a=func_0c0374da(0,1,1))){a->p16=func_0c176b2c;a->b32=5;a->p24=owner;a->p20=source;a->wcc.dword_value=(unsigned int)source->p24;((int *)a->pad10)[0]=value;a->w38=0x3002;}return a;
}
struct LinkedActor *func_0c176a90(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,1))){
 a->p16=func_0c176b2c;a->b32=4;a->p24=owner;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 }return a;
}
