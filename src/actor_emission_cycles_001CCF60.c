#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
#include "actor_inherited_state.h"
typedef struct {u8 prefix[0x1C];s16 timer,count;} ActorTimer;
extern void func_003DAA40(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001CCF40(u8 *,s32);
extern void func_0015E630(u8 *);
typedef struct {u8 prefix[0x34]; f32 x,y,z;u8 middle[0x1C];f32 vx,vy,vz,ax,ay;} ActorMotion;

void func_001CCF60(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 ActorTimer *timer=(ActorTimer *)p;
 u32 state=p[4];
 if(state==0) {
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  motion->ay=0;
  motion->ax=0;
  motion->vx=0.2083333283662796f;
  motion->vy=-1.0714285373687744f;
  if(*(s16 *)(p+0x140)) motion->vx=-motion->vx;
  func_001CCF40(p,17);
  timer->timer=16;timer->count=11;
 } else {
  if(*(s32 *)(p+0xD0)!=*(u16 *)(q+0x168)) {func_003DAA40(p);return;}
  {
  s16 remaining=timer->timer;--remaining;timer->timer=remaining;
  if(remaining<=0) {
   s16 count;
   timer->timer=16;
   count=timer->count;--count;timer->count=count;
   if(count<=0) {func_003DAA40(p);return;}
   func_001CCF40(p,(u8)timer->count);
  }
  }
  motion->x+=motion->vx;
  motion->vx+=motion->ax;
  motion->y+=motion->vy;
  motion->vy+=motion->ay;
  func_00175700(p);
 }
}

void func_001CD130(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 ActorTimer *timer=(ActorTimer *)p;
 u32 state=p[4];
 if(state==0) {
  f32 offset;
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  p[0x24]=12;
  offset=80.0f;
  motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
  motion->vx=11.666666030883789f;
  if(*(s16 *)(p+0x140)) {offset=-offset;motion->vx=-motion->vx;}
  motion->x=*(f32 *)(q+0x34)+offset;
  motion->y=*(f32 *)(q+0x38)-12.857142448425293f;
  func_001757E0(p,18,4);
  p[0]=1;func_0015E630(p);
 } else {
  if(p[5]==0) {
   func_00175700(p);
   if(*(s8 *)(p+0x151)) {p[0x151]=0;p[5]++;timer->timer=28;}
  } else {
   s16 remaining;
   motion->x+=motion->vx;motion->vx+=motion->ax;
   remaining=timer->timer;--remaining;timer->timer=remaining;
   if(remaining<0) p[4]++;
   else func_00175700(p);
  }
 }
}

void func_001CD320(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 if(state==0) {
  f32 offset;
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  p[0x31]=8;
  offset=640.0f;
  motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
  motion->vx=11.666666030883789f;
  if(*(s16 *)(p+0x140)) {offset=-offset;motion->vx=-motion->vx;}
  motion->x=*(f32 *)(q+0x34)-offset;
  motion->y=*(f32 *)(q+0x38);
  func_001757E0(p,19,8);
  p[0]=1;func_0015E630(p);
 } else {
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  if(p[5]==0) {
   f32 distance;
   motion->x+=motion->vx;motion->vx+=motion->ax;
   func_00175700(p);
   distance=*(f32 *)(q+0x34)-motion->x;
   distance=distance<0.0f ? -distance:distance;
   if(distance<160.0f) {p[5]++;*(s16 *)(q+0x2C2)=1;func_001757E0(p,19,9);}
  } else func_00175700(p);
 }
}

extern void func_001E3710(u8 *,int);
void func_001CD520(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 if(state==0) {
  f32 offset;
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  offset=640.0f;
  *(s8 *)(p+0x31)-=8;
  motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
  motion->vx=-11.666666030883789f;
  if(*(s16 *)(p+0x140)) {offset=-offset;motion->vx=-motion->vx;}
  motion->x=*(f32 *)(q+0x34)+offset;
  motion->y=*(f32 *)(q+0x38);
  func_001757E0(p,19,10);
  p[0]=1;func_0015E630(p);
 } else {
  u32 phase;
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  phase=p[5];
  if(phase==0) {
   f32 distance;
   motion->x+=motion->vx;motion->vx+=motion->ax;
   func_00175700(p);
   distance=*(f32 *)(q+0x34)-motion->x;
   distance=distance<0.0f ? -distance:distance;
   if(distance<426.666656494140625f) {
    f32 offset;
    p[5]++;*(s16 *)(q+0x2C4)=1;
    offset=53.333332061767578f;
    motion->ax=0.4166666567325592f;
    if(*(s16 *)(p+0x140)) {offset=-offset;motion->ax=-motion->ax;}
    motion->x-=offset;
    func_001757E0(p,19,11);
    func_001E3710(q,41);
   }
  } else {
   if((u8)phase==1) {
    f32 old=motion->vx;
    motion->x+=old;
    motion->vx+=motion->ax;
    if(motion->vx*old<0.0f) p[5]++;
   }
   func_00175700(p);
  }
 }
}
