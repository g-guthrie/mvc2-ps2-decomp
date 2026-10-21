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

void func_001CE330(u8 *p) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 phase=p[5];p[5]=phase+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((*(u8 **)(p+0x18))+0xEC);
        p[0x13C]=1;
        p[2]=(*(u8 **)(p+0x18))[2];p[1]=(*(u8 **)(p+0x18))[1];
        *(f32 *)(p+0x50)=*(f32 *)((*(u8 **)(p+0x18))+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((*(u8 **)(p+0x18))+0x54);
        p[0x1B7]=(*(u8 **)(p+0x18))[0x1B7];p[0x1B8]=(*(u8 **)(p+0x18))[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((*(u8 **)(p+0x18))+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((*(u8 **)(p+0x18))+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((*(u8 **)(p+0x18))+0x24);
 motion->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 motion->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 if(*(s16 *)(p+0x140)) motion->x+=23.333332061767578f;
 else motion->x+=-23.333332061767578f;
 motion->y+=169.28570556640625f;
}

extern int func_001754A0(u8 *,int,int);
void func_001CE550(u8 *p) {
 u32 state=p[4];p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((*(u8 **)(p+0x18))+0xEC);
        p[0x13C]=1;
        p[2]=(*(u8 **)(p+0x18))[2];p[1]=(*(u8 **)(p+0x18))[1];
        *(f32 *)(p+0x50)=*(f32 *)((*(u8 **)(p+0x18))+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((*(u8 **)(p+0x18))+0x54);
        p[0x1B7]=(*(u8 **)(p+0x18))[0x1B7];p[0x1B8]=(*(u8 **)(p+0x18))[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((*(u8 **)(p+0x18))+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((*(u8 **)(p+0x18))+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((*(u8 **)(p+0x18))+0x24);
 *(s16 *)(p+0x140)=*(s16 *)(*(u8 **)(p+0x18)+0x140);
 p[0x24]=0;
 *(f32 *)(p+0x34)=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 *(f32 *)(p+0x38)=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 func_001754A0(p,27,0);
}

extern f32 D_004F1FC8 __attribute__((section(".bss")));
extern f32 D_004F1FD4 __attribute__((section(".bss")));
void func_001D24C0(u8 *p) {
 u8 *q=*(u8 **)(p+0x18);
 u8 *entry=p;
 s32 count=0;
 do {
        *(ActorState *)(entry+0xEC)=*(ActorState *)(q+0xEC);
        entry[0x13C]=1;
        entry[2]=q[2];entry[1]=q[1];
        *(f32 *)(entry+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(entry+0x54)=*(f32 *)(q+0x54);
        entry[0x1B7]=q[0x1B7];entry[0x1B8]=q[0x1B8];
        *(s8 *)(entry+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(entry+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(entry+0x24)=*(s8 *)(q+0x24);
  count++;
  entry=*(u8 **)(entry+0xC);
 } while(count<13);
 p[4]++;
 *(s16 *)(p+0x140)=p[0x21];
 *(f32 *)(p+0x34)=320.0f+D_004F1FC8;
 *(f32 *)(p+0x38)=240.0f+D_004F1FD4;
 func_001757E0(p,23,20);
}

extern int func_001754A0(u8 *,int,int);
extern void func_001D1160(u8 *,u8 *);
void func_001D1030(u8 *p,void *q) {
 s32 animation;
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
 *(s8 *)(p+0x31)=-1;
 *(s32 *)(p+0xD0)=*(u16 *)((u8 *)q+0x168);
 if(p[0x20]==0) {animation=48;if(p[0x21]) animation=49;}
 else {
  animation=50;
  if(p[0x21]) *(s16 *)(p+0x140)^=1;
 }
 func_001754A0(p,27,(u8)animation);
 func_001D1160(p,q);
}
