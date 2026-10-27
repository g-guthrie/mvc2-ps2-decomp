#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
typedef struct {u16 h0;u8 pad2[2];float f4;} S9AC;
typedef struct Ent3847 Ent3847;
extern S9AC *D_004C29AC __attribute__((section(".sdata")));
extern int func_001757E0(u8*,int,int);
extern void func_003847D0(Ent3847*);
#define OWNER (*(u8**)(p+0x18))
void func_00384670(u8 *p)
{
 ++p[4];p[0x13C]=1;
*(Fields*)(p+0xEC)=*(Fields*)(OWNER+0xEC);p[0x13C]=1;
 p[2]=OWNER[2];p[1]=OWNER[1];
 *(float*)(p+0x50)=*(float*)(OWNER+0x50);*(float*)(p+0x54)=*(float*)(OWNER+0x54);
 p[0x1B7]=OWNER[0x1B7];p[0x1B8]=OWNER[0x1B8];p[0x30]=*(s8*)(OWNER+0x30);
 *(V3*)(p+0x50)=*(V3*)(OWNER+0x50);p[0x24]=*(s8*)(OWNER+0x24);
 *(s16*)(p+0x140)=*(s16*)(OWNER+0x140);D_004C29AC->h0=*(u16*)(OWNER+0x168);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;D_004C29AC->f4=0;
 *(float*)(p+0x5C)=*(s16*)(p+0x140)?1.6666666269302368f:-1.6666666269302368f;
 func_001757E0(p,23,3);func_003847D0((Ent3847*)p);
}
