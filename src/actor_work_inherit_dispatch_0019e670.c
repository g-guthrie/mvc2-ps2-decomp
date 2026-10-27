#include "actor_effect_work_callbacks.h"
typedef signed char s8;typedef unsigned int u32;
typedef struct {float x,y,z;} V3;

#include "actor_inherited_state.h"
typedef ActorState State;

#define OWNER (*(u8**)(p+0x18))
void func_0019E670(u8*p,u8*work){
 p[4]++;
 *(State*)(p+0xec)=*(State*)(OWNER+0xec);
 p[0x13c]=1;p[2]=OWNER[2];p[1]=OWNER[1];
 *(float*)(p+0x50)=*(float*)(OWNER+0x50);*(float*)(p+0x54)=*(float*)(OWNER+0x54);
 p[0x1b7]=OWNER[0x1b7];p[0x1b8]=OWNER[0x1b8];*(s8*)(p+0x30)=*(s8*)(OWNER+0x30);
 *(V3*)(p+0x50)=*(V3*)(OWNER+0x50);*(s8*)(p+0x24)=*(s8*)(OWNER+0x24);

 jtbl_0044ACC0[p[0x20]](p,work);
}
