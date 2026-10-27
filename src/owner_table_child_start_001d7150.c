#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;

#include "actor_inherited_state.h"
typedef ActorState State;

typedef struct {float x,y,z;} V3;
typedef struct {s16 x,y; s8 animation;u8 pad;} Row;
/* Eight native six-byte records; the parent emits indices zero through seven. */
extern Row D_0044E630[8];
extern int func_001754A0(u8*,int,int);extern void func_001D7340(u8*,u8*);
void func_001D7150(u8*p,u8*owner){
 ++p[4];*(State*)(p+0xEC)=*(State*)(owner+0xEC);p[0x13C]=1;p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 *(float*)(p+0x34)=*(float*)(owner+0x34);*(float*)(p+0x38)=*(float*)(owner+0x38);
 if(p[0x20]==0){p[0x13C]=0;*(int*)(p+0xD0)=0;*(int*)(p+0xD4)=0;*(int*)(p+0xD8)=0;}
 else{
  s16 dx;
  p[0x13C]=1;p[0x24]=0;
  dx=D_0044E630[*(int*)(p+0xD4)].x;
  if(*(s16*)(p+0x140))dx=-dx;
  *(float*)(p+0x34)+=1.6666666269302368f*dx;
  *(float*)(p+0x38)+=2.142857074737549f*D_0044E630[*(int*)(p+0xD4)].y;
  p[0x21]=D_0044E630[*(int*)(p+0xD4)].animation;
  func_001754A0(p,27,(u8)(p[0x21]+6));
 }
 func_001D7340(p,owner);
}
