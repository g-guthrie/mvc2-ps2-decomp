/* Solve the launch trajectory using the native sixteen-byte movement records. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#include "launch_record.h"
extern int func_001A9650(u8 *,float);
extern int func_001754A0(u8 *,int,int);
extern void func_001A9070(u8 *,u8 *);
void func_001A8E70(u8 *p,u8 *owner)
{
 const LaunchRecord *record;
 s32 *phaseRate=(s32*)(p+0xD0);
 float distance,limit;
 int steps;
 p[5]++;
 record=&D_0044B570[p[0x20]];
 *(s8*)(p+0x24)=record->layer;
 if(*(s16*)(p+0x140)==0) {
  *(float*)(p+0x34)=*(float*)(owner+0x34)+1.66666662693023681640625f*record->x;
 } else {
  *(float*)(p+0x34)=*(float*)(owner+0x34)-1.66666662693023681640625f*record->x;
 }
 *(float*)(p+0x38)=*(float*)(owner+0x38)+2.142857074737548828125f*record->y;
 if(*(s16*)(owner+0x140)==0)distance=1.66666662693023681640625f*record->targetX-1.66666662693023681640625f*record->x;
 else distance=-(1.66666662693023681640625f*record->targetX-1.66666662693023681640625f*record->x);
 limit=*(float*)(owner+0x430)+2.142857074737548828125f*record->targetY;
 *(float*)(p+0x60)=record->velocityY;
 *(float*)(p+0x6C)=-0.803571403026580810546875f;
 steps=func_001A9650(p,limit);
 *(float*)(p+0x5C)=distance/(float)steps;
 *(float*)(p+0x68)=0;
 *phaseRate=((s32)record->phase*65536)/steps;
 func_001754A0(p,27,record->frame);
 func_001A9070(p,owner);
}
