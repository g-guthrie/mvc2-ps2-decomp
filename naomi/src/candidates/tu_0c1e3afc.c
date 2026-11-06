/* Candidate: retail keeps the zero in fr12 and the third pool constant in fr15; this spelling swaps them, and the yaw add adds r3 to r2 rather than r2 to r3. */
#include "objects.h"
extern int dat_0c264590[];
extern float dat_0c2645a4[][2];
extern const float dat_0c2645cc;
extern struct Vec3_tu5_03 dat_0c2645dc;
extern void func_0c037688(struct Actor*);
extern void func_0c1ce660();
extern void func_0c1d975e();
extern float func_0c1ebd40(int);
extern float func_0c1ec2c0(int);
void func_0c1e3afc(struct Obj_tu5_03 *a);

void func_0c1e3afc(struct Obj_tu5_03 *a)
{
 double degrees=360.0;
 double half=0.5;
 double units=65536.0;
 register float zero=0.0f;
 switch(a->b4){
 case 0:
  a->b4++;
  a->f92=dat_0c2645cc*func_0c1ec2c0((int)(dat_0c264590[a->b32]*units/degrees+half)&65535);
  a->f96=zero;
  a->f100=dat_0c2645cc*func_0c1ebd40((int)(dat_0c264590[a->b32]*units/degrees+half)&65535);
  *(struct Vec3_tu5_03 *)&a->f104=dat_0c2645dc;
  break;
 case 1:
  a->b4++;func_0c1ce660(&a->pos,1);break;
 case 2:
  func_0c1d975e(a);
  a->angles.array[0]+=(int)(dat_0c2645a4[a->b32][0]*units/degrees+half)&65535;
  a->angles.scalar.l48=a->angles.scalar.l48+((int)(dat_0c2645a4[a->b32][1]*units/degrees+half)&65535u);
  if(a->pos.x>-250.0f && a->pos.x<250.0f){
   if(a->pos.y>300.0f)break;
   a->pos.y=300.0f;
  }else{
   if(a->pos.y>zero)break;
   a->pos.y=zero;
  }
  a->f96*=-0.3000000120f;
  if(++a->w28>2){a->b4++;a->w28=0;}
  break;
 case 3:
  if(++a->w28>=15)func_0c037688(a);
  break;
 }
}
