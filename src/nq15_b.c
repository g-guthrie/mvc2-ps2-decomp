#include "actor_inherited_state.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef struct {float x,y,z;} V3;
typedef struct {s16 x[4],y[4];} Samples;
extern void func_003A7D10(u8 *, u8 *);
void residual_003A7C60(u8 *p,u8 *owner)
{
 ++p[4];*(ActorState*)(p+0xEC)=*(ActorState*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x13C]=0;*(s8*)(p+0x31)=-2;*(s16*)(p+0x1C)=4;
 func_003A7D10(p,owner);
}
