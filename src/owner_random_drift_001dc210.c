/* Initialize a bounded random horizontal drift using the native fixed-point scaling. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0,kind,team,pad3,phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;

#include "actor_inherited_state.h"
typedef ActorState State;

extern int func_00174170(void),func_001754A0(u8 *,int,int);
void func_001DC210(u8 *actor,u8 *parent) {
 Actor *p=(Actor*)actor,*owner=(Actor*)parent;
 s32 jitter;
 ++p->phase;*(State*)(actor+0xEC)=*(State*)(parent+0xEC);
 p->visible=1;p->team=owner->team;p->kind=owner->kind;
 p->scale.x=owner->scale.x;p->scale.y=owner->scale.y;
 p->mode=owner->mode;p->variant=owner->variant;p->group=owner->group;
 p->scale=owner->scale;p->layer=owner->layer;
 p->layer=8;actor[0x22]=0;
 p->vx=0.0f;p->vy=0.0f;p->ax=0.0f;p->ay=0.0f;
 jitter=(func_00174170()&255)-128;
 p->vx=1.66666662693023681640625f*(f32)(jitter*512)/65536.0f;
 p->ay=-0.4017857015132904052734375f;
 func_001754A0(actor,27,(u8)((func_00174170()&3)+5));
}
