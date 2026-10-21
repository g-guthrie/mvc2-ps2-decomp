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

void func_001DB430(u8 *p) {
 u8 *q;
 u32 state=p[4];p[4]=state+1;
 q=*(u8 **)(p+0x18);
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x13C]=1;
 *(f32 *)(p+0x38)=*(f32 *)(q+0x430);
 *(f32 *)(p+0x50)=1.2000000476837158f;
 *(f32 *)(p+0x54)=1.2000000476837158f;
 if(p[0x20]==0) {*(s16 *)(p+0x1C)=16;p[0x24]=13;}
 else {*(s16 *)(p+0x1C)=4;if(p[0x20]==1) p[0x24]=11;else p[0x24]=9;}
 func_001757E0(p,18,(u8)(p[0x20]+12));
}
