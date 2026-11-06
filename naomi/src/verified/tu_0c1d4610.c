/* Fifteen-particle burst: facing helper, nested factory, particle constructor and fade callback. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern int func_0c1ec190(void);
extern void func_0c03499e(struct LinkedActor *),func_0c037688(struct Obj_tu5_03 *),func_0c1d975e(struct Obj_tu5_03 *);
void func_0c1d465c(struct Vec3_tu5_03 *),func_0c1d4690(struct Vec3_tu5_03 *,int),func_0c1d47ac(struct Obj_tu5_03 *);
void func_0c1d4610(struct LinkedActor *owner,struct Vec3_tu5_03 *offset){
 struct Vec3_tu5_03 position;
 if(owner->sdc.w130)position.x=owner->f52-offset->x;else position.x=owner->f52+offset->x;
 position.y=owner->f56+offset->y;position.z=owner->f60;
 func_0c1d465c(&position);func_0c03499e(owner);
}
void func_0c1d465c(struct Vec3_tu5_03 *position){
 int i,j;
 for(j=0;j<5;j++)for(i=0;i<3;i++)func_0c1d4690(position,i);
}
void func_0c1d4690(struct Vec3_tu5_03 *position,int variant){
 struct Obj_tu5_03 *a;int random;
 if((a=func_0c0374da(0,7,1))){
 a->b12c=1;a->p16=func_0c1d47ac;a->l84=((int *)dat_0c2d9650->p0)[variant+121];a->pos=*position;
 a->f92=func_0c1ec190()%30-15;
 a->f96=func_0c1ec190()%30-15;
 a->f100=func_0c1ec190()%30-15;
 a->f104=-a->f92/30.0f;a->f108=-a->f96/30.0f;a->f112=-a->f100/30.0f;
 a->f116=1.0f;a->angles.array[2]=func_0c1ec190()%65536;a->lcc=39;
 }
}
void func_0c1d47ac(struct Obj_tu5_03 *a){
 a->w28++;
 if(a->w28>30){func_0c037688(a);return;}
 func_0c1d975e(a);
 a->angles.array[0]+=a->angles.array[2];a->angles.array[1]+=a->angles.array[2]/2;
 a->f116-=0.016666668f;
}
