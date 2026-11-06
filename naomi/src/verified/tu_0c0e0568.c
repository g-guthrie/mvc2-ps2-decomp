#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0346da(struct Actor *,int),func_0c1b2600(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c0e0568(struct Actor *a)
{
 
 int one;
 struct MotionGlobal_0c2d9260 *event;
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f41c>a->f56){
  a->b6++;a->f56=a->f41c;
  if(a->w130)a->f52+=-106.666664124f;else a->f52+=106.666664124f;
  one=1;event=&dat_0c2d9260;
  event->b5=one;event->b6=one;
  func_0c0346da(a,73);func_0c1b2600(a,one,0);func_0c1b2600(a,one,one);
  event->b5=3;event->b6=one;func_0c02a0c4(a,13,34);
 }
}
void func_0c0e0636(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6++;a->s28=120;func_0c02a0c4(a,13,31);}
}
void func_0c0e0664(struct Actor *a)
{
 func_0c02a026(a);a->s28--;
 if(a->s28<=0){a->b6++;func_0c02a0c4(a,17,0);}
}
