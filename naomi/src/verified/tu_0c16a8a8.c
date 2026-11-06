#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern union LinkedActorWcc *dat_0c2fb3c0;
extern char dat_0c2521f0[],dat_0c2521f4[];
extern void (*table_0c2521e4[])(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,char),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
void func_0c16aa1c(struct LinkedActor *);
void func_0c16a8a8(struct LinkedActor *a){dat_0c2fb3c0->short_value=a->p24->sdc.w158.short_value;a->b36=0;func_0c02a0c4(a,21,36);}
void func_0c16a8c2(struct LinkedActor *a){table_0c2521e4[a->b32](a);}
void func_0c16a8d6(struct LinkedActor *a)
{
 a->pad11[0]=66;a->pad11[1]=66;a->b36=0;a->f52=a->p24->f52;a->f56=a->p24->f56;a->f52+=A(a->p24)->b1d2?120.0f:-120.0f;
 if(dat_0c2fb3c0->short_value!=a->p24->sdc.w158.short_value){func_0c16aa1c(a);return;}
 func_0c02a026(a);func_0c037d0c(a);
}
void func_0c16a94c(struct LinkedActor *a)
{
 a->b36=0;a->f52=a->p24->f52;a->f56=a->p24->f56;
 if(dat_0c2fb3c0->short_value!=a->p24->sdc.w158.short_value){func_0c16aa1c(a);return;}
 if(A(a)->b140!=A(a->p24)->b140)func_0c02a0c4(a,21,dat_0c2521f0[(char)A(a->p24)->b140>>1]);
}
void func_0c16a9a0(struct LinkedActor *a)
{
 a->b36=0;a->f52=a->p24->f52;a->f56=a->p24->f56;
 if(dat_0c2fb3c0->short_value!=a->p24->sdc.w158.short_value){func_0c16aa1c(a);return;}
 if(A(a)->b140!=A(a->p24)->b140)func_0c02a0c4(a,21,dat_0c2521f4[(char)A(a->p24)->b140>>1]);
}
void func_0c16aa1c(struct LinkedActor *a){a->b6++;a->sdc.b12c=0;func_0c037688(a);}
