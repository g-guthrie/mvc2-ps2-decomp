/* Burst spawners and their keyframed glow children (0x0c1cff0c-0x0c1d02f0). */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,char,int);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern struct EffectCounter dat_0c2f8398;
extern void func_0c037688(struct Obj_tu5_03 *);
extern float func_0c1ce8c4(void *,unsigned char *,int);
extern void func_0c1cef62(struct Vec3_tu5_03 *,int,char,char);
extern struct Vec3_tu5_03 dat_0c260d64;
extern struct EffectKnot dat_0c260d70[],dat_0c260d80[],dat_0c260d90[];
extern int dat_0c260da0[],dat_0c260dd0[];
extern float dat_0c260db8[],dat_0c260dec[];
void func_0c1d0058(struct Obj_tu5_03 *);
void func_0c1d0074(struct Obj_tu5_03 *,char);
void func_0c1d00b8(struct Obj_tu5_03 *);
void func_0c1d00fa(struct Obj_tu5_03 *,char);
void func_0c1d013e(struct Obj_tu5_03 *);
void func_0c1d01cc(struct Obj_tu5_03 *,char);
void func_0c1d0202(struct Obj_tu5_03 *);
void func_0c1d0246(struct Obj_tu5_03 *,char);
void func_0c1d027c(struct Obj_tu5_03 *);
void func_0c1cff0c(struct Vec3_tu5_03 *position,int unused,int mode,char angle,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  dat_0c2f8398.count++;
  a->b12c=0;a->p16=func_0c1d0058;
  a->pos=*position;
  a->lcc=0x181;
  if(mode==1){
   a->lcc=a->lcc|16;
   *(struct Vec3_tu5_03 *)&a->f80=dat_0c260d64;
  }
  func_0c1d0074(a,kind);
  func_0c1d00fa(a,kind);
  func_0c1d01cc(a,kind);
  func_0c1d0246(a,kind);
  func_0c1cef62(position,mode,angle,kind);
 }
}
void func_0c1cffac(struct Vec3_tu5_03 *position,int unused,int mode,int unused2,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  dat_0c2f8398.count++;
  a->b12c=0;a->p16=func_0c1d0058;
  a->pos=*position;
  a->lcc=0x181;
  if(mode==1){
   a->lcc=a->lcc|16;
   *(struct Vec3_tu5_03 *)&a->f80=dat_0c260d64;
  }
  func_0c1d0074(a,kind);
  func_0c1d00fa(a,kind);
  func_0c1d01cc(a,kind);
  func_0c1d0246(a,kind);
 }
}
void func_0c1d0058(struct Obj_tu5_03 *a)
{
 if(a->w28>10){dat_0c2f8398.count--;func_0c037688(a);return;}
 a->w28++;
}
void func_0c1d0074(struct Obj_tu5_03 *parent,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d00b8;
  a->l84=(int)((void **)dat_0c2d9650->p0)[82];
  a->lcc=0x400;
  a->p200=&parent->f136;
 }
}
void func_0c1d00b8(struct Obj_tu5_03 *a)
{
 if(a->w28>=4){func_0c037688(a);return;}
 a->f120=func_0c1ce8c4(dat_0c260d70,&a->b4,a->w28);
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
void func_0c1d00fa(struct Obj_tu5_03 *parent,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d013e;
  a->l84=(int)((void **)dat_0c2d9650->p0)[83];
  a->lcc=0x410;
  a->p200=&parent->f136;
 }
}
void func_0c1d013e(struct Obj_tu5_03 *a)
{
 if(a->w28>=5){func_0c037688(a);return;}
 a->f80=func_0c1ce8c4(dat_0c260d80,&a->b4,a->w28);
 a->f84=a->f80;
 a->f120=func_0c1ce8c4(dat_0c260d90,(unsigned char *)&a->b5,a->w28);
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
void func_0c1d01cc(struct Obj_tu5_03 *parent,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d0202;
  a->lcc=0x400;
  a->p200=&parent->f136;
 }
}
void func_0c1d0202(struct Obj_tu5_03 *a)
{
 if(a->w28>=6){func_0c037688(a);return;}
 a->l84=(int)((void **)dat_0c2d9650->p0)[dat_0c260da0[a->w28]];
 a->f120=dat_0c260db8[a->w28];
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
void func_0c1d0246(struct Obj_tu5_03 *parent,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d027c;
  a->lcc=0x400;
  a->p200=&parent->f136;
 }
}
void func_0c1d027c(struct Obj_tu5_03 *a)
{
 if(a->w28>=7){func_0c037688(a);return;}
 a->l84=(int)((void **)dat_0c2d9650->p0)[dat_0c260dd0[a->w28]];
 a->f120=dat_0c260dec[a->w28];
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
