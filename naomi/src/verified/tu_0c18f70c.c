#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a684(struct LinkedActor *,int,int,int),func_0c02a0c4(struct LinkedActor *,int,int);
extern int table_0c257310[];
extern void (*table_0c257328[])(struct LinkedActor *,struct LinkedActor *);
void func_0c18f70c(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c02a026(a);
 if(A(a)->b140){A(a)->b140=0;func_0c02a684(owner,1,table_0c257310[owner->b37]+A(a)->b14b,1);
 if(--a->s28==0)a->b4++;
 a->f52+=A(a)->f92;A(a)->f92+=A(a)->f104;}
}
void func_0c18f77e(register struct LinkedActor *a,struct LinkedActor *owner)
{a->b49=4;table_0c257328[(unsigned char)a->b5](a,owner);}
void func_0c18f798(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c02a026(a);
 if(A(a)->b140){a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 if(a->f56<A(owner)->f41c){a->f56=A(owner)->f41c;a->b5++;func_0c02a0c4(a,20,7);}}
}
void func_0c18f802(struct LinkedActor *a)
{
 if(func_0c02a026(a)<0){a->b5++;A(a)->f92=-13.33333302f;A(a)->f104=0;A(a)->f96=8.5714283f;A(a)->f108=0;
 if(!a->sdc.w130)A(a)->f92=-A(a)->f92;
 func_0c02a0c4(a,20,8);}
}
