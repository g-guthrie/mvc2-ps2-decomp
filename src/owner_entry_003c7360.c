/* Provisional: owner lifetime, callback ABI, and selector bounds remain unresolved. */
#include "actor_inherited_state.h"
typedef unsigned char u8; typedef signed char s8; typedef short s16; typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
extern int func_001757E0(u8 *,int,int);
void func_003C7360(u8 *p,u8 *owner)
{
    float x, velocity;
    ++p[4]; *(ActorState *)(p+0xec)=*(ActorState *)(owner+0xec); p[0x13c]=1;
    p[2]=owner[2];p[1]=owner[1];
    *(float *)(p+0x50)=*(float *)(owner+0x50);*(float *)(p+0x54)=*(float *)(owner+0x54);
    p[0x1b7]=owner[0x1b7];p[0x1b8]=owner[0x1b8];p[0x30]=*(s8 *)(owner+0x30);
    *(V3 *)(p+0x50)=*(V3 *)(owner+0x50);p[0x24]=*(s8 *)(owner+0x24);
    p[0x31]=8;*(u8 **)(p+0x14)=*(u8 **)(owner+0x1dc);
    p[0x14c]=128;p[0x14d]=0;p[0x14f]=64;p[0x14e]=64;
    *(float *)(p+0x38)=1028.5714111328125f;
    x=160.0f; velocity=-3.3333332538604736f;
    if (*(s16 *)(p+0x140)) {x=-x;velocity=-velocity;}
    *(float *)(p+0x34)=*(float *)(owner+0x34)+x;
    *(float *)(p+0x5c)=velocity;*(float *)(p+0x60)=-60.0f;*(u32 *)(p+0x6c)=0;
    func_001757E0(p,20,9);
}
