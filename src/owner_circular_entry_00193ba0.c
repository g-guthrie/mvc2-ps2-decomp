/* Initialize the owner-relative circular motion state and its first velocity components. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0,kind,team,pad3,phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
typedef struct {u8 prefix[0x10];unsigned short handle;u8 pad12[2];u32 angle;s32 angular_step;s8 scale_parameter;} OrbitWork;
extern int func_001754A0(u8 *,int,int);
extern f32 func_00417500(u32),func_00417440(u32),func_00417D50(f32,f32);
void func_00193BA0(u8 *actor,u8 *parent) {
 OrbitWork *work=(OrbitWork*)(actor+0x88);
 Actor *p=(Actor*)actor,*owner=(Actor*)parent;
 f32 component;
 s32 parameter,count;
 s32 *to,*from;
 ++p->phase;
 from=(s32*)((u8*)owner+0xEC);to=(s32*)((u8*)p+0xEC);count=49;
 do {*to++=*from++;}while(--count>0);
 p->visible=1;p->team=owner->team;p->kind=owner->kind;
 p->scale.x=owner->scale.x;p->scale.y=owner->scale.y;
 p->mode=owner->mode;p->variant=owner->variant;p->group=owner->group;
 p->scale=owner->scale;p->layer=owner->layer;
 work->handle=*(unsigned short*)((u8*)owner+0x168);work->scale_parameter=8;
 *(short*)(actor+0x1C)=180;*(short*)(actor+0x1E)=1;
 *(s8*)(actor+0x31)=-4;actor[0x168]=10;
 func_001754A0(actor,27,actor[0x168]);
 if(actor[0x21]==0)work->angle=0x4000;else work->angle=0xC000;
 if(p->facing)work->angular_step=-0x400;else work->angular_step=0x400;
 component=func_00417500(work->angle);
 parameter=work->scale_parameter;
 p->vx=component*func_00417D50(2.0f,(f32)parameter)/2.0f;
 component=func_00417440(work->angle);
 parameter=work->scale_parameter;
 p->vy=component*func_00417D50(2.0f,(f32)parameter)/2.0f;
 p->position.x=owner->position.x+p->vx;
 p->position.y=137.14285278320312f+(owner->position.y+p->vy);
}
