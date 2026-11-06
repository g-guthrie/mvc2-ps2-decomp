#include "objects.h"
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *),func_0c0451f2(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c0344a0(struct Actor *,int),func_0c19715c(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern float dat_0c242a44[];
extern void (*table_0c242b7c[])(struct Actor *,struct ActorSub2a4 *);
void func_0c08fb78(struct Actor *a)
{
 int zero,command,base;
 a->b6++;a->s28=1;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0442fa(a);func_0c048bb0(a,5);
 zero=0;
 if(a->b1f9!=2){a->f56=a->f41c;a->b1f9=zero;base=0;command=40;func_0c0432ca(a);}
 else{base=2;command=45;}
 a->b1a1=command;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,21,a->b1a3+base);
}
void func_0c08fc12(struct Actor *a)
{
 float offset;
 float *row;
 func_0c02a026(a);
 if(a->b141){a->b6++;if(a->b1f9!=2)func_0c19715c(a,1,0);
 offset=-53.3333321f;if(a->b1d2)offset=53.3333321f;a->f52+=offset;
 row=dat_0c242a44;if(a->b1f9==2)row+=4;
 row+=(unsigned char)a->b1a3*2;a->f92=*row++;a->f96=*row;a->f104=0;a->f108=-1.60714281f;
 if(a->b1d2)a->f92=-a->f92;
 func_0c19715c(a,0,0);func_0c0344a0(a,20);func_0c0451f2(a);
 }
}
void func_0c08fcfe(struct Actor *a)
{
 int zero;
 a->b1f5=2;func_0c02a026(a);zero=0;
 if(a->b19e && a->s28){a->s28=zero;a->b14b=zero;}
 if(!a->s28 && a->b14b){a->b1a1=a->b14b;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;a->b14b=zero;}
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){a->b6++;a->f56=a->f41c;a->b1f9=1;a->b1f5=zero;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c043324(a);func_0c02a0c4(a,21,4);}
}
void func_0c08fde8(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 else if(a->b141){a->b141=0;func_0c19715c(a,1,0);}
}
void func_0c08fe22(struct Actor *a){table_0c242b7c[a->b6](a,&a->sub2a4);}
