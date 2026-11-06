#include "objects.h"
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c02a0c4(struct Actor *,int,int),func_0c04b02a(struct Actor *),func_0c04c010(struct Actor *,struct Actor *,int);
extern struct LinkedActor *func_0c1633ca(struct Actor *,unsigned char,unsigned char);
#define RESULT(a) (*(int *)&(a)->pad10c[24])
void func_0c0d142c(struct Actor *a)
{
 struct Actor *other=a->p1c8;
 a->b1ea=1;a->b1ed=2;a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);
 if(a->f41c>a->f56){a->f56=a->f41c;func_0c043324(a);a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c02a0c4(a,22,14);}
 if(a->s30<5){if(--a->s28<0){a->s28=2;func_0c1633ca(a,0,a->s30);a->s30++;}}
 if(RESULT(a)){
  if(RESULT(a)<0){a->b6++;a->b7=0;a->s28=32;func_0c02a0c4(a,22,7);dat_0c2d9260.b5=2;dat_0c2d9260.b6=1;other->b1f6=16;other->b1a1=74;}
  else{dat_0c2d9260.b5=1;dat_0c2d9260.b6=1;other->b1a1=71;}
  RESULT(a)=0;other->p1b4=a;func_0c04b02a(a);func_0c04c010(other,a,1);
 }
}
