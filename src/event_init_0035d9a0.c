#include "actor_inherited_state.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef struct {float x,y,z;} V3;
typedef struct {s16 x[4],y[4];} Samples;
typedef struct {u8 pad[0x34];float x,y,z;u8 pad40[0x1c];float vx,vy,pad64,ax,ay;} Motion;
extern void func_0035DAD0(u8 *,u8 *);
void func_0035D9A0(u8 *p,u8 *owner)
{
 Motion *m=(Motion *)p;
 ++p[4];*(ActorState*)(p+0xEC)=*(ActorState*)(owner+0xEC);p[0x13C]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x13c]=0;m->x=*(float *)(owner+0x34);m->y=*(float *)(owner+0x38);m->z=*(float *)(owner+0x3c);
 m->vx=0;m->vy=0;m->ax=0;m->ay=0;
 p[0x14f]=53;p[0x14e]=53;
 if(*(s16 *)(p+0x140)==0){m->x-=80.0f;m->vx=-15.0f;}
 else {m->x+=80.0f;m->vx=15.0f;}
 *(s16 *)(p+0x1c)=1;func_0035DAD0(p,owner);
}
