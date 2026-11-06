#include "objects.h"
extern struct ActorMotionFloat2 dat_0c24ead0[],dat_0c24ead4[],dat_0c24eb10[],dat_0c24eb14[],dat_0c24eaf0[],dat_0c24eaf4[];
extern void (*table_0c24eb48[])(struct Actor *),(*table_0c24eb50[])(struct Actor *),(*table_0c24eb58[])(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,char),func_0c037688(struct Actor *);
extern char func_0c02a026(struct Actor *);
void func_0c139fd4(struct Actor *);
void func_0c139cf4(struct Actor *a)
{
 a->b12c=1;a->b36=11;a->s28=8;
 a->f92=a->w130?dat_0c24ead0[a->b33].x:-dat_0c24ead0[a->b33].x;
 a->f96=dat_0c24ead4[a->b33].x;func_0c02a0c4(a,21,a->b33+29);
}
void func_0c139d58(struct Actor *a)
{
 a->b36=11;
 a->f52+=a->w130?dat_0c24eb10[a->b33].x:-dat_0c24eb10[a->b33].x;
 a->f56+=dat_0c24eb14[a->b33].x;func_0c02a0c4(a,21,a->b33+45);
}
void func_0c139dca(struct Actor *a)
{
 if(((struct LinkedActor *)a)->p24->b5){func_0c139fd4(a);return;}
 goto dispatch;dispatch:table_0c24eb48[a->b32](a);
}
void func_0c139dee(struct Actor *a){table_0c24eb50[a->b5](a);}
void func_0c139e20(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!--a->s28){a->b5++;func_0c02a0c4(a,21,a->b33+33);}
}
void func_0c139e8c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0)func_0c139fd4(a);
}
void func_0c139ee4(struct Actor *a){table_0c24eb58[a->b5](a);}
void func_0c139ef6(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b5++;a->f92=a->w130?dat_0c24eaf0[a->b33].x:-dat_0c24eaf0[a->b33].x;a->f96=dat_0c24eaf4[a->b33].x;func_0c02a0c4(a,21,a->b33+41);}
}
void func_0c139f7c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(func_0c02a026(a)<0)func_0c139fd4(a);
}
void func_0c139fd4(struct Actor *a){a->b4++;a->b12c=0;func_0c037688(a);}
