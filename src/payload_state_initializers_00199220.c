typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;

#include "actor_inherited_state.h"
typedef ActorState Payload;

typedef void (*Unary)(u8 *);
/* GP-addressed alias of jtbl_004BF5B8[4..5]. */
extern Unary const D_004BF5C8[] __attribute__((section(".sdata")));
extern Unary const D_0044CED0[];
extern void func_001993A0(u8 *);
extern void func_001C9B10(u8 *);
void func_00199220(u8 *p) {
 u8 *q;
 p[4]++;
 p[0x13C]=1;
 q=*(u8 **)(p+0x18);
 *(Payload *)(p+0xEC)=*(Payload *)(q+0xEC);
 p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 if(p[0x21]==0)p[0x24]=11;else p[0x24]=12;
 D_004BF5C8[p[0x20]](p);
 func_001993A0(p);
}
void func_001C9530(u8 *p) {
 u8 *q;
 p[4]++;
 p[0x13C]=1;
 q=*(u8 **)(p+0x18);
 *(Payload *)(p+0xEC)=*(Payload *)(q+0xEC);
 p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
 D_0044CED0[p[0x20]](p);
 func_001C9B10(p);
}
