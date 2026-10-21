#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

typedef struct { u8 prefix[0x24]; s8 palette; } ActorPalette;
typedef struct {u8 prefix[0x5c];f32 vx;} ActorVelocity;
typedef struct {u8 prefix[0x7c];s16 count[2];} GameState;
extern GameState *D_004C2794 __attribute__((section(".sdata")));
typedef struct {s32 x,y;} LaunchVelocity;
extern LaunchVelocity D_00472B20[];
extern int func_001757E0(u8 *,int,int);
extern int func_00175700(u8 *);
extern int func_00174240(u8 *);
extern void func_001E7F60(u8 *);
typedef struct {u8 prefix[0x1c];s16 timer;} ActorTimer;
extern void func_00176160(u8 *,s32,s32,s32);
extern void func_003DAA40(u8 *);
void func_003A16D0(u8 *p,u8 *q)
{
 ActorVelocity *motion=(ActorVelocity *)p;
 if(p[4]==0) {
 p[4]++;
  *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
    p[0x13C] = 1;
        p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
 {u8 *team=p+2;
 p[0x1b0]=66;p[0x1b1]=0;
 p[0x14c]=p[0x14d]=p[0x14e]=48;
 p[0x14f]=96;
 *(f32 *)(p+0x6c)=0.0f;
 *(f32 *)(p+0x68)=0.0f;
 motion->vx=(f32)D_00472B20[p[0x1b7]].x;
 *(f32 *)(p+0x60)=(f32)D_00472B20[p[0x1b7]].y;
 if(*(s16 *)(p+0x140)!=0) {
 *(f32 *)(p+0x34)=106.66666412353516f+*(f32 *)(q+0x34);
 } else {
 *(f32 *)(p+0x34)=*(f32 *)(q+0x34)-106.66666412353516f;
 motion->vx=-motion->vx;
 }
 *(f32 *)(p+0x38)=180.0f+*(f32 *)(q+0x38);
 p[0x1b5]=54+((s8 *)p)[0x1b7]*2;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(u32 *)(p+0x1d8)=0;
 D_004C2794->count[team[0]]++;
 p[0x1b4]=0;
 func_001757E0(p,20,0);
 ((s8 *)p)[0x31]=-8;
 }}
 ((s8 *)p)[0x24]=((s8 *)q)[0x24];
 if(((s8 *)p)[0x1b2]) {p[4]=3;return;}
 *(f32 *)(p+0x34)+=motion->vx;
 motion->vx+=*(f32 *)(p+0x68);
 *(f32 *)(p+0x38)+=*(f32 *)(p+0x60);
 *(f32 *)(p+0x60)+=*(f32 *)(p+0x6c);
 if(!(*(f32 *)(q+0x430)<=*(f32 *)(p+0x38)) || !func_00174240(p)) {
 p[4]=3;return;
 }
 func_00175700(p);
 func_001E7F60(p);
}

void func_003A1970(u8 *p,u8 *q)
{
 ActorVelocity *motion=(ActorVelocity *)p;
 ActorTimer *timer=(ActorTimer *)p;
 if(p[4]==0) {
 p[4]++;
  *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
    p[0x13C] = 1;
        p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
 {u8 *team=p+2;
 p[0x1b0]=66;p[0x1b1]=0;
 motion->vx=0.0f;
 *(f32 *)(p+0x60)=0.0f;
 *(f32 *)(p+0x68)=0.0f;
 *(f32 *)(p+0x6c)=0.0f;
 motion->vx=-8.333333015441895f;
 if(*(s16 *)(p+0x140)!=0) {
 *(f32 *)(p+0x34)=106.66666412353516f+*(f32 *)(q+0x34);
 motion->vx=-motion->vx;
 } else {
 *(f32 *)(p+0x34)=*(f32 *)(q+0x34)-106.66666412353516f;
 }
 *(f32 *)(p+0x38)=*(f32 *)(q+0x38);
 p[0x1b5]=7;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(u32 *)(p+0x1d8)=0;
 D_004C2794->count[team[0]]++;
 p[0x1b4]=0;
 func_00176160(q,1,1,1);
 timer->timer=16;
 func_001757E0(p,20,1);
 ((s8 *)p)[0x31]=-8;
 }}
 ((s8 *)p)[0x24]=((s8 *)q)[0x24];
 if(--timer->timer==0) {
 if(p[0x20]==0)q[0x2c4]=0;
 func_003DAA40(p);
 } else {
 *(f32 *)(p+0x34)+=motion->vx;
 motion->vx+=*(f32 *)(p+0x68);
 if((s8)func_00175700(p)<0) {
 if(p[0x20]==0)q[0x2c4]=0;
 func_003DAA40(p);
 } else func_001E7F60(p);
 }
}
