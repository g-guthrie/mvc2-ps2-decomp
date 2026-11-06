/* Exact phase-shifted coordinate warp with wrapping angle and vertex height threshold. */
#include "objects.h"
extern struct ActorGlobalRoot *dat_0c2d964c;
extern void func_0c1d8ff8(void *,void *);
extern int func_0c1d901e(void);
extern void func_0c1d9100(struct Vec3_tu5_03 *),func_0c1d914c(struct Vec3_tu5_03 *);
extern float func_0c1ec2c0(int);
void func_0c1dfd80(struct Obj_tu5_03 *q)
{
 struct Vec3_tu5_03 point;int phase;float height;
 q->w28+=4;if(q->w28>=360)q->w28=0;
 func_0c1d8ff8(((void **)dat_0c2d964c->p0)[8],(void *)q->l84);
 phase=0;
 while(!func_0c1d901e()){
 func_0c1d9100(&point);height=point.y;
 if(height>10.0f){
 point.z+=height*height*func_0c1ec2c0((int)((q->w28+phase)*65536.0f/360.0f+0.5f)&65535)*0.0002f;
 }
 phase+=30;func_0c1d914c(&point);
 }
}
