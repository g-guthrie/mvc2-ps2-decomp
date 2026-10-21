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
extern int func_00175670(u8 *);
extern void func_001B6F10(u8 *);
extern void func_001B6F30(u8 *);
typedef struct {f32 x,y;} F32Pair;
/* B6830 modes3..7 select indices0..4 of this actual six-pair object. */
extern F32Pair data_f32v2_004B5800[6];
typedef struct {u8 prefix[0x34];f32 x,y,z;} ActorPosition;
typedef struct {u8 prefix[0x18];u8 *owner;} ActorOwner;
void func_001B6B60(u8 *p) {
 ActorOwner *links=(ActorOwner *)p;
 u8 *q=links->owner;
 u8 index=(s8)p[0x20]-3;
 u8 *work=q+0x2B8;
 ActorPosition *position=(ActorPosition *)p;
 switch(p[4]) {
 case 0:
  p[4]++;
  *(ActorState *)(p+0xEC)=*(ActorState *)(links->owner+0xEC);
  p[0x13C]=1;
  p[2]=(links->owner)[2];p[1]=(links->owner)[1];
  *(f32 *)(p+0x50)=*(f32 *)(links->owner+0x50);
  *(f32 *)(p+0x54)=*(f32 *)(links->owner+0x54);
  p[0x1B7]=(links->owner)[0x1B7];p[0x1B8]=(links->owner)[0x1B8];
  *(s8 *)(p+0x30)=*(s8 *)(links->owner+0x30);
  *(V3 *)(p+0x50)=*(V3 *)(links->owner+0x50);
  *(s8 *)(p+0x24)=*(s8 *)(links->owner+0x24);
  p[0x13C]=1;
  func_001754A0(p,27,(u8)(index+5));
  p[0x24]=0;
  *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
  if(*(s16 *)(p+0x140)) position->x-=data_f32v2_004B5800[index].x;
  else position->x+=data_f32v2_004B5800[index].x;
  position->y+=data_f32v2_004B5800[index].y;
  break;
 case 1:
  if(work[3] || q[0x1E4]!=21 || q[5]) func_001B6F10(p);
  else if((s8)func_00175670(p)<0) p[4]=0;
  break;
 case 2:
  func_001B6F30(p);
  break;
 }
}
