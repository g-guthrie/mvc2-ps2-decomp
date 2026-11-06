/* Grab-state entry and wait handlers 0x0c0c3494-0x0c0c35d0; the entry falls through into its successor. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c2463bc[];
extern void func_0c1accee(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0432ca(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0c4f04(struct Actor *,unsigned char *);
extern void func_0c0429a4(struct Actor *,struct Vec3_tu5_03 *,int);
void func_0c0c3526(struct Actor *a);

void func_0c0c3494(struct Actor *a)
{
 register struct ActorSub2a4Grab *sub=(struct ActorSub2a4Grab *)&a->sub2a4;
 int zero;
 if(a->b255==6){a->b3f0=255;a->b3f1=16;}
 a->b6++;
 zero=0;
 sub->b24=zero;
 sub->b4=255;sub->b10=255;
 a->f92=0;a->f96=0;a->f104=0;a->f108=0;
 a->b1a1=78;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c1accee(a,1);
 func_0c02a0c4(a,22,17);
 if(a->b1f9!=2)func_0c0432ca(a);
 func_0c0c3526(a);
}

void func_0c0c3526(struct Actor *a)
{
 struct ActorSub2a4Grab *sub=(struct ActorSub2a4Grab *)&a->sub2a4;
 struct Vec3_tu5_03 v;
 a->b3f8=2;
 a->b328=5;
 func_0c02a026(a);
 if(!a->b141){
  int zero;
  a->b6++;
  zero=0;
  a->b3f0=zero;a->b3f1=zero;
  sub->b11=4;sub->b10=255;
  func_0c0c4f04(a,dat_0c2463bc);
  v.x=-13.33333302f;v.y=105.0f;v.z=0;
  func_0c0429a4(a,&v,1);
 }
}
