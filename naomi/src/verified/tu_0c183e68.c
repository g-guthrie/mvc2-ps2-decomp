#include "objects.h"
#define A(a) ((struct Actor *)(a))
extern int func_0c02849a(void);
extern struct Actor dat_0c2d9260;
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int);
extern void (*table_0c25587c[])(struct LinkedActor *,struct LinkedActor *);
void func_0c183f4c(struct LinkedActor *,struct LinkedActor *);
void func_0c183e68(struct LinkedActor *a,struct LinkedActor *owner)
{
 unsigned char one;short position;struct Actor *bounds;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;a->b2=owner->b2;a->b1=owner->b1;
 a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;
 a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=-1;position=(unsigned char)func_0c02849a();
 position=position*1.66666663f;bounds=&dat_0c2d9260;position+=bounds->f136;position+=106.666664124f;a->f52=position;
 a->f56=A(owner)->f41c;a->f60=owner->f60;
 if(!(func_0c02849a()&3)){bounds->b5=one;bounds->b6=one;}
 func_0c02a0c4(a,22,4);func_0c183f4c(a,owner);
}
void func_0c183f4c(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(owner->b5 || ((struct MeActor *)owner)->blk_dc.b159!=22)goto advance;
 a->b36=owner->b36;if(func_0c02a026(a)>=0)return;
 advance:a->b4++;
}
void func_0c183f80(struct LinkedActor *a,struct LinkedActor *owner){table_0c25587c[a->b4](a,owner);}
