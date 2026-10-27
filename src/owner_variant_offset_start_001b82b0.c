#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
extern u16 *D_004C26DC __attribute__((section(".sdata")));
extern int func_001754A0(u8*,int,int);
extern void func_001B8610(u8*);
#define OWNER (*(u8**)(p+0x18))
void func_001B82B0(u8 *p) {
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(OWNER+0xEC);p[0x13C]=1;
 p[2]=OWNER[2];p[1]=OWNER[1];
 *(float*)(p+0x50)=*(float*)(OWNER+0x50);*(float*)(p+0x54)=*(float*)(OWNER+0x54);
 p[0x1B7]=OWNER[0x1B7];p[0x1B8]=OWNER[0x1B8];p[0x30]=*(s8*)(OWNER+0x30);
 *(V3*)(p+0x50)=*(V3*)(OWNER+0x50);p[0x24]=*(s8*)(OWNER+0x24);p[0x24]=0;
 *(float*)(p+0x34)=*(float*)(OWNER+0x34);*(float*)(p+0x38)=*(float*)(OWNER+0x38);
 if(p[0x1B7]) {
  float dx=*(short*)(p+0x140)?35.0f:-35.0f;
  *(float*)(p+0x34)+=dx;*(float*)(p+0x38)+=62.1428566f;*(u32*)(p+0x48)=0x1C00;
 } else {
  float dx=*(short*)(p+0x140)?60.0f:-60.0f;
  *(float*)(p+0x34)+=dx;*(float*)(p+0x38)+=49.2857132f;*(u32*)(p+0x48)=0x2400;
 }
 func_001754A0(p,27,9);*D_004C26DC=*(u16*)(OWNER+0x168);*(float*)(p+0x118)=0.5f;func_001B8610(p);
}
