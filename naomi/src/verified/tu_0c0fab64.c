/* Exact 0x0c0fab64..0x0c0fac3c: select stance and limb attack tables and start the attack animation. */
#include "objects.h"
extern void func_0c044cbc(struct Actor *),func_0c02a0c4(struct Actor *,char,char);
extern void *dat_0c24a8d8[];
extern char dat_0c24aa14[],dat_0c24aa08[],dat_0c24aa17[],dat_0c24aa23[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0fab64(struct Actor *a)
{
 unsigned char row;unsigned int zero;
 func_0c044cbc(a);row=a->b1e8;
 if(a->b1f9==1)row+=6;
 if(a->b1fe)row+=3;
 a->p3f4=dat_0c24a8d8[row%6];
 a->b1a7=dat_0c24aa14[a->b1e8];a->b1a1=dat_0c24aa08[row];
 zero=0;a->w1ac=zero;*(unsigned char *)&a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,dat_0c24aa23[row],dat_0c24aa17[row]);
 if(!a->b1fe){*(int *)((char *)a+0x2ec)=32;*(int *)((char *)a+0x2f0)=*(unsigned short *)&a->b158;}
}
