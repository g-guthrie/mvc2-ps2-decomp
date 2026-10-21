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

extern int func_001754A0(u8 *,int,int);
void func_001CE7B0(u8 *p) {
 f32 offset;
 p[4]++;
 *(ActorState *)(p+0xEC)=*(ActorState *)(*(u8 **)(p+0x18)+0xEC);
 p[0x13C]=1;
 p[2]=(*(u8 **)(p+0x18))[2];
 p[1]=(*(u8 **)(p+0x18))[1];
 *(f32 *)(p+0x50)=*(f32 *)(*(u8 **)(p+0x18)+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(*(u8 **)(p+0x18)+0x54);
 p[0x1B7]=(*(u8 **)(p+0x18))[0x1B7];
 p[0x1B8]=(*(u8 **)(p+0x18))[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(*(u8 **)(p+0x18)+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(*(u8 **)(p+0x18)+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(*(u8 **)(p+0x18)+0x24);
 *(s16 *)(p+0x140)^=1;
 *(f32 *)(p+0x34)=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 if(*(s16 *)(p+0x140)) offset=-213.3333282470703f;
 else offset=213.3333282470703f;
 *(f32 *)(p+0x34)+=offset;
 *(f32 *)(p+0x38)=*(f32 *)(*(u8 **)(p+0x18)+0x430);
 *(f32 *)(p+0x38)+=34.28571319580078f;
 p[0x13C]=0;
 func_001754A0(p,27,1);
}
