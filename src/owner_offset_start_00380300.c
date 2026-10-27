#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;typedef unsigned int u32;

#include "actor_inherited_state.h"
typedef ActorState Fields;
typedef struct {float x,y,z;} V3;typedef struct {u8 pad[0x7C];s16 count[2];} Counters;
extern Counters *D_004C2794 __attribute__((section(".sdata")));extern s16 D_004C1D48[] __attribute__((section(".sdata")));extern float D_004F1F4C;
extern int func_001757E0(u8*,int,int);extern void func_003804B0(u8*);
void func_00380300(u8*p) {
 u8 *owner=*(u8**)(p+0x18),*team;float offset;
 ++p[4];*(u16*)(p+0x26)=0x1900;*(Fields*)(p+0xEC)=*(Fields*)(owner+0xEC);p[0x13C]=1;team=p+2;
 *team=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 *(s16*)(p+0x140)=0;p[0x24]=10;p[0x31]=0;p[0x21]=0;p[0x20]=0;
 *(float*)(p+0x64)=*(float*)(p+0x50);*(float*)(p+0x70)=*(float*)(p+0x54);
 offset=1.6666666269302368f*D_004C1D48[p[0x23]];if(*(s16*)(owner+0x140))offset=-offset;
 *(float*)(p+0x34)=D_004F1F4C+offset;*(float*)(p+0x38)=*(float*)(owner+0x430);
 p[0x1B0]=68;p[0x1B1]=68;p[0x1B5]=48;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
 ++D_004C2794->count[*team];*(u16*)(p+0x1C0)|=0x200;
 func_001757E0(p,23,3);func_003804B0(p);
}
