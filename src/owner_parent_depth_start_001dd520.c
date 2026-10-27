#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
typedef struct {u8 prefix[0x31];s8 depth;} Depth;
/* Native factory call sites pass modes no greater than eight. */
extern u8 D_0044ECE0[9];
extern int func_001754A0(u8*,int,int);
extern void func_001DD660(u8*,u8*);
void func_001DD520(u8 *p,u8 *q) {
 *(Fields*)(p+0xEC)=*(Fields*)(q+0xEC);p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(float*)(p+0x50)=*(float*)(q+0x50);*(float*)(p+0x54)=*(float*)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];p[0x30]=*(s8*)(q+0x30);
 *(V3*)(p+0x50)=*(V3*)(q+0x50);p[0x24]=*(s8*)(q+0x24);
 ++p[4];((Depth*)p)->depth=-1;p[0x24]=8;
 if(p[0x20]==1) {p[0x24]=*(s8*)(*(u8**)(p+0x18)+0x24);*(s8*)(p+0x31)=-1;}
 *(V3*)(p+0x34)=*(V3*)(q+0x34);
 func_001754A0(p,27,D_0044ECE0[p[0x20]]);func_001DD660(p,q);
}
