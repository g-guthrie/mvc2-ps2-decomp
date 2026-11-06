#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern struct Vec3_tu5_03 dat_0c260e08;
extern struct EffectCounter dat_0c2f8398;
struct ScaleView {unsigned char pad[80];struct Vec3_tu5_03 scale;};
void func_0c1d0322(struct Obj_tu5_03 *);
void func_0c1d03b0(struct Obj_tu5_03 *);
void func_0c1d04cc(struct Obj_tu5_03 *,int);
void func_0c1d0580(struct Obj_tu5_03 *,int);
void func_0c1d0430(struct Obj_tu5_03 *);
void func_0c1d05d4(struct Obj_tu5_03 *);
void func_0c1d02f0(struct Obj_tu5_03 *a)
{
 a->f80+=0.800000012f;a->f84+=0.800000012f;a->f88+=0.800000012f;
 if(a->w28>=10){func_0c037688(a);return;}
 a->w28++;
}
void func_0c1d0322(struct Obj_tu5_03 *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,7,1))!=0){
  a->b12c=1;a->p16=func_0c1d02f0;
  a->l84=(int)((void **)dat_0c2d9650->p0)[23];
  a->pos=parent->pos;
  a->angles.scalar.l48=5461;
  ((struct ScaleView *)a)->scale=dat_0c260e08;
  a->lcc=409;
 }
}
void func_0c1d037e(struct Obj_tu5_03 *a)
{
 a->f80+=0.800000012f;a->f84+=0.800000012f;a->f88+=0.800000012f;
 if(a->w28>=10){func_0c037688(a);return;}
 a->w28++;
}
void func_0c1d03b0(struct Obj_tu5_03 *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,7,1))!=0){
  a->b12c=1;a->p16=func_0c1d037e;
  a->l84=(int)((void **)dat_0c2d9650->p0)[24];
  a->pos=parent->pos;
  ((struct ScaleView *)a)->scale=dat_0c260e08;
  a->lcc=401;
 }
}
void func_0c1d0430(struct Obj_tu5_03 *a)
{
 if(a->w28==2)func_0c1d0322(a);
 if(a->w28==10)func_0c1d03b0(a);
 if(a->w28>=10){func_0c037688(a);return;}
 a->w28++;
}
void func_0c1d0466(struct Vec3_tu5_03 *position)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,7,1))!=0){a->b12c=0;a->p16=func_0c1d0430;a->pos=*position;}
}
void func_0c1d049a(struct Obj_tu5_03 *a)
{
 a->f80+=0.800000012f;a->f84+=0.800000012f;a->f88+=0.800000012f;
 if(a->w28>=10){func_0c037688(a);return;}
 a->w28++;
}
void func_0c1d04cc(struct Obj_tu5_03 *parent,int layer)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,layer,1))!=0){
  a->b12c=1;a->p16=func_0c1d049a;
  a->l84=(int)((void **)dat_0c2d9650->p0)[23];
  a->pos=parent->pos;
  a->angles.scalar.l48=5461;
  ((struct ScaleView *)a)->scale=dat_0c260e08;
  a->lcc=409;
 }
}
void func_0c1d0526(struct Obj_tu5_03 *a)
{
 a->f80+=0.800000012f;a->f84+=0.800000012f;a->f88+=0.800000012f;
 if(a->w28>=10){func_0c037688(a);return;}
 a->w28++;
}
void func_0c1d0580(struct Obj_tu5_03 *parent,int layer)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,layer,1))!=0){
  a->b12c=1;a->p16=func_0c1d0526;
  a->l84=(int)((void **)dat_0c2d9650->p0)[24];
  a->pos=parent->pos;
  ((struct ScaleView *)a)->scale=dat_0c260e08;
  a->lcc=401;
 }
}
void func_0c1d05d4(struct Obj_tu5_03 *a)
{
 if(a->w28==2)func_0c1d04cc(a,(char)a->b35);
 if(a->w28==10)func_0c1d0580(a,(char)a->b35);
 if(a->w28>=10){dat_0c2f8398.count--;func_0c037688(a);return;}
 a->w28++;
}
void func_0c1d061a(struct Vec3_tu5_03 *position,int unused,char layer)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,layer,1))!=0){
  dat_0c2f8398.count++;
  a->b12c=0;a->p16=func_0c1d05d4;a->pos=*position;a->b35=layer;
 }
}
