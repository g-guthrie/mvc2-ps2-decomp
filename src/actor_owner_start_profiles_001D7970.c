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

extern int func_001754A0(u8 *,int,int);
extern void func_001D7AB0(u8 *,void *);
extern u8 D_004BFA98[] __attribute__((section(".sdata")));
void func_001D7970(u8 *p,void *q) {
 u32 state=p[4];p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((u8 *)q+0xEC);
        p[0x13C]=1;
        p[2]=((u8 *)q)[2];p[1]=((u8 *)q)[1];
        *(f32 *)(p+0x50)=*(f32 *)((u8 *)q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((u8 *)q+0x54);
        p[0x1B7]=((u8 *)q)[0x1B7];p[0x1B8]=((u8 *)q)[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((u8 *)q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((u8 *)q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((u8 *)q+0x24);
 p[0x13C]=0;*(s8 *)(p+0x31)=-1;
 if(p[0x20]==0) {
  *(s32 *)(p+0xDC)=*(s32 *)((u8 *)q+0x2D4);
  *(s16 *)(p+0x1C)=0;*(s32 *)(p+0xD8)=5;
 } else {
  *(u32 *)(p+0x8C)=0;p[0x24]=8;
  *(s16 *)(p+0x140)^=1;
  func_001754A0(p,27,D_004BFA98[*(s32 *)((u8 *)q+0xDC)]);
 }
 func_001D7AB0(p,q);
}

extern void func_001DAE90(u8 *,u8 *);
void func_001DAD60(u8 *p,void *q) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((u8 *)q+0xEC);
        p[0x13C]=1;
        p[2]=((u8 *)q)[2];p[1]=((u8 *)q)[1];
        *(f32 *)(p+0x50)=*(f32 *)((u8 *)q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((u8 *)q+0x54);
        p[0x1B7]=((u8 *)q)[0x1B7];p[0x1B8]=((u8 *)q)[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((u8 *)q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((u8 *)q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((u8 *)q+0x24);
 motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
 *(u16 *)(p+0x1C)=*(u16 *)((u8 *)q+0x168);
 *(s8 *)(p+0x31)=-2;
 motion->vx=40.0f;motion->vy=240.0f;
 if(*(s16 *)(p+0x140)) motion->vx=-motion->vx;
 func_001757E0(p,23,3);
 func_001DAE90(p,q);
}

extern void func_001D13B0(u8 *,void *);
void func_001D12E0(u8 *p,void *q) {
 u32 state=p[4];p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((u8 *)q+0xEC);
        p[0x13C]=1;
        p[2]=((u8 *)q)[2];p[1]=((u8 *)q)[1];
        *(f32 *)(p+0x50)=*(f32 *)((u8 *)q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((u8 *)q+0x54);
        p[0x1B7]=((u8 *)q)[0x1B7];p[0x1B8]=((u8 *)q)[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((u8 *)q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((u8 *)q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((u8 *)q+0x24);
 p[0x13C]=0;*(s8 *)(p+0x31)=-1;
 *(V3 *)(p+0x34)=*(V3 *)((u8 *)q+0x34);
 *(s32 *)(p+0xD0)=-1;
 *(s32 *)((u8 *)q+0x2B8)=-1;
 func_001D13B0(p,q);
}

extern u8 D_0044DFA0[],D_0044DFB0[];
extern void func_001D1700(u8 *,void *);
void func_001D1610(u8 *p,void *q) {
 u8 *mapping;
 u32 state=p[4];p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((u8 *)q+0xEC);
        p[0x13C]=1;
        p[2]=((u8 *)q)[2];p[1]=((u8 *)q)[1];
        *(f32 *)(p+0x50)=*(f32 *)((u8 *)q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((u8 *)q+0x54);
        p[0x1B7]=((u8 *)q)[0x1B7];p[0x1B8]=((u8 *)q)[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((u8 *)q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((u8 *)q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((u8 *)q+0x24);
 *(V3 *)(p+0x34)=*(V3 *)((u8 *)q+0x34);
 *(s16 *)(p+0x1C)=-1;p[0x31]=2;
 mapping=D_0044DFA0;
 if(p[0x20]) {p[0x31]=1;mapping=D_0044DFB0;}
 *(u8 **)(p+0xD0)=mapping;
 func_001D1700(p,q);
}
