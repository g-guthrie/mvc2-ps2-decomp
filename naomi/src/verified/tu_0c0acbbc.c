#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Actor *func_0c1a1a34(struct Actor *,int,int);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c025762(void),func_0c0437b8(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c0acbbc(struct Actor *a)
{
 struct Actor *child=a->p1c8;
 if(func_0c02a026(a)<0){
  struct MotionGlobal_0c2d9260 *bounds=&dat_0c2d9260;
  a->b6++;
  if(a->w130){if(a->f52>bounds->f8c+-213.33333f)a->w130=0;}
  else {if(bounds->f88+213.33333f>a->f52)a->w130=1;}
  child->f52=a->f52;child->f52+=a->w130?186.66666f:-186.66666f;
  func_0c02a0c4(a,21,30);
 }
}
void func_0c0acc58(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){
  a->b141=0;a->b6++;
  if(!(a->p20=func_0c1a1a34(a,9,2))){
   struct Actor *child=a->p1c8;
   child->b12c=1;child->f80=1.0f;child->f84=1.0f;child->p1b4=a;child->b1f6=1;
   func_0c025762();func_0c0437b8(a);
  }
 }
}
