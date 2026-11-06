#include "objects.h"
#define A(a) ((struct Actor *)(a))
#define COLOR(a) (*(unsigned int *)&((struct MeActor *)(a))->blk_dc.b13c)
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c1d53e4(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void (*table_0c2572e8[])(struct LinkedActor *,struct LinkedActor *),(*table_0c2572f8[])(struct LinkedActor *,struct LinkedActor *),(*table_0c257304[])(struct LinkedActor *,struct LinkedActor *);
void func_0c18f460(struct LinkedActor *);
struct LinkedActor *func_0c18f420(struct LinkedActor *owner,char mode)
{struct LinkedActor *a;if((a=func_0c0374da(0,3,1))){a->p16=func_0c18f460;a->p24=owner;a->b1=owner->b1;a->b32=mode;a->w38=0x303;}return a;}
void func_0c18f460(register struct LinkedActor *a)
{struct LinkedActor *owner=a->p24;a->b36=owner->b36;table_0c2572e8[a->b4](a,owner);}
void func_0c18f47c(struct LinkedActor *a,struct LinkedActor *owner)
{a->b4++;a->sdc.b12c=0;
 a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 table_0c2572f8[a->b32](a,owner);func_0c1d53e4(a);a->pad0=1;}
void func_0c18f4fc(struct LinkedActor *a,struct LinkedActor *owner)
{a->sdc.b12c=1;a->f52=owner->f52+(a->b2?-106.666664124f:106.666664124f);a->f56=owner->f56+548.5714111328125f;
 COLOR(a)=0x20202424u;A(a)->f96=-12.857142448425293f;A(a)->f108=0.13392857f;func_0c02a0c4(a,18,3);}
void func_0c18f544(struct LinkedActor *a,struct LinkedActor *owner)
{a->f52=owner->f52+(owner->sdc.w130?-93.33333f:93.33333f);a->f56=A(owner)->f41c;
 A(a)->f92=0;A(a)->f104=0;A(a)->f96=4.285714149475098f;A(a)->f108=-0.5357143f;COLOR(a)=0x60003030u;func_0c02a0c4(a,20,6);}
void func_0c18f5d8(struct LinkedActor *a,struct LinkedActor *owner)
{a->f52=owner->f52+(a->sdc.w130?106.666664124f:-106.666664124f);a->f56=owner->f56+411.4285583496094f;COLOR(a)=0x20202424u;
 A(a)->f96=-12.857142448425293f;A(a)->f108=0.13392857f;func_0c02a0c4(a,19,6);}
void func_0c18f61c(struct LinkedActor *a,struct LinkedActor *owner){table_0c257304[a->b32](a,owner);}
void func_0c18f630(struct LinkedActor *a,struct LinkedActor *owner)
{a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 if(a->f56>A(owner)->f41c){func_0c02a026(a);return;}
 a->f56=A(owner)->f41c;a->b5++;func_0c02a0c4(a,18,4);}
void func_0c18f674(struct LinkedActor *a)
{if(func_0c02a026(a)<0){a->b5++;a->s28=32;A(a)->f92=a->b2?3.3333333f:-3.3333333f;A(a)->f104=0;}}
void func_0c18f6ae(struct LinkedActor *a,struct LinkedActor *owner)
{if(owner->b6<2)return;a->b5++;func_0c02a0c4(a,18,5);}
