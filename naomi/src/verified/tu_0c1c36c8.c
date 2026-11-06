/* Resource digit selection and pulsing effect scale. */
#include "objects.h"
extern signed char dat_0c2f8378,dat_0c2f8392[];
extern short dat_0c2f891c,dat_0c2f8918;
extern struct ActorGlobalRoot *dat_0c2d9654;
extern struct Vec3_tu5_03 dat_0c25d2ac;
extern struct EffectScale4 dat_0c25d2b8[2];
extern float func_0c1ec2c0(int);
void func_0c1c36c8(struct Obj_tu5_03 *a){
 int digit=dat_0c2f8378;
 if(!a->b32)digit/=10;else digit%=10;
 a->l84=((int *)dat_0c2d9654->p0)[(int)(digit+85U)];
}
void func_0c1c3706(struct Obj_tu5_03 *a){
 int mode=dat_0c2f8392[a->b32];float half,divisor;
 if(mode>=5)mode=5;
 if(mode>=5)a->f80=a->f84=func_0c1ec2c0(dat_0c2f891c)/16.0f+1.25f;
 else *(struct Vec3_tu5_03 *)&a->f80=dat_0c25d2ac;
 half=0.5f;divisor=2.0f;
 if(mode>=5){
 a->f120=func_0c1ec2c0(dat_0c2f891c+(int)a->f104)/divisor+half;
 a->f124=func_0c1ec2c0(dat_0c2f891c+(int)a->f108)/divisor+half;
 a->f128=func_0c1ec2c0(dat_0c2f891c+(int)a->f112)/divisor+half;
 }else{
 float weight=func_0c1ec2c0(dat_0c2f8918)/divisor+half;
 struct EffectScale4 *high=dat_0c25d2b8,*low=high+1;
 {float lo=low->f120,hi=high->f120-lo;a->f120=lo+hi*weight;}
 {float lo=low->f124,hi=high->f124-lo;a->f124=lo+hi*weight;}
 {float lo=low->f128,hi=high->f128-lo;a->f128=lo+hi*weight;}
 }
 if(mode>=5)mode=9;
 a->l84=((int *)dat_0c2d9654->p0)[mode+96];
}
