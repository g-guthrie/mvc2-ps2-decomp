/* Spawner, frame dispatcher and keyframed child effects (0x0c1d3f98-0x0c1d4610). */
#include "objects.h"
extern struct Obj_tu5_03 *func_0c0374da(int,char,int);
extern struct ActorGlobalRoot *dat_0c2d9650;
extern struct EffectCounter dat_0c2f8398;
extern void func_0c037688(struct Obj_tu5_03 *);
extern float func_0c1ce8c4(void *,unsigned char *,int);
extern struct EffectKnot dat_0c261294[],dat_0c2612a4[],dat_0c2612b4[],dat_0c2612c4[],dat_0c2612dc[],dat_0c2612ec[];
extern struct EffectKnot dat_0c261304[],dat_0c261314[],dat_0c26132c[],dat_0c26133c[],dat_0c26134c[],dat_0c26135c[];
extern struct EffectKnot *dat_0c261474[];
extern int dat_0c26148c[];
void func_0c1d4010(struct Obj_tu5_03 *);
void func_0c1d40f8(struct Obj_tu5_03 *,char);
void func_0c1d413c(struct Obj_tu5_03 *);
void func_0c1d419e(struct Obj_tu5_03 *,char);
void func_0c1d4214(struct Obj_tu5_03 *);
void func_0c1d4276(struct Obj_tu5_03 *,char);
void func_0c1d42ba(struct Obj_tu5_03 *);
void func_0c1d431c(struct Obj_tu5_03 *,char);
void func_0c1d4398(struct Obj_tu5_03 *);
void func_0c1d43fa(struct Obj_tu5_03 *,char);
void func_0c1d443e(struct Obj_tu5_03 *);
void func_0c1d4534(struct Obj_tu5_03 *,int,char);
void func_0c1d457c(struct Obj_tu5_03 *);
void func_0c1d3f98(struct Vec3_tu5_03 *position,int unused1,int unused2,unsigned char angle,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  dat_0c2f8398.count++;
  a->b12c=0;a->p16=func_0c1d4010;
  a->pos=*position;
  a->b35=kind;
  a->angles.array[2]=((int)(angle*737280.0f/360.0f+0.5f)&65535)+0xc000;
  a->lcc=0x189;
 }
}
void func_0c1d4010(struct Obj_tu5_03 *a)
{
 switch(a->w28){
 case 0:func_0c1d40f8(a,a->b35);func_0c1d43fa(a,a->b35);break;
 case 3:func_0c1d419e(a,a->b35);break;
 case 4:func_0c1d4534(a,0,a->b35);break;
 case 6:func_0c1d4276(a,a->b35);func_0c1d4534(a,1,a->b35);break;
 case 7:func_0c1d4534(a,3,a->b35);break;
 case 9:func_0c1d431c(a,a->b35);break;
 case 10:func_0c1d4534(a,2,a->b35);break;
 case 12:func_0c1d4534(a,5,a->b35);break;
 case 14:func_0c1d4534(a,4,a->b35);break;
 }
 if(a->w28>18){func_0c037688(a);dat_0c2f8398.count--;return;}
 a->w28++;
}
void func_0c1d40f8(struct Obj_tu5_03 *parent,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d413c;
  a->l84=(int)((void **)dat_0c2d9650->p0)[124];
  a->lcc=0x410;
  a->p200=&parent->f136;
 }
}
void func_0c1d413c(struct Obj_tu5_03 *a)
{
 if(a->w28>6){func_0c037688(a);return;}
 a->f80=func_0c1ce8c4(dat_0c261294,&a->b4,a->w28);
 a->f84=a->f80;
 a->f88=a->f80;
 a->f120=func_0c1ce8c4(dat_0c2612a4,(unsigned char *)&a->b5,a->w28);
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
void func_0c1d419e(struct Obj_tu5_03 *parent,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d4214;
  a->l84=(int)((void **)dat_0c2d9650->p0)[125];
  a->lcc=0x410;
  a->p200=&parent->f136;
 }
}
void func_0c1d4214(struct Obj_tu5_03 *a)
{
 if(a->w28>4){func_0c037688(a);return;}
 a->f80=func_0c1ce8c4(dat_0c2612b4,&a->b4,a->w28);
 a->f84=a->f80;
 a->f88=a->f80;
 a->f120=func_0c1ce8c4(dat_0c2612c4,(unsigned char *)&a->b5,a->w28);
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
void func_0c1d4276(struct Obj_tu5_03 *parent,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d42ba;
  a->l84=(int)((void **)dat_0c2d9650->p0)[126];
  a->lcc=0x410;
  a->p200=&parent->f136;
 }
}
void func_0c1d42ba(struct Obj_tu5_03 *a)
{
 if(a->w28>4){func_0c037688(a);return;}
 a->f80=func_0c1ce8c4(dat_0c2612dc,&a->b4,a->w28);
 a->f84=a->f80;
 a->f88=a->f80;
 a->f120=func_0c1ce8c4(dat_0c2612ec,(unsigned char *)&a->b5,a->w28);
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
void func_0c1d431c(struct Obj_tu5_03 *parent,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d4398;
  a->l84=(int)((void **)dat_0c2d9650->p0)[127];
  a->lcc=0x410;
  a->p200=&parent->f136;
 }
}
void func_0c1d4398(struct Obj_tu5_03 *a)
{
 if(a->w28>6){func_0c037688(a);return;}
 a->f80=func_0c1ce8c4(dat_0c261304,&a->b4,a->w28);
 a->f84=a->f80;
 a->f88=a->f80;
 a->f120=func_0c1ce8c4(dat_0c261314,(unsigned char *)&a->b5,a->w28);
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
void func_0c1d43fa(struct Obj_tu5_03 *parent,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d443e;
  a->l84=(int)((void **)dat_0c2d9650->p0)[128];
  a->lcc=0x413;
  a->p200=&parent->f136;
 }
}
void func_0c1d443e(struct Obj_tu5_03 *a)
{
 if(a->w28>15){func_0c037688(a);return;}
 a->f80=func_0c1ce8c4(dat_0c26132c,&a->b4,a->w28);
 a->f84=a->f80;
 a->f88=a->f80;
 a->angles.array[0]=(int)(func_0c1ce8c4(dat_0c26133c,(unsigned char *)&a->b5,a->w28)*65536.0f/360.0f+0.5f)&65535;
 a->pos.x=func_0c1ce8c4(dat_0c26134c,&a->b6,a->w28);
 a->f120=func_0c1ce8c4(dat_0c26135c,&a->b7,a->w28);
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
void func_0c1d4534(struct Obj_tu5_03 *parent,int index,char kind)
{
 struct Obj_tu5_03 *a;
 if((a=func_0c0374da(0,kind,1))!=0){
  a->b12c=1;a->p16=func_0c1d457c;
  a->lcc=0x400;
  a->p200=&parent->f136;
  a->b32=index;
 }
}
void func_0c1d457c(struct Obj_tu5_03 *a)
{
 if(a->w28>=dat_0c26148c[a->b32]){func_0c037688(a);return;}
 a->l84=(int)((void **)dat_0c2d9650->p0)[dat_0c261474[a->b32][a->w28].frame];
 a->f120=dat_0c261474[a->b32][a->w28].value;
 a->f124=a->f120;
 a->f128=a->f120;
 a->w28++;
}
