#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c029e70(struct LinkedActor *,int,int),func_0c0288a8(struct LinkedActor *,int),func_0c037688(struct LinkedActor *);
extern char func_0c029fc4(struct LinkedActor *);
extern int func_0c02850e(struct LinkedActor *);
void func_0c1acc0a(struct LinkedActor *);
void func_0c1acb58(struct LinkedActor *a)
{
 struct LinkedActor *owner;
 a->b4++;a->w38=0x1c06;owner=a->p24;a->sdc=owner->sdc;a->sdc.b12c=1;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;
 a->b36=owner->b36;
 A(a)->b13c=32;A(a)->b13d=32;A(a)->b13e=32;A(a)->b13f=32;
 a->s28=120;a->b36=0;a->f104=0.0f;a->f108=0.0f;
 if(a->b32&1)func_0c0288a8(a,100);else func_0c0288a8(a,200);
 func_0c029e70(a,27,16);
 func_0c1acc0a(a);
}
void func_0c1acc0a(struct LinkedActor *a)
{
 if(--a->s28==0||!func_0c02850e(a)){a->b4++;a->sdc.b12c=0;return;}
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c029fc4(a);
}
void func_0c1acc80(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;}
void func_0c1acc8e(struct LinkedActor *a){func_0c037688(a);}
