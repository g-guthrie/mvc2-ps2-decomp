#include "objects.h"
#define A(a) ((struct Actor *)(a))
struct LandingState172 {short frame,x,y;};
extern int func_0c028708(struct LinkedActor *),func_0c02849a(void);
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c0346da(struct LinkedActor *,int),func_0c1d330c(struct LinkedActor *,struct LinkedActorVec3 *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c252970[];
extern void (*table_0c252998[])(struct LinkedActor *,struct LinkedActor *);
void func_0c1726a4(register struct LinkedActor *a,struct LinkedActor *owner)
{
 register struct LandingState172 *landing=(struct LandingState172 *)&a->wcc;
 int zero=0;
 if(!func_0c028708(a))a->sdc.b12c=zero;else a->sdc.b12c=1;
 a->f56+=a->f96;a->f96+=A(a)->f108;func_0c02a026(a);
 if(a->f56>landing->y){
  a->b5++;A(a)->b1a1=64;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
  a->f52=landing->x;a->f52+=dat_0c252970[func_0c02849a()&15];
  a->f96=-34.2857132f;A(a)->f108=-0.2678571343422f;func_0c02a0c4(a,23,a->b33+34);
 }else{goto collision;collision:if(A(a)->b19f)a->b4++;else{goto draw;draw:func_0c037d0c(a);}}
}
void func_0c1727a0(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(!func_0c028708(a))a->sdc.b12c=0;else a->sdc.b12c=1;
 a->f56+=a->f96;a->f96+=A(a)->f108;func_0c02a026(a);
 if(a->f56<A(owner)->f41c)a->f56=A(owner)->f41c;
 else{goto contact;contact:if(!A(a)->b19f){goto draw_second;draw_second:func_0c037d0c(a);if(!A(a)->b19e)return;}}
 a->b4++;
}
void func_0c17284e(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c1d330c(a,(struct LinkedActorVec3 *)&a->f52,1,8);func_0c0346da(a,73);a->b4++;a->sdc.b12c=0;
}
void func_0c17287a(struct LinkedActor *a,struct LinkedActor *owner){table_0c252998[a->b4](a,owner);}
