#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
#include "actor_inherited_state.h"
typedef struct {u8 prefix[0x34];f32 x,y,z;} ActorPosition;
extern f32 D_004F1FC8 __attribute__((section(".bss")));
extern f32 D_004F1FCC __attribute__((section(".bss")));
extern f32 D_004F1FD0 __attribute__((section(".bss")));
extern void func_00176160(u8 *,int,int,int);
extern void func_0015E630(u8 *);
extern int func_001754A0(u8 *,int,int);
void func_001B1D20(u8 *p) {
 u8 *q;
 ActorPosition *position=(ActorPosition *)p;
 f32 distance=104.99999237060547f;
 f32 offset;
 p[4]++;
 q=*(u8 **)(p+0x18);
 *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
 p[0x13c]=1;p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x13c]=1;
 p[0x24]=14;
 *(s16 *)(p+0x140)=*(s16 *)(*(u8 **)(p+0x18)+0x140);
 position->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 position->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 position->z=*(f32 *)(*(u8 **)(p+0x18)+0x3c);
 { f32 x;
 if(*(s16 *)(p+0x140))x=D_004F1FC8;
 else x=D_004F1FCC;
 position->x=x; }
 if(*(s16 *)(p+0x140))offset=distance;
 else offset=-distance;
 position->x+=offset;
 position->y=34.28571319580078f+D_004F1FD0;
 *(f32 *)(p+0x68)=0.0f;*(f32 *)(p+0x6c)=0.0f;
 *(f32 *)(p+0x6c)=-1.7678570747375488f;
 func_00176160(q,3,3,1);
 func_0015E630(p);
 p[0]=1;
 func_001754A0(p,27,10);
}

void func_001B1EE0(u8 *p) {
 u8 *q;
 ActorPosition *position=(ActorPosition *)p;
 f32 distance=104.99999237060547f;
 f32 offset;
 p[4]++;
 q=*(u8 **)(p+0x18);
 *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
 p[0x13c]=1;p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x13c]=1;
 p[0x24]=13;
 *(s16 *)(p+0x140)=*(s16 *)(*(u8 **)(p+0x18)+0x140);
 position->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 position->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 position->z=*(f32 *)(*(u8 **)(p+0x18)+0x3c);
 { f32 x;
 if(*(s16 *)(p+0x140))x=D_004F1FC8;
 else x=D_004F1FCC;
 position->x=x; }
 if(*(s16 *)(p+0x140))offset=distance;
 else offset=-distance;
 position->x+=offset;
 position->y=34.28571319580078f+D_004F1FD0;
 *(f32 *)(p+0x68)=0.0f;*(f32 *)(p+0x6c)=0.0f;
 *(f32 *)(p+0x6c)=-0.964285671710968f;
 func_00176160(q,2,2,1);
 func_001754A0(p,27,9);
}
