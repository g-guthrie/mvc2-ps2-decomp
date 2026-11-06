#include "objects.h"
extern void func_0c044cbc(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c0b8504(struct Actor *a)
{
 int status,zero;
 func_0c044cbc(a);zero=0;
 switch(a->b1e8){
 case 0:a->b159=9;a->b158=zero;status=6;break;
 case 1:a->b159=9;a->b158=1;status=7;break;
 case 2:a->b159=9;a->b158=2;status=8;break;
 case 3:a->b159=10;a->b158=zero;status=9;break;
 case 4:a->b159=10;a->b158=1;status=10;break;
 case 5:a->b159=10;a->b158=2;status=11;break;
 case 6:a->b159=7;a->b158=zero;status=0;break;
 case 7:a->b159=7;a->b158=1;status=1;break;
 case 8:a->b159=7;a->b158=2;status=2;break;
 case 9:a->b159=8;a->b158=zero;status=3;break;
 case 10:a->b159=8;a->b158=1;status=4;break;
 case 11:a->b159=8;a->b158=2;status=5;break;
 }
 a->b1a1=status;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,a->b159,a->b158);
}
