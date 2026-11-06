#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c044cbc(struct Actor *),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int),func_0c048bb0(struct Actor *,int),func_0c1b2e10(struct Actor *,int),func_0c0344a0(struct Actor *,int);
extern void (*table_0c249dd4[])(struct Actor *),(*table_0c249de0[])(struct Actor *);
extern void (*table_0c249dec[])(struct Actor *,struct ActorSub2a4 *);

void func_0c0ed56c(struct Actor *a)
{
 int zero=0;
 if(!a->b6){
  func_0c044cbc(a);a->b6++;a->b1f9=zero;func_0c02a0c4(a,20,5);
  a->b1a1=70;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
  dat_0c2f83f8->arr[a->b2]++;
  func_0c0346da(a,22);func_0c048bb0(a,5);
 }
 if(a->b1ff==3)func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=zero;func_0c1b2e10(a,1);}
}
void func_0c0ed650(struct Actor *a)
{
 func_0c043352(a);table_0c249dd4[a->b6](a);
}
void func_0c0ed66c(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){
  a->b6++;a->s28=28;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  a->f92=a->b1d2?15.83333302f:-15.83333302f;
  a->f104=a->b1d2?-0.3125f:0.3125f;
 }
}
void func_0c0ed708(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;
 if(--a->s28<0){
  a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  a->f92=a->b1d2?1.66666663f:-1.66666663f;
  func_0c02a0c4(a,2,2);
 }
}
void func_0c0ed77c(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;
 if(func_0c02a026(a)>=0)return;
 func_0c0437b8(a);
}
void func_0c0ed7ba(struct Actor *a){table_0c249de0[a->b6](a);}
void func_0c0ed7cc(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141==0){
  a->b6=a->b6+1;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  a->f92=a->b1d2?-15.83333302f:15.83333302f;
  a->f104=a->b1d2?0.3125f:-0.3125f;a->s28=28;
 }
}
void func_0c0ed854(struct Actor *a)
{
 func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(--a->s28<0){a->b6++;func_0c02a0c4(a,2,3);}
}
void func_0c0ed8c2(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c0ed8e4(struct Actor *a){table_0c249dec[a->b6](a,&a->sub2a4);}
void func_0c0ed8fa(struct Actor *a,struct ActorSub2a4 *p)
{
 a->b6++;func_0c0344a0(a,22);a->b12c=0;*(unsigned char *)&p->w4=1;
 a->f56=a->f41c+171.42856f;func_0c02a0c4(a,18,0);
}
