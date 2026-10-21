typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0x60];s32 remaining;u8 gapd4[0x44];f32 intensity;u8 gap11c[0x20];s8 active;u8 gap13d[3];s16 facing;u8 gap142[0xf];s8 animPhase;u8 gap152[0x2de];f32 ground;} Motion;
extern int func_001757E0(u8 *,int,int);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define COPY_FIELDS(p) do {(p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((Motion *)(p))->mode=((Motion *)OWNER(p))->mode;}while(0)
typedef struct {u8 prefix[0x7c];s16 counters[];} CounterState;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 *D_004C2970 __attribute__((section(".sdata")));
extern f32 D_004F1F4C __attribute__((section(".bss")));
extern void func_0015E630(u8 *);
#define RESET_ACTION(p,code) do {CounterState *counterState;(p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterState=(CounterState *)D_004C2794;counterState->counters[*side]++;}while(0)
void func_00365870(u8 *p) {
 s32 count=49;u8 *owner=OWNER(p);u32 *destination,*source;Motion *m=(Motion *)p;u8 *side;double position;f32 velocity;
 p[4]++;destination=(u32 *)(p+0xec);source=(u32 *)(OWNER(p)+0xec);do{*destination++=*source++;}while(--count>0);
 COPY_FIELDS(p);D_004C2970[1]=1;p[0x1b0]=68;p[0x1b1]=68;side=p+2;
 if(owner[0x269]==3)RESET_ACTION(p,79);else RESET_ACTION(p,49);
 p[0x14e]=64;p[0x14f]=64;p[0x14c]=128;p[0x14d]=8;
 if(m->facing)position=((double)D_004F1F4C-320.0)-106.66666412353515625;
 else position=106.66666412353515625+(320.0+(double)D_004F1F4C);
 m->x=position;m->y=480.0f+*(f32 *)(OWNER(p)+0x38);m->vx=0;m->vy=0;m->ax=0;m->ay=0;
 if(m->facing)velocity=10.0f;else velocity=-10.0f;m->vx=velocity;
 m->vy=-17.142856597900390625f;m->ay=0.4017857015132904052734375f;m->timer=16;func_0015E630(p);p[0]=1;func_001757E0(p,23,5);
}
