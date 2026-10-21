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

typedef struct {s16 x,y;} LaunchVelocity;
extern LaunchVelocity D_0044E800[4];
extern s16 D_0044E810[8];
extern int func_00174170(void);
extern int func_001754A0(u8 *,int,int);
extern void func_001D94D0(u8 *,u8 *);
void func_001D9290(u8 *p,void *q) {
 u32 index;
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((u8 *)q+0xEC);
        p[0x13C]=1;
        p[2]=((u8 *)q)[2];p[1]=((u8 *)q)[1];
        *(f32 *)(p+0x50)=*(f32 *)((u8 *)q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((u8 *)q+0x54);
        p[0x1B7]=((u8 *)q)[0x1B7];p[0x1B8]=((u8 *)q)[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((u8 *)q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((u8 *)q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((u8 *)q+0x24);
 p[0x13C]=1;*(s8 *)(p+0x31)=-1;
 motion->x=*(f32 *)((u8 *)q+0x34);
 motion->y=*(f32 *)((u8 *)q+0x38);
 *(f32 *)(p+0x3C)=*(f32 *)((u8 *)q+0x3C);
 {
 s16 vx;
 index=func_00174170()&3;
 vx=(s16)(s32)(1.6666666269302368f*D_0044E800[index].x);
 if(*(s16 *)(p+0x140)) vx=-vx;
 motion->vx=vx;
 motion->vy+=2.142857074737549f*D_0044E800[index].y;
 }
 func_001754A0(p,27,D_0044E810[func_00174170()&7]);
 func_001D94D0(p,q);
}

extern void func_001DABF0(u8 *,u8 *);
void func_001DA890(u8 *p,void *q) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((u8 *)q+0xEC);
        p[0x13C]=1;
        p[2]=((u8 *)q)[2];p[1]=((u8 *)q)[1];
        *(f32 *)(p+0x50)=*(f32 *)((u8 *)q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((u8 *)q+0x54);
        p[0x1B7]=((u8 *)q)[0x1B7];p[0x1B8]=((u8 *)q)[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((u8 *)q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((u8 *)q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((u8 *)q+0x24);
 switch(p[0x20]) {
 case 0:p[0x21]=6;break;
 case 1:p[0x21]=2;break;
 case 2:p[0x21]=10;break;
 case 3:p[0x21]=18;break;
 case 4:p[0x21]=16;break;
 case 5:p[0x21]=20;break;
 }
 motion->x=*(f32 *)((u8 *)q+0x34);
 motion->y=*(f32 *)((u8 *)q+0x38);
 p[0x31]=1;
 func_001757E0(p,21,p[0x21]);
 func_001DABF0(p,q);
}

void func_001CE070(u8 *p) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 phase=p[5];
 p[5]=phase+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((*(u8 **)(p+0x18))+0xEC);
        p[0x13C]=1;
        p[2]=(*(u8 **)(p+0x18))[2];p[1]=(*(u8 **)(p+0x18))[1];
        *(f32 *)(p+0x50)=*(f32 *)((*(u8 **)(p+0x18))+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((*(u8 **)(p+0x18))+0x54);
        p[0x1B7]=(*(u8 **)(p+0x18))[0x1B7];p[0x1B8]=(*(u8 **)(p+0x18))[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((*(u8 **)(p+0x18))+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((*(u8 **)(p+0x18))+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((*(u8 **)(p+0x18))+0x24);
 p[0x13C]=1;p[0x24]=0;
 motion->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 motion->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 if(p[0x21]) {
  motion->vx=-1.6666666269302368f;motion->ax=0;
  motion->vy=12.857142448425293f;motion->ay=-0.5357142686843872f;
 } else {
  motion->vx=-0.8333333134651184f;motion->ax=0;
  motion->vy=25.714284896850586f;motion->ay=-0.5357142686843872f;
 }
 if(*(s16 *)(p+0x140)) {motion->vx=-motion->vx;motion->ax=-motion->ax;}
 func_001757E0(p,23,1);
}
