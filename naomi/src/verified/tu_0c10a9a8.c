#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1ce916(struct LinkedActorVec3 *,int,int,int),func_0c043324(struct Actor *),func_0c173f00(struct Actor *),func_0c0346da(struct Actor *,int),func_0c025762(void),func_0c10c188(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c24b990[])(struct Actor *);
void func_0c10a9a8(struct Actor *a)
{
 struct LinkedActorVec3 position;
 a->b3f8=2;a->b328=5;if(!a->b141)func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->f56<a->f41c){
  a->b6++;a->f56=a->f41c;a->b1f9=1;
  position.x=-13.33333302f;if(a->w130)position.x=-position.x;position.x+=a->f52;position.y=a->f56+68.57143f;
  func_0c1ce916(&position,a->b1d2,15,0);func_0c043324(a);func_0c173f00(a);func_0c0346da(a,49);
  dat_0c2d9260.b5=3;dat_0c2d9260.b6=1;
 }
}
void func_0c10aa84(struct Actor *a)
{
 a->b3f8=2;a->b328=5;
 if(func_0c02a026(a)<0){int zero=0;a->b3f9=zero;a->b3f8=zero;a->b327=zero;a->b328=zero;func_0c025762();func_0c10c188(a);}
}
void func_0c10aac8(struct Actor *a){table_0c24b990[a->b6](a);}
