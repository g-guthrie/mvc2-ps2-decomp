#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c044cbc(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0346da(struct Actor *,int),func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c24cd84[])(struct Actor *);
void func_0c11a52c(struct Actor *a)
{
 int zero=0;struct ActorSub2a4 *sub=&a->sub2a4;
 sub->byte16=8;
 if(!a->b6){func_0c044cbc(a);a->b6++;func_0c048bb0(a,5);
  if((unsigned char)a->b1fe==1){a->b1a1=53;a->b1f9=zero;func_0c02a0c4(a,20,0);
   a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;sub->s18=*(short *)&a->b158;}
 }
 if((unsigned char)a->b1ff==3)func_0c043352(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 if(a->b14b){func_0c0346da(a,22);a->b14b=zero;}
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c11a624(struct Actor *a){table_0c24cd84[a->b6](a);}
