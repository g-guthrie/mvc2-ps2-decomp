#include "actor_inherited_state.h"
/* Preserve the owner snapshot and select the initial side-dependent offset. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x34];f32 x;} PositionView;
extern int func_001757E0(u8 *,int,int);
extern void func_0034CE70(u8 *);
void func_0034CCE0(u8 *p)
{
 u8 *owner=*(u8**)(p+0x18);
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
 p[0x13C]=1;
 *(s16*)(p+0x1E)=0;
 *(V3*)(p+0x34)=*(V3*)(owner+0x34);
 p[0x24]=12;
 *(s16*)(p+0x140)=p[0x20];
 p[0x1B0]=66;p[0x1B1]=66;
 if(!p[0x20]) *(f32*)(p+0x64)=213.333328f;
 else *(f32*)(p+0x64)=-213.333328f;
 *(f32*)(p+0x70)=171.428558f;
 ((PositionView*)p)->x+=*(f32*)(p+0x64);
 *(f32*)(p+0x38)+=*(f32*)(p+0x70);
 *(f32*)(p+0x48)=0;
 func_001757E0(p,22,25);
 func_0034CE70(p);
}
