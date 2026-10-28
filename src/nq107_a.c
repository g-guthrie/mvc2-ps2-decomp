#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;

#include "actor_inherited_state.h"

typedef struct {float x,y,z;} V3_a;
typedef struct {u8 prefix[0x34];V3_a position;} Position_a;
typedef struct {u8 pad[0x7C]; s16 f7c[4];} G_a;
extern G_a *D_004C2794;
void func_00376B10(u8 *p, u8 *owner)
{
 float offset;Position_a *pos=(Position_a*)p;
 ++p[4];
 *(ActorState*)(p+0xEC)=*(ActorState*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3_a*)(p+0x50)=*(V3_a*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0]=1;p[0x24]=0;
 p[0x1B5]=*(s8*)(owner+0x212)+0x30;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;
 *(u32*)(p+0x1D8)=0;
 { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
 p[0x1B0]=0x44;p[0x1B1]=0x44;
 *(u16*)(p+0x1C0)|=0x200;
 p[0x14E]=0x30;p[0x14F]=0x30;
 pos->position=*(V3_a*)(owner+0x34);
 offset=-140.0f;
 if(*(s16*)(p+0x140))offset=-offset;
 pos->position.x+=offset;
 {extern int func_001757E0(u8*,int,int); func_001757E0(p,0x17,4);}
 {extern void func_0015E630(u8*); func_0015E630(p);}
}
