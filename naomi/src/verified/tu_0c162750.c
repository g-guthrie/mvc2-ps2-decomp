#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *);
extern signed char func_0c02a026(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float dat_0c22f6e0[],dat_0c22f6f8[];
extern unsigned char dat_0c251604[];
extern void (*table_0c251608[])(struct LinkedActor *),(*table_0c251614[])(struct LinkedActor *);
void func_0c1628ca(struct LinkedActor *);
void func_0c162750(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;
 a->b2=a->p24->b2;a->b1=a->p24->b1;a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->sdc.b12c=1;a->b49=-8;a->b34=0;A(a)->b19c=66;A(a)->b19d=66;
 a->f52=dat_0c22f6e0[a->b32*2+0];a->f56=(dat_0c22f6e0+a->b32*2)[1];
 A(a)->f92=dat_0c22f6f8[a->b32*4+0];A(a)->f104=(dat_0c22f6f8+a->b32*4)[1];A(a)->f96=(dat_0c22f6f8+a->b32*4)[2];A(a)->f108=(dat_0c22f6f8+a->b32*4)[3];
 if(a->sdc.w130){a->f52=-a->f52;A(a)->f92=-A(a)->f92;A(a)->f104=-A(a)->f104;}
 a->f52+=a->p24->f52;a->f56+=a->p24->f56;
 A(a)->b1a1=dat_0c251604[a->b32];A(a)->w1ac=0;A(a)->b19e=0;A(a)->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,23,(signed char)a->b32+1);func_0c1628ca(a);
}
void func_0c1628ca(struct LinkedActor *a)
{
 a->b36=a->p24->b36;
 if(!a->b5){
 if(A(a)->b19e){a->b5++;func_0c02a0c4(a,23,10);return;}
 if(A(a)->b19f){a->b4++;a->sdc.b12c=0;return;}
 table_0c251608[a->b32](a);
 if(a->b34){a->sdc.b12c=a->b34&1;if(--a->b34==0)goto next;}else func_0c037d0c(a);
 }else if(func_0c02a026(a)<0){next:a->b4++;}
}
void func_0c162998(struct LinkedActor *a){table_0c251614[a->b6](a);}
void func_0c1629aa(struct LinkedActor *a)
{
 if(a->p24->b1d0!=20)a->b34=1;
 a->f56+=A(a)->f96;A(a)->f96+=A(a)->f108;
 if(a->f56<A(a->p24)->f41c){a->b6++;a->f56=A(a->p24)->f41c;}
}
