#include "objects.h"
extern void func_0c044cbc(struct Actor *),func_0c02a0c4(struct Actor *,int,char),func_0c18b864(struct Actor *,int);
extern unsigned char dat_0c24e053[];
extern char dat_0c24e038[],dat_0c24e02c[],dat_0c24e03b[],dat_0c24e047[];
extern void *dat_0c24df04[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c12e920(struct Actor *a)
{
 int zero;unsigned char index;
 func_0c044cbc(a);zero=0;a->b6=a->b7=zero;
 index=a->b1e8;if(a->b1f9==1)index+=6;if(a->b1fe)index+=3;
 a->l320=dat_0c24e053[index];a->p3f4=dat_0c24df04[index%6];a->b1a7=dat_0c24e038[a->b1e8];
 a->b1a1=dat_0c24e02c[index];a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,dat_0c24e047[index],dat_0c24e03b[index]);
 if(a->b141){func_0c18b864(a,a->b141-1);a->b141=zero;}
 if(a->b140){func_0c18b864(a,*(char *)&a->b140-1);a->b140=zero;}
}
