#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c24fa34[];
extern int func_0c02849a(void);
extern void func_0c02a18c(struct LinkedActor *,int,int,int);
extern void (*table_0c24fa50[])(struct Actor *,struct Actor *);
void func_0c144a30(struct Actor *,struct Actor *);
void func_0c1448d0(struct LinkedActor *a,struct LinkedActor *owner)
{
 union LinkedActorWcc *state=&a->wcc;short displacement;int zero,shade;
 a->b4++;a->sdc=owner->sdc;a->sdc.b12c=1;a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 zero=0;shade=16;goto colours;colours:a->sdc.b12c=1;a->b49=-1;((struct MeActor *)a)->blk_dc.b13c=((struct MeActor *)a)->blk_dc.b13d=((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=shade;
 ((struct Actor *)a)->b1a1=54;((struct Actor *)a)->w1ac=zero;((struct Actor *)a)->b19e=zero;*(void **)&((struct Actor *)a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;a->pad11[0]=68;a->pad11[1]=68;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 displacement=(short)(dat_0c24fa34[(unsigned char)a->b33&3]*1.66666663f);if(((struct Actor *)owner)->w130)displacement=-displacement;a->f52+=displacement;
 ((struct Actor *)a)->f92=-53.3333321f;((struct Actor *)a)->f104=6.66666651f;a->f96=5.35714245f;((struct Actor *)a)->f108=0.0f;
 if(((struct Actor *)owner)->w130){((struct Actor *)a)->f92=-((struct Actor *)a)->f92;((struct Actor *)a)->f104=-((struct Actor *)a)->f104;}
 func_0c02a18c(a,23,22,func_0c02849a()&15);((char *)state)[8]=zero;((float *)state)[1]=((struct Actor *)a)->f92;func_0c144a30((struct Actor *)a,(struct Actor *)owner);
}
void func_0c144a30(struct Actor *a,struct Actor *owner){struct Actor *record=a;table_0c24fa50[record->b5](record,owner);}
