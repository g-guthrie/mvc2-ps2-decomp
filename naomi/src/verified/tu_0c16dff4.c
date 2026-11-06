#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern short dat_0c25257c[];
extern int *dat_0c2525b8[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern int func_0c02849a(void);
extern void func_0c037d0c(struct LinkedActor *),func_0c02a0c4(struct LinkedActor *,int,int);
void func_0c16dff4(struct LinkedActor *record)
{
 struct LinkedActor *a=record;
 struct LinkedActor *owner;
 unsigned int zero=0;int index,*velocity,effect;register float dx,dy,divisor;float scale_x;
 record=a->p20;owner=record;a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->pad11[0]=66;a->pad11[1]=66;a->b36=zero;A(a)->w130=A(owner)->w130;
 ((struct MeActor *)a)->blk_dc.b13c=16;((struct MeActor *)a)->blk_dc.b13d=16;((struct MeActor *)a)->blk_dc.b13e=16;((struct MeActor *)a)->blk_dc.b13f=16;a->s28=20;
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 index=(unsigned char)a->b33*2;record=(struct LinkedActor *)(dat_0c25257c+index);dx=((short *)record)[0];dy=((short *)record)[1];record=(struct LinkedActor *)(dat_0c2525b8[a->b32]+index);velocity=(int *)record;
 scale_x=1.66666663f;divisor=65536.0f;A(a)->f92=*velocity++*scale_x/divisor;a->f96=*velocity*2.1428571f/divisor;
 if(A(a)->w130){dx=-dx;A(a)->f92=-A(a)->f92;}
 a->f52+=dx*scale_x;a->f56+=dy*2.1428571f;
 if(!a->b32)effect=50;else effect=(func_0c02849a()&1)+57;
 A(a)->b1a1=effect;A(a)->w1ac=zero;*(unsigned char *)&A(a)->b19e=zero;A(a)->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c037d0c(a);func_0c02a0c4(a,23,9);
}
