#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
typedef struct {u8 prefix[0x34];V3 position;} Position;
extern int func_001757E0(u8*,int,int);
extern void func_0015E630(u8*);
void func_003C7D20(u8 *p,u8 *owner)
{
 float offset;Position *pos=(Position*)p;
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x31]=8;*(u8**)(p+0x14)=*(u8**)(owner+0x1DC);
 p[0x14C]=80;p[0x14D]=0;p[0x14E]=80;p[0x14F]=48;
 pos->position.y=*(float*)(owner+0x430);pos->position.x=*(float*)(owner+0x34);
 offset=-133.3333282470703f;if(*(s16*)(p+0x140))offset=-offset;
 pos->position.x=*(float*)(owner+0x34)+offset;func_0015E630(p);
 p[0]=1;func_001757E0(p,20,8);
}
