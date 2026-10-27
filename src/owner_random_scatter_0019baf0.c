#include "actor_inherited_state.h"
/* Initialize a randomly offset effect with inherited or reflected motion. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0[4],phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
extern int func_00417A40(void),func_001754A0(u8 *,int,int);
extern void func_0019BD20(u8 *);
extern u8 *D_004C2840 __attribute__((section(".sdata")));
void func_0019BAF0(u8 *actor) {
 Actor *p=(Actor*)actor,*owner;

 int random;
 ++p->phase;
 owner=*(Actor**)(actor+0x18);
 *(ActorState *)((u8 *)p+0xEC)=*(ActorState *)((u8 *)owner+0xEC);
    p->visible = 1;
    actor[2] = (*(u8 **)(actor + 0x18))[2];
    actor[1] = (*(u8 **)(actor + 0x18))[1];
    p->scale.x = *(f32 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->scale.y = *(f32 *)(*(u8 **)(actor + 0x18) + 0x54);
    p->mode = (*(u8 **)(actor + 0x18))[0x1B7];
    p->variant = (*(u8 **)(actor + 0x18))[0x1B8];
    p->group = *(s8 *)(*(u8 **)(actor + 0x18) + 0x30);
    p->scale = *(V3 *)(*(u8 **)(actor + 0x18) + 0x50);
    p->layer = *(s8 *)(*(u8 **)(actor + 0x18) + 0x24);
 p->position=owner->position;
 random=func_00417A40();
 if(p->choice) {
  p->layer=0;
  p->position.y+=2.142857074737548828125f*(f32)((random&63)+24);
  random=func_00417A40();
  p->position.x+=1.66666662693023681640625f*(f32)(random&31);
  p->vx=-owner->vx;p->ax=0.0f;p->vy=-owner->vy;p->ay=0.0f;
 } else {
  p->position.y+=2.142857074737548828125f*(f32)((random&31)-16);
  p->vx=owner->vx/8.0f;p->ax=0.0f;p->vy=owner->vy/8.0f;p->ay=0.0f;
 }
 if(*(u32*)(D_004C2840+0x1C)&1)func_001754A0(actor,27,0);else func_001754A0(actor,27,1);
 func_0019BD20(actor);
}
