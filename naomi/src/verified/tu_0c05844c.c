#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void func_0c05bbd6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c025900(struct Actor *,char,char);
void func_0c05844c(struct Actor *a)
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
 func_0c02a0c4(a,15,27);
 }
}
void func_0c0584cc(struct Actor *a)
{
 struct Actor *child;
 a->b1f2=3;
 if(func_0c02a026(a)<0){
 a->b7++;
 a->f92=5.83333302f;
 a->f104=-0.1041666642f;
 a->f96=12.85714245f;
 a->f108=-0.80357140303f;
 if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 func_0c02a0c4(a,15,33);
 func_0c025900(a,0,0);
 child=a->p1c8;
 child->p1b4=a;
 child->b1f6=2;
 if(a->b255==3){child->b1a1=66;a->b1a1=66;}
 else{child->b1a1=a->b1a3+65;a->b1a1=a->b1a3+65;}
 }
}
