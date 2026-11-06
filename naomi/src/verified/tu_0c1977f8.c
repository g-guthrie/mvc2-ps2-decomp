#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern void (*table_0c2580f4[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c2580fc[])(struct LinkedActor *,struct LinkedActor *);
extern void (*table_0c258108[])(struct LinkedActor *);
void func_0c197836(struct LinkedActor *);
struct LinkedActor *func_0c1977f8(struct LinkedActor *owner,int mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,3,0))){a->w38=0xe02;a->b32=mode;a->b33=1;a->p16=func_0c197836;a->p24=owner;a->p20=owner;}return a;}
void func_0c197836(register struct LinkedActor *a){table_0c2580f4[a->b32](a,a->p24);}
void func_0c19784c(struct LinkedActor *a,struct LinkedActor *owner){table_0c2580fc[a->b4](a,owner);}
void func_0c19785e(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->b4++;a->b36=12;func_0c02a0c4(a,23,19);
}
void func_0c1978c4(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSub2a4 *state=&A(owner)->sub2a4;
 if(owner->b1d0==28 || owner->b5 || A(owner)->b1e9!=4 || ((signed char *)state)[4]<0){a->b4=2;a->sdc.b12c=0;return;}
 a->b36=12;a->f52=owner->f52;a->f56=A(owner)->f41c;
}
void func_0c19790c(struct LinkedActor *a){func_0c037688(a);}
void func_0c197912(struct LinkedActor *a){table_0c258108[a->b4](a);}
