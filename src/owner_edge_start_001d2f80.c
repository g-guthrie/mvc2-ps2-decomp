#include "owner_edge_motion.h"
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef struct {u32 words[49];} Fields;
typedef struct {float x,y,z;} V3;
typedef struct {u8 prefix[0x5C];float vx;} Motion;
extern float D_004F1FC8,D_004F1FCC;
extern void func_0015E630(u8*);
extern int func_001757E0(u8*,int,int);
void func_001D2F80(struct P1D3 *actor,struct Q1D3 *owner_context) {
 u8 *p=(u8*)actor;
 u8 *q=(u8*)owner_context;
 float x;
 *(Fields*)(p+0xEC)=*(Fields*)(q+0xEC);p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(float*)(p+0x50)=*(float*)(q+0x50);*(float*)(p+0x54)=*(float*)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];p[0x30]=*(s8*)(q+0x30);
 *(V3*)(p+0x50)=*(V3*)(q+0x50);p[0x24]=*(s8*)(q+0x24);
 ++p[4];p[0x24]=11;*(float*)(p+0x38)=*(float*)(q+0x430);
 x=D_004F1FCC+(5.0f/3.0f)*64;((Motion*)p)->vx=-10;
 if(q[0x1E6]) {x=D_004F1FC8-(5.0f/3.0f)*64;*(float*)(p+0x5C)=-*(float*)(p+0x5C);}
 *(float*)(p+0x34)=x;func_0015E630(p);func_001757E0(p,23,28);
}
