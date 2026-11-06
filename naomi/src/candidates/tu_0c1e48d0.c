#include "objects.h"
struct EndpointWindow { struct Vec3_tu5_03 start,neighbor,end; };
struct InputEvent_1444 { char pad0;unsigned char kind;char pad2[675];unsigned char mask;char pad678[766]; };
extern struct InputEvent_1444 dat_0c2d7088[];
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c2645f4[],dat_0c264618[],dat_0c26465c[],dat_0c2d926c;
extern char dat_0c264658[];
extern float dat_0c264648[];
extern int dat_0c2d9610;
extern void func_0c1e47fc(struct Obj_tu5_03 *),func_0c037688(struct Obj_tu5_03 *);
extern void func_0c1d91a8(int),func_0c1ce660(struct Vec3_tu5_03 *,int);
void func_0c1e499e(struct Obj_tu5_03 *),func_0c1e4ac8(struct Obj_tu5_03 *);
void func_0c1e48d0(int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e47fc;
  a->l84=(*(int (*)[88])&(*(union ActorGlobalEntry (*)[88])dat_0c2d964c->p0)[n*2])[72];
  a->lcc=0x801;a->pos=dat_0c2645f4[n];a->b32=n;
  func_0c1d91a8(a->l84);
 }
}
void func_0c1e4940(int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e499e;
  a->l84=(*(int (*)[88])dat_0c2d964c->p0)[dat_0c264658[n]];
  a->lcc=0x801;a->pos=dat_0c264618[n];a->b32=n;
 }
}
void func_0c1e499e(struct Obj_tu5_03 *a)
{
 struct Vec3_tu5_03 effect;
 struct InputEvent_1444 *p; struct InputEvent_1444 *end;
 unsigned char *mask;
 switch(a->b4){
 case 0:
  if(dat_0c2d9610==1)goto advance;
  else{
   int one=1; int two=2;
   end=dat_0c2d7088+2;mask=(unsigned char *)dat_0c2d7088;
   for(p=dat_0c2d7088;p<end;p++,mask+=1444){
    if(p->kind==24 && (mask[677]&(one<<a->b32))){a->b4=two;break;}
   }
  }
  break;
 case 1:if(++a->w28>=40){advance:a->b4++;}break;
 case 2:
  effect=dat_0c264618[a->b32];effect.y=dat_0c264648[a->b32];
  func_0c1ce660(&effect,0);func_0c037688(a);break;
 }
}
void func_0c1e4a92(float *x,float *y,int n)
{
 struct Vec3_tu5_03 *vertex=&dat_0c264618[n];
 register struct Vec3_tu5_03 *camera=&dat_0c2d926c;
 register float camera_x=camera->x;float camera_z=camera->z;
 *x=camera_x-(camera_x-vertex->x)*camera_z/(camera_z-vertex->z);
 *y=dat_0c264648[n];
}
void func_0c1e4ac8(struct Obj_tu5_03 *a)
{
 switch(a->b4){
 case 0:
  a->f116+=0.0100000002f;
  a->pos.x+=(((struct EndpointWindow *)&dat_0c26465c[a->b32])->end.x-dat_0c26465c[a->b32].x)/100.0;
  a->pos.y+=(((struct EndpointWindow *)&dat_0c26465c[a->b32])->end.y-dat_0c26465c[a->b32].y)/100.0;
  a->pos.z+=(((struct EndpointWindow *)&dat_0c26465c[a->b32])->end.z-dat_0c26465c[a->b32].z)/100.0;
  if(++a->w28>=100){a->b4++;a->f116=1.0f;a->pos=((struct EndpointWindow *)&dat_0c26465c[a->b32])->end;}
  break;
 case 1:if(dat_0c2d9610==2)a->b4++;break;
 case 2:
  a->f116-=0.0100000002f;
  if(++a->w28>=100)func_0c037688(a);
  break;
 }
}
void func_0c1e4c04(int n)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1e4ac8;
  a->l84=(*(int (*)[88])&(*(union ActorGlobalEntry (*)[88])dat_0c2d964c->p0)[n])[86];
  a->lcc=0x821;a->pos=dat_0c26465c[n];a->b32=n;a->f116=0.0f;
 }
}
