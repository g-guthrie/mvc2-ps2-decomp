#pragma padloop on
typedef int s32;typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
typedef struct {u8 prefix[0x34];float x;} Position;

#include "actor_inherited_state.h"
typedef ActorState State;

typedef struct {u8 prefix[0x7C];s16 count[2];} Counters;
typedef struct {s16 value,pad[3];} Column;
extern Column D_00461F60[],D_00461F62[],D_00461F64[],D_00461F66[];
extern Counters *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8*,int,int);extern void func_0015E630(u8*);
typedef struct {u8 prefix[0x1B5];u8 action;} ActorActionView;
static inline void reset_action(u8 *p,u8 action){
 s32 index; s16 count;
 ((ActorActionView*)p)->action=action;p[0x1B2]=(*(u16*)(p+0x1C0)=0);*(u32*)(p+0x1D8)=0;
 index=p[2];count=D_004C2794->count[index];D_004C2794->count[index]=count+1;
}

void func_0034A1E0(u8*p,void*owner_context){
 u8*owner=owner_context;
 u8*work=p+0x88;u8*manager=*(u8**)(p+0x14);
 ++p[4];p[5]=0;*(State*)(p+0xEC)=*(State*)(owner+0xEC);
 p[0x13C]=1;p[2]=owner[2];p[1]=owner[1];*(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);*(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 work[1]=3;work[0]=0;*(u32*)(p+0x14C)=0x60003030;p[0x1B0]=66;p[0x1B1]=66;
 reset_action(p,*(s8*)(p+0x20)+72);
 ((Position*)p)->x=80;
 if(*(s16*)(manager+0x140))*(float*)(p+0x34)=*(float*)(p+0x34)+*(float*)(p+0x5C);else *(float*)(p+0x34)=-*(float*)(p+0x34)+*(float*)(p+0x5C);
 *(float*)(p+0x38)=*(float*)(owner+0x430);*(float*)(p+0x5C)=0;*(float*)(p+0x68)=0;
 *(s16*)(p+0x1C)=D_00461F60[p[0x20]].value;*(s16*)(p+0x1E)=D_00461F62[p[0x20]].value;
 *(float*)(p+0x60)=(2.142857074737549f*(float)D_00461F64[p[0x20]].value)/256.0f;
 *(float*)(p+0x6C)=(2.142857074737549f*(float)D_00461F66[p[0x20]].value)/256.0f;
 p[0x169]=22;p[0x168]=44;func_001757E0(p,p[0x169],p[0x168]);func_0015E630(p);p[0]=1;
}
