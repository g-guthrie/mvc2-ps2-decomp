/* Resource object with fixed position and scale and an empty update callback. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9654;
extern struct Vec3_tu5_03 dat_0c25c324,dat_0c25c330;
void func_0c1c1652(struct Obj_tu5_03 *);
void func_0c1c1604(void){
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,11,1))){
 a->b12c=1;a->p16=func_0c1c1652;a->l84=((int *)dat_0c2d9654->p0)[60];
 a->lcc=0x1081f;a->pos=dat_0c25c324;*(struct Vec3_tu5_03 *)&a->f80=dat_0c25c330;
 }
}
void func_0c1c1652(struct Obj_tu5_03 *a){}
