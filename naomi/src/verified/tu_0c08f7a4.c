#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c242b30[])(struct Actor *);
void func_0c08f7a4(struct Actor *a)
{
 int zero;
 if(!a->b6){
 a->b6++;
 zero=0;a->b1f9=zero;a->b1a1=18;
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c044cbc(a);func_0c048bb0(a,5);func_0c0346da(a,21);func_0c02a0c4(a,20,4);
 }
 if(a->b1ff==3)func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c08f86a(struct Actor *a)
{
 table_0c242b30[a->b6](a);
}
void func_0c08f87c(struct Actor *a)
{
 func_0c02a026(a);
 if(!a->b141){
 a->b6++;
 a->f92=-15.83333302f;a->f104=0.3125f;
 a->s30=24;
 if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 a->f96=0;a->f108=0;
 }
}
