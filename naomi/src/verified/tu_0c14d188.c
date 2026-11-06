/* Pulsing actor handlers and their dispatcher sharing one literal pool. */
#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern void func_0c037d0c(struct Actor *);
extern void (*table_0c25031c[])(struct Actor*);
void func_0c14d188(struct Actor *a)
{
 if(dat_0c2d6f84->flags%14==0&&a->b35<=3){a->b19c=66;a->b19d=66;a->b1a1=63;a->w1ac=0;a->b19e=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;}
 func_0c02a026(a);
 a->f84+=0.200000003f;
 if(!(1.0f>a->f84))a->b36=11;
 if(a->f84>=2.0f){a->f84=0;a->b36=10;a->s30--;if(a->s30==0)a->b4++;}
 a->f80=1.0f;
 if(!(dat_0c2d6f84->flags&1))a->f80=0.800000012f;
 func_0c037d0c(a);
}
void func_0c14d242(struct Actor *a){struct Actor *record=a;table_0c25031c[record->b5](record);}
void func_0c14d254(struct Actor *a)
{
 func_0c02a026(a);
 a->f84+=0.200000003f;
 if(!(1.0f>a->f84))a->b36=11;
 if(a->f84>=2.0f){a->f84=0;a->b36=10;a->s30--;if(a->s30==0)a->b5++;}
 a->f80=1.0f;
 if(!(dat_0c2d6f84->flags&1))a->f80=0.800000012f;
}

