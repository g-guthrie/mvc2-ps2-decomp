#include "actor_inherited_state.h"
/* Inherit owner state and position, offset sideways, then grow both scales. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x34];f32 x;} PositionView;
extern void func_00347C70(u8 *);
void func_00347B10(u8 *p)
{
 ++p[4];
 *(ActorState*)(p+0xEC)=*(ActorState*)(*(u8**)(p+0x18)+0xEC);
 p[0x13C]=1;
 p[2]=(*(u8**)(p+0x18))[2];
 p[1]=(*(u8**)(p+0x18))[1];
 *(f32*)(p+0x50)=*(f32*)(*(u8**)(p+0x18)+0x50);
 *(f32*)(p+0x54)=*(f32*)(*(u8**)(p+0x18)+0x54);
 p[0x1B7]=(*(u8**)(p+0x18))[0x1B7];
 p[0x1B8]=(*(u8**)(p+0x18))[0x1B8];
 *(s8*)(p+0x30)=*(s8*)(*(u8**)(p+0x18)+0x30);
 *(V3*)(p+0x50)=*(V3*)(*(u8**)(p+0x18)+0x50);
 *(s8*)(p+0x24)=*(s8*)(*(u8**)(p+0x18)+0x24);
 *(f32*)(p+0x34)=*(f32*)(*(u8**)(p+0x18)+0x34);
 *(f32*)(p+0x38)=*(f32*)(*(u8**)(p+0x18)+0x38);
 *(f32*)(p+0x3C)=*(f32*)(*(u8**)(p+0x18)+0x3C);
 if(*(s16*)(p+0x140)) ((PositionView*)p)->x+=53.333332f;
 else ((PositionView*)p)->x-=53.333332f;
 *(f32*)(p+0x50)+=0.03f;
 *(f32*)(p+0x54)+=0.03f;
 p[0x24]=11;
 func_00347C70(p);
}
