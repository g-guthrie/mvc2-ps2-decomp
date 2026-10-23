#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef struct {float x,y,z;} Vec3;
#include "actor_inherited_state.h"
extern void func_001A8E20(u8 *);
void func_001A8D70(u8 *p)
{
 u8 *owner=*(u8**)(p+0x18);
 p[4]++;
 *(u16*)(p+0x26)=0x1001;
 *(ActorState*)(p+0xEC)=*(ActorState*)(owner+0xEC);
 p[0x13C]=1;p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);
 *(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];
 *(s8*)(p+0x30)=*(s8*)(owner+0x30);
 *(Vec3*)(p+0x50)=*(Vec3*)(owner+0x50);
 *(s8*)(p+0x24)=*(s8*)(owner+0x24);
 func_001A8E20(p);
}
