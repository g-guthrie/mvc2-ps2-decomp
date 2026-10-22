#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
#include "actor_inherited_state.h"
typedef struct {float x,y,z;} Vec3;
extern int func_001757E0(u8 *,int,int),func_001754A0(u8 *,int,int);
extern void func_001D35F0(u8 *);

void func_00199700(u8 *p)
{
 *(ActorState*)(p+0xEC)=*(ActorState*)(*(u8**)(p+0x18)+0xEC);
 p[0x13C]=1;
 p[2]=(*(u8**)(p+0x18))[2];
 p[1]=(*(u8**)(p+0x18))[1];
 *(float*)(p+0x50)=*(float*)(*(u8**)(p+0x18)+0x50);
 *(float*)(p+0x54)=*(float*)(*(u8**)(p+0x18)+0x54);
 p[0x1B7]=(*(u8**)(p+0x18))[0x1B7];
 p[0x1B8]=(*(u8**)(p+0x18))[0x1B8];
 *(s8*)(p+0x30)=*(s8*)(*(u8**)(p+0x18)+0x30);
 *(Vec3*)(p+0x50)=*(Vec3*)(*(u8**)(p+0x18)+0x50);
 *(s8*)(p+0x24)=*(s8*)(*(u8**)(p+0x18)+0x24);
 p[0x24]=0;
 *(float*)(p+0x34)=*(float*)(*(u8**)(p+0x18)+0x34);
 *(float*)(p+0x38)=*(float*)(*(u8**)(p+0x18)+0x38);
 func_001757E0(p,0x17,0xC);
}

void func_001C00E0(u8 *p)
{
 p[0x13C]=1;
 p[4]++;
 if(p[0x21]==0) {
  *(float*)(p+0x50)*=0.8f;
  *(float*)(p+0x54)*=0.8f;
 } else if(p[0x21]!=1) {
  *(float*)(p+0x50)*=1.2f;
  *(float*)(p+0x54)*=1.2f;
 }
 p[0x24]=8;
 func_001754A0(p,0x1B,2);
}

void func_001D3540(u8 *p)
{
 u8 *owner;
 p[4]++;
 owner=*(u8**)(p+0x18);
 *(ActorState*)(p+0xEC)=*(ActorState*)(owner+0xEC);
 p[0x13C]=1;
 p[2]=owner[2];
 p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);
 *(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];
 p[0x1B8]=owner[0x1B8];
 *(s8*)(p+0x30)=*(s8*)(owner+0x30);
 *(Vec3*)(p+0x50)=*(Vec3*)(owner+0x50);
 *(s8*)(p+0x24)=*(s8*)(owner+0x24);
 *(s16*)(p+0x1C)=-1;
 func_001D35F0(p);
}

extern void func_0034BDF0(u8 *);
void func_0034BD00(u8 *p)
{
 p[4]++;
 *(ActorState*)(p+0xEC)=*(ActorState*)(*(u8**)(p+0x18)+0xEC);
 p[0x13C]=1;
 p[2]=(*(u8**)(p+0x18))[2];
 p[1]=(*(u8**)(p+0x18))[1];
 *(float*)(p+0x50)=*(float*)(*(u8**)(p+0x18)+0x50);
 *(float*)(p+0x54)=*(float*)(*(u8**)(p+0x18)+0x54);
 p[0x1B7]=(*(u8**)(p+0x18))[0x1B7];
 p[0x1B8]=(*(u8**)(p+0x18))[0x1B8];
 *(s8*)(p+0x30)=*(s8*)(*(u8**)(p+0x18)+0x30);
 *(Vec3*)(p+0x50)=*(Vec3*)(*(u8**)(p+0x18)+0x50);
 *(s8*)(p+0x24)=*(s8*)(*(u8**)(p+0x18)+0x24);
 p[0x13C]=0;
 p[0x21]=0;
 *(float*)(p+0x38)=*(float*)(*(u8**)(p+0x18)+0x430);
 p[0x24]=0;
 p[0x1B0]=0x47;
 p[0x1B1]=1;
 func_0034BDF0(p);
}
