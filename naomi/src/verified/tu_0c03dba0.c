#include "objects.h"
extern void func_0c044344(struct Actor *),func_0c040b08(struct Actor *),func_0c03484c(struct Actor *),func_0c1d8eb4(struct Actor *),func_0c040b3a(struct Actor *),func_0c03cbee(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c034922(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0453c4(struct Actor *,int),func_0c1d1622(struct LinkedActorVec3 *,int);
extern int func_0c04daae(struct Actor *,int,int);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c23bb38[])(struct Actor *);
void func_0c03dbf6(struct Actor *);
void func_0c03dba0(struct Actor *a)
{
 a->b6++;func_0c044344(a);a->b12c=1;a->i72=0;
 *(struct LinkedActorVec3 *)&a->f80=*(struct LinkedActorVec3 *)((char *)a+0x284);
 a->f264=1.0f;func_0c040b08(a);
 if(a->f56<a->f41c)a->f56=a->f41c;
 a->s28=0;func_0c03dbf6(a);
}
void func_0c03dbf6(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->b1fd&&!a->b238){a->b238=1;func_0c03484c(a);func_0c1d8eb4(a);
  if(a->b235){ /* Retail evaluates this flag without changing state. */ }
 }
 if(a->s28==0 && !(a->f96>0)){a->s28=1;func_0c040b3a(a);}
 if(a->b233!=2 && --a->b239<0 && a->w420){
 a->b6=4;a->b1d6=-1;a->b1fc=1;func_0c02a0c4(a,13,30);func_0c03cbee(a);return;
 }
 if(!(a->f96>0) && func_0c044e52(a)){
 a->b6++;a->b1eb=2;a->s278=5;a->b1f9=2;func_0c02a0c4(a,13,26);
 }
}
void func_0c03dd40(struct Actor *a) {
  int value;
  a->b1eb = 2;
  if ((value = a->s278) >= 0) {
  if ((short)a->w420 > 0 && value > 0)
    goto animate;
  a->s278 = -1;
  func_0c034922(a);
  func_0c1d1622((struct LinkedActorVec3 *)&a->f52, a->b2);
  if (a->b233 != 1) {
    value = a->b207;
    value = value < 5 ? 1 : 3;
    dat_0c2d9260.b5 = value;
    dat_0c2d9260.b6 = 1;
  }
  if (a->b235 || !a->w420 || !a->b236)
    goto animate;
  if (a->b525) {
    if (func_0c04daae(a, 29, 2))
      *(char *)&a->b236 = -1;
    else
      *(char *)&a->b236 = 0;
  }
  if ((char)a->b236 < 0) {
    a->b1d3 = 0;
    func_0c0453c4(a, 17);
    return;
  }
  }
animate:
  if (func_0c02a026(a) < 0)
    func_0c0453c4(a, 23);
}
void func_0c03de42(struct Actor *a)
{
 if(a->b6==0){a->b6++;a->s28=64;a->b239=a->b232;}
 a->b1f5=0;a->b239--;a->s28--;
 if(a->b239==0 && a->s28==0){
 if(a->b1f9!=2)func_0c0437b8(a);else func_0c0438de(a);
 }
}
void func_0c03de96(struct Actor *a){table_0c23bb38[a->b6](a);}
