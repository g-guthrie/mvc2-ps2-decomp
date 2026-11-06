/* Complete 612-byte wave-effect section:602 bytes match retail.
 * Constructors and both pools match. Only the write/advance bindings in R9/R10
 * and the one/scale bindings in FR12/FR14 differ; no whole-unit credit. */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d964c;
extern struct Vec3_tu5_03 dat_0c26214c;
extern float _builtin_fabsf(float);
extern float func_0c1ec1b0(void),func_0c1ec2c0(int);
extern int func_0c1d8ff8(void *,void *),func_0c1d901e(void),func_0c1d9100(struct Vec3_tu5_03 *),func_0c1d914c(const struct Vec3_tu5_03 *);
void func_0c1da6b4(register struct Obj_tu5_03 *a)
{
 register float y;
 register float one,degrees,scale;
 register int mask;
 int (*advance)(void);
 int (*read)(struct Vec3_tu5_03 *);
 int (*write)(const struct Vec3_tu5_03 *);
 float (*cosine)(int);
 switch(a->b4){
 case 0:
  a->w28+=5;
  if(a->w28>=360)a->w28=0;
  a->f92+=a->f96;
  if(a->f96>0.0f)a->f96+=-0.000004999999874f;
  if(a->f92<=0.00004999999874f){
   a->f92=0.0f;
   a->f96=_builtin_fabsf(func_0c1ec1b0()*0.00009999999748f+func_0c1ec1b0()*0.00009999999748f-0.00009999999748f);
  }
  func_0c1d8ff8(*(void **)((char *)dat_0c2d964c->p0+((a->b32*2+8)*4)+4),(void *)a->l84);
  advance=func_0c1d901e;write=func_0c1d914c;read=func_0c1d9100;cosine=func_0c1ec2c0;
  one=1.0f;degrees=360.0f;mask=65535;scale=65536.0f;
  while(advance()==0){
   struct Vec3_tu5_03 point;
   read(&point);y=point.y;
   if(y<0.0f){
    if(a->b32)point.z-=(cosine((int)(((int)point.y+a->w28)*scale/degrees+0.5f)&mask)+one)*point.y*point.y*a->f92*3.0f;
    else point.z-=(cosine((int)(((int)point.y+a->w28)*scale/degrees+0.5f)&mask)+one)*point.y*point.y*a->f92;
   }
   write(&point);
  }
  break;
 case 1:break;
 }
}
void func_0c1da87c(int kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,5,1))!=0){
  a->b12c=1;a->p16=func_0c1da6b4;
  a->l84=(int)((void **)dat_0c2d964c->p0)[kind*2+8];
  a->pos=dat_0c26214c;
  a->angles.scalar.l44=56617;a->lcc=2053;a->b32=kind;
 }
}
void func_0c1da8d8(void)
{
 register int i;
 for(i=0;i<2;i++)func_0c1da87c(i);
}
