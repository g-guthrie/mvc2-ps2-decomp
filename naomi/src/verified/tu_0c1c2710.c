/* Selection marker that slides to its player's slot and fades with the timer. */
#include "objects.h"
extern struct Vec3_tu5_03 dat_0c25c888[];
extern float dat_0c25c8e8[4], dat_0c25c8f8[4];
extern signed char dat_0c2f836e[];
extern float func_0c1ebd40(int);
#define B1DC(p) ((p)->pad1d7[0x1dc - 0x1d7])
void func_0c1c2710(register struct Obj_tu5_03 *a)
{
 register struct Actor *p=(struct Actor *)a->p24;
 register void *zero;
 int s=p->b411;
 zero=0;
 if(a->b33!=s){
  {struct Vec3_tu5_03 *q=&dat_0c25c888[s*2+p->b2];*(struct Vec3_tu5_03 *)&a->f92=*q;}
  a->b33=s;a->w28=32;a->w30=(int)zero;
 }
 if(a->w28){
  if(a->w28==16){a->w30+=0x8000;a->pos=*(struct Vec3_tu5_03 *)((char *)a+92);}
  a->f80=func_0c1ebd40(a->w30);
  a->w28--;a->w30+=0x400;
 }
 a->f120=dat_0c25c8e8[1];a->f124=dat_0c25c8e8[2];a->f128=dat_0c25c8e8[3];
 if(p->w2a0){a->f120=dat_0c25c8f8[1];a->f124=dat_0c25c8f8[2];a->f128=dat_0c25c8f8[3];}
 if(!B1DC(p)&&(short)p->w420<=0)a->b12c=(int)zero;
 if(a->b12c){
  if(!B1DC(p))return;
  if(p->b0)return;
  if(dat_0c2f836e[p->b2]>=3&&!p->b411)goto one;
  a->f116-=0.03125f;
  if(a->f116<0.0f){a->b12c=(int)zero;a->f116=0.0f;}
 }else{
  if(B1DC(p))return;
  if((short)p->w420<=0)return;
  a->b12c=1;
  one:a->f116=1.0f;
 }
}
