#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

typedef struct {u8 prefix[0x34];f32 x,y;} ActorPosition;
typedef struct {u8 prefix[0x5c];f32 vx,vy;u32 pad64;f32 ax;} ActorVelocity;
typedef struct {s32 x,y,vx,ax;} LaunchPreset;
extern LaunchPreset D_00473F10[];
extern int func_001757E0(u8 *,int,int);
extern u8 *func_003B4120(u8 *);
void func_003B4A10(u8 *p,u8 *q)
{
 u8 *state=q+0x2b8;
 f32 *v=(f32 *)(p+0x88);
 ActorPosition *position=(ActorPosition *)p;
 ActorVelocity *motion=(ActorVelocity *)p;
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


 switch(p[0x23]) {
 case 0:p[0x21]=9;break;
 case 1:p[0x21]=5;break;
 case 2:p[0x21]=13;break;
 case 3:p[0x21]=9;break;
 case 4:p[0x21]=5;break;
 case 5:p[0x21]=13;break;
 }
 if(*(s16 *)(q+0x140)==0) {
  v[2]=-(1.6666666269302368f*(f32)D_00473F10[p[0x23]].x/65536.0f);
  v[3]=2.142857074737549f*(f32)D_00473F10[p[0x23]].y/65536.0f;
  motion->vx=-(1.6666666269302368f*(f32)D_00473F10[p[0x23]].vx/65536.0f);
  motion->ax=-(1.6666666269302368f*(f32)D_00473F10[p[0x23]].ax/65536.0f);
 } else {
  v[2]=1.6666666269302368f*(f32)D_00473F10[p[0x23]].x/65536.0f;
  v[3]=2.142857074737549f*(f32)D_00473F10[p[0x23]].y/65536.0f;
  motion->vx=1.6666666269302368f*(f32)D_00473F10[p[0x23]].vx/65536.0f;
  motion->ax=1.6666666269302368f*(f32)D_00473F10[p[0x23]].ax/65536.0f;
 }
 position->x=*(f32 *)(q+0x34)+v[2];
 position->y=*(f32 *)(q+0x38)+v[3];
 func_001757E0(p,0x15,p[0x21]);
 ((s8 *)p)[0x31]=-2;
 if(func_003B4120(p)==0) {
  p[4]=3;
  p[0x13c]=0;
  state[4]=1;
 }
}
