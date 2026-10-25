#include "actor_effect_work_callbacks.h"
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef struct {u32 words[49];} Fields;
typedef struct {float x,y,z;} V3;
extern int func_001754A0(u8*,int,int);
void func_0019D860(u8 *p,u8 *owner)
{
 ++p[4];
 if(!p[0x20]) {p[0x13C]=0;*(s16*)(p+0x1C)=0;}
 else {
  *(Fields*)(p+0xEC)=*(Fields*)(owner+0xEC);p[0x13C]=1;
  p[2]=owner[2];p[1]=owner[1];
  *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
  p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
  *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
  p[0x13C]=1;p[0x31]=1;*(s16*)(p+0x13E)+=4;
  *(V3*)(p+0x34)=*(V3*)(owner+0x34);*(s16*)(p+0x1E)=23;
  if(*(s8*)(owner+0x161)>=32)func_001754A0(p,28,*(s8*)(owner+0x161)&15);
 }
}
