/* Snapshot the offset rows and initialize owner-relative interpolation toward its target. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0,kind,team,pad3,phase,pad5[0x1B],choice,pathIndex,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,targetOffsetX,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
typedef signed short s16;
typedef struct {s16 startX[10],targetX[10];} OffsetTables;
typedef struct {s32 word[49];} State;
extern OffsetTables D_0044F000 __attribute__((aligned(16)));
extern f32 D_004F1FC8,D_004F1FCC;
extern int func_00174170(void),func_001754A0(u8 *,int,int);
extern void func_0015E630(u8 *);
void func_001E1700(u8 *actor,u8 *parent) {
 OffsetTables tables __attribute__((aligned(16)))=D_0044F000;
 Actor *owner=(Actor*)parent,*p=(Actor*)actor;
 f32 base,offset,targetOffset;
 ++p->phase;*(State*)((u8*)p+0xEC)=*(State*)((u8*)owner+0xEC);
 p->visible=1;p->team=owner->team;p->kind=owner->kind;
 p->scale.x=owner->scale.x;p->scale.y=owner->scale.y;
 p->mode=owner->mode;p->variant=owner->variant;p->group=owner->group;
 p->scale=owner->scale;p->layer=owner->layer;
 p->visible=0;p->layer=15;*(s16*)((u8*)p+0x13E)+=6;
 base=53.333332061767578125f+D_004F1FCC;
 offset=1.66666662693023681640625f*(f32)tables.startX[p->pathIndex];
 if(owner->facing) {offset=-offset;base=D_004F1FC8-53.333332061767578125f;}
 p->position.x=base+offset;p->position.y=*(f32*)((u8*)owner+0x430);
 *(s16*)((u8*)p+0x1C)=20;
 *(s16*)((u8*)p+0x1E)=func_00174170()&15;
 ((u8*)p)[0x23]=0;
 targetOffset=1.66666662693023681640625f*(f32)tables.targetX[p->pathIndex];
 p->vx=((owner->position.x+targetOffset)-p->position.x)/20.0f;
 p->targetOffsetX=targetOffset;p->ax=0.0f;
 ((u8*)p)[0x14C]=((u8*)p)[0x14D]=((u8*)p)[0x14E]=((u8*)p)[0x14F]=16;
 func_001754A0((u8*)p,27,15);
 ((u8*)p)[0]=1;((u8*)p)[0x159]=0;func_0015E630((u8*)p);
}
