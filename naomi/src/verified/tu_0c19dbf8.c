#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern short *dat_0c2fb3e8;
extern char func_0c029fc4(struct LinkedActor *);
extern void func_0c029e70(struct LinkedActor *,int,int),func_0c19ee84(struct LinkedActor *);
extern void (*table_0c258a7c[])(struct LinkedActor *);
extern float table_0c258a8c[][2];
extern float table_0c258a90[][2];
void func_0c19dbf8(struct LinkedActor *a)
{
 a->f52=a->p24->f52;a->f56=a->p24->f56;
 if(!a->b5){
  func_0c029fc4(a);
  if(*dat_0c2fb3e8==a->p24->sdc.w158.short_value)goto done;
  a->b5++;func_0c029e70(a,27,a->b33+12);return;
 }else if(func_0c029fc4(a)<0){func_0c19ee84(a);return;}
 done:;
}
void func_0c19dc5e(struct LinkedActor *a){table_0c258a7c[a->b4](a);}
void func_0c19dc70(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;a->v80=a->p24->v80;a->b36=a->p24->b36;a->b36=0;
 A(a)->f92=a->sdc.w130?table_0c258a8c[(unsigned char)a->b33][0]:-table_0c258a8c[(unsigned char)a->b33][0];
 A(a)->f96=table_0c258a90[(unsigned char)a->b33][0];
 a->f52=a->p24->f52+A(a)->f92;a->f56=a->p24->f56+A(a)->f96;
 func_0c029e70(a,27,14);
}
