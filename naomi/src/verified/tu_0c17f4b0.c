#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c037d0c(struct Actor *),func_0c180e44(struct Actor *),func_0c180b86(struct Actor *);
extern void (*table_0c25406c[])(struct Actor *);
void func_0c17f4b0(struct Actor *a)
{
 struct Actor *owner=(struct Actor *)((struct LinkedActor *)a)->p24;
 register float zero=0.0f;
 register float offset;
 a->f52+=a->f92; a->f92+=a->f104;
 a->f56+=a->f96; a->f96+=a->f108;
 if(owner->f41c>a->f56){
  a->f56=owner->f41c;
  a->f96=zero;a->f108=zero;
 }
 if(func_0c02a026(a)<0){
  a->b6++;
  func_0c02a0c4(a,25,1);
  a->f108=zero;a->f104=zero;
  a->f96=-2.1428571f;
  offset=6.6666666f;
  if(!((struct Actor *)owner)->b1d2)offset=-6.6666666f;
  a->f92=offset;
 }
 func_0c037d0c(a);
}
void func_0c17f55e(struct Actor *a)
{
 struct Actor *owner=(struct Actor *)((struct LinkedActor *)a)->p24;
 a->f52+=a->f92; a->f92+=a->f104;
 a->f56+=a->f96; a->f96+=a->f108;
 func_0c180b86(a);
 if(owner->f41c>a->f56){
  a->f56=owner->f41c;
  a->f96=0.0f;a->f108=0.0f;
 }
 if(func_0c02a026(a)<0)func_0c180e44(a);
 else func_0c037d0c(a);
}
void func_0c17f5e8(struct Actor *a){table_0c25406c[a->b4](a);}
