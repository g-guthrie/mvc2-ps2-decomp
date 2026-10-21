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

extern f32 D_004F1FC8 __attribute__((section(".bss")));
extern f32 D_004F1FCC __attribute__((section(".bss")));
extern f32 D_004F1FD0 __attribute__((section(".bss")));
extern void func_00176160(u8 *,s32,s32,s32);
extern void func_0015E630(u8 *);
extern s32 func_001754A0(u8 *,s32,s32);
typedef struct {u8 prefix[0x34];f32 x,y,z;u8 middle[0x1C];f32 vx,vy,vz,ax,ay;} ActorMotion;
typedef struct {u8 prefix[0x34];f32 x,y,z;} ActorPosition;

void func_001B16F0(u8 *p) {
 ActorMotion *m=(ActorMotion *)p;
 u8 *q;
 f32 x;
 f32 velocity;
 f32 start=53.33333206176758f;
 f32 span=0.0f;
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
 p[0x24]=12;
 *(s16 *)(p+0x140)=*(s16 *)(*(u8 **)(p+0x18)+0x140);
 m->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 m->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 m->z=*(f32 *)(*(u8 **)(p+0x18)+0x3C);
 {
  f32 margin=53.33333206176758f;
  if(*(s16 *)(p+0x140)) x=D_004F1FC8-margin;
  else x=D_004F1FCC+margin;
 }
 m->x=x;
 m->y+=51.42856979370117f;
 span+=186.66665649414062f;
 m->ax=0;m->ay=0;
 start+=span;
 if(*(s16 *)(p+0x140)) velocity=start/8.0f;
 else velocity=-(start/8.0f);
 m->vx=velocity;
 *(s16 *)(p+0x1C)=8;
 func_00176160(q,4,4,1);
 func_0015E630(p);
 p[0]=1;
 func_001754A0(p,27,8);
}

void func_001B18F0(u8 *p) {
 ActorMotion *m=(ActorMotion *)p;
 u8 *q;
 f32 x;
 f32 velocity;
 f32 start=-36.666664123535156f;
 f32 span=26.66666603088379f;
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
 p[0x24]=13;
 *(s16 *)(p+0x140)=*(s16 *)(*(u8 **)(p+0x18)+0x140);
 m->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 m->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 m->z=*(f32 *)(*(u8 **)(p+0x18)+0x3C);
 { f32 margin=-36.666664123535156f;
 if(*(s16 *)(p+0x140)) x=D_004F1FC8-margin;
 else x=D_004F1FCC+margin;
 }
 m->x=x;
 m->y=34.28571319580078f+D_004F1FD0;
 span+=186.66665649414062f;
 m->ax=0;m->ay=0;
 start+=span;
 if(*(s16 *)(p+0x140)) velocity=start/16.0f;
 else velocity=-(start/16.0f);
 m->vx=velocity;
 m->vy=0;m->ay=-0.8035714030265808f;
 *(s16 *)(p+0x1C)=16;
 func_00176160(q,2,2,1);
 func_0015E630(p);
 p[0]=1;
 func_001754A0(p,27,11);
}

void func_001B1B10(u8 *p) {
 u8 *q;
 ActorPosition *position=(ActorPosition *)p;
 f32 span=53.33333206176758f;
 f32 offset=-108.33332824707031f;
 p[4]++;
 q=*(u8 **)(p+0x18);
 *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
 p[0x13c]=1;p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x13c]=1;
 p[0x24]=7;
 *(s16 *)(p+0x140)=*(s16 *)(*(u8 **)(p+0x18)+0x140);
 position->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 position->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 position->z=*(f32 *)(*(u8 **)(p+0x18)+0x3c);
 { f32 x;
 f32 margin=53.33333206176758f;
 if(*(s16 *)(p+0x140))x=D_004F1FC8-margin;
 else x=D_004F1FCC+margin;
 position->x=x; }
 position->y-=17.14285659790039f;
 offset+=186.66665649414062f;
 *(f32 *)(p+0x68)=0.0f;*(f32 *)(p+0x6c)=0.0f;
 span+=offset;
 {f32 speed;
 if(*(s16 *)(p+0x140))speed=span/5.0f;
 else speed=-(span/5.0f);
 *(f32 *)(p+0x5c)=speed; }
 *(s16 *)(p+0x1c)=5;
 func_00176160(q,2,2,1);
 func_0015E630(p);
 p[0]=1;
 func_001754A0(p,27,7);
}
