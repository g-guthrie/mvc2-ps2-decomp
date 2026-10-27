/* Initialize a rotated linked-actor attachment and its inherited presentation. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0,kind,team,pad3,phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[8];u32 angle;u8 pad4C[4];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
typedef signed short s16;
typedef struct {s16 x,y;s8 layer;u8 animation;} AttachmentRow;

#include "actor_inherited_state.h"
typedef ActorState State;

extern AttachmentRow D_0044B900[];
extern f32 func_00417500(u32),func_00417440(u32);
extern int func_001754A0(u8 *,int,int);
extern void func_001AD0B0(u8 *);
void func_001ACE50(u8 *actor) {
 Actor *linked;
 AttachmentRow *r;
 Actor *p=(Actor*)actor,*owner;
 s16 facing;
 f32 dx,dy;
 owner=*(Actor**)(actor+0x18);linked=*(Actor**)(actor+0x14);
 ++p->phase;*(unsigned short*)(actor+0x26)=0x1007;
 *(State*)(actor+0xEC)=*(State*)((u8*)owner+0xEC);
 p->visible=1;p->team=owner->team;p->kind=owner->kind;
 p->scale.x=owner->scale.x;p->scale.y=owner->scale.y;
 p->mode=owner->mode;p->variant=owner->variant;p->group=owner->group;
 p->scale=owner->scale;p->layer=owner->layer;
 *(short*)(actor+0x1C)=30;r=&D_0044B900[p->choice];p->layer=r->layer;
 dx=1.66666662693023681640625f*(f32)r->x;
 dy=2.142857074737548828125f*(f32)r->y;
 p->angle=linked->angle;facing=linked->facing;p->facing=facing;
 if(facing==0) {
  p->position.x=(linked->position.x+dx*func_00417500(p->angle))-dy*func_00417440(p->angle);
  p->position.y=(linked->position.y+dx*func_00417440(p->angle))+dy*func_00417500(p->angle);
 } else {
  p->position.x=(linked->position.x-dx*func_00417500(p->angle))+dy*func_00417440(p->angle);
  p->position.y=(linked->position.y+dx*func_00417440(p->angle))+dy*func_00417500(p->angle);
 }
 p->vx=(p->position.x-linked->position.x)/32.0f;p->ax=0.0f;
 p->vy=8.571428298950195f;
 p->ay=-0.803571403026580810546875f;
 func_001754A0(actor,27,r->animation);
 func_001AD0B0(actor);
}
