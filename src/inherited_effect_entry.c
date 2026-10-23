#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Vec3;
#include "actor_inherited_state.h"
extern void func_001A3A10(u8 *,u8,u8),func_001A3C00(u8 *,u8 *);

void func_001A3AE0(u8 *p,u8 *owner)
{
 p[4]++;
 p[0x22]=0xFF;
 *(ActorState*)(p+0xEC)=*(ActorState*)(owner+0xEC);
 p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);
 *(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];
 *(s8*)(p+0x30)=*(s8*)(owner+0x30);
 *(Vec3*)(p+0x50)=*(Vec3*)(owner+0x50);
 *(s8*)(p+0x24)=*(s8*)(owner+0x24);
 *(float*)(p+0x68)=0.0f;*(float*)(p+0x6C)=0.0f;
 *(s8*)(p+0x24)=*(s8*)(owner+0x24);
 *(s8*)(p+0x31)=-8;
 if(p[0x21]==0) {
  func_001A3A10(owner,0,1);
  func_001A3A10(owner,0,2);
 }
 func_001A3C00(p,owner);
}
