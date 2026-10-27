typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;

#include "actor_inherited_state.h"
typedef ActorState Payload;

extern int func_001754A0(u8*,int,int);
extern void func_001BB020(u8*,u8*);
void func_001BAEE0(u8*p,u8*q){p[4]=1;p[0x13c]=1;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x24]=0;*(V3*)(p+0x34)=*(V3*)(q+0x34);
*(f32*)(p+0x34)=*(f32*)(p+0x34)+(*(s16*)(q+0x140)?-60.0f:60.0f);
func_001754A0(p,27,6);*(f32*)(p+0x118)=0.2f;func_001BB020(p,q);}
extern void func_001C1590(u8*);
void func_001C1470(u8*p){u8*q;
p[4]++;*(unsigned short*)(p+0x26)=0x1c01;p[0x13c]=1;q=*(u8**)(p+0x18);
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
*(s8*)(p+0x31)=-1;*(f32*)(p+0x34)=*(f32*)(q+0x34);
if(p[0x20])func_001754A0(p,27,1);else func_001754A0(p,27,2);
func_001C1590(p);}
