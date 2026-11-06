/* Grab-state handlers 0x0c0c78d0-0x0c0c7a4c (78d0 cloned from 0x0c0c2968). */
#include "objects.h"
extern void (*table_0c246a34[])(struct Actor *);
extern void *table_0c2479b0[];
extern unsigned char dat_0c246204[],dat_0c2471a4[];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c02a39a(struct Actor*,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0442fa(struct Actor*);
extern void func_0c0432ca(struct Actor*);
extern void func_0c0437b8(struct Actor*);
void func_0c0c27e2(struct Actor *a);
extern void func_0c0c9e20(struct Actor*,unsigned char *);
extern int func_0c0c9ea0(struct Actor*);
extern void func_0c0429a4(struct Actor *,struct Vec3_tu5_03 *,int);
extern void func_0c1c1678(struct Actor *,short *,int);
extern int func_0c02849a(void);
extern void func_0c15f7a8(struct Actor *,int);
extern void func_0c0344a0(struct Actor *,int);
void func_0c0c28ac(struct Actor *a);

void func_0c0c78d0(struct Actor *a)
{
 struct ActorSub2a4Grab *sub=(struct ActorSub2a4Grab *)&a->sub2a4;
 a->b3f8=2;
 a->b328=5;
 if(!func_0c0c9ea0(a)){
 a->b6++;
 sub->b25=sub->b10=0;
 sub->s30=180;
 func_0c1c1678(a,&sub->s30,6);
  sub->p20=table_0c2479b0[func_0c02849a()&3];
  sub->b27=1;
  func_0c0442fa(a);
  func_0c02a39a(a,0);
  func_0c15f7a8(a,0);
  func_0c15f7a8(a,1);
  func_0c15f7a8(a,3);
  func_0c15f7a8(a,4);
  func_0c0c9e20(a,dat_0c2471a4);
  func_0c02a0c4(a,22,8);
  func_0c0344a0(a,30);
 }
}

extern unsigned char dat_0c2f8338;
extern unsigned char dat_0c247234[];
extern void (*table_0c2479c0[])(struct Actor *,struct ActorSub2a4Grab *);
void func_0c0c7978(struct Actor *a)
{
 struct ActorSub2a4Grab *sub=(struct ActorSub2a4Grab *)&a->sub2a4;
 int zero;
 a->b3f8=2;
 a->b328=5;
 func_0c0c9ea0(a);
 zero=0;
 if(dat_0c2f8338>=5)sub->s30=zero;
 if(!sub->s30){
  a->b6++;a->b7=zero;sub->b25=zero;
  a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;
  func_0c0c9e20(a,dat_0c247234);
  func_0c02a0c4(a,22,34);
  func_0c0344a0(a,43);
 }else table_0c2479c0[a->b7](a,sub);
}
