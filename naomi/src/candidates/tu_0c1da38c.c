/* Complete 808-byte spline/vertex-effect section:806 bytes match retail.
 * Three functions and both pools match. The current-keyframe index temporary
 * at 0x0c1da3ee/0x0c1da3f8 uses R4 instead of retail R7; no whole-unit credit.
 * Adjacent frame lookup, separate frame indices, signedness changes and a
 * bounded ten-probe source search did not resolve these two register bytes. */
#include "objects.h"
struct Keyframe_0c261d94 {float time;struct Vec3_tu5_03 position,angles;};
extern struct Keyframe_0c261d94 dat_0c261d94[];
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern int func_0c1d8ff8(int,int),func_0c1d9100(struct Vec3_tu5_03 *),func_0c1d914c(struct Vec3_tu5_03 *);
extern int func_0c1d901e(void);
extern float func_0c1eeef0(struct Vec3_tu5_03 *),func_0c1ec2c0(int);
void func_0c1da550(struct Obj_tu5_03 *);
void func_0c1da38c(float t,float *left,float *middle,float *right){
 *left=(1.0f-t)*(1.0f-t)*0.5f;
 *middle=0.5f+t*(1.0f-t);
 *right=t*t*0.5f;
}
void func_0c1da3ae(struct Obj_tu5_03 *a){
 float left,middle,right,fraction;struct Keyframe_0c261d94 *previous,*current,*next;int frame;
 fraction=(float)a->w28/((dat_0c261d94+a->w30)[1].time-dat_0c261d94[a->w30].time);
 func_0c1da38c(fraction,&left,&middle,&right);
 frame=a->w30;previous=&dat_0c261d94[frame-1];current=&dat_0c261d94[frame];next=current+1;
 a->pos.x=previous->position.x*left+current->position.x*middle+next->position.x*right;
 a->pos.y=previous->position.y*left+current->position.y*middle+next->position.y*right;
 a->pos.z=previous->position.z*left+current->position.z*middle+next->position.z*right;
 a->angles.array[0]=(int)((previous->angles.x*left+current->angles.x*middle+next->angles.x*right)*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l44=(int)((previous->angles.y*left+current->angles.y*middle+next->angles.y*right)*65536.0f/360.0f+0.5f)&65535;
 a->angles.scalar.l48=(int)((previous->angles.z*left+current->angles.z*middle+next->angles.z*right)*65536.0f/360.0f+0.5f)&65535;
 a->w28++;
 if(a->w28>=((dat_0c261d94+a->w30)[1].time-dat_0c261d94[a->w30].time)){
 a->w28=0;a->w30++;if((unsigned int)(a->w30+1)>=34)a->w30=1;
 }
 func_0c1da550(a);
}
void func_0c1da550(struct Obj_tu5_03 *a){
 struct Vec3_tu5_03 point,copy;register float measure;
 func_0c1d8ff8(((int *)dat_0c2d964c->p0)[15],a->l84);
 while(!func_0c1d901e()){
 func_0c1d9100(&point);copy=point;measure=func_0c1eeef0(&copy);
 if((point.x < -350.0f || point.x > 350.0f) && point.z < -100.0f){
 point.y+=measure*func_0c1ec2c0((int)((a->w28*30+(int)measure)*65536.0f/360.0f+0.5f)&65535)*0.02f;
 }
 func_0c1d914c(&point);
 }
}
void func_0c1da62c(void){
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))){a->b12c=1;a->p16=func_0c1da3ae;a->l84=((int *)dat_0c2d964c->p0)[14];a->lcc=0x80f;a->w30=1;}
}
