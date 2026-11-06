#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c0437b8(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c043014(struct Actor *,struct LinkedActorVec3 *),func_0c0346da(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c2496e0[])(struct Actor *),(*table_0c2496e8[])(struct Actor *);
void func_0c0e6d2c(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c043324(a);func_0c02a0c4(a,22,14);}
}
void func_0c0e6dba(struct Actor *a){if(func_0c02a026(a)<0){a->b1f9=1;func_0c0437b8(a);}}
void func_0c0e6de0(struct Actor *a){table_0c2496e0[a->b6](a);}
void func_0c0e6df2(struct Actor *a)
{
 int zero=0;a->b6++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->b1f9=zero;a->f56=a->f41c;func_0c02a39a(a,zero);func_0c0442fa(a);func_0c0432ca(a);
 a->b1a1=94;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,21,28);
}
void func_0c0e6e68(struct Actor *a)
{
 int zero;struct LinkedActorVec3 p;
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 zero=0;if(a->b141&1){a->b141=zero;p.x=25;p.y=162.857132f;p.z=0;func_0c043014(a,&p);}
 else if(a->b141&2){a->b141=zero;func_0c0346da(a,22);}
}
void func_0c0e6efe(struct Actor *a)
{
 if(!a->b6){a->b6++;a->b1f9=0;a->f56=a->f41c;func_0c02a0c4(a,20,2);}
 else if(func_0c02a026(a)<0){func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}
}
void func_0c0e6f62(struct Actor *a){table_0c2496e8[a->b6](a);}
void func_0c0e6f74(struct Actor *a)
{
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}a->b6++;func_0c0442fa(a);a->f56=a->f41c;a->b1f9=0;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1a1=98;a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;func_0c0432ca(a);func_0c02a0c4(a,22,15);
}
