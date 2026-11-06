#include "objects.h"
extern unsigned char dat_0c2f8338;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c02a0c4(struct Actor *,int,int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c192ec8(struct Actor *,int);
void func_0c07e0cc(struct Actor *a)
{
 float offset,speed;
 a->b12c=0;
 a->b149=255;
 if(dat_0c2f8338>=2){
 a->b6++;
 a->b12c=1;
 a->b1f9=2;
 a->s28=32;
 a->f100=a->f52;
 offset=-640.0f;
 speed=20.0f;
 if(a->w130){offset=640.0f;speed=-20.0f;}
 a->f52=a->f52+offset;
 a->f92=speed;
 a->f104=0;
 a->f56=a->f41c+548.571411133f;
 a->f96=-17.142857f;
 a->f108=0;
 func_0c02a0c4(a,18,0);
 }
}
void func_0c07e150(struct Actor *a)
{
 func_0c02a026(a);
 a->f52+=a->f92;
 a->f92+=a->f104;
 a->f56+=a->f96;
 a->f96+=a->f108;
 if(a->f56<a->f41c){
 a->b6++;
 a->b1f9=0;
 a->f52=a->f100;
 a->f56=a->f41c;
 func_0c0346da(a,49);
 func_0c192ec8(a,0);
 dat_0c2d9260.b5=1;
 dat_0c2d9260.b6=1;
 func_0c02a0c4(a,18,1);
 }
}
