#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Vec3;
#include "actor_inherited_state.h"
extern const s8 D_004C2188[] __attribute__((section(".sdata")));
extern const u8 D_004C2180[] __attribute__((section(".sdata")));
extern int func_00174170(void);
extern int func_001754A0(u8 *,int,int);
extern void func_003CD9B0(u8 *,u8 *);
void func_003CD750(u8 *p,u8 *owner)
{
 p[4]++;
 *(ActorState*)(p+0xEC)=*(ActorState*)(owner+0xEC);
 p[0x13C]=1;p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];
 *(s8*)(p+0x30)=*(s8*)(owner+0x30);
 *(Vec3*)(p+0x50)=*(Vec3*)(owner+0x50);
 *(s8*)(p+0x24)=*(s8*)(owner+0x24);
 *(s8*)(p+0x31)=D_004C2188[p[0x20]];
 p[0x24]=8;
 *(Vec3*)(p+0x34)=*(Vec3*)(owner+0x34);
 if(p[0x20]>=5) {
  float x=-13.33333301544189453125f;
  if(*(s16*)(p+0x140))x=-x;
  *(float*)(p+0x34)+=x;
  *(float*)(p+0x38)+=34.28571319580078125f;
 }
 if(p[0x20]>=5) {
  float x=1.66666662693023681640625f*(float)(((u32)func_00174170()&63)<<4)/256.0f;
  if(*(s16*)(p+0x140)==0)x=-x;
  *(float*)(p+0x5C)=x;
  *(float*)(p+0x60)=2.142857074737548828125f*(float)(((u32)func_00174170()&63)<<4)/256.0f;
  *(float*)(p+0x6C)=-0.803571403026580810546875f;
 }
 func_001754A0(p,27,D_004C2180[p[0x20]]);
 func_003CD9B0(p,owner);
}
