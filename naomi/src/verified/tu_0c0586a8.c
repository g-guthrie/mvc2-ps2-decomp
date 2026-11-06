/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c05bbd6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c025900(struct Actor *,char,char);

extern struct ActorMotionFixed4 dat_0c23f844[];
void func_0c0586a8(struct Actor *a)
{
 a->b1f2=3;
 if(func_0c02a026(a)<0){
 a->b7++;
 a->f92=dat_0c23f844[(unsigned char)a->b1a3].x_speed*1.66666663f/65536.0f;
 a->f104=dat_0c23f844[(unsigned char)a->b1a3].x_acceleration*1.66666663f/65536.0f;
 a->f96=dat_0c23f844[(unsigned char)a->b1a3].y_speed*2.1428571f/65536.0f;
 a->f108=dat_0c23f844[(unsigned char)a->b1a3].y_acceleration*2.1428571f/65536.0f;
 if(!a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 func_0c02a0c4(a,15,31);
 }
}
void func_0c058768(struct Actor *a)
{
 a->b1f2=3;
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 func_0c02a026(a);
 if(func_0c044e52(a)){
 a->b7++;
 dat_0c2d9260.b5=2;
 dat_0c2d9260.b6=1;
 func_0c05bbd6(a);
 func_0c02a0c4(a,15,32);
 }
}
