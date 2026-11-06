/* Stance/limb attack selection with conditional animation overrides. */
#include "objects.h"
extern void func_0c044cbc(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c02a684(struct Actor *,int,int,int),func_0c1bc460(struct Actor *,int);
extern unsigned char dat_0c24d2cb[],dat_0c24d2b0[],dat_0c24d2a4[];
extern char dat_0c24d2b3[],dat_0c24d2bf[];
extern void *dat_0c24d18c[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c11ef44(struct Actor *a){
 unsigned char index;int zero;
 func_0c044cbc(a);zero=0;a->b7=zero;a->b6=zero;
 index=a->b1e8;if(a->b1f9==1)index+=6;if(a->b1fe)index+=3;
 a->l320=dat_0c24d2cb[index];a->p3f4=dat_0c24d18c[index%6];
 a->b1a7=dat_0c24d2b0[a->b1e8];a->b1a1=dat_0c24d2a4[index];
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,dat_0c24d2bf[index],dat_0c24d2b3[index]);
 if(index==5){if(a->w1fa&0x400){
 a->b1a1=19;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,8,3);
 }}
 if(index==2)func_0c02a684(a,1,11,1);
 if(index==7)func_0c1bc460(a,2);
}
