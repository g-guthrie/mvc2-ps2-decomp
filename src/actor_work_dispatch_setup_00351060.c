#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {float x,y,z;} V3;

#include "actor_inherited_state.h"
typedef ActorState State;

extern float D_004624E0[][2],D_004624E4[][2];
extern int func_001757E0(u8*,int,int);
#define OWNER (*(u8**)(p+0x18))
void func_003510A0(u8*p){
 p[4]++;
 *(State*)(p+0xec)=*(State*)(OWNER+0xec);
 p[0x13c]=1;p[2]=OWNER[2];p[1]=OWNER[1];
 *(float*)(p+0x50)=*(float*)(OWNER+0x50);*(float*)(p+0x54)=*(float*)(OWNER+0x54);
 p[0x1b7]=OWNER[0x1b7];p[0x1b8]=OWNER[0x1b8];*(s8*)(p+0x30)=*(s8*)(OWNER+0x30);
 *(V3*)(p+0x50)=*(V3*)(OWNER+0x50);*(s8*)(p+0x24)=*(s8*)(OWNER+0x24);
 p[0x13c]=1;*(s16*)(p+0x140)=0;p[0x24]=0;p[0x1b0]=66;p[0x1b1]=66;
 *(float*)(p+0x34)=*(float*)(OWNER+0x34);*(float*)(p+0x38)=*(float*)(OWNER+0x38);
 p[0x14c]=56;p[0x14d]=56;p[0x14e]=80;p[0x14f]=80;*(s16*)(p+0x1c)=16;*(s16*)(p+0x1e)=3;
 *(u32*)(p+0x68)=0;*(u32*)(p+0x6c)=0;
 *(float*)(p+0x5c)=D_004624E0[p[0x20]][0];*(float*)(p+0x60)=D_004624E4[p[0x20]][0];
 func_001757E0(p,21,(u8)(p[0x20]+29));
}

typedef void (*Callback)(u8*);
extern Callback const jtbl_004624C0[8];
extern u8 *D_004C2960,*D_004C295C;
void func_00351060(u8*p){
 u8*owner=*(u8**)(p+0x18);
 D_004C2960=p+0xd0;
 D_004C295C=owner+0x2b8;
 (jtbl_004624C0+4)[p[4]](p);
}
