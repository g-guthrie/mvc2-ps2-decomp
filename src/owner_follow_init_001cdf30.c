#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef unsigned int u32;typedef float f32;typedef struct {f32 x,y,z;} V3;
#include "actor_inherited_state.h"
extern int func_001757E0(u8 *,int,int);
#define OWNER (*(u8 **)(p+0x18))
void func_001CDF30(u8 *p) {
 p[5]++;*(ActorState *)(p+0xec)=*(ActorState *)(OWNER+0xec);p[0x13c]=1;p[2]=OWNER[2];p[1]=OWNER[1];
 *(f32 *)(p+0x50)=*(f32 *)(OWNER+0x50);*(f32 *)(p+0x54)=*(f32 *)(OWNER+0x54);p[0x1b7]=OWNER[0x1b7];p[0x1b8]=OWNER[0x1b8];*(s8 *)(p+0x30)=*(s8 *)(OWNER+0x30);*(V3 *)(p+0x50)=*(V3 *)(OWNER+0x50);*(s8 *)(p+0x24)=*(s8 *)(OWNER+0x24);p[0x24]=0;*(f32 *)(p+0x34)=*(f32 *)(OWNER+0x34);*(f32 *)(p+0x38)=*(f32 *)(OWNER+0x38)-6.428571224212646484375f;func_001757E0(p,23,0);}
