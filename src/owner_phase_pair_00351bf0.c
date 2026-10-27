/* Provisional: callback table ABI, phase bounds and owner lifetime need proof. */
typedef unsigned char u8;
typedef void (*Phase)(u8 *);
extern u8 *D_004C2968 __attribute__((section(".sdata")));
extern u8 *D_004C2964 __attribute__((section(".sdata")));
extern Phase const jtbl_00462630[];
void func_00351BF0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 D_004C2968=p+0xd0; D_004C2964=owner+0x2b8;
 jtbl_00462630[p[4]](p);
}

#pragma padloop on
#include "actor_inherited_state.h"
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {float x,y,z;} V3;
typedef void (*StateFn)(u8 *);
extern StateFn const jtbl_004C1A68[] __attribute__((section(".sdata")));
#define OWNER (*(u8 **)(p+0x18))
void func_00351C30(u8 *p) {
 ++p[4]; *(ActorState *)(p+0xec)=*(ActorState *)(OWNER+0xec); p[0x13c]=1;
 p[2]=OWNER[2];p[1]=OWNER[1];
 *(float *)(p+0x50)=*(float *)(OWNER+0x50);*(float *)(p+0x54)=*(float *)(OWNER+0x54);
 p[0x1b7]=OWNER[0x1b7];p[0x1b8]=OWNER[0x1b8];p[0x30]=*(s8 *)(OWNER+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(OWNER+0x50);p[0x24]=*(s8 *)(OWNER+0x24);
 *(unsigned int *)(p+0x68)=0; *(unsigned int *)(p+0x6c)=0;
 jtbl_004C1A68[p[0x20]](p);
}
