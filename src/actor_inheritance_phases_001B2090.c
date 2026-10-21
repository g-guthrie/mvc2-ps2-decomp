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

extern s32 func_001754A0(u8 *,s32,s32);
extern void func_00176160(u8 *,s32,s32,s32);
extern f32 D_004F1FC8 __attribute__((section(".bss")));
extern f32 D_004F1FCC __attribute__((section(".bss")));
extern void func_001B74E0(u8 *,u8 *);
extern void func_001B7630(u8 *);
extern void func_001B7650(u8 *);
extern void func_001E3210(u8 *,s32);
extern void func_001BB2B0(u8 *,void *);
typedef struct {u8 prefix[0x34];f32 x,y,z;u8 middle[0x1C];f32 vx,vy,vz,ax,ay;} ActorMotion;
typedef struct {u8 prefix[0x34];f32 x,y,z;} ActorPosition;
typedef struct {u8 prefix[4];u8 phase;u8 pad5[0x18-5];u8 *owner;u8 pad1c[0xec-0x1c];ActorState inherited;} LinkedActorState;

void func_001B2090(u8 *p) {
 ActorMotion *m=(ActorMotion *)p;
 u8 *q;
 f32 x,offset;
 p[4]++;
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
 p[0x24]=15;
 *(s16 *)(p+0x140)=*(s16 *)(*(u8 **)(p+0x18)+0x140);
 m->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 m->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 m->z=*(f32 *)(*(u8 **)(p+0x18)+0x3C);
 if(*(s16 *)(p+0x140)) x=D_004F1FC8;
 else x=D_004F1FCC;
 m->x=x;
 {
  f32 distance=176.66665649414062f;
  if(*(s16 *)(p+0x140)) offset=distance;
  else offset=-distance;
 }
 m->x+=offset;
 m->y=41.666664123535156f+*(f32 *)(*(u8 **)(p+0x18)+0x38);
 m->ax=0;m->ay=0;*(f32 *)(p+0x118)=0;
 *(s16 *)(p+0x1C)=30;
 func_00176160(q,2,2,1);
 func_001754A0(p,27,12);
}

void func_001B73B0(u8 *p) {
 LinkedActorState *actor=(LinkedActorState *)p;
 u8 *owner=actor->owner;
 switch(actor->phase) {
 case 0:
 actor->phase++;
 actor->inherited=*(ActorState *)(actor->owner+0xec);
 p[0x13c]=1;p[2]=(actor->owner)[2];p[1]=(actor->owner)[1];
 *(f32 *)(p+0x50)=*(f32 *)(actor->owner+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(actor->owner+0x54);
 p[0x1b7]=(actor->owner)[0x1b7];p[0x1b8]=(actor->owner)[0x1b8];
 *(s8 *)(p+0x30)=*(s8 *)(actor->owner+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(actor->owner+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(actor->owner+0x24);
 p[0x13c]=0;
 case 1:
 p[0x24]=0;
 func_001B74E0(p,owner);
 break;
 case 2:func_001B7630(p);break;
 case 3:func_001B7650(p);break;
 }
}

void func_001BB140(u8 *p,void *context) {
 u8 *q=context;
 ActorPosition *position=(ActorPosition *)p;
 p[4]=1;p[0x13c]=1;
 *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
 p[0x13c]=1;p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x24]=7;
 *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
 if(p[0x23]==1) {
  f32 offset;
  if(*(s16 *)(q+0x140))offset=-60.0f;
  else offset=60.0f;
  position->x+=offset;
 }
 position->y+=160.0f;
 func_001754A0(p,27,7);
 *(s16 *)(p+0x1c)=10;
 *(f32 *)(p+0x50)=0.0f;*(f32 *)(p+0x54)=0.0f;
 *(f32 *)(p+0x118)=1.0f;
 func_001E3210(q,30);
 func_001BB2B0(p,context);
}
