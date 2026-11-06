#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c1cea66(struct Actor *,struct LinkedActorVec3 *,int);
extern void func_0c0346da(struct Actor *,int);
extern void (*table_0c244c34[])(struct Actor *);
extern void (*table_0c244c40[])(struct Actor *);
extern void (*table_0c244c4c[])(struct Actor *);
void func_0c0b2c98(struct Actor *a) { a->b1ea=1; table_0c244c34[a->b1f7&63](a); }
void func_0c0b2cb6(struct Actor *a) { table_0c244c40[a->b6](a); }
void func_0c0b2cc8(struct Actor *a)
{
 func_0c02a026(a);
 if (a->b141) { a->b6++; a->b141=0; }
}
void func_0c0b2cec(struct Actor *a)
{
 struct LinkedActorVec3 position;
 func_0c02a026(a);
 if (a->b141) {
  a->b6++; a->b141=0;
  position.x=-113.33333f; position.y=154.28571f; position.z=0;
  func_0c1cea66(a,&position,1);
  func_0c0346da(a,1);
 }
}
void func_0c0b2d3a(struct Actor *a)
{
 struct Actor *child=a->p1c8;
 if (func_0c02a026(a)<0) { func_0c0437b8(a); return; }
 if (a->b141) {
  a->b141=0; child->p1b4=a; child->b1f6=1; child->b1a1=32;
 }
}
void func_0c0b2d80(struct Actor *a) { table_0c244c4c[a->b6](a); }
void func_0c0b2d92(struct Actor *a)
{
 func_0c02a026(a);
 if (a->b141) { a->b6++; a->b141=0; }
}
