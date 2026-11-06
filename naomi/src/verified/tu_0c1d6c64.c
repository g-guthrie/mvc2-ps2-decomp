#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern void func_0c1d6dc8(struct Obj_tu5_03 *),func_0c1d6dea(struct Obj_tu5_03 *),func_0c1d6e3e(struct Obj_tu5_03 *);
void func_0c1d6c78(struct Vec3_tu5_03 *);
void func_0c1d6cd6(struct Vec3_tu5_03 *);
void func_0c1d6d42(struct Vec3_tu5_03 *);
void func_0c1d6c64(struct Vec3_tu5_03 *position)
{
 func_0c1d6c78(position);func_0c1d6cd6(position);func_0c1d6d42(position);
}
void func_0c1d6c78(struct Vec3_tu5_03 *position)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,8,1))!=0){
  a->b12c=1;a->p16=func_0c1d6dc8;
  a->l84=(int)((void **)dat_0c2d9650->p0)[220];
  a->pos=*position;
  a->lcc=37;a->w28=0;
  a->f116=0.0f;a->f120=0.0f;a->f124=0.0f;a->f128=0.0f;
 }
}
void func_0c1d6cd6(struct Vec3_tu5_03 *position)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,8,1))!=0){
  a->b12c=1;a->p16=func_0c1d6dea;
  a->l84=(int)((void **)dat_0c2d9650->p0)[221];
  a->pos=*position;
  a->lcc=53;a->w28=0;
  a->f80=1.0f;a->f84=1.0f;a->f88=1.0f;
  a->f116=0.0f;a->f120=0.0f;a->f124=0.0f;a->f128=0.0f;
 }
}
void func_0c1d6d42(struct Vec3_tu5_03 *position)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,8,1))!=0){
  a->b12c=1;a->p16=func_0c1d6e3e;
  a->l84=(int)((void **)dat_0c2d9650->p0)[222];
  a->pos=*position;
  a->lcc=37;a->w28=0;
  a->f116=1.0f;a->f120=0.0f;a->f124=0.0f;a->f128=0.0f;
 }
}
