#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c04b02a(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c0346da(struct Actor *,int);
extern void (*table_0c244c58[])(struct Actor *);
void func_0c0b2de0(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);
 if (a->b141) {
  a->b6++;a->b141=0;
  position.x=-116.666664124f;position.y=203.57143f;position.z=0;
  func_0c1cea66(a,&position,1);func_0c0346da(a,1);
 }
}
void func_0c0b2e2e(struct Actor *a)
{
 struct Actor *child=a->p1c8;
 if (func_0c02a026(a)<0) {
  a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  func_0c0438de(a);return;
 }
 if (a->b141) { a->b141=0;child->p1b4=a;child->b1f6=1;child->b1a1=33; }
}
void func_0c0b2e86(struct Actor *a) { table_0c244c58[a->b6](a); }
void func_0c0b2e98(struct Actor *a)
{
 struct Actor *child=a->p1c8;
 struct LinkedActorVec3 position;
 int cue;
 func_0c02a026(a);
 if (a->b141<0) {
  a->b6++;func_0c025900(a,0,0);
  child->p1b4=a;child->b1f6=1;child->b1a1=36;
  a->f92=a->b1d2 ? -5.83333302f : 5.83333302f;
  a->f104=0;a->f96=12.85714245f;a->f108=-0.80357140303f;
 }else{
  switch(a->b141){
  case 1:
   a->b141=0;child->b1a1=34;func_0c04b02a(a);
   position.x=-36.666664124f;position.y=111.42857f;
   goto spawn;
  case 2:
   a->b141=0;child->b1a1=34;func_0c04b02a(a);
   position.x=-45.0f;position.y=96.42857f;
spawn:
   position.z=0;func_0c1cea66(a,&position,1);cue=4;
   goto effect;
  case 3:
   a->b141=0;child->b1a1=35;func_0c04b02a(a);
   position.x=-60.0f;position.y=90.0f;position.z=0;
   func_0c1cea66(a,&position,1);cue=6;
effect:
   func_0c0346da(a,cue);break;
  default:break;
  }
 }
}
void func_0c0b2fd8(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if (a->f96>0) return;
 if (a->f56>a->f41c) return;
 {
  a->b6++;a->f56=a->f41c;a->b1f9=0;
  func_0c02a0c4(a,1,3);
 }
}
