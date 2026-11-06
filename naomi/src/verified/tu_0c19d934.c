#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern short *dat_0c2fb3e8;
extern void func_0c0346da(struct LinkedActor *,int),func_0c029e70(struct LinkedActor *,int,int),func_0c19ee84(struct LinkedActor *),func_0c029fc4(struct LinkedActor *);
extern void (*table_0c258a5c[])(struct LinkedActor *);
void func_0c19d934(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->b36=0;
 a->f52=a->p24->f52;a->f56=a->p24->f56;*dat_0c2fb3e8=a->p24->sdc.w158.short_value;
 if(a->b33)func_0c0346da(a,75);
 A(a)->f264=0.75f;func_0c029e70(a,27,a->b33+5);
}
void func_0c19d9e8(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 if(owner->b5 || owner->b1d0!=21 || A(owner)->b1e9!=4 || !owner->sdc.b141){func_0c19ee84(a);return;}
 func_0c029fc4(a);a->f52=a->p24->f52;a->f56=a->p24->f56;
}
void func_0c19da38(struct LinkedActor *a){table_0c258a5c[a->b4](a);}
