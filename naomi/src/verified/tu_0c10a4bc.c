#include "objects.h"
extern void func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char table_0c24b96c[][2];
void func_0c10a4bc(struct Actor *a)
{
 int zero=0,timer;
 a->b6++;*(int *)((char *)a+0x2f4)=4;
 a->b1a1=53;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c0442fa(a);func_0c0432ca(a);a->f56=a->f41c;a->b1f9=zero;a->b32=zero;*(int *)((char *)a+0x2cc)=96;
 timer=120;
 if(!a->b525||a->b411)timer=30;
 a->s28=timer;func_0c048bb0(a,10);
 func_0c02a0c4(a,21,table_0c24b96c[*(int *)((char *)a+0x2c0)][(unsigned char)a->b1a3]);
 *(int *)((char *)a+0x2d8)=a->b142;
}
