#include "actor_effect_work_callbacks.h"
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
extern int func_00174170(void);
extern int func_001754A0(u8*,int,int);
void func_0019D300(u8 *p,u8 *q) {
 s16 x,y;
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(q+0xEC);p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(float*)(p+0x50)=*(float*)(q+0x50);*(float*)(p+0x54)=*(float*)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];p[0x30]=*(s8*)(q+0x30);
 *(V3*)(p+0x50)=*(V3*)(q+0x50);p[0x24]=*(s8*)(q+0x24);*(s8*)(p+0x31)=-1;
 x=0;y=0;
 if(p[0x20]) {
  x=15;if(*(s16*)(p+0x140))x=-15;
  x=(func_00174170()&7)+x;y=37+(func_00174170()&7);*(s16*)(p+0x13E)-=3;
 }
 *(float*)(p+0x34)=*(float*)(q+0x34)+(5.0f/3.0f)*(float)x;
 *(float*)(p+0x38)=*(float*)(q+0x38)+(15.0f/7.0f)*(float)y;
 *(u32*)(p+0xD0)=*(u16*)(q+0x168);
 func_001754A0(p,27,(u8)(p[0x20]+26));
}
