#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

typedef struct { s16 x,y; } MotionPair;
extern MotionPair D_00473EF0[],D_00473E70[];
typedef struct {u8 prefix[0x5c];f32 vx;} ActorVelocity;
extern int func_001757E0(u8 *,int,int);
void func_003B47C0(u8 *p,u8 *q)
{
 f32 *v=(f32 *)(p+0x88);
 ActorVelocity *motion=(ActorVelocity *)p;
 u8 *parent=*(u8 **)(p+0x14);
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


 p[0x13c]=0;
 p[0x24]=((s8 *)q)[0x24]+1;
 if(p==*(u8 **)(parent+0xc)) {
  v[2]=1.6666666269302368f*(f32)D_00473EF0[parent[0x23]].x/256.0f;
  v[3]=2.142857074737549f*(f32)D_00473EF0[parent[0x23]].y/256.0f;
  *(f32 *)(p+0x5c)=0.0f;
  *(f32 *)(p+0x60)=0.0f;
  *(f32 *)(p+0x68)=0.0f;
  *(f32 *)(p+0x6c)=0.0f;
  motion->vx=1.6666666269302368f*(f32)D_00473E70[q[0x1b7]].x/256.0f;
  *(f32 *)(p+0x60)=2.142857074737549f*(f32)D_00473E70[q[0x1b7]].y/256.0f;
  if(*(s16 *)(q+0x140)==0) {
   motion->vx=-motion->vx;
   v[2]=-v[2];
  }
 }
 switch(parent[0x23]) {
 case 0:p[0x21]=8;break;
 case 1:p[0x21]=4;break;
 case 2:p[0x21]=12;break;
 case 3:p[0x21]=8;break;
 case 4:p[0x21]=4;break;
 case 5:p[0x21]=12;break;
 }
 func_001757E0(p,0x15,p[0x21]);
}
