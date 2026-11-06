/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct ActorMotionFixed3 dat_0c23f788[];

void func_0c057490(struct Actor *a)
{
    a->b1ea = 1;
    a->b1ed = 2;
    a->b1f5 = 2;
    a->b1f2 = 3;
    if (func_0c02a026(a) < 0) {
        a->b7++;
        a->f92 = dat_0c23f788[(unsigned char)a->b1a3].x_speed * 1.66666663f / 65536.0f;
        a->f104 = 0;
        a->f96 = dat_0c23f788[(unsigned char)a->b1a3].y_speed * 2.1428571f / 65536.0f;
        a->f108 = dat_0c23f788[(unsigned char)a->b1a3].y_acceleration * 2.1428571f / 65536.0f;
        if (!(a->f52 < 0)) a->f92 = -a->f92;
        func_0c02a0c4(a, 15, 12);
    }
}

extern int func_0c047b98(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c05bbd6(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
void func_0c057552(struct Actor *a)
{
 int one=1;
 struct ActorSub2a4 *sub=&a->sub2a4;
 a->b1ea=one;a->b1ed=2;a->b1f5=2;a->b1f2=3;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(func_0c047b98(a)){
  if(a->b525){if(a->b141){a->b141=0;if(a->b142!=1)a->b142--;}}
  else a->b142=one;
  (*(char *)&sub->b2)++;
  if(*(char *)&sub->b2>20)*(char *)&sub->b2=20;
 }
 if(func_0c044e52(a)){
  a->b7++;a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  dat_0c2d9260.b5=3;dat_0c2d9260.b6=one;
  func_0c05bbd6(a);func_0c02a0c4(a,15,13);
 }
}
void func_0c057676(struct Actor *a)
{
 a->b1ea=1;a->b1ed=2;a->b1f5=2;a->b1f2=3;
 if(a->b141)a->b141=0;
 if(func_0c02a026(a)<0){
 a->b7++;a->f92=5.0f;a->f104=-0.1041666642f;a->f96=17.142857f;a->f108=-0.66964281f;
 if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 func_0c02a0c4(a,15,14);
 }
}
