#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

extern u8 *func_003DA750(u8 *, s32, s32);
extern void func_003CAA20(u8 *);
extern void func_003CAB20(u8 *, u8 *, unsigned int);

typedef struct { u8 prefix[0x38]; f32 y; u8 gap[0x20]; f32 vx,vy; u32 unused64; f32 ax,ay; } ActorMotion;
typedef struct { u8 prefix[0x430]; f32 ground; } ActorGround;
extern int func_00174170(void);
extern int fptosi(f32);
extern s16 D_00476570[],D_00476580[],D_004765A0[],D_004765B0[];
u8 *func_003CA340(u8 *owner)
{
 u8 *p;
 ActorMotion *motion;
 ActorGround *ground=(ActorGround *)owner;
 int i;
 i=0;
 do {
  if((p=func_003DA750(0,1,1))!=0) {
   int speed;
   motion=(ActorMotion *)p;
   *(void (**)(u8 *))(p+0x10)=func_003CAA20;
   *(u8 **)(p+0x18)=owner;
   p[1]=owner[1];
   *(s16 *)(p+0x26)=0x3a01;
   p[0x20]=func_00174170()&7;
   if((i&3)==0)*(s16 *)(p+0x1c)=1;
   *(s16 *)(p+0x1e)=i*4;
   *(ActorState *)(p+0xec)=*(ActorState *)(owner+0xec);
        p[0x13C] = 1;
        p[2] = owner[2];
        p[1] = owner[1];
        *(f32 *)(p + 0x50) = *(f32 *)(owner + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(owner + 0x54);
        p[0x1B7] = owner[0x1B7];
        p[0x1B8] = owner[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(owner + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(owner + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(owner + 0x24);


   p[0x24]=8;
   func_003CAB20(p,owner,2);
   speed=fptosi(1.6666666269302368f*(f32)(((u32)func_00174170()&0x1ff)+0x700)/256.0f);
   if(*(s16 *)(p+0x140)==0)speed=-speed;
   motion->vx=(f32)speed;
   motion->vy=2.142857074737549f*(f32)D_00476580[p[0x20]]/256.0f;
   motion->ay=2.142857074737549f*(f32)D_00476580[p[0x20]+8]/256.0f;
   motion->y=ground->ground+2.142857074737549f*(f32)D_00476570[p[0x20]];
   if(p[0x21]>=24) {
    motion->y=ground->ground;
    motion->ay=0.0f;
    motion->vy=0.0f;
   }
  }
  i++;
 }while(i<20);
 i=0;
 do {
  if((p=func_003DA750(0,1,1))!=0) {
   motion=(ActorMotion *)p;
   *(void (**)(u8 *))(p+0x10)=func_003CAA20;
   *(u8 **)(p+0x18)=owner;
   p[1]=owner[1];
   *(s16 *)(p+0x26)=0x3a01;
   p[0x20]=func_00174170()&7;
   *(s16 *)(p+0x1e)=i*4;
   *(ActorState *)(p+0xec)=*(ActorState *)(owner+0xec);
        p[0x13C] = 1;
        p[2] = owner[2];
        p[1] = owner[1];
        *(f32 *)(p + 0x50) = *(f32 *)(owner + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(owner + 0x54);
        p[0x1B7] = owner[0x1B7];
        p[0x1B8] = owner[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(owner + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(owner + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(owner + 0x24);


   p[0x24]=8;
   func_003CAB20(p,owner,6);
   motion->vy=2.142857074737549f*(f32)D_004765B0[p[0x20]]/256.0f;
   motion->ay=2.142857074737549f*(f32)D_004765B0[p[0x20]+8]/256.0f;
   motion->y=ground->ground+2.142857074737549f*(f32)D_004765A0[p[0x20]];
  }
  i++;
 }while(i<20);
 return p;
}
