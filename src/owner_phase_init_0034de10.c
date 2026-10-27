/* Provisional: callback ABI, selector bounds and owner lifetime need proof. */
#pragma padloop on
#include "actor_inherited_state.h"
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {float x,y,z;} V3;
typedef void (*StateFn)(u8 *);
extern StateFn const jtbl_004C1A28[] __attribute__((section(".sdata")));
#define OWNER (*(u8 **)(p+0x18))
void func_0034DE10(u8 *p) {
 ++p[4]; *(ActorState *)(p+0xec)=*(ActorState *)(OWNER+0xec); p[0x13c]=1;
 p[2]=OWNER[2];p[1]=OWNER[1];
 *(float *)(p+0x50)=*(float *)(OWNER+0x50);*(float *)(p+0x54)=*(float *)(OWNER+0x54);
 p[0x1b7]=OWNER[0x1b7];p[0x1b8]=OWNER[0x1b8];p[0x30]=*(s8 *)(OWNER+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(OWNER+0x50);p[0x24]=*(s8 *)(OWNER+0x24);
 *(s16 *)(p+0x140)=*(s16 *)(OWNER+0x140);
 jtbl_004C1A28[p[0x20]](p);
}
