#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
typedef struct {s16 x[4],y[4];} Samples;
extern int func_001757E0(u8*,int,int);
extern void func_003B2750(u8*,u8*);
void func_003B25D0(u8 *p,u8 *owner)
{
 Samples *samples=(Samples*)(p+0x5C);u8 *parent=*(u8**)(p+0x14);int i;
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x13C]=1;*(s8*)(p+0x31)=-1;
 *(float*)(p+0x34)=*(float*)(parent+0x34);*(float*)(p+0x38)=*(float*)(parent+0x38);*(float*)(p+0x3C)=*(float*)(parent+0x3C);
 for(i=0;i<4;++i){samples->x[i]=(int)*(float*)(p+0x34);samples->y[i]=(int)*(float*)(p+0x38);}
 func_001757E0(p,23,12);func_003B2750(p,owner);
}
