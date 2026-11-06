/* 0x0c1c9704..0x0c1c98b0: interpolation and constructor. func_0c1c98ac starts the next span. */
#include "objects.h"
extern struct Vec3_tu5_03 dat_0c2305f0[2],dat_0c230608[2];
extern struct ActorGlobalRoot *dat_0c2d9664;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c1d8ff8(int,int),func_0c1d9100(struct Vec3_tu5_03 *),func_0c1d914c(struct Vec3_tu5_03 *);
extern int func_0c1d901e(void);
extern float func_0c1ec2c0(int);
void func_0c1c98ac(struct Obj_tu5_03 *);
void func_0c1c9704(struct Obj_tu5_03 *a){
 struct Vec3_tu5_03 *start=&dat_0c2305f0[0],*end=&dat_0c2305f0[1],*astart=&dat_0c230608[0],*aend=&dat_0c230608[1];
 a->pos.x=start->x+(end->x-start->x)/60.0f*a->w28;
 a->pos.y=start->y+(end->y-start->y)/60.0f*a->w28;
 a->pos.z=start->z+(end->z-start->z)/60.0f*a->w28;
 a->angles.array[0]=(int)((astart->x+(aend->x-astart->x)/60.0f*a->w28)*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l44=(int)((astart->y+(aend->y-astart->y)/60.0f*a->w28)*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l48=(int)((astart->z+(aend->z-astart->z)/60.0f*a->w28)*65536.0f/360.0f+0.5f)&65535;
}
void func_0c1c97e4(void){
 struct Obj_tu5_03 *a;struct Vec3_tu5_03 *angles;
 if((a=func_0c0374da(0,11,1))){
 a->b12c=1;a->p16=func_0c1c98ac;a->l84=((int *)dat_0c2d9664->p0)[0];a->pos=dat_0c2305f0[0];angles=dat_0c230608;
 a->angles.array[0]=(int)(angles->x*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l44=(int)(angles->y*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l48=(int)(angles->z*65536.0f/360.0f+0.5f)&65535;
 a->lcc=5;a->w28=0;a->w28=1;
 }
}
