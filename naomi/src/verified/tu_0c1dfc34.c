/* Oscillate paired actors in opposite rotational directions. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c262488[];
extern float dat_0c2624a0[];
extern float func_0c1ec2c0(int);
void func_0c1dfc34(struct Obj_tu5_03 *a)
{
 if(++a->w28>=360)a->w28=0;
 {
  float degrees=360.0f;register float half=0.5f;
  a->angles.array[0]=(int)((a->b32?1:-1)*func_0c1ec2c0((int)(a->w28*65536.0/degrees+half)&65535)*917504/degrees+half)&65535;
 }
}
void func_0c1dfcb8(int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0) {
  a->b12c=1;a->p16=func_0c1dfc34;
  a->l84=(*(int (*)[68])&(*(union ActorGlobalEntry (*)[68])dat_0c2d964c->p0)[n*2])[3];
  a->lcc=0x807;a->pos=dat_0c262488[n];
  a->angles.scalar.l44=(int)(dat_0c2624a0[n]*65536.0/360.0+0.5)&65535;
  a->b32=n;
 }
}
void func_0c1dfd3a(void)
{
 func_0c1dfcb8(0);
 func_0c1dfcb8(1);
}
