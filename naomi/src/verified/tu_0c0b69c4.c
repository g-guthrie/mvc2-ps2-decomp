#include "objects.h"
extern void func_0c044cbc(struct Actor *),func_0c02a0c4(struct Actor *,int,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
/* b1e8 selects one of the twelve animation states; 6a18 is switch case0, not an independent entry. */
void func_0c0b69c4(struct Actor *a)
{
 int animation;
 func_0c044cbc(a);
 switch(a->b1e8){
 case 0: a->b159=9;a->b158=0;animation=6;break;
 case 1: a->b159=9;a->b158=1;animation=7;break;
 case 2: a->b159=9;a->b158=2;animation=8;break;
 case 3: a->b159=10;a->b158=0;animation=9;break;
 case 4: a->b159=10;a->b158=1;animation=10;break;
 case 5: a->b159=10;a->b158=2;animation=11;break;
 case 6: a->b159=7;a->b158=0;animation=0;break;
 case 7: a->b159=7;a->b158=1;animation=1;break;
 case 8: a->b159=7;a->b158=2;animation=2;break;
 case 9: a->b159=8;a->b158=0;animation=3;break;
 case 10: a->b159=8;a->b158=1;animation=4;break;
 case 11: a->b159=8;a->b158=2;animation=5;break;
 }
 a->b1a1=animation;a->w1ac=0;a->b19e=0;*(void **)&a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,a->b159,a->b158);
}
