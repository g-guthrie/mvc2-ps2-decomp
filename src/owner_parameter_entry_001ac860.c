/* Initialize rendering, timers, and horizontal motion from the selected native parameter record. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0[4],phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
typedef struct {s8 layer;u8 pad[3];f32 velocity;short duration,interval;} EntryParameters;
extern EntryParameters D_0044B7D0[];
extern f32 D_004F1FC8,D_004F1FCC;
extern void func_001ACA00(u8 *);
typedef struct {s32 word[49];} State;
void func_001AC860(u8 *actor) {
 Actor *p=(Actor*)actor,*owner=*(Actor**)(actor+0x18);
 EntryParameters *r;
 ++p->phase;*(unsigned short*)(actor+0x26)=0x1004;
 *(State*)(actor+0xEC)=*(State*)((u8*)owner+0xEC);
 p->visible=1;actor[2]=((u8*)owner)[2];actor[1]=((u8*)owner)[1];
 p->scale.x=owner->scale.x;p->scale.y=owner->scale.y;
 p->mode=owner->mode;p->variant=owner->variant;p->group=owner->group;
 p->scale=owner->scale;p->layer=owner->layer;
 p->visible=0;p->facing^=1;
 r=&D_0044B7D0[p->choice];
 p->layer=r->layer;
 *(short*)(actor+0x1C)=r->duration;*(short*)(actor+0x1E)=r->interval;
 if(p->facing==0)p->position.x=53.333332061767578125f+D_004F1FCC;
 else p->position.x=D_004F1FC8-53.333332061767578125f;
 p->position.y=*(f32*)((u8*)owner+0x430);
 p->vx=r->velocity;
 if(p->facing)p->vx=-p->vx;
 p->ax=0.0f;p->vy=0.0f;p->ay=0.0f;
 func_001757E0(actor,23,20);
 func_001ACA00(actor);
}
