#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
extern s16 D_004BF768[2] __attribute__((section(".sdata")));
extern int func_001754A0(u8*,int,int);
extern void func_001A72C0(u8*,void*);
void func_001A7160(u8 *p,void *owner_context) {
 u8 *q=owner_context;
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(q+0xEC);p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(float*)(p+0x50)=*(float*)(q+0x50);*(float*)(p+0x54)=*(float*)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];p[0x30]=*(s8*)(q+0x30);
 *(V3*)(p+0x50)=*(V3*)(q+0x50);p[0x24]=*(s8*)(q+0x24);
 p[0x13C]=1;*(s8*)(p+0x31)=-1;
 *(float*)(p+0x34)=*(float*)(q+0x34);*(float*)(p+0x38)=*(float*)(q+0x38);*(float*)(p+0x3C)=*(float*)(q+0x3C);
 *(s16*)(p+0x140)=p[0x21];
 *(float*)(p+0x34)+=(5.0f/3.0f)*D_004BF768[p[0x21]];
 func_001754A0(p,27,0);func_001A72C0(p,q);
}
