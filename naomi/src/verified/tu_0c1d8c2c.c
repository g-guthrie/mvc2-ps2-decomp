#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,int,int);
extern void func_0c037688(struct Obj_tu5_03 *);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern struct Actor dat_0c2d9260;
extern float dat_0c23279c[];
extern unsigned char *dat_0c2f83f8;
extern void (*table_0c2619e8[])(struct Obj_tu5_03 *);
extern void (*table_0c2619f8[])(struct Obj_tu5_03 *);
void func_0c1d8cc8(struct Obj_tu5_03 *);
void func_0c1d8cf6(struct Obj_tu5_03 *);
void func_0c1d8df2(struct Obj_tu5_03 *);
void func_0c1d8e20(struct Obj_tu5_03 *);
void func_0c1d8e6a(struct Obj_tu5_03 *);
void func_0c1d8c2c(struct Actor *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,7,1))!=0){
  a->b12c=1;a->p16=func_0c1d8cc8;a->lcc=1041;
  a->f80=1.0f;a->f84=1.0f;a->f88=1.0f;
  a->l84=(int)((void **)dat_0c2d9650->p0)[85];
  switch((char)parent->b1fd){case 1:a->pos.x=dat_0c2d9260.f140;break;case 2:a->pos.x=dat_0c2d9260.f136;break;}
  a->pos.y=parent->f56+(parent->b13c/2)*parent->f84*2.1428571f;
  a->f120=1.0f;a->f124=1.0f;a->f128=1.0f;
 }
}
void func_0c1d8cc8(struct Obj_tu5_03 *a){table_0c2619e8[a->b4](a);}
void func_0c1d8cda(struct Obj_tu5_03 *a)
{
 if(a->i208){a->i208--;return;}
 a->b4++;
 func_0c1d8cf6(a);
}
void func_0c1d8cf6(struct Obj_tu5_03 *a)
{
 a->f120-=0.166666672f;a->f124-=0.166666672f;a->f128-=0.166666672f;
 if((unsigned char)++a->b5>6)a->b4++;
}
void func_0c1d8d58(struct Actor *parent)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,7,1))!=0){
  a->b12c=1;a->p16=func_0c1d8df2;a->lcc=1029;
  switch((char)parent->b1fd){case 1:a->pos.x=dat_0c2d9260.f140;break;case 2:a->pos.x=dat_0c2d9260.f136;break;}
  a->pos.y=parent->f56+(parent->b13c/2)*parent->f84*2.1428571f;
  a->f120=1.0f;a->f124=1.0f;a->f128=1.0f;
  a->angles.scalar.l44=parent->w130?16384:49153;
  a->i208=3;
 }
}
void func_0c1d8df2(struct Obj_tu5_03 *a){table_0c2619f8[a->b4](a);}
void func_0c1d8e04(struct Obj_tu5_03 *a)
{
 if(a->i208){a->i208--;return;}
 a->b4++;func_0c1d8e20(a);
}
void func_0c1d8e20(struct Obj_tu5_03 *a)
{
 float *scale=&dat_0c23279c[(unsigned char)a->b5];
 a->l84=(int)((void **)dat_0c2d9650->p0)[88+(unsigned char)a->b5];
 a->f120=*scale;a->f124=*scale;a->f128=*scale;
 if((unsigned char)++a->b5>6)a->b4++;
}
void func_0c1d8e64(struct Obj_tu5_03 *a){a->b12c=0;func_0c1d8e6a(a);}
void func_0c1d8e6a(struct Obj_tu5_03 *a){a->b4++;}
void func_0c1d8e72(struct Obj_tu5_03 *a){func_0c037688(a);}
void func_0c1d8eb4(struct Actor *parent)
{
 func_0c1d8c2c(parent);func_0c1d8d58(parent);
 if(((struct MaskTarget *)parent)->b235 && parent->b1fd)dat_0c2f83f8[97]=parent->b1fd;
}
void func_0c1d8ee0(struct Vec3_tu5_03 *position,char direction)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,7,1))!=0){
  a->b12c=1;a->p16=func_0c1d8cc8;a->lcc=1041;
  a->f80=1.0f;a->f84=1.0f;a->f88=1.0f;
  a->l84=(int)((void **)dat_0c2d9650->p0)[85];
  a->pos=*position;
  a->f120=1.0f;a->f124=1.0f;a->f128=1.0f;
 }
}
void func_0c1d8f44(struct Vec3_tu5_03 *position,char direction)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,7,1))!=0){
  a->b12c=1;a->p16=func_0c1d8df2;a->lcc=1029;a->pos=*position;
  a->f120=1.0f;a->f124=1.0f;a->f128=1.0f;
  a->angles.scalar.l44=direction?16384:49153;a->i208=3;
 }
}
void func_0c1d8faa(struct Vec3_tu5_03 *position,char direction)
{
 func_0c1d8ee0(position,direction);func_0c1d8f44(position,direction);
}
