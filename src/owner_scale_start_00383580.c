#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;typedef unsigned int u32;

#include "actor_inherited_state.h"
typedef ActorState Fields;
typedef struct {float x,y,z;} V3;
typedef struct {u8 pad[0x7C];s16 count[2];} Counters;
extern Counters *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8*,int,int);extern void func_00383710(u8*);
#define OWNER (*(u8**)(p+0x18))
void func_00383580(u8*p) {
 u8 *team;
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(OWNER+0xEC);p[0x13C]=1;team=p+2;
 *team=OWNER[2];p[1]=OWNER[1];
 *(float*)(p+0x50)=*(float*)(OWNER+0x50);*(float*)(p+0x54)=*(float*)(OWNER+0x54);
 p[0x1B7]=OWNER[0x1B7];p[0x1B8]=OWNER[0x1B8];p[0x30]=*(s8*)(OWNER+0x30);
 *(V3*)(p+0x50)=*(V3*)(OWNER+0x50);p[0x24]=*(s8*)(OWNER+0x24);
 func_001757E0(p,23,16);
 p[0x1B0]=66;p[0x1B1]=66;p[0x24]=0;*(int*)(p+0x48)=410;
 *(float*)(p+0x50)*=1.5f;*(float*)(p+0x54)*=0.6666666865348816f;
 *(s16*)(p+0x1C)=8;p[0x1B5]=59;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
 ++D_004C2794->count[*team];p[7]=1;func_00383710(p);
}
