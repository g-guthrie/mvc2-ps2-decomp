#include "objects.h"
extern void (*table_0c246a34[])(struct Actor *);
extern void *table_0c246a4c[];
extern unsigned char dat_0c246204[],dat_0c246254[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c02a39a(struct Actor*,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor*);
extern void func_0c0432ca(struct Actor*);
extern void func_0c0437b8(struct Actor*);
void func_0c0c27e2(struct Actor *a);
extern void func_0c0c4f04(struct Actor*,unsigned char *);
extern int func_0c0c4f82(struct Actor*);
extern void func_0c0429a4(struct Actor *,struct Vec3_tu5_03 *,int);
extern void func_0c1c1678(struct Actor *,short *,int);
extern int func_0c02849a(void);
extern void func_0c15f7a8(struct Actor *,int);
extern void func_0c0344a0(struct Actor *,int);
void func_0c0c28ac(struct Actor *a);
void func_0c0c2794(struct Actor *a)
{
 a->b6++;
 func_0c0442fa(a);
 func_0c02a39a(a,0);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->f56=a->f41c;
 a->b1fc=0;a->b1f9=0;
 func_0c02a0c4(a,20,2);
 func_0c0c27e2(a);
}
void func_0c0c27e2(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}

void func_0c0c2804(struct Actor *a)
{
 a->x364[0]=0;
 table_0c246a34[a->b6](a);
}
void func_0c0c281e(struct Actor *a)
{
 struct ActorSub2a4Grab *sub=(struct ActorSub2a4Grab *)&a->sub2a4;
 if(a->b255==6){a->b3f0=0xff;a->b3f1=16;}
 a->b6++;
 sub->b24=0;sub->b4=0xff;
 a->b1f9=0;a->f56=a->f41c;a->b1fc=0;
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 a->b1a1=69;
 a->w1ac=0;a->b19e=0;*(unsigned int *)&a->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,22,7);
 func_0c0432ca(a);
 func_0c0c28ac(a);
}
void func_0c0c28ac(struct Actor *a)
{
 struct ActorSub2a4Grab *sub=(struct ActorSub2a4Grab *)&a->sub2a4;
 struct Vec3_tu5_03 v;
 a->b3f8=2;
 a->b328=5;
 a->b3f1=(a->b255==6)?2:0;
 func_0c02a026(a);
 if(!a->b141){
  a->b6++;
  a->b3f0=0;a->b3f1=0;
  sub->b11=2;sub->b10=0xff;
  func_0c0c4f04(a,dat_0c246204);
  v.x=-13.33333302f;v.y=105.0f;v.z=0.0f;
  func_0c0429a4(a,&v,1);
 }
}
void func_0c0c2968(struct Actor *a)
{
 struct ActorSub2a4Grab *sub=(struct ActorSub2a4Grab *)&a->sub2a4;
 a->b3f8=2;
 a->b328=5;
 if(!func_0c0c4f82(a)){
 a->b6++;
 sub->b25=sub->b10=0;
 sub->s30=180;
 func_0c1c1678(a,&sub->s30,6);
  sub->p20=table_0c246a4c[func_0c02849a()&3];
  sub->b27=1;
  func_0c0442fa(a);
  func_0c02a39a(a,0);
  func_0c15f7a8(a,0);
  func_0c15f7a8(a,1);
  func_0c15f7a8(a,3);
  func_0c15f7a8(a,4);
  func_0c0c4f04(a,dat_0c246254);
  func_0c02a0c4(a,22,8);
  func_0c0344a0(a,30);
 }
}
