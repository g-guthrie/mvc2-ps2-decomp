#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c037d0c(struct Actor *),func_0c037688(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c17d0ec(struct Actor *);
void func_0c17d004(struct Actor *a,struct Actor *owner)
{
 unsigned int zero=0;
 a->b36=owner->b36;a->f52=owner->f52+a->f92;a->f56=owner->f56+a->f96;a->b19f=zero;
 if(owner->b5 ||owner->b1d0!=29)goto cleanup;
 if(owner->b6>=3){if(!a->b5){goto enter_state;enter_state:a->b5++;a->b12c=1;func_0c02a0c4(a,23,2);}}
 if(!a->b5)func_0c02a026(a);
 else if(func_0c02a026(a)<0){cleanup:a->b4++;a->b12c=zero;return;}
 if(a->b141){a->b1a1=a->b141;a->w1ac=zero;a->b19e=zero;a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;a->b141=zero;}
 func_0c17d0ec(a);func_0c037d0c(a);
}
void func_0c17d0d8(struct Actor *a){a->b4++;a->b12c=0;}
void func_0c17d0e6(struct Actor *a){func_0c037688(a);}
void func_0c17d0ec(struct Actor *a)
{
 struct Actor *owner=(struct Actor *)((struct LinkedActor *)a)->p24;
 struct Actor *other=(struct Actor *)owner->p20c;
 if(!a->b5){float distance=other->f52-a->f52;if(!owner->w130)distance=-distance;if(distance>80.0f)a->w1ac=16;}
}
