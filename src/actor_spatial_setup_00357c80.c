#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef unsigned int u32;typedef short s16;

#include "actor_inherited_state.h"
typedef ActorState Fields;
typedef struct {float x,y,z;} V3;
extern u8 D_004C1AA8[] __attribute__((section(".sdata")));
extern void func_003577C0(u8*,u8),func_00357700(u8*),func_00357830(u8*),func_001E3210(u8*,int);
extern int func_001757E0(u8*,int,int);
extern s16 D_00462D80[],D_00462D82[];
static void func_003578A0(u8 *p) {
    float a, c;
    a = 1.666666627f * (float)D_00462D80[p[0x21] * 2];
    if (*(s16 *)(p + 0x140) != 0) a = -a;
    *(float *)(p + 0x34) = *(float *)(*(u8 **)(p + 0x18) + 0x34);
    *(float *)(p + 0x34) += a;
    c = 2.142857075f * (float)D_00462D82[p[0x21] * 2];
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38) + c;
}

#define OWNER (*(u8**)(p+0x18))
void func_00357C80(u8*p) {
 ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(OWNER+0xEC);p[0x13C]=1;
 p[2]=OWNER[2];p[1]=OWNER[1];
 *(float*)(p+0x50)=*(float*)(OWNER+0x50);*(float*)(p+0x54)=*(float*)(OWNER+0x54);
 p[0x1B7]=OWNER[0x1B7];p[0x1B8]=OWNER[0x1B8];p[0x30]=*(s8*)(OWNER+0x30);
 *(V3*)(p+0x50)=*(V3*)(OWNER+0x50);p[0x24]=*(s8*)(OWNER+0x24);
 p[0x13C]=1;p[0x23]=6;func_003578A0(p);
 p[0x24]=11;p[0x1B0]=0;p[0x1B1]=0;*(s16*)(p+0x1C)=1;p[6]=1;p[7]=0;*(s16*)(p+0x1E)=1;*(int*)(p+0xD0)=0;
 func_001757E0(p,21,D_004C1AA8[p[0x21]]);func_003577C0(p,2);func_003577C0(p,3);func_00357700(p);func_00357830(p);func_001E3210(p,30);
}
