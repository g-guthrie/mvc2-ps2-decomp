typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0x60];s32 remaining;u8 gapd4[0x44];f32 intensity;u8 gap11c[0x20];s8 active;u8 gap13d[3];s16 facing;u8 gap142[0xf];s8 animPhase;} Motion;
extern int func_00174170(void);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
extern void func_001E3710(u8 *,int);
extern void func_001E3210(u8 *,int);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))
#define COPY_FIELDS(p) do {(p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((Motion *)(p))->mode=((Motion *)OWNER(p))->mode;}while(0)

extern const u16 D_004C1C88[] __attribute__((section(".sdata")));
void func_0036D730(u8 *p) {
 Motion *m=(Motion *)p;u8 action=9;f32 scale=1.5f;const u16 *timerTable=D_004C1C88;p[0x13c]=1;
 m->x=*(f32 *)(LINK(p)+0x34);m->y=*(f32 *)(LINK(p)+0x38);m->z=*(f32 *)(LINK(p)+0x3c);
 p[0x24]=action;m->scaleX=scale;m->scaleY=scale;m->ax=0;m->ay=0;timerTable+=OWNER(p)[0x1b7];m->timer=*timerTable;p[0x169]=23;func_001757E0(p,p[0x169],59);
}
