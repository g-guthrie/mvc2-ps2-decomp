#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
typedef struct {s16 reserved,x,y;} Offset;
extern s16 D_00473E10[][4],D_00473E12[][4];
extern s8 D_00473E14[][8];
extern u8 D_00473E16[][8];
extern int func_001757E0(u8*,int,int);
extern void func_003B3BB0(u8*,u8*);
void func_003B39C0(u8 *p,u8 *owner)
{
 Offset *offset=(Offset*)(p+0xD0);
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x13C]=1;*(s8*)(p+0x31)=-1;
 *(float*)(p+0x34)=*(float*)(owner+0x34);*(float*)(p+0x38)=*(float*)(owner+0x38);*(float*)(p+0x3C)=*(float*)(owner+0x3C);
 offset->x=(int)(1.6666666269302368f*(float)D_00473E10[p[0x21]][0]);
 offset->y=(int)(2.142857074737549f*(float)D_00473E12[p[0x21]][0]);
 if(*(s16*)(p+0x140))offset->x=-offset->x;
 p[0x1B5]=D_00473E14[p[0x21]][0];if(p[0x1B5]!=255){p[0x1B0]=67;p[0x1B1]=66;}
 func_001757E0(p,23,D_00473E16[p[0x21]][0]);func_003B3BB0(p,owner);
}
